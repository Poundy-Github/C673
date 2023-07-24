//Doxygen code for landing page.
/**
 @mainpage   Headlight Assist Component

 # Welcome to HLA!

 ![2 GlareFreeAreas HLA](HLA_GFAs.png)

 HLA (Headlight Assist) is a component of the Continental ADAS camera software.

 Version info:
 This help file was compiled with source code checkpoint AL_HLA_06.00.04_INT-0.
 This help file was compiled with source code checkpoint \ref HLA_SW_VERSION_NUMBER in hla_ver.h . \n 

 \section hla_toc Table of Contents
   1. \ref hla_toc
   2. \ref hla_termsAndAbbreviationsPage
     1. \ref hla_termsAbbreviations_terms
     2. \ref hla_abbreviationsSection
     .
   3. \ref hla_overview
     1. \ref hla_overview_componentDescription
     2. \ref hla_overview_input_output
     3. \ref hla_overview_interdependence
     4. \ref hla_overview_OpModes
     5. \ref hla_overview_requirements
     6. \ref hla_overview_resources
     .
   4. \ref hla_exportInterfacePage
     1. \ref hla_exportInterface_staticView
       1. \ref hla_exportInterface_staticView_functions
       2. \ref hla_exportInterface_staticView_variablesTypesConstantsMacros
       .
     2. \ref hla_exportInterface_dynamicView
       1. \ref hla_exportInterface_dynamicView_mainCall
       2. \ref hla_exportInterface_dynamicView_opModes
         1. \ref hla_exportInterface_dynamicView_opModes_idle
         2. \ref hla_exportInterface_dynamicView_opModes_demo
         3. \ref hla_exportInterface_dynamicView_opModes_reset
         4. \ref hla_exportInterface_dynamicView_opModes_run
         5. \ref hla_exportInterface_dynamicView_opModes_error
         .
       3. \ref hla_exportInterface_dynamicView_errorCodes
         1. \ref hla_exportInterface_dynamicView_errorCodes_internal
         2. \ref hla_exportInterface_dynamicView_errorCodes_external
         .
       .
     .
   5. \ref hla_configuration
     1. \ref hla_configuration_compilerSwitches
     2. \ref hla_configuration_parameters
       1. \ref hla_configuration_parameters_cpars
       2. \ref hla_configuration_parameters_internal
       .
     .
   6. \ref hla_internalDesign
     1. \ref hla_internalDesign_modules
       1. \ref hla_internalDesign_modules_interdependenciesStatic
         1. \ref hla_internalDesign_modules_interdependenciesStatic_HLAFDecision
         2. \ref hla_internalDesign_modules_interdependenciesStatic_HLAFMatrix
         3. \ref hla_internalDesign_modules_interdependenciesStatic_HLAFSetLightStates
         .
       2. \ref hla_internalDesign_modules_interdependenciesDynamic
         1. \ref hla_internalDesign_modules_interdependenciesDynamicReset
         2. \ref hla_internalDesign_modules_interdependenciesDynamicRun
       .
     .
   7. \ref hla_openIssuesPage
   .

 Links:
   - The Detailed Design for ADAS Sensorics [community](http://connext.conti.de/wikis/home/wiki/Wcacd880f7de3_424a_8158_80436b7178d9?lang=en)
   - [Doxygen Documentation](http://www.stack.nl/~dimitri/doxygen/index.html)
   - [PlantUML Documentation](http://plantuml.com/sitemap)
   - The home page of HLA team: [HLA/LSD wiki](http://connext.conti.de/wikis/home?lang=de-de#!/wiki/HLA%20wiki)
   - The home page of Processing 2 group: [Camera Processing 2 - Wiki](https://cws7.conti.de/content/11005621/Team%20Documents)
   - The home page of sensorics department: [Sensorics Community](http://connext.conti.de/communities/service/html/communitystart?communityUuid=07209aed-4646-46d3-bdad-280e9c2dffae)
   - ADAS Development Process: [ADAS Process Map 2.3] https://processcenter.auto.contiwan.com/pkit/process/setup.do?project_id=37687
*/
// Doxygen code for terms and abbreviations chapter
/**
 \page hla_termsAndAbbreviationsPage Terms and Abbreviations
 \tableofcontents

 \section hla_termsAbbreviations_terms Terms


 | Term                  | Definition                                                                                    |
 | :-------------------- | :-------------------------------------------------------------------------------------------- |
 | GlareFreeArea         | Cut-out areas of high beam which should not be illuminated.                                   |
 | Light                 | Each intensity pyramid of regions generates a light, investigated in more detail.             |
 | LightObject           | Tracked and classified lights across several cycles.                                          |
 | OpMode                | Operational Mode of an component. OpMode order is defined in the sensor architecture. Each OpMode has its specific purpose(described by OpMode name)|

 \section hla_abbreviationsSection Abbreviations and Acronyms

   | Abbreviation  | Meaning                                                                                               |
   | :------------ | :---------------------------------------------------------------------------------------------------- |
   | CB            | Camera Blockage - software component to detect camera blockage, condensation and weather              |
   | CCT           | Common Camera Toolbox - software component providing commonly used stuff like image fingerprint       |
   | CML           | Common Math Library - software component providing commonly used mathematical stuff                   |
   | CPAR          | Coding PARameter - codable parameter for adapting functions to customer needs                         |
   | DPU           | Data Processing Unit - processor where all algorithms are running                                     |
   | EM            | Environment Model - software component to track detected objects                                      |
   | GFA           | GlareFreeArea - see \ref hla_termsAbbreviations_terms                                                             |
   | GS            | Global Scheduler - software component taking care of scheduling all algorithms in right order         |
   | HLA           | Headlight Assist - software component to influence the headlights' beam depending on environment      |
   | IPC           | Inter Processor Communication - software component responsible for data exchange between IuC and DPU  |
   | IuC           | Infrastructure micro Controller - processor responsible for device in/output like CAN messages and NVM|
   | LD            | Lane Detection - software component detecting lane markers such as lines or Bots' dots.               |
   | LSD           | Light Source Detection - software component to detect, track and classify any detectable light source |
   | MEMO          | Mono Ego Motion - software component to estimate the host vehicle's dynamics from the video image.    |
   | NVM           | Non Volatile Memory - persistent memory even after power cycle. Calibration or hot pixels are stored there |
   | RTE           | RunTime Environment - common interface between software components                                    |
   | SR            | Sign Recognition - software component to detect signs                                                 |
   | TSA           | Traffic Sign Assist - software component hosting driver assistance function on top of SR              |
   | VDY           | Vehicle Dynamics - software component hosting all |

   More abbreviations can be found on this [wiki] (http://connext.conti.de/wikis/home?lang=de-de#!/wiki/W5846a6bcfafb_4370_a9be_84036c9a5c41/page/Acronyms%20and%20Abbreviations).
*/
//Doxygen code for Overview chapter
/**
 \page hla_overview    Overview
 \tableofcontents

 \section hla_overview_componentDescription  Component Description
 HLA is responsible for:
   - Filtering for relevant objects (oncoming, preceding vehicles) in LSD LightObjects and EM object list and clustering to GFAs
   - Provide high beam recommendation and corresponding turn-off reasons
   - Provide headlight dimming areas
   - Smooth switching between high beam on/off and partly on by different switch-on delays
   - Special handling in case of blockage and bad weather (fog, heavy rain) situations
   - Special functional behavior in city, tunnel and highway scenarios

 \section hla_overview_input_output Inputs and Outputs

 The data structures for exchange between HLA and its peer components is defined in the file rte_type.h which is defined on a global 
 level and included by all components.


 The request ports (inputs) of the HLA component are listed in reqHlaPrtList_t, declared in hla_ext.h. \n
 The provide ports (outputs) of the HLA component are listed in proHlaPrtList_t, declared in hla_ext.h. 

 \section hla_overview_interdependence Component Interdependencies


 The following figure shows all components HLA has interdependencies with. 

 \startuml hla_Component_Interdependencies.png
   title HLA Component Interdependencies Diagram
   [CB   COMPONENT] as CB
   [CCT  COMPONENT] as CCT
   [CML  COMPONENT] as CML
   [EM   COMPONENT] as EM
   [GS   COMPONENT] as GS_IN
   [GS   COMPONENT] as GS_OUT
   [HLA  COMPONENT] as HLA
   [IPC  COMPONENT] as IPC_IN
   [IPC  COMPONENT] as IPC_OUT
   [LSD  COMPONENT] as LSD
   [MEMO COMPONENT] as MEMO
   [RTE  COMPONENT] as RTE
   [SR_A COMPONENT] as SR
   [VDY  COMPONENT] as VDY

   ' Request port definitions
   () "pBaseCtrlData"          as ReqPortBaseCtrlData
   () "pCParHla"               as ReqPortCpars
   () "pHlaBusInputSignals"    as ReqPortHlaBusInputSignals
   () "pLsdEnvironmentData"    as ReqPortLsdEnvironmentData
   () "pLsdLightObjectList"    as ReqPortLsdLightObjectList
   () "pLsdLightList"          as ReqPortLsdLightList
   () "pBlockage"              as ReqPortBlockage
   () "pEMObjectsList"         as ReqPortEMObjectsList
   () "pMonoCalibrationRRoi"   as ReqPortCalibrationRRoi
   () "pVehicleDynamics"       as ReqPortVehicleDynamics

   ' Provide port definitions
   () "pCompState"             as ProPortCompState
   () "pHeadlightControl"      as ProPortHeadlightControl

   GS_IN   -down-> ReqPortBaseCtrlData: provide
   IPC_IN  -down-> ReqPortCpars: provide
   IPC_IN  -down-> ReqPortHlaBusInputSignals: provide
   LSD     -down-> ReqPortLsdEnvironmentData: provide
   LSD     -down-> ReqPortLsdLightObjectList: provide
   LSD     -down-> ReqPortLsdLightList: provide
   CB      -down-> ReqPortBlockage: provide
   EM      -down-> ReqPortEMObjectsList: provide
   MEMO    -down-> ReqPortCalibrationRRoi: provide
   VDY     -down-> ReqPortVehicleDynamics: provide

   HLA  -up-( ReqPortBaseCtrlData: use
   HLA  -up-( ReqPortCpars: use
   HLA  -up-( ReqPortHlaBusInputSignals: use
   HLA  -up-( ReqPortLsdEnvironmentData: use
   HLA  -up-( ReqPortLsdLightObjectList: use
   HLA  -up-( ReqPortBlockage: use
   HLA  -up-( ReqPortEMObjectsList: use
   HLA  -up-( ReqPortCalibrationRRoi: use
   HLA  -up-( ReqPortVehicleDynamics: use
   HLA  -up-( CML: use
   HLA  -up-( CCT: use
   HLA  -up-( RTE: use

   HLA  -down-> ProPortCompState: provide
   HLA  -down-> ProPortHeadlightControl: provide

   GS_OUT   -up-(   ProPortCompState: use
   IPC_OUT  -up-(   ProPortHeadlightControl: use
   SR       -up-(   ProPortHeadlightControl: use
 \enduml
 

  HLA uses the functionality of the Common Math Library (CML component) for basic mathematical calculations. 
  The COMMON component includes the definition of the RTE and provides service functions to all components.\n\n
  
  The base software provides informations to HLA from the CAN bus and NVM like CPAR values, NVM data and custom input signals.\n
  The Global Scheduler (GS component) provides the operation modes of the components.\n
  HLA is using the vehicle informations about the movement of the car from VDY component (e.g. speed, yaw angle). \n
  Furthermore HLA needs information about the weather-state and camera blockage from Camera Blockage component.
  
  HLA provides informations like NVM values, the component state of the algo and the output signals. 
  These are e.g. the high beam recommendation (on/off, partly off) and the corresponding turn-off reasons (oncoming, preceding, city,...)

 \section hla_overview_OpModes OpModes

 HLA supports the four main OpModes: BASE_OM_IDLE, BASE_OM_RESET, BASE_OM_RUN, BASE_OM_DEMO

 |OpMode        | HLA_OpMode           | Activity Diagram    | Sequence Diagram  |  Description                                                                                                      |
 | :----------- | :------------------- | :------------------ | :---------------- | :------------------------------------------ |
 | BASE_OM_IDLE | \ref HLA_OpModeIdle  | \ref hla_exportInterface_dynamicView_opModes_idle   |   | HLA only fills provide port headers. |
 | BASE_OM_RESET| \ref HLA_OpModeReset | \ref hla_exportInterface_dynamicView_opModes_reset  | \ref hla_internalDesign_modules_interdependenciesDynamicReset  | Initialization of all internal data storage. Shall be called once before processing starts |
 | BASE_OM_RUN  | \ref HLA_OpModeRun   | \ref hla_exportInterface_dynamicView_opModes_run    | \ref hla_internalDesign_modules_interdependenciesDynamicRun   | Mode for normal operation of HLA. All processing functions of the main and sub-components are called.|
 | BASE_OM_DEMO | \ref HLA_OpModeDemo  | \ref hla_exportInterface_dynamicView_opModes_demo   |  | Writes demo values to the output ports with valid signal state|
 | n.a          | \ref HLA_OpModeError | \ref hla_exportInterface_dynamicView_opModes_error  |  | All provide pointers shall be set to zero in this case |
  \n


 \section hla_overview_requirements Requirements
 There are HLA requirements on System Level2 and Level3 available:

 | MFC4xx                          | Location in Doors                 |Link to Doors modules                                                                          |
 | :------------------------------ | :-------------------------------- | :-------------------------------------------------------------------------------------------- |
 | L2 folder                       | /COMMON/01_RequirementSet         | doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-F-0003d181   |
 | L2 module "L2_Req_Spec_HLA"     | /COMMON/01_RequirementSet         | doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-M-0003d64f   |
 | L3 folder                       | /MFC400/L3/Algo/01_RequirementSet | doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-F-00022860   |
 | L3 L3_ALGO_Req_Spec_HLA         | /MFC400/L3/Algo/01_RequirementSet | doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-M-00028762   |
  \n

 TODO: Provide relevant customer req. specifications (TA19)

 \section hla_overview_resources Resource Usage

 The global scheduling of runtime and memory budgets is maintained in the file [MFC401_ResourceSheet.xlsm](http://ims-adas:7001/si/viewrevision?projectName=/nfs/projekte1/PROJECTS/MFC400/06%5fAlgorithm/03%5fDesign/01%5fSupporting%5fDocuments/project.pj&selection=MFC401%5fResourceSheet.xlsm).
 Therein, the budgets in terms of memory usage and run time (per core) is listed for each OpMode and for each
 project specific configuration. 
 */

//Doxygen code for Export Interface chapter
/**
 \page hla_exportInterfacePage    Export Interface

 \tableofcontents

 \section hla_exportInterface_staticView Static View

   \subsection hla_exportInterface_staticView_functions Functions
   The HLA Component exports one function: HlaExec(). \n 
   All inputs are contained in the reqHlaPrtList_t struct reqPorts. \n
   This includes an instance of the BaseCtrlData_t struct, which has an eOpMode member. \n
   This parameter controls which of the OpModes list in \ref hla_overview_OpModes is requested.

   \subsection hla_exportInterface_staticView_variablesTypesConstantsMacros Variables, Types, Constants, Macros
   Variables, Typedefs, Constants, and Macros that are visible to other components are contained and described among others in following files:
   - \ref hla_defs.h
   - \ref hla_ver.h
   - \ref hlaf_ext.h
   - \ref HLA_DecisionParameters.h
   - \ref HLA_MatrixParameters.h
   - \ref hlaf_type.h
   .

   \section hla_exportInterface_dynamicView Dynamic View
 
   \subsection hla_exportInterface_dynamicView_mainCall Main call of HLA function HlaExec
   Details to the in and output signals can be seen in the function description of \ref HlaExec. 

 @startuml ActivityHlaOpModes.png
   title Main call HLAExec in hla_main.c
   (*) --> "Initialize global variables, but only the very first time"
       --> "Increment HLA call counter (cycle counter)"
       --> "Init of error-flags and reset errors"
       --> "Minimal input checks for basic functionality like error reporting and meas freezes"
       --> if "<color:green> Min. Inputs available?" then
             -left-> [NO] "Set all provide pointers to zero \n     proPorts->pAlgoCompState          = NULL; \n    proPorts->pHlaf_HeadlightControl  = NULL;"
                 --> (*)
           else
             -down->[YES] "Set HLA SyncRef: Fills signal header list with headers of current request ports"
             --> "check OP Mode"
             "check OP Mode" ---> [BASE_OM_IDLE] "HLA_OpModeIdle"
             "check OP Mode" ---> [BASE_OM_RESET] "HLA_OpModeReset"
             "check OP Mode" ---> [BASE_OM_DEMO] "HLA_OpModeDemo"
             "check OP Mode" ---> [BASE_OM_RUN] "HLA_OpModeRun"
             "check OP Mode" ---> [default] "HLA_OpModeError"
             note left: HLA_OpModeError is default value \n if HLA is called in any other OpMode as defined or OpMode is not supported
             HLA_OpModeIdle   ---> "save (all available) input sync information"
             HLA_OpModeReset  ---> "save (all available) input sync information"
             HLA_OpModeDemo   ---> "save (all available) input sync information"
             HLA_OpModeRun    ---> "save (all available) input sync information"
             HLA_OpModeError  ---> "save (all available) input sync information"
              --> "Map component error code to overall return code"
              --> "Perform output checks"
              --> "Map all detected errors to DEM events"
              --> "Measfreeze all our outputs"
           endif
       --> (*)
 @enduml


  \subsection hla_exportInterface_dynamicView_opModes OpModes
     The HLA component implements a simple state machine by having four \ref hla_overview_OpModes. It consists of one state per OpMode. 
     These are the states in which HLA is doing something when HlaExec() is called (with valid parameters),  \n
     and idle states in between those active states during which hla is waiting for the next call.
   
     @startuml
       title HLA OpMode state transitions
       ' Start State
       [*] --> ResetState : BASE_OM_RESET
       [*] --> IdleState  : BASE_OM_IDLE
       [*] --> DemoState : BASE_OM_DEMO

       ' ResetState
       ResetState --> ResetState  : BASE_OM_RESET
       ResetState --> RunState    : BASE_OM_RUN
       ResetState --> IdleState   : BASE_OM_IDLE
       ResetState --> DemoState   : BASE_OM_DEMO

       ' RunState
       RunState --> RunState    : BASE_OM_RUN
       RunState --> ResetState  : BASE_OM_RESET
       RunState --> IdleState   : BASE_OM_IDLE
       RunState --> DemoState   : BASE_OM_DEMO

       ' Idle State
       IdleState --> IdleState  : BASE_OM_IDLE
       IdleState --> DemoState  : BASE_OM_DEMO
       IdleState --> ResetState : BASE_OM_RESET

       ' Demo State
       DemoState --> DemoState  : BASE_OM_DEMO
       DemoState --> IdleState  : BASE_OM_IDLE
       DemoState --> ResetState : BASE_OM_RESET
     @enduml
 
 \subsubsection hla_exportInterface_dynamicView_opModes_idle HLA_OpModeIdle
 In HLA_OpModeIdle the Comp state is set to "not running", the sig state set to "invalid" and algo qualifier set to "OK". \n
 Details to the in and output signals can be seen in the function description of \ref HLA_OpModeIdle. 
 
 \image html ActivityHLAOpModeIdle.png

 \subsubsection hla_exportInterface_dynamicView_opModes_run HLA_OpModeRun
 In OpModeRun input are checked, mapping RTE data from request ports to HLA input interface, \n
 execution of main functions of HLAR and HLAF and trigger DEM error events if applicable.
 Details to the in and output signals can be seen in the function description of \ref HLA_OpModeRun.\n
 
 \image html ActivityHLAOpModeRun.png

 \subsubsection hla_exportInterface_dynamicView_opModes_reset HLA_OpModeReset
 In HLA_OpModeReset the Input Check is done, learning values are copied from NVM and executes the initialization. \n
 Details to the in and output signals can be seen in the function description of \ref HLA_OpModeReset. 
 
 \image html ActivityHLAOpModeReset.png

 \subsubsection hla_exportInterface_dynamicView_opModes_demo HLA_OpModeDemo
 When OpModeDemo is called predefined values for demonstration the functionality to the generic RTE output are sent. \ref HLA_SetOutputDemo \n
 Details to the in and output signals can be seen in the function description of \ref HLA_OpModeDemo. 
 
 \image html ActivityHLAOpModeDemo.png

 \subsubsection hla_exportInterface_dynamicView_opModes_error HLA_OpModeError
 The OpMode Error is active to show an error if HLA is called with wrong, not defined or not supported OpMode is called. \n
 Details to the in and output signals can be seen in the function description of \ref HLA_OpModeError. 
 
 \image html ActivityHLAOpModeError.png

 \subsection hla_exportInterface_dynamicView_errorCodes Error Codes and DEM Events

  \subsubsection General Error Handling description
 
 HLA has implemeneted an error handling of several error levels and degradation
   - return value of HlaExec() function: The HlaExec() function returns BASE_RETURN_ERROR if HLA algo execution was not
     successful and BASE_RETURN_OK if it was successful
   - AlgoCompState: the AlgoCompState_t provide port contains an CompState_t element eCompState which follows the
     specifications rte_type.h and [DOORS-LINK]
   - DEM Events: Under certain conditions, the HLA component sends the DEM Events HLA_SERVICE_ERROR, HLA_FUSI_ERROR,
     HLA_BUS_DATA_ERROR or HLA_INTERNAL_ERROR as defined in the file Dem_IntErrIdSlv.h.

 The HlaExec() function returns BASE_RETURN_OK if eCompState == COMP_STATE_RUNNING and BASE_RETURN_ERROR otherwise.

   \subsubsection hla_exportInterface_dynamicView_errorCodes_internal Internal error handling
     The internal error handling is implemented in hla_errorhandling.c. Error definitions can be found in hla_errorhandling.h.
     
     HLA has three levels of error/degradation management. Following events for notification exist:
       - errors 
       - warnings
       - information events 
     
     Every error/warning/information defines a bit in the corresponding bit field array in the error stack (t_ErrorHandling_ErrorStack). It is required that every event is used only once in the code in order to easily locate the problem. 
     The event bits are visualized in MTS like this:
     TODO add picture of error codes????
     
     \paragraph Errors
       Error events lead to abort the algo execution, i.e. something fundamental is wrong.
       There are three possibilities when error events are issued: 
         - During input checks mandatory data is invalid or even missing.
         - During output checks major deviations from expected values is detected.
         - During algo execution something essential went wrong, e.g. Error Code of any service function.       
       
     \paragraph Warnings
       Warning events categorize serious deviations from expected behavior. But algo execution is still possible. For example:
         - Failing input checks of non-mandatory request ports
         - Repairable deviations during input or output checks
         - Deviations of \ref hla_configuration_parameters_cpars "CPARs" from default values.
       
     \paragraph InformationEvents
       Information events are "just for your information". They do not affect algo execution seriously. For example:
         - Measfreeze failed.

   \subsubsection hla_exportInterface_dynamicView_errorCodes_external External error handling
     Return value of HlaExec() is not really used, i.e. in case of errors HLA just returns something unequal to zero. But for more details internal error stack should be checked.


     \paragraph DEMEvents
       DEM event handling is implemented in hla_main.c Following DEM events, defined in Dem_IntErrIdSlv.h, are used:

       | DEM event                      | Set condition                                              | Requirement                                                                                                            |
       |--------------------------------|------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------|
       | \ref HLA_FUSI_ERROR            | FUSI input/output checks failed. (Null pointer check)      | <i>doors://rbgs854a:40000/?version=2&prodID=0&view=0000005b&urn=urn:telelogic::1-503e822e5ec3651e-O-652-00028762</i>   |
       |                                | FUSI input/output checks failed. (Version number check)    | <i>doors://rbgs854a:40000/?version=2&prodID=0&view=0000005b&urn=urn:telelogic::1-503e822e5ec3651e-O-681-00028762</i>   | 
       |                                | FUSI input/output checks failed. (Signal state checks)     | <i>doors://rbgs854a:40000/?version=2&prodID=0&view=0000005b&urn=urn:telelogic::1-503e822e5ec3651e-O-683-00028762</i>   | 
       |                                | FUSI input/output checks failed. (Signal header timestamp) | <i>doors://rbgs854a:40000/?version=2&prodID=0&view=0000005b&urn=urn:telelogic::1-503e822e5ec3651e-O-685-00028762</i>   | 
       |                                | FUSI input/output checks failed. (Add.Input Signals check) | <i>doors://rbgs854a:40000/?version=2&prodID=0&view=0000005b&urn=urn:telelogic::1-503e822e5ec3651e-O-702-00028762</i>   | 
       |                                | FUSI input/output checks failed. (Output Signals check)    | <i>doors://rbgs854a:40000/?version=2&prodID=0&view=0000005b&urn=urn:telelogic::1-503e822e5ec3651e-O-704-00028762</i>   | 
       | \ref HLA_SERVICE_ERROR         | Algo service functions for failed.                         | <i>doors://rbgs854a:40000/?version=2&prodID=0&view=0000005b&urn=urn:telelogic::1-503e822e5ec3651e-O-706-00028762</i>   |
       | \ref HLA_BUS_DATA_ERROR        | Vehicle bus signals are not trustworthy.                   | <i>doors://rbgs854a:40000/?version=2&prodID=0&view=0000005b&urn=urn:telelogic::1-503e822e5ec3651e-O-707-00028762</i>   |
       |                                | SubState of Vehicle bus signals are not trustworthy.       | <i>doors://rbgs854a:40000/?version=2&prodID=0&view=0000005b&urn=urn:telelogic::1-503e822e5ec3651e-O-714-00028762</i>   |
       | \ref HLA_INTERNAL_ERROR        | Internal error detected, e.g. Blockage invalid             | <i>doors://rbgs854a:40000/?version=2&prodID=0&view=0000005b&urn=urn:telelogic::1-503e822e5ec3651e-O-709-00028762</i>   |


     \paragraph CompState
     The AlgoCompState_t is set in \ref HLA_SetOutputDefaults(). This function is called in every cycle no matter what happens. Content of AlgoCompState provide port is defined L3 architecture:\n
     <i>doors://rbgs854a:40000/?version=2&prodID=0&view=00000015&urn=urn:telelogic::1-503e822e5ec3651e-O-24374-0001a768</i>

 The following table summarizes all CompStates that are used in HLA:
 |CompState                          | Possible Reasons                                                      |
 |---------------------------------- |--------------------------------------------------------------------   |
 |COMP_STATE_RUNNING                 | No errors reported for last OpMode call                               |
 |COMP_STATE_NOT_INITIALIZED         | An error occurred in OpMode BASE_OM_RESET. HLA is not initialized.    |
 |COMP_STATE_TEMPORARY_ERROR         | Input check for mandatory FUSI input failed, that means that algo has been initialized but is temporarily not available. |
 |COMP_STATE_PERMANENT_ERROR         | Algo is in failure mode, needs to be reinitialized by frame SW        |
 |COMP_STATE_SUCCESS                 | Algo has been initialized, but did not run yet, state after init() function |
 |COMP_STATE_REDUCED_AVAILABILITY    | Input check for NOT mandatory FUSI input failed, that means that algo is running but has reduced functionality |
 |COMP_STATE_NOT_RUNNING             | Algo has been de-activated, status after exit()                       |

 The HlaExec() function returns BASE_RETURN_OK if eCompState == COMP_STATE_RUNNING and BASE_RETURN_ERROR otherwise.
*/
//Doxygen code for Configuration chapter
/**
 \page hla_configuration    Configuration
 \tableofcontents

 \section hla_configuration_compilerSwitches Compiler switches
   Compiler switches are listed in hla_defs.h and in hla_project_defs.h. All compiler switches in the table below that do not have an active link are deactivated.
   
   | Switch                                     | Effect                                                             | Affected modules        |
   |--------------------------------------------|--------------------------------------------------------------------|-------------------------|
   | \ref HLA_PROJECT                           | Project specific implementations                                   | All                     |

 \section hla_configuration_parameters Algo parameters
   There are two kind of algo parameters:
     - Coding parameters (CPARs) can be modified in NVM directly without a software re-build.
     - Internal parameters modification only take place after a software re-build.
   
   All parameters are located in customer/project specific folders, i.e. they can be different across several projects.
   
   \subsection hla_configuration_parameters_cpars Algo coding parameters (CPARs)
     Algo coding parameters are defined in RTE in this structs: CPAR_HLAF_Parameter_t and CPAR_HLAR_Parameter_t. 
     They are initialized to default values in hla_cpar_init.c.
   
   \subsection hla_configuration_parameters_internal Algo internal parameters 
     Algo internal parameters are divided into decision and matrix parameters and can be found in HLA_DecisionParameters.c and HLA_MatrixParameters.c
     - \ref t_DecisionParameters \ref m_DecisionParameters
     - \ref t_MatrixParameters \ref m_MatrixParameters
*/
//Doxygen code for Component Level Tests
/**
 \page hla_componentTests Component Level Tests
 \todo Describe how to test the design and the implementation on component level. 

 \note Should include tests of the design itself (i.e. prove that the state 
       machine does not have dead ends) and hints towards how the implementation can be tested against the design, both in terms of
       statistical validation (KPIs) and deterministic tests. \n
       Details to come.
*/
//Doxygen code for Integration chapter
/**
 \page hla_integrationPage    Integration

 \tableofcontents

 \todo Describe here the definition of the configurations from the configuration files. Describe stepwise how to integrate the module into the system. Describe the used configuration tools.

 \note We are still figuring out a good way to do this.
*/

//Doxygen code for Internal Design chapter
/**
 \page hla_internalDesign    Internal Design

 \tableofcontents

 \section hla_internalDesign_modules   Modules 

   The HLA component consists of 3 main modules, the main, the error handler and the function module. Click the modules for a detailed view on the internal design of each module.

     - HLA_Main \ref HlaExec
     - HLA_Function \ref HLAF_v_Exec
     - HLA_ErrorHandler \ref HLA_ErrorHandling_Init


   \todo add \\ingroup tag to each file/class/define/static function/struct/enum. Instead of putting a "/// \ingroup xxx" in front of 
         each declaration you can use "/// \ingroup xxx \{" to start a block and "/// \}" to close it further down in the same file.

   \subsection hla_internalDesign_modules_interdependenciesStatic Static Module Interdependencies

   \todo This section contains a graphical representation and textual description of the data exchange between your Modules and the
         "outside world". The figure doesn't have to contain all your Models, just highlight those which require or provide data 
         that is exchanged with other components.

 @startuml                                                                                                                                                               
   title HLA Module Interdependencies                                                                                                                                    
   node "HLA Component" as hla{                                                                                                                                          
     [HLA Main] as hlamain                                                                                                                                         
     node "HLA Function" as hlafunction{                                                                                                                                 
        [HLAF EnvironmentDecision] as hlafenvdecision                                                                                                                    
        [HLAF Matrix] as hlafmatrix                                                                                                                                      
        [HLAF SetLightStates] as hlafsetlightstates                                                                                                                      
        () "HLA EnvDecisionOut" as hlafenvdecisionout                                                                                                                     
        () "HLA MatrixOut" as hlafmatrixout                                                                                                                               
     }                                                                                                                                                                   
     [HLA ErrorHandler] as hlaerrorhandler                                                                                                                               
   }                                                                                                                                                                     
   () "HLAF HeadlightControl" as hlafout                                                                                                                                 
                                                                                                                                                                         
   ' DEFINITIONS                                                                                                                                                         
   [SW\n COMPONENT] as SW                                                                                                                                                
   [CB \n COMPONENT] as Blockage                                                                                                                                         
   [EM \n COMPONENT] as EnvModell                                                                                                                                        
   [GS \n COMPONENT] as GlobalScheduler                                                                                                                                  
   [LSD \n COMPONENT] as LSDetection                                                                                                                                     
   [VDY \n COMPONENT] as VDYData                                                                                                                                         
   [NORM \n COMPONENT] as norm                                                                                                                                           
   () "Vehicle \n data" as vehdata                                                                                                                                       
   () "Base \n Control \n data" as bsctrl                                                                                                                                
   () "Algo \n State" as algostate                                                                                                                                       
   () "Blockage \n Data" as blockage                                                                                                                                     
   () "Weather \n Data" as weather                                                                                                                                       
   () "CPAR" as cpar                                                                                                                                                     
   () "NVM" as nvm                                                                                                                                                       
   () "LightObjectList" as LSDLightObjectList                                                                                                                            
   () "EnvironmentData" as LSDEnvData                                                                                                                                    
                                                                                                                                                                         
   ' CONNECTIONS                                                                                                                                                         
   hlafunction-- hlafout: provide                                                                                                                                       
   hlafunction-up- algostate                                                                                                                                            
   hlafunction-up-( nvm                                                                                                                                                  
   hlafunction-up- nvm                                                                                                                                                  
   hlamain-up-( bsctrl                                                                                                                                                
   hlafunction .up.> hlaerrorhandler : uses                                                                                                                             
   hlamain .down.> hlafunction: calls                                                                                                                                 
   hlamain .left.> hlaerrorhandler: uses                                                                                                                              
                                                                                                                                                                         
                                                                                                                                                                         
   hlafenvdecision#-up- hlafenvdecisionout                                                                                                                               
   hlafmatrix-up- hlafmatrixout                                                                                                                                         
   hlafsetlightstates-up-( hlafmatrixout                                                                                                                                 
   hlafsetlightstates-up-( hlafenvdecisionout                                                                                                                            
   LSDetection-- LSDLightObjectList: provide                                                                                                                            
   LSDetection-- LSDEnvData: provide                                                                                                                                    
   hlafunction--( LSDEnvData                                                                                                                                            
   hlafunction--( vehdata                                                                                                                                               
   hlafunction--( cpar                                                                                                                                                
   hlafunction--( blockage                                                                                                                                             
   hlafunction--( weather                                                                                                                                              
   hlafunction--( LSDLightObjectList                                                                                                                                   
   hlamain--( LSDEnvData                                                                                                                                            
   hlamain--( vehdata                                                                                                                                               
   hlamain--( blockage                                                                                                                                              
   hlamain--( weather                                                                                                                                               
   hlamain--( LSDLightObjectList                                                                                                                                    
   hlafunction--( EMobject                                                                                                                                             
   hlamain--( cpar                                                                                                                                                                                                                                                                                            
                                                                                                                                                                         
   VDYData-- vehdata: provide                                                                                                                                           
   GlobalScheduler-- bsctrl: provide                                                                                                                                    
   GlobalScheduler--( algostate: request                                                                                                                                 
   Blockage-- blockage:provide                                                                                                                                          
   Blockage-- weather:provide                                                                                                                                           
   EnvModell-- EMobject:provide                                                                                                                                         
   SW-- cpar:provide                                                                                                                                                    
   SW-- nvm:provide                                                                                                                                                     
   SW--( nvm:request                                                                                                                                                  
   norm--( hlafout                                                                                                                                                       
                                                                                                                                                                         
   note right of hlafenvdecision                                                                                                                                 
     Takes the decision dependant on environment data and set HLA behaviour for
     Speed, Brightness, City, Tunnel, Fog, Highway, TrafficStyle
   end note                                                                                                 
   note right of hlafmatrix
     Filter, mapping and clustering of relevant objects to glare free areas
   end note                                                                                                                                                      
 @enduml                                                                                                                                                         




   The main HLA function part is implemented in the HLA Function module and contains 3 main units, the "Decision" part, the "Matrix" part and the "SetLightState" part.
   Click the units for a detailed view on the internal design of each unit.

     - \ref hla_internalDesign_modules_interdependenciesStatic_HLAFDecision 
     - \ref hla_internalDesign_modules_interdependenciesStatic_HLAFMatrix
     - \ref hla_internalDesign_modules_interdependenciesStatic_HLAFSetLightStates


 \subsubsection hla_internalDesign_modules_interdependenciesStatic_HLAFDecision HLAF EnvironmentDecisions: Interdependencies
 In the unit "HLAF EnvironmentDecision" the decisions dependent on the informations from blockage, weather, vehicle data and LSD are taken.

 @startuml
 title HLAF EnvironmentDecisions
      node "HLAF EnvironmentDecisions" as hlafenvdecision{
          [HLAF EnvDecision \n Blockage] as hlafdecisionblockage
          [HLAF EnvDecision \n Speed] as hlafdecisionspeed
          [HLAF EnvDecision \n City] as hlafdecisioncity
          [HLAF EnvDecision \n Weather] as hlafdecisionweather
          [HLAF EnvDecision \n Brightness] as hlafdecisionbrightness
          [HLAF EnvDecision \n Tunnel] as hlafdecisiontunnel
          [HLAF EnvDecision \n TrafficStyle] as hlafdecisiontrafficstyle
          [HLAF EnvDecision \n Highway] as hlafdecisionhighway
      }
   () "HLAF EnvDecisionOut" as hladecisionout
   hlafenvdecision#-- hladecisionout: provide
   hlafdecisioncity-up-( LSDEnvData
   hlafdecisionhighway-up-( LSDEnvData
   hlafdecisiontrafficstyle-up-( LSDEnvData
   hlafdecisiontunnel-up-( LSDEnvData
   hlafdecisionspeed-up-( vehdata
   hlafdecisionspeed-up-( cpar
   hlafdecisionblockage-up-( BlockageData
   hlafdecisionweather-up-( WeatherData
 @enduml

 Details are defined in the function: \ref HLAF_EnvironmentDecisions



  \subsubsection hla_internalDesign_modules_interdependenciesStatic_HLAFMatrix HLAF_Matrix: Interdependencies
 The diagram gives a short overview about the HLA Matrix unit where the clustering of vehicles to GFAs is done.

 @startuml
   title HLAF Matrix
      node "HLAF_Matrix" as hlafmatrix{
         [HLAF Matrix \n PrepareObjectList] as hlafmatrixobjlist
         node "HLAF Matrix \n Main" as hlafmatrixmain{
            [HLAF Matrix \n ClusterVehicles] as hlafmatrixcluster
            [HLAF Matrix \n GFAs] as hlafmatrixgfa
         }
         () "HLAF Matrix ObjectList" as hlafmatrixlist
       }
      () "HLAF MatrixOut" as hlafmatrixout
   hlafmatrix#-- hlafmatrixout: provide
   hlafmatrixobjlist-up-( LSDLightObjectList
   hlafmatrixobjlist-up-( EMobject
   hlafmatrixobjlist#-- hlafmatrixlist: provide
   hlafmatrixmain-up-( hlafmatrixlist
 @enduml

 Details are defined in the function: \ref HLAFMatrix_Main



  \subsubsection hla_internalDesign_modules_interdependenciesStatic_HLAFSetLightStates HLAF_SetLightStates: Interdependencies
 In "HLAF_SetLightStates" all relevant states and informations for the output "HLAF HeadlightControl" are set.

 @startuml
    title HLAF SetLightStates
       node "HLAF SetLightStates" as hlafSetLightStates{
          [HLAF Decision \n KeepOff, TurnOff Reasons] as HLAFDecisionReasons
          [HLAF Decision \n SetHighbeamState] as HLAFDecisionHBState
          [HLAF Matrix \n SetTurnOffReason] as HLAFMatrixTurnOffReason
          [HLAF Matrix \n SetOutput] as HLAFMatrixOutput
          [HLAF Decision \n DimmingAreas] as HLAFDimmingArea
          () "HLAF HeadlightControl" as hlafhbctrl
          () "HLAF TurnOffReasons" as hlafturnoffs
          () "HLAF Reasons" as hlafreasons
          () "HLAF HBState" as hlafHBState
          () "HLAF DimmingAreas" as hlafdimmingareas
          HLAFMatrixOutput#-- hlafhbctrl: provide
          HLAFMatrixTurnOffReason#-- hlafturnoffs: provide
          HLAFDecisionReasons#-- hlafreasons: provide
          HLAFDecisionHBState#-- hlafHBState: provide
          HLAFMatrixTurnOffReason-up-( hlafreasons
          HLAFMatrixOutput-up-( hlafturnoffs
          HLAFMatrixOutput-up-( hlafHBState
          HLAFDimmingArea#-- hlafdimmingareas: provide
       }
  @enduml  
 
 Details are defined in the function: \ref HLAF_SetLightStates



 \subsection hla_internalDesign_modules_interdependenciesDynamic Dynamic Module Interdependencies

 The following sequence diagrams gives an overview of the dynamic behaviour of HLAs main execution function HlaExec(). \n 
 This function performs error-checks (like valid input signals etc), setting output values and dependent on the eOpMode runs the HLA in \ref hla_overview_OpModes :\n
 \ref HLA_OpModeIdle   \n
  \ref HLA_OpModeReset  \n
 \ref HLA_OpModeRun  \n
 \ref HLA_OpModeDemo \n
 \ref HLA_OpModeError \n

 \subsubsection hla_internalDesign_modules_interdependenciesDynamicReset Dynamic Module Interdependencies Opmode: Reset
 \startuml HLA_Sequence_Diagram_Reset.png
  title HLA Sequence Diagram Opmode:Reset
 
  box #Blue
  participant SW_BaseControl <<Opmode>>
  end box

  box #LightGreen
  participant HLA_Main <<function HlaExec in hla_ext.h>>
  end box

  box #Yellow
  participant HLA_ErrorHandler <<function in hla_errorhandling.h>>
  end box

  box #LightBlue
  participant HLA_Function <<function hla_exec in hlaf.h>>
  end box


  == Reset/Startup ==
  autonumber "<b>[00]"
  SW_BaseControl -> HLA_Main: <b> BASE_OM_RESET <i> <<reqPorts.pBaseCtrlData->eOpMode>>
  HLA_Main -> HLA_ErrorHandler : <b> Call HLA_ErrorHandling_Init
  activate HLA_ErrorHandler #DarkSalmon
  HLA_ErrorHandler -> HLA_Main
  deactivate HLA_ErrorHandler

   HLA_Main -> HLA_Main : <b> InputChecksk_MinimumInputs
   HLA_Main -> HLA_ErrorHandler : <b> Set / Get Error Information

 HLA_Main -> HLA_Main : <b> HLA_OpModeReset
 HLA_Main -> HLA_Main : <b> HLA_InputChecks
 HLA_Main -> HLA_ErrorHandler : <b> Set / Get Error Information
 HLA_Main -> HLA_Main : <b> HLA_SetOutputDefaults
 HLA_Main ->  HLA_Function : <b> HLAF_v_Init (pReqPorts)
 activate HLA_Function #DarkSalmon
 HLA_Function -> HLA_Main
 note right: HLAF_InitData \nHLAFMatrix_Init \nHLAFDimming_InitAreas
 deactivate HLA_Function

 \enduml
  


 \subsubsection hla_internalDesign_modules_interdependenciesDynamicRun Dynamic Module Interdependencies Opmode: Run
 \startuml HLA_Sequence_Diagram_Run.png
  title HLA Sequence Diagram Opmode:Run
 
  box #Blue
  participant SW_BaseControl <<Opmode>>
  end box

  box #LightGreen
  participant HLA_Main <<function HlaExec in hla_ext.h>>
  end box

  box #Yellow
  participant HLA_ErrorHandler <<function in hla_errorhandling.h>>
  end box

  box #LightBlue
  participant HLA_Function <<function hla_exec in hlaf.h>>
  end box


   
 == Run (every cycle) ==
 autonumber "<b>[00]"
 SW_BaseControl -> HLA_Main: <b> BASE_OM_RUN <i> <<reqPorts.pBaseCtrlData->eOpMode>>
 HLA_Main -> HLA_Main : <b> HLA_InputChecks
 HLA_Main -> HLA_ErrorHandler : <b> Set / Get Error Information
 HLA_Main -> HLA_Main : <b> HLA_SetOutputDefaults
 HLA_Main ->  HLA_Function : <b> Call HLAF_v_Exec()
 activate HLA_Function #DarkSalmon
 deactivate HLA_ErrorHandler
 HLA_Function -> HLA_Function: <b> Call HLAF_FillData()
 HLA_Function -> HLA_Function: <b> Call HLAUtilsAddDetailedRtaEvent(Start)
 HLA_Function -> HLA_Function: <b> Call HLAF_EnvironmentDecisions()
 HLA_Function -> HLA_Function: <b> Call HLAUtilsAddDetailedRtaEvent(End)
 HLA_Function -> HLA_Function: <b> Call HLAUtilsAddDetailedRtaEvent(Start)
 HLA_Function -> HLA_Function: <b> Call HLAFMatrix_Main()
 HLA_Function -> HLA_Function: <b> Call HLAUtilsAddDetailedRtaEvent(End)
 HLA_Function -> HLA_Function: <b> Call HLAF_SetLightStates()
 HLA_Function -> HLA_Main
\enduml
*/
//Doxygen code for Open Issues
/**
 \page hla_openIssuesPage Open Issues
 In case you have the PTC client installed please run following command which opens HLA dashboard:
    - im rundashboard -g "[LSD/HLA]: Dashboard"
 
 Generated to do list from code comments: \ref todo
*/
