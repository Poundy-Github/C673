/* --------{ EB Automotive C Source File }-------- */

#ifndef ETH_H
#define ETH_H

#include <Eth_17_GEthMac.h>


/* needed since the module test do not consider VendorId & VendorApiInfix in all published interfaces */

#define Eth_ControllerInit(tmp1,tmp2)    E_OK 

#define ETH_AR_RELEASE_MAJOR_VERSION     ETH_17_GETHMAC_AR_RELEASE_MAJOR_VERSION
#define ETH_AR_RELEASE_MINOR_VERSION     ETH_17_GETHMAC_AR_RELEASE_MINOR_VERSION

/* Global Type Definitions */
typedef Eth_17_GEthMac_ConfigType        Eth_ConfigType;

/* Global Function Declarations */

#define Eth_Init                         Eth_17_GEthMac_Init
#define Eth_SetControllerMode            Eth_17_GEthMac_SetControllerMode
#define Eth_GetControllerMode            Eth_17_GEthMac_GetControllerMode
#define Eth_GetPhysAddr                  Eth_17_GEthMac_GetPhysAddr
#define Eth_SetPhysAddr                  Eth_17_GEthMac_SetPhysAddr
#define Eth_UpdatePhysAddrFilter         Eth_17_GEthMac_UpdatePhysAddrFilter
#define Eth_WriteMii                     Eth_17_GEthMac_WriteMii
#define Eth_ReadMii                      Eth_17_GEthMac_ReadMii
#define Eth_GetDropCount                 Eth_17_GEthMac_GetDropCount 
#define Eth_GetEtherStats                Eth_17_GEthMac_GetEtherStats
#define Eth_GetCurrentTime       	     Eth_17_GEthMac_GetCurrentTime
#define Eth_EnableEgressTimeStamp        Eth_17_GEthMac_EnableEgressTimeStamp
#define Eth_GetEgressTimeStamp           Eth_17_GEthMac_GetEgressTimeStamp
#define Eth_GetIngressTimeStamp          Eth_17_GEthMac_GetIngressTimeStamp
#define Eth_SetCorrectionTime            Eth_17_GEthMac_SetCorrectionTime
#define Eth_SetGlobalTime                Eth_17_GEthMac_SetGlobalTime
#define Eth_ProvideTxBuffer              Eth_17_GEthMac_ProvideTxBuffer
#define Eth_Transmit                     Eth_17_GEthMac_Transmit
#define Eth_Receive                      Eth_17_GEthMac_Receive
#define Eth_TxConfirmation               Eth_17_GEthMac_TxConfirmation
#define Eth_GetVersionInfo               Eth_17_GEthMac_GetVersionInfo
#define Eth_MainFunction                 Eth_17_GEthMac_MainFunction

#endif /* ETH_H */
