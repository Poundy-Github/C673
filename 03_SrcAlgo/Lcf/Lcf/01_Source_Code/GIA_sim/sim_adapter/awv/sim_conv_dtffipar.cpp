/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter em

  MODULNAME:       sim_conv_dtffipar.cpp

  DESCRIPTION:

  AUTHOR:          Thomas Berndt

  CREATION DATE:   30.1.2015

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_dtffipar.cpp  $
  CHANGES:         Revision 1.1 2021/12/13 17:20:32CET Wang, David (Wangd3) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/awv/project.pj
  CHANGES:         Revision 1.1 2017/08/10 13:14:57CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/awv/project.pj
  CHANGES:         Revision 1.3 2015/05/22 10:58:29CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         + Version 3
  CHANGES:         - Added comments -  berndtt1 [May 29, 2015 10:04:16 AM CEST]
  CHANGES:         Change Package : 276620:7 http://mks-psad:7002/im/viewissue?selection=276620
  CHANGES:         Revision 1.2 2015/02/05 11:33:34CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         * changed default values
  CHANGES:         --- Added comments ---  berndtt1 [Feb 17, 2015 6:43:41 AM CET]
  CHANGES:         Change Package : 276620:4 http://mks-psad:7002/im/viewissue?selection=276620
  CHANGES:         Revision 1.1 2015/01/30 11:54:16CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/awv/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_adapter_cfg.h"
#include "sim_conv_dtffipar.h"
#include "sim_versioninfo_impl.h"

/**
* @brief The standard AUTOSAR type boolean shall be implemented on basis of an eight bits long
*        unsigned integer.
* @implements boolean_type
*/
typedef unsigned char boolean;
/* Boolean types */
typedef boolean Boolean                                                        /* [Satisfies_rte sws 1188] */;


namespace DTFfiPar_V1
{
  typedef unsigned __int16 UInt16_A8[8];                                       /* [Satisfies_rte sws 1189] */
  typedef float Float_A8[8];                                                   /* [Satisfies_rte sws 1189] */

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    UInt16_A8 X;
    Float_A8 Y;
  } UInt16_Float_A8;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    //Boolean HAUPTWARNUNG_ENABLE_KOMPLETT;                                    /* p_b_AWV_Enable_Hauptwarnung_komplett */
    unsigned __int16 HAUPTWARNUNG_DAUER;                                       /* p_t_AWV_Hauptwarnung */
    float HAUPTWARNUNG_AAUTO_MIN;                                              /* p_a_AWV_max_Verz_Ruck */
    unsigned __int8 HAUPTWARNUNG_RUCKPROFIL1_V_MAX;                            /* p_v_AWV2_Ruck_1 */
    unsigned __int8 HAUPTWARNUNG_RUCKPROFIL2_V_MAX;                            /* p_v_AWV2_Ruck_2 */
    unsigned __int8 HAUPTWARNUNG_RUCKPROFIL3_V_MAX;                            /* p_v_AWV2_Ruck_3 */
    unsigned __int8 HAUPTWARNUNG_RUCKPROFIL4_V_MAX;                            /* p_v_AWV2_Ruck_4 */
    unsigned __int8 HAUPTWARNUNG_RUCKPROFIL5_V_MAX;                            /* p_v_AWV2_Ruck_5 */
    unsigned __int8 HAUPTWARNUNG_RUCKPROFIL6_V_MAX;                            /* p_v_AWV2_Ruck_6 */
    //Boolean VORWARNUNG_ENABLE_KOMPLETT;                                      /* p_b_AWV_Enable_Vorwarnung_komplett */
    unsigned __int16 VORWARNUNG_DAUER;                                         /* p_t_AWV_Vorwarnung */
    unsigned __int16 AWV_PRIOWARNUNG_DAUER_MIN;                                /* p_t_AWV_Warnprio_min */
    //Boolean ABSTANDSWARNUNG_ENABLE_KOMPLETT;                                 /* p_b_AWV_Enable_Abstandswarnung_komplett */
    //unsigned __int8 ABSTANDSWARNUNG_V_MIN;                                   /* p_v_AWV_Abstandswarnung_min */
    //unsigned __int8 ABSTANDSWARNUNG_V_ABBRUCH;                               /* p_v_AWV_Abstandswarnung_Abbruch */
    //unsigned __int16 ABSTANDSWARNUNG_UEBERTRETEN_DAUER;                      /* p_t_AWV_AbstWarnung_EntprellungUebertreten */
  } DTFfiWarnungPar;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned __int16 HBA_VERLAENGERUNG_DAUER;                                  /* p_t_AWV_HBA_Verlaengerung */
  } DTFfiHbaPar;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned __int16 PREFILL_DAUER_MAX;                                        /* p_t_AWV_Prefill_max */
    unsigned __int16 PREFILL_DAUER_MIN;                                        /* p_t_AWV_Prefill_min */
    //Boolean ECD_ANLAUF_ENABLE_KOMPLETT;                                      /* p_b_AWV_Enable_ECD_Anlauf_komplett */
    //unsigned __int16 ECD_ANLAUF_DAUER_MAX;                                   /* p_t_AWV_ECD_Anlauf_max */
  } DTFfiPrefillPar;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    Boolean VFGS_VERFUEGBAR;                                                   /* p_b_AWV_Enable_vFGS_komplett */
    //unsigned __int8 VFGS_WARNUNG_V_MIN;                                      /* p_v_vFGS_Warn_min */
    unsigned __int8 VFGS_EINGRIFFE_V_MAX;                                      /* p_v_vFGS_allg_max */
    unsigned __int8 VFGS_V_ABBAU_MAX;                                          /* p_v_vFGS_Teilbremsung_vDelta_max */
  } DTFfiVFgsPar;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned __int8 AWV_WARNUNGEN_V_MIN;                                       /* p_v_AWV_Warn_min */
    unsigned __int16 AWV_EINGRIFFE_V_MIN;                                      /* p_v_AWV_allg_min */
    unsigned __int16 AWV_EINGRIFFE_V_MAX;                                      /* p_v_AWV_allg_max */
    unsigned __int8 AWV_EINGRIFFE_SO_V_MAX;                                    /* p_v_AWV_v_max_SO */
    unsigned __int8 AWV_EINGRIFFE_FAHRPEDAL_MAX;                               /* p_f_AWV_Fahrpedal_max */
    unsigned __int16 AWV_EINGRIFFE_FAHRPEDALGRADIENT_ABBRUCH;                  /* p_ft_AWV_AbbruchGradientFahrpedal */
    unsigned __int16 AWV_EINGRIFFE_LENKRADWINKEL_MAX;                          /* p_r_AWV_Lenkradwinkel_max */
    unsigned __int16 AWV_EINGRIFFE_LENKRADWINKEL_ABBRUCH;                      /* p_r_AWV_Lenkradwinkel_abbruch */
    unsigned __int16 AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_MAX;           /* p_rv_AWV_Lenkradwinkelgeschwindigkeit_max */
    unsigned __int16 AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_ABBRUCH;       /* p_rv_AWV_Lenkradwinkelgeschwindigkeit_abbruch */
    unsigned __int16 AWV_EINGRIFFE_LENKENTPRELLUNG_DAUER;                      /* p_t_AWV_Lenkentprellung */
    unsigned __int16 AWV_SPERRZEIT;                                            /* p_t_AWV_Sperrzeit */
    UInt16_Float_A8 FAHRER_BREMST_DEUTLICH_VEGO_A_KENNLINIE;                   /* p_a_AWV_Fahrer_bremst_deutlich */
    unsigned __int8 FAHRER_BREMST_DEUTLICH_VMIN_UNTERDRUECKUNG_ATB;            /* p_v_AWV_Fahrer_bremst_deutlich */
    unsigned __int16 INSTABILITAET_NACHLAUF_DAUER;                             /* p_t_AWV_Instabilitaet_Nachlauf [ms] */
    unsigned __int16 UEBERHOLWUNSCH_BLINKER_DAUER;                             /* p_t_AWV_Ueberholwunsch_Blinker */
    unsigned __int8 UEBERHOLWUNSCH_FAHRPEDAL_MIN;                              /* p_f_AWV_Overtake_min */
    unsigned __int8 UEBERHOLWUNSCH_FAHRPEDAL_MAX;                              /* p_f_AWV_Overtake_max */
    unsigned __int16 UEBERHOLWUNSCH_DAUER_MAX;                                 /* p_t_AWV_Overtake_max */
    unsigned __int16 UEBERSTEUERWUNSCH_FAHRERBREMST_ABBRUCH_DAUER;             /* p_t_AWV_FahrerBremst_Abbruch [ms] */
    unsigned __int16 UEBERSTEUERWUNSCH_FAHRERBREMST_ENTPRELLUNG_DAUER;         /* p_t_AWV_FahrerBremst_Entprellung [ms] */
    unsigned __int16 UEBERSTEUERWUNSCH_FAHRPEDAL_ENTPRELLUNG_DAUER;            /* p_t_AWV_Fahrpedal_Entprellung [ms] */
    unsigned __int16 UEBERSTEUERWUNSCH_FAHRERREAKTION_ENTPRELLUNG_DAUER;       /* p_t_AWV_Wait4DriverReaction [ms] */
    unsigned __int16 UEBERSTEUERWUNSCH_FAHRERREAKTION_DAUER_MAX;               /* p_t_AWV_WaitMax4DriverReaction [ms] */
    unsigned __int8 UEBERSTEUERWUNSCH_FAHRERREAKTION_ZWEI_FAHRPEDAL;           /* p_f_AWV_FahrpedalWert4SecondDrriverReaction [Prozent] */
    unsigned __int8 UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_1;               /* p_f_AWV_Nulldurchgang_Fahrpedal_1 */
    unsigned __int8 UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_2;               /* p_f_AWV_Nulldurchgang_Fahrpedal_2 */
    unsigned __int8 UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_3;               /* p_f_AWV_Nulldurchgang_Fahrpedal_3 */
    // Boolean AUSLOESEDOKU_ENABLE_KOMPLETT;                                   /* p_b_AWV_Enable_AusloeseDokumentation_komplett */
    unsigned __int16 AUSLOESEDOKU_BEOBACHTUNG_DAUER_MAX;                       /* p_t_AWV_Auslösedoku_max_Beobachtung */
    // Boolean DEMOMODUS_ENABLE_KOMPLETT;                                      /* p_b_AWV_Enable_Demomodus_komplett */
    unsigned __int16 DEMOMODUS_ANKUENDIGUNG_DAUER;                             /* p_t_AWV_Demomodus_Ankündigung */
    DTFfiWarnungPar WARNUNG;
    DTFfiHbaPar HBA;
    DTFfiPrefillPar PREFILL;
    DTFfiVFgsPar VFGS;
  } DTFfiPar;
} // end of DTFfiPar_V1


namespace DTFfiPar_V2
{
  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    Boolean HAUPTWARNUNG_ENABLE_KOMPLETT;                                      /* p_b_AWV_Enable_Hauptwarnung_komplett */
    unsigned __int16 HAUPTWARNUNG_DAUER;                                       /* p_t_AWV_Hauptwarnung */
    float HAUPTWARNUNG_AAUTO_MIN;                                              /* p_a_AWV_max_Verz_Ruck */
    unsigned __int8 HAUPTWARNUNG_RUCKPROFIL1_V_MAX;                            /* p_v_AWV2_Ruck_1 */
    unsigned __int8 HAUPTWARNUNG_RUCKPROFIL2_V_MAX;                            /* p_v_AWV2_Ruck_2 */
    unsigned __int8 HAUPTWARNUNG_RUCKPROFIL3_V_MAX;                            /* p_v_AWV2_Ruck_3 */
    unsigned __int8 HAUPTWARNUNG_RUCKPROFIL4_V_MAX;                            /* p_v_AWV2_Ruck_4 */
    unsigned __int8 HAUPTWARNUNG_RUCKPROFIL5_V_MAX;                            /* p_v_AWV2_Ruck_5 */
    unsigned __int8 HAUPTWARNUNG_RUCKPROFIL6_V_MAX;                            /* p_v_AWV2_Ruck_6 */
    Boolean VORWARNUNG_ENABLE_KOMPLETT;                                        /* p_b_AWV_Enable_Vorwarnung_komplett */
    unsigned __int16 VORWARNUNG_DAUER;                                         /* p_t_AWV_Vorwarnung */
    unsigned __int16 AWV_PRIOWARNUNG_DAUER_MIN;                                /* p_t_AWV_Warnprio_min */
    Boolean ABSTANDSWARNUNG_ENABLE_KOMPLETT;                                   /* p_b_AWV_Enable_Abstandswarnung_komplett */
    unsigned __int8 ABSTANDSWARNUNG_V_MIN;                                     /* p_v_AWV_Abstandswarnung_min */
    unsigned __int8 ABSTANDSWARNUNG_V_ABBRUCH;                                 /* p_v_AWV_Abstandswarnung_Abbruch */
    unsigned __int16 ABSTANDSWARNUNG_UEBERTRETEN_DAUER;                        /* p_t_AWV_AbstWarnung_EntprellungUebertreten */
  } DTFfiWarnungPar;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned __int16 PREFILL_DAUER_MAX;                                        /* p_t_AWV_Prefill_max */
    unsigned __int16 PREFILL_DAUER_MIN;                                        /* p_t_AWV_Prefill_min */
    Boolean ECD_ANLAUF_ENABLE_KOMPLETT;                                        /* p_b_AWV_Enable_ECD_Anlauf_komplett */
    unsigned __int16 ECD_ANLAUF_DAUER_MAX;                                     /* p_t_AWV_ECD_Anlauf_max */
  } DTFfiPrefillPar;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    Boolean VFGS_VERFUEGBAR;                                                   /* p_b_AWV_Enable_vFGS_komplett */
    unsigned __int8 VFGS_WARNUNG_V_MIN;                                        /* p_v_vFGS_Warn_min */
    unsigned __int8 VFGS_EINGRIFFE_V_MAX;                                      /* p_v_vFGS_allg_max */
    unsigned __int8 VFGS_V_ABBAU_MAX;                                          /* p_v_vFGS_Teilbremsung_vDelta_max */
  } DTFfiVFgsPar;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned __int8 AWV_WARNUNGEN_V_MIN;                                       /* p_v_AWV_Warn_min */
    unsigned __int16 AWV_EINGRIFFE_V_MIN;                                      /* p_v_AWV_allg_min */
    unsigned __int16 AWV_EINGRIFFE_V_MAX;                                      /* p_v_AWV_allg_max */
    unsigned __int8 AWV_EINGRIFFE_SO_V_MAX;                                    /* p_v_AWV_v_max_SO */
    unsigned __int8 AWV_EINGRIFFE_FAHRPEDAL_MAX;                               /* p_f_AWV_Fahrpedal_max */
    unsigned __int16 AWV_EINGRIFFE_FAHRPEDALGRADIENT_ABBRUCH;                  /* p_ft_AWV_AbbruchGradientFahrpedal */
    unsigned __int16 AWV_EINGRIFFE_LENKRADWINKEL_MAX;                          /* p_r_AWV_Lenkradwinkel_max */
    unsigned __int16 AWV_EINGRIFFE_LENKRADWINKEL_ABBRUCH;                      /* p_r_AWV_Lenkradwinkel_abbruch */
    unsigned __int16 AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_MAX;           /* p_rv_AWV_Lenkradwinkelgeschwindigkeit_max */
    unsigned __int16 AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_ABBRUCH;       /* p_rv_AWV_Lenkradwinkelgeschwindigkeit_abbruch */
    unsigned __int16 AWV_EINGRIFFE_LENKENTPRELLUNG_DAUER;                      /* p_t_AWV_Lenkentprellung */
    unsigned __int16 AWV_SPERRZEIT;                                            /* p_t_AWV_Sperrzeit */
    DTFfiPar_V1::UInt16_Float_A8 FAHRER_BREMST_DEUTLICH_VEGO_A_KENNLINIE;      /* p_a_AWV_Fahrer_bremst_deutlich */
    unsigned __int8 FAHRER_BREMST_DEUTLICH_VMIN_UNTERDRUECKUNG_ATB;            /* p_v_AWV_Fahrer_bremst_deutlich */
    unsigned __int16 INSTABILITAET_NACHLAUF_DAUER;                             /* p_t_AWV_Instabilitaet_Nachlauf [ms] */
    unsigned __int16 UEBERHOLWUNSCH_BLINKER_DAUER;                             /* p_t_AWV_Ueberholwunsch_Blinker */
    unsigned __int8 UEBERHOLWUNSCH_FAHRPEDAL_MIN;                              /* p_f_AWV_Overtake_min */
    unsigned __int8 UEBERHOLWUNSCH_FAHRPEDAL_MAX;                              /* p_f_AWV_Overtake_max */
    unsigned __int16 UEBERHOLWUNSCH_DAUER_MAX;                                 /* p_t_AWV_Overtake_max */
    unsigned __int16 UEBERSTEUERWUNSCH_FAHRERBREMST_ABBRUCH_DAUER;             /* p_t_AWV_FahrerBremst_Abbruch [ms] */
    unsigned __int16 UEBERSTEUERWUNSCH_FAHRERBREMST_ENTPRELLUNG_DAUER;         /* p_t_AWV_FahrerBremst_Entprellung [ms] */
    unsigned __int16 UEBERSTEUERWUNSCH_FAHRPEDAL_ENTPRELLUNG_DAUER;            /* p_t_AWV_Fahrpedal_Entprellung [ms] */
    unsigned __int16 UEBERSTEUERWUNSCH_FAHRERREAKTION_ENTPRELLUNG_DAUER;       /* p_t_AWV_Wait4DriverReaction [ms] */
    unsigned __int16 UEBERSTEUERWUNSCH_FAHRERREAKTION_DAUER_MAX;               /* p_t_AWV_WaitMax4DriverReaction [ms] */
    unsigned __int8 UEBERSTEUERWUNSCH_FAHRERREAKTION_ZWEI_FAHRPEDAL;           /* p_f_AWV_FahrpedalWert4SecondDrriverReaction [Prozent] */
    unsigned __int8 UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_1;               /* p_f_AWV_Nulldurchgang_Fahrpedal_1 */
    unsigned __int8 UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_2;               /* p_f_AWV_Nulldurchgang_Fahrpedal_2 */
    unsigned __int8 UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_3;               /* p_f_AWV_Nulldurchgang_Fahrpedal_3 */
    Boolean AUSLOESEDOKU_ENABLE_KOMPLETT;                                      /* p_b_AWV_Enable_AusloeseDokumentation_komplett */
    unsigned __int16 AUSLOESEDOKU_BEOBACHTUNG_DAUER_MAX;                       /* p_t_AWV_Auslösedoku_max_Beobachtung */
    Boolean DEMOMODUS_ENABLE_KOMPLETT;                                         /* p_b_AWV_Enable_Demomodus_komplett */
    unsigned __int16 DEMOMODUS_ANKUENDIGUNG_DAUER;                             /* p_t_AWV_Demomodus_Ankündigung */
    DTFfiWarnungPar WARNUNG;
    DTFfiPar_V1::DTFfiHbaPar HBA;
    DTFfiPrefillPar PREFILL;
    DTFfiVFgsPar VFGS;
  } DTFfiPar;
} // end of DTFfiPar_V2


namespace DTFfiPar_V3
{
  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned __int8 AWV_WARNUNGEN_V_MIN;                                       /* p_v_AWV_Warn_min */
    unsigned __int16 AWV_EINGRIFFE_V_MIN;                                      /* p_v_AWV_allg_min */
    unsigned __int16 AWV_EINGRIFFE_V_MAX;                                      /* p_v_AWV_allg_max */
    unsigned __int8 AWV_EINGRIFFE_SO_V_MAX;                                    /* p_v_AWV_v_max_SO */
    unsigned __int8 AWV_EINGRIFFE_FAHRPEDAL_MAX;                               /* p_f_AWV_Fahrpedal_max */
    unsigned __int16 AWV_EINGRIFFE_FAHRPEDALGRADIENT_ABBRUCH;                  /* p_ft_AWV_AbbruchGradientFahrpedal */
    unsigned __int16 AWV_EINGRIFFE_LENKRADWINKEL_MAX;                          /* p_r_AWV_Lenkradwinkel_max */
    unsigned __int16 AWV_EINGRIFFE_LENKRADWINKEL_ABBRUCH;                      /* p_r_AWV_Lenkradwinkel_abbruch */
    unsigned __int16 AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_MAX;           /* p_rv_AWV_Lenkradwinkelgeschwindigkeit_max */
    unsigned __int16 AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_ABBRUCH;       /* p_rv_AWV_Lenkradwinkelgeschwindigkeit_abbruch */
    unsigned __int16 AWV_EINGRIFFE_LENKENTPRELLUNG_DAUER;                      /* p_t_AWV_Lenkentprellung */
    unsigned __int16 AWV_SPERRZEIT;                                            /* p_t_AWV_Sperrzeit */
    DTFfiPar_V1::UInt16_Float_A8 FAHRER_BREMST_DEUTLICH_VEGO_A_KENNLINIE;      /* p_a_AWV_Fahrer_bremst_deutlich */
    unsigned __int8 FAHRER_BREMST_DEUTLICH_VMIN_UNTERDRUECKUNG_ATB;            /* p_v_AWV_Fahrer_bremst_deutlich */
    unsigned __int16 INSTABILITAET_NACHLAUF_DAUER;                             /* p_t_AWV_Instabilitaet_Nachlauf [ms] */
    unsigned __int16 UEBERHOLWUNSCH_BLINKER_DAUER;                             /* p_t_AWV_Ueberholwunsch_Blinker */
    unsigned __int8 UEBERHOLWUNSCH_FAHRPEDAL_MIN;                              /* p_f_AWV_Overtake_min */
    unsigned __int8 UEBERHOLWUNSCH_FAHRPEDAL_MAX;                              /* p_f_AWV_Overtake_max */
    unsigned __int16 UEBERHOLWUNSCH_DAUER_MAX;                                 /* p_t_AWV_Overtake_max */
    unsigned __int16 UEBERSTEUERWUNSCH_FAHRERBREMST_ABBRUCH_DAUER;             /* p_t_AWV_FahrerBremst_Abbruch [ms] */
    unsigned __int16 UEBERSTEUERWUNSCH_FAHRERBREMST_ENTPRELLUNG_DAUER;         /* p_t_AWV_FahrerBremst_Entprellung [ms] */
    unsigned __int16 UEBERSTEUERWUNSCH_FAHRPEDAL_ENTPRELLUNG_DAUER;            /* p_t_AWV_Fahrpedal_Entprellung [ms] */
    unsigned __int16 UEBERSTEUERWUNSCH_FAHRERREAKTION_ENTPRELLUNG_DAUER;       /* p_t_AWV_Wait4DriverReaction [ms] */
    unsigned __int16 UEBERSTEUERWUNSCH_FAHRERREAKTION_DAUER_MAX;               /* p_t_AWV_WaitMax4DriverReaction [ms] */
    unsigned __int8 UEBERSTEUERWUNSCH_FAHRERREAKTION_ZWEI_FAHRPEDAL;           /* p_f_AWV_FahrpedalWert4SecondDrriverReaction [Prozent] */
    unsigned __int8 UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_1;               /* p_f_AWV_Nulldurchgang_Fahrpedal_1 */
    unsigned __int8 UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_2;               /* p_f_AWV_Nulldurchgang_Fahrpedal_2 */
    unsigned __int8 UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_3;               /* p_f_AWV_Nulldurchgang_Fahrpedal_3 */
    Boolean AUSLOESEDOKU_ENABLE_KOMPLETT;                                      /* p_b_AWV_Enable_AusloeseDokumentation_komplett */
    unsigned __int16 AUSLOESEDOKU_BEOBACHTUNG_DAUER_MAX;                       /* p_t_AWV_Auslösedoku_max_Beobachtung */
    Boolean DEMOMODUS_ENABLE_KOMPLETT;                                         /* p_b_AWV_Enable_Demomodus_komplett */
    unsigned __int16 DEMOMODUS_ANKUENDIGUNG_DAUER;                             /* p_t_AWV_Demomodus_Ankündigung */
    unsigned __int16 DEMOMODUS_VORWARNUNG_DAUER;                               /* p_t_AWV_Demomodus_Ankündigung */
    DTFfiPar_V2::DTFfiWarnungPar WARNUNG;
    DTFfiPar_V1::DTFfiHbaPar HBA;
    DTFfiPar_V2::DTFfiPrefillPar PREFILL;
    DTFfiPar_V2::DTFfiVFgsPar VFGS;
    unsigned __int8 ZBR_ENABLE_KOMPLETT;
    unsigned __int8 ATB_ENABLE_KOMPLETT;
    unsigned __int8 STILLSTAND_VEGO;
  } DTFfiPar;
} // end of DTFfiPar_V3


namespace DTFfiPar_V4
{
  typedef unsigned long UInt32_A8[8];
  typedef float Float_A8[8];

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    UInt32_A8 X;
    Float_A8 Y;
  } UInt32_Float_A8;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned __int32 HAUPTWARNUNG_ENABLE_KOMPLETT;                             /* p_b_AWV_Enable_Hauptwarnung_komplett */
    unsigned __int32 HAUPTWARNUNG_DAUER;                                       /* p_t_AWV_Hauptwarnung */
    float HAUPTWARNUNG_AAUTO_MIN;                                              /* p_a_AWV_max_Verz_Ruck */
    unsigned __int32 HAUPTWARNUNG_RUCKPROFIL1_V_MAX;                           /* p_v_AWV2_Ruck_1 */
    unsigned __int32 HAUPTWARNUNG_RUCKPROFIL2_V_MAX;                           /* p_v_AWV2_Ruck_2 */
    unsigned __int32 HAUPTWARNUNG_RUCKPROFIL3_V_MAX;                           /* p_v_AWV2_Ruck_3 */
    unsigned __int32 HAUPTWARNUNG_RUCKPROFIL4_V_MAX;                           /* p_v_AWV2_Ruck_4 */
    unsigned __int32 HAUPTWARNUNG_RUCKPROFIL5_V_MAX;                           /* p_v_AWV2_Ruck_5 */
    unsigned __int32 HAUPTWARNUNG_RUCKPROFIL6_V_MAX;                           /* p_v_AWV2_Ruck_6 */
    unsigned __int32 VORWARNUNG_ENABLE_KOMPLETT;                               /* p_b_AWV_Enable_Vorwarnung_komplett */
    unsigned __int32 VORWARNUNG_DAUER;                                         /* p_t_AWV_Vorwarnung */
    unsigned __int32 AWV_PRIOWARNUNG_DAUER_MIN;                                /* p_t_AWV_Warnprio_min */
    unsigned __int32 ABSTANDSWARNUNG_ENABLE_KOMPLETT;                          /* p_b_AWV_Enable_Abstandswarnung_komplett */
    unsigned __int32 ABSTANDSWARNUNG_V_MIN;                                    /* p_v_AWV_Abstandswarnung_min */
    unsigned __int32 ABSTANDSWARNUNG_V_ABBRUCH;                                /* p_v_AWV_Abstandswarnung_Abbruch */
    unsigned __int32 ABSTANDSWARNUNG_UEBERTRETEN_DAUER;                        /* p_t_AWV_AbstWarnung_EntprellungUebertreten */
  } DTFfiWarnungPar;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned __int32 HBA_VERLAENGERUNG_DAUER;                                  /* [[DF-AWV-173]] p_t_AWV_HBA_Verlaengerung */
  } DTFfiHbaPar;                                                               /* [[DF-AWV-798]] */

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned __int32 PREFILL_DAUER_MAX;                                        /* p_t_AWV_Prefill_max */
    unsigned __int32 PREFILL_DAUER_MIN;                                        /* p_t_AWV_Prefill_min */
    unsigned __int32 ECD_ANLAUF_ENABLE_KOMPLETT;                               /* p_b_AWV_Enable_ECD_Anlauf_komplett */
    unsigned __int32 ECD_ANLAUF_DAUER_MAX;                                     /* p_t_AWV_ECD_Anlauf_max */
  } DTFfiPrefillPar;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned __int32 VFGS_VERFUEGBAR;                                          /* p_b_AWV_Enable_vFGS_komplett */
    unsigned __int32 VFGS_WARNUNG_V_MIN;                                       /* p_v_vFGS_Warn_min */
    unsigned __int32 VFGS_EINGRIFFE_V_MAX;                                     /* p_v_vFGS_allg_max */
    unsigned __int32 VFGS_V_ABBAU_MAX;                                         /* p_v_vFGS_Teilbremsung_vDelta_max */
  } DTFfiVFgsPar;

  typedef struct                                                               /* [Satisfies_rte sws 1191] */
  {
    unsigned __int32 AWV_WARNUNGEN_V_MIN;                                      /* p_v_AWV_Warn_min */
    unsigned __int32 AWV_EINGRIFFE_V_MIN;                                      /* p_v_AWV_allg_min */
    unsigned __int32 AWV_EINGRIFFE_V_MAX;                                      /* p_v_AWV_allg_max */
    unsigned __int32 AWV_EINGRIFFE_SO_V_MAX;                                   /* p_v_AWV_v_max_SO */
    unsigned __int32 AWV_EINGRIFFE_FAHRPEDAL_MAX;                              /* p_f_AWV_Fahrpedal_max */
    unsigned __int32 AWV_EINGRIFFE_FAHRPEDALGRADIENT_ABBRUCH;                  /* p_ft_AWV_AbbruchGradientFahrpedal */
    unsigned __int32 AWV_EINGRIFFE_LENKRADWINKEL_MAX;                          /* p_r_AWV_Lenkradwinkel_max */
    unsigned __int32 AWV_EINGRIFFE_LENKRADWINKEL_ABBRUCH;                      /* p_r_AWV_Lenkradwinkel_abbruch */
    unsigned __int32 AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_MAX;           /* p_rv_AWV_Lenkradwinkelgeschwindigkeit_max */
    unsigned __int32 AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_ABBRUCH;       /* p_rv_AWV_Lenkradwinkelgeschwindigkeit_abbruch */
    unsigned __int32 AWV_EINGRIFFE_LENKENTPRELLUNG_DAUER;                      /* p_t_AWV_Lenkentprellung */
    unsigned __int32 AWV_SPERRZEIT;                                            /* p_t_AWV_Sperrzeit */
    UInt32_Float_A8 FAHRER_BREMST_DEUTLICH_VEGO_A_KENNLINIE;                   /* p_a_AWV_Fahrer_bremst_deutlich */
    unsigned __int32 FAHRER_BREMST_DEUTLICH_VMIN_UNTERDRUECKUNG_ATB;           /* p_v_AWV_Fahrer_bremst_deutlich */
    unsigned __int32 INSTABILITAET_NACHLAUF_DAUER;                             /* p_t_AWV_Instabilitaet_Nachlauf [ms] */
    unsigned __int32 UEBERHOLWUNSCH_BLINKER_DAUER;                             /* p_t_AWV_Ueberholwunsch_Blinker */
    unsigned __int32 UEBERHOLWUNSCH_FAHRPEDAL_MIN;                             /* p_f_AWV_Overtake_min */
    unsigned __int32 UEBERHOLWUNSCH_FAHRPEDAL_MAX;                             /* p_f_AWV_Overtake_max */
    unsigned __int32 UEBERHOLWUNSCH_DAUER_MAX;                                 /* p_t_AWV_Overtake_max */
    unsigned __int32 UEBERSTEUERWUNSCH_FAHRERBREMST_ABBRUCH_DAUER;             /* p_t_AWV_FahrerBremst_Abbruch [ms] */
    unsigned __int32 UEBERSTEUERWUNSCH_FAHRERBREMST_ENTPRELLUNG_DAUER;         /* p_t_AWV_FahrerBremst_Entprellung [ms] */
    unsigned __int32 UEBERSTEUERWUNSCH_FAHRPEDAL_ENTPRELLUNG_DAUER;            /* p_t_AWV_Fahrpedal_Entprellung [ms] */
    unsigned __int32 UEBERSTEUERWUNSCH_FAHRERREAKTION_ENTPRELLUNG_DAUER;       /* p_t_AWV_Wait4DriverReaction [ms] */
    unsigned __int32 UEBERSTEUERWUNSCH_FAHRERREAKTION_DAUER_MAX;               /* p_t_AWV_WaitMax4DriverReaction [ms] */
    unsigned __int32 UEBERSTEUERWUNSCH_FAHRERREAKTION_ZWEI_FAHRPEDAL;          /* p_f_AWV_FahrpedalWert4SecondDrriverReaction [Prozent] */
    unsigned __int32 UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_1;              /* p_f_AWV_Nulldurchgang_Fahrpedal_1 */
    unsigned __int32 UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_2;              /* p_f_AWV_Nulldurchgang_Fahrpedal_2 */
    unsigned __int32 UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_3;              /* p_f_AWV_Nulldurchgang_Fahrpedal_3 */
    unsigned __int32 AUSLOESEDOKU_ENABLE_KOMPLETT;                             /* p_b_AWV_Enable_AusloeseDokumentation_komplett */
    unsigned __int32 AUSLOESEDOKU_BEOBACHTUNG_DAUER_MAX;                       /* p_t_AWV_Auslösedoku_max_Beobachtung */
    unsigned __int32 DEMOMODUS_ENABLE_KOMPLETT;                                /* p_b_AWV_Enable_Demomodus_komplett */
    unsigned __int32 DEMOMODUS_ANKUENDIGUNG_DAUER;                             /* p_t_AWV_Demomodus_Ankündigung */
    unsigned __int32 DEMOMODUS_VORWARNUNG_DAUER;                               /* [[DF-AWV-664]] p_t_AWV_Demomodus_Vorwarnung */
    DTFfiWarnungPar WARNUNG;                                                   /* [[DF-AWV-794]] */
    DTFfiHbaPar HBA;                                                           /* [[DF-AWV-798]] */
    DTFfiPrefillPar PREFILL;                                                   /* [[DF-AWV-799]] */
    DTFfiVFgsPar VFGS;                                                         /* [[DF-AWV-800]] */
    unsigned __int32 ZBR_ENABLE_KOMPLETT;                                      /* [[DF-AWV-851]] p_b_AWV_Enable_ZB_komplett */
    unsigned __int32 ATB_ENABLE_KOMPLETT;                                      /* [[DF-AWV-852]] p_b_AWV_Enable_TB_komplett */
    unsigned __int32 STILLSTAND_VEGO;                                          /* [[DF-AWV-841]] p_v_AWV_Stillstand_sicher_frueh */
    unsigned __int32 PSF_SENDESTATUS_NACHLAUF;                                 /* [[DF-AWV-941]] p_t_AWV_Sendestatus_Nachlauf */
  } DTFfiPar;
} // end of DTFfiPar_V4


class CConvDTFfiPar : public CSimConverterBase
{
  // the list of dependency names used inside by the converter
  /*
  static const char *DEP_NAMES[];
  */

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    // add new dependencies here
    DEP_COUNT
  };

  DTFfiPar_V1::DTFfiPar m_BufV1;
  DTFfiPar_V2::DTFfiPar m_BufV2;
  DTFfiPar_V3::DTFfiPar m_BufV3;
  DTFfiPar_V4::DTFfiPar m_BufV4;

  // Initialization
  template <typename T> static void InitVx (T & Dest)
  {
    ::memset(&Dest, 0, sizeof(Dest));
  }

public:

  static const char *GetConverterTypeName()
  {
    return "DTFfiPar";
  }

  CConvDTFfiPar(void);
  virtual ~CConvDTFfiPar(void);

  const char *GetTypeName()
  {
    return GetConverterTypeName();
  }

  void Destroy()
  {
    delete this;
  }

  /** returns:
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_VALUE_FROM_PPORT - when the conversion is not implemented here
   *                                  and the value from Provide Port must be used
   */
  long ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
    void *pPPortData,
    void **pOutData, unsigned long &ulOutSize);

  /** returns:
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implemented here
   *                                            and the default value from Request Port must be used
   */
  long GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    void **pDefaultData, unsigned long &ulDefaultSize);

protected:

  // used to check if an unversioned PPort is compatible with a certain version of RPort
  bool IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize);

  // used to check if ports are compatible between different versions
  bool AreVersionsCompatible(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo);

private:
  enum AVWV_DTKvPar
  {
    DTFFIPAR_V1,
    DTFFIPAR_V2,
    DTFFIPAR_V3,
    DTFFIPAR_V4,
    DTFFIPAR_VERSION_COUNT
  };

  static CVersionInfoImpl BASE_VERSION;

  static const CVersionInfoImpl * const EM_OBJECTLIST_CAM_INPUT_VERSIONS[DTFFIPAR_VERSION_COUNT];

  static const unsigned long SUPPORTED_SIZE[DTFFIPAR_VERSION_COUNT];

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    for (int nI = 0; nI < DTFFIPAR_VERSION_COUNT; nI++)
    {
      if ((pPortVersion == NULL) || pPortVersion->Equals(EM_OBJECTLIST_CAM_INPUT_VERSIONS[nI]))
      {
        if (ulPortSize == SUPPORTED_SIZE[nI])
        {
          return true;
        }
      }
    };
    return false;
  };
};

CVersionInfoImpl CConvDTFfiPar::BASE_VERSION(0, 0, 0);

const CVersionInfoImpl * const CConvDTFfiPar::EM_OBJECTLIST_CAM_INPUT_VERSIONS[CConvDTFfiPar::DTFFIPAR_VERSION_COUNT] =
{
  &BASE_VERSION,
  &BASE_VERSION,
  &BASE_VERSION,
  &BASE_VERSION
};

const unsigned long CConvDTFfiPar::SUPPORTED_SIZE[CConvDTFfiPar::DTFFIPAR_VERSION_COUNT] =
{
  sizeof(DTFfiPar_V1::DTFfiPar),
  sizeof(DTFfiPar_V2::DTFfiPar),
  sizeof(DTFfiPar_V3::DTFfiPar),
  sizeof(DTFfiPar_V4::DTFfiPar)
};

__inline void v_Convert_v1_to_v2 (DTFfiPar_V2::DTFfiPar * const pDest,
  const DTFfiPar_V1::DTFfiPar * const pSrc)
{
  pDest->AWV_WARNUNGEN_V_MIN                                = pSrc->AWV_WARNUNGEN_V_MIN;
  pDest->AWV_EINGRIFFE_V_MIN                                = pSrc->AWV_EINGRIFFE_V_MIN;
  pDest->AWV_EINGRIFFE_V_MAX                                = pSrc->AWV_EINGRIFFE_V_MAX;
  pDest->AWV_EINGRIFFE_SO_V_MAX                             = pSrc->AWV_EINGRIFFE_SO_V_MAX;
  pDest->AWV_EINGRIFFE_FAHRPEDAL_MAX                        = pSrc->AWV_EINGRIFFE_FAHRPEDAL_MAX;
  pDest->AWV_EINGRIFFE_FAHRPEDALGRADIENT_ABBRUCH            = pSrc->AWV_EINGRIFFE_FAHRPEDALGRADIENT_ABBRUCH;
  pDest->AWV_EINGRIFFE_LENKRADWINKEL_MAX                    = pSrc->AWV_EINGRIFFE_LENKRADWINKEL_MAX;
  pDest->AWV_EINGRIFFE_LENKRADWINKEL_ABBRUCH                = pSrc->AWV_EINGRIFFE_LENKRADWINKEL_ABBRUCH;
  pDest->AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_MAX     = pSrc->AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_MAX;
  pDest->AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_ABBRUCH = pSrc->AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_ABBRUCH;
  pDest->AWV_EINGRIFFE_LENKENTPRELLUNG_DAUER                = pSrc->AWV_EINGRIFFE_LENKENTPRELLUNG_DAUER;
  pDest->AWV_SPERRZEIT                                      = pSrc->AWV_SPERRZEIT;
  pDest->FAHRER_BREMST_DEUTLICH_VEGO_A_KENNLINIE            = pSrc->FAHRER_BREMST_DEUTLICH_VEGO_A_KENNLINIE;
  pDest->FAHRER_BREMST_DEUTLICH_VMIN_UNTERDRUECKUNG_ATB     = pSrc->FAHRER_BREMST_DEUTLICH_VMIN_UNTERDRUECKUNG_ATB;
  pDest->INSTABILITAET_NACHLAUF_DAUER                       = pSrc->INSTABILITAET_NACHLAUF_DAUER;
  pDest->UEBERHOLWUNSCH_BLINKER_DAUER                       = pSrc->UEBERHOLWUNSCH_BLINKER_DAUER;
  pDest->UEBERHOLWUNSCH_FAHRPEDAL_MIN                       = pSrc->UEBERHOLWUNSCH_FAHRPEDAL_MIN;
  pDest->UEBERHOLWUNSCH_FAHRPEDAL_MAX                       = pSrc->UEBERHOLWUNSCH_FAHRPEDAL_MAX;
  pDest->UEBERHOLWUNSCH_DAUER_MAX                           = pSrc->UEBERHOLWUNSCH_DAUER_MAX;
  pDest->UEBERSTEUERWUNSCH_FAHRERBREMST_ABBRUCH_DAUER       = pSrc->UEBERSTEUERWUNSCH_FAHRERBREMST_ABBRUCH_DAUER;
  pDest->UEBERSTEUERWUNSCH_FAHRERBREMST_ENTPRELLUNG_DAUER   = pSrc->UEBERSTEUERWUNSCH_FAHRERBREMST_ENTPRELLUNG_DAUER;
  pDest->UEBERSTEUERWUNSCH_FAHRPEDAL_ENTPRELLUNG_DAUER      = pSrc->UEBERSTEUERWUNSCH_FAHRPEDAL_ENTPRELLUNG_DAUER;
  pDest->UEBERSTEUERWUNSCH_FAHRERREAKTION_ENTPRELLUNG_DAUER = pSrc->UEBERSTEUERWUNSCH_FAHRERREAKTION_ENTPRELLUNG_DAUER;
  pDest->UEBERSTEUERWUNSCH_FAHRERREAKTION_DAUER_MAX         = pSrc->UEBERSTEUERWUNSCH_FAHRERREAKTION_DAUER_MAX;
  pDest->UEBERSTEUERWUNSCH_FAHRERREAKTION_ZWEI_FAHRPEDAL    = pSrc->UEBERSTEUERWUNSCH_FAHRERREAKTION_ZWEI_FAHRPEDAL;
  pDest->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_1        = pSrc->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_1;
  pDest->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_2        = pSrc->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_2;
  pDest->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_3        = pSrc->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_3;
  pDest->AUSLOESEDOKU_ENABLE_KOMPLETT                       = 0;
  pDest->AUSLOESEDOKU_BEOBACHTUNG_DAUER_MAX                 = pSrc->AUSLOESEDOKU_BEOBACHTUNG_DAUER_MAX;
  pDest->DEMOMODUS_ENABLE_KOMPLETT                          = 0;
  pDest->DEMOMODUS_ANKUENDIGUNG_DAUER                       = pSrc->DEMOMODUS_ANKUENDIGUNG_DAUER;

  pDest->WARNUNG.HAUPTWARNUNG_ENABLE_KOMPLETT               = 1;
  pDest->WARNUNG.HAUPTWARNUNG_DAUER                         = pSrc->WARNUNG.HAUPTWARNUNG_DAUER;
  pDest->WARNUNG.HAUPTWARNUNG_AAUTO_MIN                     = pSrc->WARNUNG.HAUPTWARNUNG_AAUTO_MIN;
  pDest->WARNUNG.HAUPTWARNUNG_RUCKPROFIL1_V_MAX             = pSrc->WARNUNG.HAUPTWARNUNG_RUCKPROFIL1_V_MAX;
  pDest->WARNUNG.HAUPTWARNUNG_RUCKPROFIL2_V_MAX             = pSrc->WARNUNG.HAUPTWARNUNG_RUCKPROFIL2_V_MAX;
  pDest->WARNUNG.HAUPTWARNUNG_RUCKPROFIL3_V_MAX             = pSrc->WARNUNG.HAUPTWARNUNG_RUCKPROFIL3_V_MAX;
  pDest->WARNUNG.HAUPTWARNUNG_RUCKPROFIL4_V_MAX             = pSrc->WARNUNG.HAUPTWARNUNG_RUCKPROFIL4_V_MAX;
  pDest->WARNUNG.HAUPTWARNUNG_RUCKPROFIL5_V_MAX             = pSrc->WARNUNG.HAUPTWARNUNG_RUCKPROFIL5_V_MAX;
  pDest->WARNUNG.HAUPTWARNUNG_RUCKPROFIL6_V_MAX             = pSrc->WARNUNG.HAUPTWARNUNG_RUCKPROFIL6_V_MAX;
  pDest->WARNUNG.VORWARNUNG_ENABLE_KOMPLETT                 = 1;
  pDest->WARNUNG.VORWARNUNG_DAUER                           = pSrc->WARNUNG.VORWARNUNG_DAUER;
  pDest->WARNUNG.AWV_PRIOWARNUNG_DAUER_MIN                  = pSrc->WARNUNG.AWV_PRIOWARNUNG_DAUER_MIN;
  pDest->WARNUNG.ABSTANDSWARNUNG_ENABLE_KOMPLETT            = 1;
  pDest->WARNUNG.ABSTANDSWARNUNG_V_MIN                      = 65;
  pDest->WARNUNG.ABSTANDSWARNUNG_V_ABBRUCH                  = 60;
  pDest->WARNUNG.ABSTANDSWARNUNG_UEBERTRETEN_DAUER          = 5000;

  pDest->HBA = pSrc->HBA;

  pDest->PREFILL.PREFILL_DAUER_MAX = pSrc->PREFILL.PREFILL_DAUER_MAX;
  pDest->PREFILL.PREFILL_DAUER_MIN = pSrc->PREFILL.PREFILL_DAUER_MIN;
  pDest->PREFILL.ECD_ANLAUF_ENABLE_KOMPLETT = 1;
  pDest->PREFILL.ECD_ANLAUF_DAUER_MAX = 500;

  pDest->VFGS.VFGS_VERFUEGBAR = pSrc->VFGS.VFGS_VERFUEGBAR;
  pDest->VFGS.VFGS_WARNUNG_V_MIN = 30;
  pDest->VFGS.VFGS_EINGRIFFE_V_MAX = pSrc->VFGS.VFGS_EINGRIFFE_V_MAX;
  pDest->VFGS.VFGS_V_ABBAU_MAX = pSrc->VFGS.VFGS_V_ABBAU_MAX;
}


__inline void v_Convert_v4_to_v3 (DTFfiPar_V3::DTFfiPar * const pDest,
  const DTFfiPar_V4::DTFfiPar * const pSrc)
{
  pDest->AWV_WARNUNGEN_V_MIN                                = pSrc->AWV_WARNUNGEN_V_MIN;
  pDest->AWV_EINGRIFFE_V_MIN                                = pSrc->AWV_EINGRIFFE_V_MIN;
  pDest->AWV_EINGRIFFE_V_MAX                                = pSrc->AWV_EINGRIFFE_V_MAX;
  pDest->AWV_EINGRIFFE_SO_V_MAX                             = pSrc->AWV_EINGRIFFE_SO_V_MAX;
  pDest->AWV_EINGRIFFE_FAHRPEDAL_MAX                        = pSrc->AWV_EINGRIFFE_FAHRPEDAL_MAX;
  pDest->AWV_EINGRIFFE_FAHRPEDALGRADIENT_ABBRUCH            = pSrc->AWV_EINGRIFFE_FAHRPEDALGRADIENT_ABBRUCH;
  pDest->AWV_EINGRIFFE_LENKRADWINKEL_MAX                    = pSrc->AWV_EINGRIFFE_LENKRADWINKEL_MAX;
  pDest->AWV_EINGRIFFE_LENKRADWINKEL_ABBRUCH                = pSrc->AWV_EINGRIFFE_LENKRADWINKEL_ABBRUCH;
  pDest->AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_MAX     = pSrc->AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_MAX;
  pDest->AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_ABBRUCH = pSrc->AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_ABBRUCH;
  pDest->AWV_EINGRIFFE_LENKENTPRELLUNG_DAUER                = pSrc->AWV_EINGRIFFE_LENKENTPRELLUNG_DAUER;
  pDest->AWV_SPERRZEIT                                      = pSrc->AWV_SPERRZEIT;
  for (int nI=0; nI<8; nI++)
  {
    pDest->FAHRER_BREMST_DEUTLICH_VEGO_A_KENNLINIE.X[nI]    = pSrc->FAHRER_BREMST_DEUTLICH_VEGO_A_KENNLINIE.X[nI];
    pDest->FAHRER_BREMST_DEUTLICH_VEGO_A_KENNLINIE.Y[nI]    = pSrc->FAHRER_BREMST_DEUTLICH_VEGO_A_KENNLINIE.Y[nI];
  }
  pDest->FAHRER_BREMST_DEUTLICH_VMIN_UNTERDRUECKUNG_ATB     = pSrc->FAHRER_BREMST_DEUTLICH_VMIN_UNTERDRUECKUNG_ATB;
  pDest->INSTABILITAET_NACHLAUF_DAUER                       = pSrc->INSTABILITAET_NACHLAUF_DAUER;
  pDest->UEBERHOLWUNSCH_BLINKER_DAUER                       = pSrc->UEBERHOLWUNSCH_BLINKER_DAUER;
  pDest->UEBERHOLWUNSCH_FAHRPEDAL_MIN                       = pSrc->UEBERHOLWUNSCH_FAHRPEDAL_MIN;
  pDest->UEBERHOLWUNSCH_FAHRPEDAL_MAX                       = pSrc->UEBERHOLWUNSCH_FAHRPEDAL_MAX;
  pDest->UEBERHOLWUNSCH_DAUER_MAX                           = pSrc->UEBERHOLWUNSCH_DAUER_MAX;
  pDest->UEBERSTEUERWUNSCH_FAHRERBREMST_ABBRUCH_DAUER       = pSrc->UEBERSTEUERWUNSCH_FAHRERBREMST_ABBRUCH_DAUER;
  pDest->UEBERSTEUERWUNSCH_FAHRERBREMST_ENTPRELLUNG_DAUER   = pSrc->UEBERSTEUERWUNSCH_FAHRERBREMST_ENTPRELLUNG_DAUER;
  pDest->UEBERSTEUERWUNSCH_FAHRPEDAL_ENTPRELLUNG_DAUER      = pSrc->UEBERSTEUERWUNSCH_FAHRPEDAL_ENTPRELLUNG_DAUER;
  pDest->UEBERSTEUERWUNSCH_FAHRERREAKTION_ENTPRELLUNG_DAUER = pSrc->UEBERSTEUERWUNSCH_FAHRERREAKTION_ENTPRELLUNG_DAUER;
  pDest->UEBERSTEUERWUNSCH_FAHRERREAKTION_DAUER_MAX         = pSrc->UEBERSTEUERWUNSCH_FAHRERREAKTION_DAUER_MAX;
  pDest->UEBERSTEUERWUNSCH_FAHRERREAKTION_ZWEI_FAHRPEDAL    = pSrc->UEBERSTEUERWUNSCH_FAHRERREAKTION_ZWEI_FAHRPEDAL;
  pDest->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_1        = pSrc->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_1;
  pDest->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_2        = pSrc->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_2;
  pDest->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_3        = pSrc->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_3;
  pDest->AUSLOESEDOKU_ENABLE_KOMPLETT                       = pSrc->AUSLOESEDOKU_ENABLE_KOMPLETT;
  pDest->AUSLOESEDOKU_BEOBACHTUNG_DAUER_MAX                 = pSrc->AUSLOESEDOKU_BEOBACHTUNG_DAUER_MAX;
  pDest->DEMOMODUS_ENABLE_KOMPLETT                          = pSrc->DEMOMODUS_ENABLE_KOMPLETT;
  pDest->DEMOMODUS_ANKUENDIGUNG_DAUER                       = pSrc->DEMOMODUS_ANKUENDIGUNG_DAUER;

  pDest->WARNUNG.HAUPTWARNUNG_ENABLE_KOMPLETT               = pSrc->WARNUNG.HAUPTWARNUNG_ENABLE_KOMPLETT;
  pDest->WARNUNG.HAUPTWARNUNG_DAUER                         = pSrc->WARNUNG.HAUPTWARNUNG_DAUER;
  pDest->WARNUNG.HAUPTWARNUNG_AAUTO_MIN                     = pSrc->WARNUNG.HAUPTWARNUNG_AAUTO_MIN;
  pDest->WARNUNG.HAUPTWARNUNG_RUCKPROFIL1_V_MAX             = pSrc->WARNUNG.HAUPTWARNUNG_RUCKPROFIL1_V_MAX;
  pDest->WARNUNG.HAUPTWARNUNG_RUCKPROFIL2_V_MAX             = pSrc->WARNUNG.HAUPTWARNUNG_RUCKPROFIL2_V_MAX;
  pDest->WARNUNG.HAUPTWARNUNG_RUCKPROFIL3_V_MAX             = pSrc->WARNUNG.HAUPTWARNUNG_RUCKPROFIL3_V_MAX;
  pDest->WARNUNG.HAUPTWARNUNG_RUCKPROFIL4_V_MAX             = pSrc->WARNUNG.HAUPTWARNUNG_RUCKPROFIL4_V_MAX;
  pDest->WARNUNG.HAUPTWARNUNG_RUCKPROFIL5_V_MAX             = pSrc->WARNUNG.HAUPTWARNUNG_RUCKPROFIL5_V_MAX;
  pDest->WARNUNG.HAUPTWARNUNG_RUCKPROFIL6_V_MAX             = pSrc->WARNUNG.HAUPTWARNUNG_RUCKPROFIL6_V_MAX;
  pDest->WARNUNG.VORWARNUNG_ENABLE_KOMPLETT                 = pSrc->WARNUNG.VORWARNUNG_ENABLE_KOMPLETT;
  pDest->WARNUNG.VORWARNUNG_DAUER                           = pSrc->WARNUNG.VORWARNUNG_DAUER;
  pDest->WARNUNG.AWV_PRIOWARNUNG_DAUER_MIN                  = pSrc->WARNUNG.AWV_PRIOWARNUNG_DAUER_MIN;
  pDest->WARNUNG.ABSTANDSWARNUNG_ENABLE_KOMPLETT            = pSrc->WARNUNG.ABSTANDSWARNUNG_ENABLE_KOMPLETT;
  pDest->WARNUNG.ABSTANDSWARNUNG_V_MIN                      = pSrc->WARNUNG.ABSTANDSWARNUNG_V_MIN;
  pDest->WARNUNG.ABSTANDSWARNUNG_V_ABBRUCH                  = pSrc->WARNUNG.ABSTANDSWARNUNG_V_ABBRUCH;
  pDest->WARNUNG.ABSTANDSWARNUNG_UEBERTRETEN_DAUER          = pSrc->WARNUNG.ABSTANDSWARNUNG_UEBERTRETEN_DAUER;

  pDest->HBA.HBA_VERLAENGERUNG_DAUER                        = pSrc->HBA.HBA_VERLAENGERUNG_DAUER;

  pDest->PREFILL.PREFILL_DAUER_MAX                          = pSrc->PREFILL.PREFILL_DAUER_MAX;
  pDest->PREFILL.PREFILL_DAUER_MIN                          = pSrc->PREFILL.PREFILL_DAUER_MIN;
  pDest->PREFILL.ECD_ANLAUF_ENABLE_KOMPLETT                 = pSrc->PREFILL.ECD_ANLAUF_ENABLE_KOMPLETT;
  pDest->PREFILL.ECD_ANLAUF_DAUER_MAX                       = pSrc->PREFILL.ECD_ANLAUF_DAUER_MAX;

  pDest->VFGS.VFGS_VERFUEGBAR                               = pSrc->VFGS.VFGS_VERFUEGBAR;
  pDest->VFGS.VFGS_WARNUNG_V_MIN                            = pSrc->VFGS.VFGS_WARNUNG_V_MIN;
  pDest->VFGS.VFGS_EINGRIFFE_V_MAX                          = pSrc->VFGS.VFGS_EINGRIFFE_V_MAX;
  pDest->VFGS.VFGS_V_ABBAU_MAX                              = pSrc->VFGS.VFGS_V_ABBAU_MAX;

  pDest->ZBR_ENABLE_KOMPLETT                                = pSrc->ZBR_ENABLE_KOMPLETT;
  pDest->ATB_ENABLE_KOMPLETT                                = pSrc->ATB_ENABLE_KOMPLETT;
  pDest->STILLSTAND_VEGO                                    = pSrc->STILLSTAND_VEGO;
}


__inline void v_Convert_v2_to_v3 (DTFfiPar_V3::DTFfiPar * const pDest,
  const DTFfiPar_V2::DTFfiPar * const pSrc)
{
  pDest->AWV_WARNUNGEN_V_MIN                                = pSrc->AWV_WARNUNGEN_V_MIN;
  pDest->AWV_EINGRIFFE_V_MIN                                = pSrc->AWV_EINGRIFFE_V_MIN;
  pDest->AWV_EINGRIFFE_V_MAX                                = pSrc->AWV_EINGRIFFE_V_MAX;
  pDest->AWV_EINGRIFFE_SO_V_MAX                             = pSrc->AWV_EINGRIFFE_SO_V_MAX;
  pDest->AWV_EINGRIFFE_FAHRPEDAL_MAX                        = pSrc->AWV_EINGRIFFE_FAHRPEDAL_MAX;
  pDest->AWV_EINGRIFFE_FAHRPEDALGRADIENT_ABBRUCH            = pSrc->AWV_EINGRIFFE_FAHRPEDALGRADIENT_ABBRUCH;
  pDest->AWV_EINGRIFFE_LENKRADWINKEL_MAX                    = pSrc->AWV_EINGRIFFE_LENKRADWINKEL_MAX;
  pDest->AWV_EINGRIFFE_LENKRADWINKEL_ABBRUCH                = pSrc->AWV_EINGRIFFE_LENKRADWINKEL_ABBRUCH;
  pDest->AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_MAX     = pSrc->AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_MAX;
  pDest->AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_ABBRUCH = pSrc->AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_ABBRUCH;
  pDest->AWV_EINGRIFFE_LENKENTPRELLUNG_DAUER                = pSrc->AWV_EINGRIFFE_LENKENTPRELLUNG_DAUER;
  pDest->AWV_SPERRZEIT                                      = pSrc->AWV_SPERRZEIT;
  pDest->FAHRER_BREMST_DEUTLICH_VEGO_A_KENNLINIE            = pSrc->FAHRER_BREMST_DEUTLICH_VEGO_A_KENNLINIE;
  pDest->FAHRER_BREMST_DEUTLICH_VMIN_UNTERDRUECKUNG_ATB     = pSrc->FAHRER_BREMST_DEUTLICH_VMIN_UNTERDRUECKUNG_ATB;
  pDest->INSTABILITAET_NACHLAUF_DAUER                       = pSrc->INSTABILITAET_NACHLAUF_DAUER;
  pDest->UEBERHOLWUNSCH_BLINKER_DAUER                       = pSrc->UEBERHOLWUNSCH_BLINKER_DAUER;
  pDest->UEBERHOLWUNSCH_FAHRPEDAL_MIN                       = pSrc->UEBERHOLWUNSCH_FAHRPEDAL_MIN;
  pDest->UEBERHOLWUNSCH_FAHRPEDAL_MAX                       = pSrc->UEBERHOLWUNSCH_FAHRPEDAL_MAX;
  pDest->UEBERHOLWUNSCH_DAUER_MAX                           = pSrc->UEBERHOLWUNSCH_DAUER_MAX;
  pDest->UEBERSTEUERWUNSCH_FAHRERBREMST_ABBRUCH_DAUER       = pSrc->UEBERSTEUERWUNSCH_FAHRERBREMST_ABBRUCH_DAUER;
  pDest->UEBERSTEUERWUNSCH_FAHRERBREMST_ENTPRELLUNG_DAUER   = pSrc->UEBERSTEUERWUNSCH_FAHRERBREMST_ENTPRELLUNG_DAUER;
  pDest->UEBERSTEUERWUNSCH_FAHRPEDAL_ENTPRELLUNG_DAUER      = pSrc->UEBERSTEUERWUNSCH_FAHRPEDAL_ENTPRELLUNG_DAUER;
  pDest->UEBERSTEUERWUNSCH_FAHRERREAKTION_ENTPRELLUNG_DAUER = pSrc->UEBERSTEUERWUNSCH_FAHRERREAKTION_ENTPRELLUNG_DAUER;
  pDest->UEBERSTEUERWUNSCH_FAHRERREAKTION_DAUER_MAX         = pSrc->UEBERSTEUERWUNSCH_FAHRERREAKTION_DAUER_MAX;
  pDest->UEBERSTEUERWUNSCH_FAHRERREAKTION_ZWEI_FAHRPEDAL    = pSrc->UEBERSTEUERWUNSCH_FAHRERREAKTION_ZWEI_FAHRPEDAL;
  pDest->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_1        = pSrc->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_1;
  pDest->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_2        = pSrc->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_2;
  pDest->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_3        = pSrc->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_3;
  pDest->AUSLOESEDOKU_ENABLE_KOMPLETT                       = pSrc->AUSLOESEDOKU_ENABLE_KOMPLETT;
  pDest->AUSLOESEDOKU_BEOBACHTUNG_DAUER_MAX                 = pSrc->AUSLOESEDOKU_BEOBACHTUNG_DAUER_MAX;
  pDest->DEMOMODUS_ENABLE_KOMPLETT                          = pSrc->DEMOMODUS_ENABLE_KOMPLETT;
  pDest->DEMOMODUS_ANKUENDIGUNG_DAUER                       = pSrc->DEMOMODUS_ANKUENDIGUNG_DAUER;
  pDest->DEMOMODUS_VORWARNUNG_DAUER                         = 1000;
  pDest->WARNUNG                                            = pSrc->WARNUNG;
  pDest->HBA                                                = pSrc->HBA;
  pDest->PREFILL                                            = pSrc->PREFILL;
  pDest->VFGS                                               = pSrc->VFGS;
  pDest->ZBR_ENABLE_KOMPLETT                                = 1;
  pDest->ATB_ENABLE_KOMPLETT                                = 1;
  pDest->STILLSTAND_VEGO                                    = 2;
}

__inline void v_Convert_v3_to_v4 (DTFfiPar_V4::DTFfiPar * const pDest,
  const DTFfiPar_V3::DTFfiPar * const pSrc)
{
  pDest->AWV_WARNUNGEN_V_MIN                                = pSrc->AWV_WARNUNGEN_V_MIN;
  pDest->AWV_EINGRIFFE_V_MIN                                = pSrc->AWV_EINGRIFFE_V_MIN;
  pDest->AWV_EINGRIFFE_V_MAX                                = pSrc->AWV_EINGRIFFE_V_MAX;
  pDest->AWV_EINGRIFFE_SO_V_MAX                             = pSrc->AWV_EINGRIFFE_SO_V_MAX;
  pDest->AWV_EINGRIFFE_FAHRPEDAL_MAX                        = pSrc->AWV_EINGRIFFE_FAHRPEDAL_MAX;
  pDest->AWV_EINGRIFFE_FAHRPEDALGRADIENT_ABBRUCH            = pSrc->AWV_EINGRIFFE_FAHRPEDALGRADIENT_ABBRUCH;
  pDest->AWV_EINGRIFFE_LENKRADWINKEL_MAX                    = pSrc->AWV_EINGRIFFE_LENKRADWINKEL_MAX;
  pDest->AWV_EINGRIFFE_LENKRADWINKEL_ABBRUCH                = pSrc->AWV_EINGRIFFE_LENKRADWINKEL_ABBRUCH;
  pDest->AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_MAX     = pSrc->AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_MAX;
  pDest->AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_ABBRUCH = pSrc->AWV_EINGRIFFE_LENKRADWINKELGESCHWINDIGKEIT_ABBRUCH;
  pDest->AWV_EINGRIFFE_LENKENTPRELLUNG_DAUER                = pSrc->AWV_EINGRIFFE_LENKENTPRELLUNG_DAUER;
  pDest->AWV_SPERRZEIT                                      = pSrc->AWV_SPERRZEIT;
  for (int nI=0; nI<8; nI++)
  {
    pDest->FAHRER_BREMST_DEUTLICH_VEGO_A_KENNLINIE.X[nI]    = pSrc->FAHRER_BREMST_DEUTLICH_VEGO_A_KENNLINIE.X[nI];
    pDest->FAHRER_BREMST_DEUTLICH_VEGO_A_KENNLINIE.Y[nI]    = pSrc->FAHRER_BREMST_DEUTLICH_VEGO_A_KENNLINIE.Y[nI];
  }
  pDest->FAHRER_BREMST_DEUTLICH_VMIN_UNTERDRUECKUNG_ATB     = pSrc->FAHRER_BREMST_DEUTLICH_VMIN_UNTERDRUECKUNG_ATB;
  pDest->INSTABILITAET_NACHLAUF_DAUER                       = pSrc->INSTABILITAET_NACHLAUF_DAUER;
  pDest->UEBERHOLWUNSCH_BLINKER_DAUER                       = pSrc->UEBERHOLWUNSCH_BLINKER_DAUER;
  pDest->UEBERHOLWUNSCH_FAHRPEDAL_MIN                       = pSrc->UEBERHOLWUNSCH_FAHRPEDAL_MIN;
  pDest->UEBERHOLWUNSCH_FAHRPEDAL_MAX                       = pSrc->UEBERHOLWUNSCH_FAHRPEDAL_MAX;
  pDest->UEBERHOLWUNSCH_DAUER_MAX                           = pSrc->UEBERHOLWUNSCH_DAUER_MAX;
  pDest->UEBERSTEUERWUNSCH_FAHRERBREMST_ABBRUCH_DAUER       = pSrc->UEBERSTEUERWUNSCH_FAHRERBREMST_ABBRUCH_DAUER;
  pDest->UEBERSTEUERWUNSCH_FAHRERBREMST_ENTPRELLUNG_DAUER   = pSrc->UEBERSTEUERWUNSCH_FAHRERBREMST_ENTPRELLUNG_DAUER;
  pDest->UEBERSTEUERWUNSCH_FAHRPEDAL_ENTPRELLUNG_DAUER      = pSrc->UEBERSTEUERWUNSCH_FAHRPEDAL_ENTPRELLUNG_DAUER;
  pDest->UEBERSTEUERWUNSCH_FAHRERREAKTION_ENTPRELLUNG_DAUER = pSrc->UEBERSTEUERWUNSCH_FAHRERREAKTION_ENTPRELLUNG_DAUER;
  pDest->UEBERSTEUERWUNSCH_FAHRERREAKTION_DAUER_MAX         = pSrc->UEBERSTEUERWUNSCH_FAHRERREAKTION_DAUER_MAX;
  pDest->UEBERSTEUERWUNSCH_FAHRERREAKTION_ZWEI_FAHRPEDAL    = pSrc->UEBERSTEUERWUNSCH_FAHRERREAKTION_ZWEI_FAHRPEDAL;
  pDest->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_1        = pSrc->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_1;
  pDest->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_2        = pSrc->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_2;
  pDest->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_3        = pSrc->UEBERSTEUERWUNSCH_NULLDURCHGANG_FAHRPEDAL_3;
  pDest->AUSLOESEDOKU_ENABLE_KOMPLETT                       = pSrc->AUSLOESEDOKU_ENABLE_KOMPLETT;
  pDest->AUSLOESEDOKU_BEOBACHTUNG_DAUER_MAX                 = pSrc->AUSLOESEDOKU_BEOBACHTUNG_DAUER_MAX;
  pDest->DEMOMODUS_ENABLE_KOMPLETT                          = pSrc->DEMOMODUS_ENABLE_KOMPLETT;
  pDest->DEMOMODUS_ANKUENDIGUNG_DAUER                       = pSrc->DEMOMODUS_ANKUENDIGUNG_DAUER;
  pDest->DEMOMODUS_VORWARNUNG_DAUER                         = pSrc->DEMOMODUS_VORWARNUNG_DAUER;
  pDest->WARNUNG.HAUPTWARNUNG_ENABLE_KOMPLETT               = pSrc->WARNUNG.HAUPTWARNUNG_ENABLE_KOMPLETT;
  pDest->WARNUNG.HAUPTWARNUNG_ENABLE_KOMPLETT               = pSrc->WARNUNG.HAUPTWARNUNG_ENABLE_KOMPLETT;
  pDest->WARNUNG.HAUPTWARNUNG_DAUER                         = pSrc->WARNUNG.HAUPTWARNUNG_DAUER;
  pDest->WARNUNG.HAUPTWARNUNG_AAUTO_MIN                     = pSrc->WARNUNG.HAUPTWARNUNG_AAUTO_MIN;
  pDest->WARNUNG.HAUPTWARNUNG_RUCKPROFIL1_V_MAX             = pSrc->WARNUNG.HAUPTWARNUNG_RUCKPROFIL1_V_MAX;
  pDest->WARNUNG.HAUPTWARNUNG_RUCKPROFIL2_V_MAX             = pSrc->WARNUNG.HAUPTWARNUNG_RUCKPROFIL2_V_MAX;
  pDest->WARNUNG.HAUPTWARNUNG_RUCKPROFIL3_V_MAX             = pSrc->WARNUNG.HAUPTWARNUNG_RUCKPROFIL3_V_MAX;
  pDest->WARNUNG.HAUPTWARNUNG_RUCKPROFIL4_V_MAX             = pSrc->WARNUNG.HAUPTWARNUNG_RUCKPROFIL4_V_MAX;
  pDest->WARNUNG.HAUPTWARNUNG_RUCKPROFIL5_V_MAX             = pSrc->WARNUNG.HAUPTWARNUNG_RUCKPROFIL5_V_MAX;
  pDest->WARNUNG.HAUPTWARNUNG_RUCKPROFIL6_V_MAX             = pSrc->WARNUNG.HAUPTWARNUNG_RUCKPROFIL6_V_MAX;
  pDest->WARNUNG.VORWARNUNG_ENABLE_KOMPLETT                 = pSrc->WARNUNG.VORWARNUNG_ENABLE_KOMPLETT;
  pDest->WARNUNG.VORWARNUNG_DAUER                           = pSrc->WARNUNG.VORWARNUNG_DAUER;
  pDest->WARNUNG.AWV_PRIOWARNUNG_DAUER_MIN                  = pSrc->WARNUNG.AWV_PRIOWARNUNG_DAUER_MIN;
  pDest->WARNUNG.ABSTANDSWARNUNG_ENABLE_KOMPLETT            = pSrc->WARNUNG.ABSTANDSWARNUNG_ENABLE_KOMPLETT;
  pDest->WARNUNG.ABSTANDSWARNUNG_V_MIN                      = pSrc->WARNUNG.ABSTANDSWARNUNG_V_MIN;
  pDest->WARNUNG.ABSTANDSWARNUNG_V_ABBRUCH                  = pSrc->WARNUNG.ABSTANDSWARNUNG_V_ABBRUCH;
  pDest->WARNUNG.ABSTANDSWARNUNG_UEBERTRETEN_DAUER          = pSrc->WARNUNG.ABSTANDSWARNUNG_UEBERTRETEN_DAUER;
  pDest->HBA.HBA_VERLAENGERUNG_DAUER                        = pSrc->HBA.HBA_VERLAENGERUNG_DAUER;
  pDest->PREFILL.PREFILL_DAUER_MAX                          = pSrc->PREFILL.PREFILL_DAUER_MAX;
  pDest->PREFILL.PREFILL_DAUER_MIN                          = pSrc->PREFILL.PREFILL_DAUER_MIN;
  pDest->PREFILL.ECD_ANLAUF_ENABLE_KOMPLETT                 = pSrc->PREFILL.ECD_ANLAUF_ENABLE_KOMPLETT;
  pDest->PREFILL.ECD_ANLAUF_DAUER_MAX                       = pSrc->PREFILL.ECD_ANLAUF_DAUER_MAX;
  pDest->VFGS.VFGS_VERFUEGBAR                               = pSrc->VFGS.VFGS_VERFUEGBAR;
  pDest->VFGS.VFGS_WARNUNG_V_MIN                            = pSrc->VFGS.VFGS_WARNUNG_V_MIN;
  pDest->VFGS.VFGS_EINGRIFFE_V_MAX                          = pSrc->VFGS.VFGS_EINGRIFFE_V_MAX;
  pDest->VFGS.VFGS_V_ABBAU_MAX                              = pSrc->VFGS.VFGS_V_ABBAU_MAX;
  pDest->ZBR_ENABLE_KOMPLETT                                = pSrc->ZBR_ENABLE_KOMPLETT;
  pDest->ATB_ENABLE_KOMPLETT                                = pSrc->ATB_ENABLE_KOMPLETT;
  pDest->STILLSTAND_VEGO                                    = pSrc->STILLSTAND_VEGO;
  pDest->PSF_SENDESTATUS_NACHLAUF                           = 2500;
}


CConvDTFfiPar::CConvDTFfiPar(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufV1(), m_BufV2()
{
  InitVx(m_BufV1);
  InitVx(m_BufV2);
}

CConvDTFfiPar::~CConvDTFfiPar(void)
{
}

long CConvDTFfiPar::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  //const unsigned int uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<unsigned int*>(pPPortData)):(0);

  if (eRPortType == ePPortType)
  {
    if ((ulRPortSize == ulPPortSize) && ((pProvidePortVersionInfo == NULL) || requestPortVersionInfo.Equals(pProvidePortVersionInfo)))
    {
      // Use data directly from provide port
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
    else
    {
      // First decide which version we are converting from
      if ((ulPPortSize == SUPPORTED_SIZE[DTFFIPAR_V4]) &&
        ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      {
        const DTFfiPar_V4::DTFfiPar *pSrc = reinterpret_cast<DTFfiPar_V4::DTFfiPar *>(pPPortData);
        // The decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[DTFFIPAR_V3]) &&
          (requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V2 is m_BufV2
          v_Convert_v4_to_v3(&m_BufV3, pSrc);
          *pOutData = &m_BufV3;
          ulOutSize = sizeof(m_BufV3);
          lRet = SIM_ERR_OK;
        }
        if ((ulRPortSize == SUPPORTED_SIZE[DTFFIPAR_V3]) &&
          (requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V2 is m_BufV2
          v_Convert_v4_to_v3(&m_BufV3, pSrc);
          //v_Convert_v3_to_v2(&m_BufV2, &m_BufV3);
          *pOutData = &m_BufV2;
          ulOutSize = sizeof(m_BufV2);
          lRet = SIM_ERR_OK;
        }
        if ((ulRPortSize == SUPPORTED_SIZE[DTFFIPAR_V3]) &&
          (requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V2 is m_BufV2
          v_Convert_v4_to_v3(&m_BufV3, pSrc);
          //v_Convert_v3_to_v2(&m_BufV2, &m_BufV3);
          //v_Convert_v2_to_v1(&m_BufV1, &m_BufV2);
          *pOutData = &m_BufV1;
          ulOutSize = sizeof(m_BufV1);
          lRet = SIM_ERR_OK;
        }
      }
      else if ((ulPPortSize == SUPPORTED_SIZE[DTFFIPAR_V3]) &&
        ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      {
        const DTFfiPar_V3::DTFfiPar *pSrc = reinterpret_cast<DTFfiPar_V3::DTFfiPar *>(pPPortData);
        // The decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[DTFFIPAR_V4]) &&
          (requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V2 is m_BufV2
          v_Convert_v3_to_v4(&m_BufV4, pSrc);
          *pOutData = &m_BufV4;
          ulOutSize = sizeof(m_BufV4);
          lRet = SIM_ERR_OK;
        }
      }
      else if ((ulPPortSize == SUPPORTED_SIZE[DTFFIPAR_V2]) &&
        ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      {
        const DTFfiPar_V2::DTFfiPar *pSrc = reinterpret_cast<DTFfiPar_V2::DTFfiPar *>(pPPortData);
        // The decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[DTFFIPAR_V4]) &&
          (requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V2 is m_BufV2
          v_Convert_v2_to_v3(&m_BufV3, pSrc);
          v_Convert_v3_to_v4(&m_BufV4, &m_BufV3);
          *pOutData = &m_BufV4;
          ulOutSize = sizeof(m_BufV4);
          lRet = SIM_ERR_OK;
        }
      }
      else if ((ulPPortSize == SUPPORTED_SIZE[DTFFIPAR_V1]) &&
        ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      {
        const DTFfiPar_V1::DTFfiPar *pSrc = reinterpret_cast<DTFfiPar_V1::DTFfiPar *>(pPPortData);
        // The decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[DTFFIPAR_V4]) &&
          (requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V4 is m_BufV4
          v_Convert_v1_to_v2(&m_BufV2, pSrc);
          v_Convert_v2_to_v3(&m_BufV3, &m_BufV2);
          v_Convert_v3_to_v4(&m_BufV4, &m_BufV3);
          *pOutData = &m_BufV4;
          ulOutSize = sizeof(m_BufV4);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[DTFFIPAR_V2]) &&
          (requestPortVersionInfo.Equals(&BASE_VERSION)))
        {
          // Destination port of V2 is m_BufV2
          v_Convert_v1_to_v2(&m_BufV2, pSrc);
          *pOutData = &m_BufV2;
          ulOutSize = sizeof(m_BufV2);
          lRet = SIM_ERR_OK;
        }
      }
    }
  }
  return lRet;
}

/** returns:
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvDTFfiPar::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == SUPPORTED_SIZE[DTFFIPAR_V4]) && (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      InitVx(m_BufV4);
      *pDefaultData = &m_BufV4;
      ulDefaultSize = sizeof(DTFfiPar_V4::DTFfiPar);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[DTFFIPAR_V3]) && (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      InitVx(m_BufV3);
      *pDefaultData = &m_BufV3;
      ulDefaultSize = sizeof(DTFfiPar_V3::DTFfiPar);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[DTFFIPAR_V2]) && (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      InitVx(m_BufV2);
      *pDefaultData = &m_BufV2;
      ulDefaultSize = sizeof(DTFfiPar_V2::DTFfiPar);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[DTFFIPAR_V1]) && BASE_VERSION.Equals(&requestPortVersionInfo))
    {
      InitVx(m_BufV1);
      *pDefaultData = &m_BufV1;
      ulDefaultSize = sizeof(DTFfiPar_V1::DTFfiPar);
      lRet = SIM_ERR_OK;
    }
    else
    {
      // No conversion available
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvDTFfiPar::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType))
  {
    bResult = true;
  }
  else if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, NULL)))
    {
      bResult = true;
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvDTFfiPar::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType))
  {
    bResult = true;
  }
  else if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, &providePortVersionInfo)))
    {
      bResult = true;
    }
  }
  return bResult;
}

//
// Main factory class returning conversion class
//
IConverter * CreateDTFfiParConvClass(void)
{
  return new CConvDTFfiPar();
}
