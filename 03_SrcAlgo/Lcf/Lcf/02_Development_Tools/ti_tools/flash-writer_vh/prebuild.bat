@echo off

rem Remove write-protect bit of generated files
if exist flash-writer_vh.out attrib flash-writer_vh.out -r
if exist flash-writer_vh.map attrib flash-writer_vh.map -r
