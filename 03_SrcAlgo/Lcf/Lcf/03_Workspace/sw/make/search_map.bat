@echo off
echo.

rem delete old results of search_map.pl
if exist _*.txt del _*.txt
if exist search_map_%1\_*.txt del search_map_%1\_*.txt

echo Executing search_map.pl 
C:\Tools\perl\v5.6\bin\perl.exe search_map.pl %1 %2 %3 %4

rem Create the date and time elements if not already defined from top level script
if "%1" == "" (
	rem Create the date and time elements
	echo.
	if "%date:~2,1%" == "." (
	  rem echo Using German date format
	) else if "%date:~2,1%" == "/" (
	  rem echo Using British date format
	) else if "%date:~2,1%" == "-" (
	  rem echo Using Indian date format
	) else if "%date:~5,1%" == "." (
	  rem echo Using Finnish date format
	) else (
	  echo *** Invalid regional settings detected - aborting ***
	  echo.
	  echo Only parsing of British, Indian, Finnish and German and date formats is supported.
	  echo Please set your regional settings to either British, German, Finnish or Indian.  You
	  echo can do this independently of the language used on your system.  US date format
	  echo is non standard and thus not supported.
	  exit /b 1
	)

	rem Check if hours are less 10 and add leading 0
	if %time:~0,2% lss 10 (
	  set hrs=0%time:~1,1%
	  ) else (
	  set hrs=%time:~0,2%
	  )
	if "%date:~2,1%" == "." (
	set tsnow=%date:~8,2%%date:~3,2%%date:~0,2%_%hrs%%time:~3,2%
	) else if "%date:~5,1%" == "." (
	set tsnow=%date:~11,2%%date:~6,2%%date:~3,2%_%hrs%%time:~3,2%
	) else (
	set tsnow=%date:~8,2%%date:~3,2%%date:~0,2%_%hrs%%time:~3,2%
	)
)
	
rem Store the generated files for later use with time stamp
if not exist archive mkdir archive
copy _flash_end_address.txt archive\%tsnow%_flash_end_address.txt > NUL
copy _name_sorted_SoC1.txt archive\%tsnow%_name_sorted_SoC1.txt > NUL
copy _name_sorted_SoC2.txt archive\%tsnow%_name_sorted_SoC2.txt > NUL
copy _origin_sorted_SoC1.txt archive\%tsnow%_origin_sorted_SoC1.txt > NUL
copy _origin_sorted_SoC2.txt archive\%tsnow%_origin_sorted_SoC2.txt > NUL
copy _reserved_sorted_SoC1.txt archive\%tsnow%_reserved_sorted_SoC1.txt > NUL
copy _reserved_sorted_SoC2.txt archive\%tsnow%_reserved_sorted_SoC2.txt > NUL
copy _used_sorted_SoC1.txt archive\%tsnow%_used_sorted_SoC1.txt > NUL
copy _used_sorted_SoC2.txt archive\%tsnow%_used_sorted_SoC2.txt > NUL

rem Copy search_map results to projectname-directory
if not exist search_map_%1 mkdir search_map_%1
if exist _*.txt copy _*.txt search_map_%1 /Y > NUL
