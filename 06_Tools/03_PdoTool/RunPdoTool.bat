@echo off
set origin_dir=%cd%
if not exist ..\..\05_Output\pdo (
mkdir ..\..\05_Output\pdo )

:::pdoScanVDY.py -r D:\02_WorkSpace\10_C385\C385_local -v -p D:\02_WorkSpace\10_C385\C385_local\MCU_APP\01_AsrConfig\output\pdo -d D:\02_WorkSpace\10_C385\C385_local\MCU_APP\06_Tools\03_PdoTool\pdo_tool -o D:\02_WorkSpace\10_C385\C385_local\MCU_APP\01_AsrConfig\output\pdo -a D:\02_WorkSpace\10_C385\C385_local\MCU_APP\01_AsrConfig\source\Swc_Appl -i D:\02_WorkSpace\10_C385\C385_local\MCU_APP\01_AsrConfig\output\generated\include -s D:\02_WorkSpace\10_C385\C385_local\MCU_APP\06_Tools\03_PdoTool\pdo_tool\2.17\cip\testing\package\3475bd55b91ae904ac96fde0f106a136ab951a5e/pdo_scan.exe -t D:\02_WorkSpace\10_C385\C385_local\MCU_APP\06_Tools\03_PdoTool\pdo_tool\2.17\cip\testing\package\3475bd55b91ae904ac96fde0f106a136ab951a5e/pdo_tool.exe -c FCTVDY
%TOOLPATH_PYTHON_EXE% pdoScanVDY.py -r ..\..\ -v -p ..\..\05_Output\pdo -d .\pdo_tool -o ..\..\05_Output\pdo -a ..\..\ -i ..\..\01_AsrConfig\output\generated\include -s .\pdo_tool\2.17\cip\testing\package\3475bd55b91ae904ac96fde0f106a136ab951a5e\pdo_scan.exe -t .\pdo_tool\2.17\cip\testing\package\3475bd55b91ae904ac96fde0f106a136ab951a5e\pdo_tool.exe -c C673

cd %origin_dir%
