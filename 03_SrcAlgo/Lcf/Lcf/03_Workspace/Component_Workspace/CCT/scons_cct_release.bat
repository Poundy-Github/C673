@echo off

call scons.bat -j%NUMBER_OF_PROCESSORS% install_to_deliverables_dir=debug cct_algo_pc_debug
pause
call scons.bat -j%NUMBER_OF_PROCESSORS% cct_algo_release cct_sim_pc_release cct_qac
pause