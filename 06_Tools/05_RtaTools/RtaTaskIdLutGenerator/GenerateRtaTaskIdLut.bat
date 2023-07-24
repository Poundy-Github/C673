::@echo off
::
::Call the RtaTaskIdLutGenerator
::
::Generate TaskID lookup table
::
::positional arguments:
::  inputCfgFile          The input configuration file in which all relevant files and folders are provided.
::
::optional arguments:
::  -h, --help            show this help message and exit
::  -r PRJREFPATH, --prjRefPath PRJREFPATH
::                        The project referencePath is used as a base to determine the absolutePaths for all 
::                        relativePaths given in the corresponding RtaXmlGenerator_InputCfg*.yaml.
::                        This argument is not necessary in case all the paths in the RtaXmlGenerator_InputCfg*.yaml are provided as absolute paths.
::  -g, --gui             enables/disables configuration GUI


pushd "%~dp0"


%TOOLPATH_PYTHON_EXE% GenerateRtaTaskIdLut.py %1 %2 %3 %4

popd
