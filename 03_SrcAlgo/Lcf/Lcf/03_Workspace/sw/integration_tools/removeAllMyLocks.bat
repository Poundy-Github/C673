@echo off
:: This script removes all the file lock of the calling user.
:: Using the script asumes that you know what you are doing. 

:: (C) 2014 - ADC Lindau GERMANY
:: Author: Frank Sautter-Steisslinger
:: Version: 1.0  Script generation							23.06.2015    Frank Sautter-Steisslinger
::          1.1  Moved to Mainstream                        17.01.2017    Magnus Baur
::          1.2  First working version in Mainstream        17.01.2017    Magnus Baur

:: Make sure changes to environment variables are only local do not affect the calling command line
SETLOCAL ENABLEDELAYEDEXPANSION

:: Store current working directory, so we can CD back in case of an error
set INITIAL_WD=%CD%

:: Change working directory to the directory where this script is stored. This allows invoking
:: this script from any directory without CD'ing into the batch file's home directory
cd %~dp0
set CURRENT_WD=%CD%

:: Remove all my file locks
cd ..\..\..\..\..\
si unlock --action=remove --quiet -R

cd %CURRENT_WD%
