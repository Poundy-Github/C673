@echo off

rem   Example command for using open document command:
rem   -> open_documentation.bat p hfl130 ia

:: Make sure changes to environment variables are only local do not affect the calling command line
setlocal EnableDelayedExpansion
set project=

:: Read input option
:optionsloop
if "%1" == "" (
  echo.
  echo Error: Please specify the product ID with a parameter to the "p" argument
  echo        ie. lockFilesForCP.bat p mfs430bw16
  exit /b
)

if "%1" == "p" (
  if "%2%"=="" (
    echo.
    echo Error: Please specify the product ID with a parameter to the "p" argument
    echo        ie. lockFilesForCP.bat p mfs430bw16
    exit /b
  ) else (
    set project=%2
  )
)

if defined project (
if "%3%"=="" (
  echo.
  echo Error: Please specify the component ie. FF, IPC etc.
  echo 		  or SoC for complete documentation
  exit /b
) else (
  SET component=%3
  goto optionopen
)
)

:: Shift next command option and do the loop again until all options are processed
shift
if "%1" == "" goto optionsend
goto optionsloop
:optionsend


:optionopen
pushd %~dp0
if not exist ..\..\..\04_Build\doc\%project%\%component%\%component%.chm (
	echo.
	echo Documentation is not yet generated
	echo.
	echo Generate Doxygen documentation
	call create_documentation.bat p %project% %component%
)
echo.
echo Open Doxygen documentation
start ..\..\..\04_Build\doc\%project%\%component%\%component%.chm
popd