::@echo off

:: call the IsrLocalIdXmlGenerator
::
:: usage: IsrLocalIdXmlGenerator [-h] [-g]
::                               project build_unit generatorCfgFile outputPath
::                               inputRefPath
:: 
:: Generates the IsrLocalID XML file based on given input header files
:: 
:: positional arguments:
::   project           The name of the project.
::   build_unit        The name of the buildUnit
::   generatorCfgFile  The generator configuration file in which all relevant input header files have to be provided.
::   outputPath        This argument has to provide the path where the generated XML file shall be stored to. 
::   inputRefPath      This argument has to provide the input reference path which is used as a basePath 
::                     for given input header files  in the generator configuration file. 
:: 
:: optional arguments:
::   -h, --help        show this help message and exit
::   -g, --gui         enables/disables configuration GUI

pushd "%~dp0"

C:\"Program Files"\Python36\python.exe GenerateIsrLocalIdXml.py %1 %2 %3 %4 %5 %6

popd
