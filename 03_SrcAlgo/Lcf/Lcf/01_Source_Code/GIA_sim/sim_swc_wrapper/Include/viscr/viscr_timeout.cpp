/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_timeout.cpp  

  DESCRIPTION:    Timeout management

  AUTHOR:         L. GARCIA

  CREATION DATE:  31.05.2011

  VERSION:        $Revision: 1.1 $

  CHANGES:        $Log: viscr_timeout.cpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:39CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:38CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.8 2012/07/04 17:14:12CEST Behrens, Alexander (uidv2823) 
  CHANGES:        add code coverage tags (always false/true cases)
  CHANGES:        - Added comments -  uidv2823 [Jul 4, 2012 5:14:12 PM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.7 2012/07/03 17:33:02CEST Behrens Alexander (uidv2823) (uidv2823) 
  CHANGES:        add code coverage tags
  CHANGES:        --- Added comments ---  uidv2823 [Jul 3, 2012 5:33:02 PM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.6 2012/06/26 14:09:22CEST Godreau, Bertrand (uid28828) 
  CHANGES:        Add code review findings
  CHANGES:        --- Added comments ---  uid28828 [Jun 26, 2012 2:09:22 PM CEST]
  CHANGES:        Change Package : 130169:2 http://mks-psad:7002/im/viewissue?selection=130169
  CHANGES:        Revision 1.5 2011/11/10 19:03:17CET Spruck, Jochen (spruckj) 
  CHANGES:        Bug fix check for driven distance to set the write flags for the temp table
  CHANGES:        --- Added comments ---  spruckj [Nov 10, 2011 7:03:17 PM CET]
  CHANGES:        Change Package : 87605:1 http://mks-psad:7002/im/viewissue?selection=87605
  CHANGES:        Revision 1.4 2011/11/10 17:48:17CET Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Overload functions with float values instead of ui64
  CHANGES:        --- Added comments ---  spruckj [Nov 10, 2011 5:48:17 PM CET]
  CHANGES:        Change Package : 87605:1 http://mks-psad:7002/im/viewissue?selection=87605
  CHANGES:        Revision 1.3 2011/10/04 10:20:46CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Remove PC lints warnings
  CHANGES:        --- Added comments ---  uid26778 [Oct 4, 2011 10:20:46 AM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.2 2011/09/29 16:31:30CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Remove warnings on timeout mng
  CHANGES:        --- Added comments ---  uid26778 [Sep 29, 2011 4:31:30 PM CEST]
  CHANGES:        Change Package : 79047:3 http://mks-psad:7002/im/viewissue?selection=79047
  CHANGES:        Revision 1.1 2011/09/29 10:37:57CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/Kernel/project.pj

  

**************************************************************************** */


#include <viscr_timeout.hpp>

namespace SAC{

void SAC::viscr_timeout::viscr_timeout_start( const ui8_t enable, const ui64_t start_value, const ui64_t timeout_value)
{
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Check if timeout is already running. */
  if ( m_state != VISCR_TIMEOUT_STATE_RUNNIG)
    {
    if (enable == 1U)
      {
      m_state = VISCR_TIMEOUT_STATE_RUNNIG;
      m_start_value = start_value;
      m_timeout_value = timeout_value;
      }
    else
      {
      m_state = VISCR_TIMEOUT_STATE_STOP;
      }
    }
}

void SAC::viscr_timeout::viscr_timeout_start( const bool_t enable, const f32_t start_value, const f32_t timeout_value)
{
  if ( m_state != VISCR_TIMEOUT_STATE_RUNNIG)
  {
    /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Check if function is enabled. */
    if (enable == TRUE)
    {
      m_state = VISCR_TIMEOUT_STATE_RUNNIG;
      m_fstart_value = start_value;
      m_ftimeout_value = timeout_value;
    }
    else
    {
      m_state = VISCR_TIMEOUT_STATE_STOP;
    }
  }
}

ui8_t SAC::viscr_timeout::viscr_timeout_check(const ui64_t current_value) const
/* ~CodeReview ~ID:f1396f8d777a19c5166b13b915753ade ~Reviewer:CW01\uid28828 ~Date:21/06/2012 ~Priority:3 ~Comment:case current_value < m_start_value not managed */
{
  ui8_t timeout = 0U;
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Parameter check. */
  if ( (m_state == VISCR_TIMEOUT_STATE_RUNNIG) &&((current_value - m_start_value) >= m_timeout_value))
    {
    timeout = 1U;
    }
  return timeout;
}

bool_t SAC::viscr_timeout::viscr_timeout_check(const f32_t current_value) const
{
  bool_t timeout = FALSE;
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 04.07.2012 reason: Parameter check. */
  if ( (m_state == VISCR_TIMEOUT_STATE_RUNNIG) &&((current_value - m_fstart_value) >= m_ftimeout_value))
  {
    timeout = TRUE;
  }
  return timeout;
}

/* <ln_offset:+1to+7 COVERAGE reviewer name: Alexander Behrens date: 03.07.2012 reason: Covered by condition in function "i32_SACRun". */
void SAC::viscr_timeout::viscr_timeout_restart(const ui64_t current_value)
{
  if (m_state == VISCR_TIMEOUT_STATE_RUNNIG) 
  {
    m_start_value = current_value;
  }
}

/* <ln_offset:+1to+7 COVERAGE reviewer name: Alexander Behrens date: 03.07.2012 reason: Function is covered by "TempModel::SACTempModelCompletePendingWrites". */
void SAC::viscr_timeout::viscr_timeout_restart(const f32_t current_value)
{
  if (m_state == VISCR_TIMEOUT_STATE_RUNNIG) 
  {
    m_fstart_value = current_value;
  }
}

void SAC::viscr_timeout::viscr_timeout_stop()
{
  m_state = VISCR_TIMEOUT_STATE_STOP;
}

}





