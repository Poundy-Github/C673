@echo off
:: set DPU dir
SET DPU_DIR=..\..\..\..\

:: set tools relative to DPU dir
SET TOOLS_DIR=04_Engineering\02_Development_Tools
SET DOXYGEN_EXE=%TOOLS_DIR%\doxygen\bin\doxygen.exe
SET GRAPHVIZ_DOT=%TOOLS_DIR%\graphviz\bin\dot.exe
SET MOVPY_EXE=%TOOLS_DIR%\movpy\movpy.exe

SET SHORTNAME=HLA

:: set path to doxygen configuration file relative to DPU dir
SET DESIGN_DIR=03_Design\02_Architecture\Generic\%SHORTNAME%

:: change to DPU dir and save old dir on stack
PUSHD "%DPU_DIR%"

:: Remove write protection of CHM file if available
SET CHM_PATH=%DESIGN_DIR%\Continental_%SHORTNAME%_Design_Documentation_SIL.chm
if exist %CHM_PATH% (
  attrib -r %CHM_PATH%
)

:: call doxygen for current dir (doxyfile)
%DOXYGEN_EXE% %DESIGN_DIR%\Cfg_Doxy_%SHORTNAME%_Sil.doxy

:: change to saved dir
POPD

:: Filter log file
%DPU_DIR%%MOVPY_EXE% FilterDoxyLog.py %1

:: Open final result
::if exist %CHM_PATH% (
::  %CHM_PATH%
::)
