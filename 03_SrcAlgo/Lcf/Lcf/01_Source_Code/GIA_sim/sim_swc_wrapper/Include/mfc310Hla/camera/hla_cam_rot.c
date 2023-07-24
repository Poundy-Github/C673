/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

  PROJECT:                MFC400

  CPU:                    TI DSP C674x

  COMPONENT:              HLA

  MODULNAME:              hla_cam_rot.c

  DESCRIPTION:            Routines for full camera rotation and translation

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2013-02-27

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_cam_rot.c  $
  CHANGES:                Revision 1.1 2021/12/13 17:26:50CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/camera/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:38:25CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/camera/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:22CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/camera/project.pj
  CHANGES:                Revision 1.8 2014/03/25 18:35:12CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hla_cam_rot.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_cam_rot.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/camera/project.pj.
  CHANGES:                Revision 1.7 2014/03/21 09:39:25CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added more Cantata tests
  CHANGES:                --- Added comments ---  uidv7867 [Mar 21, 2014 9:39:25 AM CET]
  CHANGES:                Change Package : 207432:34 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.6 2014/03/19 16:30:27CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGES:                Fixed hlar input adapter for old recordings (headlamp type)
  CHANGES:                Clean-up of no longer needed files in simulation
  CHANGES:                --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:28 PM CET]
  CHANGES:                Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGES:                Revision 1.5 2014/03/10 13:20:54CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed some new critical QAC warnings
  CHANGES:                Moved suppressions from .hoc file to comment in source code
  CHANGES:                --- Added comments ---  uidv7867 [Mar 10, 2014 1:20:55 PM CET]
  CHANGES:                Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.4 2014/02/06 16:01:11CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGES:                Centralized Null pointer checks
  CHANGES:                Refactored dframe calculation
  CHANGES:                --- Added comments ---  uidv7867 [Feb 6, 2014 4:01:11 PM CET]
  CHANGES:                Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGES:                Revision 1.3 2014/01/10 18:33:30CET Mutschler, Matthias (uidv7867) 
  CHANGES:                First part of LRF on EVE (disabled)
  CHANGES:                Merged LRF inputs into one struct
  CHANGES:                Fixed exception handling of internal cali 
  CHANGES:                Removed all tabs in the code and further clean-up
  CHANGES:                --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:30 PM CET]
  CHANGES:                Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.2 2013/12/17 17:32:39CET Glebov, Roman (uidg4759) 
  CHANGES:                QAC Changes + Documentation of Chain of Light + fix of devision by 0 + small efficiency tweaks
  CHANGES:                --- Added comments ---  uidg4759 [Dec 17, 2013 5:32:39 PM CET]
  CHANGES:                Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGES:                Revision 1.1 2013/03/04 11:15:26CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGES:                Revision 1.1 2013/02/27 13:02:02CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision 
  CHANGES:                Based on /nfs/projekte1/customer/Base_ARS3xx_ISF1xx/3_development/4_sw/dev/appl/pc_sim/head_light/assist/src/cam/rcs/cam_rot.c (revision 1.26.1.10)
**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#include "cml_ext.h"
#include "hla_cam_rot.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  CONSTANTS
*****************************************************************************/
/* Constant for minimum allowed Z coordinate for points and tracks */
static const float32 f_MinAllowedZCoordinate = 0.001f;


/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/
static void HLACamRotPrecalculation(HLACamRot* cr);
static float32 HLACamRotSquare (float32 a);
static float32 HLACamRotGetInverseZk(float32 i_fx, float32 d_xb, float32 d_yb, float32 d);

/****************************************************************************
fN*  function name    : HLACamRotSetRot
f$*  ------------------------------------------------------------------------
fE*  input parameters : float32 angle_x    : rotation angle, x_w axis 
fE*                   : float32 angle_y    : rotation angle, y_w axis
fE*                   : float32 angle z    : rotation angle, z_w axis
fE*                   : -
fA*  output parameters: -
fR*  return value     : -
fV*  used routines    : -
fF*  error handling   : -
f$*  ------------------------------------------------------------------------
fU*  autor            : Stefan Heinrich 
f$*  ------------------------------------------------------------------------
fB*  description      : generate ROT_W and ROT_K from rotation angles.
fB*                   :
fB*                   : ROT_W = Rz*Ry*Rx with:
fB*                   :
fB*                   :     [cos(z) ] [-sin(z)] [0      ]
fB*                   : Rz =[sin(z) ] [cos(z) ] [0      ]
fB*                   :     [0      ] [0      ] [1      ]
fB*                   :
fB*                   :     [cos(y) ] [0      ] [sin(y) ]
fB*                   : Ry =[0      ] [1      ] [0      ]
fB*                   :     [-sin(y)] [0      ] [cos(y) ]
fB*                   :
fB*                   :     [1      ] [0      ] [0      ]
fB*                   : Rx =[0      ] [cos(x) ] [-sin(x)]
fB*                   :     [0      ] [sin(x) ] [cos(x) ]
fB*                   :
fB*                   : ROT_K = trn(ROT_W)
fB*                   :
****************************************************************************/
void HLACamRotSetRot(HLACamRot* cr, float32 x, float32 y, float32 z)
{
  float32 sx, sy, sz, cx, cy, cz;
  
  /* calculate and remember new angles */
  sx = sinf(x); cx = cosf(x);  cr->A[0] = x; 
  sy = sinf(y); cy = cosf(y);  cr->A[1] = y;
  sz = sinf(z); cz = cosf(z);  cr->A[2] = z; 
  
  /* ROT_W */
  cr->ROT_W[0] = cz*cy;               cr->ROT_W[1] = (-sz*cx)+(cz*sy*sx); cr->ROT_W[2] = (sz*sx)+(cz*sy*cx);
  cr->ROT_W[3] = sz*cy;               cr->ROT_W[4] = (cz*cx)+(sz*sy*sx);  cr->ROT_W[5] = (-cz*sx)+(sz*sy*cx);
  cr->ROT_W[6] = -sy;                 cr->ROT_W[7] = cy*sx;               cr->ROT_W[8] = cy*cx;

  /*  ROT_K */
  cr->ROT_K[0] = cr->ROT_W[0];        cr->ROT_K[1] = cr->ROT_W[3];        cr->ROT_K[2] = cr->ROT_W[6];
  cr->ROT_K[3] = cr->ROT_W[1];        cr->ROT_K[4] = cr->ROT_W[4];        cr->ROT_K[5] = cr->ROT_W[7];
  cr->ROT_K[6] = cr->ROT_W[2];        cr->ROT_K[7] = cr->ROT_W[5];        cr->ROT_K[8] = cr->ROT_W[8];
  
  /* ROT_K_derivatives */
  cr->ROT_K_a[0]= 0.0f;               cr->ROT_K_a[1]= 0.0f;               cr->ROT_K_a[2]= 0.0f;
  cr->ROT_K_a[3]= cr->ROT_W[2];       cr->ROT_K_a[4]= cr->ROT_W[5];       cr->ROT_K_a[5]= cr->ROT_W[8];
  cr->ROT_K_a[6]=-cr->ROT_W[1];       cr->ROT_K_a[7]=-cr->ROT_W[4];       cr->ROT_K_a[8]=-cr->ROT_W[7];
  
  cr->ROT_K_b[0]=-cz*sy;              cr->ROT_K_b[1]=-sz*sy;              cr->ROT_K_b[2]=-cy;
  cr->ROT_K_b[3]= cr->ROT_W[0]*sx;    cr->ROT_K_b[4]= cr->ROT_W[3]*sx;    cr->ROT_K_b[5]= cr->ROT_W[6]*sx;
  cr->ROT_K_b[6]= cr->ROT_W[0]*cx;    cr->ROT_K_b[7]= cr->ROT_W[3]*cx;    cr->ROT_K_b[8]= cr->ROT_W[6]*cx;

  cr->ROT_K_c[0]=-cr->ROT_W[3];       cr->ROT_K_c[1]= cr->ROT_W[0];       cr->ROT_K_c[2]= 0.0f;
  cr->ROT_K_c[3]=-cr->ROT_W[4];       cr->ROT_K_c[4]= cr->ROT_W[1];       cr->ROT_K_c[5]= 0.0f;
  cr->ROT_K_c[6]=-cr->ROT_W[5];       cr->ROT_K_c[7]= cr->ROT_W[2];       cr->ROT_K_c[8]= 0.0f;  
  
  /* ROT_KW_deriv. = ROT_K_deriv. * ROT_W */
  cr->ROT_KW_a[0] = 0.0f;                                                                                      cr->ROT_KW_a[1] = 0.0f;                                                                                      cr->ROT_KW_a[2] = 0.0f;
  cr->ROT_KW_a[3] = (cr->ROT_K_a[3]*cr->ROT_W[0])+(cr->ROT_K_a[4]*cr->ROT_W[3])+(cr->ROT_K_a[5]*cr->ROT_W[6]); cr->ROT_KW_a[4] = (cr->ROT_K_a[3]*cr->ROT_W[1])+(cr->ROT_K_a[4]*cr->ROT_W[4])+(cr->ROT_K_a[5]*cr->ROT_W[7]); cr->ROT_KW_a[5] = (cr->ROT_K_a[3]*cr->ROT_W[2])+(cr->ROT_K_a[4]*cr->ROT_W[5])+(cr->ROT_K_a[5]*cr->ROT_W[8]);
  cr->ROT_KW_a[6] = (cr->ROT_K_a[6]*cr->ROT_W[0])+(cr->ROT_K_a[7]*cr->ROT_W[3])+(cr->ROT_K_a[8]*cr->ROT_W[6]); cr->ROT_KW_a[7] = (cr->ROT_K_a[6]*cr->ROT_W[1])+(cr->ROT_K_a[7]*cr->ROT_W[4])+(cr->ROT_K_a[8]*cr->ROT_W[7]); cr->ROT_KW_a[8] = (cr->ROT_K_a[6]*cr->ROT_W[2])+(cr->ROT_K_a[7]*cr->ROT_W[5])+(cr->ROT_K_a[8]*cr->ROT_W[8]);
  
  cr->ROT_KW_b[0] = (cr->ROT_K_b[0]*cr->ROT_W[0])+(cr->ROT_K_b[1]*cr->ROT_W[3])+(cr->ROT_K_b[2]*cr->ROT_W[6]); cr->ROT_KW_b[1] = (cr->ROT_K_b[0]*cr->ROT_W[1])+(cr->ROT_K_b[1]*cr->ROT_W[4])+(cr->ROT_K_b[2]*cr->ROT_W[7]); cr->ROT_KW_b[2] = (cr->ROT_K_b[0]*cr->ROT_W[2])+(cr->ROT_K_b[1]*cr->ROT_W[5])+(cr->ROT_K_b[2]*cr->ROT_W[8]);
  cr->ROT_KW_b[3] = (cr->ROT_K_b[3]*cr->ROT_W[0])+(cr->ROT_K_b[4]*cr->ROT_W[3])+(cr->ROT_K_b[5]*cr->ROT_W[6]); cr->ROT_KW_b[4] = (cr->ROT_K_b[3]*cr->ROT_W[1])+(cr->ROT_K_b[4]*cr->ROT_W[4])+(cr->ROT_K_b[5]*cr->ROT_W[7]); cr->ROT_KW_b[5] = (cr->ROT_K_b[3]*cr->ROT_W[2])+(cr->ROT_K_b[4]*cr->ROT_W[5])+(cr->ROT_K_b[5]*cr->ROT_W[8]);
  cr->ROT_KW_b[6] = (cr->ROT_K_b[6]*cr->ROT_W[0])+(cr->ROT_K_b[7]*cr->ROT_W[3])+(cr->ROT_K_b[8]*cr->ROT_W[6]); cr->ROT_KW_b[7] = (cr->ROT_K_b[6]*cr->ROT_W[1])+(cr->ROT_K_b[7]*cr->ROT_W[4])+(cr->ROT_K_b[8]*cr->ROT_W[7]); cr->ROT_KW_b[8] = (cr->ROT_K_b[6]*cr->ROT_W[2])+(cr->ROT_K_b[7]*cr->ROT_W[5])+(cr->ROT_K_b[8]*cr->ROT_W[8]);
  
  cr->ROT_KW_c[0] = (cr->ROT_K_c[0]*cr->ROT_W[0])+(cr->ROT_K_c[1]*cr->ROT_W[3]);                               cr->ROT_KW_c[1] = (cr->ROT_K_c[0]*cr->ROT_W[1])+(cr->ROT_K_c[1]*cr->ROT_W[4]);                               cr->ROT_KW_c[2] = (cr->ROT_K_c[0]*cr->ROT_W[2])+(cr->ROT_K_c[1]*cr->ROT_W[5]);
  cr->ROT_KW_c[3] = (cr->ROT_K_c[3]*cr->ROT_W[0])+(cr->ROT_K_c[4]*cr->ROT_W[3]);                               cr->ROT_KW_c[4] = (cr->ROT_K_c[3]*cr->ROT_W[1])+(cr->ROT_K_c[4]*cr->ROT_W[4]);                               cr->ROT_KW_c[5] = (cr->ROT_K_c[3]*cr->ROT_W[2])+(cr->ROT_K_c[4]*cr->ROT_W[5]);
  cr->ROT_KW_c[6] = (cr->ROT_K_c[6]*cr->ROT_W[0])+(cr->ROT_K_c[7]*cr->ROT_W[3]);                               cr->ROT_KW_c[7] = (cr->ROT_K_c[6]*cr->ROT_W[1])+(cr->ROT_K_c[7]*cr->ROT_W[4]);                               cr->ROT_KW_c[8] = (cr->ROT_K_c[6]*cr->ROT_W[2])+(cr->ROT_K_c[7]*cr->ROT_W[5]);

  /* set init flag */
  cr->InitStatus |= HLA_CAM_ROT_ROTATION_SET;

  /* update pre-calculated values */
  if (((cr->InitStatus & HLA_CAM_ROT_TRANSLATION_SET) != 0u) && ((cr->InitStatus & HLA_CAM_ROT_FOCAL_SET) != 0u))
  {
    HLACamRotPrecalculation(cr);
  }
}

/****************************************************************************
fN*  function name    : HLACamRotSetT
f$*  ------------------------------------------------------------------------
fE*  input parameters : float32 x    : camera position, x coordinate 
fE*                   : float32 y    : camera position, y coordinate
fE*                   : float32 z    : camera position, z coordinate
fE*                   : -
fA*  output parameters: -
fR*  return value     : -
fV*  used routines    : -
fF*  error handling   : -
f$*  ------------------------------------------------------------------------
fU*  autor            : Stefan Heinrich 
f$*  ------------------------------------------------------------------------
fB*  description      : generate transition vector for position of 
fB*                   : camera in world coordinates
fB*                   :
fB*                   : TRANS =[x][y][z]
fB*                   :
****************************************************************************/
void HLACamRotSetT(HLACamRot* cr, float32 x, float32 y, float32 z){
  cr->T[0] = x;
  cr->T[1] = y;
  cr->T[2] = z;

  /* set init flag */
  cr->InitStatus |= HLA_CAM_ROT_TRANSLATION_SET;

  /* update precalculated values */
  if (((cr->InitStatus & HLA_CAM_ROT_ROTATION_SET) != 0u) && ((cr->InitStatus & HLA_CAM_ROT_FOCAL_SET) != 0u))
  {
    /* ~CodeReview ~ID:1d8056f368d2230030dc0e353e0b4d1b ~Reviewer:CW01\muellerr5 ~Date:16.07.2012 ~Priority:3 ~Comment:no need for call to precalculation when transition vector changes */
    HLACamRotPrecalculation(cr);
  }
}


/* **************************************************************************** 
  Functionname:     void HLACamRotGetT(const HLACamRot* cr, float32* x, float32* y, float32* z)     */ /*!  
  Description:      

  @param[in,out]    void

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
void HLACamRotGetT(const HLACamRot* cr, float32* x, float32* y, float32* z)
{
  *x = cr->T[0];
  *y = cr->T[1];
  *z = cr->T[2];
}

/* **************************************************************************** 
  Functionname:     float32 HLACamRotGetTx (const HLACamRot* cr)      */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
float32 HLACamRotGetTx (const HLACamRot* cr) 
{ 
  return cr->T[0]; 
}

/* **************************************************************************** 
  Functionname:     float32 HLACamRotGetTy (const HLACamRot* cr)       */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
float32 HLACamRotGetTy (const HLACamRot* cr) 
{ 
  return cr->T[1]; 
}

/* **************************************************************************** 
  Functionname:     float32 HLACamRotGetTz (const HLACamRot* cr)      */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
float32 HLACamRotGetTz (const HLACamRot* cr) 
{ 
  return cr->T[2]; 
}

/****************************************************************************
fN*  function name    : HLACamRotSetFxFyXoYo
f$*  ------------------------------------------------------------------------
fE*  input parameters : float32 fx     
fE*                   : float32 fy    
fE*                   : float32 xo    
fE*                   : float32 yo    
fE*                   : -
fA*  output parameters: -
fR*  return value     : -
fV*  used routines    : -
fF*  error handling   : -
f$*  ------------------------------------------------------------------------
fU*  autor            : Stefan Heinrich 
f$*  ------------------------------------------------------------------------
fB*  description      : set module intern parameter FX, FY, XO, YO
fB*                   :
****************************************************************************/
void HLACamRotSetFxFyXoYo(HLACamRot* cr, float32 fx, float32 fy, float32 xo, float32 yo){
  cr->FX = fx;
  cr->FY = fy;
  cr->XO = xo;
  cr->YO = yo;

  /* set init flag */
  cr->InitStatus |= HLA_CAM_ROT_FOCAL_SET;

  /* update precalculated values */
  if (((cr->InitStatus & HLA_CAM_ROT_ROTATION_SET) != 0u) && ((cr->InitStatus & HLA_CAM_ROT_TRANSLATION_SET) != 0u))
  {
    HLACamRotPrecalculation(cr);
  }
}

/* **************************************************************************** 
  Functionname:     void HLACamRotGetFxFyXoYo(const HLACamRot* cr, float32* fx, float32* fy, float32* xo, float32* yo)      */ /*!  
  Description:      

  @param[in,out]    void

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
void HLACamRotGetFxFyXoYo(const HLACamRot* cr, float32* fx, float32* fy, float32* xo, float32* yo)
{
  *fx = cr->FX;
  *fy = cr->FY;
  *xo = cr->XO;
  *yo = cr->YO;
}

/* **************************************************************************** 
  Functionname:     float32 HLACamRotGetFx (const HLACamRot* cr)      */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
float32 HLACamRotGetFx (const HLACamRot* cr) 
{ 
  return cr->FX; 
}

/* **************************************************************************** 
  Functionname:     float32 HLACamRotGetFy (const HLACamRot* cr)      */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
float32 HLACamRotGetFy (const HLACamRot* cr) 
{
  return cr->FY; 
}

/* **************************************************************************** 
  Functionname:     float32 HLACamRotGetTz (const HLACamRot* cr)      */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
float32 HLACamRotGetXo (const HLACamRot* cr) 
{ 
  return cr->XO; 
}

/* **************************************************************************** 
  Functionname:     float32 HLACamRotGetYo (const HLACamRot* cr)      */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
float32 HLACamRotGetYo (const HLACamRot* cr) 
{ 
  return cr->YO; 
}

/****************************************************************************
fN*  function name    : HLACamRotGetXb / get_Xb_3D / HLACamRotGetxb / HLACamRotGetyb
f$*  ------------------------------------------------------------------------
fE*  input parameters : xw, yw, zw  : world coordinates
fE*                   : -
fA*  output parameters: xb, yb       : image coordinates
fR*  return value     : -
fV*  used routines    : -
fF*  error handling   : -
f$*  ------------------------------------------------------------------------
fU*  autor            : Stefan Heinrich 
f$*  ------------------------------------------------------------------------
fB*  description      : compute image coordinate (xb, yb) from world 
fB*                   : coordinate (xw, yw, zw)
fB*                   :
fB*                   : xb = FX/zk*xk + XO; yb = FY/zk*yk +YO;
fB*                   :
fB*                   : with:
fB*                   :  
fB*                   : Xk   = ROT_K*( Xw - T )  
fB*                   :          ~
fB*                   : [xk]          [xw] [tx]
fB*                   : [yk} = ROT_K*([yw]-[ty])
fB*                   : [zk]          [zw] [tz]
fB*                   :
****************************************************************************/
void  HLACamRotGetXb(const HLACamRot* cr, float32* xb, float32* yb, float32 xw, float32 yw, float32 zw)
{
  float32 xk, yk, zk;
  HLACamRotGetXkXw (cr, &xk, &yk, &zk, xw, yw, zw);
  
  /* avoid projection behind camera */
  /* do not move points behind camera to 0, because there is then a division by 0 in next step*/
  zk = CML_f_Max(zk, f_MinAllowedZCoordinate);
  
  /* see Zisserman page 154 top equation 6.1 */
  *xb = ((cr->FX/zk) * xk) + cr->XO;
  *yb = ((cr->FY/zk) * yk) + cr->YO;
}

/* **************************************************************************** 
  Functionname:     float32 HLACamRotGetxb(const HLACamRot* cr, float32 xw, float32 yw, float32 zw)      */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
float32 HLACamRotGetxb(const HLACamRot* cr, float32 xw, float32 yw, float32 zw)
{
  float32 xk, yk, zk;
  HLACamRotGetXkXw (cr, &xk, &yk, &zk, xw, yw, zw);
  
  /* avoid projection behind camera */
  /* do not move points behind camera to 0, because there is then a division by 0 in next step*/
  zk = CML_f_Max(zk,f_MinAllowedZCoordinate); 

  /* applying a mapping to image plane of a point in 3D Camera Coordinates */
  /* see Zisserman page 154 top equation 6.1 */
  return(((cr->FX/zk) * xk) + cr->XO);
}

/* **************************************************************************** 
  Functionname:     float32 HLACamRotGetyb(const HLACamRot* cr, float32 xw, float32 yw, float32 zw)    */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
float32 HLACamRotGetyb(const HLACamRot* cr, float32 xw, float32 yw, float32 zw)
{
  float32 xk, yk, zk;
  HLACamRotGetXkXw (cr, &xk, &yk, &zk, xw, yw, zw);
  
  /* avoid projection behind camera */
  /* do not move points behind camera to 0, because there is then a division by 0 in next step*/
  zk = CML_f_Max(zk,f_MinAllowedZCoordinate);

  /* applying a mapping to image plane of a point in 3D Camera Coordinates */
  /* see Zisserman page 154 top equation 6.1 */
  return(((cr->FY/zk) * yk) + cr->YO);
}

/****************************************************************************
fN*  function name    : HLACamRotGetXkXw
f$*  ------------------------------------------------------------------------
fE*  input parameters : xw, yw, zw : world coordinates
fE*                   : -
fA*  output parameters: xk, yk, zk : camera coordinates
fR*  return value     : -
fV*  used routines    : -
fF*  error handling   : -
f$*  ------------------------------------------------------------------------
fU*  autor            : Christian Exner / Stefan Heinrich
f$*  ------------------------------------------------------------------------
fB*  description      : compute camera coordinate (xk, yk, zk) from world 
fB*                   : coordinate (xw, yw, zw)
fB*                   :  
fB*                   : Xk   = ROT_K * ( Xw  -  T  )
fB*                   :          ~
fB*                   : [xk]            [xw]   [tx]
fB*                   : [yk] = ROT_K * ([yw] - [ty])
fB*                   : [zk]            [zw]   [tz]
fB*                   :
****************************************************************************/
void HLACamRotGetXkXw (const HLACamRot* cr, float32* xk, float32* yk, float32* zk, float32 xw, float32 yw, float32 zw)
{
    /* Translating the point based on position of camera view */
  /* See Zisserman page 156 equation 6.6 */
    float32 dx = xw-cr->T[0];
    float32 dy = yw-cr->T[1];
    float32 dz = zw-cr->T[2];

    /* Making camera view specific rotation */
    *xk = (cr->ROT_K[0]*dx) + (cr->ROT_K[1]*dy) + (cr->ROT_K[2]*dz);
    *yk = (cr->ROT_K[3]*dx) + (cr->ROT_K[4]*dy) + (cr->ROT_K[5]*dz);
    *zk = (cr->ROT_K[6]*dx) + (cr->ROT_K[7]*dy) + (cr->ROT_K[8]*dz);
}


/****************************************************************************
fN*  function name    : get_Xw
f$*  ------------------------------------------------------------------------
fE*  input parameters : xb, yb, xw/yw/zw : image coordinates,
fE*                   :                    one known world coordinate
fE*                   : -
fA*  output parameters: yw,zw / xw,zw / xw,yw : world coordinates
fR*  return value     : -
fV*  used routines    : -
fF*  error handling   : -
f$*  ------------------------------------------------------------------------
fU*  autor            : Christian Exner
f$*  ------------------------------------------------------------------------
fB*  description      : compute 2 world coordinates from 2 image
fB*                   : coordinates (xb, yb) and one known world coordinate
fB*                   :
fB*                   : xb   = FX/zk*xk + XO
fB*                   : yb   = FY/zk*yk + YO
fB*                   : Xw   = ROT_W * Xk  +  T   
fB*                   :          ~
fB*                   : [xw]          [xk]   [tx]
fB*                   : [yw] = ROT_W *[yk] + [ty]
fB*                   : [zw]          [zk]   [tz]
fB*                   :          ~
fB*                   : xw = (r11*a + r12*b + r13) * zk + tx
fB*                   : yw = (r21*a + r22*b + r23) * zk + ty
fB*                   : zw = (r31*a + r32*b + r33) * zk + tz
fB*                   :
fB*                   : with:
fB*                   : a = (xb - XO) / FX; b = (yb - YO) / FY
fB*                   : 
****************************************************************************/
void HLACamRotGetXwX (const HLACamRot* cr, float32 xw, float32* yw, float32* zw, float32 xb, float32 yb)
{
    float32 a, b, zk;
    float32 fTmp;

    a = (xb - cr->XO) / cr->FX;
    b = (yb - cr->YO) / cr->FY;

    fTmp = ((cr->ROT_W[0] * a) + (cr->ROT_W[1] * b) + cr->ROT_W[2]);
    
    if (fabs(fTmp) > CML_f_Delta)
    {
      zk = (xw - cr->T[0]) / fTmp;
    }
    else
    {
      zk = 0.0f;
    }
    
    *yw = (((cr->ROT_W[3] * a) + (cr->ROT_W[4] * b) + cr->ROT_W[5]) * zk) + cr->T[1];
    *zw = (((cr->ROT_W[6] * a) + (cr->ROT_W[7] * b) + cr->ROT_W[8]) * zk) + cr->T[2];
}

/* **************************************************************************** 
  Functionname:     float32 HLACamRotGetywX (const HLACamRot* cr, float32 xw, float32 xb, float32 yb)  */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
float32 HLACamRotGetywX (const HLACamRot* cr, float32 xw, float32 xb, float32 yb)
{
    float32 a, b, zk;
    float32 fTmp;

    a = (xb - cr->XO) / cr->FX;
    b = (yb - cr->YO) / cr->FY;

    fTmp = ((cr->ROT_W[0] * a) + (cr->ROT_W[1] * b) + cr->ROT_W[2]);
    
    if (fabs(fTmp) > CML_f_Delta)
    {
      zk = (xw - cr->T[0]) / fTmp;
    }
    else
    {
      zk = 0.0f;
    }
    
    return (((cr->ROT_W[3] * a) + (cr->ROT_W[4] * b) + cr->ROT_W[5]) * zk) + cr->T[1];
}

/* **************************************************************************** 
  Functionname:     float32 HLACamRotGetzwX (const HLACamRot* cr, float32 xw, float32 xb, float32 yb)   */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
float32 HLACamRotGetzwX (const HLACamRot* cr, float32 xw, float32 xb, float32 yb)
{
    float32 a, b, zk;
    float32 fTmp;

    a = (xb - cr->XO) / cr->FX;
    b = (yb - cr->YO) / cr->FY;

    fTmp = ((cr->ROT_W[0] * a) + (cr->ROT_W[1] * b) + cr->ROT_W[2]);
    
    if (fabs(fTmp) > CML_f_Delta)
    {
      zk = (xw - cr->T[0]) / fTmp;
    }
    else
    {
      zk = 0.0f;
    }
    
    return (((cr->ROT_W[6] * a) + (cr->ROT_W[7] * b) + cr->ROT_W[8]) * zk) + cr->T[2];
}

/* **************************************************************************** 
  Functionname:     void HLACamRotGetXwY (const HLACamRot* cr, float32* xw, float32 yw, float32* zw, float32 xb, float32 yb)   */ /*!  
  Description:      

  @param[in,out]    void

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
void HLACamRotGetXwY (const HLACamRot* cr, float32* xw, float32 yw, float32* zw, float32 xb, float32 yb)
{
    float32 a, b, zk;
    float32 fTmp;

    a = (xb - cr->XO) / cr->FX;
    b = (yb - cr->YO) / cr->FY;

    fTmp = ((cr->ROT_W[3] * a) + (cr->ROT_W[4] * b) + cr->ROT_W[5]);
    
    if (fabs(fTmp) > CML_f_Delta)
    {
      zk = (yw - cr->T[1]) / fTmp;
    }
    else
    {
      zk = 0.0f;
    }
        
    *xw = (((cr->ROT_W[0] * a) + (cr->ROT_W[1] * b) + cr->ROT_W[2]) * zk) + cr->T[0];
    *zw = (((cr->ROT_W[6] * a) + (cr->ROT_W[7] * b) + cr->ROT_W[8]) * zk) + cr->T[2];
}

/* **************************************************************************** 
  Functionname:     float32 HLACamRotGetxwY (const HLACamRot* cr, float32 yw, float32 xb, float32 yb)    */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
float32 HLACamRotGetxwY (const HLACamRot* cr, float32 yw, float32 xb, float32 yb)
{
    float32 a, b, zk;
    float32 fTmp;

    a = (xb - cr->XO) / cr->FX;
    b = (yb - cr->YO) / cr->FY;

    fTmp = ((cr->ROT_W[3] * a) + (cr->ROT_W[4] * b) + cr->ROT_W[5]);
    
    if (fabs(fTmp) > CML_f_Delta)
    {
      zk = (yw - cr->T[1]) / fTmp;
    }
    else
    {
      zk = 0.0f;
    }
    
    return (((cr->ROT_W[0] * a) + (cr->ROT_W[1] * b) + cr->ROT_W[2]) * zk) + cr->T[0];
}

/* **************************************************************************** 
  Functionname:     void HLACamRotGetXwZ (const HLACamRot* cr, float32* xw, float32* yw, float32 zw, float32 xb, float32 yb)    */ /*!  
  Description:      

  @param[in,out]    void

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
void HLACamRotGetXwZ (const HLACamRot* cr, float32* xw, float32* yw, float32 zw, float32 xb, float32 yb)
{
    float32 a, b, zk;
    float32 fTmp;
    
    a = (xb - cr->XO) / cr->FX;
    b = (yb - cr->YO) / cr->FY;

    fTmp = ((cr->ROT_W[6] * a) + (cr->ROT_W[7] * b) + cr->ROT_W[8]);
    
    if (fabs(fTmp) > CML_f_Delta)
    {
      zk = (zw - cr->T[2]) / fTmp;
    }
    else
    {
      zk = 0.0f;
    }
    
    *xw = (((cr->ROT_W[0] * a) + (cr->ROT_W[1] * b) + cr->ROT_W[2]) * zk) + cr->T[0];
    *yw = (((cr->ROT_W[3] * a) + (cr->ROT_W[4] * b) + cr->ROT_W[5]) * zk) + cr->T[1];
}

/* **************************************************************************** 
  Functionname:     float32 HLACamRotGetywZ (const HLACamRot* cr, float32 zw, float32 xb, float32 yb)    */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
float32 HLACamRotGetywZ (const HLACamRot* cr, float32 zw, float32 xb, float32 yb)
{
    float32 a, b, zk;
    float32 fTmp;

    a = (xb - cr->XO) / cr->FX;
    b = (yb - cr->YO) / cr->FY;

    fTmp = ((cr->ROT_W[6] * a) + (cr->ROT_W[7] * b) + cr->ROT_W[8]);

    if (fabs(fTmp) > CML_f_Delta)
    {
      zk = (zw - cr->T[2]) / fTmp;
    }
    else
    {
      zk = 0.0f;
    }
    
    return (((cr->ROT_W[3] * a) + (cr->ROT_W[4] * b) + cr->ROT_W[5]) * zk) + cr->T[1];
}

/* **************************************************************************** 
  Functionname:     float32 HLACamRotGetJacobianxbxwXb   */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
float32 HLACamRotGetJacobianxbxwXb(const HLACamRot* cr, 
                                   float32 xb, float32 yb, float32 d)
{
  /*                      */
  /* assumption: fx = fy  */
  /*                      */
  /* use d = 1 as default */
  /*                      */

  register float32 d_xb = xb - cr->XO;
  register float32 d_yb = yb - cr->YO;
  register float32 i_zk;

  i_zk = HLACamRotGetInverseZk(cr->SQR_1_FX, d_xb, d_yb, d);

  /*  return i_zk*(fx*cr->ROT_K[0]-d_xb*cr->ROT_K[6]);  */
  return (i_zk * (cr->FX_x_RK0 - (d_xb * cr->ROT_K[6])));
}

/* **************************************************************************** 
  Functionname:     float32 HLACamRotGetJacobianxbywXb   */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
float32 HLACamRotGetJacobianxbywXb(const HLACamRot* cr, 
                                   float32 xb, float32 yb, float32 d)
{
  /*                      */
  /* assumption: fx = fy  */
  /*                      */
  /* use d = 1 as default */
  /*                      */

  register float32 d_xb = xb - cr->XO;
  register float32 d_yb = yb - cr->YO;
  register float32 i_zk;

  i_zk = HLACamRotGetInverseZk(cr->SQR_1_FX, d_xb, d_yb, d);

  /*  return i_zk*(fx*cr->ROT_K[1]-d_xb*cr->ROT_K[7]);  */
  return (i_zk * (cr->FX_x_RK1 - (d_xb * cr->ROT_K[7])));
}

/* **************************************************************************** 
  Functionname:     float32 HLACamRotGetJacobianxbzwXb    */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
float32 HLACamRotGetJacobianxbzwXb(const HLACamRot* cr, 
                                   float32 xb, float32 yb, float32 d)
{
  /*                      */
  /* assumption: fx = fy  */
  /*                      */
  /* use d = 1 as default */
  /*                      */

  register float32 d_xb = xb - cr->XO;
  register float32 d_yb = yb - cr->YO;
  register float32 i_zk;

  i_zk = HLACamRotGetInverseZk(cr->SQR_1_FX, d_xb, d_yb, d);

  /*  return i_zk*(fx*cr->ROT_K[2]-d_xb*cr->ROT_K[8]);  */
  return (i_zk * (cr->FX_x_RK2 - (d_xb * cr->ROT_K[8])));
}

/* **************************************************************************** 
  Functionname:     float32 HLACamRotGetJacobianybxwXb    */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
float32 HLACamRotGetJacobianybxwXb(const HLACamRot* cr, 
                                   float32 xb, float32 yb, float32 d)
{
  /*                      */
  /* assumption: fx = fy  */
  /*                      */
  /* use d = 1 as default */
  /*                      */

  register float32 d_xb = xb - cr->XO;
  register float32 d_yb = yb - cr->YO;
  register float32 i_zk;

  i_zk = HLACamRotGetInverseZk(cr->SQR_1_FX, d_xb, d_yb, d);

  /*  return i_zk*(fy*cr->ROT_K[3]-d_yb*cr->ROT_K[6]);  */
  return (i_zk * (cr->FY_x_RK3 - (d_yb * cr->ROT_K[6])));
}

/* **************************************************************************** 
  Functionname:     float32 HLACamRotGetJacobianybywXb    */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
float32 HLACamRotGetJacobianybywXb(const HLACamRot* cr, 
                                   float32 xb, float32 yb, float32 d)
{
  /*                      */
  /* assumption: fx = fy  */
  /*                      */
  /* use d = 1 as default */
  /*                      */

  register float32 d_xb = xb - cr->XO;
  register float32 d_yb = yb - cr->YO;
  register float32 i_zk;

  i_zk = HLACamRotGetInverseZk(cr->SQR_1_FX, d_xb, d_yb, d);

  /*  return i_zk*(fy*cr->ROT_K[4]-d_yb*cr->ROT_K[7]);  */
  return (i_zk * (cr->FY_x_RK4 - (d_yb * cr->ROT_K[7])));
}

/* **************************************************************************** 
  Functionname:     float32 HLACamRotGetJacobianybzwXb   */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
float32 HLACamRotGetJacobianybzwXb(const HLACamRot* cr, 
                                   float32 xb, float32 yb, float32 d)
{
  /*                      */
  /* assumption: fx = fy  */
  /*                      */
  /* use d = 1 as default */
  /*                      */

  register float32 d_xb = xb - cr->XO;
  register float32 d_yb = yb - cr->YO;
  register float32 i_zk;

  i_zk = HLACamRotGetInverseZk(cr->SQR_1_FX, d_xb, d_yb, d);

  /*  return i_zk*(fy*cr->ROT_K[5]-d_yb*cr->ROT_K[8]);  */
  return (i_zk * (cr->FY_x_RK5 - (d_yb * cr->ROT_K[8])));
}

/* **************************************************************************** 
  Functionname:     float32 HLACamRotGetJacobianxbcXb(const HLACamRot* cr, float32 xb, float32 yb)    */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
float32 HLACamRotGetJacobianxbcXb(const HLACamRot* cr, float32 xb, float32 yb)
{
  register float32 d_xb = xb - cr->XO;
  register float32 d_yb = yb - cr->YO;
  register float32 f_xb = d_xb / cr->FX;
  register float32 f_yb = d_yb / cr->FY;

  /* return d_yb*cr->ROT_KW_c[1] + fx*cr->ROT_KW_c[2] + d_xb*(cr->ROT_KW_c[0] - cr->ROT_KW_c[8] - f_xb*cr->ROT_KW_c[6] - f_yb*cr->ROT_KW_c[7]) */
  return (d_yb * cr->ROT_KW_c[1]) + cr->FX_x_RKWc2 + (d_xb * ((cr->RKWc0_min_RKWc8 - (f_xb * cr->ROT_KW_c[6])) - (f_yb * cr->ROT_KW_c[7])));
}

/* **************************************************************************** 
  Functionname:     float32 HLACamRotGetJacobianybbXb(const HLACamRot* cr, float32 xb, float32 yb)    */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
float32 HLACamRotGetJacobianybbXb(const HLACamRot* cr, float32 xb, float32 yb)
{
  register float32 d_xb = xb - cr->XO;
  register float32 d_yb = yb - cr->YO;
  register float32 f_xb = d_xb / cr->FX;
  register float32 f_yb = d_yb / cr->FY;

  /* return d_xb*cr->ROT_KW_b[3] + fx*cr->ROT_KW_b[5] + d_yb*(cr->ROT_KW_b[4] - cr->ROT_KW_b[8] - f_xb*cr->ROT_KW_b[6] - f_yb*cr->ROT_KW_b[7]) */
  return (d_yb * cr->ROT_KW_b[3]) + cr->FX_x_RKWb5 + (d_xb * ((cr->RKWb4_min_RKWb8 - (f_xb * cr->ROT_KW_b[6])) - (f_yb * cr->ROT_KW_b[7])));
}

/* **************************************************************************** 
  Functionname:     void  HLACamRotGetJacobianXb    */ /*!  
  Description:      

  @param[in,out]    void

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
void  HLACamRotGetJacobianXb(const HLACamRot* cr, 
                             float32 xb, float32* xb_xw, float32* xb_yw, float32* xb_zw, float32* xb_a,  float32* xb_b,  float32* xb_c,
                             float32 yb, float32* yb_xw, float32* yb_yw, float32* yb_zw, float32* yb_a,  float32* yb_b,  float32* yb_c)
{
  /*                      */
  /* assumption: fx = fy  */
  /*                      */
  /* use d = 1 as default */
  /*                      */

  register float32 d_xb = xb-cr->XO;
  register float32 d_yb = yb-cr->YO;
  register float32 f_xb = d_xb / cr->FX;
  register float32 f_yb = d_yb /cr->FY;
  register float32 i_zk;
  register float32 fTemp;

  i_zk = HLACamRotGetInverseZk(cr->SQR_1_FX, d_xb, d_yb, 1.0f);

  *xb_xw = i_zk * (cr->FX_x_RK0 - (d_xb * cr->ROT_K[6]));
  *yb_xw = i_zk * (cr->FY_x_RK3 - (d_yb * cr->ROT_K[6]));
  *xb_yw = i_zk * (cr->FX_x_RK1 - (d_xb * cr->ROT_K[7]));
  *yb_yw = i_zk * (cr->FY_x_RK4 - (d_yb * cr->ROT_K[7]));
  *xb_zw = i_zk * (cr->FX_x_RK2 - (d_xb * cr->ROT_K[8]));
  *yb_zw = i_zk * (cr->FY_x_RK5 - (d_yb * cr->ROT_K[8]));

  /*                                       [1/fx * (xb-x0)] */
  /*           [fx  0 -(xb-x0)]            [1/fy * (yb-y0)] */
  /* dXb/dAw = [ 0 fy -(yb-y0)] * ROT_KW_x [      1       ] */
  /*                                                        */
  /*  *xb_a = (fx*cr->ROT_KW_a[0]-d_xb*cr->ROT_KW_a[6])*f_xb + (fx*cr->ROT_KW_a[1]-d_xb*cr->ROT_KW_a[7])*f_yb + (fx*cr->ROT_KW_a[2]-d_xb*cr->ROT_KW_a[8]);  */
  /*  *yb_a = (fy*cr->ROT_KW_a[3]-d_yb*cr->ROT_KW_a[6])*f_xb + (fy*cr->ROT_KW_a[4]-d_yb*cr->ROT_KW_a[7])*f_yb + (fy*cr->ROT_KW_a[5]-d_yb*cr->ROT_KW_a[8]);  */
  /*  *xb_b = (fx*cr->ROT_KW_b[0]-d_xb*cr->ROT_KW_b[6])*f_xb + (fx*cr->ROT_KW_b[1]-d_xb*cr->ROT_KW_b[7])*f_yb + (fx*cr->ROT_KW_b[2]-d_xb*cr->ROT_KW_b[8]);  */
  /*  *yb_b = (fy*cr->ROT_KW_b[3]-d_yb*cr->ROT_KW_b[6])*f_xb + (fy*cr->ROT_KW_b[4]-d_yb*cr->ROT_KW_b[7])*f_yb + (fy*cr->ROT_KW_b[5]-d_yb*cr->ROT_KW_b[8]);  */
  /*  *xb_c = (fx*cr->ROT_KW_c[0]-d_xb*cr->ROT_KW_c[6])*f_xb + (fx*cr->ROT_KW_c[1]-d_xb*cr->ROT_KW_c[7])*f_yb + (fx*cr->ROT_KW_c[2]-d_xb*cr->ROT_KW_c[8]);  */
  /*  *yb_c = (fy*cr->ROT_KW_c[3]-d_yb*cr->ROT_KW_c[6])*f_xb + (fy*cr->ROT_KW_c[4]-d_yb*cr->ROT_KW_c[7])*f_yb + (fy*cr->ROT_KW_c[5]-d_yb*cr->ROT_KW_c[8]);  */

  /* *xb_a = d_yb*cr->ROT_KW_a[1] + fx*cr->ROT_KW_a[2] + d_xb*(cr->ROT_KW_a[0] - cr->ROT_KW_a[8] - f_xb*cr->ROT_KW_a[6] - f_yb*cr->ROT_KW_a[7]) */
  /* *yb_a = d_xb*cr->ROT_KW_a[3] + fx*cr->ROT_KW_a[5] + d_yb*(cr->ROT_KW_a[4] - cr->ROT_KW_a[8] - f_xb*cr->ROT_KW_a[6] - f_yb*cr->ROT_KW_a[7]) */

  fTemp = cr->ROT_KW_a[8] + (f_xb * cr->ROT_KW_a[6]) + (f_yb * cr->ROT_KW_a[7]);
  *xb_a = (d_yb * cr->ROT_KW_a[1]) + cr->FX_x_RKWa2 + (d_xb * (cr->ROT_KW_a[0] - fTemp));
  *yb_a = (d_xb * cr->ROT_KW_a[3]) + cr->FX_x_RKWa5 + (d_yb * (cr->ROT_KW_a[4] - fTemp));

  /* *xb_b = d_yb*cr->ROT_KW_b[1] + fx*cr->ROT_KW_b[2] + d_xb*(cr->ROT_KW_b[0] - cr->ROT_KW_b[8] - f_xb*cr->ROT_KW_b[6] - f_yb*cr->ROT_KW_b[7]) */
  /* *yb_b = d_xb*cr->ROT_KW_b[3] + fx*cr->ROT_KW_b[5] + d_yb*(cr->ROT_KW_b[4] - cr->ROT_KW_b[8] - f_xb*cr->ROT_KW_b[6] - f_yb*cr->ROT_KW_b[7]) */

  fTemp = cr->ROT_KW_b[8] + (f_xb * cr->ROT_KW_b[6]) + (f_yb * cr->ROT_KW_b[7]);
  *xb_b = (d_yb * cr->ROT_KW_b[1]) + cr->FX_x_RKWb2 + (d_xb * (cr->ROT_KW_b[0] - fTemp));
  *yb_b = (d_xb * cr->ROT_KW_b[3]) + cr->FX_x_RKWb5 + (d_yb * (cr->ROT_KW_b[4] - fTemp));
  /* *xb_c = d_yb*cr->ROT_KW_c[1] + fx*cr->ROT_KW_c[2] + d_xb*(cr->ROT_KW_c[0] - cr->ROT_KW_c[8] - f_xb*cr->ROT_KW_c[6] - f_yb*cr->ROT_KW_c[7]) */
  /* *yb_c = d_xb*cr->ROT_KW_c[3] + fx*cr->ROT_KW_c[5] + d_yb*(cr->ROT_KW_c[4] - cr->ROT_KW_c[8] - f_xb*cr->ROT_KW_c[6] - f_yb*cr->ROT_KW_c[7]) */

  fTemp = cr->ROT_KW_c[8] + (f_xb * cr->ROT_KW_c[6]) + (f_yb * cr->ROT_KW_c[7]);
  *xb_c = (d_yb * cr->ROT_KW_c[1]) + cr->FX_x_RKWc2 + (d_xb * (cr->ROT_KW_c[0] - fTemp));
  *yb_c = (d_xb * cr->ROT_KW_c[3]) + cr->FX_x_RKWc5 + (d_yb * (cr->ROT_KW_c[4] - fTemp));
}

/* **************************************************************************** 
  Functionname:     void HLACamRotGetJacobianxbaxbcybaybcXb    */ /*!  
  Description:      

  @param[in,out]    void

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
void HLACamRotGetJacobianxbaxbcybaybcXb(const HLACamRot* cr,
                                        float32*  xb_a, float32* xb_c, 
                                        float32*  yb_a, float32* yb_c,
                                        float32   xb,   float32  yb)
{
  /*                      */
  /* assumption: fx = fy  */
  /*                      */
  /* use d = 1 as default */
  /*                      */

  register float32 d_xb = xb - cr->XO;
  register float32 d_yb = yb - cr->YO;
  register float32 f_xb = d_xb / cr->FX;
  register float32 f_yb = d_yb / cr->FY;
  register float32 fTemp;

  /* *xb_a = d_yb*cr->ROT_KW_a[1] + fx*cr->ROT_KW_a[2] + d_xb*(cr->ROT_KW_a[0] - cr->ROT_KW_a[8] - f_xb*cr->ROT_KW_a[6] - f_yb*cr->ROT_KW_a[7]) */
  /* *yb_a = d_xb*cr->ROT_KW_a[3] + fx*cr->ROT_KW_a[5] + d_yb*(cr->ROT_KW_a[4] - cr->ROT_KW_a[8] - f_xb*cr->ROT_KW_a[6] - f_yb*cr->ROT_KW_a[7]) */
  fTemp = cr->ROT_KW_a[8] + (f_xb * cr->ROT_KW_a[6]) + (f_yb * cr->ROT_KW_a[7]);
  *xb_a = (d_yb * cr->ROT_KW_a[1]) + cr->FX_x_RKWa2 + (d_xb * (cr->ROT_KW_a[0] - fTemp));
  *yb_a = (d_xb * cr->ROT_KW_a[3]) + cr->FX_x_RKWa5 + (d_yb * (cr->ROT_KW_a[4] - fTemp));


  /* *xb_c = d_yb*cr->ROT_KW_c[1] + fx*cr->ROT_KW_c[2] + d_xb*(cr->ROT_KW_c[0] - cr->ROT_KW_c[8] - f_xb*cr->ROT_KW_c[6] - f_yb*cr->ROT_KW_c[7]) */
  /* *yb_c = d_xb*cr->ROT_KW_c[3] + fx*cr->ROT_KW_c[5] + d_yb*(cr->ROT_KW_c[4] - cr->ROT_KW_c[8] - f_xb*cr->ROT_KW_c[6] - f_yb*cr->ROT_KW_c[7]) */
  fTemp = cr->ROT_KW_c[8] + (f_xb * cr->ROT_KW_c[6]) + (f_yb * cr->ROT_KW_c[7]);
  *xb_c = (d_yb * cr->ROT_KW_c[1]) + cr->FX_x_RKWc2 + (d_xb * (cr->ROT_KW_c[0] - fTemp));
  *yb_c = (d_xb * cr->ROT_KW_c[3]) + cr->FX_x_RKWc5 + (d_yb * (cr->ROT_KW_c[4] - fTemp));
}

/* **************************************************************************** 
  Functionname:     void HLACamRotGetJacobianxbxwxbywybxwybywXb    */ /*!  
  Description:      

  @param[in,out]    void

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
void HLACamRotGetJacobianxbxwxbywybxwybywXb(const HLACamRot* cr,
                                            float32*  xb_xw, float32* xb_yw,
                                            float32*  yb_xw, float32* yb_yw,
                                            float32   xb,    float32 yb)
{
  /*                      */
  /* assumption: fx = fy  */
  /*                      */
  /* use d = 1 as default */
  /*                      */

  register float32 d_xb = xb - cr->XO;
  register float32 d_yb = yb - cr->YO;
  register float32 i_zk;

  i_zk = HLACamRotGetInverseZk(cr->SQR_1_FX, d_xb, d_yb, 1.0f);

  *xb_xw = i_zk*(cr->FX_x_RK0 - (d_xb * cr->ROT_K[6]));
  *yb_xw = i_zk*(cr->FY_x_RK3 - (d_yb * cr->ROT_K[6]));

  *xb_yw = i_zk*(cr->FX_x_RK1 - (d_xb * cr->ROT_K[7]));
  *yb_yw = i_zk*(cr->FY_x_RK4 - (d_yb * cr->ROT_K[7]));
}

/* **************************************************************************** 
  Functionname:     void HLACamRotGetJacobianxbcybaxbxwxbywybxwybywXb   */ /*!  
  Description:      

  @param[in,out]    void

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
void HLACamRotGetJacobianxbcybaxbxwxbywybxwybywXb(const HLACamRot* cr, 
                                                  float32* xb_xw, float32* xb_yw, 
                                                  float32* yb_xw, float32* yb_yw, 
                                                  float32* xb_c,  float32* yb_a, 
                                                  float32  xb,    float32  yb, 
                                                  float32 d)
{
  /*                      */
  /* assumption: fx = fy  */
  /*                      */
  /* use d = 1 as default */
  /*                      */

  register float32 d_xb = xb - cr->XO;
  register float32 d_yb = yb - cr->YO;
  register float32 f_xb = d_xb / cr->FX;
  register float32 f_yb = d_yb / cr->FY;
  register float32 i_zk;

  /*  1/zk = sqrtf((1/fx)² * (d_xb² + d_yb²) + 1.0f) / d;  */
  i_zk = HLACamRotGetInverseZk(cr->SQR_1_FX, d_xb, d_yb, d);

  *xb_xw = i_zk*(cr->FX_x_RK0 - (d_xb * cr->ROT_K[6]));
  *yb_xw = i_zk*(cr->FY_x_RK3 - (d_yb * cr->ROT_K[6]));

  *xb_yw = i_zk*(cr->FX_x_RK1 - (d_xb * cr->ROT_K[7]));
  *yb_yw = i_zk*(cr->FY_x_RK4 - (d_yb * cr->ROT_K[7]));

  *yb_a = (d_xb * cr->ROT_KW_a[3]) + cr->FX_x_RKWa5 + (d_yb * ((cr->RKWa4_min_RKWa8 - (f_xb * cr->ROT_KW_a[6])) - (f_yb * cr->ROT_KW_a[7])));
  *xb_c = (d_yb * cr->ROT_KW_c[1]) + cr->FX_x_RKWc2 + (d_xb * ((cr->RKWc0_min_RKWc8 - (f_xb * cr->ROT_KW_c[6])) - (f_yb * cr->ROT_KW_c[7])));
}


/* **************************************************************************** 
  Functionname:     static void HLACamRotPrecalculation(HLACamRot* cr)    */ /*!  
  Description:      

  @param[in,out]    static void

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
static void HLACamRotPrecalculation(HLACamRot* cr)
{
  /* cr->FX is the focal length; range = ]100;2000[ */
  cr->SQR_1_FX = HLACamRotSquare(1.0f / cr->FX); /* (1/FX)*(1/FX) */

  cr->FX_x_RK0 = cr->FX * cr->ROT_K[0]; /* FX * ROT_K[0] */
  cr->FX_x_RK1 = cr->FX * cr->ROT_K[1]; /* FX * ROT_K[1] */
  cr->FX_x_RK2 = cr->FX * cr->ROT_K[2]; /* FX * ROT_K[2] */
  cr->FY_x_RK3 = cr->FY * cr->ROT_K[3]; /* FY * ROT_K[3] */
  cr->FY_x_RK4 = cr->FY * cr->ROT_K[4]; /* FY * ROT_K[4] */
  cr->FY_x_RK5 = cr->FY * cr->ROT_K[5]; /* FY * ROT_K[5] */

  cr->FX_x_RKWa2 = cr->FX * cr->ROT_KW_a[2]; /* FX * ROT_KW_a[2] */
  cr->FX_x_RKWa5 = cr->FX * cr->ROT_KW_a[5]; /* FX * ROT_KW_a[5] */
  cr->FX_x_RKWb2 = cr->FX * cr->ROT_KW_b[2]; /* FX * ROT_KW_b[2] */
  cr->FX_x_RKWb5 = cr->FX * cr->ROT_KW_b[5]; /* FX * ROT_KW_b[5] */
  cr->FX_x_RKWc2 = cr->FX * cr->ROT_KW_c[2]; /* FX * ROT_KW_c[2] */
  cr->FX_x_RKWc5 = cr->FX * cr->ROT_KW_c[5]; /* FX * ROT_KW_c[5] */

  cr->RKWa0_min_RKWa8 = cr->ROT_KW_a[0] * cr->ROT_KW_a[8]; /* ROT_KW_a[0] - ROT_KW_a[8] */
  cr->RKWa4_min_RKWa8 = cr->ROT_KW_a[4] * cr->ROT_KW_a[8]; /* ROT_KW_a[4] - ROT_KW_a[8] */
  cr->RKWb0_min_RKWb8 = cr->ROT_KW_b[0] * cr->ROT_KW_b[8]; /* ROT_KW_b[0] - ROT_KW_b[8] */
  cr->RKWb4_min_RKWb8 = cr->ROT_KW_b[4] * cr->ROT_KW_b[8]; /* ROT_KW_b[4] - ROT_KW_b[8] */
  cr->RKWc0_min_RKWc8 = cr->ROT_KW_c[0] * cr->ROT_KW_c[8]; /* ROT_KW_c[0] - ROT_KW_c[8] */
  cr->RKWc4_min_RKWc8 = cr->ROT_KW_c[4] * cr->ROT_KW_c[8]; /* ROT_KW_c[4] - ROT_KW_c[8] */
}

/* **************************************************************************** 
  Functionname:     static float32 HLACamRotSquare (float32 a)    */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
static float32 HLACamRotSquare (float32 a)
{
  return (a * a);
}

/* **************************************************************************** 
  Functionname:     static float32 HLACamRotGetInverseZk(float32 i_fx, float32 d_xb, float32 d_yb, float32 d)    */ /*!  
  Description:      

  @param[in,out]    float32

  @return           -
  @pre              -
  @post             -
**************************************************************************** */
static float32 HLACamRotGetInverseZk(float32 i_fx, float32 d_xb, float32 d_yb, float32 d)
{
 /* ~CodeReview ~ID:bfae3e38243a2c54c7d26624f885e556 ~Reviewer:PC2357\dijkstg ~Date:11-7-2012 ~Priority:3 ~Comment:If (d==0) -> shouldn't i_zk be max float in stead of 0! (See also similar functions) */
  /* check d against zero devision and i_fx against negativ sqrt */
  float32 i_zk = 0.0f;
  if (    (d > CML_f_Delta)
       && (!(i_fx < 0.0f))
     )
  {
    /*  1/zk = sqrtf((1/fx)² * (d_xb² + d_yb²) + 1.0f) / d;  */
    i_zk = sqrtf((i_fx * (HLACamRotSquare(d_xb) + HLACamRotSquare(d_yb))) + 1.0f) / d;
  }
  return i_zk;
}/* PRQA S 861 1 */
