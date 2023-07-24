::@echo off

:: call the rtaXmlGenerator
::
::
:: Generate all RtaXmlFiles.
:: 
::positional arguments:
::  inputCfgFile          The input configuration file in which all relevant files and folders are provided.
::
::optional arguments:
::  -h, --help            show this help message and exit
::  -r PRJREFPATH, --prjRefPath PRJREFPATH
::                        The project referencePath is used as a base to determine the absolutePaths for the following elements 
::                        in the RtaXmlGenerator_InputCfg*.yaml:  "generator_cfg_file", "os_dir_path", "lut_cfg_file_path", "rta_taskids_h"
::                        This argument is not necessary in case all these elements are provided with absolute paths in the RtaXmlGenerator_InputCfg*.yaml.
::  -p PDOREFPATH, --pdoRefPath PDOREFPATH
::                        This argument has to provide the base path where the DAT files are stored to by the pdoTool.
::                        This referencePath is used to establish an absolute path together with the "pdo_path" given in the corresponding RtaXmlGenerator_InputCfg*.yaml
::                        This argument is not necessary in case "pdo_path" in the RtaXmlGenerator_InputCfg*.yaml is given as an absolute path.
::  -i GLOBIDREFPATH, --globIdRefPath GLOBIDREFPATH
::                        This argument has to provide the base path to the rta_globalids.h - e.g. the package path in which the globalID file can be found. 
::                        This referencePath is used to establish an absolute path together with the "rta_globalids_h" given in the corresponding RtaXmlGenerator_InputCfg*.yaml
::                        This argument is not necessary in case "rta_globalids_h" in the RtaXmlGenerator_InputCfg*.yaml is given as an absolute path.
::  -o OUTPUTREFPATH, --outputRefPath OUTPUTREFPATH
::                        This argument has to provide the base path to the desired outputPath. 
::                        This referencePath is used to establish an absolute path together with the "output_path" given in the corresponding RtaXmlGenerator_InputCfg*.yaml.
::                        This argument is not necessary in case "output_path" in the RtaXmlGenerator_InputCfg*.yaml is given as an absolute path. 
::  -l LOCALIDXMLSREFPATH, --localIdXmlsRefPath LOCALIDXMLSREFPATH
::                        This argument has to provide the base path to the path where preGenerated localIdXml files are located. 
::                        This referencePath is used to establish an absolute path together with the "local_id_xml_path" given in the corresponding RtaXmlGenerator_InputCfg*.yaml.
::                        In case there are no preGenerated localIdXml files, which means the "local_id_xml_path" is not given in the corresponding RtaXmlGenerator_InputCfg*.yaml 
::                        then it is not relevant at all.
::                        This argument is also not necessary in case "local_id_xml_path" in the RtaXmlGenerator_InputCfg*.yaml is given as an absolute path. 
::  -g, --gui             enables/disables configuration GUI


pushd "%~dp0"

set args=%1 %2 %3 %4 %5 %6 %7 %8 %9 
for /L %%i in (0,1,8) do @shift
set args=%args% %1 %2 %3 %4 %5 %6 %7 %8 %9
%TOOLPATH_PYTHON_EXE% GenerateRtaXmls.py %args%

popd
