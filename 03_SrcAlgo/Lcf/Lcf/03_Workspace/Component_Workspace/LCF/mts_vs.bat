echo off
set project_name=%1
attrib -r ..\..\..\..\04_Engineering\*.* /s
call scons lcf_ide_msvc project=%project_name%

call build_all_dll %project_name%
copy ..\..\..\04_Build\algo\lcf_sim\pc\sim_swc_lcf_sen\debug\sim_swc_lcf_sen.dll ..\..\..\..\..\MTS\05_Testing\MTS\mts_measurement\dll\00_Projects\%project_name%\LCF_sim\sim_swc_lcf_sen.dll
copy ..\..\..\04_Build\algo\lcf_sim\pc\sim_swc_lcf_sen\debug\sim_swc_lcf_sen.pdb ..\..\..\..\..\MTS\05_Testing\MTS\mts_measurement\dll\00_Projects\%project_name%\LCF_sim\sim_swc_lcf_sen.pdb

copy ..\..\..\04_Build\algo\lcf_sim\pc\sim_swc_lcf_veh\debug\sim_swc_lcf_veh.dll ..\..\..\..\..\MTS\05_Testing\MTS\mts_measurement\dll\00_Projects\%project_name%\LCF_sim\sim_swc_lcf_veh.dll
copy ..\..\..\04_Build\algo\lcf_sim\pc\sim_swc_lcf_veh\debug\sim_swc_lcf_veh.pdb ..\..\..\..\..\MTS\05_Testing\MTS\mts_measurement\dll\00_Projects\%project_name%\LCF_sim\sim_swc_lcf_veh.pdb

copy ..\..\..\04_Build\algo\lcf_sim\pc\sim_swc_lcf_vis\debug\sim_swc_lcf_vis.dll ..\..\..\..\..\MTS\05_Testing\MTS\mts_measurement\dll\00_Projects\%project_name%\LCF_sim\sim_swc_lcf_vis.dll
copy ..\..\..\04_Build\algo\lcf_sim\pc\sim_swc_lcf_vis\debug\sim_swc_lcf_vis.pdb ..\..\..\..\..\MTS\05_Testing\MTS\mts_measurement\dll\00_Projects\%project_name%\LCF_sim\sim_swc_lcf_vis.pdb

cd ..\00_Projects\MFC431LO19\LCF_sim\
lcf.sln
cd ..\..\..\..\..\..\..\MTS\05_Testing\MTS\mts_measurement\cfg\00_Projects\%project_name%\JOINT

python jointsim.pyw



