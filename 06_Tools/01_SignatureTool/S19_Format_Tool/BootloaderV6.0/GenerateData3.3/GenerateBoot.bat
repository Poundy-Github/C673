@echo ===============================================================================

SET BOOT_ORG_FILE=input\TRICORE_TC38XQ_Boot.mot
rem SET BOOT_ORG_FILE=input\TRICORE_TC38XQ_Boot.hex -intel

SET BOOT_FILE=output\TOOL\Boot.s19
rem SET BOOT_FILE=output\TOOL\Boot.hex -intel

SET OUT_FILE_OPT=-address-length=4 -obs=32 -disable=data-count -Execution_Start_Address=0x0000
rem SET OUT_FILE_OPT=

srec_cat.exe ^
 %BOOT_ORG_FILE% -crop 0x80040080 0x80060000 -fill 0x00 0x80040080 0x80060000 ^
 -o %BOOT_FILE% %OUT_FILE_OPT%

@echo ===============================================================================

rem pause