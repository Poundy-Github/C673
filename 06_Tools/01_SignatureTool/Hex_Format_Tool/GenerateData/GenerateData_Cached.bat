@echo ===============================================================================

rem Get Sample Binary Data
srec_cat.exe ^
 ApplicationA.hex -intel ^
 -crop 0x80104100 0x80136100 ^
 -fill 0x00 0x80104100 0x80136100 ^
 -offset -0x80104100 ^
 -o ApplicationSampleA.bin -binary

rem Calculate Sample Signature
signature.exe -i ApplicationSampleA.bin -o ApplicationSampleSignatureA.bin

rem Get All Binary Data
srec_cat.exe ^
 ApplicationA.hex -intel ^
 -crop 0x80104000 0x804FFFC0 ^
 -fill 0x00 0x80104000 0x804FFFC0 ^
 -offset -0x80104000 ^
 ApplicationSampleSignatureA.bin -binary  -offset 0x3FBFD0 ^
 -generate 0x003FBFC0 0x003FBFC4 -constant-l-e 0x5AA5A55A 4 ^
 -generate 0x003FBFC4 0x003FBFC8 -constant 0x00 ^
 -generate 0x003FBFC8 0x003FBFCC -constant-l-e 0x80104100 4 ^
 -generate 0x003FBFCC 0x003FBFD0 -constant-l-e 0x00032000 4 ^
 -o ApplicationAllA.bin -binary

rem Calculate All Signature
signature.exe -i ApplicationAllA.bin -o ApplicationAllSignatureA.bin

rem Add Signature
srec_cat.exe ^
 ApplicationAllA.bin -binary -offset 0x80104000 ^
 ApplicationAllSignatureA.bin -binary -offset 0x804FFFF0 ^
 -generate 0x804FFFE0 0x804FFFE4 -constant-l-e 0x5AA5A55A 4 ^
 -generate 0x804FFFE4 0x804FFFE8 -constant 0x00 ^
 -generate 0x804FFFE8 0x804FFFEC -constant-l-e 0x80104000 4 ^
 -generate 0x804FFFEC 0x804FFFF0 -constant-l-e 0x003FBFE0 4 ^
 -o ApplicationA_OTA.hex -intel

rem Add Status
srec_cat.exe ^
 -generate 0x80100000 0x80100020 -repeat-data 0x5A 0xA5 0xA5 0x5A ^
 -generate 0x80100020 0x80104000 -constant 0x00 ^
 ApplicationA_OTA.hex -intel ^
 -o ApplicationA_TOOL.hex -intel

del /f /s /q ApplicationSampleA.bin
del /f /s /q ApplicationSampleSignatureA.bin
del /f /s /q ApplicationAllA.bin
del /f /s /q ApplicationAllSignatureA.bin

@echo ===============================================================================

rem Get Sample Binary Data
srec_cat.exe ^
 ApplicationB.hex -intel ^
 -crop 0x80504100 0x80536100 ^
 -fill 0x00 0x80504100 0x80536100 ^
 -offset -0x80504100 ^
 -o ApplicationSampleB.bin -binary

rem Calculate Sample Signature
signature.exe -i ApplicationSampleB.bin -o ApplicationSampleSignatureB.bin

rem Get All Binary Data
srec_cat.exe ^
 ApplicationB.hex -intel ^
 -crop 0x80504000 0x808FFFC0 ^
 -fill 0x00 0x80504000 0x808FFFC0 ^
 -offset -0x80504000 ^
 ApplicationSampleSignatureB.bin -binary  -offset 0x3FBFD0 ^
 -generate 0x003FBFC0 0x003FBFC4 -constant-l-e 0x5AA5A55A 4 ^
 -generate 0x003FBFC4 0x003FBFC8 -constant 0x00 ^
 -generate 0x003FBFC8 0x003FBFCC -constant-l-e 0x80504100 4 ^
 -generate 0x003FBFCC 0x003FBFD0 -constant-l-e 0x00032000 4 ^
 -o ApplicationAllB.bin -binary

rem Calculate All Signature
signature.exe -i ApplicationAllB.bin -o ApplicationAllSignatureB.bin

rem Add Signature
srec_cat.exe ^
 ApplicationAllB.bin -binary -offset 0x80504000 ^
 ApplicationAllSignatureB.bin -binary -offset 0x808FFFF0 ^
 -generate 0x808FFFE0 0x808FFFE4 -constant-l-e 0x5AA5A55A 4 ^
 -generate 0x808FFFE4 0x808FFFE8 -constant 0x00 ^
 -generate 0x808FFFE8 0x808FFFEC -constant-l-e 0x80504000 4 ^
 -generate 0x808FFFEC 0x808FFFF0 -constant-l-e 0x003FBFE0 4 ^
 -o ApplicationB_OTA.hex -intel

rem Add Status
srec_cat.exe ^
 -generate 0x80500000 0x80500020 -repeat-data 0x5A 0xA5 0xA5 0x5A ^
 -generate 0x80500020 0x80504000 -constant 0x00 ^
 ApplicationB_OTA.hex -intel ^
 -o ApplicationB_TOOL.hex -intel

del /f /s /q ApplicationSampleB.bin
del /f /s /q ApplicationSampleSignatureB.bin
del /f /s /q ApplicationAllB.bin
del /f /s /q ApplicationAllSignatureB.bin

@echo ===============================================================================
rem pause