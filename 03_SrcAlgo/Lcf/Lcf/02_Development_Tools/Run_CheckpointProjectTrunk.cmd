@echo off

rem Set the current directory as CurrentWorkDirectory(CWD)
for /f "TOKENS=*" %%I IN ('cd') DO SET CWD=%%I

Set PATH_PHYTHON_INSTALLATION=C:\tools\Python\2.7.10
SET IMS_HOST=ims-adas
SET IMS_PORT=7001

:Project_Path
echo .
echo *** Please enter your project family ***
echo *** ARS441x ***
echo *** ARS51x  ***
echo *** MFC431x ***
echo *** SRR51x  ***
echo *** SRR52x  ***
set /P PjFam=ProjectFamily :
SET PRJFAMILY=%PjFam%

echo .
echo *** Please enter your project ***
echo *** ARS441     ***
echo *** ARS441DP10 ***
echo *** ARS510     ***
echo *** ARS510EVS  ***
echo *** ARS510GM18 ***
echo *** ARS510HA19 ***
echo *** MFC431     ***
echo *** MFC431TA19 ***
echo *** SRR510     ***
echo *** SRR520     ***
echo *** SRR520EVS  ***
echo *** SRR520GM18 ***
set /P Prj=Project :
SET PROJECT=%Prj%

SET IMS_PROJECT_PATH=/ADAS/SW/Projects/%PRJFAMILY%/%PROJECT%/project.pj

echo .
echo *** General Settings ***
echo .
echo PATH_PHYTHON_INSTALLATION: %PATH_PHYTHON_INSTALLATION%
echo IMS_HOST: %IMS_HOST%
echo IMS_PORT: %IMS_PORT%
echo IMS_PROJECT_PATH: %IMS_PROJECT_PATH%

echo .
echo *** Is this information correct [y/n]? ***
set /P InfoCorr=[y/n] :
if "%InfoCorr%" == "y" (
  goto Job_Select
) else (
  goto Project_Path
)

:Job_Select
echo .
echo *** What Job do you want to execute ? ***
echo *** 1 - generate the list of build shares ***
echo *** 2 - generate the list of normal shares ***
echo *** 3 - create a PreIntegration checkpoint  ***
echo *** 4 - recover from PreIntegration checkpoint creation ***
set /P opt=Option. :
if "%opt%" == "1" (
  goto run_tool
) else if "%opt%" == "2" (
  goto run_tool
) else if "%opt%" == "3" (
  goto CP_Info
) else if "%opt%" == "4" (
  goto CP_Info
) else (
  echo Invalid Option !
  pause
  goto Job_Select
)

:CP_Info
echo .
echo *** Enter your change package ID ***
echo *** Format: [RO Id]:[CP Id] ***
set /P CpId=ChangePackage ID :
SET IMS_CHANGE_PACKAGE=%CpId%

echo .
echo *** Enter your PreIntegration CheckPointLabel ***
set /P CpLabel=CheckPoint Label :
SET IMS_CHECKPOINT=%CpLabel%

echo .
echo *** Enter your CheckPoint Description ***
set /P CpDescr=CheckPoint Description :
SET IMS_CHECKPOINT_DESCRIPTION=%CpDescr%

echo .
echo *** Is this information correct [y/n]? ***
echo.
echo. your ChangePackage ID is: %CpId%
echo.
echo. your CheckPointLabel is: %CpLabel%
echo.
echo. your CheckPoint Description is: %CpDescr%
set /P InfoCorr=[y/n] :
if "%InfoCorr%" == "y" (
  goto run_tool
) else (
  goto CP_Info
)

:run_tool
echo.
echo launching BuildNormalTool

cd MKS_Source\CheckpointProjectTrunk

if "%opt%" == "1" (
  start %PATH_PHYTHON_INSTALLATION%\python CheckpointProjectTrunk.py %IMS_HOST% %IMS_PORT% --project=%IMS_PROJECT_PATH% --generate=build
) else if "%opt%" == "2" (
  start %PATH_PHYTHON_INSTALLATION%\python CheckpointProjectTrunk.py %IMS_HOST% %IMS_PORT% --project=%IMS_PROJECT_PATH% --generate=shared
) else if "%opt%" == "3" (
  start %PATH_PHYTHON_INSTALLATION%\python CheckpointProjectTrunk.py %IMS_HOST% %IMS_PORT% --project=%IMS_PROJECT_PATH% --changepackage=%IMS_CHANGE_PACKAGE% --checkpoint="%IMS_CHECKPOINT%" --description="%IMS_CHECKPOINT_DESCRIPTION%" --execute --skipcheck
) else (
  start %PATH_PHYTHON_INSTALLATION%\python CheckpointProjectTrunk.py %IMS_HOST% %IMS_PORT% --project=%IMS_PROJECT_PATH% --changepackage=%IMS_CHANGE_PACKAGE% --checkpoint="%IMS_CHECKPOINT%" --description="%IMS_CHECKPOINT_DESCRIPTION%" --recover --xml=ComponentIntegrationList.xml 
)

:exit_tool
exit
