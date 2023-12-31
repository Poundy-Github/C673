/*!
 * File generated by platform wizard. DO NOT MODIFY
 *
 */

metaonly module Platform inherits xdc.platform.IPlatform {

    config ti.platforms.generic.Platform.Instance CPU =
        ti.platforms.generic.Platform.create("CPU", {
            clockRate:      200,                                       
            catalogName:    "ti.catalog.arm.cortexm3",
            deviceName:     "TMS320DM8148",
            customMemoryMap:
           [          
                ["M3VPSS_CODE", 
                     {
                        name: "M3VPSS_CODE",
                        base: 0x00000000,                    
                        len: 0x00000004,                    
                        space: "code",
                        access: "RX",
                     }
                ],
                ["M3VPSS_DATA", 
                     {
                        name: "M3VPSS_DATA",
                        base: 0x00000004,                    
                        len: 0x00000004,                    
                        space: "data",
                        access: "RW",
                     }
                ],
           ],

    });
    
instance :
    
    override config string codeMemory  = "M3VPSS_CODE";   
    override config string dataMemory  = "M3VPSS_DATA";                                
    override config string stackMemory = "M3VPSS_DATA";

}
