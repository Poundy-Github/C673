::Batch file to build all LCF dlls for MFC431 platform - to be placed in 04_Engineering\03_Workspace\Component_Workspace\LCF\

set project_name=%1
echo %project_name%

if %project_name%x == x goto MFC431

if %project_name% == MFC431 goto MFC431
			          
if %project_name% == MFC431LO19 goto MFC431LO19

if %project_name% == MFC431SC19 goto MFC431SC19

if %project_name% == MFC431SW19 goto MFC431SW19

if %project_name% == MFC431VA10 goto MFC431VA10

if %project_name% == MFC431LO20 goto MFC431LO20

if %project_name% == MFC5J3 goto MFC5J3

if %project_name% == MFC5J3CN15 goto MFC5J3CN15

if %project_name% == MFC431VA21 goto MFC431VA21

if %project_name% == MFC431BD21 goto MFC431BD21

::If none of the conditions above were fulfilled means that the project name does not exist
echo Error: Project name is incorrect
goto Terminate


:MFC431
::build for MFC431
set project=MFC431
set warnings_file=warnings_%project%.log
echo Start SIL build %project%
type nul > %warnings_file%

::clean all
call scons -j 8 -c project=%project%

::build LCF_SEN sim dll
call scons -j 8 lcf_sim_swc_lcf_sen project=%project%
::sdl generation sometimes does not work on first lcf_sim_swc_lcf_sen build; it will be called twice if first build failed
if %errorlevel% neq 0 call scons -j 8 lcf_sim_swc_lcf_sen project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, SEN task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point

::build LCF_VEH sim dll
call scons -j 8 lcf_sim_swc_lcf_veh project=%project%
::sdl generation sometimes does not work on first lcf_sim_swc_lcf_veh build; it will be called twice if first build failed
if %errorlevel% neq 0 call scons -j 8 lcf_sim_swc_lcf_veh project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, VEH task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point

::build LCF vis dll
call scons -j 8 lcf_sim_swc_vis project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, VIS task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point
if not %project_name%x == x goto Terminate


:MFC431LO19  
::build for MFC431LO19
set project=MFC431LO19
set warnings_file=warnings_%project%.log
echo Start SIL build %project%
type nul > %warnings_file%

::clean all
call scons -j 8 -c project=%project%

::build LCF_SEN sim dll
call scons -j 8 lcf_sim_swc_lcf_sen project=%project%
::sdl generation sometimes does not work on first lcf_sim_swc_lcf_sen build; it will be called twice if first build failed
if %errorlevel% neq 0 call scons -j 8 lcf_sim_swc_lcf_sen project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, SEN task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point

::build LCF_VEH sim dll
call scons -j 8 lcf_sim_swc_lcf_veh project=%project%
::sdl generation sometimes does not work on first lcf_sim_swc_lcf_veh build; it will be called twice if first build failed
if %errorlevel% neq 0 call scons -j 8 lcf_sim_swc_lcf_veh project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, VEH task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point

::build LCF vis dll
call scons -j 8 lcf_sim_swc_vis project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, VIS task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point
if not %project_name%x == x goto Terminate

:MFC431LO20
::build for MFC431LO20
set project=MFC431LO20
set warnings_file=warnings_%project%.log
echo Start SIL build %project%
type nul > %warnings_file%

::clean all
call scons -j 8 -c project=%project%

::build LCF_SEN sim dll
call scons -j 8 lcf_sim_swc_lcf_sen project=%project%
::sdl generation sometimes does not work on first lcf_sim_swc_lcf_sen build; it will be called twice if first build failed
if %errorlevel% neq 0 call scons -j 8 lcf_sim_swc_lcf_sen project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, SEN task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point

::build LCF_VEH sim dll
call scons -j 8 lcf_sim_swc_lcf_veh project=%project%
::sdl generation sometimes does not work on first lcf_sim_swc_lcf_veh build; it will be called twice if first build failed
if %errorlevel% neq 0 call scons -j 8 lcf_sim_swc_lcf_veh project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, VEH task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point

::build LCF vis dll
call scons -j 8 lcf_sim_swc_vis project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, VIS task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point
if not %project_name%x == x goto Terminate


:MFC431SC19  
::build for MFC431SC19
set project=MFC431SC19
set warnings_file=warnings_%project%.log
echo Start SIL build %project%
type nul > %warnings_file%

::clean all
call scons -j 8 -c project=%project%

::build LCF_SEN sim dll
call scons -j 8 lcf_sim_swc_lcf_sen project=%project%
::sdl generation sometimes does not work on first lcf_sim_swc_lcf_sen build; it will be called twice if first build failed
if %errorlevel% neq 0 call scons -j 8 lcf_sim_swc_lcf_sen project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, SEN task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point

::build LCF_VEH sim dll
call scons -j 8 lcf_sim_swc_lcf_veh project=%project%
::sdl generation sometimes does not work on first lcf_sim_swc_lcf_veh build; it will be called twice if first build failed
if %errorlevel% neq 0 call scons -j 8 lcf_sim_swc_lcf_veh project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, VEH task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point

::build LCF vis dll
call scons -j 8 lcf_sim_swc_vis project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, VIS task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point
if not %project_name%x == x goto Terminate


:MFC431SW19  
::build for MFC431SW19
set project=MFC431SW19
set warnings_file=warnings_%project%.log
echo Start SIL build %project%
type nul > %warnings_file%

::clean all
call scons -j 8 -c project=%project%

::build LCF_SEN sim dll
call scons -j 8 lcf_sim_swc_lcf_sen project=%project%
::sdl generation sometimes does not work on first lcf_sim_swc_lcf_sen build; it will be called twice if first build failed
if %errorlevel% neq 0 call scons -j 8 lcf_sim_swc_lcf_sen project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, SEN task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point

::build LCF_VEH sim dll
call scons -j 8 lcf_sim_swc_lcf_veh project=%project%
::sdl generation sometimes does not work on first lcf_sim_swc_lcf_veh build; it will be called twice if first build failed
if %errorlevel% neq 0 call scons -j 8 lcf_sim_swc_lcf_veh project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, VEH task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point

::build LCF vis dll
call scons -j 8 lcf_sim_swc_vis project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, VIS task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point
if not %project_name%x == x goto Terminate


:MFC431VA10 
::build for MFC431VA10
set project=MFC431VA10
set warnings_file=warnings_%project%.log
echo Start SIL build %project%
type nul > %warnings_file%

::clean all
call scons -j 8 -c project=%project%

::build LCF_SEN sim dll
call scons -j 8 lcf_sim_swc_lcf_sen project=%project%
::sdl generation sometimes does not work on first lcf_sim_swc_lcf_sen build; it will be called twice if first build failed
if %errorlevel% neq 0 call scons -j 8 lcf_sim_swc_lcf_sen project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, SEN task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point

::build LCF_VEH sim dll
call scons -j 8 lcf_sim_swc_lcf_veh project=%project%
::sdl generation sometimes does not work on first lcf_sim_swc_lcf_veh build; it will be called twice if first build failed
if %errorlevel% neq 0 call scons -j 8 lcf_sim_swc_lcf_veh project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, VEH task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point

::build LCF vis dll
call scons -j 8 lcf_sim_swc_vis project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, VIS task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point
if not %project_name%x == x goto Terminate

:MFC431VA21 
::build for MFC431VA21
set project=MFC431VA21
set warnings_file=warnings_%project%.log
echo Start SIL build %project%
type nul > %warnings_file%

::clean all
call scons -j 8 -c project=%project%

::build LCF_SEN sim dll
call scons -j 8 lcf_sim_swc_lcf_sen project=%project%
::sdl generation sometimes does not work on first lcf_sim_swc_lcf_sen build; it will be called twice if first build failed
if %errorlevel% neq 0 call scons -j 8 lcf_sim_swc_lcf_sen project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, SEN task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point

::build LCF_VEH sim dll
call scons -j 8 lcf_sim_swc_lcf_veh project=%project%
::sdl generation sometimes does not work on first lcf_sim_swc_lcf_veh build; it will be called twice if first build failed
if %errorlevel% neq 0 call scons -j 8 lcf_sim_swc_lcf_veh project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, VEH task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point

::build LCF vis dll
call scons -j 8 lcf_sim_swc_vis project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, VIS task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point
if not %project_name%x == x goto Terminate


:MFC5J3 
::build for MFC5J3
set project=MFC5J3
set warnings_file=warnings_%project%.log
echo Start SIL build %project%
type nul > %warnings_file%

::clean all
call scons -j 8 -c project=%project%

::build LCF_SEN sim dll
call scons -j 8 lcf_sim_swc_lcf_sen project=%project%
::sdl generation sometimes does not work on first lcf_sim_swc_lcf_sen build; it will be called twice if first build failed
if %errorlevel% neq 0 call scons -j 8 lcf_sim_swc_lcf_sen project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, SEN task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point

::build LCF_VEH sim dll
call scons -j 8 lcf_sim_swc_lcf_veh project=%project%
::sdl generation sometimes does not work on first lcf_sim_swc_lcf_veh build; it will be called twice if first build failed
if %errorlevel% neq 0 call scons -j 8 lcf_sim_swc_lcf_veh project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, VEH task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point

::build LCF vis dll
call scons -j 8 lcf_sim_swc_vis project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, VIS task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point
if not %project_name%x == x goto Terminate


:MFC5J3CN15 
::build for MFC5J3CN15
set project=MFC5J3CN15
set warnings_file=warnings_%project%.log
echo Start SIL build %project%
type nul > %warnings_file%

::clean all
call scons -j 8 -c project=%project%

::build LCF_SEN sim dll
call scons -j 8 lcf_sim_swc_lcf_sen project=%project%
::sdl generation sometimes does not work on first lcf_sim_swc_lcf_sen build; it will be called twice if first build failed
if %errorlevel% neq 0 call scons -j 8 lcf_sim_swc_lcf_sen project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, SEN task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point

::build LCF_VEH sim dll
call scons -j 8 lcf_sim_swc_lcf_veh project=%project%
::sdl generation sometimes does not work on first lcf_sim_swc_lcf_veh build; it will be called twice if first build failed
if %errorlevel% neq 0 call scons -j 8 lcf_sim_swc_lcf_veh project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, VEH task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point

::build LCF vis dll
call scons -j 8 lcf_sim_swc_vis project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, VIS task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point
if not %project_name%x == x goto Terminate


:MFC431BD21 
::build for MFC431BD21
set project=MFC431BD21
set warnings_file=warnings_%project%.log
echo Start SIL build %project%
type nul > %warnings_file%

::clean all
call scons -j 8 -c project=%project%

::build LCF_SEN sim dll
call scons -j 8 lcf_sim_swc_lcf_sen project=%project%
::sdl generation sometimes does not work on first lcf_sim_swc_lcf_sen build; it will be called twice if first build failed
if %errorlevel% neq 0 call scons -j 8 lcf_sim_swc_lcf_sen project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, SEN task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point

::build LCF_VEH sim dll
call scons -j 8 lcf_sim_swc_lcf_veh project=%project%
::sdl generation sometimes does not work on first lcf_sim_swc_lcf_veh build; it will be called twice if first build failed
if %errorlevel% neq 0 call scons -j 8 lcf_sim_swc_lcf_veh project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, VEH task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point

::build LCF vis dll
call scons -j 8 lcf_sim_swc_vis project=%project%
if %errorlevel% neq 0 goto Terminate
echo && echo "========= Warnings for %project%, VIS task =========" >> %warnings_file%
findstr /r /c:": warning" sconsbuild.log >> %warnings_file%
::continue building only if building successful up to this point
if not %project_name%x == x goto Terminate

goto Terminate

:Terminate

cmd /k


