/**********************************************************************************************************************
  COMPANY:     Continental Teves AG & Co. OHG
  PROJECT:     PROJECT-INDEPENDENT
  CPU:         Aurix TC389QP
  MODULNAME:   Scu
  VERSION:     $Revision: 1.0 $
 *********************************************************************************************************************/

/*
 *  \file       ScuWdt.h
 *  \brief      Interfaces to global Endinit as well as global Safety Endinit protection (header file)
 *  \date       2019-03-14
 *  \copyright  Continental AG
 *
 *  Unit provides the interfaces to handle the global Endinit and global Safety Endinit protection of the registers.
 *  The interfaces has to be used once the system/safety related register have to be written/modified.
 *
 */

#ifndef SCUWDT_H
#define SCUWDT_H

#ifdef __cplusplus
extern "C"
{
#endif

/* ================================================================================================================= */
/*                                            QAC Warnings Suppressions                                              */
/*                                           (Global Files Suppressions)                                             */
/* ================================================================================================================= */

/* ================================================================================================================= */
/*                                                Include Files                                                      */
/* ================================================================================================================= */
#include <Platform_Types.h>

/** @defgroup Productive Productive code
 *  @{
 */

/** @defgroup ScuWdt ScuWdt
 *  @{
 */

/* ================================================================================================================= */
/*                                               Defines & Macros                                                    */
/* ================================================================================================================= */

/* ================================================================================================================= */
/*                                                 Public Types                                                      */
/* ================================================================================================================= */

/* ================================================================================================================= */
/*                                          Public Variables Declarations                                            */
/* ================================================================================================================= */

/* ================================================================================================================= */
/*                                           Public Functions Declarations                                           */
/* ================================================================================================================= */

/**
 *  \brief  Clears global Endinit protection \n
 *
 *   The function clears the global Endinit protection.
 *
 *  \startuml
 *     start
 *     :get Password;
 *     :clear global Endinit bit using password;
 *     :wait until global Endinit bit is cleared;
 *     stop
 *  \enduml
 *
 *  \globals
 *  NA - no global variables in use
 *
 *  \InOutCorrelation
 *  No correlation with global variables.
 *
 *  \pre         On the multicore platforms it has to be ensured by the user of this function that only once core
 *               unlock and lock back the global Endinit protection.
 *               The user has to ensure short execution time till the global Endinit protection is locked back.
 *               In case execution time with unlocked global Endinit protection will be exceeded,
 *               time-out will be generated and respective alarm will be reported to the SMU.
 *
 *  \post        Global Endinit protection unlocked on success. On fail, it blocks the caller CPU in endless loop.
 *
 *  \param [in]  void
 *
 *  \return      void
 *
 *  \testmethod
 *   - Tested indirectly within CorTst_*_LLD.c, RamTst_*_LLD.c modules Software Requirement Tests.
 *
 *  \satisfy{}
 *
 */
extern void ScuWdt_EndinitClear( void );

/**
 *  \brief  Sets global Endinit protection \n
 *
 *   The function sets the global Endinit protection.
 *
 *  \startuml
 *     start
 *     :get Password;
 *     :set global Endinit bit using password;
 *     :wait until global Endinit bit is set;
 *     stop
 *  \enduml
 *
 *  \globals
 *  NA - no global variables in use
 *
 *  \InOutCorrelation
 *  No correlation with global variables.
 *
 *  \pre         On the multicore platforms it has to be ensured by the user of this function that only once core
 *               unlock and lock back the global Endinit protection.
 *
 *  \post        Global Endinit protection locked on success. On fail, it blocks the caller CPU in end-less loop.
 *
 *  \param [in]  void
 *
 *  \return      void
 *
 *  \testmethod
 *   - Tested indirectly within CorTst_*_LLD.c, RamTst_*_LLD.c modules Software Requirement Tests.
 *
 *  \satisfy{}
 *
 */
extern void ScuWdt_EndinitSet( void );

/**
 *  \brief  Clears global Safety Endinit protection \n
 *
 *   The function clears the global Safety Endinit protection mechanism.
 *
 *  \startuml
 *     start
 *     :get Password;
 *     :clear Safety Endinit bit using password;
 *     :wait until Endinit bit is cleared;
 *     stop
 *  \enduml
 *
 *  \globals
 *  NA - no global variables in use
 *
 *  \InOutCorrelation
 *  No correlation with global variables.
 *
 *  \pre         On the multicore platforms it has to be ensured by the user of this function that only once core
 *               unlock and lock back the global Safety Endinit protection.
 *               The user has to ensure short execution time till the global Safety Endinit protection is locked back.
 *               In case execution time with unlocked global Safety Endinit protection will be exceeded,
 *               time-out will be generated and respective alarm will be reported to the SMU.
 *
 *  \post        Global Safety Endinit protection unlocked on success.
 *               On fail, it blocks the caller CPU in endless loop.
 *
 *  \param [in]  void
 *
 *  \return      void
 *
 *  \testmethod
 *   - Tested indirectly within CorTst_*_LLD.c, RamTst_*_LLD.c modules Software Requirement Tests.
 *
 *  \satisfy{}
 *
 */
extern void ScuWdt_SafetyEndinitClear( void );

/**
 *  \brief  Sets global Safety Endinit protection \n
 *
 *   The function sets the global Safety Endinit protection mechanism.
 *
 *  \startuml
 *     start
 *     :get Password;
 *     :set Safety Endinit bit using password;
 *     :wait until Safety Endinit bit is set;
 *     stop
 *  \enduml
 *
 *  \globals
 *  NA - no global variables in use
 *
 *  \InOutCorrelation
 *  No correlation with global variables.
 *
 *  \pre         On the multicore platforms it has to be ensured by the user of this function that only once core
 *               unlock and lock back the global Safety Endinit protection.
 *
 *  \post        Global Safety Endinit protection locked on success.
 *               On fail, it blocks the caller CPU in end-less loop.
 *
 *  \param [in]  void
 *
 *  \return      void
 *
 *  \testmethod
 *   - Tested indirectly within CorTst_*_LLD.c, RamTst_*_LLD.c modules Software Requirement Tests.
 *
 *  \satisfy{}
 *
 */
extern void ScuWdt_SafetyEndinitSet( void );

/**
 *  \brief  Clears Cpu0 Endinit protection \n
 *
 *   The function clears the Cpu0 Endinit protection mechanism.
 *
 *  \startuml
 *     start
 *     :get Password;
 *     :get Rel value;
 *     :write the password to unlock the register(Password access);
 *     :write the Rel value to the register(Modify access);
 *     :wait until Endinit bit is cleared;
 *     stop
 *  \enduml
 *
 *  \globals
 *  NA - no global variables in use
 *
 *  \InOutCorrelation
 *  No correlation with global variables.
 *
 *  \pre         On the multicore platforms it has to be ensured by the user of this function that only one core
 *               unlock and lock back the Cpu0 protection.
 *               The user has to ensure short execution time till the global Safety Endinit protection is locked back.
 *               In case execution time with unlocked Cpu0 Endinit protection will be exceeded,
 *               time-out will be generated and respective alarm will be reported to the SMU.
 *
 *  \post        Cpu0 Endinit protection unlocked on success.
 *               On fail, it blocks the caller CPU in endless loop.
 *
 *  \param [in]  void
 *
 *  \return      void
 *
 *  \testmethod
 *   - Software Requirement Test.
 *
 *  \satisfy{}
 *
 */
extern void ScuWdt_Cpu0EndinitClear( void );

/**
 *  \brief  Sets Cpu0 Endinit protection \n
 *
 *   The function sets the Cpu0 Endinit protection mechanism.
 *
 *  \startuml
 *     start
 *     :get Password;
 *     :get Rel value;
 *     :write the password to unlock the register(Password access);
 *     :write the Rel value to the register(Modify access);
 *     :wait until Endinit bit is set;
 *     stop
 *  \enduml
 *
  *  \globals
 *  NA - no global variables in use
 *
 *  \InOutCorrelation
 *  No correlation with global variables.
 *
 *  \pre         On the multicore platforms it has to be ensured by the user of this function that only one core
 *               unlock and lock back the Cpu0 protection.
 *
 *  \post        Cpu0 Endinit protection locked on success.
 *               On fail, it blocks the caller CPU in endless loop.
 *
 *  \param [in]  void
 *
 *  \return      void
 *
 *  \testmethod
 *   - Tested indirectly within CorTst_*_LLD.c, RamTst_*_LLD.c modules Software Requirement Tests.
 *
 *  \satisfy{}
 *
 */
extern void ScuWdt_Cpu0EndinitSet( void );

/**
 *  \brief  Clears Cpu1 Endinit protection \n
 *
 *   The function clears the Cpu1 Endinit protection mechanism.
 *
 *  \startuml
 *     start
 *     :get Password;
 *     :get Rel value;
 *     :write the password to unlock the register(Password access);
 *     :write the Rel value to the register(Modify access);
 *     :wait until Endinit bit is cleared;
 *     stop
 *  \enduml
 *
 *  \globals
 *  NA - no global variables in use
 *
 *  \InOutCorrelation
 *  No correlation with global variables.
 *
 *  \pre         On the multicore platforms it has to be ensured by the user of this function that only one core
 *               unlock and lock back the Cpu1 protection.
 *               The user has to ensure short execution time till the global Safety Endinit protection is locked back.
 *               In case execution time with unlocked Cpu1 Endinit protection will be exceeded,
 *               time-out will be generated and respective alarm will be reported to the SMU.
 *
 *  \post        Cpu1 Endinit protection unlocked on success.
 *               On fail, it blocks the caller CPU in endless loop.
 *
 *  \param [in]  void
 *
 *  \return      void
 *
 *  \testmethod
 *   - Tested indirectly within CorTst_*_LLD.c, RamTst_*_LLD.c modules Software Requirement Tests.
 *
 *  \satisfy{}
 *
 */
extern void ScuWdt_Cpu1EndinitClear( void );

/**
 *  \brief  Sets Cpu1 Endinit protection \n
 *
 *   The function sets the Cpu1 Endinit protection mechanism.
 *
 *  \startuml
 *     start
 *     :get Password;
 *     :get Rel value;
 *     :write the password to unlock the register(Password access);
 *     :write the Rel value to the register(Modify access);
 *     :wait until Endinit bit is set;
 *     stop
 *  \enduml
 *
 *  \globals
 *  NA - no global variables in use
 *
 *  \InOutCorrelation
 *   - Tested indirectly within CorTst_*_LLD.c, RamTst_*_LLD.c modules Software Requirement Tests.
 *
 *  \pre         On the multicore platforms it has to be ensured by the user of this function that only one core
 *               unlock and lock back the Cpu1 protection.
 *
 *  \post        Cpu1 Endinit protection locked on success.
 *               On fail, it blocks the caller CPU in endless loop.
 *
 *  \param [in]  void
 *
 *  \return      void
 *
 *  \testmethod
 *   - Software Requirement Test.
 *
 *  \satisfy{}
 *
 */
extern void ScuWdt_Cpu1EndinitSet( void );

#ifdef __cplusplus
}
#endif
#endif /* SCUWDT_H */

/** @} doxygen end group definition  */
/** @} doxygen end group definition  */

/* ================================================================================================================= */
/*                                                     End of File                                                   */
/* ================================================================================================================= */
