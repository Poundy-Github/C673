@echo off
:: This script checks out the needed SIL files for a DPU checkpoint
:: Using the script asumes that you know what you are doing. 

:: (C) 2014 - ADC Lindau GERMANY
:: Author: Magnus Baur
:: Version: 1.0  Script generation							15.02.2018    Magnus Baur


:: Make sure changes to environment variables are only local do not affect the calling command line
setlocal EnableDelayedExpansion
set project=

:: Store current working directory, so we can CD back in case of an error
set INITIAL_WD=%CD%

:: Change working directory to the directory where this script is stored. This allows invoking
:: this script from any directory without CD'ing into the batch file's home directory
cd %~dp0
set CURRENT_WD=%CD%

:: Read input option
:optionsloop
if "%1" == "" (
  echo.
  echo Error: Please specify the product ID with a parameter to the "p" argument
  echo        ie. lockFilesForCP.bat p mfc431
  exit /b
)

if "%1" == "p" (
  if "%2%"=="" (
    echo.
    echo Error: Please specify the product ID with a parameter to the "p" argument
    echo        ie. lockFilesForCP.bat p mfc431
    exit /b
  ) else (
    set project=%2
  )
)

:: Shift next command option and do the loop again until all options are processed
shift
if "%1" == "" goto optionsend
goto optionsloop
:optionsend

:: Check for valid project names and make them capital
if "%project%" == "mfc431" (
    set project=MFC431
) else if "%project%" == "mfc431ta19" (
    set project=MFC431TA19
) else if "%project%" == "mfc431sc19" (
    set project=MFC431SC19
) else (
    echo.
    echo Error: No valid product.
    exit /b
)

:: CP IDs to be used
echo.
si viewcps
echo.
echo Enter the Change Package ID to be used [%changePID%]: 
set /p changePID=

if "%changePID%" == "" (
    echo.
    echo Error: Please select the CP ID to be used
    exit /b
  )

cd %CURRENT_WD%
cd ..\..\..\..\..\MTS\05_Testing\MTS\mts_measurement\dll\00_Projects\%project%

echo ###### Lock MTS dlls for %PROJECT% ######
:: Checkout all SIL output Files
cd VODCA_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_vodca.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_vodca.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_vodcavis.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_vodcavis.pdb
cd ../FCT_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_fct_sen.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_fct_sen.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_fct_veh.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_fct_veh.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_fct_vis.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_fct_vis.pdb
cd ../VDY_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_adapter_vdy.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_adapter_vdy.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_vdy.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_vdy.pdb
cd ../UDW_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_udw.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_udw.pdb
cd ../SR_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_sr_rte_vis.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_sr_a_rte.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_sr_b_rte.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_sr_b_rte.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_sr_rte_vis.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_sr_a_rte.dll
cd ../TLR_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_tlr.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_tlr.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_tlr_vis.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_tlr_vis.pdb
cd ../TSA_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_tsa.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_tsa.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_tsa_vis.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_tsa_vis.pdb
cd ../PC_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_pc.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_pc_vis.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_pc_vis.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_pc.dll
cd ../PFC_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_pfc.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_pfc.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_pfc_vis.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_pfc_vis.pdb
cd ../RUM_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_rum.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_rum.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_rumvis.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_rumvis.pdb
cd ../MEMO_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_emodrawmeas.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_emodrawmeas.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_memo.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_memo.pdb
cd ../LD_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_ld_vis2.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_ld_vis2.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_ld.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_ld.pdb
cd ../LSD_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_lsd.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_lsd.pdb
cd ../MAP_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_map.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_map.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_map_vis.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_map_vis.pdb
cd ../GS_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_gs.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_ctrl.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_ctrl.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_gs.dll
cd ../HLA_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_hla.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_hla.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_hla_vis.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_hla_vis.pdb
cd ../LCF_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_lcf_sen.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_lcf_sen.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_lcf_veh.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_lcf_veh.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_lcf_vis.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_lcf_vis.pdb
cd ../GIA_sim
si lock --changePackageId=%changePID% --lockType=exclusive adapter.dll
si lock --changePackageId=%changePID% --lockType=exclusive adapter.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_fct_cpar.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_fct_cpar.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_mfc_wrapper.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_mfc_wrapper.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_sil_input_adapter.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_sil_input_adapter.pdb
cd ../FAMO_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_famo_vis.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_famo_vis.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_famo.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_famo.pdb
cd ../CIPP_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_cipp.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_cipp.pdb
cd ../ECM_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_ecm.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_ecm.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_ecm_vis.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_ecm_vis.pdb
cd ../EM_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_em.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_em.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_em_vis.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_em_vis.pdb
cd ../ACAL_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_acal.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_acal.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_acal_vis.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_acal_vis.pdb
cd ../CB_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_cb.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_cb.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_cb_vis.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_cb_vis.pdb
cd ../CCT_sim
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_cut_roi.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_cut_roi.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_vis_image.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_vis_image.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_vis_perspectives.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_vis_perspectives.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_vis_rt_range.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_vis_rt_range.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_vis_velodyne.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_swc_vis_velodyne.pdb
si lock --changePackageId=%changePID% --lockType=exclusive sim_hil_client.dll
si lock --changePackageId=%changePID% --lockType=exclusive sim_hil_client.pdb

cd %CURRENT_WD%

call ..\..\Component_Workspace\Compile_SIL.bat p %project%

cd %INITIAL_WD%


ENDLOCAL & SET changePID=%changePID%