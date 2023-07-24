----------------------------
TI Code Composer Studio v5.x
    VISION HIGH SUPPORT
----------------------------

I. Requirements:
----------------

  Texas Instruments Code Composer Studio 
    Version: 5.5.0.00077


II. Files in this package:
-------------------------

  [a] readme.txt                                  -> This file.
  [b] ADAS-S28.xml                                -> Platform support file (sufficient for CCSv6)
  [c] CCS_CSP_ADAS_S28_ES1.0_NDA_TRM_vA_gels7.zip -> Chip Support Package


III. Description
---------------

To launch VH28 EVMHIL projects with CCSv5 the chip support must be added.
Therefore the files [b] and [c] must be installed.

a) Copy the following file:
   ADAS-S28.xml -> <CCSv5-install-dir>\ccs_base\common\targetdb\devices

b) Unpack the following file:
   CCS_CSP_ADAS_S28_ES1.0_NDA_TRM_vA_gels7.zip

c) Follow the instructions in "CSP_USER_MANUAL_v1.0.pdf"
