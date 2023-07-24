@echo ===============================================================================

SET APP_A_ORG_FILE=input\ApplicationA.mot
rem SET APP_A_ORG_FILE=input\TRICORE_TC38XQ_Application_A.hex -intel

SET APP_B_ORG_FILE=input\ApplicationB.mot
rem SET APP_B_ORG_FILE=input\TRICORE_TC38XQ_Application_B.hex -intel

SET APP_FILE=output\TOOL\Application.s19
rem SET APP_FILE=output\TOOL\Application.hex -intel

SET APP_A_01_OTA_FILE=output\OTA\A_01_Application.s19
rem SET APP_A_01_OTA_FILE=output\OTA\A_01_Application.hex -intel

SET APP_A_02_OTA_FILE=output\OTA\A_02_Application.s19
rem SET APP_A_02_OTA_FILE=output\OTA\A_02_Application.hex -intel

SET APP_A_03_OTA_FILE=output\OTA\A_03_Application.s19
rem SET APP_A_03_OTA_FILE=output\OTA\A_03_Application.hex -intel

SET APP_A_04_OTA_FILE=output\OTA\A_04_Application.s19
rem SET APP_A_04_OTA_FILE=output\OTA\A_04_Application.hex -intel

SET APP_B_01_OTA_FILE=output\OTA\B_01_Application.s19
rem SET APP_B_01_OTA_FILE=output\OTA\B_01_Application.hex -intel

SET APP_B_02_OTA_FILE=output\OTA\B_02_Application.s19
rem SET APP_B_02_OTA_FILE=output\OTA\B_02_Application.hex -intel

SET APP_B_03_OTA_FILE=output\OTA\B_03_Application.s19
rem SET APP_B_03_OTA_FILE=output\OTA\B_03_Application.hex -intel

SET APP_B_04_OTA_FILE=output\OTA\B_04_Application.s19
rem SET APP_B_04_OTA_FILE=output\OTA\B_04_Application.hex -intel

SET OUT_FILE_OPT=-address-length=4 -obs=32 -disable=data-count -Execution_Start_Address=0x0000
rem SET OUT_FILE_OPT=

SET APP_SAMPLE_SIZE=0x20000
SET APP_A_SAMPLE_START=0x80106000
SET APP_A_SAMPLE_END=0x80126000
SET APP_B_SAMPLE_START=0x80206000
SET APP_B_SAMPLE_END=0x80226000

md temp

srec_cat.exe ^
 %APP_A_ORG_FILE% -crop %APP_A_SAMPLE_START% %APP_A_SAMPLE_END% -fill 0x00 %APP_A_SAMPLE_START% %APP_A_SAMPLE_END% -offset -%APP_A_SAMPLE_START% ^
 -o temp\A_ApplicationSample.bin -binary

signature.exe -i temp\A_ApplicationSample.bin -o temp\A_ApplicationSampleSignature.bin

srec_cat.exe ^
 -generate 0x00 0x04 -constant-l-e 0x5AA5A55A 4 ^
 -generate 0x04 0x08 -constant 0x00 ^
 -generate 0x08 0x0C -constant-l-e %APP_A_SAMPLE_START% 4 ^
 -generate 0x0C 0x10 -constant-l-e %APP_SAMPLE_SIZE% 4 ^
 temp\A_ApplicationSampleSignature.bin -binary -offset 0x10 ^
 %APP_A_ORG_FILE% -crop 0x80104040 0x80200000 -fill 0x00 0x80104040 0x80200000 -offset -0x80104020 ^
 %APP_A_ORG_FILE% -crop 0x80300000 0x80480000 -fill 0x00 0x80300000 0x80480000 -offset -0x80204020 ^
 %APP_A_ORG_FILE% -crop 0x80600000 0x80780000 -fill 0x00 0x80600000 0x80780000 -offset -0x80384020 ^
 %APP_A_ORG_FILE% -crop 0x80900000 0x80980000 -fill 0x00 0x80900000 0x80980000 -offset -0x80504020 ^
 -o temp\A_Application.bin -binary

signature.exe -i temp\A_Application.bin -o temp\A_ApplicationSignature.bin

srec_cat.exe ^
 %APP_B_ORG_FILE% -crop %APP_B_SAMPLE_START% %APP_B_SAMPLE_END% -fill 0x00 %APP_B_SAMPLE_START% %APP_B_SAMPLE_END% -offset -%APP_B_SAMPLE_START% ^
 -o temp\B_ApplicationSample.bin -binary

signature.exe -i temp\B_ApplicationSample.bin -o temp\B_ApplicationSampleSignature.bin

srec_cat.exe ^
 -generate 0x00 0x04 -constant-l-e 0x5AA5A55A 4 ^
 -generate 0x04 0x08 -constant 0x00 ^
 -generate 0x08 0x0C -constant-l-e %APP_B_SAMPLE_START% 4 ^
 -generate 0x0C 0x10 -constant-l-e %APP_SAMPLE_SIZE% 4 ^
 temp\B_ApplicationSampleSignature.bin -binary -offset 0x10 ^
 %APP_B_ORG_FILE% -crop 0x80204040 0x80300000 -fill 0x00 0x80204040 0x80300000 -offset -0x80204020 ^
 %APP_B_ORG_FILE% -crop 0x80480000 0x80600000 -fill 0x00 0x80480000 0x80600000 -offset -0x80384020 ^
 %APP_B_ORG_FILE% -crop 0x80780000 0x80900000 -fill 0x00 0x80780000 0x80900000 -offset -0x80504020 ^
 %APP_B_ORG_FILE% -crop 0x80980000 0x80A00000 -fill 0x00 0x80980000 0x80A00000 -offset -0x80584020 ^
 -o temp\B_Application.bin -binary

signature.exe -i temp\B_Application.bin -o temp\B_ApplicationSignature.bin

srec_cat.exe ^
 -generate 0x80100000 0x80100020 -repeat-data 0x5A 0xA5 0xA5 0x5A ^
 -generate 0x80100020 0x80104000 -constant 0x00 ^
 -generate 0x80104000 0x80104004 -constant-l-e 0x5AA5A55A 4 ^
 -generate 0x80104004 0x80104010 -constant 0x00 ^
 temp\A_ApplicationSignature.bin -binary -offset 0x80104010 ^
 -generate 0x80104020 0x80104024 -constant-l-e 0x5AA5A55A 4 ^
 -generate 0x80104024 0x80104028 -constant 0x00 ^
 -generate 0x80104028 0x8010402C -constant-l-e %APP_A_SAMPLE_START% 4 ^
 -generate 0x8010402C 0x80104030 -constant-l-e %APP_SAMPLE_SIZE% 4 ^
 temp\A_ApplicationSampleSignature.bin -binary -offset 0x80104030 ^
 %APP_A_ORG_FILE% -crop 0x80104040 0x80200000 -fill 0x00 0x80104040 0x80200000 ^
 -generate 0x80200000 0x80200020 -repeat-data 0x5A 0xA5 0xA5 0x5A ^
 -generate 0x80200020 0x80204000 -constant 0x00 ^
 -generate 0x80204000 0x80204004 -constant-l-e 0x5AA5A55A 4 ^
 -generate 0x80204004 0x80204010 -constant 0x00 ^
 temp\B_ApplicationSignature.bin -binary -offset 0x80204010 ^
 -generate 0x80204020 0x80204024 -constant-l-e 0x5AA5A55A 4 ^
 -generate 0x80204024 0x80204028 -constant 0x00 ^
 -generate 0x80204028 0x8020402C -constant-l-e %APP_B_SAMPLE_START% 4 ^
 -generate 0x8020402C 0x80204030 -constant-l-e %APP_SAMPLE_SIZE% 4 ^
 temp\B_ApplicationSampleSignature.bin -binary -offset 0x80204030 ^
 %APP_B_ORG_FILE% -crop 0x80204040 0x80300000 -fill 0x00 0x80204040 0x80300000 ^
 %APP_A_ORG_FILE% -crop 0x80300000 0x80480000 -fill 0x00 0x80300000 0x80480000 ^
 %APP_B_ORG_FILE% -crop 0x80480000 0x80600000 -fill 0x00 0x80480000 0x80600000 ^
 %APP_A_ORG_FILE% -crop 0x80600000 0x80780000 -fill 0x00 0x80600000 0x80780000 ^
 %APP_B_ORG_FILE% -crop 0x80780000 0x80900000 -fill 0x00 0x80780000 0x80900000 ^
 %APP_A_ORG_FILE% -crop 0x80900000 0x80980000 -fill 0x00 0x80900000 0x80980000 ^
 %APP_B_ORG_FILE% -crop 0x80980000 0x80A00000 -fill 0x00 0x80980000 0x80A00000 ^
 -o %APP_FILE% %OUT_FILE_OPT%

srec_cat.exe ^
 %APP_FILE% -crop 0x80104000 0x80200000 ^
 -o %APP_A_01_OTA_FILE% %OUT_FILE_OPT%

srec_cat.exe ^
 %APP_FILE% -crop 0x80300000 0x80480000 ^
 -o %APP_A_02_OTA_FILE% %OUT_FILE_OPT%

srec_cat.exe ^
 %APP_FILE% -crop 0x80600000 0x80780000 ^
 -o %APP_A_03_OTA_FILE% %OUT_FILE_OPT%

srec_cat.exe ^
 %APP_FILE% -crop 0x80900000 0x80980000 ^
 -o %APP_A_04_OTA_FILE% %OUT_FILE_OPT%

srec_cat.exe ^
 %APP_FILE% -crop 0x80204000 0x80300000 ^
 -o %APP_B_01_OTA_FILE% %OUT_FILE_OPT%

srec_cat.exe ^
 %APP_FILE% -crop 0x80480000 0x80600000 ^
 -o %APP_B_02_OTA_FILE% %OUT_FILE_OPT%

srec_cat.exe ^
 %APP_FILE% -crop 0x80780000 0x80900000 ^
 -o %APP_B_03_OTA_FILE% %OUT_FILE_OPT%

srec_cat.exe ^
 %APP_FILE% -crop 0x80980000 0x80A00000 ^
 -o %APP_B_04_OTA_FILE% %OUT_FILE_OPT%

rd /s /q temp

@echo ===============================================================================

rem pause