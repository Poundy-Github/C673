/*!
 * File generated by platform wizard. DO NOT MODIFY
 *
 */

metaonly module Platform inherits xdc.platform.IPlatform {

    config ti.platforms.generic.Platform.Instance CPU =
        ti.platforms.generic.Platform.create("CPU", {
            clockRate:      500,                                       
            catalogName:    "ti.catalog.c6000",
            deviceName:     "Vayu",
            customMemoryMap:
           [          
                ["L1DSRAM", 
                     {
                        name: "L1DSRAM",
                        base: 0x00F00000,                    
                        len: 0x00000000,                    
                        space: "data",
                        access: "RW",
                     }
                ],
                ["L1PSRAM", 
                     {
                        name: "L1PSRAM",
                        base: 0x00E00000,                    
                        len: 0x00000000,                    
                        space: "code",
                        access: "RWX",
                     }
                ],
                ["L2SRAM", 
                     {
                        name: "L2SRAM",
                        base: 0x00800000,                    
                        len: 0x00040000,                    
                        space: "code/data",
                        access: "RWX",
                     }
                ],
                ["DDR_DSP1_CODE", 
                     {
                        name: "DDR_DSP1_CODE",
                        base: 0x0,                    
                        len: 0x4,                    
                        space: "code",
                        access: "RW",
                     }
                ],
                ["DDR_DSP1_DATA_ASIL", 
                     {
                        name: "DDR_DSP1_DATA_ASIL",
                        base: 0x4,                    
                        len: 0x4,                    
                        space: "data",
                        access: "RW",
                     }
                ],
           ],
          l2Mode: "128k",
          l1PMode: "32k",
          l1DMode: "32k",

    });
    
instance :
    
    override config string codeMemory  = "DDR_DSP1_CODE";   
    override config string dataMemory  = "DDR_DSP1_DATA_ASIL";                                
    override config string stackMemory = "DDR_DSP1_DATA_ASIL";

    config String l2Mode = "128k";
    config String l1PMode = "32k";
    config String l1DMode = "32k";
}
