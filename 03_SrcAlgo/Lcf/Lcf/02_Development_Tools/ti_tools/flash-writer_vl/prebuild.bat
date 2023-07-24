@echo off

rem Remove write-protect bit of generated files
if exist flash-writer_vl.out attrib flash-writer_vl.out -r
if exist flash-writer_vl.map attrib flash-writer_vl.map -r
