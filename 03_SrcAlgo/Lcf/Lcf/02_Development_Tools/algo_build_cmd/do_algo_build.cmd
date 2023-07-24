@echo off
cd build_cmd

python build_main.py AlgoBuild -c ..\..\..\03_Workspace\algo\make_all_sim.xml -l -o .\

cd ..
pause

