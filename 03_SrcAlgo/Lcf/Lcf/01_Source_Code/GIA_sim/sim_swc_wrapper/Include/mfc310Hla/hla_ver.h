/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_VER_INCLUDED
#define HLA_VER_INCLUDED


/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/


/* Component version number as 4 byte BCD MM.SS.F1.F2
  MM: Main version number. This number is dependent on the external component 
      interface i.e. interface change enforces an increase. The number 
      starts with "01".
  SS: Sub version number. This number reflects functional changes within the main
      version of the component. The number starts with "00" at every new main 
      version number step. 
  F1: Bug fix level number. This number indicates exclusively error-correcting changes.
      If the sub version number in incremented the bug fix level restarts with "00".
  F2: Bug fix sub-level number.
*/
#define HLA_SW_VERSION_NUMBER_MAIN      5U
#define HLA_SW_VERSION_NUMBER_SUB      13U
#define HLA_SW_VERSION_NUMBER_BUGFIX1   1U
#if (HLA_PROJECT == HLA_PROJECT_SRLCAM4T0)
#define HLA_SW_VERSION_NUMBER_BUGFIX2   10U
#else
#define HLA_SW_VERSION_NUMBER_BUGFIX2   0U
#endif

/*! HLA version number: */
#define HLA_SW_VERSION_NUMBER ((HLA_SW_VERSION_NUMBER_MAIN<<24) | (HLA_SW_VERSION_NUMBER_SUB<<16) | (HLA_SW_VERSION_NUMBER_BUGFIX1<<8) | (HLA_SW_VERSION_NUMBER_BUGFIX2))

#define HLA_APPL_VERSION_NUMBER_GENERATION  0x4U
#if (HLA_PROJECT == HLA_PROJECT_SRLCAM4T0)
#define HLA_APPL_VERSION_NUMBER_CUSTOMER    0x1U
#else
#define HLA_APPL_VERSION_NUMBER_CUSTOMER    0xBU
#endif
#define HLA_APPL_VERSION_NUMBER_PLATFORM1   0x0U
#define HLA_APPL_VERSION_NUMBER_PLATFORM2   0x0U


/*! HLA application version number: */
#define HLA_APPL_VERSION_NUMBER  ((HLA_APPL_VERSION_NUMBER_GENERATION<<24) | (HLA_APPL_VERSION_NUMBER_CUSTOMER<<16) | (HLA_APPL_VERSION_NUMBER_PLATFORM1<<8) | (HLA_APPL_VERSION_NUMBER_PLATFORM2))

#if (HLA_PROJECT == HLA_PROJECT_SRLCAM4T0)
#define HLA_SW_VERSION_INFO                 "SRLCam4T0 Toyota R2.2 HLA"
#else
#define HLA_SW_VERSION_INFO                 "SMFC4B0 BMW I390 HLA"
#endif

/* avoid cyclic binding ---------------------------------------------------*/
#endif /* #ifndef HLA_VER_INCLUDED */
