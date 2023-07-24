@echo off
SET PYTHON_EXE=C:\Tools\python\2.7.10\python.exe
SET PROJECT_LIST=mfc431,ars441,mfc430hi17,hfl130

%PYTHON_EXE% %~dp0\patch_eclipse_project.py %PROJECT_LIST%
pause
