::@echo off

::Call the RteStandardRtaInstrGenerator
::
::
::RteStandardRtaInstrumentationGenerator is generating RTE RTA calls in the postgenProcess of Tresos.
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
::  -x XMLPATH, --xmlPath XMLPATH
::                        In case the xmlPath is provided the generator will also generate all the localID-Xmls related to RTE.
::                        The xmlPath can be provided as relative path in this case it will be combined with the prjRefPath to build the absolute path.
::  -g, --gui             enables/disables configuration GUI


pushd "%~dp0"

C:\"Program Files"\Python36\python.exe GenerateRteStandardRtaInstrumentation.py %1 %2 %3 %4

popd
