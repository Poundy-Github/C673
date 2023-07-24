@echo off
rem (C) 2012 - ADC Lindau, Germany
rem Author: Edmund Friedrichs

echo.
echo --- Start: MulticorePostprocCommon.bat
echo.
call :delete_helper_files

set checkBinarySize=1
if "%PROJECT_NAME%" == "" (
	echo Error: This batch file can no longer be used standalone.  Please use the
	echo        command "sw_build.bat postonly" to generate ROM images without building
	exit /b 1
)
SET PROJECT=%PRODUCT%
if "%PRODUCT%" == "hfl110ta10" (
	echo Warning: hfl110ta10 is treated as hfl110 in MulticorePostprocCommon.bat
	set PRODUCT=hfl110
	set checkBinarySize=1
)

if "%PRODUCT%" == "mfc431lo19" (
	echo Warning: mfc431lo19 is treated as mfc431 in MulticorePostprocCommon.bat
	set PRODUCT=mfc431
	set checkBinarySize=1
)

if "%PRODUCT%" == "mfc431lo20" (
	echo Warning: mfc431lo20 is treated as mfc431 in MulticorePostprocCommon.bat
	set PRODUCT=mfc431
	set checkBinarySize=1
)

if "%PRODUCT%" == "mfc431ta19" (
	echo Warning: mfc431ta19 is treated as mfc431 in MulticorePostprocCommon.bat
	set PRODUCT=mfc431
	set checkBinarySize=1
)

if "%PRODUCT%" == "mfc431sc19" (
	echo Warning: mfc431sc19 is treated as mfc431 in MulticorePostprocCommon.bat
	set PRODUCT=mfc431
	set checkBinarySize=1
)

if "%PRODUCT%" == "mfc431sw19" (
	echo Warning: mfc431sw19 is treated as mfc431 in MulticorePostprocCommon.bat
	set PRODUCT=mfc431
	set checkBinarySize=1
)

if "%PRODUCT%" == "mfc431va10" (
	echo Warning: mfc431va10 is treated as mfc431 in MulticorePostprocCommon.bat
	set PRODUCT=mfc431
	set checkBinarySize=1
)

if "%PRODUCT%" == "mfc431bd10" (
	echo Warning: mfc431bd10 is treated as mfc431 in MulticorePostprocCommon.bat
	set PRODUCT=mfc431
	set checkBinarySize=1
)

if "%PRODUCT%" == "mfc431va21" (
	echo Warning: mfc431va21 is treated as mfc431 in MulticorePostprocCommon.bat
	set PRODUCT=mfc431
	set checkBinarySize=1
)

echo Step0: Create SBL image file
set stepno=0
call ../postprocess/sbl_create_tiimage.bat %APP_PROJECT_NAME% .

if "%SOCTYPE%" == "low" (
if not exist "SBL.rprc" (
	echo.
	echo *** SBL.rprc could not be created - aborting ***
	exit /b 1
)	
) else (
if not exist "SBL.tiimage" (
	echo.
	echo *** SBL.tiimage could not be created - aborting ***
	exit /b 1
)
)

rem --------------------------------------

echo Step1: Create Core application image files
set stepno=1
call ../postprocess/MulticoreImageGenCommon.bat

if not exist "AppImage_BE.mfc" (
	echo.
	echo *** Archive file AppImage_BE.mfc could not be created - aborting ***
	exit /b 1
)

echo.
echo Step2: Merge the application image files
set stepno=2

rem define local variables for paths
setlocal
set post_process_dir=..\..\..\02_Development_Tools\post_process
set pp_cat=%post_process_dir%\cat.exe
set srec_cat=%post_process_dir%\srec_cat.exe

set source_config_dir=..\..\..\00_Projects\%APP_PROJECT_NAME%
rem we take any product-specific flash-related files from this directory (may not exist if there are no such files)
set flash_file_data=%source_config_dir%\flash_file_data
set build_dir=..\..\..\04_Build
set arm_m_0_outfile=%build_dir%\out\%APP_PROJECT_NAME%\%BUILDCONFIG%_arm-m_0\arm-m_0.out
set eng_deliverables_dir=..\..\..\..\..\06_Deliverables

rem define local variables for addresses in the flash image
rem IB_ infoblock
rem AI_ app image
rem SR2_ security record 2, SR1_ security record 1, fs0_ flash status
rem FIXME: inconsistency between crc offset for srlcam, high
rem FIXME: perhaps these could go in a batch file in the product config directory, perhaps flash_file_data or whatever...

  echo Setting flash addresses for %APP_PROJECT_NAME% %soctype%
  if "%SOCTYPE%" == "low" (
    rem IB is concatenated
    rem SOC binary file (*.bin) includes SBL (address 0x5c020000) and SOC application image (0x5c0f0000)
    rem Addresses are identical for all vision low projects (including ARS441)  
    set  mot_flash_offset=0x5C000000
    set     PRESBL_offset=0x00000000
    set	       SBL_offset=0x00020000
    set	        IB_offset=0x00038000
    set        EVE_offset=0x000f0000
    set         AI_offset=0x000f4000
    set  crc_flash_offset=0x5C600000
	    
    rem Usually vision low SOC projects mot file includes only SBL, but ARS441 includes PRESBL (start address 0x5c000000) in addition to SBL (start address 0x5c020000) 
    if "%APP_PROJECT_NAME%" == "ars441" (
      set 	ars441_mot_flash_offset=0x5C000000
      set    ars441_PRESBL_offset=0x00000000	
      set	ars441_SBL_offset=0x00020000
      set	 ars441_IB_offset=0x00038000
      set       ars441_EVE_offset=0x000f0000
      set        ars441_AI_offset=0x000f4000
    )^
  )^
  else if "%SOCTYPE%" == "high" (
    if "%APP_PROJECT_NAME%" == "mfc431" (
      rem SBL for mfc431 is bigger so we need to move the offsets a bit otherwise it won't fit
      set           IB_offset=0x4FF00
      set          SR2_offset=0x4FF80
      set             SR2_end=0x50000
      set  mot_flash_offset=0x2000000
      set crc_flash_offset=0x02F00000
    )^
    else if "%APP_PROJECT_NAME%" == "mfc431lo19" (
      rem SBL for mfc431 is bigger so we need to move the offsets a bit otherwise it won't fit
      set           IB_offset=0x4FF00
      set          SR2_offset=0x4FF80
      set             SR2_end=0x50000
      set  mot_flash_offset=0x2000000
      set crc_flash_offset=0x02F00000
    )^
	else if "%APP_PROJECT_NAME%" == "mfc431lo20" (
      rem SBL for mfc431 is bigger so we need to move the offsets a bit otherwise it won't fit
      set           IB_offset=0x4FF00
      set          SR2_offset=0x4FF80
      set             SR2_end=0x50000
      set  mot_flash_offset=0x2000000
      set crc_flash_offset=0x02F00000
    )^
    else if "%APP_PROJECT_NAME%" == "mfc431ta19" (
      rem SBL for mfc431 is bigger so we need to move the offsets a bit otherwise it won't fit
      set           IB_offset=0x4FF00
      set          SR2_offset=0x4FF80
      set             SR2_end=0x50000
      set  mot_flash_offset=0x2000000
      set crc_flash_offset=0x03F00000
    )^
    else if "%PRODUCT%" == "hfl110" (
      rem like mfc431, SBL for hfl110 is bigger so we need to move the offsets a bit otherwise it won't fit
      set           IB_offset=0x4FF00
      set          SR2_offset=0x4FF80
      set             SR2_end=0x50000
      set  mot_flash_offset=0x2000000
      set crc_flash_offset=0x02F00000
    )^
	else if "%APP_PROJECT_NAME%" == "mfc431sc19" (
      rem SBL for mfc431 is bigger so we need to move the offsets a bit otherwise it won't fit
      set           IB_offset=0x4FF00
      set          SR2_offset=0x4FF80
      set             SR2_end=0x50000
      set  mot_flash_offset=0x2000000
      set crc_flash_offset=0x02F00000
    )^
    else if "%APP_PROJECT_NAME%" == "mfc431sw19" (
      rem SBL for mfc431 is bigger so we need to move the offsets a bit otherwise it won't fit
      set           IB_offset=0x4FF00
      set          SR2_offset=0x4FF80
      set             SR2_end=0x50000
      set  mot_flash_offset=0x2000000
      set crc_flash_offset=0x02F00000
    )^
    else if "%APP_PROJECT_NAME%" == "mfc431va10" (
      rem SBL for mfc431 is bigger so we need to move the offsets a bit otherwise it won't fit
      set           IB_offset=0x4FF00
      set          SR2_offset=0x4FF80
      set             SR2_end=0x50000
      set  mot_flash_offset=0x2000000
      set crc_flash_offset=0x02F00000
    )^
    else if "%APP_PROJECT_NAME%" == "mfc431va21" (
      rem SBL for mfc431 is bigger so we need to move the offsets a bit otherwise it won't fit
      set           IB_offset=0x4FF00
      set          SR2_offset=0x4FF80
      set             SR2_end=0x50000
      set  mot_flash_offset=0x2000000
      set crc_flash_offset=0x02F00000
    )^
    else if "%APP_PROJECT_NAME%" == "mfc431bd10" (
      rem SBL for mfc431 is bigger so we need to move the offsets a bit otherwise it won't fit
      set           IB_offset=0x4FF00
      set          SR2_offset=0x4FF80
      set             SR2_end=0x50000
      set  mot_flash_offset=0x2000000
      set crc_flash_offset=0x02F00000
    )^
    else (
      rem IB_ offset and length, SR2_ offset same as in SRLCam
      rem SR1_ and fs0_ offsets taken from rev 1.4 of:
      rem http://mks-psad:7001/si/viewrevision?projectName=/nfs/projekte1/SW/SW%5fMFC4xx/SW%5fMFC4T0/01%5fSupporting%5fProcesses/04%5fCommunication/02%5fCustomer/FBL/project.pj&selection=GSP%2d15PF%2dMFC%2dMIC%2dSTD.xlsx
      set flash_file_data=%source_config_dir%\flash_file_data
      set           IB_offset=0x1FF20
      set          SR2_offset=0x1FFA0
      set             SR2_end=0x20000
      set  mot_flash_offset=0x1000000
      set  fs0_flash_offset=0x167FFE0
      set crc_flash_offset=0x01680000
    )
    set          EVE_offset=0x80000
    set           AI_offset=0x84000
    rem 6.5MiB bound
    set         SR1_offset=0x67FF00
    set         fs0_offset=0x67FFE0
    set         crc_offset=0x680000
    rem real end of flash, remainder for customer use
    rem flash end        0x01800000
  )^
  else (
    rem IB is concatenated
    set          EVE_offset=0x20000
    set           AI_offset=0x24000
    set  mot_flash_offset=0x1000000
    set crc_flash_offset=0x01800000
  )


echo.
rem --------------------------------------

echo Step 3: create infoblock, security region 1, security region 2 and flash status 0 images
set stepno=3
echo make infoblock image
rem run perl script to find the infoblock address in %BUILDCONFIG% arm-m_0.map
rem this generates infoblock_details.bat and hex6x_infoblock.cmd
c:\tools\perl\v5.6\bin\perl.exe ..\postprocess\search_mapfile_common.pl %APP_PROJECT_NAME% %BUILDCONFIG%
if ERRORLEVEL 1 (
  echo search_mapfile_common.pl failed & exit /b 1
)
call infoblock_details.bat infoblock_addr infoblock_length infoblock_end

%post_process_dir%\hex470.exe hex6x_infoblock.cmd %arm_m_0_outfile%

rem srec_cat: Intel to Motorola Format
%srec_cat% infoblock.asc -Ascii-Hex -crop %infoblock_addr% %infoblock_end% -offset -%infoblock_addr% -Output infoblock.bin -Binary
if ERRORLEVEL 1 (
  echo -Output infoblock.bin failed & exit /b 1
)

echo make specificdatablock image
c:\tools\perl\v5.6\bin\perl.exe ..\postprocess\search_mapfile_specificdatablock.pl %APP_PROJECT_NAME% %BUILDCONFIG%
if ERRORLEVEL 1 (
  echo search_mapfile_specificdatablock.pl failed & exit /b 1
)
call specificdatablock_details.bat infoblock_addr infoblock_length infoblock_end

%post_process_dir%\hex470.exe hex6x_specificdatablock.cmd %arm_m_0_outfile%

rem srec_cat: Intel to Motorola Format
%srec_cat% specificdatablock.asc -Ascii-Hex -crop %infoblock_addr% %infoblock_end% -offset -%infoblock_addr% -Output specificdatablock.bin -Binary
if ERRORLEVEL 1 (
  echo -Output infoblock.bin failed & exit /b 1
)

echo.
rem --------------------------------------

if not exist %build_dir%\mot mkdir %build_dir%\mot

rem Step4: add the infoblock, security blocks etc
echo Step4: Adding infoblock etc
set stepno=4
rem this step always copies a standardised output file to %build_dir%\mot\soc_allCores.bin
rem the intermediate file used to generate the mot file has a different name depending on how it has been generated
rem this is of course quite confusing

  rem Info: Next two lines to be used if the Info Block should be at the end of the bin file.
  rem       This was default until 21.06.2013. Change asked from boot loader team.
  rem %pp_cat% SOC_allCores.tiimage infoblock.bin > APP_image_withIB.bin
  rem if exist APP_image_withIB.bin    copy APP_image_withIB.bin %build_dir%\mot\soc_allcores.bin
  rem output for step5: APP_image_withIB.bin

  rem Info: Next lines to be used if the Info Block should be behind the SFBL.

  if "%SOCTYPE%" == "low" (
     %srec_cat% ^
      PreSBL_Standalone.bin -Binary -offset %PRESBL_offset% ^
      SBLBE.rprc -Binary -offset %SBL_offset% ^
      infoblock.bin -Binary -offset %IB_offset% ^
      EveMemTestBE.rprc -Binary -offset %EVE_offset% ^
      AppImage_BE.mfc -Binary -offset %AI_offset% ^
      -Output APP_image_withIB.bin -Binary
    if ERRORLEVEL 1 (
      echo srec_cat -Output APP_image_withIB.bin failed & exit /b 1
    )
	
    rem Vision low SOC project ARS441 mot file needs to include PreSBL in addition to SBL and application image
    rem For ARS441 needs byte swapping in mot file is necessary because RaceRunner and SOC uses different endian type formats    
    if "%APP_PROJECT_NAME%" == "ars441" (
      %srec_cat% ^
      PreSBL_Standalone.bin -Binary -Byte-Swap 4 -offset %ars441_PRESBL_offset% ^
      SBLBE.rprc -Binary -Byte-Swap 4 -offset %ars441_SBL_offset% ^
      infoblock.bin -Binary -offset %ars441_IB_offset% ^
      EveMemTestBE.rprc -Binary -Byte_Swap 4 -offset %ars441_EVE_offset% ^
      AppImage_BE.mfc -Binary -Byte-Swap 4 -offset %ars441_AI_offset% ^
      -Output APP_image_withIB_swapped.bin -Binary

      if ERRORLEVEL 1 (
        echo srec_cat -Output APP_image_withIB_swapped.bin failed & exit /b 1
      )
    )	
	
    copy APP_image_withIB.bin %build_dir%\mot\soc_allcores.bin
    rem output for step5: APP_image_withIB.bin
    rem output for step5: APP_image_withIB_swapped.bin

  )^
  else if "%SOCTYPE%" == "high" (
    if "%PRODUCT%" == "mfc431" (
      rem first generate soc_allcores.bin using the big-endian images
      rem for the binary file we generate using unswapped images
      %srec_cat% ^
        SBL.tiimage -Binary -exclude %IB_offset% %SR2_end% ^
        infoblock.bin -Binary -Byte-Swap 4 -offset %IB_offset% ^
        specificdatablock.bin -Binary -Byte-Swap 4 -offset %SR2_offset% ^
        EveMemTestBE.rprc -Binary -offset %EVE_offset% ^
        AppImage_BE.mfc -Binary -offset %AI_offset% ^
        -Output APP_image_withIB.bin -Binary
      if ERRORLEVEL 1 (
        echo srec_cat -Output APP_image_withIB.bin failed & exit /b 1
      )
      copy APP_image_withIB.bin %build_dir%\mot\SOC_allCores.bin
      
      rem for the mot file, we generate using swapped images, then must calculate and add crc
      %srec_cat% ^
        SBL.tiimage -Binary -Byte-Swap 4 -exclude %IB_offset% %SR2_end% ^
        infoblock.bin -Binary -offset %IB_offset% ^
        specificdatablock.bin -Binary -offset %SR2_offset% ^
        EveMemTestBE.rprc -Binary -Byte-Swap 4 -offset %EVE_offset% ^
        AppImage_BE.mfc -Binary -Byte-Swap 4 -offset %AI_offset% ^
        -Output SBL_IB_SR2_AI_SR1_swapped.bin -Binary
      if ERRORLEVEL 1 (
        echo srec_cat -Output SBL_IB_SR2_AI_SR1_swapped.bin failed & exit /b 1
      )
    )^
    else if "%PRODUCT%" == "hfl110" (
      rem exactly as mfc431
      rem first generate soc_allcores.bin using the big-endian images
      rem for the binary file we generate using unswapped images
      %srec_cat% ^
        SBL.tiimage -Binary -exclude %IB_offset% %SR2_end% ^
        infoblock.bin -Binary -Byte-Swap 4 -offset %IB_offset% ^
        EveMemTestBE.rprc -Binary -offset %EVE_offset% ^
        AppImage_BE.mfc -Binary -offset %AI_offset% ^
        -Output APP_image_withIB.bin -Binary
      if ERRORLEVEL 1 (
        echo srec_cat -Output APP_image_withIB.bin failed & exit /b 1
      )
      copy APP_image_withIB.bin %build_dir%\mot\SOC_allCores.bin
      
      rem for the mot file, we generate using swapped images, then must calculate and add crc
      %srec_cat% ^
        SBL.tiimage -Binary -Byte-Swap 4 -exclude %IB_offset% %SR2_end% ^
        infoblock.bin -Binary -offset %IB_offset% ^
        EveMemTestBE.rprc -Binary -Byte-Swap 4 -offset %EVE_offset% ^
        AppImage_BE.mfc -Binary -Byte-Swap 4 -offset %AI_offset% ^
        -Output SBL_IB_SR2_AI_SR1_swapped.bin -Binary
      if ERRORLEVEL 1 (
        echo srec_cat -Output SBL_IB_SR2_AI_SR1_swapped.bin failed & exit /b 1
      )
    )^
    else (
      rem first generate soc_allcores.bin using the big-endian images
      rem this is what we did before adding the security blocks
      rem %srec_cat% SBL_image_withIB.tiimage -Binary AppImage_BE.mfc -Binary -offset %AI_offset% -Output APP_image_withIB.bin -Binary
      rem if exist APP_image_withIB.bin    copy APP_image_withIB.bin %build_dir%\mot\soc_allcores.bin
      rem rem output for step5: APP_image_withIB.bin

      rem convert extra flash areas to binary
      %srec_cat% %flash_file_data%\SecurityRegion2.asc -Ascii-Hex -Output SecurityRegion2.bin -Binary
      %srec_cat% %flash_file_data%\SecurityRegion1.asc -Ascii-Hex -Output SecurityRegion1.bin -Binary
      %srec_cat% %flash_file_data%\FlashStatus0.asc -Ascii-Hex -Output FlashStatus0.bin -Binary

      echo generating SBL_IB_SR2_AI_SR1_fs0.bin, %build_dir%\mot\SOC_allCores.bin
      rem for the binary file we generate using unswapped images and add fs0 straight away
      rem exclude infoblock and SR2 area within SBL area to avoid contradictory error due to overlapping areas
      rem SBL binary contains addresses before and after infoblock and SR2
      %srec_cat% ^
        SBL.tiimage -Binary -exclude %IB_offset% %SR2_end% ^
        infoblock.bin -Binary -Byte-Swap 4 -offset %IB_offset% ^
        SecurityRegion2.bin -Binary -Byte-Swap 4 -offset %SR2_offset% ^
        EveMemTestBE.rprc -Binary -offset %EVE_offset% ^
        AppImage_BE.mfc -Binary -offset %AI_offset% ^
        SecurityRegion1.bin -Binary -Byte-Swap 4 -offset %SR1_offset% ^
        FlashStatus0.bin -Binary -Byte-Swap 4 -offset %fs0_offset% ^
        -Output SBL_IB_SR2_AI_SR1_fs0.bin -Binary
      if ERRORLEVEL 1 (
        echo srec_cat -Output SBL_IB_SR2_AI_SR1_fs0.bin failed & exit /b 1
      )
      copy SBL_IB_SR2_AI_SR1_fs0.bin %build_dir%\mot\SOC_allCores.bin

      rem for the mot file, we generate using swapped images, then must calculate and add crc, then add fs0:
      rem the SBL and application image (AppImage_BE.mfc) have been swapped into big endian format as the VME SPI bus swaps the bytes on reading them back.
      rem the VH28 QSPI does not do this swapping so we have to swap the SBL and application image *back* into little endian format before they are written
      rem exclude infoblock and SR2 area within SBL area to avoid contradictory error due to overlapping areas
      rem SBL binary contains addresses before and after infoblock and SR2
      echo generating SBL_IB_SR2_AI_SR1_swapped.bin
      %srec_cat% ^
        SBL.tiimage -Binary -Byte-Swap 4 -exclude %IB_offset% %SR2_end% ^
        infoblock.bin -Binary -offset %IB_offset% ^
        SecurityRegion2.bin -Binary -offset %SR2_offset% ^
        EveMemTestBE.rprc -Binary -Byte-Swap 4 -offset %EVE_offset% ^
        AppImage_BE.mfc -Binary -Byte-Swap 4 -offset %AI_offset% ^
        SecurityRegion1.bin -Binary -offset %SR1_offset% ^
        -Output SBL_IB_SR2_AI_SR1_swapped.bin -Binary
      if ERRORLEVEL 1 (
        echo srec_cat -Output SBL_IB_SR2_AI_SR1_swapped.bin failed & exit /b 1
      )
      rem output for step5: SBL_IB_SR2_AI_SR1_swapped.bin
      rem output for step7: SBL_IB_SR2_AI_SR1_fs0.bin
    )
  )^
  else (
    rem empty else
  )

rem Check filesize of the binary file (has to be fit into SDF)
set temp_file_path=%build_dir%\mot\tempfile.txt
type nul > !temp_file_path!
if %checkBinarySize% == 1 (
echo.
  echo Step 4.1: Check filesize of binary
  set stepno=4
)
set binary_path=%build_dir%\mot\soc_allcores.bin

if "%APP_PROJECT_NAME%" == "mfc431" (
  set config_file_path=%source_config_dir%\MEMMAP_DPU\memory_soc0.cmd
) else if "%APP_PROJECT_NAME%" == "mfc431ta19" (
  set config_file_path=%source_config_dir%\MEMMAP_DPU\memory_soc0.cmd
) else if "%APP_PROJECT_NAME%" == "mfc431lo19" (
  set config_file_path=%source_config_dir%\MEMMAP_DPU\memory_soc0.cmd
) else if "%APP_PROJECT_NAME%" == "mfc431lo20" (
  set config_file_path=%source_config_dir%\MEMMAP_DPU\memory_soc0.cmd
) else if "%APP_PROJECT_NAME%" == "ars441" (
  set config_file_path=%source_config_dir%\MEMMAP_DPU\memory_soc0.cmd
) else if "%APP_PROJECT_NAME%" == "hfl110" (
  set config_file_path=%source_config_dir%\MEMMAP_DPU\memory_soc0.cmd
) else if "%APP_PROJECT_NAME%" == "hfl110ta10" (
  set config_file_path=%source_config_dir%\MEMMAP_DPU\memory_soc0.cmd
) else if "%APP_PROJECT_NAME%" == "mfc431sc19" (
  set config_file_path=%source_config_dir%\MEMMAP_DPU\memory_soc0.cmd
) else if "%APP_PROJECT_NAME%" == "mfc431sw19" (
  set config_file_path=%source_config_dir%\MEMMAP_DPU\memory_soc0.cmd
) else if "%APP_PROJECT_NAME%" == "mfc431va10" (
  set config_file_path=%source_config_dir%\MEMMAP_DPU\memory_soc0.cmd
) else if "%APP_PROJECT_NAME%" == "mfc431va21" (
  set config_file_path=%source_config_dir%\MEMMAP_DPU\memory_soc0.cmd
) else if "%APP_PROJECT_NAME%" == "mfc431bd10" (
  set config_file_path=%source_config_dir%\MEMMAP_DPU\memory_soc0.cmd
) else (
  set config_file_path=%source_config_dir%\memory_soc0.cmd
)

echo PFAD: %config_file_path%

set MissingValue=0
set /A startAddressOfSoCAppl=0
set /A endAddressOfSoCAppl=0
rem parse memory_cmd.bat file and get start and end addresses of the SDF
if %checkBinarySize% == 1 (
  call %PYTHON_PATH%\python.exe ../postprocess/parse_memory_cmd_file.py !config_file_path! u_MEM_STA_SDF_SOC_APP !temp_file_path!

  if ERRORLEVEL 1 (
    echo.
    echo *** Parsing memory command file for start address failed ***
    exit /b 1
  )

  set /p temp_address= < !temp_file_path! 
  set /A startAddressOfSoCAppl= !temp_address!
  call %PYTHON_PATH%\python.exe ../postprocess/parse_memory_cmd_file.py !config_file_path! u_MEM_END_SDF_SOC_APP !temp_file_path! 

  if ERRORLEVEL 1 (
    echo.
    echo *** Parsing memory command file for end address failed ***
    exit /b 1
  )

  set /p temp_address= < !temp_file_path! 
  set /A endAddressOfSoCAppl= !temp_address!
rem  del %temp_file_path%
  rem Check if the symbol for the configuration is found in memory map
  if %startAddressOfSoCAppl% == 0 ( set MissingValue=1 
  )^
  else if %endAddressOfSoCAppl% == 0 ( set MissingValue=1
  )^
  else ( set MissingValue=0
  )
  set /A maxfilesize=!endAddressOfSoCAppl!-!startAddressOfSoCAppl!
  if %MissingValue% == 1 (
    echo The configuration symbole "u_MEM_STA_SDF_SOC_APP" or u_MEM_END_SDF_SOC_APP" is missing
    echo The symbole contains the max size in byte of the SoC Application in the SDF
    echo Please add this symbole to the "memory_soc.cmd" file
    goto ERRORLINE 
  )
  rem Calculate and print binary size to screen
  echo The max. configured binary size is !maxfilesize! bytes.
  for %%A in (%binary_path%) do set filesize=%%~zA
  echo The filesize of the binary "SoC_allCores.bin" is !filesize! bytes.
  if !filesize! GTR !maxfilesize! (
    echo The generated binary "SoC_allCores.bin" is too large.
    goto ERRORLINE
  )
  echo.
) 
del !temp_file_path!

rem Check if Binary does also fit into FLASH_CODE Area in SDF
call %PYTHON_PATH%\python.exe ../postprocess/checkImageSize.py %PROJECT%
if ERRORLEVEL 1 (
    echo.
    echo *** The generated binary "SoC_allCores.bin" is too large to fit into FLASH_CODE section  ***
    goto ERRORLINE
  )
  
rem --------------------------------------

echo Step5: Create the mot file (SOC_no_crc.mot)
set stepno=5
if "%SOCTYPE%" == "high" (
  %srec_cat% SBL_IB_SR2_AI_SR1_swapped.bin -Binary -Offset %mot_flash_offset% -Output SOC_no_crc.mot -Motorola -Execution_Start_Address 0
  if ERRORLEVEL 1 (
    echo srec_cat -Output SOC_no_crc.mot failed & exit /b 1
  )
  if "%SCRIPT%" == "sx" (
    if "%PRODUCT%" == "" (
      rem To be used if build needs an absolute mot file for the production needle flasher
      rem We only need to generate this with the sx script
      rem Only difference is no offset here
      %srec_cat% SBL_IB_SR2_AI_SR1_swapped.bin -Binary -Output SOC_no_crc_abs.mot -Motorola -Execution_Start_Address 0
      if ERRORLEVEL 1 (
        echo srec_cat -Output SOC_no_crc_abs.mot failed & exit /b 1
      )
    )
  )  
)^
else if "%APP_PROJECT_NAME%" == "ars441" (
    %srec_cat% APP_image_withIB_swapped.bin -Binary -Offset %ars441_mot_flash_offset% -Output SOC_no_crc.mot -Motorola -Execution_Start_Address 0
  )^
  else (
    %srec_cat% APP_image_withIB.bin -Binary -Offset %mot_flash_offset% -Output SOC_no_crc.mot -Motorola -Execution_Start_Address 0
  )
  if ERRORLEVEL 1 (
    echo srec_cat -Output SOC_no_crc.mot failed & exit /b 1
  )
)

echo.
echo Step6: Add the crc to the mot file
set stepno=6

if exist tmp_crc.mot del tmp_crc.mot
echo %post_process_dir%\crc_pp.exe SOC_no_crc.mot %crc_flash_offset% tmp_crc 2
%post_process_dir%\crc_pp.exe SOC_no_crc.mot %crc_flash_offset% tmp_crc 2
if not exist tmp_crc.mot (
	echo ERROR: CRC patch rel
  goto ERRORLINE
)
if "%SCRIPT%" == "sx" (
  if "%PRODUCT%" == "" (
    rem To be used if build needs an absolute mot file for the production needle flasher
    rem We only need to generate this with the sx script
    rem Only difference is no offset here
    if exist tmp_crc_abs.mot del tmp_crc_abs.mot
    echo %post_process_dir%\crc_pp.exe SOC_no_crc_abs.mot %crc_offset% tmp_crc_abs 2
    %post_process_dir%\crc_pp.exe SOC_no_crc_abs.mot %crc_offset% tmp_crc_abs 2
    if not exist tmp_crc_abs.mot (
      echo ERROR: CRC patch abs
      goto ERRORLINE
    )
  )
)

echo.
echo Step7: Copy SoC mot file for %APP_PROJECT_NAME%
set stepno=7
if "%SOCTYPE%" == "high" (
  if "%PRODUCT%" == "mfc431" (
    if %DEBUG% == 0 (
        rem Copy the latest mot file without timestamp info also to the build directory
        if exist %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.mot (
            del %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.mot
        )
        copy tmp_crc.mot %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.mot
        rem Copy the latest all cores bin file without timestamp info also to the build directory
        if exist %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.bin (
            del %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.bin
        )
        copy APP_image_withIB.bin %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.bin
        
        if "%SCRIPT%" == "sx" (
            echo Copy Overall mot file for %APP_PROJECT_NAME% - %PRODUCT%
            copy tmp_crc.mot %build_dir%\mot\%tsnow%_%BUILDCONFIG%_%APP_PROJECT_NAME%_SOC.mot
            copy APP_image_withIB.bin %build_dir%\mot\%tsnow%_%BUILDCONFIG%_%APP_PROJECT_NAME%_SOC.bin
            attrib -r %eng_deliverables_dir%\DPU\%APP_PROJECT_NAME%_SOC_rel.mot
            copy %build_dir%\mot\%tsnow%_%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.mot %eng_deliverables_dir%\DPU\%APP_PROJECT_NAME%_SOC_rel.mot
            attrib -r %eng_deliverables_dir%\DPU\%APP_PROJECT_NAME%_SOC_rel.bin
            copy %build_dir%\mot\%tsnow%_%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.bin %eng_deliverables_dir%\DPU\%APP_PROJECT_NAME%_SOC_rel.bin
        )
    ) 
  )^
  else if "%PRODUCT%" == "hfl110" (
    rem exactly as mfc431
    if %DEBUG% == 0 (
        rem Copy the latest mot file without timestamp info also to the build directory
        if exist %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.mot (
            del %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.mot
        )
        copy tmp_crc.mot %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.mot
        rem Copy the latest all cores bin file without timestamp info also to the build directory
        if exist %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.bin (
            del %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.bin
        )
        copy APP_image_withIB.bin %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.bin
    
        if "%SCRIPT%" == "sx" (
            echo Copy Overall mot file for %APP_PROJECT_NAME% - %PRODUCT%
            copy tmp_crc.mot %build_dir%\mot\%tsnow%_%BUILDCONFIG%_%APP_PROJECT_NAME%_SOC.mot
            copy APP_image_withIB.bin %build_dir%\mot\%tsnow%_%BUILDCONFIG%_%APP_PROJECT_NAME%_SOC.bin
            attrib -r %eng_deliverables_dir%\DPU\%APP_PROJECT_NAME%_SOC_rel.mot
            copy %build_dir%\mot\%tsnow%_%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.mot %eng_deliverables_dir%\DPU\%APP_PROJECT_NAME%_SOC_rel.mot
            attrib -r %eng_deliverables_dir%\DPU\%APP_PROJECT_NAME%_SOC_rel.bin
            copy %build_dir%\mot\%tsnow%_%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.bin %eng_deliverables_dir%\DPU\%APP_PROJECT_NAME%_SOC_rel.bin
        )
    ) 
  )^
  else (
    echo Adding flash status 0 and copy SoC mot file for %APP_PROJECT_NAME%
    %srec_cat% tmp_crc.mot -Motorola FlashStatus0.bin -Binary -offset %fs0_flash_offset% -Output tmp_crc_fs0.mot -Motorola
    if ERRORLEVEL 1 (
      echo srec_cat -Output tmp_crc_fs0.mot failed & exit /b 1
    )
    if %DEBUG% == 0 (  
        rem Copy the latest mot file without timestamp info also to the build directory
        if exist %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.mot (
            del %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.mot
        )
        copy tmp_crc_fs0.mot %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.mot
        rem Copy the latest all cores bin file without timestamp info also to the build directory
        if exist %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.bin (
            del %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.bin
        )
        copy SBL_IB_SR2_AI_SR1_fs0.bin %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.bin
    
        if "%SCRIPT%" == "sx" (
            copy tmp_crc_fs0.mot %build_dir%\mot\%tsnow%_%BUILDCONFIG%_%APP_PROJECT_NAME%_SOC.mot
            copy SBL_IB_SR2_AI_SR1_fs0.bin %build_dir%\mot\%tsnow%_%BUILDCONFIG%_%APP_PROJECT_NAME%_SOC.bin
            attrib -r %eng_deliverables_dir%\DPU\%APP_PROJECT_NAME%_SOC_rel.mot
            copy %build_dir%\mot\%tsnow%_%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.mot %eng_deliverables_dir%\DPU\%APP_PROJECT_NAME%_SOC_rel.mot
            attrib -r %eng_deliverables_dir%\DPU\%APP_PROJECT_NAME%_SOC_rel.bin
            copy %build_dir%\mot\%tsnow%_%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.bin %eng_deliverables_dir%\DPU\%APP_PROJECT_NAME%_SOC_rel.bin
      )
    )
  )
) ^
else (
  if %DEBUG% == 0 (
    rem Copy the latest mot file without timestamp info also to the build directory
    if exist %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.mot (
        del %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.mot
    )
    copy tmp_crc.mot %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.mot
    rem Copy the latest all cores bin file without timestamp info also to the build directory
    if exist %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.bin (
        del %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.bin
    )
    copy APP_image_withIB.bin %build_dir%\mot\%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.bin
  
    if "%SCRIPT%" == "sx" (
      echo Copy SoC mot file for %APP_PROJECT_NAME%
      copy tmp_crc.mot %build_dir%\mot\%tsnow%_%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.mot
      copy APP_image_withIB.bin %build_dir%\mot\%tsnow%_%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.bin
      attrib -r %eng_deliverables_dir%\DPU\%APP_PROJECT_NAME%_soc_rel.mot
      copy %build_dir%\mot\%tsnow%_%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.mot %eng_deliverables_dir%\DPU\%APP_PROJECT_NAME%_soc_rel.mot
      attrib -r %eng_deliverables_dir%\DPU\%APP_PROJECT_NAME%_soc_rel.bin
      copy %build_dir%\mot\%tsnow%_%BUILDCONFIG%_%APP_PROJECT_NAME%_soc.bin %eng_deliverables_dir%\DPU\%APP_PROJECT_NAME%_soc_rel.bin
    )
  )
)

rem Temporarily store the APP_PROJECT_NAME
set APP_PROJECT_NAME_TEMP_VAR=%APP_PROJECT_NAME%
if %APP_PROJECT_NAME% == MFC4T0 (
	rem Make lower case 
	set APP_PROJECT_NAME=mfc4t0
)

rem Restore the APP_PROJECT_NAME
set APP_PROJECT_NAME=%APP_PROJECT_NAME_TEMP_VAR%

goto step8
:delete_helper_files
echo Deleting helper files
if exist infoblock_details.bat            del /Q infoblock_details.bat
if exist hex6x_infoblock.cmd              del /Q hex6x_infoblock.cmd
if exist infoblock.asc                    del /Q infoblock.asc
if exist infoblock.bin                    del /Q infoblock.bin
if exist hex6xinfoblock.map               del /Q hex6xinfoblock.map

if exist specificdatablock_details.bat    del /Q specificdatablock_details.bat
if exist hex6x_specificdatablock.cmd      del /Q hex6x_specificdatablock.cmd
if exist specificdatablock.asc            del /Q specificdatablock.asc
if exist specificdatablock.bin            del /Q specificdatablock.bin
if exist hex6xspecificdatablock.map       del /Q hex6xspecificdatablock.map

if exist SecurityRegion1.bin       del /Q SecurityRegion1.bin
if exist SecurityRegion2.bin       del /Q SecurityRegion2.bin
if exist FlashStatus0.bin          del /Q FlashStatus0.bin

if exist tmp_crc.mot               del /Q tmp_crc.mot
if exist tmp_crc_fs0.mot           del /Q tmp_crc_fs0.mot
if exist tmp_crc.crc               del /Q tmp_crc.crc
if exist SOC_no_crc.mot            del /Q SOC_no_crc.mot

if exist tmp_crc_abs.mot           del /Q tmp_crc_abs.mot
if exist tmp_crc_fs0_abs.mot       del /Q tmp_crc_fs0_abs.mot
if exist tmp_crc_abs.crc           del /Q tmp_crc_abs.crc
if exist SOC_no_crc_abs.mot        del /Q SOC_no_crc_abs.mot

if exist CA8_0.tiimage             del /Q CA8_0.tiimage
if exist CA8_1.tiimage             del /Q CA8_1.tiimage
if exist DSP_0.tiimage             del /Q DSP_0.tiimage
if exist DSP_1.tiimage             del /Q DSP_1.tiimage
if exist M3VIDEO.tiimage           del /Q M3VIDEO.tiimage
if exist M3VPSS.tiimage            del /Q M3VPSS.tiimage
if exist ARP32_0.tiimage           del /Q ARP32_0.tiimage
if exist ARP32_1.tiimage           del /Q ARP32_1.tiimage
if exist PreSBL_Standalone.bin     del /Q PreSBL_Standalone.bin
if exist SBL.tiimage               del /Q SBL.tiimage
if exist SBL_swapped.tiimage       del /Q SBL_swapped.tiimage
if exist SBL_image_withIB.tiimage  del /Q SBL_image_withIB.tiimage
if exist SBL_with_Eve_and_IB.tiimage      del /Q SBL_with_Eve_and_IB.tiimage
if exist SBL_image_withIB_swapped.tiimage del /Q SBL_image_withIB_swapped.tiimage
if exist SBL.bin                   del /Q SBL.bin
if exist SBL_IB.bin                del /Q SBL_IB.bin
if exist SBL_IB_SR2.bin            del /Q SBL_IB_SR2.bin
if exist SBL_IB_SR2_AI.bin         del /Q SBL_IB_SR2_AI.bin
if exist SBL_IB_SR2_AI_SR1.bin     del /Q SBL_IB_SR2_AI_SR1.bin
if exist SBL_IB_SR2_AI_SR1_fs0.bin del /Q SBL_IB_SR2_AI_SR1_fs0.bin
if exist soc_allcores.bin          del /Q soc_allcores.bin
if exist SBL_swapped.tiimage       del /Q SBL_swapped.tiimage
if exist SBL_IB_SR2_AI_SR1_swapped.bin    del /Q SBL_IB_SR2_AI_SR1_swapped.bin
if exist SOC_allCores.tiimage      del /Q SOC_allCores.tiimage
if exist SOC_allCoresIB.tiimage    del /Q SOC_allCoresIB.tiimage
if exist APP_image_withIB.bin      del /Q APP_image_withIB.bin
if exist APP_image_withIB_swapped.bin     del /Q APP_image_withIB_swapped.bin
if exist AppImage_BE               del /Q AppImage_BE
if exist AppImage_BE.mfc           del /Q AppImage_BE.mfc
if exist AppImageDual_BE           del /Q AppImageDual_BE
if exist AppImageDual_BE.mfc       del /Q AppImageDual_BE.mfc
if exist EveMemTest.rprc           del /Q EveMemTest.rprc
if exist EveMemTestBE.rprc         del /Q EveMemTestBE.rprc
if exist SBL.rprc		           del /Q SBL.rprc
if exist SBLBE.rprc		           del /Q SBLBE.rprc
goto :eof

:step8
echo.
echo Step8: Delete the helper files
set stepno=8
call :delete_helper_files

echo.
echo *******************************************
echo   postproc DONE successfully
echo *******************************************

goto ENDE

:ERRORLINE
echo.
echo *******************************************
echo   postproc failed - ERROR in step %stepno%
echo *******************************************
exit /b 1

:ENDE

echo.
echo --- Done:  MulticorePostprocCommon.bat
