attrib -R *.chm
echo =========================
echo Run Doxygen
echo =========================
.\..\..\..\..\02_Development_Tools\doxygen\bin\doxygen .\sim_swc_doxy_setup.txt
echo =========================
echo Run html workshop
echo =========================
.\..\..\..\..\02_Development_Tools\html_help_workshop\hhc.exe .\doxygen\html\index.hhp
echo =========================