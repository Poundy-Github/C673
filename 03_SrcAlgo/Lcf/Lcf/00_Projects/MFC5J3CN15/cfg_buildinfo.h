#ifndef GEN_BUILDINFO_H
#define GEN_BUILDINFO_H
// #ifndef _APPL
// #define _APPL
// #endif
// Select project name. Use max. 8 characters.
#define MK_PROJECT_ID_INFOBLOCK MFC5J3CN15\0
// #define MK_OUTPUT_FILE_NAME_BASE mfc400_appl
// #define MK_EXE_ID_NAME= 1
// Default user, time and date
#define MK_BNAME default_user
#define MK_BTIME 123456U
#define MK_BDATE 123456U
// Release Naming   PPB.YWW.DC
// PP -> Project Code (00 - Trunk, ... , 6 - MFC431 )
// B	-> Baseline (0 - Trunk, 1 - Rel 2.0, 2 - Rel 2.1, ...)
// Y	-> Year (0 - 2017, 1 - 2018, 2 - 2019)
// WW	-> Calendar week
// D	-> Day of Week (0 - 6 / So - Sa)
// C	-> Counter per day (0-9) / Checkpoint per day
// SW Version Number 000.332.20
//
#define MK_EXE_VERSION ((( 6 ) << 16u) + (( 111 ) << 8u) + ( 10 ))
//
// Selected build type: 0x00: do not use, 0x01: PreRelease, 0x02: Testversion, 0x03: NightlyBuilds, 0x04: Release
#define MK_EXE_BTYPE 0x04U
#define MK_OEM_BOOT_INIT  /* .OemId = */ MFC5J3CN15, /* .SGBMId = */ { /* .ProcessClass = */ { 0x08 },	/* (SWFL) */ /* .Ident = */ { 0x00, 0x00, 0x0D, 0xB5 }, /* .Version = */ { 4, 31, 1 } }, /* .SerialNumber= */ { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 }, /* .pSign = */ 0, /* .Reserved = */ 0
//#define MK_MCU_NAME= 1
#define MK_CUSTOMER_PRODUCT_ID  ""
#endif // GEN_BUILDINFO_H
