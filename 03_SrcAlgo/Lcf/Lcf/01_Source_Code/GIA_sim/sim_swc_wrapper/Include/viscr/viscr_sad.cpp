/*! \file **********************************************************************

COMPANY:        Continental AG

PROJECT:        MFC300

CPU:            

COMPONENT:      SAC - Stereo Auto Calibration

MODULNAME:      viscr_sad.cpp 

DESCRIPTION:    Sum of Absolute Differences

AUTHOR:         L. GARCIA

CREATION DATE:  30.08.2011

VERSION:        $Revision: 1.1 $
CHANGES:        $Log: viscr_sad.cpp  $
CHANGES:        Revision 1.1 2021/12/13 17:28:34CET Wang, David (Wangd3) 
CHANGES:        Initial revision
CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
CHANGES:        Revision 1.0 2017/03/03 10:40:27CET Sorge, Sven (uidg3181) 
CHANGES:        Initial revision
CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
CHANGES:        Revision 1.2 2011/10/04 15:09:39CEST Garcia, Lucien (uid26778) 
CHANGES:        Remove lint warnings
CHANGES:        - Added comments -  uid26778 [Oct 4, 2011 3:09:39 PM CEST]
CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
CHANGES:        Revision 1.1 2011/09/09 15:25:43CEST Garcia Lucien (uid26778) (uid26778) 
CHANGES:        Initial revision
CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj

**************************************************************************** */

#include <viscr_sad.hpp>
#include <viscr_matrix.hpp>
#include <viscr_corner_check.hpp>


// ROI sizes                           UP               DOWN
const viscr_coord viscr_sad_roi_u_start[2]=   {0,               0};
const viscr_coord viscr_sad_roi_u_stop[2]=    {40,              40};
const viscr_coord viscr_sad_roi_v_start[2]=   {-15,             3};
const viscr_coord viscr_sad_roi_v_stop[2]=    {-3,              15};



static viscr_bool coordinate_ok(
                                const viscr_image & img,
                                const viscr_coord u,
                                const viscr_coord v,
                                const viscr_coord rad)
  {
  viscr_bool return_coordinate_ok = viscr_true;
  if( (static_cast<viscr_uint>(u)<static_cast<viscr_uint>(rad+1)) || (static_cast<viscr_uint>(v)<static_cast<viscr_uint>(rad+1)))
    {return_coordinate_ok = viscr_false;}
  if( (static_cast<viscr_uint>(u+rad)>=static_cast<viscr_uint>(img.size.u)) || (static_cast<viscr_uint>(v+rad)>=static_cast<viscr_uint>(img.size.v)))
    {return_coordinate_ok =  viscr_false;}
  return return_coordinate_ok;
  }

void viscr_sad_process(
                       const viscr_image & k0, 
                       viscr_coord u0,
                       viscr_coord v0,
                       const viscr_image & k1, 
                       const viscr_float u1,
                       const viscr_float v1, 
                       viscr_float &u1_sad,
                       viscr_float &v1_sad
                       )
  {
  viscr_uint sad_in;
  viscr_coord u1_tmp, v1_tmp;

  u1_sad = u1;
  v1_sad = v1;

  // Check if we can correctly perform the operation on both images.
  if( (coordinate_ok( k0, u0, v0, VISCR_SAD_BLOCK_RAD) == viscr_false) ||
    ((u0 + VISCR_SAD_ROI+VISCR_SAD_BLOCK_RAD) >= k1.size.u)
    )
    {return;}

  ///////////////////////////////////////////////////////////////////////////////////////
  // Find SAD score on proposed solution
  // means between u0,v0 and u1,v1
  ///////////////////////////////////////////////////////////////////////////////////////
  {
  viscr_int px;
  viscr_float fu; viscr_float fv;
  viscr_pixel px_value;
  u1_tmp = static_cast<viscr_coord>(u1);
  v1_tmp = static_cast<viscr_coord>(v1);
  fu = u1 - static_cast<viscr_float>(u1_tmp);
  fv = v1 - static_cast<viscr_float>(v1_tmp);
  sad_in = 0U;
  //  Position      Pixel
  //  1 2 3         1 2
  //  4 5 6         3 4
  //  7 8 9

  if ( fv<=0.333 )
  {
    //   Pos1 => Px1;
    if      ( fu<=0.333 )
    {
      
      for (viscr_coord v= -VISCR_SAD_BLOCK_RAD; v<=VISCR_SAD_BLOCK_RAD; v++)  
      {
        for (viscr_coord u= -VISCR_SAD_BLOCK_RAD; u<=VISCR_SAD_BLOCK_RAD; u++)
        {
          sad_in +=  static_cast<viscr_uint>(abs(static_cast<viscr_coord>(viscr_image_getPixel( k0, u0+u, v0+v)) - static_cast<viscr_coord>(viscr_image_getPixel(k1, u1_tmp+u, v1_tmp+v))));
        }
      }    
    }
    else 
    {
      if ( fu<=0.666 )
      {
        //    Pos2  => (Px1 + px2)/2;
        for (viscr_coord v= -VISCR_SAD_BLOCK_RAD; v<=VISCR_SAD_BLOCK_RAD; v++)  
        {
          for (viscr_coord u= -VISCR_SAD_BLOCK_RAD; u<=VISCR_SAD_BLOCK_RAD; u++)
          {
            px = u1_tmp+u+((v1_tmp+v)*k1.size.u);
            px_value = (k1.data[px]+k1.data[px+1])/2U;
            sad_in +=  static_cast<viscr_uint>(abs(static_cast<viscr_coord>(viscr_image_getPixel( k0, u0+u, v0+v)) - static_cast<viscr_coord>(px_value)));
          }
        }
      }
      else   
      {
        // Pos3 => Px2
        for (viscr_coord v= -VISCR_SAD_BLOCK_RAD; v<=VISCR_SAD_BLOCK_RAD; v++)  
        {
          for (viscr_coord u= -VISCR_SAD_BLOCK_RAD; u<=VISCR_SAD_BLOCK_RAD; u++)
            {
            px = u1_tmp+u+((v1_tmp+v)*k1.size.u);
            px_value = k1.data[px+1];
            sad_in +=  static_cast<viscr_uint>(abs(static_cast<viscr_coord>(viscr_image_getPixel( k0, u0+u, v0+v)) - static_cast<viscr_coord>(px_value)));
            }
        }
      }
    }
  }
  else 
  {
    if ( fv<=0.666 )
    {
      if      ( fu<=0.333 ) 
        {
        // Pos4 => (Px1 + Px3)/2
        for (viscr_coord v= -VISCR_SAD_BLOCK_RAD; v<=VISCR_SAD_BLOCK_RAD; v++)
          {
          for (viscr_coord u= -VISCR_SAD_BLOCK_RAD; u<=VISCR_SAD_BLOCK_RAD; u++)
            {
            px = u1_tmp+u+((v1_tmp+v)*k1.size.u);
            px_value = (k1.data[px]+k1.data[px+k1.size.u])/2U;
            sad_in +=  static_cast<viscr_uint>(abs(static_cast<viscr_coord>(viscr_image_getPixel( k0, u0+u, v0+v)) - static_cast<viscr_coord>(px_value)));
            }
          }
        }
      else 
      {
        if ( fu<=0.666 )
        {
          // Pos5 => (Px1 + Px2 + Px3 + Px4)/4
          for (viscr_coord v= -VISCR_SAD_BLOCK_RAD; v<=VISCR_SAD_BLOCK_RAD; v++)  
          {
            for (viscr_coord u= -VISCR_SAD_BLOCK_RAD; u<=VISCR_SAD_BLOCK_RAD; u++)
            {
              px = u1_tmp+u+((v1_tmp+v)*k1.size.u);
              px_value = (k1.data[px]+k1.data[px+k1.size.u]+k1.data[px+1]+k1.data[px+k1.size.u+1])/4U;
              sad_in +=  static_cast<viscr_uint>(abs(static_cast<viscr_coord>(viscr_image_getPixel( k0, u0+u, v0+v)) - static_cast<viscr_coord>(px_value)));
            }
          }
        }
        else    
        {
          // Pos 6 => (Px2+Px4)/2
          for (viscr_coord v= -VISCR_SAD_BLOCK_RAD; v<=VISCR_SAD_BLOCK_RAD; v++)
          {
            for (viscr_coord u= -VISCR_SAD_BLOCK_RAD; u<=VISCR_SAD_BLOCK_RAD; u++)
            {
              px = u1_tmp+u+((v1_tmp+v)*k1.size.u);
              px_value = (k1.data[px+1]+k1.data[px+k1.size.u+1])/2U;
              sad_in +=  static_cast<viscr_uint>(abs(static_cast<viscr_coord>(viscr_image_getPixel( k0, u0+u, v0+v)) - static_cast<viscr_coord>(px_value)));
            }
          }
        }
      }
    }
    else
    {
      if      ( fu<=0.333 ) 
      {
        // Pos7 => Px3
        for (viscr_coord v= -VISCR_SAD_BLOCK_RAD; v<=VISCR_SAD_BLOCK_RAD; v++)  
        {
          for (viscr_coord u= -VISCR_SAD_BLOCK_RAD; u<=VISCR_SAD_BLOCK_RAD; u++)
          {
            px = u1_tmp+u+((v1_tmp+v)*k1.size.u);
            px_value = k1.data[px+k1.size.u];
            sad_in +=  static_cast<viscr_uint>(abs(static_cast<viscr_coord>(viscr_image_getPixel( k0, u0+u, v0+v)) - static_cast<viscr_coord>(px_value)));
          }
        }
      }
      else 
      {
        if ( fu<=0.666 ) 
        {
          // Pos8 => (Px3 + Px4)/2
          for (viscr_coord v= -VISCR_SAD_BLOCK_RAD; v<=VISCR_SAD_BLOCK_RAD; v++)
          {
            for (viscr_coord u= -VISCR_SAD_BLOCK_RAD; u<=VISCR_SAD_BLOCK_RAD; u++)
            {
              px = u1_tmp+u+((v1_tmp+v)*k1.size.u);
              px_value = (k1.data[px+k1.size.u]+k1.data[px+k1.size.u+1])/2U;
              sad_in +=  static_cast<viscr_uint>(abs(static_cast<viscr_coord>(viscr_image_getPixel( k0, u0+u, v0+v)) - static_cast<viscr_coord>(px_value)));
            }
          }
        }
        else
        {
          // Pos9 => (Px4)
          for (viscr_coord v= -VISCR_SAD_BLOCK_RAD; v<=VISCR_SAD_BLOCK_RAD; v++)
          {
            for (viscr_coord u= -VISCR_SAD_BLOCK_RAD; u<=VISCR_SAD_BLOCK_RAD; u++)
            {
              px = u1_tmp+u+((v1_tmp+v)*k1.size.u);
              px_value = k1.data[px+k1.size.u+1];
              sad_in += static_cast<viscr_uint>( abs(static_cast<viscr_coord>(viscr_image_getPixel( k0, u0+u, v0+v)) - static_cast<viscr_coord>(px_value)));
            }
          }
        }
      }
    }
  }
  }


    
  viscr_uint sad_out_min;
  viscr_uint sad_out_min_2;
  viscr_coord sad_out_min_u1 = 0;
  viscr_coord sad_out_min_v1 = 0;
  viscr_coord sad_out_min_2_u1 = 0;
  viscr_coord sad_out_min_2_v1 = 0;

  ///////////////////////////////////////////////////////////////////////////////////////
  // Find the 2 best SAD score on ROI windows
  ///////////////////////////////////////////////////////////////////////////////////////
  {
  viscr_uint sad_out;
  sad_in = sad_in - static_cast<viscr_uint>(VISCR_SAD_MIN_THRESHOLD);
  sad_out_min = sad_in;
  sad_out_min_2 = sad_in;

  for (viscr_uint window = 0; window<=1; window++)
    {
    for (viscr_coord v_roi = viscr_sad_roi_v_start[window]; v_roi<= viscr_sad_roi_v_stop[window]; v_roi++)
      {
      for (viscr_coord u_roi =  viscr_sad_roi_u_start[window]; u_roi<= viscr_sad_roi_u_stop[window]; u_roi++)
        {
        if (viscr_corner_check(k1,u0+u_roi,v0+v_roi) == viscr_true)
          {
          sad_out = 0U;
          for (viscr_coord v= -VISCR_SAD_BLOCK_RAD; v<=VISCR_SAD_BLOCK_RAD; v++)
            {
            for (viscr_coord u= -VISCR_SAD_BLOCK_RAD; u<=VISCR_SAD_BLOCK_RAD; u++)
              {
              sad_out +=  static_cast<viscr_uint>(abs(static_cast<viscr_coord>(viscr_image_getPixel( k0, u0+u, v0+v)) - static_cast<viscr_coord>(viscr_image_getPixel( k1, u0+u+u_roi, v0+v+v_roi))));
              }
            }
          if (sad_out < sad_out_min_2)
            {
            if (sad_out < sad_out_min)
              {
              sad_out_min_2 = sad_out_min;
              sad_out_min = sad_out;
              sad_out_min_u1 = u0+u_roi;
              sad_out_min_v1 = v0+v_roi;
              }
            else
              {
              sad_out_min_2 = sad_out;
              sad_out_min_2_u1 = u0+u_roi;
              sad_out_min_2_v1 = v0+v_roi;
              }
            }
          }
        }
      }
    }
  }


  
  ///////////////////////////////////////////////////////////////////////////////////////
  // Find best SAD score on proposed solution
  // means between u0,v0 and u1,v1
  ///////////////////////////////////////////////////////////////////////////////////////
  {
  viscr_uint dis_between_min = static_cast<viscr_uint>(abs(((sad_out_min_u1 - sad_out_min_2_u1) + sad_out_min_v1) - sad_out_min_2_v1));
  if ( 
        ((sad_out_min < sad_in) && (sad_out_min_2 == sad_in))       // only one maximum
     || (   (sad_out_min < sad_in) && (sad_out_min_2 < sad_in) &&      
            ( (dis_between_min <= 2U) || ( (dis_between_min >= 5U) && (sad_out_min < (sad_out_min_2 - (static_cast<viscr_uint>(VISCR_SAD_MIN_THRESHOLD)/4U))))) 
        )                                                           // second maximum is closed to the first maximum or far away but enougth small
     )
    {
    u1_sad = static_cast<viscr_float>(sad_out_min_u1);
    v1_sad = static_cast<viscr_float>(sad_out_min_v1);
    }
  }
  
  return;
  }

