@echo off
:: Note
:: Copy 04_Engineering\02_Development_Tools\scons_tools\scons_templates\03_Workspace\algo\xxx\scons.bat to 04_Engineering\03_Workspace\algo\hla\

cd /d %~dp0

for %%* in (.) do set component=%%~n*

:: Update error handling hashes
..\..\..\02_Development_Tools\movpy\movpy.exe ..\..\..\..\03_Design\03_Code_Generation\Generic\HLA\ErrorHandlingGenerator.py

:: Duplicate pdo tags file from .h to .c since this scons can only handle
SET PDO_HEADER=%~dp0\..\..\..\01_Source_Code\HLA\hla_pdo_tags_file.h
SET PDO_DUMMY_SOURCE=%~dp0\..\..\..\01_Source_Code\HLA\hla_pdo_tags_file_copy.cpp

copy /Y %PDO_HEADER% %PDO_DUMMY_SOURCE%

call ../../../02_Development_Tools/scons_tools/scons_common_scripts/batch/scons.bat %* no_err_warning=1
SET /A RETURN_VALUE=%ERRORLEVEL%

:: Remove duplicated pdo tags file
del /F %PDO_DUMMY_SOURCE%

echo.
echo SCons finished: %date% @ %time%

exit /B %RETURN_VALUE%
