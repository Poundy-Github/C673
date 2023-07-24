// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This header contains the defines for the RTA version.

#ifndef RTA_VERSION_H_
#define RTA_VERSION_H_


/// Definition of component major version.
/// It has always to match with the release version.
#define RTA_MAJOR_VERSION 50uL


/// Definition of component minor version.
/// It has always to match with the release version.
#define RTA_MINOR_VERSION 0uL


/// Definition of component patch version.
/// It has always to match with the release version.
#define RTA_PATCH_VERSION 0uL


/// This define holds the whole componentVersion: \n
/// Bit  0 ...  7: patchVersion \n
/// Bit  8 ... 15: MinorVersion \n
/// Bit 16 ... 31: Major Version
#define RTA_COMPONENT_VERSION  (((RTA_MAJOR_VERSION<<16uL) | (RTA_MINOR_VERSION <<8uL) | (RTA_PATCH_VERSION)))


#endif // RTA_VERSION_H_
