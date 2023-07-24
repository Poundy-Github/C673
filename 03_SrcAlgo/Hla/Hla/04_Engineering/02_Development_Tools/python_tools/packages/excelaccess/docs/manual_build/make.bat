@ECHO OFF

REM Command file for Sphinx documentation

pushd %~dp0

if "%SPHINXBUILD%" == "" (
	set SPHINXBUILD=python -msphinx
)
set SOURCEDIR=source
set BUILDDIR=build
set ALLSPHINXOPTS=-d %BUILDDIR%/doctrees %SPHINXOPTS% .
set I18NSPHINXOPTS=%SPHINXOPTS% .
if NOT "%PAPER%" == "" (
	set ALLSPHINXOPTS=-D latex_elements.papersize=%PAPER% %ALLSPHINXOPTS%
	set I18NSPHINXOPTS=-D latex_elements.papersize=%PAPER% %I18NSPHINXOPTS%
)

if "%1" == "" goto help

if "%1" == "help" (
	:help
	echo.Please use `make ^<target^>` where ^<target^> is one of
	echo.  html       to make standalone HTML files
	echo.  dirhtml    to make HTML files named index.html in directories
	echo.  singlehtml to make a single large HTML file
	echo.  pickle     to make pickle files
	echo.  json       to make JSON files
	echo.  htmlhelp   to make HTML files and an HTML help project
	echo.  qthelp     to make HTML files and a qthelp project
	echo.  devhelp    to make HTML files and a Devhelp project
	echo.  epub       to make an epub
	echo.  epub3      to make an epub3
	echo.  latex      to make LaTeX files, you can set PAPER=a4 or PAPER=letter
	echo.  text       to make text files
	echo.  man        to make manual pages
	echo.  texinfo    to make Texinfo files
	echo.  gettext    to make PO message catalogs
	echo.  changes    to make an overview over all changed/added/deprecated items
	echo.  xml        to make Docutils-native XML files
	echo.  pseudoxml  to make pseudoxml-XML files for display purposes
	echo.  linkcheck  to check all external links for integrity
	echo.  doctest    to run all doctests embedded in the documentation if enabled
	echo.  coverage   to run coverage check of the documentation if enabled
	echo.  dummy      to check syntax errors of document sources
	goto end
)

if "%1" == "clean" (
	for /d %%i in (%BUILDDIR%\*) do rmdir /q /s %%i
	del /q /s %BUILDDIR%\*
	goto end
)


REM Check if sphinx-build is available
%SPHINXBUILD% >NUL 2>NUL
if errorlevel 9009 (
	echo.
	echo.The Sphinx module was not found. Make sure you have Sphinx installed,
	echo.then set the SPHINXBUILD environment variable to point to the full
	echo.path of the 'sphinx-build' executable. Alternatively you may add the
	echo.Sphinx directory to PATH.
	echo.
	echo.If you don't have Sphinx installed, grab it from
	echo.http://sphinx-doc.org/
	exit /b 1
)


if "%1" == "html" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	if errorlevel 1 exit /b 1
	echo.
	echo.Build finished. The HTML pages are in %BUILDDIR%/html.
	goto end
)

if "%1" == "dirhtml" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	if errorlevel 1 exit /b 1
	echo.
	echo.Build finished. The HTML pages are in %BUILDDIR%/dirhtml.
	goto end
)

if "%1" == "singlehtml" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	if errorlevel 1 exit /b 1
	echo.
	echo.Build finished. The HTML pages are in %BUILDDIR%/singlehtml.
	goto end
)

if "%1" == "pickle" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	if errorlevel 1 exit /b 1
	echo.
	echo.Build finished; now you can process the pickle files.
	goto end
)

if "%1" == "json" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	if errorlevel 1 exit /b 1
	echo.
	echo.Build finished; now you can process the JSON files.
	goto end
)

if "%1" == "htmlhelp" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	if errorlevel 1 exit /b 1
	echo.
	echo.Build finished; now you can run HTML Help Workshop with the ^
.hhp project file in %BUILDDIR%/htmlhelp.
	goto end
)

if "%1" == "qthelp" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	if errorlevel 1 exit /b 1
	echo.
	echo.Build finished; now you can run "qcollectiongenerator" with the ^
.qhcp project file in %BUILDDIR%/qthelp, like this:
	echo.^> qcollectiongenerator %BUILDDIR%\qthelp\ExcelAccess.qhcp
	echo.To view the help file:
	echo.^> assistant -collectionFile %BUILDDIR%\qthelp\ExcelAccess.ghc
	goto end
)

if "%1" == "devhelp" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	if errorlevel 1 exit /b 1
	echo.
	echo.Build finished.
	goto end
)

if "%1" == "epub" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	if errorlevel 1 exit /b 1
	echo.
	echo.Build finished. The epub file is in %BUILDDIR%/epub.
	goto end
)

if "%1" == "epub3" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	if errorlevel 1 exit /b 1
	echo.
	echo.Build finished. The epub3 file is in %BUILDDIR%/epub3.
	goto end
)

if "%1" == "latex" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	if errorlevel 1 exit /b 1
	echo.
	echo.Build finished; the LaTeX files are in %BUILDDIR%/latex.
	goto end
)

if "%1" == "latexpdf" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	cd %BUILDDIR%/latex
	make all-pdf
	cd %~dp0
	echo.
	echo.Build finished; the PDF files are in %BUILDDIR%/latex.
	goto end
)

if "%1" == "latexpdfja" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	cd %BUILDDIR%/latex
	make all-pdf-ja
	cd %~dp0
	echo.
	echo.Build finished; the PDF files are in %BUILDDIR%/latex.
	goto end
)

if "%1" == "text" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	if errorlevel 1 exit /b 1
	echo.
	echo.Build finished. The text files are in %BUILDDIR%/text.
	goto end
)

if "%1" == "man" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	if errorlevel 1 exit /b 1
	echo.
	echo.Build finished. The manual pages are in %BUILDDIR%/man.
	goto end
)

if "%1" == "texinfo" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	if errorlevel 1 exit /b 1
	echo.
	echo.Build finished. The Texinfo files are in %BUILDDIR%/texinfo.
	goto end
)

if "%1" == "gettext" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	if errorlevel 1 exit /b 1
	echo.
	echo.Build finished. The message catalogs are in %BUILDDIR%/locale.
	goto end
)

if "%1" == "changes" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	if errorlevel 1 exit /b 1
	echo.
	echo.The overview file is in %BUILDDIR%/changes.
	goto end
)

if "%1" == "linkcheck" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	if errorlevel 1 exit /b 1
	echo.
	echo.Link check complete; look for any errors in the above output ^
or in %BUILDDIR%/linkcheck/output.txt.
	goto end
)

if "%1" == "doctest" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	if errorlevel 1 exit /b 1
	echo.
	echo.Testing of doctests in the sources finished, look at the ^
results in %BUILDDIR%/doctest/output.txt.
	goto end
)

if "%1" == "coverage" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	if errorlevel 1 exit /b 1
	echo.
	echo.Testing of coverage in the sources finished, look at the ^
results in %BUILDDIR%/coverage/python.txt.
	goto end
)

if "%1" == "xml" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	if errorlevel 1 exit /b 1
	echo.
	echo.Build finished. The XML files are in %BUILDDIR%/xml.
	goto end
)

if "%1" == "pseudoxml" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	if errorlevel 1 exit /b 1
	echo.
	echo.Build finished. The pseudo-XML files are in %BUILDDIR%/pseudoxml.
	goto end
)

if "%1" == "dummy" (
	%SPHINXBUILD% -M %1 %SOURCEDIR% %BUILDDIR% %SPHINXOPTS%
	if errorlevel 1 exit /b 1
	echo.
	echo.Build finished. Dummy builder generates no files.
	goto end
)

:end
popd
