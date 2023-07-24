#ifndef cct_ver_h__
#define cct_ver_h__

// PRQA S 1020,1026 EOF
// date: 2015-17-07, reviewer: Christian Exner, reason: The use case for the macros is the pre-processor, hence keeping them as defines makes sense.

/// CCT Checkpoint name in MKS
#define CCT_CHECKPOINT "AL_CCT_07.04.02_INT-0"

/// CCT library interface version, as a combination of the
/// checkpoint version: AL_CCT_AA.BB.CC_INT-DD -> 0xAABBCCDD
#define CCT_INTFVER (0x07040200)

#endif // cct_ver_h__
