// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT:      RTA
// VERSION:        $Revision: 1.30 $
/// @file
/// @brief         contains enumeration describing all GlobalIDs sent to the RTA_MOs, file is generated, no manual changes

// File Name:      $Source: RTA_GlobalIDs.h $
// Author:         Matthias Kammerl

/***********************************************************************************************************************/

#ifndef RTA_GLOBALDS_H_INCLUDED
#define RTA_GLOBALDS_H_INCLUDED

/// enumeration describing all GlobalIDs sent to the RTA_MOs \n
/// These enumLiterals shall be used by the components as globalIDs for adding their rtaEvents.
/// They are used as second argument in the function \n
/// void RTA_v_AddEvent(const RTA_t_Events EVENT, const uint8 u_GLOBALID, const uint8 u_LOCALID, const uint8 u_OPTDATA)

/// Up to now the compIDs defined in glob_comp_id.h are used as globalIDs.
/// But as these compIDs are not only used for RTA we have quite a mess concerning the IDs. \n
/// A further important reason is that we are running out of the 8-bit range. Currently we have
/// ~250 compIDs and we want avoid to extend to 16-bit values.
/// Therefore we decided to introduce an enumeration defining all globalIDs. \n
/// Important: \n
/// - Only the literals of this enumeration shall be used as globalIDs for rtaEvents \n
/// - The literals of this enumeration must not be used for any other purpose!
///   Only exception: They shall be used by the genericAdapter as localIDs to measure the runtime of the related
///   algorithm (adaptorRuntime and algoExecution). \n
/// - In case you need a new RTA_GLOBALID for your component just contact Matthias Kammerl. \n
///   (Matthias.Kammerl@continental-corporation.com)
/// As we just started the enumeration is not complete yet.


//Generated file - no manual changes please!****************************************************************************

//PRQA S 0647 L1
//date:          2019-09_18, reviewer: R. Sanyasinaidu, M. Kammerl
//reason:        [L] Number of enumeration constants exceeds 127 - program does not conform strictly to ISO:C90: Non-critical.
//justification: Full 8-bit range is needed.

//___GENERATOR_TAG___RTA_GLOBAL_ID_ENUM___START___

//  Number of free globalIDs in the 8-bit range: 199

typedef enum
{
  RTA_GLOBALID_INTERRUPTS =   0,  // All the interrupts - only for RTA internal usage!!
  RTA_GLOBALID_RTE        = 200,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_1      = 201,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_2      = 202,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_3      = 203,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_4      = 204,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_5      = 205,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_6      = 206,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_7      = 207,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_8      = 208,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_9      = 209,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_10     = 210,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_11     = 211,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_12     = 212,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_13     = 213,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_14     = 214,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_15     = 215,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_16     = 216,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_17     = 217,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_18     = 218,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_19     = 219,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_20     = 220,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_21     = 221,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_22     = 222,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_23     = 223,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_24     = 224,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_25     = 225,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_26     = 226,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_27     = 227,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_28     = 228,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_29     = 229,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_30     = 230,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_31     = 231,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_32     = 232,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_33     = 233,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_34     = 234,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_35     = 235,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_36     = 236,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_37     = 237,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_38     = 238,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_39     = 239,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_40     = 240,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_41     = 241,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_42     = 242,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_43     = 243,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_44     = 244,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_45     = 245,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_46     = 246,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_47     = 247,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_48     = 248,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_49     = 249,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_50     = 250,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_51     = 251,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_52     = 252,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_53     = 253,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_54     = 254,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_DONOTUSE   = 255   // !!! MUST NOT BE USED !!!
}RTA_t_GlobalIDs;
//___GENERATOR_TAG___RTA_GLOBAL_ID_ENUM___END___

//PRQA L:L1

//Generated file - no manual changes please!****************************************************************************

#endif //RTA_GLOBALDS_H_INCLUDED
