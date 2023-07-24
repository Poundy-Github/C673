@echo off
setlocal

:: Change directory to SandboxRoot
cd ..\..\..
set SCRIPT_EXEC=C:\Tools\perl\v5.6\bin\perl.exe 04_Engineering\03_Workspace\ccs\eclipse_prj_patcher.pl

%SCRIPT_EXEC% arm-a_0 mfc431
%SCRIPT_EXEC% arm-m_0 mfc431,ars441
%SCRIPT_EXEC% arm-m_1 mfc431
%SCRIPT_EXEC%   dsp_0 mfc431,ars441
%SCRIPT_EXEC%   dsp_1 mfc431,ars441
%SCRIPT_EXEC%   eve_0 mfc431
%SCRIPT_EXEC%   eve_1 mfc431
pause


