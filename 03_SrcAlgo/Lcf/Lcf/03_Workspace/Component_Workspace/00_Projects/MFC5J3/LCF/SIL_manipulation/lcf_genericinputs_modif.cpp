#ifndef __LCF_GENERICINPUTS_MODIF_C__
#define __LCF_GENERICINPUTS_MODIF_C__

#include "lcf_genericinputs_modif.h"


void Overwrite_LCF_GenericInputs_t ( LCF_GenericInputs_t &input ) //C++
{ 
input;//avoid warnings/errors while LCF_GENERICINPUTS_MANIPULATION is not defined
#ifdef LCF_GENERICINPUTS_MANIPULATION
  input.LKAMainSwitch__nu = 1; 
  input.TJAMainSwitch__nu = 1; 
  input.LDWSwitch__nu = 1; 
  input.LDPOncomingSwitch__nu = 1; 
  input.LDPSwitch__nu = 1;
  input.ALCASwitch__nu = 1;
  input.RDPSwitch__nu = 1;
  input.ACC_ActiveState__nu = 1; // If TJA is in Controlling, OF mode ?? 
  input.VehicleReadyState__nu = 1;
  input.DynamometerTestBenchDetected__nu = 0;
  input.EPS_Toi_Flt__nu = 0;
  input.EPS_Toi_Unavail__nu = 0;
  input.EPS_Toi_Active__nu = 4;
  /*Necessary in SW19 project*/
  input.DrvSteerWheelTrq__nm = 0.35f;
#endif

}  

#endif