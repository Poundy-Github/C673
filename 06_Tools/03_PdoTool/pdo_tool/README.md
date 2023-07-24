# Folder content description #

This folder contains all relevant binaries, configuration files and scripts relevant for the pdo tool

## Folder Structure ##

- folder /templateSwc: the template configurations for the SWC generation
- createSwc.py: python script to generate the SWC needed for measfreezes
- *.cfg files: configuration files for the pdo_scan.exe and pdo_tool.exe applications

## CEM200 usage ##

The pdo_scan.exe and pdo_tool.exe are fetched via conan from artifactory and called from CEM200/swc/common/cmake/pdo.cmake to generate one sdl file for all components and additionally one sdl file with all components merged in one file.
Additionally createSwc.py is used to generate the Softwarecontainer for the MI 5.

