echo off
echo =============================================================
echo This script copies the java-script-command, that is needed to
echo load the debug-server-script into clipboard.
echo Please execute the script and paste clipboard afterwards
echo into the CCS-scripting console. This will register
echo the debug server script in the Eclipse workspace.
echo.
echo U.W., -918
echo =============================================================


set SCRIPT_FILE=..\..\..\..\04_Engineering\01_Source_Code\DPUHWIF_TI_TDA123\ds\DebugServerScripting.js

if not exist %SCRIPT_FILE% goto IllegalFolder

echo loadJSFile "%CD%\%SCRIPT_FILE%" true > temp_ULWA

CLIP < temp_ULWA
del temp_ULWA

echo.
echo The scripting-console-command for registering the Startup-JavaScript into workspace has been stored in clipboard!
echo Please paste it into the CCS-Scripting-Console (ctrl+v)

goto EndOfFile

:IllegalFolder
echo.
echo.
echo ERROR: Current directory must be the folder of java-script-file (CCS-project-directory)!
echo Please start this batch from windows-explorer and NOT from Eclipse-Project-Explorer!
echo.
echo.
pause

:EndOfFile
echo Done!

pause
