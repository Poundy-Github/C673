if exist ..\..\..\05_Output\pdo\sim_swc_c673.sdl (
copy ..\..\..\05_Output\pdo\sim_swc_c673.sdl .\InputSource\sdl\mfc5J3_MCU.sdl
)

mtsswccli --build -o Swccli_MFC5J3_MCU.swc^
 --sdl      .\InputSource\sdl\mfc5J3_MCU.sdl^
 --cycles   .\InputSource\cycle-definition\cycle-definition.xml^
 --channels .\InputSource\channel-definition\channel-definition.xml^
 --hw-data  .\InputSource\hw-data-cycle\hw-data-cycle.xml^
 --mot      .\Dummy.mot^
 --mapping  .\InputSource\channel-mapping\channel-mapping.xml^
 -k
 
copy .\Swccli_MFC5J3_MCU.swc ..\..\..\05_Output\pdo\C673_MCU.swc
 
