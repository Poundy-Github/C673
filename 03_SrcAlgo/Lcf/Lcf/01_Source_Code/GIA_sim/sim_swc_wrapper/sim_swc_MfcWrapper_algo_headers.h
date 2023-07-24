#ifndef sim_swc_mfcwrapper_algo_headers_h__
#define sim_swc_mfcwrapper_algo_headers_h__

// switch off disturbing defines
#ifdef CFG_USE_COMPACT_ENUMS
#undef CFG_USE_COMPACT_ENUMS
#endif

// Switch to 8-Byte boundary alignment as it was in MFC300
#pragma pack( push, before_mfc310includes )
#pragma pack(8)

// change paths for includes to stay within the mfc310 scope
#pragma include_alias ( "cct_type.h"                         , "./Include/mfc310_stereo_if/cct_type.h"                          )
#pragma include_alias ( "sac_interface.h"                    , "./Include/mfc310_stereo_if/sac_interface.h"                     )
#pragma include_alias ( "sac_math_types.h"                   , "./Include/sac_math_types.h"                                     )
#pragma include_alias ( "sac_temperatur_model_types.h"       , "./Include/sac_temperatur_model_types.h"                         )
#pragma include_alias ( "viscr_smpc_depth_types.h"           , "./Include/viscr_smpc_depth_types.h"                             )
#pragma include_alias ( "ic_cfg_ext.h"                       , "./Include/mfc310_common/ic_cfg_ext.h"                           )
#pragma include_alias ( "glob_type.h"                        , "./Include/mfc310_common/glob_type.h"                            )
#pragma include_alias ( "glob_defs.h"                        , "./Include/mfc310_common/glob_defs.h"                            )
#pragma include_alias ( "glob_cfg.h"                         , "./Include/mfc310_common/MFC310_glob_cfg.h"                      )
#pragma include_alias ( "common_interface_defines.h"         , "./Include/mfc310_stereo_if/common_interface_defines.h"          )
#pragma include_alias ( "sfod_outputInterface_baseTypes.h"   , "./Include/mfc310_stereo_if/sfod_outputInterface_baseTypes.h"    )
#pragma include_alias ( "sfod_outputInterface_carpet.h"      , "./Include/mfc310_stereo_if/sfod_outputInterface_carpet.h"       )
#pragma include_alias ( "sfod_outputInterface_corridor.h"    , "./Include/mfc310_stereo_if/sfod_outputInterface_corridor.h"     )
#pragma include_alias ( "sfod_outputInterface_object.h"      , "./Include/mfc310_stereo_if/sfod_outputInterface_object.h"       )
#pragma include_alias ( "sfod_outputInterface_floxelParams.h", "./Include/mfc310_stereo_if/sfod_outputInterface_floxelParams.h" )
#pragma include_alias ( "hlar_ext.h"                         , "./Include/mfc310Hla/hlar_ext.h"                                )
#pragma include_alias ( "hlaf_type.h"                        , "./Include/mfc310Hla/function/hlaf_type.h"                      )
#pragma include_alias ( "hla_base.h"                         , "./Include/mfc310Hla/hla_base.h"                                )
#pragma include_alias ( "hla_type.h"                         , "./Include/mfc310Hla/hla_type.h"                                )
#pragma include_alias ( "LDInterface.h"                      , "./Include/mfc310_ld/LDInterface.h"                              )


// 310 specific includes
namespace mfc310
{
  namespace stereo
  {
    #include "./Include/sac_meas.h"
    #include "./Include/mfc310_stereo_if/sfod_outputInterface.h"
  }

  namespace ic
  {
    typedef signed long long sint64;
    #include "./Include/mfc310_ic/ic_interface.h"
    #include "./Include/mfc310_ic/ic_exposure.h"
  }

  namespace ld
  {
#define __PC_SW
    #include "./Include/mfc310_ld/LDInterface.h"
#undef __PC_SW
  }


  namespace sr
  {
    #undef GLOB_TYPE_H
    #pragma include_alias ( "glob_type.h"                        , "./Include/mfc310_sr/glob_type.h"                                )
    #include "./Include/mfc310_sr/srif_input.h"
  }

  namespace hla
  {
    // re-enable inclusions for this name space
    #undef PLATFORM_TYPES_H
    #undef GLOB_TYPE_H
    #undef GLOB_DEFS_H
    #undef MFC310_GLOB_CFG_H
    #pragma include_alias ( "glob_type.h"                        , "./Include/mfc310_common/glob_type.h"                            )
    // include interface of hla
    #include "./Include/mfc310Hla/hlar_ext.h"
    #include "./Include/mfc310Hla/function/hlaf_type.h"
    #include "./Include/mfc310Hla/hla_base.h"
    #include "./Include/mfc310Hla/hla_type.h" 
  }
}

// change back to normal
#pragma include_alias ( "cct_type.h"                         , "cct_type.h"                          )
#pragma include_alias ( "sac_interface.h"                    , "sac_interface.h"                     )
#pragma include_alias ( "sac_math_types.h"                   , "sac_math_types.h"                    )
#pragma include_alias ( "sac_temperatur_model_types.h"       , "sac_temperatur_model_types.h"        )
#pragma include_alias ( "viscr_smpc_depth_types.h"           , "viscr_smpc_depth_types.h"            )
#pragma include_alias ( "ic_cfg_ext.h"                       , "ic_cfg_ext.h"                        )
#pragma include_alias ( "glob_type.h"                        , "glob_type.h"                         )
#pragma include_alias ( "glob_defs.h"                        , "glob_defs.h"                         )
#pragma include_alias ( "glob_cfg.h"                         , "glob_cfg.h"                          )
#pragma include_alias ( "common_interface_defines.h"         , "common_interface_defines.h"          )
#pragma include_alias ( "sfod_outputInterface_baseTypes.h"   , "sfod_outputInterface_baseTypes.h"    )
#pragma include_alias ( "sfod_outputInterface_carpet.h"      , "sfod_outputInterface_carpet.h"       )
#pragma include_alias ( "sfod_outputInterface_corridor.h"    , "sfod_outputInterface_corridor.h"     )
#pragma include_alias ( "sfod_outputInterface_object.h"      , "sfod_outputInterface_object.h"       )
#pragma include_alias ( "sfod_outputInterface_floxelParams.h", "sfod_outputInterface_floxelParams.h" )
#pragma include_alias ( "hla_interface.h"                    , "hla_interface.h"                     )
#pragma include_alias ( "hlar_ext.h"                         , "hlar_ext.h"                          )
#pragma include_alias ( "hlaf_type.h"                        , "hlaf_type.h"                         )
#pragma include_alias ( "hla_type.h"                         , "hla_type.h"                          )
#pragma include_alias ( "hla_base.h"                         , "hla_base.h"                          )
#pragma include_alias ( "LDInterface.h"                      , "LDInterface.h"                       )

// switch off disturbing defines
#ifdef CFG_USE_COMPACT_ENUMS
#undef CFG_USE_COMPACT_ENUMS
#endif

// Switch back Byte alignment
#pragma pack( pop, before_mfc310includes )

#endif // sim_swc_mfcwrapper_algo_headers_h__

