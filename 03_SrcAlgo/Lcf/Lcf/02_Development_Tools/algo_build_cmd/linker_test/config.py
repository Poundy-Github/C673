##############################################################################
import sys


##############################################################################

TargetsToBuild = ["ti_c674x", "ti_arp32","ti_cortex_a8"]

Components = [\
'srl',\
'cml',\
'hla',\
'sr',\
'tsa',\
'ld',\
'cb',\
'ecm',\
'cipp',\
'emo',\
'vdy',\
'fct',\
'em',\
'vcl',\
'vodca',\
'pc',\
'cct',\
'gs',\
'asf',\
'ped',\
'pv'\
]

CMPs_Target = {"ti_c674x":['cb', 'cct', 'cipp', 'ecm', 'em', 'fsd', 'gen', 'hla', 'ld', 'memo', 'pc', 'ped', 'pv', 'sac', 'scb', 'sib', 'vcl', 'vodca'],
               "ti_arp32":['cb', 'cipp', 'hla', 'ld', 'pc', 'scb', 'sib', 'vodca'],
               "ti_cortex_a8":['cct', 'memo', 'pc', 'pv', 'semo', 'sr', 'tsa'],
               "ti_cortex_a15":[]}

Excluded_Wrappers = {"ti_c674x":['pv_wrp', 'sac_wrp'],
               "ti_arp32":['pv_wrp', 'sac_wrp'],
               "ti_cortex_a8":['pv_wrp', 'sac_wrp','sr_wrp','sr_wrp_a','sr_wrp_b','memo','semo'],
               "ti_cortex_a15":[]}
               
Generate_Main = "ON"


Compile_Wrappers = "ON"

Compile_Aux = "OFF"


Compile_Main  = "ON"

Debug = "OFF"

Lib_SCAN = "OFF"

LINK = "ON"

