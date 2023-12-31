@ECHO OFF
REM ****************************************************************************
REM *                                                                         **
REM * Copyright (C) Infineon Technologies (2016)                              **
REM *                                                                         **
REM * All rights reserved.                                                    **
REM *                                                                         **
REM * This document contains proprietary information belonging to Infineon    **
REM * Technologies. Passing on and copying of this document, and communication**
REM * of its contents is not permitted without prior written authorization.   **
REM *                                                                         **
REM ****************************************************************************
REM *                                                                         **
REM *  FILENAME  : DemoAppBuild.bat                                           **
REM *                                                                         **
REM *  VERSION   : 1.0.0                                                      **
REM *                                                                         **
REM *  DATE      : 2020.08.10                                                 **
REM *                                                                         **
REM *  PLATFORM  : Infineon AURIX2G                                           **
REM *                                                                         **
REM *  AUTHOR    : DL-AUTOSAR-Engineering                                     **
REM *                                                                         **
REM *  VENDOR    : Infineon Technologies                                      **
REM *                                                                         **
REM *  DESCRIPTION  : This file builds MCAL Demo Applications                 **
REM *                                                                         **
REM *  MAY BE CHANGED BY USER [yes\no]: YES                                   **
REM *                                                                         **
REM ***************************************************************************\

@ECHO OFF
REM ****************************************************************************
REM  Get Root Path
REM ****************************************************************************
set BINUTILS_PATH=..\..\..\Tools\Bifaces\bin
set PATH=%BINUTILS_PATH%;%PATH%
set PATH=%PATH%;C:\sofit\aurix2g_sw_mcal\hightec\4.9.4.1\hightec\licensemanager
SET BUILDENV=DEMOAPP
SET BUILD_DEMOAPP_PACKAGE=1
SET WITHOUT_TRESOS_WITHOUT_FR=0

REM ****************************************************************************
REM Get the Compiler and Tresos Installation Path
REM ***************************************************************************
IF "%1" == "" SET COMPILER=Tasking
IF "%1" == "TASKING" SET COMPILER=Tasking
IF "%1" == "GNU" SET COMPILER=Gnuc
IF "%1" == "DCC" SET COMPILER=Dcc
IF "%1" == "GHS" SET COMPILER=Ghs

IF "%COMPILER%" == "Tasking" SET B_Tasking_COMPILER_PATH=C:/sofit/aurix2g_sw_mcal/tasking/6.3r1p2/tasking/ctc/bin
IF "%COMPILER%" == "Gnuc" SET B_Gnuc_COMPILER_PATH=C:/sofit/aurix2g_sw_mcal/hightec/4.9.4.1/hightec/toolchains/tricore/v4.9.4.1/bin
IF "%COMPILER%" == "Dcc" SET B_DCC_TRICORE_PATH=C:/sofit/aurix2g_sw_mcal/windriver/5.9.7.0_17054/windriver/compilers/diab-5.9.7.0/WIN32
IF "%COMPILER%" == "Ghs" SET B_GHS_TRICORE_PATH=C:/sofit/aurix2g_sw_mcal/green-hills/v2018.1.5-9.15.1/green-hills/comp_201815

IF "%2" == "" SET TRESOS_BUILD=YES
IF "%2" == "WITHOUT_TRESOS" SET TRESOS_BUILD=NO
IF "%2" == "WITHOUT_TRESOS_WITHOUT_FR" ( 
	SET WITHOUT_TRESOS_WITHOUT_FR=1
	SET TRESOS_BUILD=NO
)	
IF "%2" == "WITH_TRESOS" SET TRESOS_BUILD=YES

IF "%3" == "" SET TRESOS_BIN_PATH=%TRESOS_26_2_0_HOME%/tresos/bin
IF NOT "%3" == "" SET TRESOS_BIN_PATH=%3

REM ****************************************************************************
REM Check if link file exist in TRESOS
REM ***************************************************************************
IF EXIST "%TRESOS_BIN_PATH%\..\links\*.link" (
   ECHO DemoApp Compilation requires to delete the link file from tresos path tresos/tresos/link folder 
   ECHO Please take backup of the link file in TRESOS and try again
   ECHO Also make sure you copy the plugins from <Package>\PluginsTresos\eclipse\plugins to tresos\tresos\plugins directory
   PAUSE
   EXIT /B
)

IF NOT "%4" == "" SET B_%COMPILER%_COMPILER_PATH=%4

REM Copy the Config.xml file for DemoApp
xcopy /y ..\..\..\Tools\Compiler_Configs_AS422_200PR\TC33A_ED_Config_%COMPILER%.xml 1_ToolEnv\0_Build\1_Config\Config.xml
make all

PAUSE

