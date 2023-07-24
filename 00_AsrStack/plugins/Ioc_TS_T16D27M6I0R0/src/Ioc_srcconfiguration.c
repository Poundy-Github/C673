/* Ioc_srcconfiguration.c
 *
 * This file defines the objects storing the IOC configuration.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: Ioc_srcconfiguration.c 2497 2018-02-06 12:11:28Z olme8414 $
*/

#include <private/Ioc_osinterface.h>
#include <private/Ioc_configinterface.h>
#include <Ioc_ChCfg.h>

const ioc_uint32_t IOC_nChannels = IOC_CFG_NCHANNELS;


#if (IOC_CFG_NCHANNELS > 0)

const ioc_config_t IOC_channelConfigurations[IOC_CFG_NCHANNELS] = IOC_CHANNEL_CONFIGURATIONS;

#if (IOC_LCFG_KERNEL_TYPE == IOC_MICROKERNEL)
const ioc_addressrange_t IOC_appReadableRegions[IOC_CFG_NREADABLEMKREGIONS] = IOC_CFG_READABLEMKREGIONS;
#endif


#else /* IOC_CFG_NCHANNELS */

/* IOC_channelConfigurations must be defined, so we add a dummy object here.
 * It won't be accessed, since IOC_nChannels is 0.
 * Strictly speaking, this wastes space. However, in this case, to save space,
 * the IOC can be completely removed from the project.
*/
const ioc_config_t IOC_channelConfigurations[1] = { IOC_EMPTY_CHANNEL_CONFIG_INIT };

#if (IOC_LCFG_KERNEL_TYPE == IOC_MICROKERNEL)
const ioc_addressrange_t IOC_appReadableRegions[1] = { IOC_EMPTY_ADDRESSRANGE_INIT };
#endif

#endif /* IOC_CFG_NCHANNELS */


/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
