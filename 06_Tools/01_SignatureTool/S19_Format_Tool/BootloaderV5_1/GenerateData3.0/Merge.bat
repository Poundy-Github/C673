@echo ===============================================================================

SET BOOT_FILE=output\TOOL\Boot.s19
rem SET BOOT_FILE=output\TOOL\Boot.hex -intel

SET FBL_FILE=output\TOOL\FlashBootLoader.s19
rem SET FBL_FILE=output\TOOL\FlashBootLoader.hex -intel

SET APP_FILE=output\TOOL\Application.s19
rem SET APP_FILE=output\TOOL\Application.hex -intel

SET MERGED_FILE=output\TOOL\Merged.s19
rem SET MERGED_FILE=output\TOOL\Merged.hex -intel

SET APP_A_01_OTA_FILE=output\OTA\A_01_Application.s19
rem SET APP_A_01_OTA_FILE=output\OTA\A_01_Application.hex -intel

SET APP_A_02_OTA_FILE=output\OTA\A_02_Application.s19
rem SET APP_A_02_OTA_FILE=output\OTA\A_02_Application.hex -intel

SET APP_A_03_OTA_FILE=output\OTA\A_03_Application.s19
rem SET APP_A_03_OTA_FILE=output\OTA\A_03_Application.hex -intel

SET APP_A_04_OTA_FILE=output\OTA\A_04_Application.s19
rem SET APP_A_04_OTA_FILE=output\OTA\A_04_Application.hex -intel

SET APP_A_OTA_FILE=output\OTA\A_Application.s19
rem SET APP_A_OTA_FILE=output\OTA\A_Application.hex -intel

SET APP_B_01_OTA_FILE=output\OTA\B_01_Application.s19
rem SET APP_B_01_OTA_FILE=output\OTA\B_01_Application.hex -intel

SET APP_B_02_OTA_FILE=output\OTA\B_02_Application.s19
rem SET APP_B_02_OTA_FILE=output\OTA\B_02_Application.hex -intel

SET APP_B_03_OTA_FILE=output\OTA\B_03_Application.s19
rem SET APP_B_03_OTA_FILE=output\OTA\B_03_Application.hex -intel

SET APP_B_04_OTA_FILE=output\OTA\B_04_Application.s19
rem SET APP_B_04_OTA_FILE=output\OTA\B_04_Application.hex -intel

SET APP_B_OTA_FILE=output\OTA\B_Application.s19
rem SET APP_B_OTA_FILE=output\OTA\B_Application.hex -intel

SET BLU_OTA_FILE=output\OTA\01_BootLoaderUpdater.s19
rem SET BLU_OTA_FILE=output\OTA\01_BootLoaderUpdater.hex -intel

SET FBL_OTA_FILE=output\OTA\02_FlashBootLoader.s19
rem SET FBL_OTA_FILE=output\OTA\02_FlashBootLoader.hex -intel

SET BLU_FBL_OTA_FILE=output\OTA\FlashBootLoader.s19
rem SET BLU_FBL_OTA_FILE=output\OTA\FlashBootLoader.hex -intel

SET OUT_FILE_OPT=-address-length=4 -obs=32 -disable=data-count -Execution_Start_Address=0x0000
rem SET OUT_FILE_OPT=

srec_cat.exe ^
 %BOOT_FILE% ^
 %FBL_FILE% ^
 %APP_FILE% ^
 -o %MERGED_FILE% %OUT_FILE_OPT%

srec_cat.exe ^
 %APP_A_01_OTA_FILE% ^
 %APP_A_02_OTA_FILE% ^
 %APP_A_03_OTA_FILE% ^
 %APP_A_04_OTA_FILE% ^
 -o %APP_A_OTA_FILE% %OUT_FILE_OPT%

srec_cat.exe ^
 %APP_B_01_OTA_FILE% ^
 %APP_B_02_OTA_FILE% ^
 %APP_B_03_OTA_FILE% ^
 %APP_B_04_OTA_FILE% ^
 -o %APP_B_OTA_FILE% %OUT_FILE_OPT%

srec_cat.exe ^
 %BLU_OTA_FILE% ^
 %FBL_OTA_FILE% ^
 -o %BLU_FBL_OTA_FILE% %OUT_FILE_OPT%

@echo ===============================================================================

rem pause