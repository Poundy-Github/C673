@echo ===============================================================================

SET FBL_ORG_FILE=input\TRICORE_TC38XQ_FlashBootLoader.mot
rem SET FBL_ORG_FILE=input\TRICORE_TC38XQ_FlashBootLoader.hex -intel

SET FBL_FILE=output\TOOL\FlashBootLoader.s19
rem SET FBL_FILE=output\TOOL\FlashBootLoader.hex -intel

SET FBL_FD_FILE=output\OTA\FlashDriver.s19
rem SET FBL_FD_FILE=output\OTA\FlashDriver.hex -intel

SET FBL_OTA_FILE=output\OTA\02_FlashBootLoader.s19
rem SET FBL_OTA_FILE=output\OTA\02_FlashBootLoader.hex -intel

SET OUT_FILE_OPT=-address-length=4 -obs=32 -disable=data-count -Execution_Start_Address=0x0000
rem SET OUT_FILE_OPT=

SET FBL_SAMPLE_SIZE=0x10000
SET FBL_SAMPLE_START=0x80064100
SET FBL_SAMPLE_END=0x80074100

md temp

srec_cat.exe ^
 %FBL_ORG_FILE% -crop %FBL_SAMPLE_START% %FBL_SAMPLE_END% -fill 0x00 %FBL_SAMPLE_START% %FBL_SAMPLE_END% -offset -%FBL_SAMPLE_START% ^
 -o temp\FlashBootLoaderSample.bin -binary

signature.exe -i temp\FlashBootLoaderSample.bin -o temp\FlashBootLoaderSampleSignature.bin

srec_cat.exe ^
 -generate 0x00 0x04 -constant-l-e 0x5AA5A55A 4 ^
 -generate 0x04 0x08 -constant 0x00 ^
 -generate 0x08 0x0C -constant-l-e %FBL_SAMPLE_START% 4 ^
 -generate 0x0C 0x10 -constant-l-e %FBL_SAMPLE_SIZE% 4 ^
 temp\FlashBootLoaderSampleSignature.bin -binary -offset 0x10 ^
 %FBL_ORG_FILE% -crop 0x80064040 0x800A0000 -fill 0x00 0x80064040 0x800A0000 -offset -0x80064020 ^
 -o temp\FlashBootLoader.bin -binary

signature.exe -i temp\FlashBootLoader.bin -o temp\FlashBootLoaderSignature.bin

srec_cat.exe ^
 -generate 0x80060000 0x80060020 -repeat-data 0x5A 0xA5 0xA5 0x5A ^
 -generate 0x80060020 0x80064000 -constant 0x00 ^
 -generate 0x80064000 0x80064004 -constant-l-e 0x5AA5A55A 4 ^
 -generate 0x80064004 0x80064010 -constant 0x00 ^
 temp\FlashBootLoaderSignature.bin -binary -offset 0x80064010 ^
 -generate 0x80064020 0x80064024 -constant-l-e 0x5AA5A55A 4 ^
 -generate 0x80064024 0x80064028 -constant 0x00 ^
 -generate 0x80064028 0x8006402C -constant-l-e %FBL_SAMPLE_START% 4 ^
 -generate 0x8006402C 0x80064030 -constant-l-e %FBL_SAMPLE_SIZE% 4 ^
 temp\FlashBootLoaderSampleSignature.bin -binary -offset 0x80064030 ^
 %FBL_ORG_FILE% -crop 0x80064040 0x800A0000 -fill 0x00 0x80064040 0x800A0000 ^
 -o %FBL_FILE% %OUT_FILE_OPT%

srec_cat.exe ^
 %FBL_FILE% -crop 0x80064000 0x800A0000 -offset 0x60000 ^
 -o %FBL_OTA_FILE% %OUT_FILE_OPT%

srec_cat.exe ^
 %FBL_ORG_FILE% -crop 0x70000020 0x70001000 -fill 0x00 0x70000020 0x70001000 -offset -0x70000020 ^
 -o temp\FlashDriver.bin -binary

signature.exe -i temp\FlashDriver.bin -o temp\FlashDriverSignature.bin

srec_cat.exe ^
 -generate 0x70000000 0x70000004 -constant-l-e 0x5AA5A55A 4 ^
 -generate 0x70000004 0x70000010 -constant 0x00 ^
 temp\FlashDriverSignature.bin -binary -offset 0x70000010 ^
 %FBL_ORG_FILE% -crop 0x70000020 0x70001000 -fill 0x00 0x70000020 0x70001000 ^
 -o %FBL_FD_FILE% %OUT_FILE_OPT%

rd /s /q temp

@echo ===============================================================================

rem pause