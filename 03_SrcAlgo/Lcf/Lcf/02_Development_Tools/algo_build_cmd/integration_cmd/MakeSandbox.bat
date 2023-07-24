@echo off
set MyVariant=MFS430BW16_110.000.000
set MainLocation=D:\Sandboxs\
set MainProject=MFC400



set MyProj=/nfs/projekte1/PROJECTS/%MainProject%/project.pj
set SandboxLocation=%MainLocation%%MyVariant%
si createsandbox --project=%MyProj% --norecurse --devpath=%MyVariant% %SandboxLocation%

si resync --overwriteChanged -R %SandboxLocation%\06_Algorithm\04_Engineering\01_Source_Code\project.pj
si resync --overwriteChanged -R %SandboxLocation%\06_Algorithm\04_Engineering\03_Workspace\project.pj
si resync --overwriteChanged -R %SandboxLocation%\06_Algorithm\04_Engineering\02_Development_Tools\project.pj