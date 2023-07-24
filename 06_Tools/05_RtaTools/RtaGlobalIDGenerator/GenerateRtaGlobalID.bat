:: The RtaGlobalIDGenerator

:: With this generator new globalIDs can be added.

:: Adding new globalIDs has to be handled with care!!
:: Therefore this generator must not be used by somebody else but teamMembers of the log&trace team!!

:: In case you need a new globalID, please contact Matthias Kammerl
:: (Matthias.Kammerl@continental-corporation.com)

:: Thank you!





::@echo off
::Call the RtaGlobalIDGenerator 
::usage: RtaGlobalIDGenerator [-h] rta_globalids_path
::
::Generate RTA Global IDs
::
::positional arguments:
::  rta_globalids_path  Location of the RTA_GlobalIDs.h file
::
::optional arguments:
::  -h, --help          show this help message and exit

pushd "%~dp0"
%TOOLPATH_PYTHON_EXE% RtaGlobalIDGenerator.py %1
popd
