#################################################################
# ASM_FILES_TO_BUILD, EXCLUDE_MAKE_DEPEND
# The paths to own user include files. The paths must be preceded
# by no option . If more than one path is used, you will have
# to separate them by spaces.
#
# 02_SrcAppl
# 
ASM_FILES_TO_BUILD   +=  $(PROJECT_BASE)\02_SrcAppl\EbIntegr\boards\TriboardTC387TH_DPM\boardAsm.s
EXCLUDE_MAKE_DEPEND  +=  $(PROJECT_BASE)\02_SrcAppl\EbIntegr\boards\TriboardTC387TH_DPM\boardAsm.s

#################################################################
# CC_FILES_TO_BUILD, :
# The paths to own user include files. The paths must be preceded
# by no option . If more than one path is used, you will have
# to separate them by spaces.
#
# 02_SrcAppl
# 
CC_FILES_TO_BUILD += $(wildcard $(addprefix $(PROJECT_BASE)/02_SrcAppl/,\
	ComH/Cpr/02_Config/*.c\
	ComH/Cpr/8001_CSC_Platform_CPR/01_Implements/*.c\
	ComH/Cps/02_Config/*.c\
	ComH/Cps/8002_CSC_Platform_CPS/01_Implements/*.c\
	ComH/Fcu/Src/*.c\
	DiagServ/Dsm/*.c\
	EbIntegr/boards/TriboardTC387TH_DPM/*.c\
	EbIntegr/EbIntegr/*.c\
	ErrH/Esh/*.c\
	ErrH/Med/02_Config/*.c\
	ErrH/Med/8003_CSC_Platform_MED/01_Implements/*.c\
	ErrH/Sed/02_Config/*.c\
	ErrH/Sed/8005_CSC_Platform_SED/01_Implements/*.c\
	HwAbs/EvAdc/*.c\
	HwMon/HeartbeatDet/*.c\
	MeasServ/Logging/800A_CSC_Platform_Log/01_Implements/*.c\
	MeasServ/Print/*.c\
	MeasServ/RTM/8009_CSC_Platform_Rtm/01_Implements/*.c\
	MeasServ/RTM/02_Config/*.c\
	MeasServ/Mtsi/02_Config/*.c\
	MeasServ/Mtsi/A000_CSC_Platform_Mtsi4Hssl/01_Implements/Mtsi/src/*.c\
	MeasServ/Mtsi/A000_CSC_Platform_Mtsi4Hssl/01_Implements/Mtsi_tc3xx/src/*.c\
	MeasServ/Rta/02_Config/Callouts/*.c\
	MeasServ/Rta/02_Config/Project/iuc/*.c\
	MeasServ/Rta/8006_CSC_Platform_Rta/01_Implements/source/aux_cores/dis/*.c\
	MeasServ/Rta/8006_CSC_Platform_Rta/01_Implements/source/em_freeze/dis/*.c\
	MeasServ/Rta/8006_CSC_Platform_Rta/01_Implements/source/ll_addevent/dis/*.c\
	MeasServ/Rta/8006_CSC_Platform_Rta/01_Implements/source/os/basic/isr_full/*.c\
	MeasServ/Rta/8006_CSC_Platform_Rta/01_Implements/source/os/basic/*.c\
	MeasServ/Rta/8006_CSC_Platform_Rta/01_Implements/source/os/normal_os/en/isr_on/*.c\
	MeasServ/Rta/8006_CSC_Platform_Rta/01_Implements/source/rta_basic/en/stat/*.c\
	MeasServ/Rta/8006_CSC_Platform_Rta/01_Implements/source/rta_basic/en/*.c\
	MeasServ/Rta/8006_CSC_Platform_Rta/01_Implements/source/suspend/dis/*.c\
	MeasServ/Rta/8006_CSC_Platform_Rta/01_Implements/RtaAdapter/*.c\
	MemServ/Cdm/*.c\
	MemServ/AEBDS/*.c\
	MemServ/Qsm/8008_CSC_Platform_Qsm/01_Implements/*.c\
	MemServ/Qsm/Config/*.c\
	SysM/ComCo/*.c\
	SysM/Esm/*.c\
	SysM/Gp_PowerCtrl/*.c\
	SysM/VoltMonI/*.c\
	SysM/SystemData/*.c\
	SysM/ModM/*.c\
	Platform/*.c\
	Platform/CSC_Platform/02_Config/*.c\
	Platform/CSC_Platform/8000_CSC_Platform_Common/01_Implements/01_Common/*.c\
	Platform/CSC_Platform/8000_CSC_Platform_Common/01_Implements/02_DataConvert/*.c\
	Platform/CSC_Platform/8000_CSC_Platform_Common/01_Implements/04_Dbg/*.c\
	Platform/CSC_Platform/8000_CSC_Platform_Common/01_Implements/05_MemMap/*.c\
	Platform/VerInfo/*.c \
	PmicServ/FS8x_driver/*.c \
	PmicServ/PF8X_driver/*.c\
	PmicServ/PF5xdriver/*.c\
	PmicServ/*.c\
	SecurityServ/Ucb/*.c\
	SecurityServ/Ucb/mbedtls/*.c\
	SpiServ/Sdc/src/*.c\
	SpiServ/SpiTp/*.c\
    SpiServ/*.c\
	Stubs/*.c\
	TimeServ/SpiSync/02_Config/*.c\
	TimeServ/SpiSync/8004_CSC_Platform_SpiSync/01_Implements/*.c\
	TimeServ/Time/02_Config/*.c\
	TimeServ/Time/8007_CSC_Platform_Time/01_Implements/*.c\
	FSMonitor/*.c\
	FSMonitor/esm/*.c\
	FSMonitor/exec/*.c\
	FSMonitor/utils/*.c\
	FSMonitor/exec/state_machine/*.c\
	FSMonitor/ism/*.c))



#################################################################
# CC_FILES_TO_BUILD, :
# The paths to own user include files. The paths must be preceded
# by no option . If more than one path is used, you will have
# to separate them by spaces.
#
# 03_SrcAlgo
# 
CC_FILES_TO_BUILD += $(wildcard $(addprefix $(PROJECT_BASE)/03_SrcAlgo/,\
	Common/cml/*.c \
	Common/Common/*.c \
	Fct/FctAdapter/*.c \
	Fct/Fct/00_Custom/*.c \
	Fct/Fct/algo_common/*.c \
	Fct/Fct/fct/*.c \
	Fct/Fct/LODMC/*.c \
	Fct/Fct/00_Custom/fct/*.c \
	Fct/Fct/00_Custom/LODMC/*.c \
	Fct/Fct/00_Custom/fct/ACDC/*.c \
	Fct/Fct/00_Custom/fct/FCT/*.c \
	Fct/Fct/00_Custom/fct/ISC/*.c \
	Fct/Fct/00_Custom/fct/LOCC/*.c \
	Fct/Fct/00_Custom/fct/LOHP/*.c \
	Fct/Fct/00_Custom/fct/LOPC/*.c \
	Fct/Fct/00_Custom/fct/MEDIC/*.c \
	Fct/Fct/00_Custom/fct/SLATE/*.c \
	Fct/Fct/00_Custom/fct/SLATE1/*.c \
	Fct/Fct/00_Custom/fct/SLATE2/*.c \
	Fct/Fct/00_Custom/fct/SPM/*.c \
	Fct/Fct/00_Custom/fct/ACDC/aip/*.c \
	Fct/Fct/00_Custom/fct/ACDC/cd/*.c \
	Fct/Fct/00_Custom/fct/ACDC/emp/*.c \
	Fct/Fct/00_Custom/fct/ACDC/espm/*.c \
	Fct/Fct/00_Custom/fct/ACDC/frame_acdc/*.c \
	Fct/Fct/00_Custom/fct/FCT/frame/*.c \
	Fct/Fct/00_Custom/fct/FCT/frame_sen/*.c \
	Fct/Fct/00_Custom/fct/FCT/frame_veh/*.c \
	Fct/Fct/00_Custom/fct/ISC/frame_isc/*.c \
	Fct/Fct/00_Custom/fct/ISC/isc/*.c \
	Fct/Fct/00_Custom/fct/ISC/isc/hmi/*.c \
	Fct/Fct/00_Custom/fct/ISC/isc/sm/*.c \
	Fct/Fct/00_Custom/fct/LOCC/frame_locc/*.c \
	Fct/Fct/00_Custom/fct/LOCC/locc/*.c \
	Fct/Fct/00_Custom/fct/LOCC/locc/cc/*.c \
	Fct/Fct/00_Custom/fct/LOHP/frame_lohp/*.c \
	Fct/Fct/00_Custom/fct/LOHP/lohp/*.c \
	Fct/Fct/00_Custom/fct/LOHP/lohp/dm/*.c \
	Fct/Fct/00_Custom/fct/LOHP/lohp/fca/*.c \
	Fct/Fct/00_Custom/fct/LOHP/lohp/hp/*.c \
	Fct/Fct/00_Custom/fct/LOHP/lohp/pred/*.c \
	Fct/Fct/00_Custom/fct/LOHP/lohp/tc/*.c \
	Fct/Fct/00_Custom/fct/LOPC/frame_lopc/*.c \
	Fct/Fct/00_Custom/fct/LOPC/lopc/*.c \
	Fct/Fct/00_Custom/fct/LOPC/lopc/kmc/*.c \
	Fct/Fct/00_Custom/fct/LOPC/lopc/loc/*.c \
	Fct/Fct/00_Custom/fct/LOPC/lopc/lop/*.c \
	Fct/Fct/00_Custom/fct/LOPC/lopc/tci/*.c \
	Fct/Fct/00_Custom/fct/MEDIC/dim/*.c \
	Fct/Fct/00_Custom/fct/MEDIC/dim20/*.c \
	Fct/Fct/00_Custom/fct/MEDIC/frame_medic/*.c \
	Fct/Fct/00_Custom/fct/MEDIC/head/*.c \
	Fct/Fct/00_Custom/fct/MEDIC/head20/*.c \
	Fct/Fct/00_Custom/fct/MEDIC/dim/dim_eba/*.c \
	Fct/Fct/00_Custom/fct/SLATE/frame_slate/*.c \
	Fct/Fct/00_Custom/fct/SLATE1/cp/*.c \
	Fct/Fct/00_Custom/fct/SLATE1/la/*.c \
	Fct/Fct/00_Custom/fct/SLATE1/ooi/*.c \
	Fct/Fct/00_Custom/fct/SLATE1/out/*.c \
	Fct/Fct/00_Custom/fct/SLATE1/sit/*.c \
	Fct/Fct/00_Custom/fct/SLATE2/apm/*.c \
	Fct/Fct/00_Custom/fct/SLATE2/fip/*.c \
	Fct/Fct/00_Custom/LODMC/interface/*.c \
	Fct/Fct/fct/ACDC/*.c \
	Fct/Fct/fct/CAL/*.c \
	Fct/Fct/fct/FCT/*.c \
	Fct/Fct/fct/ISC/*.c \
	Fct/Fct/fct/LOCC/*.c \
	Fct/Fct/fct/LOHP/*.c \
	Fct/Fct/fct/LOPC/*.c \
	Fct/Fct/fct/MEDIC/*.c \
	Fct/Fct/fct/SLATE/*.c \
	Fct/Fct/fct/SLATE1/*.c \
	Fct/Fct/fct/SLATE2/*.c \
	Fct/Fct/fct/SPM/*.c \
	Fct/Fct/fct/ACDC/aip/*.c \
	Fct/Fct/fct/ACDC/cd/*.c \
	Fct/Fct/fct/ACDC/emp/*.c \
	Fct/Fct/fct/ACDC/espm/*.c \
	Fct/Fct/fct/ACDC/frame_acdc/*.c \
	Fct/Fct/fct/ACDC/sfl/*.c \
	Fct/Fct/fct/FCT/frame/*.c \
	Fct/Fct/fct/FCT/frame_sen/*.c \
	Fct/Fct/fct/FCT/frame_veh/*.c \
	Fct/Fct/fct/ISC/frame_isc/*.c \
	Fct/Fct/fct/ISC/isc/*.c \
	Fct/Fct/fct/ISC/isc/hmi/*.c \
	Fct/Fct/fct/ISC/isc/sm/*.c \
	Fct/Fct/fct/LOCC/frame_locc/*.c \
	Fct/Fct/fct/LOCC/locc/*.c \
	Fct/Fct/fct/LOCC/locc/cc/*.c \
	Fct/Fct/fct/LOHP/frame_lohp/*.c \
	Fct/Fct/fct/LOHP/lohp/*.c \
	Fct/Fct/fct/LOHP/lohp/dm/*.c \
	Fct/Fct/fct/LOHP/lohp/fca/*.c \
	Fct/Fct/fct/LOHP/lohp/hp/*.c \
	Fct/Fct/fct/LOHP/lohp/pred/*.c \
	Fct/Fct/fct/LOHP/lohp/tc/*.c \
	Fct/Fct/fct/LOPC/frame_lopc/*.c \
	Fct/Fct/fct/LOPC/lopc/*.c \
	Fct/Fct/fct/LOPC/lopc/kmc/*.c \
	Fct/Fct/fct/LOPC/lopc/loc/*.c \
	Fct/Fct/fct/LOPC/lopc/lop/*.c \
	Fct/Fct/fct/LOPC/lopc/tci/*.c \
	Fct/Fct/fct/MEDIC/dim/*.c \
	Fct/Fct/fct/MEDIC/dim20/*.c \
	Fct/Fct/fct/MEDIC/frame_medic/*.c \
	Fct/Fct/fct/MEDIC/head/*.c \
	Fct/Fct/fct/MEDIC/head20/*.c \
	Fct/Fct/fct/MEDIC/targetplanner/*.c \
	Fct/Fct/fct/SLATE/frame_slate/*.c \
	Fct/Fct/fct/SLATE1/cp/*.c \
	Fct/Fct/fct/SLATE1/la/*.c \
	Fct/Fct/fct/SLATE1/ooi/*.c \
	Fct/Fct/fct/SLATE1/out/*.c \
	Fct/Fct/fct/SLATE1/sit/*.c \
	Fct/Fct/fct/SLATE2/apm/*.c \
	Fct/Fct/fct/SLATE2/fip/*.c \
	Fct/Fct/fct/SPM/blockage/*.c \
	Fct/Fct/fct/SPM/frame/*.c \
	Fct/Fct/fct/SPM/interference/*.c \
	Fct/Fct/fct/SPM/srr_frame/*.c \
	Fct/Fct/LODMC/lodmc/*.c \
	Fct/Fct/LODMC/lodmc/header/*.c \
	Fct/Fct/LODMC/lodmc/source/*.c \
	Hla/HlaAdapter/*.c \
	Hla/Hla/04_Engineering/00_Projects/MFC5J3/HLA/*.c \
	Hla/Hla/04_Engineering/00_Projects/MFC5J3/HLA/parameters/*.c \
	Hla/Hla/04_Engineering/00_Projects/MFC5J3/HLA/sw_support/*.c \
	Hla/Hla/04_Engineering/01_Source_Code/HLA/*.c \
	Hla/Hla/04_Engineering/01_Source_Code/HLA/frame/*.c \
	Hla/Hla/04_Engineering/01_Source_Code/HLA/function/*.c \
	Lcf/LcfAdapter/*.c \
	Lcf/Lcf/00_Projects/MFC5J3CN15/*.c \
	Lcf/Lcf/00_Projects/MFC5J3CN15/LCF/*.c \
	Lcf/Lcf/00_Projects/MFC5J3CN15/LCF/MFJSCT/*.c \
	Lcf/Lcf/00_Projects/MFC5J3CN15/LCF/HMIOC/*.c \
	Lcf/Lcf/00_Projects/MFC5J3CN15/LCF/LCF_DPU/*.c \
	Lcf/Lcf/00_Projects/MFC5J3CN15/LCF/MFJSCT/JCNCTR/*.c \
	Lcf/Lcf/00_Projects/MFC5J3CN15/LCF/HMIOC/HMODFL/*.c \
	Lcf/Lcf/00_Projects/MFC5J3CN15/LCF/LCF_DPU/LCFERR/*.c \
	Lcf/Lcf/00_Projects/MFC5J3CN15/LCF/LCF_DPU/LCFPRM/*.c \
	Lcf/Lcf/00_Projects/MFC5J3CN15/LCF/LCF_DPU/LCFRCV/*.c \
	Lcf/Lcf/00_Projects/MFC5J3CN15/LCF/LCF_DPU/LCFSEN/*.c \
	Lcf/Lcf/00_Projects/MFC5J3CN15/LCF/LCF_DPU/LCFSND/*.c \
	Lcf/Lcf/00_Projects/MFC5J3CN15/LCF/LCF_DPU/LCFVEH/*.c \
	Lcf/Lcf/01_Source_Code/common/*.c \
	Lcf/Lcf/01_Source_Code/LCF/*.c \
	Lcf/Lcf/01_Source_Code/common/LCF/*.c \
	Lcf/Lcf/01_Source_Code/common/LCF/RTW/*.c \
	Lcf/Lcf/01_Source_Code/LCF/ABPR/*.c \
	Lcf/Lcf/01_Source_Code/LCF/ALCASA/*.c \
	Lcf/Lcf/01_Source_Code/LCF/Common/*.c \
	Lcf/Lcf/01_Source_Code/LCF/CTRSC/*.c \
	Lcf/Lcf/01_Source_Code/LCF/DRVMN/*.c \
	Lcf/Lcf/01_Source_Code/LCF/LATDMC/*.c \
	Lcf/Lcf/01_Source_Code/LCF/LCFERR/*.c \
	Lcf/Lcf/01_Source_Code/LCF/LCF_MFC431x/*.c \
	Lcf/Lcf/01_Source_Code/LCF/LDPSA/*.c \
	Lcf/Lcf/01_Source_Code/LCF/MDCTR/*.c \
	Lcf/Lcf/01_Source_Code/LCF/ODPR/*.c \
	Lcf/Lcf/01_Source_Code/LCF/RDPSA/*.c \
	Lcf/Lcf/01_Source_Code/LCF/TJASA/*.c \
	Lcf/Lcf/01_Source_Code/LCF/TRJCTR/*.c \
	Lcf/Lcf/01_Source_Code/LCF/TRJPLN/*.c \
	Lcf/Lcf/01_Source_Code/LCF/VDPR/*.c \
	Lcf/Lcf/01_Source_Code/LCF/ABPR/ABPLBP/*.c \
	Lcf/Lcf/01_Source_Code/LCF/ABPR/ABPREP/*.c \
	Lcf/Lcf/01_Source_Code/LCF/ALCASA/LCRSIA/*.c \
	Lcf/Lcf/01_Source_Code/LCF/ALCASA/LCRSMI/*.c \
	Lcf/Lcf/01_Source_Code/LCF/ALCASA/LCRTTG/*.c \
	Lcf/Lcf/01_Source_Code/LCF/ALCASA/LCRTVG/*.c \
	Lcf/Lcf/01_Source_Code/LCF/Common/SDA/*.c \
	Lcf/Lcf/01_Source_Code/LCF/Common/sw_support/*.c \
	Lcf/Lcf/01_Source_Code/LCF/Common/utils/*.c \
	Lcf/Lcf/01_Source_Code/LCF/CTRSC/CSCLTA/*.c \
	Lcf/Lcf/01_Source_Code/LCF/DRVMN/DRMDAE/*.c \
	Lcf/Lcf/01_Source_Code/LCF/DRVMN/DRMHOD/*.c \
	Lcf/Lcf/01_Source_Code/LCF/LATDMC/latdmc_veh_ang/*.c \
	Lcf/Lcf/01_Source_Code/LCF/LCF_MFC431x/DPU/*.c \
	Lcf/Lcf/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_SEN/*.c \
	Lcf/Lcf/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_VEH/*.c \
	Lcf/Lcf/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFRCV/*.c \
	Lcf/Lcf/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFSND/*.c \
	Lcf/Lcf/01_Source_Code/LCF/LDPSA/DPLSIA/*.c \
	Lcf/Lcf/01_Source_Code/LCF/LDPSA/DPLSMI/*.c \
	Lcf/Lcf/01_Source_Code/LCF/LDPSA/DPLSMW/*.c \
	Lcf/Lcf/01_Source_Code/LCF/LDPSA/DPLTTG/*.c \
	Lcf/Lcf/01_Source_Code/LCF/LDPSA/DPLTVG/*.c \
	Lcf/Lcf/01_Source_Code/LCF/MDCTR/MCTLFC/*.c \
	Lcf/Lcf/01_Source_Code/LCF/ODPR/ODPFOH/*.c \
	Lcf/Lcf/01_Source_Code/LCF/ODPR/ODPFOP/*.c \
	Lcf/Lcf/01_Source_Code/LCF/RDPSA/DPRSIA/*.c \
	Lcf/Lcf/01_Source_Code/LCF/RDPSA/DPRSMI/*.c \
	Lcf/Lcf/01_Source_Code/LCF/RDPSA/DPRSMW/*.c \
	Lcf/Lcf/01_Source_Code/LCF/RDPSA/DPRTTG/*.c \
	Lcf/Lcf/01_Source_Code/LCF/RDPSA/DPRTVG/*.c \
	Lcf/Lcf/01_Source_Code/LCF/TJASA/TJACMB/*.c \
	Lcf/Lcf/01_Source_Code/LCF/TJASA/TJAGEN/*.c \
	Lcf/Lcf/01_Source_Code/LCF/TJASA/TJALKA/*.c \
	Lcf/Lcf/01_Source_Code/LCF/TJASA/TJAOBF/*.c \
	Lcf/Lcf/01_Source_Code/LCF/TJASA/TJASTM/*.c \
	Lcf/Lcf/01_Source_Code/LCF/TJASA/TJATTG/*.c \
	Lcf/Lcf/01_Source_Code/LCF/TJASA/TJATVG/*.c \
	Lcf/Lcf/01_Source_Code/LCF/TRJCTR/TCTCDC/*.c \
	Lcf/Lcf/01_Source_Code/LCF/TRJCTR/TCTCLM/*.c \
	Lcf/Lcf/01_Source_Code/LCF/TRJCTR/TCTDTE/*.c \
	Lcf/Lcf/01_Source_Code/LCF/TRJCTR/TCTEST/*.c \
	Lcf/Lcf/01_Source_Code/LCF/TRJCTR/TCTFFC/*.c \
	Lcf/Lcf/01_Source_Code/LCF/TRJCTR/TCTLGC/*.c \
	Lcf/Lcf/01_Source_Code/LCF/TRJPLN/TPLCEN/*.c \
	Lcf/Lcf/01_Source_Code/LCF/TRJPLN/TPLFBT/*.c \
	Lcf/Lcf/01_Source_Code/LCF/TRJPLN/TPLFRT/*.c \
	Lcf/Lcf/01_Source_Code/LCF/TRJPLN/TPLLCO/*.c \
	Lcf/Lcf/01_Source_Code/LCF/TRJPLN/TPLTJC/*.c \
	Lcf/Lcf/01_Source_Code/LCF/VDPR/VDPDRV/*.c \
	Tsa/TsaAdapter/*.c \
	Vdy/VdyAdapter/*.c \
	Vdy/Vdy/00_Projects/MFC431BD10/VDY/custom/*.c \
	Vdy/Vdy/00_Projects/MFC431BD10/VDY/vdy/*.c \
	Vdy/Vdy/00_Projects/MFC431BD10/VDY/custom/sw_support/*.c \
	Vdy/Vdy/00_Projects/MFC431BD10/VDY/custom/vdy/*.c \
	Vdy/Vdy/00_Projects/MFC431BD10/VDY/custom/sw_support/vdy/*.c \
	Vdy/Vdy/01_Source_Code/VDY/rtw/*.c \
	Vdy/Vdy/01_Source_Code/VDY/vdy/*.c))
