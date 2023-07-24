# This file has been transformed in order to be component oriented.
# The aim is to describe here the components which need courage test frames.
# The listing of test frames will be done in component folder
# for example in 05_Testing\05_Test_Environment\Dynamic_Tests\DPUFF\Courage\test_frames.json
# Please adapt or add one test_frames.json for your component XXX
# in your component test folder 05_Testing\05_Test_Environment\Dynamic_Tests\XXX\Courage\

default_enabled = True

courage_components = {
    'common': [
        {'component': 'DPUCDR'       , 'enabled': default_enabled},
        {'component': 'DPUCOM'       , 'enabled': default_enabled},
        {'component': 'DPUFF'        , 'enabled': default_enabled},
        {'component': 'DPUHWIF'      , 'enabled': default_enabled},
        {'component': 'DPUIA'        , 'enabled': default_enabled},
        {'component': 'DPUIC'        , 'enabled': default_enabled},
        {'component': 'DPUINFRA'     , 'enabled': default_enabled},
        {'component': 'DPUOSW'       , 'enabled': default_enabled},
        {'component': 'DPUSERVICE'   , 'enabled': default_enabled},
        {'component': 'DPUSPI_DRIVER', 'enabled': default_enabled},
        {'component': 'DPUSM'        , 'enabled': default_enabled},
        {'component': 'MTSI_VH'      , 'enabled': default_enabled},
        {'component': 'RTA_VH'       , 'enabled': default_enabled},
        {'component': 'RTL_VH'       , 'enabled': default_enabled},
        {'component': 'SAP_VH'       , 'enabled': default_enabled},
        {'component': 'SAP'          , 'enabled': default_enabled},
        {'component': 'IPC_BASE'     , 'enabled': default_enabled},
        {'component': 'IPC_SLAVE'    , 'enabled': default_enabled},
        {'component': 'HLA'          , 'enabled': default_enabled},
        {'component': 'LSD'          , 'enabled': default_enabled}
    ],
    'ars441': [
        {'component': 'Project_Specific/ARS441/DPUFF'        , 'enabled': default_enabled}
    ],
    'hfl110': [
        {'component': 'DPUIC'        , 'enabled': default_enabled},
        {'component': 'DPUFF'        , 'enabled': default_enabled}
    ],
    'mfc431': [
        {'component': 'DPUIC'        , 'enabled': default_enabled},
        {'component': 'DPUFF'        , 'enabled': default_enabled},
        {'component': 'Project_Specific/MFC431/DPUIC_V1'        , 'enabled': default_enabled},
        {'component': 'Project_Specific/MFC431/DPUSERVICE'      , 'enabled': default_enabled}
    ],
    'mfc431ta19': [],
}
