#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: areas.py
#
# DESCRIPTION: Script that contains the list of area used for Ram/Rom/shared allocation of Libraries.
#
# INITIAL AUTHOR: Hendra.Sasmito-EXT (uidw1406)
#
# CREATION DATE: 2013/11/04
#
# LAST CHANGE:      $Date: 2021/12/13 19:03:49CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: areas.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:03:49CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.10 2015/08/26 12:02:32CEST Verzilov-EXT, Evgenii (uidg4013) 
# CHANGES:                   introduced new memory blocks for FUSI-RAM and FUSI-ROM
# CHANGES:                   - Added comments -  uidg4013 [Aug 26, 2015 12:02:33 PM CEST]
# CHANGES:                   Change Package : 301231:2 http://mks-psad:7002/im/viewissue?selection=301231
# CHANGES:                   Revision 1.9 2015/06/29 05:59:48CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   Areas are updated based on the change package 350940
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 29, 2015 5:59:48 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

areas = [
# RAM block: 
"RAM, \
.far, \
.bss, \
.got, \
mdb, \
mdb_unprotected, \
.fardata, \
.far:rta_buffer, \
.neardata, \
.data_near_qm, \
.data_far_qm, \
.data_near_asil, \
scratch_ddr_sr, \
scratch_vodca, \
ALGO_STATICDATA_DDR, \
vcop_parameter_block, \
.vcop_parameter_block, \
COMMON, \
.eve_shared, \
.exc_context, \
.memsec_sac_var, \
dmem_pc, \
.intvecs, \
.inthandler, \
.stack, \
res_set_sect, \
Eve2All, \
SBL_APPL_INTERFACE_shared, \
.staticSectionStart, \
.staticSectionEnd, \
.vip_frame, \
.infoblock, \
.ducatiBoot, \
.task_mon_event_buff, \
.intram_data, \
.mbox_fifo_out, \
.exc_context_dsp_0, \
.exc_context_ca8_0, \
.exc_context_m3_1, \
.fatal_error_context, \
.data_qm, \
.exc_context_eve_1, \
iob, \
.exc_context_eve_0", \
\
# FUSI-RAM block: 
"FUSI-RAM, \
.data_secure_section_var", \
\
# FUSI-ROM block: 
"FUSI-ROM, \
.const_secure_section_const", \
\
# ROM block
"ROM, \
.data, \
.data.1, \
.data.2, \
.text, \
.text_qm, \
.text_all, \
.const, \
.const_all,  \
algo_ext_const, \
.rodata, \
.switch, \
.switch.1, \
.switch.2, \
.switch.3, \
.init_array, \
.const:.string, \
.const:.string:*, \
.ARM, \
.TI, \
.intram_code, \
.stab, \
.bootVecs, \
.resetVecs, \
.c_int00, \
.bootVecs, \
.vecs", \
\
# IGNORED block (contains shared memory regions)
"IGNORED, \
dmem_sr, \
imem_la_sr, \
imem_ha_sr, \
imem_lb_sr, \
imem_hb_sr, \
wmem_sr, \
imem_ha_hla, \
imem_la_hla, \
wmem_hla, \
dmem_hla, \
.debug_aranges, \
.debug_info, \
.debug_abbrev, \
.debug_line, \
.debug_str, \
.debug_frame, \
.debug_loc, \
.debug_ranges, \
dmem_vodca, \
ALGO_SHARED_VODCA_EVE, \
ALGO_SCRATCHBUFF_DMEM, \
ALGO_SCRATCHBUFF_OCMC_EVE, \
.shared_data, \
.mem_l2_shared, \
.mem_l3_shared, \
ALGO_SCRATCHBUFF_WMEM, \
ALGO_SCRATCHBUFF_IMEM_LA, \
ALGO_SCRATCHBUFF_IMEM_HA, \
ALGO_SCRATCHBUFF_IMEM_LB, \
ALGO_SCRATCHBUFF_IMEM_HB, \
ALGO_SCRATCHBUFF_DDR, \
.SBL_APPL_INTERFACE_shared, \
scratch_cipp, \
.application_debug_ctrl", 
]
