#include "stdafx.h"
#include "resource.h"
#include "sim_swc_yaw_rate_workaround.h"
#include "sim_swc_yaw_rate_workaround_version.h"

#include <sstream>

// the client port names
const char* CSimYawRateWorkaround::CP_CALCULATIONDONE          = "CalculationDone";
const char* CSimYawRateWorkaround::CP_DISTRIBUTEOUTPUTDATA     = "DistributeOutputData";
const char* CSimYawRateWorkaround::CP_DISTRIBUTEONLYDIRTYPORTS = "DistributeOnlyDirtyPorts";

// the provide port names
const char* CSimYawRateWorkaround::PP_VEH_SIG               = "VehSig";
const char* CSimYawRateWorkaround::PP_VEH_DYN               = "VehDyn";
const char* CSimYawRateWorkaround::PP_VEH_DYN_RADAR         = "VehDynRadar";

const float CAN_YAW_RATE_LSB = 0.244f;

static void VehSigReceived (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimYawRateWorkaround* silInputAdapter = reinterpret_cast<CSimYawRateWorkaround*>(PlgID);
  silInputAdapter->ReplaceVehSigYawRate();
}

static void VehDynReceived (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimYawRateWorkaround* silInputAdapter = reinterpret_cast<CSimYawRateWorkaround*>(PlgID);
  silInputAdapter->ReplaceVehDynYawRate();
}

static void YawRateReceived (void* PlgID, long /*Param1*/, long /*Param2*/)
{
  CSimYawRateWorkaround* silInputAdapter = reinterpret_cast<CSimYawRateWorkaround*>(PlgID);
  silInputAdapter->ComputeYawRate();
}


CSimYawRateWorkaround::CSimYawRateWorkaround()
: CSimSwcBase ("..\\gia_sim\\adapter.dll")
, m_rpVehSig                 (this, PP_VEH_SIG,               VehSig_t(),     sizeof(VehSig_t), 0, VehSigReceived,   this)
, m_rpVehDyn                 (this, PP_VEH_DYN,               VehDyn_t(),     sizeof(VehDyn_t), 0, VehDynReceived,   this)
, m_rpVehDynRadar            (this, PP_VEH_DYN_RADAR,         VehDyn_t())
, m_rpYawRate                (this, "YawRate",                   0,           sizeof(float),    0, YawRateReceived,  this)
, m_rpYawRateDiff            (this, "YawRateDiff",               0)
, m_rpYRS1Error              (this, "YRS1Error",                 0)
, m_rpYRS1InvalidFlag        (this, "YRS1InvalidFlag",           0)
, m_rpYRS2Error              (this, "YRS2Error",                 0)
, m_rpYRS2InvalidFlag        (this, "YRS2InvalidFlag",           0)
, m_rpPowerSupplyInvalidFlag (this, "PowerSupplyInvalidFlag",    0)
, m_bYawRateComputed  (false)
, m_fYawRate(0.0f)
{
  // info strings
  std::stringstream headerTxt;
  std::stringstream dataTxt;

  headerTxt << "YawRateWorkaround version " << YAW_RATE_WORKAROUNDALL_SW_MAIN_VER_NO << "." << YAW_RATE_WORKAROUNDALL_SW_SUB_VER_NO << "." << YAW_RATE_WORKAROUNDALL_SW_BUG_FIX_LEV << "." << YAW_RATE_WORKAROUNDALL_SW_BUG_FIX_LEV2;
  dataTxt   << "YawRateWorkaround (YawRateWorkaround Simulation Module)";
  AddInternalData(headerTxt.str().c_str(), dataTxt.str().c_str());

#ifdef _DEBUG
  dataTxt.str("Debug ");
#else
  dataTxt.str("Release ");
#endif
  dataTxt << "build at " << __DATE__ << " " << __TIME__;
  AddInternalData("Compiling Info", dataTxt.str().c_str());

  // Create server Ports
  AddServerPort("Reset", Reset, this);
  AddServerPort("Init",  Init,  this);
  AddServerPort("Doit",  Doit,  this); // Not needed

  // Create client ports
  AddClientPort(CP_DISTRIBUTEOUTPUTDATA,      NULL, 0);
  AddClientPort(CP_DISTRIBUTEONLYDIRTYPORTS,  NULL, 0);
  AddClientPort(CP_CALCULATIONDONE,           NULL, 0, PORT_WITH_AUTOCLONE); // Not needed

  // Create algorithm ports
  SetupPorts();
}

CSimYawRateWorkaround::~CSimYawRateWorkaround()
{
}

void CSimYawRateWorkaround::SetupPorts()
{
  // input ports
  m_rpVehSig.setVersion       ("VehSig_t",                  CreateVersionInfoFromI32(BSW_VEH_SIG_INTFVER));
  m_rpVehDyn.setVersion       ("VehDyn_t",                  CreateVersionInfoFromI32(VDY_VEH_DYN_INTFVER));
  m_rpVehDynRadar.setVersion  ("VehDyn_t",                  CreateVersionInfoFromI32(VDY_VEH_DYN_INTFVER));

  // output ports
  memset(&m_ppVehSig, 0, sizeof(m_ppVehSig));
  AddProvidePort(PP_VEH_SIG, simOPAQUE_t, &m_ppVehSig, sizeof(m_ppVehSig));
  SetPPortVersion(PP_VEH_SIG, "VehSig_t", CreateVersionInfoFromI32(BSW_VEH_SIG_INTFVER));

  memset(&m_ppVehDyn, 0, sizeof(m_ppVehDyn));
  AddProvidePort(PP_VEH_DYN, simOPAQUE_t, &m_ppVehDyn, sizeof(m_ppVehDyn));
  SetPPortVersion(PP_VEH_DYN, "VehDyn_t", CreateVersionInfoFromI32(VDY_VEH_DYN_INTFVER));
}

void CSimYawRateWorkaround::Reset()
{
  // TODO: Place reset stuff
  m_bYawRateComputed = false;
  m_fYawRate = 0.0f;
}

void CSimYawRateWorkaround::Init()
{
  // TODO: Place initialization stuff
}

void CSimYawRateWorkaround::Doit()
{
  // trigger data distribution
  TriggerEvent(CP_DISTRIBUTEOUTPUTDATA, 0, 0);

  // trigger done port
  TriggerEvent(CP_CALCULATIONDONE, 0, 0);
}

void CSimYawRateWorkaround::ReplaceVehSigYawRate()
{
  SetPPortDirty(PP_VEH_SIG);
  m_ppVehSig = m_rpVehSig.val();

  if (m_bYawRateComputed)
  {
    m_ppVehSig.VehSigMain.YawRate = float(DEG2RAD(m_fYawRate));
  }

  // trigger data distribution
  TriggerEvent(CP_DISTRIBUTEONLYDIRTYPORTS, 0, 0);
}

void CSimYawRateWorkaround::ReplaceVehDynYawRate()
{
  SetPPortDirty(PP_VEH_DYN);
  m_ppVehDyn = m_rpVehDyn.val();

  // If vehicle velocity is invalid replace it by radar velocity or acceleration
  if (m_ppVehDyn.State[3] != VDY_IO_STATE_VALID || m_ppVehDyn.State[4] != VDY_IO_STATE_VALID)      //VDY_SOUT_POS_VEL=3,VDY_SOUT_POS_LATACC=8,VDY_SOUT_POS_DRCRV=2,VDY_SOUT_POS_YWR=1,VDY_SOUT_POS_CURVE=0,VDY_SOUT_POS_VCORR=6,VDY_SOUT_POS_SSA=7,VDY_SOUT_POS_ACCEL=4,VDY_SOUT_POS_MSTAT=5,VDY_SOUT_POS_MAX=12,} */	/* [Satisfies_rte sws 1188] */;
  {
    m_ppVehDyn = m_rpVehDynRadar.val();
    m_ppVehDyn.sSigHeader = m_rpVehDyn.val().sSigHeader;
  }

  // If Radar VehDyn is available overwrite Camera's yawrate with Radar's
  else if (m_rpVehDynRadar.isDirty())
  {
    m_ppVehDyn.Lateral.YawRate.YawRate  = m_rpVehDynRadar.val().Lateral.YawRate.YawRate;
#if VDY_VEH_DYN_INTFVER < 10
    m_ppVehDyn.Lateral.YawRate.Quality  = m_rpVehDynRadar.val().Lateral.YawRate.Quality;
#endif
    m_ppVehDyn.Lateral.YawRate.Variance = m_rpVehDynRadar.val().Lateral.YawRate.Variance;
    m_ppVehDyn.State[1] = m_rpVehDynRadar.val().State[1]; // VDY_SOUT_POS_YWR=1. Use YawRate State from Radar measfreeze 

   
  }
  // radar not available -> check can as fallback
  else if (m_bYawRateComputed)
  {
    m_ppVehDyn.Lateral.YawRate.YawRate = float(DEG2RAD(m_fYawRate));
  }

  // trigger data distribution
  TriggerEvent(CP_DISTRIBUTEONLYDIRTYPORTS, 0, 0);
}

void CSimYawRateWorkaround::ComputeYawRate()
{

  /*
   Judgment conditions:
  AND - <<  CAN communication invalid (YAW) >> = 0(b)
      - (( Yaw rate sensor 1 error )) = 0(b)
      - (( Yawrate_Sensor1_Invalid_Flag )) = 0(b)
      - (( Yaw rate sensor 2 error )) = 0(b)
      - (( Yawrate_Sensor2_Invalid_Flag )) = 0(b)
      - (( sensor power supply voltage (IG) invalidation/validation )) = 0(b)
  */
  if( (0 == m_rpYRS1Error.val())               &&      // YGS1S03.YRS11S
      (0 == m_rpYRS1InvalidFlag.val())         &&      // YGS1S03.YRS14S
      (0 == m_rpYRS2Error.val())               &&      // YGS1S03.YRS21S
      (0 == m_rpYRS2InvalidFlag.val())         &&      // YGS1S03.YRS24S
      (0 == m_rpPowerSupplyInvalidFlag.val())          // YGS1S03.YGS1
     )
  {
    /*  When the above conditions are met Perform section "Calculation of the yaw-rate" */

    // Update Signal Status
    m_bYawRateComputed  = true;
    float yawrateValue1;
    float yawrateValue2;
    
    /*  Calculation of the yaw-rate*/
    // Note: In the following calculation of yaw-rate, the data name is expressed in physical value

    /*  Restore the value of yaw-rate   */

    /*
    (1) Offset yaw-rate (even)

    the condition:
      (Yawrate_Difference_Value/CAN_YAW_RATE_LSB) is even.
    */
    if( 0 == (m_rpYawRateDiff.val() %2) 		//Yawrate_Difference_Value is even
        )
    {
      /*
      When the above condition is met
        Yawrate1_Value = Yawrate_Value + (Yawrate_Difference_Value ÷ 2 )
        Yawrate2_Value = Yawrate_Value - (Yawrate_Difference_Value ÷ 2 )  
      */	
      yawrateValue1 = m_rpYawRate.val() + (m_rpYawRateDiff.val() / 2.000F);
      yawrateValue2 = m_rpYawRate.val() - (m_rpYawRateDiff.val() / 2.000F);
    }
    /*
    (2) Offset yaw-rate (odd1)
    
    the conditions:
      AND - (Yawrate_Difference_Value/CAN_YAW_RATE_LSB) is odd
          - Yawrate_Difference_Value  >= 0
    */	
    else if( (1 == (m_rpYawRateDiff.val() %2) )  &&   	//Yawrate_Difference_Value is odd && (Yawrate_Difference_Value >= 0)
             (0 <= m_rpYawRateDiff.val())
            )
    {
      /*
      When the above conditions are met
         Yawrate1_Value = Yawrate_Value + Yawrate_Difference_Value ÷ 2 
         Yawrate2_Value =  Yawrate_Value - Yawrate_Difference_Value÷ 2 -1*CAN_YAW_RATE_LSB
      */
      yawrateValue1 = m_rpYawRate.val() + (m_rpYawRateDiff.val() / 2.000F);
      yawrateValue2 = (m_rpYawRate.val() - (m_rpYawRateDiff.val() / 2.000F)) - (1.000F * CAN_YAW_RATE_LSB);
    }
    /*
    (3) Offset yawrate (odd2)
    
    the conditions:
      AND - (Yawrate_Difference_Value/CAN_YAW_RATE_LSB) is odd
          - Yawrate_Difference_Value < 0
    */
    else if( (1 == (m_rpYawRateDiff.val() %2) )   &&     //Yawrate_Difference_Value is odd ) && (Yawrate_Difference_Value < 0)
             (0 > m_rpYawRateDiff.val())
            )
    {
      /*
      When the above conditions are met
         Yawrate1_Value = Yawrate_Value + Yawrate_Difference_Value ÷ 2 - 1*CAN_YAW_RATE_LSB
         Yawrate2_Value =  Yawrate_Value -   Yawrate_Difference_Value ÷ 2
      */
      yawrateValue1 = (m_rpYawRate.val() + (m_rpYawRateDiff.val() / 2.000F)) - (1.000F * CAN_YAW_RATE_LSB);
      yawrateValue2 = m_rpYawRate.val() - (m_rpYawRateDiff.val() / 2.000F);
    }
    else
    {
      // Keep the last values for Yawrate1_Value and Yawrate2_Value
      yawrateValue1 = m_rpYawRate.val();
      yawrateValue2 = m_rpYawRate.val();
    }

    /*   Yawrate_Operation_Value = (Yawrate1_Value+Yawrate2_Value) ÷ 2  */
    m_fYawRate           = (yawrateValue1 + yawrateValue2) / 2.000F;	

    //Yawrate_Operation_Previous_Value  = m_fYawRate;

  }
  else
  {
    /*
    When the above conditions are NOT met
    << Yawrate_Operation_Value >> = {{ Yawrate_Operation_Previous_Value  }}
    Finish the calculation of the yaw rate
    */
    m_bYawRateComputed  = false;
    //Yawrate_Operation_Value         = Yawrate_Operation_Previous_Value;
  }

}

CVersionInfoImpl CSimYawRateWorkaround::CreateVersionInfoFromI32( const long version )
{
  return CVersionInfoImpl (
    static_cast<unsigned char>((version >> 16) & 0xFF),
    static_cast<unsigned char>((version >> 8)  & 0xFF),
    static_cast<unsigned char>( version        & 0xFF));
}