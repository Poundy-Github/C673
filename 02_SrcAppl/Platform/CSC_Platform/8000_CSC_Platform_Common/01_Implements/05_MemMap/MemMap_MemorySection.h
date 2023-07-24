/**
 * \file CSC_Platform_MemorySection.h
 *
 * \brief
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2022.12.24			Mingfen XIAO			1.Init version
 */

/******************************************************************
 * Code Flash Memory Map : Core0 QM Code Section
 * ****************************************************************/
#if ((defined CORE0_QM_CODE_SECTION_OPEN) && (defined START_SEC_ROM_CORE0_QM_CODE_SECTION))
#	error "Section: CORE0_QM_CODE_SECTION_OPEN opened but in addition: START_SEC_ROM_CORE0_QM_CODE_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_ROM_CORE0_QM_CODE_SECTION
#	undef START_SEC_ROM_CORE0_QM_CODE_SECTION
#	define CORE0_QM_CODE_SECTION_OPEN
#pragma section code Grp_ROM_Core0_QM_Code_Section
#endif

#ifdef STOP_SEC_ROM_CORE0_QM_CODE_SECTION
#	undef STOP_SEC_ROM_CORE0_QM_CODE_SECTION
#	ifdef CORE0_QM_CODE_SECTION_OPEN
#		undef CORE0_QM_CODE_SECTION_OPEN
#pragma section code restore
#	else
#		error "CORE0 QM code section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * Code Flash Memory Map : Core0 ASIL Code Section
 * ****************************************************************/
#if ((defined CORE0_ASIL_CODE_SECTION_OPEN) && (defined START_SEC_ROM_CORE0_ASIL_CODE_SECTION))
#	error "Section: CORE0_ASIL_CODE_SECTION_OPEN opened but in addition: START_SEC_ROM_CORE0_ASIL_CODE_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_ROM_CORE0_ASIL_CODE_SECTION
#	undef START_SEC_ROM_CORE0_ASIL_CODE_SECTION
#	define CORE0_ASIL_CODE_SECTION_OPEN
#pragma section code Grp_ROM_Core0_ASIL_Code_Section
#endif

#ifdef STOP_SEC_ROM_CORE0_ASIL_CODE_SECTION
#	undef STOP_SEC_ROM_CORE0_ASIL_CODE_SECTION
#	ifdef CORE0_ASIL_CODE_SECTION_OPEN
#		undef CORE0_ASIL_CODE_SECTION_OPEN
#pragma section code restore
#	else
#		error "CORE0 ASIL code section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * Code Flash Memory Map : CORE1 QM Code Section
 * ****************************************************************/
#if ((defined CORE1_QM_CODE_SECTION_OPEN) && (defined START_SEC_ROM_CORE1_QM_CODE_SECTION))
#	error "Section: CORE1_QM_CODE_SECTION_OPEN opened but in addition: START_SEC_ROM_CORE1_QM_CODE_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_ROM_CORE1_QM_CODE_SECTION
#	undef START_SEC_ROM_CORE1_QM_CODE_SECTION
#	define CORE1_QM_CODE_SECTION_OPEN
#pragma section code Grp_ROM_CORE1_QM_Code_Section
#endif

#ifdef STOP_SEC_ROM_CORE1_QM_CODE_SECTION
#	undef STOP_SEC_ROM_CORE1_QM_CODE_SECTION
#	ifdef CORE1_QM_CODE_SECTION_OPEN
#		undef CORE1_QM_CODE_SECTION_OPEN
#pragma section code restore
#	else
#		error "CORE1 QM code section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * Code Flash Memory Map : CORE1 ASIL Code Section
 * ****************************************************************/
#if ((defined CORE1_ASIL_CODE_SECTION_OPEN) && (defined START_SEC_ROM_CORE1_ASIL_CODE_SECTION))
#	error "Section: CORE1_ASIL_CODE_SECTION_OPEN opened but in addition: START_SEC_ROM_CORE1_ASIL_CODE_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_ROM_CORE1_ASIL_CODE_SECTION
#	undef START_SEC_ROM_CORE1_ASIL_CODE_SECTION
#	define CORE1_ASIL_CODE_SECTION_OPEN
#pragma section code Grp_ROM_CORE1_ASIL_Code_Section
#endif

#ifdef STOP_SEC_ROM_CORE1_ASIL_CODE_SECTION
#	undef STOP_SEC_ROM_CORE1_ASIL_CODE_SECTION
#	ifdef CORE1_ASIL_CODE_SECTION_OPEN
#		undef CORE1_ASIL_CODE_SECTION_OPEN
#pragma section code restore
#	else
#		error "CORE1 ASIL code section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * Code Flash Memory Map : CORE2 QM Code Section
 * ****************************************************************/
#if ((defined CORE2_QM_CODE_SECTION_OPEN) && (defined START_SEC_ROM_CORE2_QM_CODE_SECTION))
#	error "Section: CORE2_QM_CODE_SECTION_OPEN opened but in addition: START_SEC_ROM_CORE2_QM_CODE_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_ROM_CORE2_QM_CODE_SECTION
#	undef START_SEC_ROM_CORE2_QM_CODE_SECTION
#	define CORE2_QM_CODE_SECTION_OPEN
#pragma section code Grp_ROM_CORE2_QM_Code_Section
#endif

#ifdef STOP_SEC_ROM_CORE2_QM_CODE_SECTION
#	undef STOP_SEC_ROM_CORE2_QM_CODE_SECTION
#	ifdef CORE2_QM_CODE_SECTION_OPEN
#		undef CORE2_QM_CODE_SECTION_OPEN
#pragma section code restore
#	else
#		error "CORE2 QM code section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * Code Flash Memory Map : CORE2 ASIL Code Section
 * ****************************************************************/
#if ((defined CORE2_ASIL_CODE_SECTION_OPEN) && (defined START_SEC_ROM_CORE2_ASIL_CODE_SECTION))
#	error "Section: CORE2_ASIL_CODE_SECTION_OPEN opened but in addition: START_SEC_ROM_CORE2_ASIL_CODE_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_ROM_CORE2_ASIL_CODE_SECTION
#	undef START_SEC_ROM_CORE2_ASIL_CODE_SECTION
#	define CORE2_ASIL_CODE_SECTION_OPEN
#pragma section code Grp_ROM_CORE2_ASIL_Code_Section
#endif

#ifdef STOP_SEC_ROM_CORE2_ASIL_CODE_SECTION
#	undef STOP_SEC_ROM_CORE2_ASIL_CODE_SECTION
#	ifdef CORE2_ASIL_CODE_SECTION_OPEN
#		undef CORE2_ASIL_CODE_SECTION_OPEN
#pragma section code restore
#	else
#		error "CORE2 ASIL code section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * Code Flash Memory Map : CORE3 QM Code Section
 * ****************************************************************/
#if ((defined CORE3_QM_CODE_SECTION_OPEN) && (defined START_SEC_ROM_CORE2_QM_CODE_SECTION))
#	error "Section: CORE3_QM_CODE_SECTION_OPEN opened but in addition: START_SEC_ROM_CORE3_QM_CODE_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_ROM_CORE3_QM_CODE_SECTION
#	undef START_SEC_ROM_CORE3_QM_CODE_SECTION
#	define CORE3_QM_CODE_SECTION_OPEN
#pragma section code Grp_ROM_CORE3_QM_Code_Section
#endif

#ifdef STOP_SEC_ROM_CORE3_QM_CODE_SECTION
#	undef STOP_SEC_ROM_CORE3_QM_CODE_SECTION
#	ifdef CORE3_QM_CODE_SECTION_OPEN
#		undef CORE3_QM_CODE_SECTION_OPEN
#pragma section code restore
#	else
#		error "CORE3 QM code section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * Code Flash Memory Map : CORE3 ASIL Code Section
 * ****************************************************************/
#if ((defined CORE3_ASIL_CODE_SECTION_OPEN) && (defined START_SEC_ROM_CORE3_ASIL_CODE_SECTION))
#	error "Section: CORE3_ASIL_CODE_SECTION_OPEN opened but in addition: START_SEC_ROM_CORE3_ASIL_CODE_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_ROM_CORE3_ASIL_CODE_SECTION
#	undef START_SEC_ROM_CORE3_ASIL_CODE_SECTION
#	define CORE3_ASIL_CODE_SECTION_OPEN
#pragma section code Grp_ROM_CORE3_ASIL_Code_Section
#endif

#ifdef STOP_SEC_ROM_CORE3_ASIL_CODE_SECTION
#	undef STOP_SEC_ROM_CORE3_ASIL_CODE_SECTION
#	ifdef CORE3_ASIL_CODE_SECTION_OPEN
#		undef CORE3_ASIL_CODE_SECTION_OPEN
#pragma section code restore
#	else
#		error "CORE3 ASIL code section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * Code Flash Memory Map : Core0 QM CONST Section
 * ****************************************************************/
#if ((defined CORE0_QM_CONST_SECTION_OPEN) && (defined START_SEC_ROM_CORE0_QM_CONST_SECTION))
#	error "Section: CORE0_QM_CONST_SECTION_OPEN opened but in addition: START_SEC_ROM_CORE0_QM_CONST_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_ROM_CORE0_QM_CONST_SECTION
#	undef START_SEC_ROM_CORE0_QM_CONST_SECTION
#	define CORE0_QM_CONST_SECTION_OPEN
#pragma section farrom Grp_ROM_Core0_QM_Const_Section
#endif

#ifdef STOP_SEC_ROM_CORE0_QM_CONST_SECTION
#	undef STOP_SEC_ROM_CORE0_QM_CONST_SECTION
#	ifdef CORE0_QM_CONST_SECTION_OPEN
#		undef CORE0_QM_CONST_SECTION_OPEN
#pragma section farrom restore
#	else
#		error "CORE0 QM CONST section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * Code Flash Memory Map : Core0 ASIL CONST Section
 * ****************************************************************/
#if ((defined CORE0_ASIL_CONST_SECTION_OPEN) && (defined START_SEC_ROM_CORE0_ASIL_CONST_SECTION))
#	error "Section: CORE0_ASIL_CONST_SECTION_OPEN opened but in addition: START_SEC_ROM_CORE0_ASIL_CONST_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_ROM_CORE0_ASIL_CONST_SECTION
#	undef START_SEC_ROM_CORE0_ASIL_CONST_SECTION
#	define CORE0_ASIL_CONST_SECTION_OPEN
#pragma section farrom Grp_ROM_Core0_ASIL_Const_Section
#endif

#ifdef STOP_SEC_ROM_CORE0_ASIL_CONST_SECTION
#	undef STOP_SEC_ROM_CORE0_ASIL_CONST_SECTION
#	ifdef CORE0_ASIL_CONST_SECTION_OPEN
#		undef CORE0_ASIL_CONST_SECTION_OPEN
#pragma section farrom restore
#	else
#		error "CORE0 ASIL CONST section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * Code Flash Memory Map : CORE1 QM CONST Section
 * ****************************************************************/
#if ((defined CORE1_QM_CONST_SECTION_OPEN) && (defined START_SEC_ROM_CORE1_QM_CONST_SECTION))
#	error "Section: CORE1_QM_CONST_SECTION_OPEN opened but in addition: START_SEC_ROM_CORE1_QM_CONST_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_ROM_CORE1_QM_CONST_SECTION
#	undef START_SEC_ROM_CORE1_QM_CONST_SECTION
#	define CORE1_QM_CONST_SECTION_OPEN
#pragma section farrom Grp_ROM_Core1_QM_Const_Section
#endif

#ifdef STOP_SEC_ROM_CORE1_QM_CONST_SECTION
#	undef STOP_SEC_ROM_CORE1_QM_CONST_SECTION
#	ifdef CORE1_QM_CONST_SECTION_OPEN
#		undef CORE1_QM_CONST_SECTION_OPEN
#pragma section farrom restore
#	else
#		error "CORE1 QM CONST section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * Code Flash Memory Map : CORE1 ASIL CONST Section
 * ****************************************************************/
#if ((defined CORE1_ASIL_CONST_SECTION_OPEN) && (defined START_SEC_ROM_CORE1_ASIL_CONST_SECTION))
#	error "Section: CORE1_ASIL_CONST_SECTION_OPEN opened but in addition: START_SEC_ROM_CORE1_ASIL_CONST_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_ROM_CORE1_ASIL_CONST_SECTION
#	undef START_SEC_ROM_CORE1_ASIL_CONST_SECTION
#	define CORE1_ASIL_CONST_SECTION_OPEN
#pragma section farrom Grp_ROM_Core1_ASIL_Const_Section
#endif

#ifdef STOP_SEC_ROM_CORE1_ASIL_CONST_SECTION
#	undef STOP_SEC_ROM_CORE1_ASIL_CONST_SECTION
#	ifdef CORE1_ASIL_CONST_SECTION_OPEN
#		undef CORE1_ASIL_CONST_SECTION_OPEN
#pragma section farrom restore
#	else
#		error "CORE1 ASIL CONST section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * Code Flash Memory Map : CORE2 QM CONST Section
 * ****************************************************************/
#if ((defined CORE2_QM_CONST_SECTION_OPEN) && (defined START_SEC_ROM_CORE2_QM_CONST_SECTION))
#	error "Section: CORE2_QM_CONST_SECTION_OPEN opened but in addition: START_SEC_ROM_CORE2_QM_CONST_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_ROM_CORE2_QM_CONST_SECTION
#	undef START_SEC_ROM_CORE2_QM_CONST_SECTION
#	define CORE2_QM_CONST_SECTION_OPEN
#pragma section farrom Grp_ROM_Core2_QM_Const_Section
#endif

#ifdef STOP_SEC_ROM_CORE2_QM_CONST_SECTION
#	undef STOP_SEC_ROM_CORE2_QM_CONST_SECTION
#	ifdef CORE2_QM_CONST_SECTION_OPEN
#		undef CORE2_QM_CONST_SECTION_OPEN
#pragma section farrom restore
#	else
#		error "CORE2 QM CONST section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * Code Flash Memory Map : CORE2 ASIL CONST Section
 * ****************************************************************/
#if ((defined CORE2_ASIL_CONST_SECTION_OPEN) && (defined START_SEC_ROM_CORE2_ASIL_CONST_SECTION))
#	error "Section: CORE2_ASIL_CONST_SECTION_OPEN opened but in addition: START_SEC_ROM_CORE2_ASIL_CONST_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_ROM_CORE2_ASIL_CONST_SECTION
#	undef START_SEC_ROM_CORE2_ASIL_CONST_SECTION
#	define CORE2_ASIL_CONST_SECTION_OPEN
#pragma section farrom Grp_ROM_Core2_ASIL_Const_Section
#endif

#ifdef STOP_SEC_ROM_CORE2_ASIL_CONST_SECTION
#	undef STOP_SEC_ROM_CORE2_ASIL_CONST_SECTION
#	ifdef CORE2_ASIL_CONST_SECTION_OPEN
#		undef CORE2_ASIL_CONST_SECTION_OPEN
#pragma section farrom restore
#	else
#		error "CORE2 ASIL CONST section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * Code Flash Memory Map : CORE3 QM CONST Section
 * ****************************************************************/
#if ((defined CORE3_QM_CONST_SECTION_OPEN) && (defined START_SEC_ROM_CORE3_QM_CONST_SECTION))
#	error "Section: CORE3_QM_CONST_SECTION_OPEN opened but in addition: START_SEC_ROM_CORE3_QM_CONST_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_ROM_CORE3_QM_CONST_SECTION
#	undef START_SEC_ROM_CORE3_QM_CONST_SECTION
#	define CORE3_QM_CONST_SECTION_OPEN
#pragma section farrom Grp_ROM_Core3_QM_Const_Section
#endif

#ifdef STOP_SEC_ROM_CORE3_QM_CONST_SECTION
#	undef STOP_SEC_ROM_CORE3_QM_CONST_SECTION
#	ifdef CORE3_QM_CONST_SECTION_OPEN
#		undef CORE3_QM_CONST_SECTION_OPEN
#pragma section farrom restore
#	else
#		error "CORE3 QM CONST section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * Code Flash Memory Map : CORE3 ASIL CONST Section
 * ****************************************************************/
#if ((defined CORE3_ASIL_CONST_SECTION_OPEN) && (defined START_SEC_ROM_CORE3_ASIL_CONST_SECTION))
#	error "Section: CORE3_ASIL_CONST_SECTION_OPEN opened but in addition: START_SEC_ROM_CORE3_ASIL_CONST_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_ROM_CORE3_ASIL_CONST_SECTION
#	undef START_SEC_ROM_CORE3_ASIL_CONST_SECTION
#	define CORE3_ASIL_CONST_SECTION_OPEN
#pragma section farrom Grp_ROM_Core3_ASIL_Const_Section
#endif

#ifdef STOP_SEC_ROM_CORE3_ASIL_CONST_SECTION
#	undef STOP_SEC_ROM_CORE3_ASIL_CONST_SECTION
#	ifdef CORE3_ASIL_CONST_SECTION_OPEN
#		undef CORE3_ASIL_CONST_SECTION_OPEN
#pragma section farrom restore
#	else
#		error "CORE3 ASIL CONST section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * DSPR Memory Map : Core0 QM VAR_CLEARED Section
 * ****************************************************************/
#if ((defined DSPR_CORE0_QM_VAR_CLEARED_SECTION_OPEN) && (defined START_SEC_RAM_DSPR_CORE0_QM_VAR_CLEARED_SECTION))
#	error "Section: DSPR_CORE0_QM_VAR_CLEARED_SECTION_OPEN opened but in addition: START_SEC_RAM_DSPR_CORE0_QM_VAR_CLEARED_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_DSPR_CORE0_QM_VAR_CLEARED_SECTION
#	undef START_SEC_RAM_DSPR_CORE0_QM_VAR_CLEARED_SECTION
#	define DSPR_CORE0_QM_VAR_CLEARED_SECTION_OPEN
#pragma section farbss Grp_RAM_DSPR_Core0_QM_Bss_Section
#endif

#ifdef STOP_SEC_RAM_DSPR_CORE0_QM_VAR_CLEARED_SECTION
#	undef STOP_SEC_RAM_DSPR_CORE0_QM_VAR_CLEARED_SECTION
#	ifdef DSPR_CORE0_QM_VAR_CLEARED_SECTION_OPEN
#		undef DSPR_CORE0_QM_VAR_CLEARED_SECTION_OPEN
#pragma section farbss restore
#	else
#		error "DSPR_CORE0 QM VAR_CLEARED section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * DSPR Memory Map : Core0 ASIL VAR_CLEARED Section
 * ****************************************************************/
#if ((defined DSPR_CORE0_ASIL_VAR_CLEARED_SECTION_OPEN) && (defined START_SEC_RAM_DSPR_CORE0_ASIL_VAR_CLEARED_SECTION))
#	error "Section: DSPR_CORE0_ASIL_VAR_CLEARED_SECTION_OPEN opened but in addition: START_SEC_RAM_DSPR_CORE0_ASIL_VAR_CLEARED_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_DSPR_CORE0_ASIL_VAR_CLEARED_SECTION
#	undef START_SEC_RAM_DSPR_CORE0_ASIL_VAR_CLEARED_SECTION
#	define DSPR_CORE0_ASIL_VAR_CLEARED_SECTION_OPEN
#pragma section farbss Grp_RAM_DSPR_Core0_ASIL_Bss_Section
#endif

#ifdef STOP_SEC_RAM_DSPR_CORE0_ASIL_VAR_CLEARED_SECTION
#	undef STOP_SEC_RAM_DSPR_CORE0_ASIL_VAR_CLEARED_SECTION
#	ifdef DSPR_CORE0_ASIL_VAR_CLEARED_SECTION_OPEN
#		undef DSPR_CORE0_ASIL_VAR_CLEARED_SECTION_OPEN
#pragma section farbss restore
#	else
#		error "DSPR_CORE0 ASIL VAR_CLEARED section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * DSPR Memory Map : Core1 QM VAR_CLEARED Section
 * ****************************************************************/
#if ((defined DSPR_CORE1_QM_VAR_CLEARED_SECTION_OPEN) && (defined START_SEC_RAM_DSPR_CORE1_QM_VAR_CLEARED_SECTION))
#	error "Section: DSPR_CORE1_QM_VAR_CLEARED_SECTION_OPEN opened but in addition: START_SEC_RAM_DSPR_CORE1_QM_VAR_CLEARED_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_DSPR_CORE1_QM_VAR_CLEARED_SECTION
#	undef START_SEC_RAM_DSPR_CORE1_QM_VAR_CLEARED_SECTION
#	define DSPR_CORE1_QM_VAR_CLEARED_SECTION_OPEN
#pragma section farbss Grp_RAM_DSPR_Core1_QM_Bss_Section
#endif

#ifdef STOP_SEC_RAM_DSPR_CORE1_QM_VAR_CLEARED_SECTION
#	undef STOP_SEC_RAM_DSPR_CORE1_QM_VAR_CLEARED_SECTION
#	ifdef DSPR_CORE1_QM_VAR_CLEARED_SECTION_OPEN
#		undef DSPR_CORE1_QM_VAR_CLEARED_SECTION_OPEN
#pragma section farbss restore
#	else
#		error "DSPR_CORE1 QM VAR_CLEARED section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * DSPR Memory Map : Core1 ASIL VAR_CLEARED Section
 * ****************************************************************/
#if ((defined DSPR_CORE1_ASIL_VAR_CLEARED_SECTION_OPEN) && (defined START_SEC_RAM_DSPR_CORE1_ASIL_VAR_CLEARED_SECTION))
#	error "Section: DSPR_CORE1_ASIL_VAR_CLEARED_SECTION_OPEN opened but in addition: START_SEC_RAM_DSPR_CORE1_ASIL_VAR_CLEARED_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_DSPR_CORE1_ASIL_VAR_CLEARED_SECTION
#	undef START_SEC_RAM_DSPR_CORE1_ASIL_VAR_CLEARED_SECTION
#	define DSPR_CORE1_ASIL_VAR_CLEARED_SECTION_OPEN
#pragma section farbss Grp_RAM_DSPR_CORE1_ASIL_Bss_Section
#endif

#ifdef STOP_SEC_RAM_DSPR_CORE1_ASIL_VAR_CLEARED_SECTION
#	undef STOP_SEC_RAM_DSPR_CORE1_ASIL_VAR_CLEARED_SECTION
#	ifdef DSPR_CORE1_ASIL_VAR_CLEARED_SECTION_OPEN
#		undef DSPR_Core1_ASIL_VAR_CLEARED_SECTION_OPEN
#pragma section farbss restore
#	else
#		error "DSPR_CORE1 ASIL VAR_CLEARED section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * DSPR Memory Map : Core2 QM VAR_CLEARED Section
 * ****************************************************************/
#if ((defined DSPR_CORE2_QM_VAR_CLEARED_SECTION_OPEN) && (defined START_SEC_RAM_DSPR_CORE2_QM_VAR_CLEARED_SECTION))
#	error "Section: DSPR_CORE2_QM_VAR_CLEARED_SECTION_OPEN opened but in addition: START_SEC_RAM_DSPR_CORE2_QM_VAR_CLEARED_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_DSPR_CORE2_QM_VAR_CLEARED_SECTION
#	undef START_SEC_RAM_DSPR_CORE2_QM_VAR_CLEARED_SECTION
#	define DSPR_CORE2_QM_VAR_CLEARED_SECTION_OPEN
#pragma section farbss Grp_RAM_DSPR_Core2_QM_Bss_Section
#endif

#ifdef STOP_SEC_RAM_DSPR_CORE2_QM_VAR_CLEARED_SECTION
#	undef STOP_SEC_RAM_DSPR_CORE2_QM_VAR_CLEARED_SECTION
#	ifdef DSPR_CORE2_QM_VAR_CLEARED_SECTION_OPEN
#		undef DSPR_CORE2_QM_VAR_CLEARED_SECTION_OPEN
#pragma section farbss restore
#	else
#		error "DSPR_CORE2 QM VAR_CLEARED section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * DSPR Memory Map : Core2 ASIL VAR_CLEARED Section
 * ****************************************************************/
#if ((defined DSPR_CORE2_ASIL_VAR_CLEARED_SECTION_OPEN) && (defined START_SEC_RAM_DSPR_CORE2_ASIL_VAR_CLEARED_SECTION))
#	error "Section: DSPR_CORE2_ASIL_VAR_CLEARED_SECTION_OPEN opened but in addition: START_SEC_RAM_DSPR_CORE2_ASIL_VAR_CLEARED_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_DSPR_CORE2_ASIL_VAR_CLEARED_SECTION
#	undef START_SEC_RAM_DSPR_CORE2_ASIL_VAR_CLEARED_SECTION
#	define DSPR_CORE2_ASIL_VAR_CLEARED_SECTION_OPEN
#pragma section farbss Grp_RAM_DSPR_Core2_ASIL_Bss_Section
#endif

#ifdef STOP_SEC_RAM_DSPR_CORE2_ASIL_VAR_CLEARED_SECTION
#	undef STOP_SEC_RAM_DSPR_CORE2_ASIL_VAR_CLEARED_SECTION
#	ifdef DSPR_CORE2_ASIL_VAR_CLEARED_SECTION_OPEN
#		undef DSPR_CORE2_ASIL_VAR_CLEARED_SECTION_OPEN
#pragma section farbss restore
#	else
#		error "DSPR_CORE2 ASIL VAR_CLEARED section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * DSPR Memory Map : Core3 QM VAR_CLEARED Section
 * ****************************************************************/
#if ((defined DSPR_CORE3_QM_VAR_CLEARED_SECTION_OPEN) && (defined START_SEC_RAM_DSPR_CORE3_QM_VAR_CLEARED_SECTION))
#	error "Section: DSPR_CORE3_QM_VAR_CLEARED_SECTION_OPEN opened but in addition: START_SEC_RAM_DSPR_CORE3_QM_VAR_CLEARED_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_DSPR_CORE3_QM_VAR_CLEARED_SECTION
#	undef START_SEC_RAM_DSPR_CORE3_QM_VAR_CLEARED_SECTION
#	define DSPR_CORE3_QM_VAR_CLEARED_SECTION_OPEN
#pragma section farbss Grp_RAM_DSPR_Core3_QM_Bss_Section
#endif

#ifdef STOP_SEC_RAM_DSPR_CORE3_QM_VAR_CLEARED_SECTION
#	undef STOP_SEC_RAM_DSPR_CORE3_QM_VAR_CLEARED_SECTION
#	ifdef DSPR_CORE3_QM_VAR_CLEARED_SECTION_OPEN
#		undef DSPR_CORE3_QM_VAR_CLEARED_SECTION_OPEN
#pragma section farbss restore
#	else
#		error "DSPR_CORE3 QM VAR_CLEARED section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * DSPR Memory Map : Core3 ASIL VAR_CLEARED Section
 * ****************************************************************/
#if ((defined DSPR_CORE3_ASIL_VAR_CLEARED_SECTION_OPEN) && (defined START_SEC_RAM_DSPR_CORE3_ASIL_VAR_CLEARED_SECTION))
#	error "Section: DSPR_CORE3_ASIL_VAR_CLEARED_SECTION_OPEN opened but in addition: START_SEC_RAM_DSPR_CORE3_ASIL_VAR_CLEARED_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_DSPR_CORE3_ASIL_VAR_CLEARED_SECTION
#	undef START_SEC_RAM_DSPR_CORE3_ASIL_VAR_CLEARED_SECTION
#	define DSPR_CORE3_ASIL_VAR_CLEARED_SECTION_OPEN
#pragma section farbss Grp_RAM_DSPR_Core3_ASIL_Bss_Section
#endif

#ifdef STOP_SEC_RAM_DSPR_CORE3_ASIL_VAR_CLEARED_SECTION
#	undef STOP_SEC_RAM_DSPR_CORE3_ASIL_VAR_CLEARED_SECTION
#	ifdef DSPR_CORE3_ASIL_VAR_CLEARED_SECTION_OPEN
#		undef DSPR_CORE3_ASIL_VAR_CLEARED_SECTION_OPEN
#pragma section farbss restore
#	else
#		error "DSPR_CORE3 ASIL VAR_CLEARED section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * PSPR Memory Map : Core0 QM VAR_CLEARED Section
 * ****************************************************************/
#if ((defined PSPR_CORE0_QM_VAR_CLEARED_SECTION_OPEN) && (defined START_SEC_RAM_PSPR_CORE0_QM_VAR_CLEARED_SECTION))
#	error "Section: PSPR_CORE0_QM_VAR_CLEARED_SECTION_OPEN opened but in addition: START_SEC_RAM_PSPR_CORE0_QM_VAR_CLEARED_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_PSPR_CORE0_QM_VAR_CLEARED_SECTION
#	undef START_SEC_RAM_PSPR_CORE0_QM_VAR_CLEARED_SECTION
#	define PSPR_CORE0_QM_VAR_CLEARED_SECTION_OPEN
#pragma section farbss Grp_RAM_PSPR_Core0_QM_Bss_Section
#endif

#ifdef STOP_SEC_RAM_PSPR_CORE0_QM_VAR_CLEARED_SECTION
#	undef STOP_SEC_RAM_PSPR_CORE0_QM_VAR_CLEARED_SECTION
#	ifdef PSPR_CORE0_QM_VAR_CLEARED_SECTION_OPEN
#		undef PSPR_CORE0_QM_VAR_CLEARED_SECTION_OPEN
#pragma section farbss restore
#	else
#		error "PSPR_CORE0 ASIL VAR_CLEARED section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * PSPR Memory Map : Core0 ASIL VAR_CLEARED Section
 * ****************************************************************/
#if ((defined PSPR_CORE0_ASIL_VAR_CLEARED_SECTION_OPEN) && (defined START_SEC_RAM_PSPR_CORE0_ASIL_VAR_CLEARED_SECTION))
#	error "Section: PSPR_CORE0_ASIL_VAR_CLEARED_SECTION_OPEN opened but in addition: START_SEC_RAM_PSPR_CORE0_ASIL_VAR_CLEARED_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_PSPR_CORE0_ASIL_VAR_CLEARED_SECTION
#	undef START_SEC_RAM_PSPR_CORE0_ASIL_VAR_CLEARED_SECTION
#	define PSPR_CORE0_ASIL_VAR_CLEARED_SECTION_OPEN
#pragma section farbss Grp_RAM_PSPR_Core0_ASIL_Bss_Section
#endif

#ifdef STOP_SEC_RAM_PSPR_CORE0_ASIL_VAR_CLEARED_SECTION
#	undef STOP_SEC_RAM_PSPR_CORE0_ASIL_VAR_CLEARED_SECTION
#	ifdef PSPR_CORE0_ASIL_VAR_CLEARED_SECTION_OPEN
#		undef PSPR_CORE0_ASIL_VAR_CLEARED_SECTION_OPEN
#pragma section farbss restore
#	else
#		error "PSPR_CORE0 ASIL VAR_CLEARED section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * PSPR Memory Map : Core1 QM VAR_CLEARED Section
 * ****************************************************************/
#if ((defined PSPR_CORE1_QM_VAR_CLEARED_SECTION_OPEN) && (defined START_SEC_RAM_PSPR_CORE1_QM_VAR_CLEARED_SECTION))
#	error "Section: PSPR_CORE1_QM_VAR_CLEARED_SECTION_OPEN opened but in addition: START_SEC_RAM_PSPR_CORE1_QM_VAR_CLEARED_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_PSPR_CORE1_QM_VAR_CLEARED_SECTION
#	undef START_SEC_RAM_PSPR_CORE1_QM_VAR_CLEARED_SECTION
#	define PSPR_CORE1_QM_VAR_CLEARED_SECTION_OPEN
#pragma section farbss Grp_RAM_PSPR_Core1_QM_Bss_Section
#endif

#ifdef STOP_SEC_RAM_PSPR_CORE1_QM_VAR_CLEARED_SECTION
#	undef STOP_SEC_RAM_PSPR_CORE1_QM_VAR_CLEARED_SECTION
#	ifdef PSPR_CORE1_QM_VAR_CLEARED_SECTION_OPEN
#		undef PSPR_CORE1_QM_VAR_CLEARED_SECTION_OPEN
#pragma section farbss restore
#	else
#		error "PSPR_CORE1 QM VAR_CLEARED section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * PSPR Memory Map : Core1 ASIL VAR_CLEARED Section
 * ****************************************************************/
#if ((defined PSPR_CORE1_ASIL_VAR_CLEARED_SECTION_OPEN) && (defined START_SEC_RAM_PSPR_CORE1_ASIL_VAR_CLEARED_SECTION))
#	error "Section: PSPR_CORE1_ASIL_VAR_CLEARED_SECTION_OPEN opened but in addition: START_SEC_RAM_PSPR_CORE1_ASIL_VAR_CLEARED_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_PSPR_CORE1_ASIL_VAR_CLEARED_SECTION
#	undef START_SEC_RAM_PSPR_CORE1_ASIL_VAR_CLEARED_SECTION
#	define PSPR_CORE1_ASIL_VAR_CLEARED_SECTION_OPEN
#pragma section farbss Grp_RAM_PSPR_CORE1_ASIL_Bss_Section
#endif

#ifdef STOP_SEC_RAM_PSPR_CORE1_ASIL_VAR_CLEARED_SECTION
#	undef STOP_SEC_RAM_PSPR_CORE1_ASIL_VAR_CLEARED_SECTION
#	ifdef PSPR_CORE1_ASIL_VAR_CLEARED_SECTION_OPEN
#		undef PSPR_Core1_ASIL_VAR_CLEARED_SECTION_OPEN
#pragma section farbss restore
#	else
#		error "PSPR_CORE1 ASIL VAR_CLEARED section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * PSPR Memory Map : Core2 QM VAR_CLEARED Section
 * ****************************************************************/
#if ((defined PSPR_CORE2_QM_VAR_CLEARED_SECTION_OPEN) && (defined START_SEC_RAM_PSPR_CORE2_QM_VAR_CLEARED_SECTION))
#	error "Section: PSPR_CORE2_QM_VAR_CLEARED_SECTION_OPEN opened but in addition: START_SEC_RAM_PSPR_CORE2_QM_VAR_CLEARED_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_PSPR_CORE2_QM_VAR_CLEARED_SECTION
#	undef START_SEC_RAM_PSPR_CORE2_QM_VAR_CLEARED_SECTION
#	define PSPR_CORE2_QM_VAR_CLEARED_SECTION_OPEN
#pragma section farbss Grp_RAM_PSPR_Core2_QM_Bss_Section
#endif

#ifdef STOP_SEC_RAM_PSPR_CORE2_QM_VAR_CLEARED_SECTION
#	undef STOP_SEC_RAM_PSPR_CORE2_QM_VAR_CLEARED_SECTION
#	ifdef PSPR_CORE2_QM_VAR_CLEARED_SECTION_OPEN
#		undef PSPR_CORE2_QM_VAR_CLEARED_SECTION_OPEN
#pragma section farbss restore
#	else
#		error "PSPR_CORE2 QM VAR_CLEARED section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * PSPR Memory Map : Core2 ASIL VAR_CLEARED Section
 * ****************************************************************/
#if ((defined PSPR_CORE2_ASIL_VAR_CLEARED_SECTION_OPEN) && (defined START_SEC_RAM_PSPR_CORE2_ASIL_VAR_CLEARED_SECTION))
#	error "Section: PSPR_CORE2_ASIL_VAR_CLEARED_SECTION_OPEN opened but in addition: START_SEC_RAM_PSPR_CORE2_ASIL_VAR_CLEARED_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_PSPR_CORE2_ASIL_VAR_CLEARED_SECTION
#	undef START_SEC_RAM_PSPR_CORE2_ASIL_VAR_CLEARED_SECTION
#	define PSPR_CORE2_ASIL_VAR_CLEARED_SECTION_OPEN
#pragma section farbss Grp_RAM_PSPR_Core2_ASIL_Bss_Section
#endif

#ifdef STOP_SEC_RAM_PSPR_CORE2_ASIL_VAR_CLEARED_SECTION
#	undef STOP_SEC_RAM_PSPR_CORE2_ASIL_VAR_CLEARED_SECTION
#	ifdef PSPR_CORE2_ASIL_VAR_CLEARED_SECTION_OPEN
#		undef PSPR_CORE2_ASIL_VAR_CLEARED_SECTION_OPEN
#pragma section farbss restore
#	else
#		error "PSPR_CORE2 ASIL VAR_CLEARED section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * PSPR Memory Map : Core3 QM VAR_CLEARED Section
 * ****************************************************************/
#if ((defined PSPR_CORE3_QM_VAR_CLEARED_SECTION_OPEN) && (defined START_SEC_RAM_PSPR_CORE3_QM_VAR_CLEARED_SECTION))
#	error "Section: PSPR_CORE3_QM_VAR_CLEARED_SECTION_OPEN opened but in addition: START_SEC_RAM_PSPR_CORE3_QM_VAR_CLEARED_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_PSPR_CORE3_QM_VAR_CLEARED_SECTION
#	undef START_SEC_RAM_PSPR_CORE3_QM_VAR_CLEARED_SECTION
#	define PSPR_CORE3_QM_VAR_CLEARED_SECTION_OPEN
#pragma section farbss Grp_RAM_PSPR_Core3_QM_Bss_Section
#endif

#ifdef STOP_SEC_RAM_PSPR_CORE3_QM_VAR_CLEARED_SECTION
#	undef STOP_SEC_RAM_PSPR_CORE3_QM_VAR_CLEARED_SECTION
#	ifdef PSPR_CORE3_QM_VAR_CLEARED_SECTION_OPEN
#		undef PSPR_CORE3_QM_VAR_CLEARED_SECTION_OPEN
#pragma section farbss restore
#	else
#		error "PSPR_CORE3 QM VAR_CLEARED section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * PSPR Memory Map : Core3 ASIL VAR_CLEARED Section
 * ****************************************************************/
#if ((defined PSPR_CORE3_ASIL_VAR_CLEARED_SECTION_OPEN) && (defined START_SEC_RAM_PSPR_CORE3_ASIL_VAR_CLEARED_SECTION))
#	error "Section: PSPR_CORE3_ASIL_VAR_CLEARED_SECTION_OPEN opened but in addition: START_SEC_RAM_PSPR_CORE3_ASIL_VAR_CLEARED_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_PSPR_CORE3_ASIL_VAR_CLEARED_SECTION
#	undef START_SEC_RAM_PSPR_CORE3_ASIL_VAR_CLEARED_SECTION
#	define PSPR_CORE3_ASIL_VAR_CLEARED_SECTION_OPEN
#pragma section farbss Grp_RAM_PSPR_Core3_ASIL_Bss_Section
#endif

#ifdef STOP_SEC_RAM_PSPR_CORE3_ASIL_VAR_CLEARED_SECTION
#	undef STOP_SEC_RAM_PSPR_CORE3_ASIL_VAR_CLEARED_SECTION
#	ifdef PSPR_CORE3_ASIL_VAR_CLEARED_SECTION_OPEN
#		undef PSPR_CORE3_ASIL_VAR_CLEARED_SECTION_OPEN
#pragma section farbss restore
#	else
#		error "PSPR_CORE3 ASIL VAR_CLEARED section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * DSPR Memory Map : Core0 QM VAR_INIT Section
 * ****************************************************************/
#if ((defined DSPR_CORE0_QM_VAR_INIT_SECTION_OPEN) && (defined START_SEC_RAM_DSPR_CORE0_QM_VAR_INIT_SECTION))
#	error "Section: DSPR_CORE0_QM_VAR_INIT_SECTION_OPEN opened but in addition: START_SEC_RAM_DSPR_CORE0_QM_VAR_INIT_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_DSPR_CORE0_QM_VAR_INIT_SECTION
#	undef START_SEC_RAM_DSPR_CORE0_QM_VAR_INIT_SECTION
#	define DSPR_CORE0_QM_VAR_INIT_SECTION_OPEN
#pragma section fardata Grp_RAM_DSPR_Core0_QM_Data_Section
#endif

#ifdef STOP_SEC_RAM_DSPR_CORE0_QM_VAR_INIT_SECTION
#	undef STOP_SEC_RAM_DSPR_CORE0_QM_VAR_INIT_SECTION
#	ifdef DSPR_CORE0_QM_VAR_INIT_SECTION_OPEN
#		undef DSPR_CORE0_QM_VAR_INIT_SECTION_OPEN
#pragma section fardata restore
#	else
#		error "DSPR_CORE0 QM VAR_INIT section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * DSPR Memory Map : Core0 ASIL VAR_INIT Section
 * ****************************************************************/
#if ((defined DSPR_CORE0_ASIL_VAR_INIT_SECTION_OPEN) && (defined START_SEC_RAM_DSPR_CORE0_ASIL_VAR_INIT_SECTION))
#	error "Section: DSPR_CORE0_ASIL_VAR_INIT_SECTION_OPEN opened but in addition: START_SEC_RAM_DSPR_CORE0_ASIL_VAR_INIT_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_DSPR_CORE0_ASIL_VAR_INIT_SECTION
#	undef START_SEC_RAM_DSPR_CORE0_ASIL_VAR_INIT_SECTION
#	define DSPR_CORE0_ASIL_VAR_INIT_SECTION_OPEN
#pragma section fardata Grp_RAM_DSPR_Core0_ASIL_Data_Section
#endif

#ifdef STOP_SEC_RAM_DSPR_CORE0_ASIL_VAR_INIT_SECTION
#	undef STOP_SEC_RAM_DSPR_CORE0_ASIL_VAR_INIT_SECTION
#	ifdef DSPR_CORE0_ASIL_VAR_INIT_SECTION_OPEN
#		undef DSPR_CORE0_ASIL_VAR_INIT_SECTION_OPEN
#pragma section fardata restore
#	else
#		error "DSPR_CORE0 ASIL VAR_INIT section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * DSPR Memory Map : Core1 QM VAR_INIT Section
 * ****************************************************************/
#if ((defined DSPR_CORE1_QM_VAR_INIT_SECTION_OPEN) && (defined START_SEC_RAM_DSPR_CORE1_QM_VAR_INIT_SECTION))
#	error "Section: DSPR_CORE1_QM_VAR_INIT_SECTION_OPEN opened but in addition: START_SEC_RAM_DSPR_CORE1_QM_VAR_INIT_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_DSPR_CORE1_QM_VAR_INIT_SECTION
#	undef START_SEC_RAM_DSPR_CORE1_QM_VAR_INIT_SECTION
#	define DSPR_CORE1_QM_VAR_INIT_SECTION_OPEN
#pragma section fardata Grp_RAM_DSPR_Core1_QM_Data_Section
#endif

#ifdef STOP_SEC_RAM_DSPR_CORE1_QM_VAR_INIT_SECTION
#	undef STOP_SEC_RAM_DSPR_CORE1_QM_VAR_INIT_SECTION
#	ifdef DSPR_CORE1_QM_VAR_INIT_SECTION_OPEN
#		undef DSPR_CORE1_QM_VAR_INIT_SECTION_OPEN
#pragma section fardata restore
#	else
#		error "DSPR_CORE1 QM VAR_INIT section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * DSPR Memory Map : Core1 ASIL VAR_INIT Section
 * ****************************************************************/
#if ((defined DSPR_CORE1_ASIL_VAR_INIT_SECTION_OPEN) && (defined START_SEC_RAM_DSPR_CORE1_ASIL_VAR_INIT_SECTION))
#	error "Section: DSPR_CORE1_ASIL_VAR_INIT_SECTION_OPEN opened but in addition: START_SEC_RAM_DSPR_CORE1_ASIL_VAR_INIT_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_DSPR_CORE1_ASIL_VAR_INIT_SECTION
#	undef START_SEC_RAM_DSPR_CORE1_ASIL_VAR_INIT_SECTION
#	define DSPR_CORE1_ASIL_VAR_INIT_SECTION_OPEN
#pragma section fardata Grp_RAM_DSPR_CORE1_ASIL_Data_Section
#endif

#ifdef STOP_SEC_RAM_DSPR_CORE1_ASIL_VAR_INIT_SECTION
#	undef STOP_SEC_RAM_DSPR_CORE1_ASIL_VAR_INIT_SECTION
#	ifdef DSPR_CORE1_ASIL_VAR_INIT_SECTION_OPEN
#		undef DSPR_Core1_ASIL_VAR_INIT_SECTION_OPEN
#pragma section fardata restore
#	else
#		error "DSPR_CORE1 ASIL VAR_INIT section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * DSPR Memory Map : Core2 QM VAR_INIT Section
 * ****************************************************************/
#if ((defined DSPR_CORE2_QM_VAR_INIT_SECTION_OPEN) && (defined START_SEC_RAM_DSPR_CORE2_QM_VAR_INIT_SECTION))
#	error "Section: DSPR_CORE2_QM_VAR_INIT_SECTION_OPEN opened but in addition: START_SEC_RAM_DSPR_CORE2_QM_VAR_INIT_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_DSPR_CORE2_QM_VAR_INIT_SECTION
#	undef START_SEC_RAM_DSPR_CORE2_QM_VAR_INIT_SECTION
#	define DSPR_CORE2_QM_VAR_INIT_SECTION_OPEN
#pragma section fardata Grp_RAM_DSPR_Core2_QM_Data_Section
#endif

#ifdef STOP_SEC_RAM_DSPR_CORE2_QM_VAR_INIT_SECTION
#	undef STOP_SEC_RAM_DSPR_CORE2_QM_VAR_INIT_SECTION
#	ifdef DSPR_CORE2_QM_VAR_INIT_SECTION_OPEN
#		undef DSPR_CORE2_QM_VAR_INIT_SECTION_OPEN
#pragma section fardata restore
#	else
#		error "DSPR_CORE2 QM VAR_INIT section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * DSPR Memory Map : Core2 ASIL VAR_INIT Section
 * ****************************************************************/
#if ((defined DSPR_CORE2_ASIL_VAR_INIT_SECTION_OPEN) && (defined START_SEC_RAM_DSPR_CORE2_ASIL_VAR_INIT_SECTION))
#	error "Section: DSPR_CORE2_ASIL_VAR_INIT_SECTION_OPEN opened but in addition: START_SEC_RAM_DSPR_CORE2_ASIL_VAR_INIT_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_DSPR_CORE2_ASIL_VAR_INIT_SECTION
#	undef START_SEC_RAM_DSPR_CORE2_ASIL_VAR_INIT_SECTION
#	define DSPR_CORE2_ASIL_VAR_INIT_SECTION_OPEN
#pragma section fardata Grp_RAM_DSPR_Core2_ASIL_Data_Section
#endif

#ifdef STOP_SEC_RAM_DSPR_CORE2_ASIL_VAR_INIT_SECTION
#	undef STOP_SEC_RAM_DSPR_CORE2_ASIL_VAR_INIT_SECTION
#	ifdef DSPR_CORE2_ASIL_VAR_INIT_SECTION_OPEN
#		undef DSPR_CORE2_ASIL_VAR_INIT_SECTION_OPEN
#pragma section fardata restore
#	else
#		error "DSPR_CORE2 ASIL VAR_INIT section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * DSPR Memory Map : Core3 QM VAR_INIT Section
 * ****************************************************************/
#if ((defined DSPR_CORE3_QM_VAR_INIT_SECTION_OPEN) && (defined START_SEC_RAM_DSPR_CORE3_QM_VAR_INIT_SECTION))
#	error "Section: DSPR_CORE3_QM_VAR_INIT_SECTION_OPEN opened but in addition: START_SEC_RAM_DSPR_CORE3_QM_VAR_INIT_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_DSPR_CORE3_QM_VAR_INIT_SECTION
#	undef START_SEC_RAM_DSPR_CORE3_QM_VAR_INIT_SECTION
#	define DSPR_CORE3_QM_VAR_INIT_SECTION_OPEN
#pragma section fardata Grp_RAM_DSPR_Core3_QM_Data_Section
#endif

#ifdef STOP_SEC_RAM_DSPR_CORE3_QM_VAR_INIT_SECTION
#	undef STOP_SEC_RAM_DSPR_CORE3_QM_VAR_INIT_SECTION
#	ifdef DSPR_CORE3_QM_VAR_INIT_SECTION_OPEN
#		undef DSPR_CORE3_QM_VAR_INIT_SECTION_OPEN
#pragma section fardata restore
#	else
#		error "DSPR_CORE3 QM VAR_INIT section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * DSPR Memory Map : Core3 ASIL VAR_INIT Section
 * ****************************************************************/
#if ((defined DSPR_CORE3_ASIL_VAR_INIT_SECTION_OPEN) && (defined START_SEC_RAM_DSPR_CORE3_ASIL_VAR_INIT_SECTION))
#	error "Section: DSPR_CORE3_ASIL_VAR_INIT_SECTION_OPEN opened but in addition: START_SEC_RAM_DSPR_CORE3_ASIL_VAR_INIT_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_DSPR_CORE3_ASIL_VAR_INIT_SECTION
#	undef START_SEC_RAM_DSPR_CORE3_ASIL_VAR_INIT_SECTION
#	define DSPR_CORE3_ASIL_VAR_INIT_SECTION_OPEN
#pragma section fardata Grp_RAM_DSPR_Core3_ASIL_Data_Section
#endif

#ifdef STOP_SEC_RAM_DSPR_CORE3_ASIL_VAR_INIT_SECTION
#	undef STOP_SEC_RAM_DSPR_CORE3_ASIL_VAR_INIT_SECTION
#	ifdef DSPR_CORE3_ASIL_VAR_INIT_SECTION_OPEN
#		undef DSPR_CORE3_ASIL_VAR_INIT_SECTION_OPEN
#pragma section fardata restore
#	else
#		error "DSPR_CORE3 ASIL VAR_INIT section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * PSPR Memory Map : Core0 QM VAR_INIT Section
 * ****************************************************************/
#if ((defined PSPR_CORE0_QM_VAR_INIT_SECTION_OPEN) && (defined START_SEC_RAM_PSPR_CORE0_QM_VAR_INIT_SECTION))
#	error "Section: PSPR_CORE0_QM_VAR_INIT_SECTION_OPEN opened but in addition: START_SEC_RAM_PSPR_CORE0_QM_VAR_INIT_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_PSPR_CORE0_QM_VAR_INIT_SECTION
#	undef START_SEC_RAM_PSPR_CORE0_QM_VAR_INIT_SECTION
#	define PSPR_CORE0_QM_VAR_INIT_SECTION_OPEN
#pragma section fardata Grp_RAM_PSPR_Core0_QM_Data_Section
#endif

#ifdef STOP_SEC_RAM_PSPR_CORE0_QM_VAR_INIT_SECTION
#	undef STOP_SEC_RAM_PSPR_CORE0_QM_VAR_INIT_SECTION
#	ifdef PSPR_CORE0_QM_VAR_INIT_SECTION_OPEN
#		undef PSPR_CORE0_QM_VAR_INIT_SECTION_OPEN
#pragma section fardata restore
#	else
#		error "PSPR_CORE0 QM VAR_INIT section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * PSPR Memory Map : Core0 ASIL VAR_INIT Section
 * ****************************************************************/
#if ((defined PSPR_CORE0_ASIL_VAR_INIT_SECTION_OPEN) && (defined START_SEC_RAM_PSPR_CORE0_ASIL_VAR_INIT_SECTION))
#	error "Section: PSPR_CORE0_ASIL_VAR_INIT_SECTION_OPEN opened but in addition: START_SEC_RAM_PSPR_CORE0_ASIL_VAR_INIT_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_PSPR_CORE0_ASIL_VAR_INIT_SECTION
#	undef START_SEC_RAM_PSPR_CORE0_ASIL_VAR_INIT_SECTION
#	define PSPR_CORE0_ASIL_VAR_INIT_SECTION_OPEN
#pragma section fardata Grp_RAM_PSPR_Core0_ASIL_Data_Section
#endif

#ifdef STOP_SEC_RAM_PSPR_CORE0_ASIL_VAR_INIT_SECTION
#	undef STOP_SEC_RAM_PSPR_CORE0_ASIL_VAR_INIT_SECTION
#	ifdef PSPR_CORE0_ASIL_VAR_INIT_SECTION_OPEN
#		undef PSPR_CORE0_ASIL_VAR_INIT_SECTION_OPEN
#pragma section fardata restore
#	else
#		error "PSPR_CORE0 ASIL VAR_INIT section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * PSPR Memory Map : Core1 QM VAR_INIT Section
 * ****************************************************************/
#if ((defined PSPR_CORE1_QM_VAR_INIT_SECTION_OPEN) && (defined START_SEC_RAM_PSPR_CORE1_QM_VAR_INIT_SECTION))
#	error "Section: PSPR_CORE1_QM_VAR_INIT_SECTION_OPEN opened but in addition: START_SEC_RAM_PSPR_CORE1_QM_VAR_INIT_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_PSPR_CORE1_QM_VAR_INIT_SECTION
#	undef START_SEC_RAM_PSPR_CORE1_QM_VAR_INIT_SECTION
#	define PSPR_CORE1_QM_VAR_INIT_SECTION_OPEN
#pragma section fardata Grp_RAM_PSPR_Core1_QM_Data_Section
#endif

#ifdef STOP_SEC_RAM_PSPR_CORE1_QM_VAR_INIT_SECTION
#	undef STOP_SEC_RAM_PSPR_CORE1_QM_VAR_INIT_SECTION
#	ifdef PSPR_CORE1_QM_VAR_INIT_SECTION_OPEN
#		undef PSPR_CORE1_QM_VAR_INIT_SECTION_OPEN
#pragma section fardata restore
#	else
#		error "PSPR_CORE1 QM VAR_INIT section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * PSPR Memory Map : Core1 ASIL VAR_INIT Section
 * ****************************************************************/
#if ((defined PSPR_CORE1_ASIL_VAR_INIT_SECTION_OPEN) && (defined START_SEC_RAM_PSPR_CORE1_ASIL_VAR_INIT_SECTION))
#	error "Section: PSPR_CORE1_ASIL_VAR_INIT_SECTION_OPEN opened but in addition: START_SEC_RAM_PSPR_CORE1_ASIL_VAR_INIT_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_PSPR_CORE1_ASIL_VAR_INIT_SECTION
#	undef START_SEC_RAM_PSPR_CORE1_ASIL_VAR_INIT_SECTION
#	define PSPR_CORE1_ASIL_VAR_INIT_SECTION_OPEN
#pragma section fardata Grp_RAM_PSPR_CORE1_ASIL_Data_Section
#endif

#ifdef STOP_SEC_RAM_PSPR_CORE1_ASIL_VAR_INIT_SECTION
#	undef STOP_SEC_RAM_PSPR_CORE1_ASIL_VAR_INIT_SECTION
#	ifdef PSPR_CORE1_ASIL_VAR_INIT_SECTION_OPEN
#		undef PSPR_Core1_ASIL_VAR_INIT_SECTION_OPEN
#pragma section fardata restore
#	else
#		error "PSPR_CORE1 ASIL VAR_INIT section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * PSPR Memory Map : Core2 QM VAR_INIT Section
 * ****************************************************************/
#if ((defined PSPR_CORE2_QM_VAR_INIT_SECTION_OPEN) && (defined START_SEC_RAM_PSPR_CORE2_QM_VAR_INIT_SECTION))
#	error "Section: PSPR_CORE2_QM_VAR_INIT_SECTION_OPEN opened but in addition: START_SEC_RAM_PSPR_CORE2_QM_VAR_INIT_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_PSPR_CORE2_QM_VAR_INIT_SECTION
#	undef START_SEC_RAM_PSPR_CORE2_QM_VAR_INIT_SECTION
#	define PSPR_CORE2_QM_VAR_INIT_SECTION_OPEN
#pragma section fardata Grp_RAM_PSPR_Core2_QM_Data_Section
#endif

#ifdef STOP_SEC_RAM_PSPR_CORE2_QM_VAR_INIT_SECTION
#	undef STOP_SEC_RAM_PSPR_CORE2_QM_VAR_INIT_SECTION
#	ifdef PSPR_CORE2_QM_VAR_INIT_SECTION_OPEN
#		undef PSPR_CORE2_QM_VAR_INIT_SECTION_OPEN
#pragma section fardata restore
#	else
#		error "PSPR_CORE2 QM VAR_INIT section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * PSPR Memory Map : Core2 ASIL VAR_INIT Section
 * ****************************************************************/
#if ((defined PSPR_CORE2_ASIL_VAR_INIT_SECTION_OPEN) && (defined START_SEC_RAM_PSPR_CORE2_ASIL_VAR_INIT_SECTION))
#	error "Section: PSPR_CORE2_ASIL_VAR_INIT_SECTION_OPEN opened but in addition: START_SEC_RAM_PSPR_CORE2_ASIL_VAR_INIT_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_PSPR_CORE2_ASIL_VAR_INIT_SECTION
#	undef START_SEC_RAM_PSPR_CORE2_ASIL_VAR_INIT_SECTION
#	define PSPR_CORE2_ASIL_VAR_INIT_SECTION_OPEN
#pragma section fardata Grp_RAM_PSPR_Core2_ASIL_Data_Section
#endif

#ifdef STOP_SEC_RAM_PSPR_CORE2_ASIL_VAR_INIT_SECTION
#	undef STOP_SEC_RAM_PSPR_CORE2_ASIL_VAR_INIT_SECTION
#	ifdef PSPR_CORE2_ASIL_VAR_INIT_SECTION_OPEN
#		undef PSPR_CORE2_ASIL_VAR_INIT_SECTION_OPEN
#pragma section fardata restore
#	else
#		error "PSPR_CORE2 ASIL VAR_INIT section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * PSPR Memory Map : Core3 QM VAR_INIT Section
 * ****************************************************************/
#if ((defined PSPR_CORE3_QM_VAR_INIT_SECTION_OPEN) && (defined START_SEC_RAM_PSPR_CORE3_QM_VAR_INIT_SECTION))
#	error "Section: PSPR_CORE3_QM_VAR_INIT_SECTION_OPEN opened but in addition: START_SEC_RAM_PSPR_CORE3_QM_VAR_INIT_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_PSPR_CORE3_QM_VAR_INIT_SECTION
#	undef START_SEC_RAM_PSPR_CORE3_QM_VAR_INIT_SECTION
#	define PSPR_CORE3_QM_VAR_INIT_SECTION_OPEN
#pragma section fardata Grp_RAM_PSPR_Core3_QM_Data_Section
#endif

#ifdef STOP_SEC_RAM_PSPR_CORE3_QM_VAR_INIT_SECTION
#	undef STOP_SEC_RAM_PSPR_CORE3_QM_VAR_INIT_SECTION
#	ifdef PSPR_CORE3_QM_VAR_INIT_SECTION_OPEN
#		undef PSPR_CORE3_QM_VAR_INIT_SECTION_OPEN
#pragma section fardata restore
#	else
#		error "PSPR_CORE3 QM VAR_INIT section request closed but not opened the section.Please opened one section first.."
#	endif
#endif

/******************************************************************
 * PSPR Memory Map : Core3 ASIL VAR_INIT Section
 * ****************************************************************/
#if ((defined PSPR_CORE3_ASIL_VAR_INIT_SECTION_OPEN) && (defined START_SEC_RAM_PSPR_CORE3_ASIL_VAR_INIT_SECTION))
#	error "Section: PSPR_CORE3_ASIL_VAR_INIT_SECTION_OPEN opened but in addition: START_SEC_RAM_PSPR_CORE3_ASIL_VAR_INIT_SECTION is still defined as well. Please remove the obsolete define!"
#endif

#ifdef START_SEC_RAM_PSPR_CORE3_ASIL_VAR_INIT_SECTION
#	undef START_SEC_RAM_PSPR_CORE3_ASIL_VAR_INIT_SECTION
#	define PSPR_CORE3_ASIL_VAR_INIT_SECTION_OPEN
#pragma section fardata Grp_RAM_PSPR_Core3_ASIL_Data_Section
#endif

#ifdef STOP_SEC_RAM_PSPR_CORE3_ASIL_VAR_INIT_SECTION
#	undef STOP_SEC_RAM_PSPR_CORE3_ASIL_VAR_INIT_SECTION
#	ifdef PSPR_CORE3_ASIL_VAR_INIT_SECTION_OPEN
#		undef PSPR_CORE3_ASIL_VAR_INIT_SECTION_OPEN
#pragma section fardata restore
#	else
#		error "PSPR_CORE3 ASIL VAR_INIT section request closed but not opened the section.Please opened one section first.."
#	endif
#endif
