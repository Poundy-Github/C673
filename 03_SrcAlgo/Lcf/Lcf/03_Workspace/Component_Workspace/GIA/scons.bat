REM @echo off
REM : Note
REM : Copy 04_Engineering\02_Development_Tools\scons_tools\scons_templates\03_Workspace\algo\xxx\scons.bat to 04_Engineering\03_Workspace\algo\xxx\

set oriPath=%cd%
cd /d %~dp0

for %%* in (.) do set component=%%~n*
call ../../../02_Development_Tools/scons_tools/scons_common_scripts/batch/scons.bat %*