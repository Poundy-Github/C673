@echo off

pushd %~dp0

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


start C:\Tools\T32\T32_R_2017_09_000092037\bin\windows64\t32marm64.exe -c LauterbachConfig_a53_only.t32, init.cmm ca53 0
popd
