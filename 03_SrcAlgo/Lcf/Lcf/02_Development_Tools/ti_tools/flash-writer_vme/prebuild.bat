@echo off

rem Remove write-protect bit of generated files
if exist flash-writer_vme.out attrib flash-writer_vme.out -r
if exist flash-writer_vme.map attrib flash-writer_vme.map -r
