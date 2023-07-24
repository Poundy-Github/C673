
@echo off

:: Make sure changes to environment variables are only local do not affect the calling command line
setlocal EnableDelayedExpansion

rem --- Generate GA and MDB files from xml
if exist ..\preprocess\function_code_gen.py (
	attrib -R -H ..\..\..\00_Projects\%APP_PROJECT_NAME%\DPUFF\ga\* /S
	echo.
	echo Generating GA and MDB files
	dir \\cw01.contiwan.com\root\loc\ulm2\didt6402\SW-DevTools\python
	dir \\cw01.contiwan.com\root\loc\ulm2\didt6402\SW-DevTools\python\2.7
	call \\cw01.contiwan.com\root\loc\ulm2\didt6402\SW-DevTools\python\2.7\python.exe ..\..\..\02_Development_Tools\soccer\socGenerator.py -c "..\..\..\00_Projects\%APP_PROJECT_NAME%\DPUFF\ga" -o "..\..\..\00_Projects\%APP_PROJECT_NAME%\DPUFF\ga" -t "..\code_gen_templates" --ga --mdb
	if ERRORLEVEL 1 (
		echo.
		echo *** Generating GA and MDB files failed ***
		exit /b 1
	)
)
