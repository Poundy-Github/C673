/*! \file **********************************************************************

COMPANY:        Continental AG

PROJECT:        MFC300

CPU:            

COMPONENT:      SAC - Stereo Auto Calibration

MODULNAME:      viscr_sad.hpp 

DESCRIPTION:    Sum of Absolute Differences

AUTHOR:         L. GARCIA

CREATION DATE:  30.08.2011

VERSION:        $Revision: 1.1 $
CHANGES:        $Log: viscr_sad.hpp  $
CHANGES:        Revision 1.1 2021/12/13 17:28:35CET Wang, David (Wangd3) 
CHANGES:        Initial revision
CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
CHANGES:        Revision 1.0 2017/03/03 10:40:28CET Sorge, Sven (uidg3181) 
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


#ifndef _viscr_sad_hpp_
#define _viscr_sad_hpp_

#include <viscr_types.hpp>
#include <viscr_image.hpp>

#define VISCR_SAD_BLOCK_SIZE 10 // size of SAD window in pixels
#define VISCR_SAD_BLOCK_RAD (VISCR_SAD_BLOCK_SIZE/2) // size of SAD window in pixels
#define VISCR_SAD_MIN_THRESHOLD (11*11*16*2)
#define VISCR_SAD_ROI (40) 

extern void viscr_sad_process(
    const viscr_image & k0, 
    viscr_coord u0,
    viscr_coord v0,
    const viscr_image & k1, 
    const viscr_float u1,
    const viscr_float v1,
    viscr_float &u1_sad,
    viscr_float &v1_sad
    );


#endif

