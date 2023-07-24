@echo off
:: Wrapper script to start nonMembers.py from batch

:: Make sure changes to environment variables are only local do not affect the calling command line
setlocal EnableDelayedExpansion

:: Use a dedicated python version
set PYTHON_PATH=c:\Tools\python\2.7.10

:: Batch file calling python script
call %PYTHON_PATH%\python.exe ..\integration_tools\nonMembers.py %1

::Back to batch
echo.