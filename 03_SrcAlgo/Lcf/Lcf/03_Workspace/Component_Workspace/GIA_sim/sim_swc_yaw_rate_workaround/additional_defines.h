#include "glob_type.h"

namespace TurnSignal
{
  #ifndef   FCT_LKA_INPUT_GENERIC_INTFVER
    #define FCT_LKA_INPUT_GENERIC_INTFVER  (9)
  #endif
  #ifndef   LKS_TURN_SIGNAL_OFF
    #define LKS_TURN_SIGNAL_OFF (0)
  #endif
  #ifndef   LKS_TURN_SIGNAL_LEFT
    #define LKS_TURN_SIGNAL_LEFT (1)
  #endif
  #ifndef   LKS_TURN_SIGNAL_RIGHT
    #define LKS_TURN_SIGNAL_RIGHT (2)
  #endif

//static const uint32 FCT_LKA_INPUT_GENERIC_INTFVER = (9);
//static const uint32 LKS_TURN_SIGNAL_OFF = (0);
//static const uint32 LKS_TURN_SIGNAL_LEFT = (1);
//static const uint32 LKS_TURN_SIGNAL_RIGHT = (2);


  typedef struct
  {
    uint32 uiTimeStamp;
    uint16 uiMeasurementCounter;
    uint16 uiCycleCounter;
    uint8 eSigStatus;
  } SignalHeader_t;

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    uint32 uiVersionNumber;
    SignalHeader_t sSigHeader;
    uint8 eLKAALDWMode;
    uint8 eLDWSwitch;
    uint8 eLDPSwitch;
    uint8 eLKASwitch;
    uint8 eLKSSensitivity;
    uint8 eLKSTurnSignal;
    float32 fDriverTorque;
    float32 fPinionAngle;
    uint8 bHazardLight;
    uint8 bChasCtrlOn;
    uint8 bChasCtrlActive;
  } FCTALDWInputGeneric_t;			/* @vaddr:0x20270200 @vaddr_defs: FCT_MEAS_ID_ALDW_INPUT_GEN @cycleid:ALDW_VEH_IN @vname:FCTAldwInputGen */
}