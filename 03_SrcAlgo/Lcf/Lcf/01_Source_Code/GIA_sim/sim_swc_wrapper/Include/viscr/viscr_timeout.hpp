/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_timeout.hpp  

  DESCRIPTION:    Timeout management

  AUTHOR:         L. GARCIA

  CREATION DATE:  31.05.2011

  VERSION:        $Revision: 1.1 $

  CHANGES:        $Log: viscr_timeout.hpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:39CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:39CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.9 2013/03/11 14:28:31CET Ruland, Thomas (uidw0251) 
  CHANGES:        - added sac_legacy_typeDefs.h to reactivate old style typedefs
  CHANGES:        - Added comments -  uidw0251 [Mar 11, 2013 2:28:32 PM CET]
  CHANGES:        Change Package : 173649:1 http://mks-psad:7002/im/viewissue?selection=173649
  CHANGES:        Revision 1.8 2013/01/24 14:05:17CET Pfitzer, Martin (uidu4871) 
  CHANGES:        using algo_type instead of cct_type
  CHANGES:        --- Added comments ---  uidu4871 [Jan 24, 2013 2:05:18 PM CET]
  CHANGES:        Change Package : 131461:3 http://mks-psad:7002/im/viewissue?selection=131461
  CHANGES:        Revision 1.7 2012/06/26 14:09:23CEST Godreau, Bertrand (uid28828) 
  CHANGES:        Add code review findings
  CHANGES:        --- Added comments ---  uid28828 [Jun 26, 2012 2:09:23 PM CEST]
  CHANGES:        Change Package : 130169:2 http://mks-psad:7002/im/viewissue?selection=130169
  CHANGES:        Revision 1.6 2012/06/05 19:08:40CEST Garcia, Lucien (uid26778) 
  CHANGES:        Add intialisation inside the constructor
  CHANGES:        --- Added comments ---  uid26778 [Jun 5, 2012 7:08:40 PM CEST]
  CHANGES:        Change Package : 125595:1 http://mks-psad:7002/im/viewissue?selection=125595
  CHANGES:        Revision 1.5 2011/11/10 19:03:17CET Spruck, Jochen (spruckj) 
  CHANGES:        Bug fix check for driven distance to set the write flags for the temp table
  CHANGES:        --- Added comments ---  spruckj [Nov 10, 2011 7:03:17 PM CET]
  CHANGES:        Change Package : 87605:1 http://mks-psad:7002/im/viewissue?selection=87605
  CHANGES:        Revision 1.4 2011/11/10 17:48:17CET Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Overload functions with float values instead of ui64
  CHANGES:        --- Added comments ---  spruckj [Nov 10, 2011 5:48:17 PM CET]
  CHANGES:        Change Package : 87605:1 http://mks-psad:7002/im/viewissue?selection=87605
  CHANGES:        Revision 1.3 2011/10/04 10:20:47CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Remove PC lints warnings
  CHANGES:        --- Added comments ---  uid26778 [Oct 4, 2011 10:20:47 AM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.2 2011/09/29 16:31:30CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Remove warnings on timeout mng
  CHANGES:        --- Added comments ---  uid26778 [Sep 29, 2011 4:31:30 PM CEST]
  CHANGES:        Change Package : 79047:3 http://mks-psad:7002/im/viewissue?selection=79047
  CHANGES:        Revision 1.1 2011/09/29 10:37:58CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj


**************************************************************************** */


#ifndef _viscr_timeout_hpp_
#define _viscr_timeout_hpp_

#include "sac_legacy_typeDefs.h"
#include <viscr_types.hpp>
#include "algo_glob.h"

namespace SAC {
  class viscr_timeout
  {
  public:
    /** Default constructor to silence the compiler. */
    viscr_timeout():
         m_state(VISCR_TIMEOUT_STATE_STOP),
         m_start_value(0L),
         m_timeout_value(0L),
         m_fstart_value(0.0F),
         m_ftimeout_value(0.0F)
         {}
    ~viscr_timeout() {}

    void viscr_timeout_start( const ui8_t enable, const ui64_t start_value, const ui64_t timeout_value);
    void viscr_timeout_start( const bool_t enable, const f32_t start_value, const f32_t timeout_value);
    ui8_t viscr_timeout_check( const ui64_t current_value) const;
    bool_t viscr_timeout_check( const f32_t current_value) const;
    void viscr_timeout_restart( const ui64_t current_value);
    void viscr_timeout_restart( const f32_t current_value);
    void viscr_timeout_stop( );

  private:

  /* ~CodeReview ~ID:295105b2f040c08d735518d684ebfac4 ~Reviewer:CW01\uid28828 ~Date:21/06/2012 ~Priority:3 ~Comment:VISCR_TIMEOUT_STATE_REACHED never used */
    typedef enum
    {
      VISCR_TIMEOUT_STATE_STOP      = 0,  
      VISCR_TIMEOUT_STATE_RUNNIG    = 1,  
      VISCR_TIMEOUT_STATE_REACHED   = 2  
    } viscr_timeout_state_t;
    viscr_timeout_state_t m_state;
    ui64_t m_start_value;
    ui64_t m_timeout_value;
    f32_t m_fstart_value;
    f32_t m_ftimeout_value;
  };
}

#endif

