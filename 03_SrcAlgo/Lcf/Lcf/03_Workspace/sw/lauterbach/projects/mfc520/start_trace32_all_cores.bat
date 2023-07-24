@echo off

setlocal
cd /d %~dp0

if not exist C:\Tools\T32\T32_R_2017_09_000092037 (
	echo.
	echo ************************************************************************************
	echo ERROR: You do not have Lauterbach Trace32 version T32_R_2017_09_000092037 installed!
	echo ************************************************************************************
	echo.
	echo Please grab it from
	echo.
	echo    L:\T32\T32_R_2017_09_000092037_3570334753.7Z
	echo.
	echo and unzip to
	echo. 
	echo    C:\Tools\T32\
    echo.
    echo It creates a subfolder T32_R_2017_09_000092037.
    echo.
	echo Copy also all *.men and *.per files from L:\T32\T32_INTERIM_BUILDS\R-CAR_V3M\ to that folder.
	echo.
	pause
	exit
)

echo Starting Trace32 for Cortex R7 core
start c:\Tools\T32\T32_R_2017_09_000092037\bin\windows64\t32marm.exe -c LauterbachConfig_r7.t32, init.cmm cr7 1
echo Waiting 6 seconds ...
ping -n 7 127.0.0.1 > nul
echo Starting Trace32 for Cortex A53 cores
start c:\Tools\T32\T32_R_2017_09_000092037\bin\windows64\t32marm64.exe -c LauterbachConfig_a53.t32, init.cmm ca53 1
