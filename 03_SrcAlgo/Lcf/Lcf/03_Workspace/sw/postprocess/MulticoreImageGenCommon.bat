@echo off
setlocal
echo.
echo --- Start: MulticoreImageGenCommon.bat (%BUILDCONFIG%)
echo.

if "%PROJECT_NAME%" == "" (
	echo Error: This batch file can no longer be used standalone.  Please use the
	echo        command "sw_build.bat postonly" to generate ROM images without building
	exit /b
)

REM Define Device Id Centaurus - 3; Centeve - 8
set Dev_ID=8

REM Define Output file path
rem CONTI_CHANGE: Update the paths to suit our build environment
set Out_Path=.
rem CONTI_CHANGE: Define tool path to out2rprc.exe
set Out2rprc_exe="..\..\..\02_Development_Tools\out2rprc\out2rprc_src\out2rprc\bin\Release\out2rprc.exe"

rem The following flag is used to force the out2rprc.exe to generate corrupted section CRC values for test purpuse. 
rem If this flag is set the resulting output is NOT BOOTABLE. So be carefull.
if %CORRUPTCRC% == 1 (
  set Out2rprc_Argument="corruptCRC"
) else (
  set Out2rprc_Argument=
)

REM Define Input file paths; To skip the core leave it blank
set App_DSP_0=..\..\..\04_Build\out\%APP_PROJECT_NAME%\%BUILDCONFIG%_dsp_0\dsp_0.out
set App_DSP_1=..\..\..\04_Build\out\%APP_PROJECT_NAME%\%BUILDCONFIG%_dsp_1\dsp_1.out
set App_VideoM3=..\..\..\04_Build\out\%APP_PROJECT_NAME%\%BUILDCONFIG%_arm-m_0\arm-m_0.out

rem Mono uses two extra cores not used by the other projects so we must check whether we are
rem building for this project and add them if necessary
if "%SOCTYPE%" == "high" (
  set App_A8=..\..\..\04_Build\out\%APP_PROJECT_NAME%\%BUILDCONFIG%_arm-a_0\arm-a_0.out
  set App_VpssM3=..\..\..\04_Build\out\%APP_PROJECT_NAME%\%BUILDCONFIG%_arm-m_1\arm-m_1.out
  set App_EVE_0=..\..\..\04_Build\out\%APP_PROJECT_NAME%\%BUILDCONFIG%_eve_0\eve_0.out
	set App_EVE_1=..\..\..\04_Build\out\%APP_PROJECT_NAME%\%BUILDCONFIG%_eve_1\eve_1.out
)

set App_A8_RPRC=
set App_DSP_0_RPRC=
set App_DSP_1_RPRC=
set App_VideoM3_RPRC=
set App_VpssM3_RPRC=
set App_EVE_0_RPRC=
set App_EVE_1_RPRC=

rem CONTI_CHANGE: Delete destination images in case something fails
del %Out_Path%\AppImage_BE* 2> nul:

if defined App_A8 (
set Core_A8=0
set image_gen=1
set App_A8_RPRC=%App_A8%.rprc )
if defined App_A8 (
	rem CONTI_CHANGE: Check for existence of the input file and abort processing if it is not there
	rem               This is done individually for each and every input file
	if exist "%App_A8%" (
	%Out2rprc_exe% %App_A8% %App_A8_RPRC% %Out2rprc_Argument%
	) else (
		echo Input file %App_A8% does not exist - aborting image creation
		exit /b
	)
)

if defined App_DSP_0 (
set Core_DSP_0=8
set image_gen=1
set App_DSP_0_RPRC=%App_DSP_0%.rprc )
if defined App_DSP_0 (
	if exist "%App_DSP_0%" (
	%Out2rprc_exe% %App_DSP_0% %App_DSP_0_RPRC% %Out2rprc_Argument%
	) else (
		echo Input file %App_DSP_0% does not exist - aborting image creation
		exit /b
	)
)

if defined App_DSP_1 (
set Core_DSP_1=9
set image_gen=1
set App_DSP_1_RPRC=%App_DSP_1%.rprc )
if defined App_DSP_1 (
	if exist "%App_DSP_1%" (
	%Out2rprc_exe% %App_DSP_1% %App_DSP_1_RPRC% %Out2rprc_Argument%
	) else (
		echo Input file %App_DSP_1% does not exist - aborting image creation
		exit /b
	)
)

if defined App_VideoM3 (
set Core_VideoM3=2
set image_gen=1
set App_VideoM3_RPRC=%App_VideoM3%.rprc )
if defined App_VideoM3 (
	if exist "%App_VideoM3%" (
	%Out2rprc_exe% %App_VideoM3% %App_VideoM3_RPRC% %Out2rprc_Argument%
	) else (
		echo Input file %App_VideoM3% does not exist - aborting image creation
		exit /b
	)
)

if defined App_VpssM3 (
set Core_VpssM3=3
set image_gen=1
set App_VpssM3_RPRC=%App_VpssM3%.rprc )
if defined App_VpssM3 (
	if exist "%App_VpssM3%" (
	%Out2rprc_exe% %App_VpssM3% %App_VpssM3_RPRC% %Out2rprc_Argument%
	) else (
		echo Input file %App_VpssM3% does not exist - aborting image creation
		exit /b
	)
)

if defined App_EVE_0 (
set Core_EVE_0=10
set image_gen=1
set App_EVE_0_RPRC=%App_EVE_0%.rprc )
if defined App_EVE_0 (
	if exist "%App_EVE_0%" (
	%Out2rprc_exe% %App_EVE_0% %App_EVE_0_RPRC% %Out2rprc_Argument%
	) else (
		echo Input file %App_EVE_0% does not exist - aborting image creation
		exit /b
	)
)

if defined App_EVE_1 (
set Core_EVE_1=11
set image_gen=1
set App_EVE_1_RPRC=%App_EVE_1%.rprc )
if defined App_EVE_1 (
	if exist "%App_EVE_1%" (
	%Out2rprc_exe% %App_EVE_1% %App_EVE_1_RPRC% %Out2rprc_Argument%
	) else (
		echo Input file %App_EVE_1% does not exist - aborting image creation
		exit /b
	)
)

if defined image_gen (
rem CONTI_CHANGE: Generate only BE image as this is the only one required.  Generating both only creates confusion!
rem "multicore_image_generator\MulticoreImageGen.exe" LE %Dev_ID% %Out_Path%\AppImage %Core_A8% %App_A8_RPRC% %Core_DSP_0% %App_DSP_0_RPRC% %Core_VideoM3% %App_VideoM3_RPRC% %Core_VpssM3% %App_VpssM3_RPRC% %Core_EVE_0% %App_EVE_0_RPRC%

"..\..\..\02_Development_Tools\multicore_image_generator\MulticoreImageGen.exe" BE %Dev_ID% %Out_Path%\AppImage_BE %Core_A8% %App_A8_RPRC% %Core_DSP_0% %App_DSP_0_RPRC% %Core_DSP_1% %App_DSP_1_RPRC% %Core_VideoM3% %App_VideoM3_RPRC% %Core_VpssM3% %App_VpssM3_RPRC% %Core_EVE_0% %App_EVE_0_RPRC% %Core_EVE_1% %App_EVE_1_RPRC% )
"..\..\..\02_Development_Tools\image_compressor\Release\CreateImage.exe" %Out_Path%\AppImage_BE %Out_Path%\AppImage_BE.mfc

echo.
echo --- Done:  MulticoreImageGenCommon.bat
