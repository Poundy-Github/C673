/*  **********************************************************************

  COMPANY:                    Continental Automotive

  PROJECT:                    MFC300

  CPU:                        DSP Stereo

  PACKAGE:                    SFOD

  MODULNAME:                  sfod_interface_defines.h

  DESCRIPTION:                Defines for sfod_interface.h

  CREATION DATE:              31.01.2011

**************************************************************************** */

#ifndef COMMON_INTERFACE_DEFINES_H
#define COMMON_INTERFACE_DEFINES_H


// ~CodeReview ~ID:ec3a3f95ea6cad75fec0e409f5fd7ec8 ~Reviewer:F.Stein/O.Vogel ~Date:7/5/2012 ~Priority:2 ~Comment:Global: The following three files have to be removed from all files!!
#if defined(PC_SIM) && !defined(GUYS_BUILD_MESSAGE_COMPRESSOR)
    #pragma message ("- Including [" __TIMESTAMP__ "] " __FILE__ )
#endif // PC_SIM



#ifdef __cplusplus
  // ~CodeReview ~ID:d0a7c3a79406cf58b69f1abdc956cdca ~Reviewer:F.Stein/O.Vogel ~Date:7/5/2012 ~Priority:2 ~Comment:Global: The following three files have to be removed from all files!!
  #if defined (PC_SIM) && !defined(GUYS_BUILD_MESSAGE_COMPRESSOR)
    #pragma message(" Interface structs have tag ArchiveVersionNumber")
  #endif // PC_SIM

  #define DEFINE_VERSION_MEMBER(STRUCT) \
    ui32_t VersionNumber; \
    enum { ArchiveVersionNumber =  STRUCT##_VersionNumber }
#else
  #if defined(PC_SIM) && !defined(GUYS_BUILD_MESSAGE_COMPRESSOR)
    #pragma message(" Interface structs do NOT provide ArchiveVersionNumber")
  #endif // PC_SIM

  #define DEFINE_VERSION_MEMBER(STRUCT) ui32_t VersionNumber  /*!< Version Number of the entity */
#endif // __cplusplus


#endif //COMMON_INTERFACE_DEFINES_H
