@echo off
cls
pushd "%~dp0"
..\..\movpy\movpy.exe build.py %1 %2 %3
popd