@echo off

setlocal

pushd %~dp0

rem Set the current directory as CurrentWorkDirectory(CWD)
for /f "TOKENS=*" %%I IN ('cd') DO SET CWD=%%I

Set PATH_USR_MSG_FILE=%CWD%\UserMessageFile\
Set PATH_QAC_PRJ_FILE=%CWD%\

set CMNAME=m2cm

echo.
echo Setting up QAC environment for (current) %CMNAME% Compliance Module
echo.

echo CMNAME           now set to %CMNAME%

rem Set QACPATH       to point to QAC root directory
set QACPATH=C:\tools\qac\8.1.1-R

rem Set QACBIN        to point to location of QAC executables
set QACBIN=%QACPATH%bin
echo QACBIN           now points to %QACBIN%

rem Set QACOUTPATH    to point to location of .err and .met files
set QACOUTPATH=%QACPATH%temp
echo QACOUTPATH       now points to %QACOUTPATH%

rem Set QACHELPFILES  to point to location of HTML reference files
set QACHELPFILES=%QACPATH%help
echo QACHELPFILES     now points to %QACHELPFILES%

rem Set QACTEMP       to point to location of QAC temp directory
set QACTEMP=%QACPATH%temp
echo QACTEMP          now points to %QACTEMP%

rem Set CMHOME        to point to (current) Compliance Module root directory
set CMHOME=%QACPATH%%CMNAME%\
echo CMHOME           now points to %CMHOME%

rem Set CMBIN         to point to location of (current) Compliance Module executables
set CMBIN=%CMHOME%bin
echo CMBIN            now points to %CMBIN%

rem Modify existing path:
set path=%CMBIN%;%QACBIN%;%path%
echo.
echo *** What QAC Project do you want to launch ? ***
echo *** 1 - MFC431     ***
echo *** 2 - MFC4T0     ***
echo *** 3 - HFL110     ***
echo *** 4 - ARS441     ***
echo *** 5 - HFL110TA10 ***
set /P Prj=Project :

if "%Prj%" == "1" (
  start C:\tools\qac\8.1.1-R\bin\QACANL.exe %PATH_QAC_PRJ_FILE%_mfc431.prj
) else if "%Prj%" == "2" (
  start C:\tools\qac\8.1.1-R\bin\QACANL.exe %PATH_QAC_PRJ_FILE%_mfc4t0.prj
) else if "%Prj%" == "3" (
  start C:\tools\qac\8.1.1-R\bin\QACANL.exe %PATH_QAC_PRJ_FILE%_hfl110.prj
) else if "%Prj%" == "4" (
  start C:\tools\qac\8.1.1-R\bin\QACANL.exe %PATH_QAC_PRJ_FILE%_ars441.prj
) else if "%Prj%" == "5" (
  start C:\tools\qac\8.1.1-R\bin\QACANL.exe %PATH_QAC_PRJ_FILE%_hfl110ta10.prj
) else (
  echo Invalid Option !
  pause
)

popd
exit /b
