@echo off
:: Make sure changes to environment variables are only local do not affect the calling command line
setlocal EnableDelayedExpansion

echo.
echo ===== Start build sysbios =====
echo.

:: Set paths

set OutPath=%PROJ_PATH%/%TD5_PROC_OUTPUT_PATH%
set TI_BIOS=%TI_BIOS_PATH%/packages;


IF "%1"=="" GOTO End
SET core=%1

IF "%2"=="hil" (
  SET build_for_hil=%2
  IF "%3"=="" GOTO End
  SET ConfigFilePath=%3
  IF "%4"=="" GOTO End
  SET PlatformFolderPath=%4
  SET TI_NDK=%TI_NDK_PATH%/packages
  SET TI_NSP=%TI_NSP_PATH%/packages
  SET TI_EDMA3_LLD=%TI_EDMA3_LLD_PATH%/packages
) ELSE (
  SET build_for_hil=
  SET ConfigFilePath=%PROJ_PATH%/04_Engineering/01_Source_Code/DPUSERVICE_TI_TDA123/osc
)

:: Copy config files      
if not exist "%OutPath%" (
  mkdir "%OutPath%"
)

if "%core%"=="dsp_0" (
    if "%build_for_hil%"=="hil" (
      SET SourcePath=%PlatformFolderPath%;%TI_BIOS%;%TI_EDMA3_LLD%
      SET platform=vh28_evm_hil_c66xx
    ) else (
      SET SourcePath=%PROJ_PATH%/04_Engineering/03_Workspace/sw/rtsc_platforms/Conti/MFC400;%TI_BIOS%
      SET platform=Vayu_DSP
    )
    SET target=ti.targets.elf.C66
    SET compileOptions=--compileOptions" -g --optimize_with_debug"
    SET compiler=%TI_C6000_PATH%
)
if "%core%"=="dsp_1" (
    if "%build_for_hil%"=="hil" (
      SET SourcePath=%PlatformFolderPath%;%TI_BIOS%;%TI_EDMA3_LLD%
      SET platform=vh28_evm_hil_c66xx
    ) else (
      SET SourcePath=%PROJ_PATH%/04_Engineering/03_Workspace/sw/rtsc_platforms/Conti/MFC400;%TI_BIOS%
      SET platform=Vayu_DSP1
    )
    SET target=ti.targets.elf.C66
    SET compileOptions=--compileOptions" -g --optimize_with_debug"
    SET compiler=%TI_C6000_PATH%
)
if "%core%"=="arm-a_0" (
    if "%build_for_hil%"=="hil" (
      SET SourcePath=%PlatformFolderPath%;%TI_BIOS%;%TI_EDMA3_LLD%
      SET platform=vh28_evm_hil_ca15
    ) else (
      SET SourcePath=%PROJ_PATH%/04_Engineering/03_Workspace/sw/rtsc_platforms;%TI_BIOS%
      SET platform=Conti.MFC400.Vayu_CA15_0
    )
    SET target=gnu.targets.arm.A15F
    SET compileOptions=
    SET compiler=%GCC_ARM_PATH%
)
if "%core%"=="arm-m_0" (
    if "%build_for_hil%"=="hil" (
      SET SourcePath=%PlatformFolderPath%;%TI_BIOS%;%TI_NDK%;%TI_NSP%
      SET platform=vh28_evm_hil_cm4
    ) else (
      SET SourcePath=%PROJ_PATH%/04_Engineering/03_Workspace/sw/rtsc_platforms;%TI_BIOS%
      SET platform=Conti.MFC400.M3VIDEO
    )
    SET target=ti.targets.arm.elf.M4
    SET compileOptions=--compileOptions" -g --optimize_with_debug"
    SET compiler=%TI_ARM_PATH%
)
if "%core%"=="arm-m_1" (
    SET SourcePath=%PROJ_PATH%/04_Engineering/03_Workspace/sw/rtsc_platforms;%TI_BIOS%
    SET target=ti.targets.arm.elf.M4
    SET platform=Conti.MFC400.M3VPSS
    SET compileOptions=--compileOptions" -g --optimize_with_debug"
    SET compiler=%TI_ARM_PATH%
)


copy "%ConfigFilePath%\app_%core%.cfg" "%OutPath%" /Y   
if "%build_for_hil%"=="" (
  copy "%ConfigFilePath%\linker_%core%.xdt" "%OutPath%" /Y
)

:: Execute XDC tool
echo.

%TI_XDC_PATH%xs.exe ^
 --xdcpath="%SourcePath%" ^
 xdc.tools.configuro ^
 -o"%OutPath%/configPkg" ^
 -D=product=hfl110 ^
 -D=chipset=high ^
 -t %target% ^
 -p %platform% ^
 -r debug ^
 -c %compiler% ^
 %compileOptions% ^
 "%OutPath%/app_%core%.cfg"

if %ERRORLEVEL% neq 0 (
  echo.
  echo ===== Sysbios build failed =====
  exit 1
  )

:End
echo.
echo ===== End build sysbios =====
echo.