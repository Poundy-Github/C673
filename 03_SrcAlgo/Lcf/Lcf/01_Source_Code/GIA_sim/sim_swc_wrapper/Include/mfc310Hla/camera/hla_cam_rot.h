/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

  PROJECT:                MFC400

  CPU:                    TI DSP C674x

  COMPONENT:              HLA

  MODULNAME:              hla_cam_rot.h

  DESCRIPTION:            Routines for full camera rotation and translation

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2013-02-27

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_cam_rot.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:26:50CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/camera/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:38:25CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/camera/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:23CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/camera/project.pj
  CHANGES:                Revision 1.8 2014/03/25 18:35:12CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hla_cam_rot.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_cam_rot.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/camera/project.pj.
  CHANGES:                Revision 1.7 2014/03/21 09:39:31CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added more Cantata tests
  CHANGES:                --- Added comments ---  uidv7867 [Mar 21, 2014 9:39:31 AM CET]
  CHANGES:                Change Package : 207432:34 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.6 2014/03/19 16:30:23CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGES:                Fixed hlar input adapter for old recordings (headlamp type)
  CHANGES:                Clean-up of no longer needed files in simulation
  CHANGES:                --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:24 PM CET]
  CHANGES:                Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGES:                Revision 1.5 2014/03/04 16:51:55CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed QAC warnings
  CHANGES:                Coding style
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2014 4:51:55 PM CET]
  CHANGES:                Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.4 2014/02/24 10:43:16CET Fischer, Alexander (uidv8778) 
  CHANGES:                Added extern "C" for visu dll
  CHANGES:                --- Added comments ---  uidv8778 [Feb 24, 2014 10:43:16 AM CET]
  CHANGES:                Change Package : 207443:1 http://mks-psad:7002/im/viewissue?selection=207443
  CHANGES:                Revision 1.3 2014/01/10 18:33:26CET Mutschler, Matthias (uidv7867) 
  CHANGES:                First part of LRF on EVE (disabled)
  CHANGES:                Merged LRF inputs into one struct
  CHANGES:                Fixed exception handling of internal cali 
  CHANGES:                Removed all tabs in the code and further clean-up
  CHANGES:                --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:27 PM CET]
  CHANGES:                Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.2 2013/03/06 11:19:32CET Zechner, Stefan (uidt9253) 
  CHANGES:                - remove dependencies to algo_common
  CHANGES:                - replace HLA type Pix16_t by RTE type t_PixelData
  CHANGES:                --- Added comments ---  uidt9253 [Mar 6, 2013 11:19:32 AM CET]
  CHANGES:                Change Package : 166950:1 http://mks-psad:7002/im/viewissue?selection=166950
  CHANGES:                Revision 1.1 2013/03/04 11:15:27CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGES:                Revision 1.1 2013/02/27 13:02:02CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision 
  CHANGES:                Based on /nfs/projekte1/customer/Base_ARS3xx_ISF1xx/3_development/4_sw/dev/appl/pc_sim/head_light/assist/src/cam/rcs/cam_rot.h (revision 1.17.1.4.1.4)
  CHANGES:
  CHANGES:
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_CAM_ROT_INCLUDED
#define HLA_CAM_ROT_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/  
#include "glob_type.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/



/*****************************************************************************
  MACROS 
*****************************************************************************/

#define HLA_CAM_ROT_ROTATION_SET        0x01u  /* 00000001 */
#define HLA_CAM_ROT_TRANSLATION_SET     0x02u  /* 00000010 */
#define HLA_CAM_ROT_FOCAL_SET           0x04u  /* 00000100 */
#define HLA_CAM_ROT_3X3_MATRIXSIZE      9
#define HLA_CAM_ROT_3X3_VECTORSIZE      3


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
typedef struct
{
  float32 ROT_W[HLA_CAM_ROT_3X3_MATRIXSIZE];             /* rotation matrix Xw = ROT_W*Kk + TRANS      */ 
  float32 ROT_K[HLA_CAM_ROT_3X3_MATRIXSIZE];             /* rotation matrix Xk = ROT_K*(Kw - TRANS)      */ 
  float32 ROT_K_a[HLA_CAM_ROT_3X3_MATRIXSIZE];           /* derivates of matrix ROT_K in respect to angle a  */
  float32 ROT_K_b[HLA_CAM_ROT_3X3_MATRIXSIZE];           /* derivates of matrix ROT_K in respect to angle b  */
  float32 ROT_K_c[HLA_CAM_ROT_3X3_MATRIXSIZE];           /* derivates of matrix ROT_K in respect to angle c  */
  float32 ROT_KW_a[HLA_CAM_ROT_3X3_MATRIXSIZE];          /* ROT_K_a * ROT_W  */
  float32 ROT_KW_b[HLA_CAM_ROT_3X3_MATRIXSIZE];          /* ROT_K_b * ROT_W  */
  float32 ROT_KW_c[HLA_CAM_ROT_3X3_MATRIXSIZE];          /* ROT_K_c * ROT_W  */
  float32 T[HLA_CAM_ROT_3X3_VECTORSIZE];                 /* vector for camera position  [x][y][z]      */
  float32 FX, FY;                                        /* camera parameter xb=FX/zk*xk, yb=FY/zk*yk    */
  float32 XO, YO;                                        /* camera parameter "Hauptpunkt"          */
  float32 A[HLA_CAM_ROT_3X3_VECTORSIZE];                 /* vector for camera angles [a][b][c]      */

  /* precalculated values */
  float32 SQR_1_FX;             /* (1/FX)*(1/FX) */

  float32 FX_x_RK0;             /* FX * ROT_K[0] */
  float32 FX_x_RK1;             /* FX * ROT_K[1] */
  float32 FX_x_RK2;             /* FX * ROT_K[2] */
  float32 FY_x_RK3;             /* FY * ROT_K[3] */
  float32 FY_x_RK4;             /* FY * ROT_K[4] */
  float32 FY_x_RK5;             /* FY * ROT_K[5] */

  float32 FX_x_RKWa2;           /* FX * ROT_KW_a[2] */
  float32 FX_x_RKWa5;           /* FX * ROT_KW_a[5] */
  float32 FX_x_RKWb2;           /* FX * ROT_KW_b[2] */
  float32 FX_x_RKWb5;           /* FX * ROT_KW_b[5] */
  float32 FX_x_RKWc2;           /* FX * ROT_KW_c[2] */
  float32 FX_x_RKWc5;           /* FX * ROT_KW_c[5] */

  float32 RKWa0_min_RKWa8;      /* ROT_KW_a[0] - ROT_KW_a[8] */
  float32 RKWa4_min_RKWa8;      /* ROT_KW_a[4] - ROT_KW_a[8] */
  float32 RKWb0_min_RKWb8;      /* ROT_KW_b[0] - ROT_KW_b[8] */
  float32 RKWb4_min_RKWb8;      /* ROT_KW_b[4] - ROT_KW_b[8] */
  float32 RKWc0_min_RKWc8;      /* ROT_KW_c[0] - ROT_KW_c[8] */
  float32 RKWc4_min_RKWc8;      /* ROT_KW_c[4] - ROT_KW_c[8] */

  uint8 InitStatus;           /* status byte for init flags */
} HLACamRot;

/* Needed for visu DLL since it is written in C++ */
#ifdef __cplusplus
extern "C"{
#endif

/*****************************************************************************
  FUNCTION 
*****************************************************************************/

/****************************************************************************
fN*  function name    : HLACamRotSetRot
f$*  ------------------------------------------------------------------------
fE*  input parameters : float32 angle_x    : rotation angle, x_w axis [Rad] 
fE*                   : float32 angle_y    : rotation angle, y_w axis [Rad]
fE*                   : float32 angle z    : rotation angle, z_w axis [Rad]
fE*                   : -
fA*  output parameters: -
fR*  return value     : -
fV*  used routines    : -
fF*  error handling   : -
f$*  ------------------------------------------------------------------------
fU*  autor            : Stefan Heinrich 
f$*  ------------------------------------------------------------------------
fB*  description      : generate ROT_W from rotation angles.
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
void HLACamRotSetRot(HLACamRot* cr, float32 x, float32 y, float32 z);

/****************************************************************************
fN*  function name    : HLACamRotSetT
f$*  ------------------------------------------------------------------------
fE*  input parameters : float32 x    : camera position, x coordinate [m]
fE*                   : float32 y    : camera position, y coordinate [m]
fE*                   : float32 z    : camera position, z coordinate [m]
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
void HLACamRotSetT(HLACamRot* cr, float32 x, float32 y, float32 z);
void HLACamRotGetT(const HLACamRot* cr, float32* x, float32* y, float32* z);
float32 HLACamRotGetTx (const HLACamRot* cr);
float32 HLACamRotGetTy (const HLACamRot* cr);
float32 HLACamRotGetTz (const HLACamRot* cr);

/****************************************************************************
fN*  function name    : HLACamRotSetFxFyXoYo
f$*  ------------------------------------------------------------------------
fE*  input parameters : float32 fx : focal length x-direction [Pix]    
fE*                   : float32 fy : focal length y-direction [Pix]   
fE*                   : float32 xo : principal point x-pos.   [Pix]   
fE*                   : float32 yo : principal point y-pos.   [Pix]   
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
void HLACamRotSetFxFyXoYo(HLACamRot* cr, float32 fx, float32 fy, float32 xo, float32 yo);
void HLACamRotGetFxFyXoYo(const HLACamRot* cr, float32* fx, float32* fy, float32* xo, float32* yo);
float32 HLACamRotGetFx (const HLACamRot* cr);
float32 HLACamRotGetFy (const HLACamRot* cr);
float32 HLACamRotGetXo (const HLACamRot* cr);
float32 HLACamRotGetYo (const HLACamRot* cr);

/****************************************************************************
fN*  function name    : get_Xb_3D / HLACamRotGetXb / HLACamRotGetxb / HLACamRotGetyb
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
void  HLACamRotGetXb(const HLACamRot* cr, float32* xb, float32* yb, float32 xw, float32 yw, float32 zw);
float32 HLACamRotGetxb(const HLACamRot* cr,                       float32 xw, float32 yw, float32 zw);
float32 HLACamRotGetyb(const HLACamRot* cr,                       float32 xw, float32 yw, float32 zw);

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
fB*                   : Xk   = ROT_W * ( Xw  -  T  )
fB*                   :          ~
fB*                   : [xk]            [xw]   [tx]
fB*                   : [yk] = ROT_K * ([yw] - [ty])
fB*                   : [zk]            [zw]   [tz]
fB*                   :
****************************************************************************/
void  HLACamRotGetXkXw (const HLACamRot* cr, float32* xk, float32* yk, float32* zk, float32 xw, float32 yw, float32 zw);

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
void  HLACamRotGetXwX (const HLACamRot* cr, float32  xw, float32* yw, float32* zw, float32 xb, float32 yb);
float32 HLACamRotGetywX (const HLACamRot* cr, float32  xw,                       float32 xb, float32 yb);
float32 HLACamRotGetzwX (const HLACamRot* cr, float32  xw,                       float32 xb, float32 yb);
void  HLACamRotGetXwY (const HLACamRot* cr, float32* xw, float32  yw, float32* zw, float32 xb, float32 yb);
float32 HLACamRotGetxwY (const HLACamRot* cr,            float32  yw,            float32 xb, float32 yb);
void  HLACamRotGetXwZ (const HLACamRot* cr, float32* xw, float32* yw, float32  zw, float32 xb, float32 yb);
float32 HLACamRotGetywZ (const HLACamRot* cr,                       float32  zw, float32 xb, float32 yb);

/****************************************************************************
fN*  function name    : HLACamRotGetJacobianXb
f$*  ------------------------------------------------------------------------
fE*  input parameters : xb, yb  : image coordinates
fE*                   : d       : distance to sensor
fE*                   : a, b, c : rotation angles
fE*                   : -
fA*  output parameters: xb_xw, yb_xw : derivatives of image coordinates
fA*                   : xb_yw, yb_yw      
fA*                   : xb_zw, yb_zw     
fA*                   : xb_a,  yb_a  : angular derivatives 
fA*                   : xb_b,  yb_b  
fA*                   : xb_c,  yb_c  
fR*  return value     : -
fV*  used routines    : -
fF*  error handling   : -
f$*  ------------------------------------------------------------------------
fU*  autor            : Stefan Heinrich
f$*  ------------------------------------------------------------------------
fB*  description      : compute partial derivatives of image coordinates 
fB*                   : (xb, yb) from world coordinate (xw, yw, zw, a, b, c)
fB*                   :        
fB*                   :                             [xb]   [FX*xk/zk + X0]
fB*                   : Xb   = P * Xk^* + X0   =>   [yb] = [FY*yk/zk + Y0]    
fB*                   :        
fB*                   :                                                 [xk]
fB*                   :             [1 0 0]       [xk^*]        [1 0 0] [yk]
fB*                   : Xk^* = 1/Zk [0 1 0] Xk => [yk^*] = 1/Zk [0 1 0] [zk]
fB*                   :        
fB*                   :                             [xk]          [xw] [tx]
fB*                   : Xk   = ROT_K*(Xw - T)  =>   [yk] = ROT_K*([yw]-[ty])
fB*                   :                             [zk]          [zw] [tz]
fB*                   :
fB*                   : first the partial derivative of Xk^* is computed
fB*                   :
fB*                   :         [1 0 0]        [Xk^*]        [1 0 0]
fB*                   : dXk^* = [0 1 0] dR*R^T [  1 ] + 1/zk [0 1 0] R dXw - 1/zk dzk Xk^*
fB*                   :
fB*                   : then the partial derivative of Xb
fB*                   :                           
fB*                   :                                               [1/fx(xb-x0)]             
fB*                   :                    [fx 0 -(xb-x0)]            [1/fy(yb-y0)]
fB*                   : dXb   = P * dXk^* =[0 fy -(yb-y0)] * ( dR*R^T [      1    ] + 1/zk*R*dXw ) 
fB*                   :                           
fB*                   :
****************************************************************************/

float32 HLACamRotGetJacobianxbxwXb(const HLACamRot* cr, float32 xb, float32 yb, float32 d);
float32 HLACamRotGetJacobianxbywXb(const HLACamRot* cr, float32 xb, float32 yb, float32 d);
float32 HLACamRotGetJacobianxbzwXb(const HLACamRot* cr, float32 xb, float32 yb, float32 d);
float32 HLACamRotGetJacobianybxwXb(const HLACamRot* cr, float32 xb, float32 yb, float32 d);
float32 HLACamRotGetJacobianybywXb(const HLACamRot* cr, float32 xb, float32 yb, float32 d);
float32 HLACamRotGetJacobianybzwXb(const HLACamRot* cr, float32 xb, float32 yb, float32 d);

float32 HLACamRotGetJacobianxbcXb(const HLACamRot* cr, float32 xb, float32 yb);
float32 HLACamRotGetJacobianybbXb(const HLACamRot* cr, float32 xb, float32 yb);

void  HLACamRotGetJacobianXb(const HLACamRot* cr, 
                             float32 xb, float32* xb_xw, float32* xb_yw, float32* xb_zw, float32* xb_a,  float32* xb_b,  float32* xb_c,
                             float32 yb, float32* yb_xw, float32* yb_yw, float32* yb_zw, float32* yb_a,  float32* yb_b,  float32* yb_c);
void HLACamRotGetJacobianxbaxbcybaybcXb(const HLACamRot* cr, float32* xb_a, float32* xb_c, float32* yb_a, float32* yb_c, float32 xb, float32 yb);
void HLACamRotGetJacobianxbxwxbywybxwybywXb(const HLACamRot* cr, float32* xb_xw, float32* xb_yw, float32* yb_xw, float32* yb_yw, float32 xb, float32 yb);
void HLACamRotGetJacobianxbcybaxbxwxbywybxwybywXb(const HLACamRot* cr, float32* xb_xw, float32* xb_yw, float32* yb_xw, float32* yb_yw, float32* xb_c, float32* yb_a, float32 xb, float32 yb, float32 d);

#ifdef __cplusplus
}
#endif
/* avoid cyclic binding ---------------------------------------------------*/
#endif
