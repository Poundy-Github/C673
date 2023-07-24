@echo ===============================================================================

SET BLU_ORG_FILE=input\TRICORE_TC38XQ_BootLoaderUpdater.mot
rem SET BLU_ORG_FILE=input\TRICORE_TC38XQ_BootLoaderUpdater.hex -intel

SET BLU_FILE=output\TOOL\BootLoaderUpdater.s19
rem SET BLU_FILE=output\TOOL\BootLoaderUpdater.hex -intel

SET BLU_OTA_FILE=output\OTA\01_BootLoaderUpdater.s19
rem SET BLU_OTA_FILE=output\OTA\01_BootLoaderUpdater.hex -intel

SET OUT_FILE_OPT=-address-length=4 -obs=32 -disable=data-count -Execution_Start_Address=0x0000
rem SET OUT_FILE_OPT=

SET BLU_SAMPLE_SIZE=0x10000
SET BLU_SAMPLE_START=0x800A4100
SET BLU_SAMPLE_END=0x800B4100

md temp

srec_cat.exe ^
 %BLU_ORG_FILE% -crop %BLU_SAMPLE_START% %BLU_SAMPLE_END% -fill 0x00 %BLU_SAMPLE_START% %BLU_SAMPLE_END% -offset -%BLU_SAMPLE_START% ^
 -o temp\BootLoaderUpdaterSample.bin -binary

signature.exe -i temp\BootLoaderUpdaterSample.bin -o temp\BootLoaderUpdaterSampleSignature.bin

srec_cat.exe ^
 -generate 0x00 0x04 -constant-l-e 0x5AA5A55A 4 ^
 -generate 0x04 0x08 -constant 0x00 ^
 -generate 0x08 0x0C -constant-l-e %BLU_SAMPLE_START% 4 ^
 -generate 0x0C 0x10 -constant-l-e %BLU_SAMPLE_SIZE% 4 ^
 temp\BootLoaderUpdaterSampleSignature.bin -binary -offset 0x10 ^
 %BLU_ORG_FILE% -crop 0x800A4040 0x800C0000 -fill 0x00 0x800A4040 0x800C0000 -offset -0x800A4020 ^
 -o temp\BootLoaderUpdater.bin -binary

signature.exe -i temp\BootLoaderUpdater.bin -o temp\BootLoaderUpdaterSignature.bin

srec_cat.exe ^
 -generate 0x800A0000 0x800A0020 -repeat-data 0x5A 0xA5 0xA5 0x5A ^
 -generate 0x800A0020 0x800A4000 -constant 0x00 ^
 -generate 0x800A4000 0x800A4004 -constant-l-e 0x5AA5A55A 4 ^
 -generate 0x800A4004 0x800A4010 -constant 0x00 ^
 temp\BootLoaderUpdaterSignature.bin -binary -offset 0x800A4010 ^
 -generate 0x800A4020 0x800A4024 -constant-l-e 0x5AA5A55A 4 ^
 -generate 0x800A4024 0x800A4028 -constant 0x00 ^
 -generate 0x800A4028 0x800A402C -constant-l-e %BLU_SAMPLE_START% 4 ^
 -generate 0x800A402C 0x800A4030 -constant-l-e %BLU_SAMPLE_SIZE% 4 ^
 temp\BootLoaderUpdaterSampleSignature.bin -binary -offset 0x800A4030 ^
 %BLU_ORG_FILE% -crop 0x800A4040 0x800C0000 -fill 0x00 0x800A4040 0x800C0000 ^
 -o %BLU_FILE% %OUT_FILE_OPT%

srec_cat.exe ^
 %BLU_FILE% -crop 0x800A4000 0x800C0000 ^
 -o %BLU_OTA_FILE% %OUT_FILE_OPT%

rd /s /q temp

@echo ===============================================================================

rem pause