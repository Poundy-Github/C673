echo =========================
echo Run Doxygen
echo =========================
.\..\..\..\..\doxygen\bin\doxygen .\gscons_doxygen_config.dox
echo =========================
echo Run html workshop
echo =========================
.\..\..\..\..\html_help_workshop\hhc.exe .\html_documentation\index.hhp
echo =========================