::@echo off

:: call the RtaLocalIdXmlOnlyGenerator
::
:: usage: GenerateLocalIdXmlsOnly [-h] [-p PDOREFPATH] [-o OUTPUTREFPATH] [-g]
::                                generatorCfgFile
:: 
:: Generate local ID XML files, errorID XML files, intern errorID XML files and errorOffsetID XML files from given dat-file(s). 
:: 
:: positional arguments:
::   generatorCfgFile      The generator configuration file in which all relevant datFiles have to be provided.
:: 
:: optional arguments:
::   -h, --help            show this help message and exit
::   -p PDOREFPATH, --pdoRefPath PDOREFPATH
::                         This argument has to provide the base path where the datFiles can be found.
::                         This referencePath is used to establish an absolute path together with the "pdo_path" given in the corresponding RtaXmlGenerator_InputCfg*.yaml
::   -o OUTPUTREFPATH, --outputRefPath OUTPUTREFPATH
::                         This argument has to provide the path where the generated XML files shall be stored to. 
::   -g, --gui             enables/disables configuration GUI
  
pushd "%~dp0"

C:\"Program Files"\Python36\python.exe GenerateLocalIdXmlsOnly.py %1 %2 %3 %4 %5 %6

popd
