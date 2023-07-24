# MFC5J3 C385 LCF100 Source Code
> This repo is use for LCF100 Source Code Release.  
> Can use for TASKING Compile and MTS simulation compile.  
> If you want to use MTS simulation, please use **[MFC5J3 C385 LCF100 DEV](https://github-am.geo.conti.de/ADAS/MFC5J3_C385_LCF100_DEV)** repo. 

## How to Integrate with TC38x  

Now this repo provide code for 2 Projects:
- ChangAn C385  
    Project Name internal: **MFC5J3**

- ChangAn C673  
    Project Name internal: **MFC5J3CN15**

please use correct project name when configure compile path.

### add header(.h) file path to USER_INCLUDE_PATH in **Merged_Makefile.mak**  
```MakeFile
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\00_Projects\{PROJECT_NAME} \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\00_Projects\{PROJECT_NAME}\LCF \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\00_Projects\{PROJECT_NAME}\LCF\MFJSCT \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\00_Projects\{PROJECT_NAME}\LCF\HMIOC \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\00_Projects\{PROJECT_NAME}\LCF\LCF_DPU \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\00_Projects\{PROJECT_NAME}\LCF\MFJSCT\JCNCTR \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\00_Projects\{PROJECT_NAME}\LCF\HMIOC\HMODFL \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\00_Projects\{PROJECT_NAME}\LCF\LCF_DPU\LCFERR \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\00_Projects\{PROJECT_NAME}\LCF\LCF_DPU\LCFPRM \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\00_Projects\{PROJECT_NAME}\LCF\LCF_DPU\LCFRCV \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\00_Projects\{PROJECT_NAME}\LCF\LCF_DPU\LCFSEN \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\00_Projects\{PROJECT_NAME}\LCF\LCF_DPU\LCFSND \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\00_Projects\{PROJECT_NAME}\LCF\LCF_DPU\LCFVEH \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\common \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\common\LCF \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\common\LCF\RTW \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\ABPR \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\ALCASA \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\Common \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\CTRSC \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\DRVMN \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\LATDMC \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\LCFERR \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\LCF_MFC431x \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\LDPSA \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\MDCTR \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\ODPR \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\RDPSA \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\TJASA \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\TRJCTR \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\TRJPLN \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\VDPR \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\ABPR\ABPLBP \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\ABPR\ABPREP \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\ALCASA\LCRSIA \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\ALCASA\LCRSMI \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\ALCASA\LCRTTG \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\ALCASA\LCRTVG \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\Common\SDA \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\Common\sw_support \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\Common\utils \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\CTRSC\CSCLTA \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\DRVMN\DRMDAE \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\DRVMN\DRMHOD \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\LATDMC\latdmc_veh_ang \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\LCF_MFC431x\DPU \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\LCF_MFC431x\DPU\FRAME_SEN \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\LCF_MFC431x\DPU\FRAME_VEH \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\LCF_MFC431x\DPU\LCFRCV \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\LCF_MFC431x\DPU\LCFSND \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\LDPSA\DPLSIA \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\LDPSA\DPLSMI \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\LDPSA\DPLSMW \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\LDPSA\DPLTTG \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\LDPSA\DPLTVG \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\MDCTR\MCTLFC \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\ODPR\ODPFOH \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\ODPR\ODPFOP \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\RDPSA\DPRSIA \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\RDPSA\DPRSMI \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\RDPSA\DPRSMW \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\RDPSA\DPRTTG \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\RDPSA\DPRTVG \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\TJASA\TJACMB \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\TJASA\TJAGEN \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\TJASA\TJALKA \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\TJASA\TJAOBF \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\TJASA\TJASTM \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\TJASA\TJATTG \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\TJASA\TJATVG \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\TRJCTR\TCTCDC \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\TRJCTR\TCTCLM \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\TRJCTR\TCTDTE \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\TRJCTR\TCTEST \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\TRJCTR\TCTFFC \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\TRJCTR\TCTLGC \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\TRJPLN\TPLCEN \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\TRJPLN\TPLFBT \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\TRJPLN\TPLFRT \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\TRJPLN\TPLLCO \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\TRJPLN\TPLTJC \
	$(PROJECT_ROOT)\source\SWC_ALGO\LCF\01_Source_Code\LCF\VDPR\VDPDRV \
```  

### add source code(.c) files path to **CC_FILES_TO_BUILD** in **Makefile.mak**:
```MakeFile
	SWC_ALGO/LCF/00_Projects/{PROJECT_NAME}/*.c \
	SWC_ALGO/LCF/00_Projects/{PROJECT_NAME}/LCF/*.c \
	SWC_ALGO/LCF/00_Projects/{PROJECT_NAME}/LCF/MFJSCT/*.c \
	SWC_ALGO/LCF/00_Projects/{PROJECT_NAME}/LCF/HMIOC/*.c \
	SWC_ALGO/LCF/00_Projects/{PROJECT_NAME}/LCF/LCF_DPU/*.c \
	SWC_ALGO/LCF/00_Projects/{PROJECT_NAME}/LCF/MFJSCT/JCNCTR/*.c \
	SWC_ALGO/LCF/00_Projects/{PROJECT_NAME}/LCF/HMIOC/HMODFL/*.c \
	SWC_ALGO/LCF/00_Projects/{PROJECT_NAME}/LCF/LCF_DPU/LCFERR/*.c \
	SWC_ALGO/LCF/00_Projects/{PROJECT_NAME}/LCF/LCF_DPU/LCFPRM/*.c \
	SWC_ALGO/LCF/00_Projects/{PROJECT_NAME}/LCF/LCF_DPU/LCFRCV/*.c \
	SWC_ALGO/LCF/00_Projects/{PROJECT_NAME}/LCF/LCF_DPU/LCFSEN/*.c \
	SWC_ALGO/LCF/00_Projects/{PROJECT_NAME}/LCF/LCF_DPU/LCFSND/*.c \
	SWC_ALGO/LCF/00_Projects/{PROJECT_NAME}/LCF/LCF_DPU/LCFVEH/*.c \
	SWC_ALGO/LCF/01_Source_Code/common/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/*.c \
	SWC_ALGO/LCF/01_Source_Code/common/LCF/*.c \
	SWC_ALGO/LCF/01_Source_Code/common/LCF/RTW/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/ABPR/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/ALCASA/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/Common/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/CTRSC/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/DRVMN/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/LATDMC/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/LCFERR/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/LCF_MFC431x/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/LDPSA/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/MDCTR/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/ODPR/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/RDPSA/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/TJASA/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/TRJCTR/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/TRJPLN/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/VDPR/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/ABPR/ABPLBP/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/ABPR/ABPREP/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/ALCASA/LCRSIA/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/ALCASA/LCRSMI/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/ALCASA/LCRTTG/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/ALCASA/LCRTVG/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/Common/SDA/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/Common/sw_support/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/Common/utils/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/CTRSC/CSCLTA/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/DRVMN/DRMDAE/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/DRVMN/DRMHOD/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/LATDMC/latdmc_veh_ang/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/LCF_MFC431x/DPU/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_SEN/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_VEH/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFRCV/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFSND/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/LDPSA/DPLSIA/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/LDPSA/DPLSMI/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/LDPSA/DPLSMW/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/LDPSA/DPLTTG/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/LDPSA/DPLTVG/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/MDCTR/MCTLFC/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/ODPR/ODPFOH/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/ODPR/ODPFOP/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/RDPSA/DPRSIA/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/RDPSA/DPRSMI/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/RDPSA/DPRSMW/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/RDPSA/DPRTTG/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/RDPSA/DPRTVG/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/TJASA/TJACMB/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/TJASA/TJAGEN/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/TJASA/TJALKA/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/TJASA/TJAOBF/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/TJASA/TJASTM/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/TJASA/TJATTG/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/TJASA/TJATVG/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/TRJCTR/TCTCDC/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/TRJCTR/TCTCLM/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/TRJCTR/TCTDTE/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/TRJCTR/TCTEST/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/TRJCTR/TCTFFC/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/TRJCTR/TCTLGC/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/TRJPLN/TPLCEN/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/TRJPLN/TPLFBT/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/TRJPLN/TPLFRT/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/TRJPLN/TPLLCO/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/TRJPLN/TPLTJC/*.c \
	SWC_ALGO/LCF/01_Source_Code/LCF/VDPR/VDPDRV/*.c \
```

## Developments

if you want to develop with this repo, please checkout all required submodule  
```bash
git clone --recursive git@github-am.geo.conti.de:ADAS/MFC5J3_C385_LCF100.git
```  
or if you have cloned, update[ --init] submodule  
```bash
git submodule update
# or
git submodule update --init
```

### Use with Visual Studio 2010

#### Build Visual Studio solution

- run these commands:
  ```bash
  cd 03_Workspace/Component_Workspace/LCF
  
  # replace MFC5J3 with your want to build project name
  scons.bat project=MFC5J3 lcf_ide_msvc
  ```  

- Open VS sln
  you can find .sln file in 03_Workspace/Component_Workspace/00_Projects/**MFC5J3**/LCF_sim  
  > Attention: **MFC5J3** is base your build project name