// Doxygen code for landing page.
/// @mainpage   VEHICLE DYNAMICS OBSERVER COMPONENT
///
/// # Welcome to VDY!
///
/// VDY (VEHICLE DYNAMICS OBSERVER COMPONENT) is a component of the Continental ADAS camera software.
///
///
/// Version info: 
/// Version information is found in vdy_ver.h
///
///
/// \section vdy_toc Table of Contents
///	1. \ref vdy_toc
///	2. \ref vdy_termsAndAbbreviationsPage
///		1. \ref vdy_termsSection
///		2. \ref vdy_abbreviationsSection
///		.
///	3. \ref vdy_overViewPage
///		1. \ref vdy_overview_CompDescription
///		2. \ref vdy_overview_input_output
///		3. \ref vdy_overview_interdependence
///		4. \ref subComponentDependencies
///		5. \ref vdy_overview_OpModes
///		6. \ref vdy_overview_requirements
///		7. \ref vdy_overview_resources
///		.
///	4. \ref vdy_exportInterfacePage
///		1. \ref vdy_exportInterface_staticView
///			1. \ref vdy_exportInterface_staticView_functions
///			2. \ref vdy_exportInterface_staticView_variablesTypesConstantsMacros
///			.
///		2. \ref vdy_exportInterface_dynamicView
///			1. \ref vdy_exportInterface_dynamicView_OpModes
///			2. \ref vdy_exportInterface_dynamicView_ErrorCodes
///			.
///		.
///	5. \ref vdy_configurationPage
///	6. \ref vdy_designPage
///		1. \ref vdy_internalDesign_modules
///			1. \ref vdy_internalDesign_modules_interdependenciesStatic
///			2. \ref vdy_internalDesign_modules_interdependenciesDynamic
///			3. \ref VDYMainModule
///			4. \ref VDYMonModule
///			5. \ref SWA_LAOffsetEstimation
///			6. \ref YWRSensorSignalProcessing
///			7. \ref WheelSpeedSignalProcessing
///			8. \ref VDYVelCorr
///			9. \ref CommonFunctions
///			10. \ref VDYAye
///			11. \ref VDYGye
///			12. \ref VDYSye
///			13. \ref VDYWye
///			14. \ref VDYYe
///			15. \ref VDYMotSt
///			16. \ref VDYWpp
///			17. \ref VDYVe
///			18. \ref VDYSae
///			.
///		.
///	.
///
/// Links:
///   - The Detailed Design for ADAS Sensorics [community](http://connext.conti.de/wikis/home/wiki/Wcacd880f7de3_424a_8158_80436b7178d9?lang=en)
///   - [Doxygen Documentation](http://www.stack.nl/~dimitri/doxygen/index.html)
///   - [PlantUML Documentation](http://plantuml.com/sitemap)
///   - The home page of VDY team: [VDY](http://connext.conti.de/wikis/yourTeamWiki.html)
///   - The home page of Processing 4 group: [Camera Processing 4 - Wiki](http://connext.conti.de/wikis/home?lang=de-de#!/wiki/Camera%20Processing%204%20-%20Wiki/page/Camera%20Processing%204%20-%20Wiki)
///   - The home page of sensorics department: [Sensorics Community](http://connext.conti.de/communities/service/html/communitystart?communityUuid=07209aed-4646-46d3-bdad-280e9c2dffae)
///   - ADAS Development Process: [ADAS Process Map 2.3] https://processcenter.auto.contiwan.com/pkit/process/setup.do?project_id=37687

/// \page vdy_termsAndAbbreviationsPage Terms and Abbreviations
///
/// \tableofcontents
///
/// \section vdy_termsSection Terms
///
///
/// | Term                  | Definition                                                                                    |
/// | :-------------------- | :-------------------------------------------------------------------------------------------- |
/// | VDY                   | Vehicle Dynamics                                                                              |
/// | SWA                   | Steering wheel angle (input signal for VDY)                                                   |
/// | NVM                   | Non Volatile Memory                                                                           |      
/// | COG                   | Centre of Gravity                                                                             |                                                                  
///
/// \section vdy_abbreviationsSection Abbreviations and Acronyms
///
///
/// | Abbreviation  | Meaning                                                                                               |
/// | :------------ | :---------------------------------------------------------------------------------------------------- |
/// | EM            | Environment Model - software component that uses yaw rate from VDY to track detected objects          |
/// | EBA           | Emergency break assist - software component to emergency breaking                                     | 
///	| ACC			| Adaptive Cruise Control																				|
///	| LD			| Lane Departure																						|                   
/// | NORM          | Functions - Frame software that reads the data from sensor on the BUS and then performs the normalization operation and then write the data on the RTE interface so that VDY can read it from there.|

// Doxygen code for Overview chapter
/// \page vdy_overViewPage    Overview
/// \tableofcontents
///
/// \section vdy_overview_CompDescription  Component Description
///	VDY is responsible for,
///		- Estimation of  vehicle dynamic signals like Longitudinal Velocity & Acceleration, Yaw rate and Lateral Acceleration by Offset Compensation, Filtering and Plausibilization.\n
///		- Vehicle path prediction by providing Curvature estimation & Motion State detection.\n
///		- Set the DEMs/Errors in case of
///			- Invalid inputs
///			- Estimated signal / Variance is crossing threshold
///			- Input parameters out of range
///			- Input signals out of range
///			- NVM data out of range
///			.
///		.
///	The VDY Software component estimates the Vehicle DYnamics (VDY) based on Single Track Model. VDY is called every 20ms. Various external/internal input inertial sensoric signals such as steering wheel angle, yaw rate, wheel velocities, lateral acceleration and etc., are processed for the estimation of the vehicle dynamics. \n
///	Because of the availability and the quality of the input signals the VDY component is separated into separate three layers.\n
///	1. First layer "Signal processing" is preprocessing the input signals, removes offsets, and supports for each input signal a yaw rate and a corresponding variances.
///	2. Second layer "State estimation" consist of three modules:
///		- The yaw rate fusion module using the preprocessed yaw rates
///		- The velocity estimation
///		- The motion state estimation
///		.
///	3. The Last layer "Supplementary data" estimates some additional date based on the information from the above layers, like curve, and lateral acceleration.\n
///		- The VDY software component is designed to be flexible towards the infrastructure of the vehicle. Not all input sensors are available in all vehicles, yet any additional source reflecting the dynamic state of the vehicle should be used. \n
///		.
///	.
///	There shall be a module for any potential vehicle dynamics sensor handling the sensor specifics. These modules should be configurable. \n
///	The state variables reflecting the complete dynamic state of the vehicle are the yaw rate, longitudinal velocity and side slip angle. Any other variable, such as curvature, lateral acceleration, longitudinal acceleration, etc. can be derived from these variables. \n
///
/// \section vdy_overview_input_output Inputs and Outputs
///	- <b> VDY Component takes several sensor input signals </b> 
///		- Gier Yaw Rate
///			- Angular velocity about the vertical vehicle axis
///			- Range: -2.61799 to +2.61799 rad/s 
///		- Steering Wheel Angle
///			- Angular displacement of the steering wheel measured from straight-ahead position. 
///			- Range: (-1.5708 to +1.5708)*SWRatio rad; SWRatio is Steering Wheel Ratio parameter
///		- Lateral Acceleration
///			- Acceleration of vehicle perpendicular to the longitudinal vehicle axis, contains parts of gravity given by transversal slope
///			- Range: -15 to +15 m/s^2
///		- Four Wheels Speeds (Front-Left, Front-Right, Rear-Left and Rear-Right)
///			- Angular velocity of the wheel about its spin axis. Wheel velocity is an equivalent measure derived from wheel speeds in consideration of dynamic circumference.
///			- Range: 0 to 115 m/s
///		- External Vehicle Velocity (provided by the customer)
///			- Vehicle Velocity provided by the customer
///			- Range: 0 to 115 m/s
///		- External Vehicle Longitudinal Acceleration (provided by the customer)
///			- Acceleration of vehicle in direction to the longitudinal vehicle axis, contains parts of gravity given by longitudinal slope
///			- Range: -15 to +15 m/s^2
///		- Four Wheels Rotation Directions
///			- Rotation direction of wheel spin
///			- Forward, Reverse or Standstill
///		- External Vehicle Direction (provided by the customer)
///		- Four wheels Ticks( or Pulse)
///			- Accumulated pulses generated by sensor ring connected to revolving wheel. Traveled distance is an equivalent measure derived from wheel pulse counter in consideration of wheel ticks per revolution and dynamic rolling circumference.
///			- Range: 1 to 250
///		- Gear Position
///			- Active gear stage
///			- ACT_GEAR_POS_NEUTRAL(0), ACT_GEAR_POS_PARKING(1), ACT_GEAR_POS_FORWARD(2), ACT_GEAR_POS_REVERSE(3)
///		- Brake Torque
///			- Torque, equivalent to pressure in main brake cylinder
///		- Parking Brake
///			- Park brake state
///			- STAT_INACTIVE(0), STAT_ACTIVE(1)
///	- <b> VDY Vehicle Input Parameters </b> 
///		- Understeer / Self Steering Gradient
///			- Rate of change in steering wheel angle with respect to change in steady-state lateral acceleration.
///			- Range: 0.00174533 to 0.00698132 rad s^2/m
///		- Steering ratio
///			- Rate of change of steering wheel angle at given steering wheel trim position, with respect to change in average steer angel of a pair of steered wheels. In case of active steering systems this parameter is dependent additional vehicle states
///			- Range: +1 to +500
///		- Wheel base
///			- Longitudinal distance between  the center of tire contact of pair of wheels on same vehicle side
///			- Range: +2 to +4.5 m
///		- Track width front/rear
///			- Lateral distance between the center of tire contact of pair of wheels on same vehicle axle
///			- Range: 1 to 2m
///		- Vehicle/curb weight
///			- The weight of a fueled automobile with standard equipment but without cargo or passengers
///			- Range: 500 to 7500 kg
///		- Center of gravity height
///			- Imaginary point where the total weight of the body may be thought to be concentrated
///			- Range: +0.02 to +1 m
///		- Axle load distribution
///			- The ratio of the vertical load at rear axle to total vehicle vertical load
///			- Range: +0.2 to +0.8
///		- Wheel Load Dependency Front/Rear Axle
///			- Change of difference in wheel circumferential speed resulting from this load transfer during cornering at front/rear axle
///			- Range: 0 to +3.0 
///		- Wheel Circumfence
///			- Dynamic wheel rolling circumference
///			- Range: 1.5 to 2.5m
///		- Wheel ticks per revolution
///			- Number of sensor pulses per wheel revolution
///			- Range: 1 to 250
///	- <b> VDY Output </b> (with variances)
///		-  <b> Longitudinal Dynamics </b> 
///			- Vehicle Velocity 
///			- Vehicle Acceleration
///				- Longitudinal Dnamics are computed based upon either Input Wheel Speed or Wheel Tick Signals (Wheel Pre Processing).
///				- If External velocity and acceleration is being provided by the customer, then it can be directly used as an output from VDY.
///		- <b> Lateral Dynamics </b> 
///			- Yaw Rate
///			- Lateral Acceleration
///			- Vehicle Curvature
///			- Driver Intended Curvature
///				- Lateral Dynamics are computed based upon Input Yaw Rate, Lateral Acceleration, Steering Wheel Angle and Wheel Speed signals. All of these signals except wheel speeds must be available to compute the above mentioned outputs. Wheel Speed signals if available are used to increase the accuracy of the computed Outputs.
///				- Also, it should be known whether these input signals are offset compensated or not. Based upon this info VDY will switch on or off VDY offset computation algorithm.
///		- <b> Motion State </b> 
///			- Motion State is predicted based upon the following inputs 
///				- Velocity (Either External input or internally computed)
///				- Yaw Rate (Internally computed)
///				- Wheel Ticks
///				- Wheel Direction
///				- Brake Torque
///				- Gear Position
///				- Parking Brake
///			1. Either Wheel Direction or Gear position must be available. Velocity and Yaw Rate information is must. Other signals increase the accuracy of the computation.
///			2. If External Motion State or Direction info is being provided by the customer, then it can be directly used as an output from VDY.
///			.
///		.   
///	.
///
/// The data structures for exchange between vdy and its peer components is defined in the file rte_type.h which is defined on a global 
/// level an included by all components.
///
/// The request ports (inputs) and the provide ports (outputs) of the VDY component are listed in reqVdyPrtList_t and proVdyPrtList_t respectively, declared in vdy_ext.h. 
///
/// |_____VDY Component Input Output ____|
/// |:--------------------------------------------------------------| 
/// |																|
/// |Request_Ports                 | Provide_Ports					|
/// |:------------------------------|:------------------------------|
/// |pBaseCtrlData					|pAlgoCompState					|
/// |pNVMRead						|pNVMWrite						|
/// |pVehicleInputSignals			|pVDYErrors						|
/// |pVehicleParameter				|pVDYEstCurves					|
/// |								|pVDYOffsets					|
/// |								|pVehicleDynamicSignals			|
///
/// \startuml vdy_Component_Interdependencies2.png
///   skinparam componentStyle uml2 
///   title VDY Component Description Diagram
///
///
///
/// package "BUS" {
/// [<b>CAN-BUS</b> \n Vehicle Bus Interface] as can
/// [<b>NVM Data</b>] as nvm 
/// }
/// package "NORM" {
/// [<b>NORM</b> \n (Raw Data -> Engg. Units & Engg. Data -> VDY Compatible Units)] as norm
///	[<b>Signals & States:</b> \n 1. 4 Wheels Speeds \n 2. Longitudinal & Lateral Acceleration \n 3. Yaw Rate \n 4. Brake Actuation \n 5. Gear Position \n 6. 4 Wheels Ticks Counts \n 7. 4 Wheels Directions 8. ABS / Traction Control \n 9. Steering - Wheel angle ] as signals
///	[<b>NVM Read / Write</b>] as nvmRead
///	[ <b> Parameters: </b>\n 1. Wheel Base \n 2. Steer Ratio \n 3. Axle Load Distance \n 4. Wheel Load Dependency \n 5. Front & Rear Track Width \n 6. Self-Steer Gradient \n 7. Front & Rear Axle Distances \n 8. Vehicle Weight] as parameters
/// }
///	package "RTE INPUT" {
///	[<b>Real Time Environment Interface</b>] as rte1
///	}	
///	package "VDY" {
///	"<b>V</b>ehicle <b>DY</b>namics Observer Component \n VDY is called every <b>20ms</b> by GS \n VDY reads input and writes output every <b>20ms</b>"
/// [<b>Checks:</b> \n 1. Range Checks \n 2. Gradient Checks \n 3. Validation] as checks
/// [<b>Offset Compensation</b>] as oc
/// [<b>Computation:</b> \n 1. Adaptive Filtering \n 2. Fusion \n 3. Parameter Estimation \n 4. Path Estimation Estimation ] as autoCode
/// [<b>Outputs:</b> \n 1. Longitudinal & Lateral Acceleration \n 2. Longitudinal Vehicle Velocity \n 3. Yaw Rate \n 4. Motion State \n 5. Curvature \n 6. Curve Error \n 7. Curve Confidence] as output
/// [<b>NVM Read / Write</b>] as nvmWrite
///	[<b>Faults / DEM</b>] as dems
///	}
///	package "RTE OUTPUT" {
///	[<b>Real Time Environment Interface</b>] as rte2
///	}
///
///
/// [<b>ACC Component</b>] as acc
/// [<b>EBA Component</b>] as eba
/// [<b>EM Component</b>] as em
/// [<b>LD Component</b>] as ld
/// [<b>CML Component</b>] as cml
///
/// rte2 #=up=> acc
/// rte2 #=up=> eba
/// rte2 #=up=> em
/// rte2 #=up=> ld
/// output #=up=> rte2
/// autoCode #=right=> output
/// oc #=right=> autoCode
/// checks #=up=> oc
/// autoCode #=down=> nvmWrite
/// autoCode #=down=> dems
/// autoCode .-left-> cml : Use
/// rte1 #=up=> checks : Input
/// signals #=up=> rte1
/// nvmRead <==> rte1
/// parameters #=up=> rte1
/// norm #=up=> signals
/// norm #=up=> nvmRead
/// norm #=up=> parameters
/// can #=up=> norm
/// nvm #=up=> norm
/// checks #=left=> dems
/// nvmWrite <==> rte1
/// dems #=down=> rte1
///
/// 
/// \enduml
/// 
/// \section vdy_overview_interdependence Component Interdependencies
///
/// The following figure shows all components VDY has interdependencies with. 
///
/// \startuml vdy_Component_Interdependencies.png
///   skinparam componentStyle uml2 
///   title VDY Component Interdependencies Diagram
///   [EM COMPONENT] as EM
///   [EBA COMPONENT] as EBA
///   [ACC COMPONENT] as ACC
///	  [LD COMPONENT] as LD
///	  [SR COMPONENT] as SR
///   [VDY COMPONENT] as VDY
///   [FCU COMPONENT] as FCU
///   [VCS COMPONENT] as VCS
///   [GS COMPONENT] as GS
///
///	() "Request Port" as RequestPort
/// () "Provide Port" as ProvideSignalPort
///
///	
///   EM #.down-> ProvideSignalPort : request
///   EBA #.down-> ProvideSignalPort : request
///   ACC #.down-> ProvideSignalPort : request
///   LD #.down-> ProvideSignalPort : request
///   SR #.down-> ProvideSignalPort : request
///   VDY #-up-> ProvideSignalPort: VehDyn Output
///   VDY #.down-> RequestPort: request
///   GS #-up-> RequestPort: Base Control Data
///   FCU #-up-> RequestPort: Input Sensor Signals
///   VCS #-up-> RequestPort: Input Vehicle Parameters
///
///
///
/// \enduml
///
/// \n \n \n \n
///
///
/// \section subComponentDependencies Sub-Component Interdependencies
/// \n \n
/// 
/// DOORS link: doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-77-00026448
///
///	@startuml
/// note left
///	Sub-Components dependencies
/// <img:images\InterComponentDependency1.png>
/// end note
/// @enduml
///
/// \n \n \n \n
///
/// \section vdy_overview_OpModes OpModes
///
/// The VDY component is called in 2 active OpModes.\n
///   1.BASE_OM_RESET \n
///   2.BASE_OM_RUN \n
/// and Two other OpModes very rarely to be called with are \n
///   3.BASE_OM_IDLE \n
///   4.BASE_OM_DEMO \n
/// These modes are called by the GS(Global Scheduler) using the eOpMode. 
///
/// \section vdy_overview_requirements Requirements
///
/// doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-M-000221c8
///
/// \section vdy_overview_resources Resource Usage
///
/// The global scheduling of runtime and memory budgets is maintained in the files
/// [MFC510_ResBudget](http://ims-adas:7001/si/viewrevision?projectName=%23/ADAS/SW%23Projects/MFC5xx/MFC51x/MFC510/APPL/04_Engineering/03_Workspace/00_Projects/MFC510/resbudget&selection=dpu_budget.xlsm) and 
/// [MFC520_ResBudget](http://ims-adas:7001/si/viewrevision?projectName=%23/ADAS/SW%23Projects/MFC5xx/MFC52x/MFC520/APPL/04_Engineering/03_Workspace/00_Projects/MFC520/resbudget&selection=dpu_budget.xlsm).
/// Therein, the budgets in terms of memory usage and run time (per core) is listed for each OpMode and for each project specific configuration. 
///
///
//Doxygen code for Export Interface chapter
/// \page vdy_exportInterfacePage    Export Interface
///
/// \tableofcontents
///
/// \note this whole chapter actually describes the component from an architecture point of view. 
///  It's an open question how we interlink architecture and design, but we should limit redundancies to a minimum.
///  We welcome your comments on this (and any other) issue on the connext group "Detailed Design for ADAS Sensorics".
///
/// \section vdy_exportInterface_staticView Static View
///
///   \subsection vdy_exportInterface_staticView_functions Functions
///   The VDY Component exports one function: VdyExec(). All inputs are contained in the reqVdyPrtList_t Struct reqPorts. 
///   This includes an instance of the BaseCtrlData_t Struct, which has an eOpMode member. This parameter controls which of the 
///   OpModes list in \ref vdy_exportInterface_dynamicView_OpModes OpModes  is requested.
///
///   \subsection vdy_exportInterface_staticView_variablesTypesConstantsMacros Variables, Types, Constants, Macros
///    Variables, Typedefs, Constants, and Macros that are visible to other components are contained and described in the files vdy_cfg_ext.h, vdy_par.h and vdy_ext.h
///
///   \section vdy_exportInterface_dynamicView Dynamic View
///   \subsection vdy_exportInterface_dynamicView_OpModes OpModes
///   The VDY Component implements a state machine shown in the following state chart. It consists of one state per OpMode, these are the states in which VDY is actually doing something when VdyExec() is called (with valid parameters), and idle states in between those active states during which VDY is waiting for the next call. Refer to chapter cipp_overview_resources and the spreadsheet referenced there for information about the timing behind these function calls.
///
///   \note The proposed diagram type to model the Component's life cycle, including the required OpMode order, is a State Chart
///
/// @startuml
///   [*] --> Uninitialized
///   Uninitialized --> Initializing : "BASE_OM_RESET"
///   Initializing --> OpMode : "RUNNING /BASE_OM_RUN"
///   Initializing --> Uninitialized : NOT_INITIALISED!
///   OpMode --> Initializing : "BASE_OM_RESET"
///   OpMode --> OpMode : "BASE_OM_RUN"
///   OpMode : Process Cycle
/// 
/// 
/// @enduml
///
/// \subsection BASE_OM_RESET
/// If the op-mode sent by the global scheduler is 'BASE_OM_RESET' following rules apply:
/// Algo component is called by the scheduler, but no calculation should be done. The algo component must be reset/initialized. This op mode is called in case of ecu startup, sw reset or scheduler mode changes.
/// @startuml
/// title BASE_OM_RESET
/// (*) --> "Clear Outputs"
/// "Clear Outputs" --> "No Calculation and No DEM set"
/// "No Calculation and No DEM set" --> "VDY data to be reset(set to default) and only input checks"
/// "VDY data to be reset(set to default) and only input checks" --> "Provide output interfaces"
/// "Provide output interfaces" --> "MeasFreeze"
/// --> (*)
/// @enduml
/// 
/// \subsection BASE_OM_RUN
/// VDY has only one op mode in which calculations are performed it shall use the default 'BASE_OM_RUN'. All derived or specialized running op modes have to fulfill the same requirements.
/// @startuml
/// title BASE_OM_RUN
/// (*) --> "Clear Outputs"
/// "Clear Outputs" --> "Perform Calculation and set DEM's"
/// "Perform Calculation and set DEM's" --> "I/O checks to be performed"
/// "I/O checks to be performed" --> "Provide output interfaces"
/// "Provide output interfaces" --> "MeasFreeze"
/// --> (*)
/// @enduml
///
/// \subsection vdy_exportInterface_dynamicView_ErrorCodes Error Codes and DEM Events
/// 
/// VDY has several levels of error/degradation management
///   - return value of VdyExec() function: The VdyExec() function returns    \n
///           BASE_RETURN_ERROR   if algo execution was not successful.           \n
///           BASE_RETURN_OK      if eCompState == COMP_STATE_RUNNING.                  \n
///   - AlgoCompState: the AlgoCompState_t provide port contains an CompState_t element eCompState which follows the
///     specifications rte_type.h and \n DOORS Link: doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1639-000221c8
///   - DEM Events: Under certain conditions, the VDY component sends the DEM Events VDY_SERVICE_ERROR, VDY_FUSI_ERROR,
///     VDY_BUS_DATA_ERROR, VDY_INTERNAL_ERROR as defined in the file Dem_IntErrIdSlv.h.
///   - Internal Error Handling: The following are the checks done for handling the internal errors     \n
///         Version number checks, Timestamp checks, NULL checks , Signal status checks, Debounce checks, Data sanity, all Service checks.
/// The following table summarizes all Errors that are used in CIPP:
/// |Errors                                     | Possible Reasons                                                   |
/// |-----------------------------------------------|--------------------------------------------------------------------|
/// |VDY_BUS_DATA_ERROR                             |  is set if there is no error in CIPP.                              |
/// |VDY_INTERNAL_ERROR                             |  if the error is not known or not present in the list.             |
/// |VDY_SERVICE_ERROR                              | if the OpMode is invalid/not supported .                           |
/// |VDY_FUSI_ERROR                                 | is set if the entire input port list is NULL                       |
/// |VDY_FS_YR_VS_WSP                               | failure w.r.t to Yaw rate monitor check                            |
/// |VDY_FS_YR_VS_AY                                | failure w.r.t to Yaw rate monitor check                            |
/// |VDY_FS_YR_VS_SWA                               | failure w.r.t to Yaw rate monitor check                            |
/// |VDY_VEH_VEL_NOT_AVAILABLE                      | failure w.r.t to vehicle velocity                                  |
/// |VDY_YWR_NOT_AVAILABLE                          | failure w.r.t to Yaw rate                                          |
/// |VDY_NVM_LEARN_DATA_ERROR                       | Failure w.r.t NVM read/write                                       |
/// |VDY_ERR_STATE_UNKNOWN                          | Unknown state                                                      |
/// |VDY_ERR_STATE_ACTIVE                           | Any of the internal VDY error is active                            |
/// |VDY_ERR_STATE_INACTIVE                         | No internal VDY error is active                                    |
///
///\n
/// VDY contains the logic that decides per OpMode whether the internal error state demands
/// reporting of an error to the frame software by setting CompState_t eCompState in the AlgoCompState_t provide port
/// to an error code (COMP_STATE_NOT_INITIALIZED, COMP_STATE_RUNNING, COMP_STATE_PERMANENT_ERROR, 
/// COMP_STATE_TEMPORARY_ERROR,COMP_STATE_SUCCESS,COMP_STATE_NOT_RUNNING ) 
/// according to the requirements [DOORS LINK: doors://rbgs854a:40000/?version=2&prodID=0&view=00000005&urn=urn:telelogic::1-503e822e5ec3651e-O-1638-000221c8
///
/// The following table summarizes all CompStates that are used in CIPP:
/// |CompState                  | Possible Reasons                                                   |
/// |---------------------------|--------------------------------------------------------------------|
/// |COMP_STATE_RUNNING         | Must be set in case the algo is called and no error was detected   |
/// |COMP_STATE_NOT_INITIALIZED | An error occurred in OpMode BASE_OM_RESET. Refer to ErrorDataList in Measfreeze for details. \n VCL is not initialized.|
/// |COMP_STATE_TEMPORARY_ERROR,COMP_STATE_PERMANENT_ERROR | Should be set in case of errors|
/// |COMP_STATE_SUCCESS |  Is reserved for special op modes (e.g. reset, demo, EOL calibration)
/// |COMP_STATE_NOT_RUNNING |  Shall be set if the algo is called in the idle op mode|
///


//Doxygen code for Configuration chapter
/// \page vdy_configurationPage    Configuration
///
/// \tableofcontents
/// 
/// Project-specific configuration and paramterization is realised in the files vdy_cfg_ext.h which contains custom switches 
/// for activating or deactivating the functionality which contains project-specific settings and parameters
/// that reflect the differences in the requirements of some projects.
///
///
/// The following table summarizes and explains all switches. The comment column provides references to module and/or 
/// unit level Detailed Design elements, which are affected by the switch as well as describes limitations/dependencies
/// in switch settings.\n
///
/// | Switch                                                       | Effect                                                                                                                | 
/// |--------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------|
/// |CFG_VDY_MEASUREMENT                                          |         Enable measurement                                                                                             |
/// |CFG_VDY_YW_DYN_AVG                                           |       	 Enable dynamic gyro offst compensation                                                                        |
/// |CFG_VDY_EX_YWR_NVM                                           |       	 Enable offset storage  in nonvolatile memory                                                                  |
/// |CFG_VDY_INT_GYRO                                             |         Enable internal yaw rate sensor processing                                                                     |
/// |CFG_VDY_FPM_754                                              |      	 Enable optimized math function approximation                                                                  |
/// |CFG_VDY_USE_EX_LONG_ACCEL                                    |       	 Use external provided longitudinal acceleration signal                                                        |
/// |CFG_VDY_MOT_STATE                                            |     	 Use external provided longitudinal velocity signal                                                            |
/// |CFG_VDY_DO_VELOCITY_CORR                                     |     	 Enable motion state processing                                                                                |
/// |VEL_CORR_ALN                                                 |    	     Enables the velocity correction                                                                               |
/// |VEL_CORR_HIST_STATIONARY_TARGETS                             |   	     Enables ALN calculated velocity as input for velocity correction                                              |
/// |CFG_VDY_USE_CORRECT_VELO_CORR_VAR                            |  	     Enables stationary targets as input for velocity correction                                                   |
/// |CFG_VDY_USE_EXT_PROC_CURVATURE                               | 	     Enable lower max. variance of velocity correction factor variance if one measurement update is available      |
/// |CFG_VDY_USE_EXT_PROC_YAW_RATE                                |	     Enables usage of external curve as vdy output curve                                                               |
/// |CFG_VDY_USE_EXT_PROC_SIDE_SLIP_ANGLE                         |         Enables usage of external yaw rate as vdy output yaw rate                                                      |
/// |CFG_VDY_DIS_SWA_OFFSET_COMP                                  |      	 Enables usage of external side slip angle as vdy ouput side slip angle                                        |
/// |CFG_VDY_DIS_YWR_OFFSET_COMP                                  |     	 Disables zero point offset compensation of input steering wheel angle signal                                  |
/// |CFG_VDY_DIS_WHS_OFFSET_COMP                                  |    	 Disables zero point offset compensation of input yaw rate signal                                                  |
/// |CFG_VDY_DIS_LAT_OFFSET_COMP                                  |   	     Disables offset compensation between left and right wheel on vehicle axle                                     | 
/// |CFG_VDY_USE_EXT_PROC_UNDERSTEER_GRAD                         |  	     Disables zero point offset compensation of input lateral acceleration signal                                  |
/// |VDY_USE_LEARNED_UNDERSTEER_GRAD                              | 	     Enables usage external estimated understeer gradient                                                          |
/// |VDY_USE_EST_WLD_DEP                                          |         Enables usage of internal estimated understeer gradient instead of input parameter                             |
/// |CFG_VDY_USE_VELO_MONITOR                                     |         Enables velocity monitor                                                                                       |
/// |CFG_VDY_YWR_OFFSET_MONITOR                                   |         Enables monitoring of external vehicle velocity. The velocity is compared with estimated                       |
/// |CFG_VDY_DIS_WHEEL_PRE_PROCESSING                             |         Enables monitoring of yaw rate at vehicle-stop, during vehicle-stop and vehicle drive-off. During this driving |
/// |CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING                        |  	     Disables the wheel speed pre processing,                                                                      |
/// |CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING                	  |         Disables the sensor yaw rate pre processing,                                                                   |
/// |CFG_VDY_DIS_YAW_SENSOR_OUTPUT                                |         Disables the alignment yaw rate offset pre filtering,                                                          |
/// |CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING                  |	     Disables the alignment yaw rate output,                                                                           |
/// |CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING                  |	     Disables the lateral acceleration sensor pre processing,                                                          |
/// |CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION                       | 	     Disables the steering wheel angle sensor pre processing,                                                      |
/// |CFG_VDY_GEN_VELOCITY_VARIANCE                                |         Disables the side slip angle estimation                                                                        |
/// |CFG_VDY_ALIGNMENT_OFFSET_MONITOR                             |       	 Generated a velocity variance by deviation of the acceleration                                                |
/// |CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON                            |      	 Do yaw rate offset monitoring with alignment offset estimation input                                          |
/// |CFG_VDY_CALC_VDY_TIMING                                      |         Disable functional safety monitoring                                                                           |
/// |CFG_VDY_64BIT_TIMESTAMP_INTERV                               |         Enables the 64 bit Timestamp interface                                                                         |
/// |CFG_VDY_DIS_CURVE_OUTPUT                                     |         Disable the additional VDY curve output                                                                        |
/// |CFG_VDY_FS_VELO_CORR_MON                                     |         Enables the fast velocity to stationary targets monitor                                                        |
/// |CFG_VDY_MON_OUTPUT_PEAKS                                     |         Enables the output peak monitoring                                                                             |
/// |VDY_CHECKPOINT_ENABLED                                       |         Enables checkpoints for execution flow supervision                                                             |
/// |VDY_PROFILING_ENABLED                                        |         Enables runtime measurement and profiling                                                                      |
/// |CFG_VDY_USE_ALGOCOMPSTATE                                    |         Enables the compstate output                                                                                   |
/// |CFG_VDY_SET_DEM_EVENTS                                       |         Enables setting DEM events by VDY, otherwise only the VDYError flags are set                                   |
/// |CFG_VDY_TURNTABLE_DETECTION                                  |         Enables the Turn Table detection and limit max. delta 4deg                                                     |
/// |CFG_VDY_NVM_LEARN_DATA_ERROR                                 |         Enable DEM relates NVM learning values to ensure no corrupted data is written to flash memory                  |
/// |CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK               | 	     Disables Valid Or Invalid check before reading NVM and writes NVM data                                        |
/// |CFG_VDY_DEBOUNCE_OUTPUTS                                     |         Enables the max debouncing output counter                                                                      |
/// |CFG_VDY_BMW_LONG_ACCEL_MODEL                                 |         Enables BMW specific Long Accel Calculation                                                                    |
/// |CFG_VDY_ROLLBENCH_DETECTION                                  |         Enables reaction to roll bench detection                                                                       |
/// |CFG_VDY_VELO_VARIANCE_CHECK                                  |         Enables the velocity variance check for setting the velocity not available DEM                                 | 
/// |CFG_VDY_REDUCE_CURVE_ERROR                                   |         Enables the code for reducing the curve error after software reset                                             |
/// |CFG_VDY_INIT_MODE_AS_STARTUP_MODE                            |    	 Enables the switch to stop toggling the DEM for trucks                                                            |
/// |CFG_VDY_VELO_MONITOR_MIN_MAX                                 |    	 Enables New Velocity monitoring based on new minimum and maximum velocity signals for ARS4D1 and ARS4D2           |
/// |CFG_VDY_YAWRATE_VARIANCE_CHECK                               |	     Enables the yaw rate variance check for yaw rate not available DEM                                                |
/// |CFG_VDY_FS_YR_VS_WSP_ENABLE                                  |	     Enables the FS_YR_VS_WSP DEM                                                                                      |
/// |CFG_VDY_POLYSPACE_ERROR_DISABLE                              |	     Disable unused function throwing red error in polyspace                                                           |
/// |CFG_VDY_VDYNVIODATARD_MEASFREEZ_ENABLE                       |         Enable measfreezing of VDY Structure VDYNvIoDataRD                                                             |
/// 
///
//Doxygen code for Integration chapter
/// \page vdy_integrationPage    Integration
///
/// \tableofcontents
///  Please find the release doc for VDY for more details on the release process .
///  Release doc : 
//Doxygen code for Internal Design chapter
/// \page vdy_designPage    Internal Design
///
/// \tableofcontents
///
/// \section vdy_internalDesign_modules   Modules 
///
/// The VDY component consists of two categories of modules: Handcode and Autocode. \n \n
/// <b> Hand Code Modules </b> \n The following modules are hand coded. \n \n
/// - \ref VDYMainModule \n This module contains the Exec function of VDY. This module contains the sequencing for the Vehicle Dynamics Component. This is the vdy main module. The vdy main function is VDYExec. The vdy main module contains the vdy process workflow for the different vdy operation modes: running, init and startup. \ref VDYMainModuleUnit
/// - \ref VDYMonModule \n This module contains the monitoring functions. \ref VDYMonModuleUnit
/// - \ref SWA_LAOffsetEstimation \n This module contains the steering wheel angle (SWA) and lateral acceleration offset estimation. \ref SWA_LAOffsetEstimationUnit
/// - \ref YWRSensorSignalProcessing \n This module contains the yaw rate sensor signal processing \ref YWRSensorSignalProcessingUnit
/// - \ref WheelSpeedSignalProcessing \n This module contains the wheel speeds signal processing. \ref WheelSpeedSignalProcessingUnit
/// - \ref VDYVelCorr \n The velocity correction block corrects the vehicle velocity estimation from wheel speed sensors based on the relative velocity measurement of stationary objects.
/// - \ref CommonFunctions \n This module contains the commonly used function. \ref CommonFunctionsUnit 
///
/// <b> Auto Code Modules </b> \n The following modules are auto code generated. Designed with matlab simulink. \n \n
/// - \ref VDYAye \n Yaw rate estimation using lateral acceleration 
/// - \ref VDYGye \n Yaw rate estimation using gier sensor output
/// - \ref VDYSye \n Yaw rate estimation using steering wheel angle  
/// - \ref VDYWye \n Yaw rate estimation using wheel speeds
/// - \ref VDYYe \n Yaw rate estimation using Aye, Gye, Sye and Wye. It also estimates Vehicle curvature.
/// - \ref VDYMotSt \n Vehicle motion state estimation : vdy motion state estimation, use a bayes net to compute a motion state
/// - \ref VDYWpp \n Vehicle wheel speeds pre processing : This module estimates and merges four wheel speeds
/// - \ref VDYVe \n Vehicle velocity estimation : This module merges the four wheel speeds and estimates vehicle velocity and acceleration
/// - \ref VDYSae \n Vehicle sideslip angle estimation
///
///   \subsection vdy_internalDesign_modules_interdependenciesStatic Static Module Interdependencies
///
///   The following component diagram shows the interdependencies of the vdy algo modules \n
///	@startuml
/// note left
///	Vehicle DYnamics
/// <img:images\vdy.PNG>
/// end note
/// @enduml
///
///   \subsection vdy_internalDesign_modules_interdependenciesDynamic Dynamic Module Interdependencies
///   
///  \startuml VDY_Sequence_Diagram.png
///		title VDY Sequence Diagram
///
///		box #LightYellow
///		participant GS << Global Scheduler >>
///		end box
///
///		box #LightBlue
///		participant reqPorts << reqVdyPrtList_t in vdy_ext.h >>
///		end box
///
///		box #LightGreen
///		participant vdy << function in vdy_main.c >>
///		end box
///
///		box #LightYellow
///		participant VDYMonitorInput << class in vdy_mon.c >>
///		end box
///
///		box #LightYellow
///		participant VDYProcess << function in vdy_main.c >>
///		end box
///
///		box #LightBlue
///		participant proPorts << proVdyPrtList_t in vdy_ext.h >>
///		end box
///
///		box #LightBlue
///		participant otherComponets << EBA / ACC / SR / LD / EM >>
///		end box
///
///		== Reset/Startup ==
///		autonumber "<b>[00]"	
///		GS -> reqPorts: <b> Calls VdyExec function with eOpMode BASE_OM_RESET
///		reqPorts -> vdy: <b> BASE_OM_RESET <<<i>reqPorts.pBaseCtrlData->eOpMode>>
///		reqPorts -> vdy: <b> RTEData <<<i>reqPorts.pVehicleInputSignals->VehSig_t>>
///		vdy -> VDYProcess : <b> Receive RTEData <<<i>reqPorts.pVehicleInputSignals->VehSig_t>>
///		vdy -> VDYProcess: <b> Validate OpModeHandler <<<i>m_OpModeHandler>>
///		vdy -> VDYMonitorInput : <b> check input signals  <<<i>reqPorts.pVehicleInputSignals->VehSig_t>>
///		vdy -> VDYProcess: <b> Save Signals - <<<i>VDYProcess>>
///
///		== Cyclic Mode (for each cycle) ==
///		autonumber "<b>[00]"
///		GS -> reqPorts: <b> Calls VdyExec function with eOpMode BASE_OM_RUN
///		group Process Sensor signals
///		reqPorts -> vdy:  <b> BASE_OM_RUN <<<i>reqPorts.pBaseCtrlData->eOpMode>>
///		reqPorts -> vdy:  <b> RTEData <<<i>reqPorts.pVehicleInputSignals->VehSig_t>>
///		vdy -> VDYProcess : <b> Receive RTEData <<<i>reqPorts.pVehicleInputSignals->VehSig_t>>
///		vdy -> VDYMonitorInput : <b> check input signals and report errors <<<i>reqPorts.pVehicleInputSignals->VehSig_t>>
///		vdy -> VDYProcess : <b> VDY computations performed and DEM's set <<<i>reqPorts.pVehicleDynamicSignals-> VehDyn_t>>
///		vdy -> VDYProcess : <b> Save Signals - <<<i>VDYProcess>>
///		VDYProcess -> proPorts : <b> VDY output sent to ProPort <<<i>>proPorts.pVehicleDynamicSignals-> VehDyn_t >>
///		VDYProcess -> proPorts : <b> Send RTEData <<<i>>proPorts.pVehicleDynamicSignals-> VehDyn_t >>
///		proPorts -> otherComponets : <b> VDY Output VehDyn Signals </b>
///		end
///
///	\enduml
///
/// \page VDYMainModule VDY Main Module
/// Goto : \ref VDYMainModuleUnit \n \n \n
/// \ref VDYMainModule \n
/// vdy_main.c : This module contains the Exec function of VDY. This module contains the sequencing for the Vehicle Dynamics Component. This is the vdy main module. The vdy main function is VDYExec. The vdy main module contains the vdy process workflow for the different vdy operation modes: running, init and startup. 
///							- <b> Roller Test Bench Detection </b>
///									- If the vehicle is placed on a roller test bench, the ego velocity from the vehicle bus is incorrect (since the vehicle is not moving) and all stationary objects are erroneously classified as moving. This can lead to wrong learn values in Blockage, VDY, RHC and ALN. False learning values should be avoided even if the test bench situation is erroneously not communicated by service diagnosis. On the roller bench nearly all objects have Doppler speed zero, even though the ego speed from the vehicle bus is not zero.
///									- This must be used in EM for detection of the roller bench. EM stops evaluation of blockage and communicates this information to VDY. 
///									- VDY stops learning of any learn value and sets the corrected ego velocity to zero to ensure the correct sensor behavior.
///									- Velocity correction and offsets learning will not happen in VDY when Roller test bench is detected.
///							- <b> Quality calculation for output signal </b>
///									- This function calculates the quality for the vdy output signals
///											- curve (fused, yaw rate and driver intended curve)
///											- yaw rate (fused yaw rate)
///									- The quality is in range of 0 - 1.0
///									- Curve and yaw rate have the same quality, it depends on the offset states of the input signals
///											- The yaw rate offset state is mapped to the following quality:
///													- if no yaw rate offset is available (no eeprom and no stand still) add 0 to the  to the curve and yaw rate quality
///													- if stand still yaw rate offset is available add 0.45 to the curve and the yaw rate quality.
///													- if eeprom stand still offset is available add 0.2 to the curve and the yaw rate quality.
///											- If the offset state of the steering wheel angle is above 2 add 0.35 to the curve and yaw rate quality
///											- If the offset state of the lateral acceleration is above 2 add 0.15 to the curve andd the yaw rate quality
///											- If the deviations of the front and rear axle offsets are below 1.0 add 0.05 to the curve and the yaw rate quality
///							- <b> The ALN yaw rate interface </b>
///											- This functionality is not used any more in ARS400/SRR300 and MFC400 projects.  This chapter is kept as reference as the code is still available and the functionality might be reactivated. \n The ALN yaw rate (not fused yaw rate, only based on the yaw rate from the yaw rate sensor) \n This interface has the following alignment:
///											- typedef struct \n { \n		uint32 uiVersionNumber;                           // Number of used Version @min:0.0 @max:16277215.0 \n	float32 YawRate;                                         // Estimated vehicle angular rate about vertical axis (offset compensated)  \n		float32 Quality;                                            // Differenz zwischen der kurzzeitgefilterten und langzeitgefilterten yaw rate  \n		OffsetCompState_t OffsetCompState;    // Offset state of the yaw rate  \n			boolean bSenYawRateState;                    // yaw rate valid flag 1=Valid. 0= Invalid \n } ALNYawRate_t;
///											- YawRate contains an offset and pre filtered yaw rate signal, based on the the raw yaw rate signal
///											- Quality and OffsetCompState: \n The quality is in range of 0.0-1.0 and the state in range form 0 - 4
///													- Reduce Quality: \n The aln yaw rate quality has its own vdy_gye module instance. \n The yaw rate offset input of this module is filterd to smoth the discrete steps of the estimated yaw rate offset. \n The quality is modulated with the diffrence between the not filterd offset and the low pass filtered yaw rate offset. \n		reduce_quality = diff *50 (0.01rad difference lead to a reduce quality of 0.5) \n		this reduce_quality is limited to 0.2
///											- External Yaw rate sensor quality and state processing:
///													- The yaw rate offset state is mapped to the following aln pre reduce quality:
///															- if no yaw rate offset is available (no eeprom and no stand still) 
///																	- set aln pre_reduce_quality is 0
///																	- and set the aln yaw rate offset state to: ALN_YAW_RATE_NO_EEPROM
///															- if stand still yaw rate offset is availabel and external stand still yaw rate offset quality is/was once above 0.75
///																	- set alnpre_reduce_quality to 1.0
///																	- and set the aln yaw rate offset state to ALN_YAW_RATE_FULL_STAND_STILL.
///															- if stand still yaw rate offset is availabel and external stand still yaw rate offset quality is below below 0.75
///																	- set aln pre_reduce_quality to 0.75
///																	- and set the aln yaw rate offset state to ALN_YAW_RATE_SHORT_STAND_STILL.
///															- if eeprom stand still offset is availabel
///																	- set aln pre_reduce_quality to 0.2
///																	- and set the aln yaw rate offset state to  ALN_YAW_RATE_NO_STAND_STILL.
///													- Internal Yaw rate sensor quality and state processing:
///															- The Quality is directly mapped form the internal yaw rate offset estimation to the aln yaw rate quality
///															- The yaw rate offset state is mapped to the following aln pre reduce quality:
///																	- if no yaw rate offset is available (no eeprom and no stand still) 
///																			- and set the aln yaw rate offset state to: ALN_YAW_RATE_NO_EEPROM
///																	- if stand still yaw rate offset is available and internal stand still yaw rate offset quality is/was once above 0.75
///																			- and set the aln yaw rate offset state to ALN_YAW_RATE_FULL_STAND_STILL.
///																	- if stand still yaw rate offset is availabel and internal stand still yaw rate offset quality is below below 0.75
///																			- and set the aln yaw rate offset state to ALN_YAW_RATE_SHORT_STAND_STILL.
///																	- if eeprom stand still offset is availabel
///																			- and set the aln yaw rate offset state to  ALN_YAW_RATE_NO_STAND_STILL.
///											- The ALN yaw rate offset quality is calculate by:
///													- Quality = pre_reduce_quality -  reduce_quality
///											- If the stand still offset is actually processed the aln yaw rate offset state is ALN_YAW_RATE_PROCESS_STAND_STILL
///							- <b> Rear Wheel Angle (Rear Steering Wheel) </b>
///									- In VDY, Rear Steering Wheel angle is considered along with Front Steering Wheel angle for estimating 
///									- Effective Steering Wheel Angle Offset, Yaw rate based on Effective Steering Wheel Angle and understeer Gradient.
///									- That can be implemented as below
///											- <b> Effective Steering Wheel Angle = (Front Wheel Angle - Rear Wheel Angle) * Steering Ratio. </b>
///									- Later, this Effective Steering Wheel Angle will be used for estimating steering wheel Offset, Yaw Rate and understeer Gradient.
///							- <b> The vdy offset output interface </b>
///									- The vdy component provides an interface that includes the estimated offsets of yaw rate, steering angle and lateral acceleration
///									- <b> Yaw rate offset </b>
///									- Two types of offset are available,
///									- StandStill offset and dynamic offset.
///									- This is the interface: \n typedef struct \n { \n		fYawRate_t StandStillOffset;                   // Stand still Yaw rate offset  \n			sint32 StandStillState;                     	      // Stand still Yaw rate offset state  \n		fYawRate_t DynOffset;                            // Dynamic Yaw rate offset  \n		fVariance_t DynVariance;                        // Dynamic Yaw rate offset Variance  \n } Ywr_t;			// Yaw rate offset result 
///									- <b> StandStillOffset </b> always contains the stand still offset, could be also a standstill offset from eeprom
///									- <b> StandStillState </b> contains the state of the offset,
///											- 0 = no stand still offset available
///											- 1 = Short stand still offset (short stand still time), use StandStillOffset 
///											- 2 = Full stand still offset (long stand still time), use StandStillOffset 
///											- 3 = EEProm offset, use StandStillOffset
///											- 4 = Dynamic offset, use DynOffset
///									- <b> DynOffset </b> contains the dynamic yaw rate offset
///									- <b> DynVariance </b> contains the dynamic yaw rate offset variance
///									- <b> Steering wheel angle offset </b> \n The output interface of estimated steering angle offset uses the following interface: \n typedef struct \n { \n		fAngle_t Offset;            // Steering wheel angle offset  \n		fVariance_t Variance;   // Steering wheel angle offset variance  \n		sint32 State;                   // Steering wheel angle offset state  \n } Swa_t;
///									- <b> Offset</b> contains the steering angle offset
///									- <b> Variance</b> contains the correspoinding variance of the offset
///									- <b> State</b> contains the state of the offset is in range from 0 - 6, above 2 are well learned offsets
///									- <b> Lateral accel offset</b> \n The output interface of the lateral accel offset use the following interface: \n typedef struct \n { \n		fAngle_t Offset;        // Steering wheel angle offset  \n		fVariance_t Variance;   // Steering wheel angle offset variance  \n		sint32 State;           // Steering wheel angle offset state  \n } Ay_t;
///									- <b> Offset</b> contains the lateral acceleration offset
///									- <b> Variance</b> contains the correspoinding variance of the offset
///									- <b> State</b> contains the state of the offset is in range from 0 - 6, above 2 are well learned offsets
///							- <b> Input signal debouncing </b>
///									- The input signals might have short disturbances and might not be available in the needed quality or not at all.  Possible cause could be short timeouts on the vehicle bus.  To avoid faults if the signals are not available for a very short time, all input signals are debounced for 2 cycles.
///									- If the input signal state is either 'invalid' or 'not available', the last correctly received value is used in the VDY module.  This is done up to 2 times, and after the 3rd cycle with an invalid input signal, the signal is not buffered anymore and the normal reaction to invalid inputs will happen (e.g. the steering angle would not be processed anymore and no driver intended curve would be calculated).
///									- This buffering is done for each signal separately and the signals do not influence each other.
///							- <b> Lateral error calculation </b>
///									- To calculate a safe distance for which the curve output is surely pointing to the correct lane, a worst case lateral error is calculated out of the remaining errors of the input signals.
///									- The curve is calucated out of yaw rate, steering angle, lateral acceleration, wheel speed and vehicle velocity.
///									- All these inputs are compensated to have the most precise inputs available.  In these compensation algorithms the offsets or correction factors are learned over time and have a status to show how good the compensation values are already learned.  Based on this status, the remaining error on the input signal can be estimated and the error caused by these remaining signal errors can be calculated.
///									- All these calculated signal errors are then combined in the same way as the signals themselves are combined into the curve.
///									- The yaw rate error is based on the yaw rate offset compensation state.
///									- An uncompensated signal can have an offset of up to 10deg/s as defined in the gyroscope specification.  We do not know which gyro is used in the project, but 10deg/s is a very high value and covers all gyros.
///									- After a standstill compensation we assume 1deg/s as remaining possible offset.
///									- If only a NVM value is taken and no new offset could be determined, a remaining error of 2.5deg/s is assumed to cover the offset difference caused by the temperature difference between last cycle and this cycle.  As the yaw rate offset is not stored at the end of a cycle when the sensor is most likely at the maximum temperature, 2.5deg/s are a safe assumption.
///									- When the dynamic offset compensation is active (starts after the wheel speed compensation is finished), the compensation steps are 0.002rad/s. So the remaining difference between real and compensated sensor signal is less than 0,002rad/s and this value can be used as remaining error.
///									- The steering angle is compensated in the vdy_ay_swa.c module.  For every state an error based on the learning state is given, and this error is used for the lateral error calculation.
///									- The lateral acceleration is compensated in the vdy_ay_swa.c module.  For every state an error based on the learning state is given, and this error is used for the lateral error calculation.
///									- The wheels on each axle are compensated in the vdy_whs.c module.  The deviation of the wheel offset is used to calculate the remaining error for each axle.  Then the error for front and rear axle are added together to get the wheel speed error.
///									- The velocity is corrected in the vdy_velcorr.c module.  The correction factor is checked every cycle against new samples, so the quality state of the correction factor gives a remaining error of the velocity.
///									- If no correction value is available, the maximum error of the input velocity can be 15% as specified in in the system input signal specification.
///									- If a correction value is stored, but no data could confirm this factor, the assumed error is 15% as new wheel could have been mounted and the correction factor could be completely wrong.
///									- After the correction factor is confirmed with new input samples, the remaining error is 10% as this is the allowed maximum difference specified in the TSC between input samples and input velocity.
///									- Note: This value is preliminary and will be improved when more data about the precision of the velocity correction is available.
///									- The different signal errors are calculated into yaw rate errors by using the same formula which is used in the yaw rate models.
///									- These yaw rate errors are added up using the same weighting as the yaw rate fusion weights the yaw rates.  The added yaw rate is then transformed into a curve and the error of this curve and the error of the steering angle curve is then added together using the same weighting as the curve calculation to get a final curve error.
///							- <b> Curve Lateral Error </b>
///									- In order to get the curve confirmation qualifier, the lateral error is a certain distance is needed.
///									- This lateral error is determined by calculating the lateral distance between the current curve and the curve with the error applied to it at the needed longitudinal distance.
///									- As the curve is a circle, the longitudinal distance is the arc length on the circle, and the 2 point with and without error are calculated by taking the arc length and determining the geometrical position on these circles. As the 2 curves are very close together as the error is not very high, the lateral distance is given by the euclidean distance between the 2 points on the curve circles.  The error because the 2 points also have a longitudinal distance as they are not fully orthogonal in respect to the other circle is neglecyable and in the range of a few centimeters.
///									- If the curve is very low (the radius is very high), the circle can be considered a straight line (the calculation of a circle would not give a usable result any more).
///							- <b> Curve Error Confirmation Qualifier </b>
///									- The confidence qualifier is set considering the states of the input signals and the lateral curve error at the distances predicted over 1, 2, 3 and 4 seconds at current speed.  The lateral error must be less than 1.75m at the given distances (higher distance gives a higher confidence).
///									- The input states are debounced for 100ms.  Reducing the confidence due to lower distance is delayed by 400ms to avoid a toggling confidence qualifier. \n \n
///									.
///							.
/// Goto : \ref VDYMainModuleUnit
/// \page VDYMonModule Input Output Monitor  
/// Goto : \ref VDYMonModuleUnit \n \n \n
/// \ref VDYMonModule \n
/// vdy_mon.c : This module contains the monitoring functions 
///							- <b> Monitoring component should monitor  </b>
///									- Input signals
///									- Output signals
///									- Yaw rate offset (new old dynamic offset)
///									- Velocity correction
///									- ASIL monitoring
///							- <b> Input signals monitoring </b> \n Check for peaks and valid values the following signals/parameters:
///									- <b> Check for signal peaks  </b>
///											- If the difference of an input signal between the last and the actual cycle is above a defined theshold, the signal gradient is limited to the max allowed difference and the state is set to 'Decreased'.
///											- This check is done every cycle and only if both the old and new signal is valid but continues until the gradient of the signal gets normal again.
///											- Valid signals which follow immediately after an invalid signal are taken directly without this check.
///											- For e.g. If 2 consecutive yaw rate signals are 2deg/s and 10deg/s, the difference is with 8deg/s higher than the max allowed difference of 6deg/s.  As a result, the second signal would be set to 8deg/s \n and a signal peak fault is set. State of Yaw Rate will be set as 'Decreased'.
///									- <b> Check for valid signals (range)  </b>
///											- Check if the input signals are within a possible range.
///											- If a signal is outside of a defined range, it is limited to the maximum allowed value and the state set to 'Substitute'.
///											- If a signal is outside of the defined limits (lower than the minimum value or higher than the maximum value), a signal fault is set.
///											- These signals are checked:
///													- Yaw rate
///													- Steering wheel angle
///													- Lateral acceleration
///													- Four wheel velocities
///													- Vehicle velocity
///													- Longitudinal acceleration
///											- For e.g. If Input value of Yaw Rate is 165deg/s in the current cycle, then it is above the maximum limit of 150deg/s and will be limited to 150deg/s. An InputSignalError will be set. State of Yaw Rate will be set as 'Substitute'.
///									- <b> Check for valid parameters (range)  </b>
///											- Check if the parameters values are within the range of a normal vehicle and are set to a valid state.
///											- If a parameter is outside of the defined range, a default value is set and a parameter fault is set.
///											- The default value is set to avoid calculation issues in the models with extreme values.  For example, a wheel base of 0m is not possible in a car and would cause a division by zero when calculating the yaw rate out of the steering angle, so a safe default is set and no undefined mathematical operations happen.
///											- The limits can be set in the custom config and will then override the defaults set in the MON module, as e.g. a truck project must allow a longer wheel base than a car project.
///									- <b> Output signals monitoring  </b>
///											- Check the two main output signals (velocity and yaw rate) for valid signal range
///											- 1. If the velocity is below 115 m/s and the long acceleration is below 15 m/s^2 and the Velocity is not nan, set an error flag inactive for velocity , otherwise set the velocity and long acceleration state to invalid and set an error flag for velocity.
///											- 2. If the yaw rate is below 150 deg/s and the lateral acceleration is below 15 m/s set an error flag for yaw rate inactive, otherwise set the yaw rate state and lateral acceleration to invalid and set an error flag for the yaw rate.
///											- 3. If velocity is below 1m/s the state of the yaw rate output signal is always valid.
///											- 4. If the yaw rate signal state is invalid, because of other conditions, like invalid input signal, the output state is not over written by the monitoring.
///									- <b> Yaw rate monitoring  </b>
///											- The yaw rate monitoring is divided in separate modules
///													- Offset monitoring with external provided offset
///													- Dynamic yaw rate offset monitoring
///													- Stand still yaw rate monitoring
///											- <b> Offset monitoring with external offset input signal  </b>
///													- This functionality is not used and not active in the ARS400 environment any more, this chapter serves only as a reference in case this functionality must be activated again.
///													- This offset is delivered externally from the ALN component
///													- If the difference between the external offset and the internal offset is above a value (specified in the par file, customer specific) and this difference is present for a specified time (par file) set an error flag. One error flag for contiguard and one for acc, with different delta and time thresholds.
///	@startuml
/// note left
///	VDY Yaw Rate Estimation
/// <img:images\VDY_YawRateEstimation.PNG>
/// end note
/// @enduml
///											- <b> Dynamic offset monitoring </b>
///													- 1. If the absolute difference between the internal data input yaw rate offset and ToAutocode interface offset is above 0.1 deg/s and offset state is VDY_YAWRATE_STATE_NVM or VDY_YAWRATE_STATE_STANDSTILL, make a local copy of offset in oldoffset and stand still offset of ToAutocode interface. \n Otherwise copy offset and its state to the internal data input yaw rate from ToAutocode interface.
///													- 2. If the absolute difference between new dynamic offset estimated by the internal data input yaw rate offset is above 0.00395 and vdy_ywr autocode modules offset is VDY_YAWRATE_STATE_KEEP_TYPE and the new dynamic offset is not confirmed by the old dynamic offset, set internal data input yaw rate offset temporarily by the old offset and state will be VDY_YAWRATE_STATE_STANDSTILL. \n Otherwise set internal data input yaw rate offset to original stand still offset and set oldoffset to actual estimated dynamic (gier) offset.
///											- <b> Stand still yaw rate offset monitoring </b>
///									- <b> External velocity monitoring </b> \n This monitoring checks if the external estimated vehicle velocity and the internal estimated velocity (vdy_ve) is in the same range.
///											- 1. If the external velocity state is valid the monitoring will active, otherwise no monitoring and velocity monitoring short term error and long-term error set to UNKNOWN.
///													- The difference is external velocity - internal velocity.
///											- 2. If ABS (difference) - 4*estimated internal standard deviation of the velocity > 1% of internal velocity increment Outside counter, otherwise decrement counter. \n * if the current value is 0, decrement is not allowed.
///													- If Current velocity variance is negative calculate standard deviation of the velocity with last velocity variance, if not calculate standard deviation with current velocity variance and last variance is set to current velocity variance.
///													- There are two error conditions, long term and short term.
///											- 3. If counter is 250 cycles or above set the long term error monitoring fault and clears the short term event.
///											- 4. If counter is 20 cycles or above set the short term error monitoring fault and clears the long term fault. \n - This constants 20 and 250 are default values and can be tuned in the par file.
///									- If ABS signal is valid and active till 1000 cycles hold your velocity monitoring and make VDY_VEH_VEL_NOT_AVAILABLE Inactive increment ABS cycle counter else do velocity monitoring.
///							- <b> Error conditions </b>
///							- <b> Short term fault </b>
///									- <b> Description </b> \n Plausibility check of provided vehicle velocity and provided single wheel speeds. The wheel speeds are converted to wheel velocities by use of vehicle parameter "wheel circumference" and averaged between left and right side per axle to eliminate differences between vehicle cornering. The front and rear axle velocities are fused to a vehicle velocity in dependence of vehicle driving conditions and driven axle.
///									- <b> Prerequisites </b> \n Vehicle velocity and wheel speeds (with circumference or velocities) at least from one axle have to be provided by vehicle interface
///									- <b> Setup conditions </b> \n Difference between vehicle velocity and velocity derived from wheel speeds less its uncertainty must be greater than 1 % of provided vehicle velocity for longer than typ. 400ms without interruption.
///									- <b> Reset condition </b> \n Setup condition not fulfilled any longer
///									- <b> Criticality </b> \n Severe fault, but event might be triggered during vehicle skidding
///							- <b> Long term fault </b>
///									- <b> Description: </b> \n Long-term plausibility check of provided vehicle velocity and provided single wheel speeds. The wheel speeds re converted to wheel velocities by use of vehicle parameter "wheel circumference" and averaged between left and right side per axle to eliminate differences between vehicle cornering. The front and rear axle velocities are fused to a vehicle velocity in dependence of vehicle driving conditions and driven axle.
///									- <b> Prerequisites </b> \n Vehicle velocity and wheel speeds (with circumference or velocities) at least from one axle have to provided by vehicle interface
///									- <b> Setup conditions </b> \n Difference between vehicle velocity and velocity derived from wheel speeds less its uncertainty must be greater than 1 % of provided vehicle velocity for longer than typ. 5 sec without interruption.
///									- <b> Reset condition </b> \n Setup condition not fulfilled any longer
///									- <b> Criticality </b> \n Critical fault, sensor shall enter fail safe state
///							- <b> ASIL monitoring </b> \n This implementation is based on the ASIL vdy concept:
///									- It consists of 2 safty mechanisms
///											- I.Safeguarding against ego-vehicle velocity faults
///											- II. Safeguarding against yaw rate faults
///							- <b> Ego vehicle velocity fault monitoring </b>
///									- 1. If monitoring of external vehicle velocity enabled, update the FS error monitors state (FSIntExtVeloCheck) with long term error else keep the FS error monitors state (FSIntExtVeloCheck)at default.
///									- 2. If the velocity correction enabled, update the FS error monitors state (FSCorrVeloCheck) with Velocity correction factor range error else keep the FS error monitors state (FSCorrVeloCheck)at default.
///									- 3. If the fast velocity monitor detects a fault, raise correction factor variance to 100.
///							- 1. If  vdy control mode is init call initializes Velocity Monitoring routine and set fusi error (VDY_FS_VEH_CORR_MON) to UNKNOWN else call Monitors velocity for faults routine.
///							- 2. If velocity monitor fault is ACTIVE, set fusi error (VDY_FS_VEH_CORR_MON) ACTIVE else INACTIVE.
///							- If vehicle velocity could not be calculated set the error (VDY_VEH_VEL_NOT_AVAILABLE) based on below conditions,
///									- a) Set error (VDY_VEH_VEL_NOT_AVAILABLE) active if velocity output state is not valid
///									- b) External longitudinal acceleration more than acceleration threshold (0.5) and velocity variance is more than threshold of variance of corrected velocity during dynamic acceleration (65).
///									- c) External longitudinal acceleration not more than acceleration threshold (0.5) and velocity variance is more than threshold of variance of corrected velocity during static (30).
///							- If yaw rate could not be calculated while vehicle is moving set the error (VDY_VEH_YWR_NOT_AVAILABLE) based on below conditions.
///									- 1. If yaw rate output state is not valid and vehicle moving reverse with velocity greater than 1 m/s, set error (VDY_VEH_YWR_NOT_AVAILABLE) active. \n else
///									- 2. If the vehicle is moving reverse or yaw rate output state is Valid , yaw rate error (VDY_VEH_YWR_NOT_AVAILABLE) should be inactive.
///							- <b> II. Yaw rate fault monitoring </b> \n Compare the offest compensated (dynamic/stand still) yaw rate from the yaw rate sensor with the other internal yaw rates from wheel velocities, lateral acceleration and steering wheel. \n If the difference is above a limit, the driven distance is accumulated.  Once the difference is below the limit, the difference is reset to 0m.
///							- <b> Check with wheel yaw rate </b>
///									- 1. The pre check conditions are vehicle velocity must be above 15 m/s and the curve gradient must be below 0.0005. \n The delta is YawWheelDelta =  (sensor yaw rate) - (wheel yaw rate)
///									- 2. If the YawWheelDelta is above 0.04 the driven distance YawWheelDist is accumulated, otherwise the YawWheelDist is set to zero.
///									- 3. If the pre conditions are not fulfilled the YawWheelDist is set to zero.
///									- 4. If the driven dist YawWheelDist is above 150m set the functional safety fault event FSWheelYawRateCheck to active, otherwise inactive.
///							- <b> Check with lateral acceleration yaw rate </b>
///									- 1. The pre check conditions are vehicle velocity must be above 10 m/s and the curve gradient must be below 0.0005. \n The delta is YawAccelDelta =  (sensor yaw rate) - (lateral acceleration rate)
///									- 2.If the YawAccelDelta is above 0.01 the driven distance YawAccelDist is accumulated, otherwise the YawAccelDist is set to zero.
///									- 3. If the pre conditions are not fulfilled the YawAccelDist is set to zero
///									- 4. If the driven dist YawWheelDist is above 150m set the functional safety fault event FSLatAccelYawRateCheck to active, otherwise inactive
///							- <b> Check with steering wheel rate </b>
///									- 1. The pre check conditions are vehicle velocity must be above 10 m/s and the curve gradient must be below 0.0005. \n The delta is YawSteerDelta =  (sensor yaw rate) - (Steering Wheel Yaw rate)
///									- 2. If the YawSteerDelta is above 0.045 the driven distance YawSteerDist is accumulated, otherwise the YawAccelDist is set to zero.
///									- 3. If the pre conditions are not fulfilled the YawSteerDist is set to zero.
///									- 4. If the driven dist YawSteerDist is above 150m set the functional safety fault event FSSteeringWheelYawRateCheck to active, otherwise inactive.
///							- <b> Course prediction error monitoring </b> \n This functionality is outdated as the course error is calculated by adding the remaining errors from the learn states and provide a lateral error of the curve output. \n This chapter is kept as reference as the code is still available.
///									- First a mean yaw rate error Δω is calculated. \n Therefore the mean of the delta yaw rate errors is calculated. This delta yaw rate errors are added to separate intervals in the see safety strategy II. If the volume of the interval is above 50m the mean is calculated and the interfall is reduced to 50%. This is done for the three possible deltas YawWheelDeltas, YawAccelDeltas and YawSteerDeltas. \n If for one of the three intervals the mean is (re)calulated, the mean Δω over all three intervals is also calculated . With the following wighting YawWheelDeltasMean 30%, YawAccelDeltasMean 40% and YawSteerDeltasMean 40%.
///									- With the mean yaw rate error Δω calculated of the three yaw rate delta means is the actual possible later displacment error Δy calculeted, the prediction horizont T is set to 3 seconds: \n Δy = 1/2 • v_ego • T2 • Δω 
///									- If this lateral displacement error is above 1.5 and is above this threshold for 15 cycle (300ms) set the course prediction error event to active, otherwise inactive \n
///									.
///							.
/// Goto : \ref VDYMonModuleUnit
/// \page SWA_LAOffsetEstimation SWA - Lateral Acceleration Offset Estimation 
/// Goto : \ref SWA_LAOffsetEstimationUnit \n \n \n 
/// \ref SWA_LAOffsetEstimation \n
/// vdy_ay_swa.c : This module contains the steering wheel angle (SWA) and lateral acceleration offset estimation
///	@startuml
/// note left
///	Steering Wheel Angle and Lateral Acceleration
/// <img:images\SWA.PNG>
/// end note
/// @enduml
///							- The steering angle is compensated in the vdy_ay_swa.c module.  For every state an error based on the learning state is given, and this error is used for the lateral error calculation. 
///							- The zero steering wheel angle offset is estimated by an algorithm based on the assumption that on average vehicle has been driving straight-ahead after a certain distance independent of the type of route. Since this assumption is not true for all driving-condition several prerequisites must be fulfilled to run the calibration (e. g. minimum driving velocity, small steering wheel angle range etc.). In addition the assumption is not feasible for all types of routes. Hence, a histogram is used to exclude routes with unfavorable distributions. The estimated steering wheel angle offset is stored to non-volatile memory. The estimated steering wheel angle offset is successive approximated across several ignition cycles to get a more accurate estimation and less dependence on one single route type. If the approximation runs to steady state and the estimated offset is confirmed the estimation is completed. If the estimated offset deviates from current offset the successive approximation is restarted. 
///							- <b> Learn condition </b>
///									- Steering angle must be valid
///									- Steering angle must be below 30 deg
///									- Corrected velocity must be above 10m/s
///									- Motion state should be not reverse
///									- The filtered axis wheel velocity difference should be low (to check driving mainly straight) - (Default threshold 0.3m/s)
///
///							- <b> Reset conditions for the actual histogram: </b>
///									- If the long term filtered (T=60sec) lateral acceleration is above 1.8m/s (detect circular driving)
///							- <b> Steering wheel angle NVM Interface </b>
///									- The NVM steering wheel angle offset interface, consists of the offset and learn state:
///									- steering wheel angle offset [rad]
///									- learn state in range from 0 to 6
///											- 0 : offset value not existen
///											- 1: run up of offset
///											- 2: run up of offset
///											- 3: run up of offset
///											- 4: learned but not confirmed yet
///											- 5: learned and confirmed once
///											- 6: learned and confirmed twice
///							- <b> SWA NVM Initialization   </b>
///									- If control mode is not running, initialize steering wheel angle data and lateral acceleration data.
///									- If control mode is running , NVM read state for swa is valid (both zeroth and first bits of reqVDYPrtList_t->VDYNvIoData_t->VDYNvmState_t are zeros) and EEPromReadOk is not set,  Internal NVM SWa offset and state shall be initialized with req port NVM data in the following way: \n VDYSwaData_t->VDYSwaOffsEEprom_t->VDYSwaOffset_t->Offset = reqVDYPrtList_t->VDYNvIoData_t->VDYNvStWhlAngCal_t->ZeroAngle \n VDYSwaData_t->VDYSwaOffsEEprom_t->VDYSwaOffset_t->State = reqVDYPrtList_t->VDYNvIoData_t->VDYNvStWhlAngCal_t->CalStatus \n And set EEPromReadOk.
///									- If EEPromReadOk is set and Internal NVM SWA offset is out of range (>12 degree) or state is invalid(less than 0 or greater than 6), internal swa offset and state are initialized with default values. \n Default values \n VDYSwaData_t->VDYSwaOffsEEprom_t->VDYSwaOffset_t->Offset => SWA_ANG_OFFS_DEFAULT (0.0f) \n VDYSwaData_t->VDYSwaOffsEEprom_t->VDYSwaOffset_t->State =>SWA_STATE_DEFAULT (zero) \n VDYSwaData_t->VDYSwaOffsEEprom_t->VDYSwaOffset_t->Dev = 4 degree. \n And \n VDYSwaOffsData_t->StrgOffset = SWA_ANG_OFFS_DEFAULT (0.0f) \n VDYSwaOffsData_t->OffsState = SWA_STATE_DEFAULT (zero) \n VDYSwaOffsData_t->Dev = 4 degree. \n Also set error NVMerrOffsRg as Active.
///									- If Internal NVM SWA offset is within range (<12 degree) and state is valid (greater than or equal to 0 or less than or equal to 6) \n VDYSwaOffsData_t->StrgOffset = VDYSwaData_t->VDYSwaOffsEEprom_t->VDYSwaOffset_t->Offset \n VDYSwaOffsData_t->OffsState = VDYSwaData_t->VDYSwaOffsEEprom_t->VDYSwaOffset_t->State \n VDYSwaOffsData_t->Dev = 4 degree. \n Also set error NVMerrOffsRg as Inactive.
///							- <b> Conditions to collect samples to SWA histogram: </b>
///									- Input Steering wheel angle should be valid and less than 30 degree
///									- Velocity is greater than 10m/s
///									- Motion state should not be reverse
///									- When FL and FR are valid and absolute speed difference between front wheels (FL-FR) is less than 0.3f
///									- When RL and RR are valid and absolute speed difference between Rear wheels (RL-RR) is less than 0.3f
///									- Current input lateral acceleration is less than 5.0f.
///									- Calibration mode is off for swa (BSW_s_VDYCtrlData_t -> CaliMode != 16)
///							-  <b> Offset and confidence estimation: </b> \n Offset and confidence estimation for SWA and Ay should start once covered distance is greater than or equal to threshold distance. \n Takeover conditions for SWA and Ay
///									- SWA takeover happens if:
///											- Estimated offset is within range (less than or equal to 14 degree) 
///											- Confidence is greater than or equal to required confidence
///											- Else 
///											- Histogram get reset
///									- Ay takeover happens if 
///											- estimated offset is within range (less than or equal to 1.2f)
///											- confidence is greater than or equal to required confidence
///											- SWA confidence is greater than zero
///											- Else
///											- Histogram get reset
///							- <b> SWA NVM Write : </b>
///									- If EEPROM write request flag is set i.e VDYSwaData_t->VDYSwaOffsEEprom_t->EEPromWriteRequ=1, write the final offset and state to pro port. \n 	proVDYPrtList_t->pNVMWrite->VDYNvStWhlAngCal_t->ZeroAngle = VDYSwaData_t->VDYSwaOffsEEprom_t->VDYSwaOffset_t->Offset \n proVDYPrtList_t->pNVMWrite->VDYNvStWhlAngCal_t->CalStatus = VDYSwaData_t->VDYSwaOffsEEprom_t->VDYSwaOffset_t->State
///									- If the absolute filtered lateral acceleration is greater than 1.8f (SWA_OFFS_LAT_ACC_MAX = 1.8f) i.e if detected constant circular driving, reinit the histogram and set lateral acceleration to zero.  
///							- <b> Initialization of range and volume histogram: </b>
///									- Create two histogram range (VDYSwaOffsData_t->VDYSwaOffsEst_t->VDYHistogram_t->Range) and volume (VDYSwaOffsData_t->VDYSwaOffsEst_t->VDYHistogram_t->Volume) of size 29 bins (SWA_OFFS_HIST_NO_BINS).
///									- Max and min range of histogram are +29.25deg to  -29.25 deg and is calculated using formula +/- ((((SWA_OFFS_HIST_NO_BINS / 2.0F))) + 0.5F) * SWA_OFFSET_HIST_WIDTH. Where SWA_OFFSET_HIST_WIDTH = 1.95 Deg.
///									- Bin width is computed as (max range -min range )/SWA_OFFS_HIST_NO_BINS.
///									- All the bins of volume histogram are initialized with zero. i.e., hist->Volume[binNo] = 0.F.
///									- All the bins of range histogram are initialized with (min range + ((Bin index+0.5)*binWidth) i.e., hist->Range[binNo]  = (binWidth * ((float32)binNo + ROUNDING_OFFSET)) + minValue;
///							- <b> Updating SWA range and volume histogram: </b>
///									- Find respective bin index (idx) by ((Input SWA - min range) / BinWidth) + 0.5
///									- Corresponding respective bin (idx) of Volume histogram (i.e hist->Volume[idx]) is updated by cumulatively adding the distance covered and update the total distance covered (i.e hist->Sum) \n hist->Volume[idx] += velocity *cycle time; \n hist->Sum+ = velocity *cycle time;
///									- Range histogram can be updated by below formula: \n weight = velocity * cycle time; \n invWeight = 1.0F / (weight + hist->Volume[idx]); \n hist->Range[idx] = (hist->Range[idx] * (hist->Volume[idx] * invWeight)) + ((weight * input SWA angle) * invWeight);
///							- <b> SWA Mean computation: </b>
///									- Mean is computed as average of cumulative weighted sum range histogram. \n mean   += hist->Volume[idx] * hist->Range[idx]; \n volSum += hist->Volume[idx]; \n mean  /= volSum
///							- <b> SWA Median computation: </b>
///									- Get the index by calculating median of volume histogram and get the value  from range histogram for corresponding index.
///							- <b> SWA Confidence calculation and offset estimation: </b>
///									- 1)If absolute difference between mean with maximum count bin is less than 1 deg, estimated offset is equal to mean (StrgOffsData->Est.Offs = hist->Mean)and set the confidence (StrgOffsData->Est.Conf) as below: 
///											- Medium confidence : Driving long section with same steering wheel angle (straight or constant radius)
///											- Max confidence (AY_SWA_OFFS_MAX_CONF=1): if adjacent bins of maximum have enough counts 
///									- 2)If the count difference between secondary peak and maximum peak of volume histogram is big enough (>20% of total volume), estimated offset is mean around (max+2 and max-2) maximum peak and set confidence as low.
///									- 3)If the absolute difference between median and max count bin is less than 2.5 deg, estimated offset is mean around (max+10 and max-10) maximum peak and set confidence as Low.
///									- 4)If the absolute difference between median and mean is less than 1 deg, estimated offset is equal to median and set confidence as below:
///											- Medium confidence :absolute difference between volume at max index and volume at mean index is less than 10% of threshold distance
///											- Low confidence : If it is not medium
///									- 5)If none of the above condition meets, set confidence as low.
///							- <b> Conditions for SWA Offset takeover: </b>
///									- SWA offset takeover will happen if below conditions meet:
///											- 1) If driven distance computed from volume histogram(VDYSwaOffsData_t->VDYSwaOffsEst_t->VDYHistogram_t->sum) crosses threshold distance(VDYSwaOffsData_t->VDYSwaOffsEst_t->VDYHistogram_t->ThrldDist)
///													-  Threshold distance with respect to state
/// |  State  |     Threshold Distance|
/// |---------|-----------------------| 
/// |   0     |       20k			  |
/// |   1     |       25k			  |
/// |   2     |       30k			  |
/// |   3     |       35k			  |
/// |   4     |       40k			  |
/// |   5     |       40k			  |
/// |   6     |       50k			  |
///													-  Set deviation with respect to state
/// |  State  |  Deviation    |
/// |---------|---------------|
/// |   0     |   1 degree    |
/// |   1     |   1 degree    |
/// |   2     |   1 degree    |     
/// |   3     |   1 degree    |
/// |   4     |   0.5 degree  |
/// |   5     |   0.5 degree  |     
/// |   6     |   0.5 degree  |
/// .
///											- 2) Discretized currently estimated offset is within range (<=12 deg)
///											- 3) Calculated confidence is greater than or equal to required confidence.
/// | State            | Required confidence |
/// |------------------|---------------------|
/// |SWA_STATE_DEFAULT |          LOW		 |
/// |SWA_STATE_1       |          LOW		 |
/// |SWA_STATE_2       |          LOW		 |
/// |SWA_STATE_3       |          LOW		 |
/// |SWA_STATE_4       |         Medium		 |
/// |SWA_STATE_5       |         Medium		 |
/// |SWA_STATE_6       |         Medium		 |
///							- SWA ERROR interface:
///											- 1) The Histogramm is rejected in case of offset out of range e.g offsef  > 12 deg (could be defined in the vdy parameter file) or the estimated  confidence is less 0.2 if learn state is equal or below 3 and less than 0.5 if learn state above 3.
///											- 2) Increment the Reinit counter (ReInitCntr) if offset is out of range i.e offset>12 deg and estimated offset confidence is greater than greater than zero.
///											- 3) If the steering angle histograms are rejected (Reint happen) in a row e.g. 3 times (could be defined in the vdy parameter file) the error event errOffsRg sets active.
///											- Else error event errOffsRg  sets inactive
///							- <b> SWA Offset takeover		 </b>
///											- 1) If state is SWA_STATE_DEFAULT, \n new SWA offset = current estimated SWA offset
///											- 2) If state is not SWA_STATE_DEFAULT, \n New SWA offset is average of existing and newly estimated offset.
///											- 1) If current state is SWA_STATE_DEFAULT
///													- 	a) Increment state by 1 and increment over take counter by 1.
///													- 	b) Final offset = new SWA offset	
///													- 	c) Write final offset and state into the EEPROM
///													- 	d) Reinitialize the histogram (as mention in requirement: Reinitialization of histogram)
///											- 2) If current state is SWA_STATE_1/ SWA_STATE_2 /SWA_STATE_3
///													- 	a) If the difference between existing and newly estimated offset is less than 1.5 deg, \n Increment state by 1 and increment over take counter by 1. \n Else \n Keep the current state and do not increment over take counter		
///													- 	b) Final offset = new SWA offset
///													- 	c) Write final offset and state into the EEPROM
///													- 	d) Reinitialize the histogram (as mention in requirement: Reinitialization of histogram)
///											- 3) If current state is SWA_STATE_4
///													-    a) If the difference between existing and newly estimated offset is greater than 0.5 deg, \n Keep the current state and do not increment over take counter \n Else \n Increment state by 1 and increment over take counter by 1.
///													- 	b) Final offset = new SWA offset
///													- 	c) Write final offset and state into the EEPROM
///													- 	d) If the difference between existing and newly estimated offset is greater than 0.5 deg, \n Reduce histogram by 50%	(as mention in requirement: reduction of  histogram) \n Else \n Reinitialize the histogram (as mention in requirement: Reinitialization of histogram)
///											-   4) If current state is SWA_STATE_5 :
///													- 	4A) if the difference between existing offset and currently estimated offset is greater than 0.5 deg,
///															- 	a. Reduce state by 1
///															- 	b. Do not update final SWA offset with newly estimated offset value
///															- 	c. Do not write the final offset into EEPROM
///															- 	d. Reduce Histogram by 50%
///													- 	4B) If the difference between existing offset and currently estimated offset is less than 0.5 deg and \n Change of state from 4 to 5 did not happen in the present ignition cycle (as indicated by Take Over counter = 0)
///															- 	a. Increment state by 1
///															- 	b. Update final SWA offset with newly estimated offset value
///															- 	c. Write the final offset into EEPROM
///															- 	d. Reduce Histogram by 50%
///													- 	4C) If the difference between existing offset and currently estimated offset is less than 0.5 deg and \n Change of state from 4 to 5 happens in the present ignition cycle (as indicated by Take Over counter = 1)
///															- 	a. Hold existing state
///															- 	b. Do not update final SWA offset with newly estimated offset value
///															- 	c. Do not write the final offset into EEPROM
///															- 	d. Reduce Histogram by 50%
///											- 	Remark: Changing the state from 4->5-> 6 cannot happen in one ignition cycle.
///											- 5) If current state is SWA_STATE_6:
///													- 	5A) if the difference between existing offset and currently estimated offset is greater than 0.5 deg,
///															- 		a. Reduce state by 1
///															- 		b. Do not update final SWA offset with newly estimated offset value
///															- 		c. Do not write the final offset into EEPROM
///															- 		d. Reduce Histogram by 50%
///													- 	5B) if the difference between existing offset and currently estimated offset is less than 0.5 deg,
///															- 		a. Hold existing state
///															- 		b. Do not update final SWA offset with newly estimated offset value
///															- 		c. Do not write the final offset into EEPROM
///															- 		d. Reduce Histogram by 50%	
///											- After takeover set EEPROM write request flag i.e., VDYSwaData_t->VDYSwaOffsEEprom_t->EEPromWriteRequ = 1,
///							- <b> SWA Histogram Reinit: </b>
///											- Set histogram Mean, Dev and sum to zero \n VDYSwaOffsData_t->VDYSwaOffsEst_t->VDYHistogram_t->Mean = 0.F \n VDYSwaOffsData_t->VDYSwaOffsEst_t->VDYHistogram_t->Dev = 0.F \n VDYSwaOffsData_t->VDYSwaOffsEst_t->VDYHistogram_t->sum = 0.F
///											- Set the value of each bin of volume histogram to zero.	\n VDYSwaOffsData_t->VDYSwaOffsEst_t->VDYHistogram_t->Volume[binNo] = 0.F;
///							- <b> SWA histogram Reduction: </b>
///											- Reduce histogram volume in each bin to reduction factor percent of the respective bin volume.
///											- Reduce sum to reduction factor percent of sum \n \n
///							- <b> Lateral acceleration offset </b> \n The estimation of the lateral acceleration offset is done by the same algorithm like the steering wheel angle offset. \n With the same assumptions. \n \n The estimated lateral acceleration offset is successive approximated across several ignition cycles to get a more accurate estimation and less dependence on one single route type. If the approximation runs to steady state and the estimated offset is confirmed the estimation is completed. If the estimated offset deviates from current offset the successive approximation is restarted. 
///							- <b> Lateral acceleration offset NVM Interface </b> \n The NVM lateral acceleration offset interface, consists of the offset and a learn state:
///											- Lateral acceleration offset [m/s^2]
///											- learn state in range from 0 to 3
///															- 0: offset value not existen
///															- 1: run up of offset
///															- 2: run up of offset
///															- 3: learn and relearn
///							- <b> Ay NVM Initialization </b>
///											- 1) Ay offset and state shall be initialized with req port NVM data if following conditions meet:
///															- NVM read state for Ay is valid (6th bit of req port NVm state)
///															- control mode is running
///											- 2) If Ay offset and state are out of range, Ay offset and state are initialized with default values.
///															- default values \n offset => SWA_ANG_OFFS_DEFAULT (0.0f) \n state =>SWA_STATE_DEFAULT (zero) \n Dev = 1.0f/3.0f .
///											- 3) Based on Ay offset state threshold distance and deviation shall be get updated.
///															- Distance with respect to state
/// 														 	|State |  Distance |
///									    					 	|------|-----------|
///  														 	|   0  |    20k	|
///															 	|   1  |    25k	|
/// 														 	|   2  |    30k	|
///														  		|   3  |    30k	|
///															- Deviation with respect to state
///  															|State | Deviation |
///  															|------|-----------|
///  															|   0  |   0.5f	|
///  															|   1  |   0.5f	|
///  															|   2  |   0.5f	|
///  															|   3  |   0.2f	|
///							- <b> Conditions to add samples to Ay histogram if below condition meets: </b>
///											- Steering wheel angle should be less than 30 degree
///											- Velocity is greater than 10KMPH
///											- Vehicle is moving in forward direction
///											- Front wheel difference is less than 0.3f
///											- Rear wheel difference is less than 0.3f
///											- Lateral acceleration state is valid
///											- Calibration mode is off for Ay
///							- <b> If circular motion is detected reset the histogram and Reset integrated lateral acceleration. </b>
///							- <b> Ay NVM Initialization </b>
///											- If control mode is running and NVM read state for Ay is valid (both 6th and 7th bits of reqVDYPrtList_t->VDYNvIoData_t->VDYNvmState_t are zeros)
///															- 1) NVM Ay offset and state are within range, \n Internal Ay offset and state shall be initialized with req port NVM data in the following way:  \n  VDYAyOffsData_t->AyOffset = reqVDYPrtList_t->VDYNvIoData_t->LatAcc_t->ZeroAccel \n VDYAyOffsData_t->OffsState = reqVDYPrtList_t->VDYNvIoData_t->LatAcc_t->CalStatus \n and inactive the Ay offset range error 
///															- 2) If Internal Ay offset is out of range (>1.2) or state is invalid(less than 0 or greater than 3), internal Ay offset and state are initialized with default values. \n VDYAyOffsData_t->AyOffset = AY_OFFS_DEFAULT (0.0f) \n VDYAyOffsData_t->OffsState = AY_STATE_DEFAULT (Zero) \n VDYAyOffsData_t->Dev = 1/3; \n And \n VDYAyData_t->VDYAyIo_t->VDYNvIoData_t->LatAcc_t->ZeroAccel = AY_OFFS_DEFAULT \n VDYAyData_t->VDYAyIo_t->VDYNvIoData_t->LatAcc_t-CalStatus = AY_STATE_DEFAULT \n And activate the Ay offset range error
///															- If control mode is running and NVM read state for Ay is invalid (6th or 7th bits of reqVDYPrtList_t->VDYNvIoData_t->VDYNvmState_t is zero), use Ay init offset values. \n VDYAyOffsData_t->AyOffset = AY_OFFS_DEFAULT (0.0f) \n VDYAyOffsData_t->OffsState = AY_STATE_DEFAULT (Zero) \n VDYAyOffsData_t->Dev = 1/3;
///							- <b> Conditions to collect samples to Ay histogram: </b>
///											- Input Steering wheel angle should be valid and less than 30 degree
///											- Velocity is greater than 10m/s
///											- Motion state should not be reverse
///											- When FL and FR are valid and absolute speed difference between front wheels (FL-FR) is less than 0.3f
///											- When RL and RR are valid and absolute speed difference between Rear wheels (RL-RR)is less than 0.3f
///											- Lateral acceleration input signal state is valid
///											- Calibration mode is off for Ay(BSW_s_VDYCtrlData_t -> CaliMode != 32)
///							- <b> Initialization of Ay range and volume histogram: </b>
///											- Create two histogram range (VDYAyData_t->VDYAyOffsEst_t->VDYHistogram_t->Range) and volume (VDYAyData_t->VDYAyOffsEst_t->VDYHistogram_t->Volume) of size 41 bins(AY_OFFS_HIST_NO_BINS)
///											- Max and min range of histogram are +5.25f to -5.25f and is calculated using formula +/- (((float32)((uint32)((float32)AY_OFFS_HIST_NO_BINS/ 2.0F))) + 0.5F) * AY_OFFSET_HIST_WIDTH. \n Where AY_OFFSET_HIST_WIDTH = 0.25f.
///											- Bin width is computed as (max range -min range)/AY_OFFS_HIST_NO_BINS.
///											- All the bins of volume histogram are initialized with zero. \n hist->Volume[binNo] = 0.F;
///											- All the bins of range histogram are initialized with (min range + ((Bin index+0.5)*binWidth) \n i.e hist->Range[binNo]  = (binWidth * ((float32)binNo + ROUNDING_OFFSET)) + minValue;
///							- <b> Updating Ay range and volume histogram: </b>
///											- Find respective bin index (idx) by ((Input Ay - min range) / BinWidth) + 0.5
///											- Corresponding respective bin (idx) of Volume histogram (i.e hist->Volume[idx]) is updated by cumulatively adding the distance covered and update the total distance covered (i.e hist->Sum) \n hist->Volume[idx] += velocity *cycle time; \n hist->Sum+ = velocity *cycle time;
///											- Range histogram can be updated by below formula: \n weight = velocity * cycle time; \n invWeight = 1.0F / (weight + hist->Volume[idx]); \n hist->Range[idx] = (hist->Range[idx] * (hist->Volume[idx] * invWeight)) + ((weight * input Ay) * invWeight);
///							- <b> Ay mean computation: </b>
///											- Mean is computed as average of cumulative weighted sum range histogram. \n mean   += hist->Volume[idx] * hist->Range[idx]; \n volSum += hist->Volume[idx]; \n mean /= volSum
///							- <b> Ay Median computation: </b>
///											- Get the index by calculating median of volume histogram and get the value from range histogram for corresponding index.
///							- <b> Ay Confidence calculation and offset estimation: </b>
///									- 1) If absolute difference between mean with maximum count bin is less than 0.2f, estimated offset is equal to mean (VDYAyOffsData_t->VDYAyOffsEst_t->Offs = hist->Mean)and set the confidence (VDYAyOffsData_t->VDYAyOffsEst_t->Conf) as below: \n - Medium confidence (AY_SWA_OFFS_MAX_CONF = 0.5): Driving long section with same steering wheel angle (straight or constant radius) \n - Max confidence (AY_SWA_OFFS_MAX_CONF=1): if adjacent bins of maximum have enough counts 
///									- 2) If the count difference between secondary peak and maximum peak of volume histogram is big enough (>20% of total volume), estimated offset is mean around (max+3 and max-3) maximum peak and set confidence as low (AY_SWA_OFFS_LOW_CONF = 0.2f)
///									- 3)If the absolute difference between median and max count bin is less than 0.3f and the difference between mean around maximum peak (max+10 and max-10) and median is less than 0.2 , set offset as median and set confidence as Low.
///									- 4) If none of the above condition meets, set confidence as low.
///							- <b> Conditions for Ay Offset takeover: </b> \n Ay offset takeover will happen if below conditions meet:
///									- 1) If driven distance computed from volume histogram(VDYAyOffsData_t->VDYAyOffsEst_t->VDYHistogram_t->sum) crosses threshold distance(VDYAyOffsData_t->VDYAyOffsEst_t->ThrldDist)
///											- Threshold distance with respect to state
///  | State | Threshold Distance |
///  |-------|--------------------|
///  |   0   |        20k         |
///  |   1   |        25k         |
///  |   2   |        30k         |
///  |   3   |        30k         |
///											- Set deviation with respect to state
///  | State |     Deviation
///  |-------|--------------------|
///  |   0   |        0.5         |
///  |   1   |        0.5         |
///  |   2   |        0.5         |
///  |   3   |        0.2         |
/// .
///									- 2) Estimated offset is within range (<=1.2)
///									- 3) Calculated confidence is greater than or equal to required confidence.
///  |   State           | Required confidence |
///  |-------------------|---------------------|
///  |SWA_STATE_DEFAULT  |         LOW		   |
///  |SWA_STATE_1        |         LOW         |
///  |SWA_STATE_2        |         LOW		   |
///  |SWA_STATE_3        |       Medium		   |
///							- <b> Ay Offset takeover: </b> 
///									- Offset:
///											- 1) If state is AY_STATE_DEFAULT, new Ay offset = current estimated Ay offset
///											- 2) If state is not AY_STATE_DEFAULT, new Ay offset = (0.3*existing offset) + (0.7*newly estimated offset).
///									- Offset state:
///											- 1) If current state is AY_STATE_DEFAULT/AY_STATE_1/AY_STATE_2 and Interims flag is inactive (i.e. FALSE)
///													- a) If the difference between existing and newly estimated offset is less than 0.7f, \n Increment over take counter by 1 and if takeover counter is less than AY_OFFS_TAKE_OVR_MAX (where AY_OFFS_TAKE_OVR_MAX = 3U), increment state by 1. \n Else \n Keep the current state and do not increment over take counter		
///													- b) Final offset = new SWA offset
///													- c) Write final offset and state into the NVM
///													- d) Reinitialize the histogram (as mention in requirement: Reinitialization of histogram)
///													- e) Update current Ay offset and state with new ay offset and state respectively
///											- 2) If current state is AY_STATE_3
///													- A) If the difference between existing and newly estimated offset is greater than or equal to 0.5f,
///															- a) Change state to AY_STATE_2 and do not increment over take counter
///															- b) Final offset = new SWA offset
///															- c) Write final offset and state into the NVM
///															- d) If Interims flag is FALSE, reinitialize the histogram (as mention in requirement: Reinitialization of Ay histogram)
///													- B) If the difference between existing and newly estimated offset is less than 0.5f and Interims flag is FALSE
///															- a) Keep the state as AY_STATE_3 and increment over take counter by 1
///															- b) Final offset = new SWA offset
///															- c) Write final offset and state into the NVM
///															- d) Reinitialize the histogram (as mention in requirement: Reinitialization of Ay histogram)
///							- <b> Ay NVM Write: </b>
///									- Write the final offset and state to pro port. \n proVDYPrtList_t->VDYNvIoData_t->LatAcc_t->ZeroAccel = VDYAyOffsData_t-AyOffset \n proVDYPrtList_t->VDYNvIoData_t->LatAcc_t->CalStatus = VDYAyOffsData_t->OffsState
///							- <b> Ay Histogram Reinit: </b>
///									- Set histogram Mean, Dev and sum to zero \n VDYAyOffsData_t->VDYAyOffsEst_t->VDYHistogram_t->Mean = 0.F \n VDYAyOffsData_t->VDYAyOffsEst_t->VDYHistogram_t->Dev = 0.F \n VDYAyOffsData_t->VDYAyOffsEst_t->VDYHistogram_t->sum = 0.F
///									- Set the value of each bin of volume histogram to zero. \n VDYAyOffsData_t->VDYAyOffsEst_t->VDYHistogram_t->Volume[binNo] = 0.F;
///							- <b> Ay Histogram Reduction: </b>
///									- Reduce histogram volume in each bin to reduction factor percent of the respective bin volume.
///									- Reduce sum to reduction factor percent of sum \n 
///									.
///							.
/// Goto : \ref SWA_LAOffsetEstimationUnit \n
/// \page YWRSensorSignalProcessing Yaw Rate Sensor Signal Processing
/// Goto : \ref YWRSensorSignalProcessingUnit \n \n \n 
/// \ref YWRSensorSignalProcessing \n
/// vdy_ywr.c : This module contains the yaw rate sensor signal processing
///							- Yaw rate standstill calibration
///									- Turn Table Detection \n When the vehicle is on the turn-table stand-still is detected. Yaw rate gyro picks up turn table rate which is further used for stand still offset computation eventually leading to wrong offset computation. \n Hence to overcome this issue VDY first detects the Turn table scenario if it satisfies the below conditionds,
///											- 1) Motion State should detect a vehicle standstill.
///											- 2) Gier Yaw rate should be greater than 7 deg/sec.
///									- Once VDY detects a turn table, No offset computation is performed. \n Maximum stand-still offset learning in a stand still cycle (from the time vehicle enters into stand still condition till drive-off point) should not exceed 4 deg/sec from the standstill offset of previous cycle. \n If difference between the  Current computed offset and the frozen offset before standstill > 4deg/s but < 7 deg/s,then \n Present Offset = Frozen offset +/- 4deg/s. \n If difference between the  Current computed offset and the frozen offset before standstill < 4deg/s \n Present Offset = Computed offset. \n vdy_internal_data.vdy_wye_out.front_whl_yaw_rate_filt_wld - YawRateFilt>7&&vdy_internal_data.vdy_wye_out.rear_whl_yaw_rate_filt_wld - YawRateFilt>7
///	@startuml
/// note left
///	VDY Yaw Rate Standstill Calibration
/// <img:images\VDY_YawRateStandStillCalibration.PNG>
/// end note
/// @enduml
///							- During the vehicle standstill situation the vehicle yaw rate is zero (earth rotation is neglectable). So the observed sensor yaw rate during this situation is the zero yaw rate sensor offset. The measured sensor signal during vehicle standstill is averaged to improve the accuracy. Furthermore the yaw acceleration and standard deviation is checked to avoid erroneous calibration due to possible vehicle motions in spite of detected vehicle standstill. The averaged values are buffered into a FIFO structure and by start of vehicle motion the last values calculated during standstill are discarded to prevent miss-calibration because of delayed reset of vehicle standstill. \n The yaw rate standstill offset is stored to nonvolatile memory. This nonvolatile offset value will be used if no vehicle standstill is present during the startup phase.
///											- ToAutocode Interface: \n Fill the interface to with the stand still offset and flags used by the autocode module. This interface should include the information when the stand still offset could be overtake as startup value for the dynamic offset estimation. \n The state should have the following information
///													- 0 = DoNot takeover the offset, no offset stand still offset
///													- 1 = Stand still offset autocode should takeover this offset
///													- 2 = EEProm offset autocode should takeover this offset
///													- 3 = NoOffset autocode should not takeover this offset
///							- <b> Yaw rate offset NVM Interface </b> \n The NVM yaw rate offet interface includes four values:
///									- Min yaw rate offset [rad/s]
///									- Max yaw rate offset [rad/s]
///									- Yaw rate offset, [rad/s], 
///									- Yaw rate offset state, range [0..100]
///							- To determine the min and max yaw rate offset the actual mean filtered stand still offset is used and not the nvm yaw rate offset because the nvm yaw rate offset is low pass filtered depending on the nvm yaw rate offset state. If the nvm yaw rate offset will be used, peaks in the yaw rate offset will not be stored as min max to the nvm.
///									- Yaw rate offset computation shall be done only when
///											- Control Mode is running,
///											- Yaw rate input is VALID,
///											- Stand-Still is detected,
///											- Turn table is not detected
///											- Yaw rate signal is stable. \n VDYIn.Frame.CtrlMode = VDY_CTRL_STATE_RUNNING \n input->Signals.State  == VDY_IO_STATE_VALID \n VDYYwrData_t.VDYYwrSenData_t.YawRate = input->Signals.YawRate \n VDYYwrData_t.VDYYwrSenData_t.Valid = true \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.StandstillOK = true \n VDYYwrData_t.VDYYwrSenData_t.Gradient <= 1.2 deg/sec
///							- <b> Calculate run times required for offset calibration </b>
///									- Update ECU runtime up to maximum permitted value(Maximum ECU running time 10 days) \n VDYYwrData_t.VDYYwrOffsData_t.EcuElpsdTime	=(10.0F * 24.0F * 60.0F * 60.0F) \n else \n VDYYwrData_t.VDYYwrOffsData_t.EcuElpsdTime	= VDYYwrData_t.VDYYwrOffsData_t.EcuElpsdTime + CycleTime(Avoid zero or too large cycle times, 20 ms is nominal cycle time)
///									- Update time since last offset calibration up to maximum permitted value(Maximum time since last calibration) \n VDYYwrData_t.VDYYwrOffsData_t.OffsElpsdTime = (60.0F * 60.0F) else \n VDYYwrData_t.VDYYwrOffsData_t.OffsElpsdTime = VDYYwrData_t.VDYYwrOffsData_t.OffsElpsdTime+CycleTime(Avoid zero or too large cycle times, 20 ms is nominal cycle time)
///									- Update time since last storage of standstill offset to nonvolatile memory \n VDYYwrData_t.VDYYwrOffsData_t.StandStillEepromOffset.TimeLastWrittenEepromOffset = (60.0F * 60.0F) \n else \n Start timing not until first value has been written \n if  (VDYYwrData_t.VDYYwrOffsData_t.StandStillEepromOffset.NumOfWrittenOffsets > 0 \n VDYYwrData_t.VDYYwrOffsData_t.StandStillEepromOffset.TimeLastWrittenEepromOffset = VDYYwrData_t.VDYYwrOffsData_t.StandStillEepromOffset.TimeLastWrittenEepromOffset+CycleTime(Avoid zero or too large cycle times, 20 ms is nominal cycle time) 
///							- Stability of the yaw rate signal is determined based on the gradient computed between the previous and the present filtered yaw rate input signal. \n For the first cycle previous yaw rate filtered signal is initialized with present input value \n If the gradient is less than or equal to 1.2 then it can be considered as stable (offset will be computed) \n when  (VDYYwrData_t.VDYYwrSenData_t.Valid == TRUE) \n 	in case of first cycle, init old filt yaw rate with actual yaw rate \n if VDYYwrData_t.VDYYwrSenData_t.YwFirstCycleDone == FALSE \n VDYYwrData_t.VDYYwrSenData_t.YawRateOld = input->Signals.YawRate \n Note : \n Find YawRateFilt using VDYYwrData_t.VDYYwrSenData_t.YawRate, VDYYwrData_t.VDYYwrSenData_t.YawRateOld with Filter time constant for input filter of yaw rate sensor signal (0.25F) \n Find Gradient using YawRateFilt, VDYYwrData_t.VDYYwrSenData_t.YawRateOld \n Gradient = (YawRateFilt - VDYYwrData_t.VDYYwrSenData_t.YawRateOld)/20ms \n Gradient <=1.2F(then it can be considered as stable.)
///							- when the yaw rate is INVALID reset the previous yaw rate filtered signal to zero. \n input->Signals.State[VDY_SIN_POS_YWR] = VDY_IO_STATE_INVALID \n VDYYwrData_t.VDYYwrSenData_t.Valid == FALSE
///							- Reset the previous yaw rate filtered signal to zero \n VDYYwrData_t.VDYYwrSenData_t.DeltaDist         = 0.F; \n VDYYwrData_t.VDYYwrSenData_t.Gradient          = 0.F; \n 	VDYYwrData_t.VDYYwrSenData_t.GradientAbsOld    = 0.F; \n VDYYwrData_t.VDYYwrSenData_t.YawRate           = 0.F; \n VDYYwrData_t.VDYYwrSenData_t.YawRateCurveFilt1 = 0.F; \n VDYYwrData_t.VDYYwrSenData_t.YawRateCurveFilt2 = 0.F; \n VDYYwrData_t.VDYYwrSenData_t.YawRateCurveFilt3 = 0.F; \n VDYYwrData_t.VDYYwrSenData_t.YawRateOld        = 0.F; \n VDYYwrData_t.VDYYwrSenData_t.YwCurveOld        = 0.F; \n VDYYwrData_t.VDYYwrSenData_t.Valid             = FALSE; \n VDYYwrData_t.VDYYwrSenData_t.YwFirstCycleDone  = FALSE; \n VDYYwrData_t.VDYYwrSenData_t.FilterTime        = 0.F; 
///							- <b>Max Quality : </b> \n Standstill Max Quality will be computed based on Sample volume *Cycle time using interpolation table. \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.MaxQuality = Linear ramp function(VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.Volume * CycleTime)
///							- Compute Quality Time based on Offset elapsed time and multiply with Max. Quality, with respect to OffsType.(QualNo Read) \n - VDYYwrData_t.VDYYwrOffsData_t.QualNoRed = VDYYwrData_t.VDYYwrOffsData_t.MaxQuality * Linear ramp function(VDYYwrData_t.VDYYwrOffsData_t.OffsElpsdTime) \n \n Remark : \n Using Interpolation table compute Quality time (In the main file, this is used for changing the State from 1 to 2 if Quality Time based on Offset elapsed time > 0.75) \n As the sequence of execution is (Volume * Cycle time) ----> Max Quality -----> Take Over Offset ---> Quality time ( = Max Quality * Interplotation table (ECU elapsed time)) \n Take Over offset only if Max Quality > Quality time satisfies : Quality time is always equal to Max Quality as the output of the interpolation table is always less than or equal to 1.
///							- Compute EEPROM Quality Time based on Offset EcuElpsdTime and multiply with StandStillEepromOffset MaxQuality.(QualNo Read) \n - VDYYwrData_t.VDYYwrOffsData_t.QualNoRed = VDYYwrData_t.VDYYwrOffsData_t.StandStillEepromOffset.MaxQuality * Linear ramp function(VDYYwrData_t.VDYYwrOffsData_t.EcuElpsdTime)
///							- Mean, Deviation and Sum of the squares, of the second buffer is updated with data of first buffer computed from set of fifteen samples subsequently reset the first buffer with zero. \n Deviation and Sum of the squares, of the second buffer is updated with data of first buffer computed from next set of fifteen samples and third buffer data is updated with data of second buffer. Subsequently reset first and second buffers. \n VDYYwrData_t.VDYYwrOffsData_t.Observable = true \n collect 15 samples in the first buffer VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_1 using YawRateFilt and Weight constant 1 \n 	VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_1.Sum    =  VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_1.Sum+YawRateFilt*Weight \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_1.SqSum  =  VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_1.SqSum+SQR(Value) * Weight \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_1.Volume =  VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_1.Volume+Weight \n check if VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_1.Volume >= 15 \n copy gathering interval to delay interval VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_2 \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_2.Sum    +=  VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_1.Sum \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_2.SqSum  +=  VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_1.SqSum \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_2.Volume +=  VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_1.Volume \n Add delay interval to evaluation interval VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.Sum    +=  VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_2.Sum \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.SqSum  +=  VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_2.SqSum \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.Volume +=  VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_2.Volume \n
///							- Yaw rate offset learning is limited to 4 deg/sec compared to previous offset. \n - Take over new zero point offset if it the delta offset difference is under the MAX limit else take delta offset as previous offset +/-  4deg/sec \n if ((PrevYawRateOffset - VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.Mean) < 4) \n PrevYawRateOffset - VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.YawRateOffset = VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.Mean \n else if \n  VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.Mean >PrevYawRateOffset \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.YawRateOffset = PrevYawRateOffset+4 \n else \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.YawRateOffset = PrevYawRateOffset-4 \n	
///							- If sufficient number of samples are collected in the third buffer, final yaw rate offset shall be calculated based on moving average of third buffer data. Sufficient number of samples reached or not is determined based on product of Number of Samples collected multiplied with cycle time. (Max Quality > Quality time) \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.MaxQuality = Linear ramp function(VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.Volume * CycleTime)
///							- If the sample count reaches 3000 reduce the volume to 90%. \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.Sum  *= 0.9  \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.SqSum *= 0.9 \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.Volume *= 0.9 \n \n Remark : Last 30 samples are not considered for yaw rate offset computation.\n
///							- Reset all buffers,
///									- a. If the input yaw rate is INVALID  \
///									- b. If there is a jump in the yaw rate offset. Jump is determined from sqrt((Sqsum/Vol-Mean*Mean)) > Threshold. \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.Sum  = 0 \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.SqSum = 0 \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.Volume = 0 \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.Mean  = 0 \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.Dev = 0 \n \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_1.Sum  = 0  \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_1.SqSum = 0 \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.Volume = 0 \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_1.Mean  = 0 \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_1.Dev = 0 \n \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_2.Sum  = 0 \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_2.SqSum = 0 \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_2.Volume = 0 \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_2.Mean  = 0 \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_2.Dev = 0 \n 
///							- When INVALID yawrate OR NON-Stand-still is detected CLEAR / RESET first and second buffers. \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_1.Sum  = 0 \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_1.SqSum = 0 \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.Volume = 0 \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_1.Mean  = 0 \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_1.Dev = 0 \n \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_2.Sum  = 0 \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_2.SqSum = 0 \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_2.Volume = 0 \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_2.Mean  = 0 \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval_2.Dev = 0  \n From the event INVALID yawrate OR NON-Stand-still occurs AND when the volume of third buffer is Non zero: Hold the third buffer data Till Adjustable time = 60s  then clear the third buffer \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.Sum  = 0 \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.SqSum = 0 \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.Volume = 0 \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.Mean  = 0 \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.SampleInterval.Dev = 0 \n VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.AdjustTime = 0
///							- When Ego speed is zero (Stand-still detected), if signal sate is VALID using Take Off function update Yaw rate offset and Offset type as follows, \n a. Yaw rate offset = 0 and Offset type = 0 subsequently in the auto-code function and Main function(Default case till enough time collect the samples)  \n		Takeoff \n		if(VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.MaxQuality>=VDYYwrData_t.VDYYwrOffsData_t.QualNoRed)->fails \n		VDYYwrData_t.VDYYwrOffsData_t.YawRateOffset = 0 \n 		VDYYwrData_t.VDYYwrOffsData_t.MaxQuality	 = 0 \n		VDYYwrData_t.VDYYwrOffsData_t.OffsType		 = 0 \n 		Autocode \n 		VDYYwrData_t.VDYYwrOffsData_t.ToAutocode.OffsData.offset = 0.0F \n 		VDYYwrData_t.VDYYwrOffsData_t.ToAutocode.OffsData.state = 3 \n 		Maincode \n 		proPorts->pVDYOffsets->Ywr.StandStillOffset = VDYYwrData_t.VDYYwrOffsData_t.ToAutocode_t.vdy_yaw_offset_t.offset \n 		proPorts->pVDYOffsets->Ywr.StandStillState = 0 \n \n 		b. Yaw rate offset = Moving average of third buffer data and Offset type = 1 once condition of Max Quality > Quality time is satisfied \n 		   subsequently no change in offset and offset type happens in auto-code interface and in the MAIN function set Offset type = 1 or 2 based on Max Quality. \n 		Takeoff \n 		If the MAx quality <=0.6 set Offset type 1 and if MAx quality > 0.75 set Offset type = 2. \n 		VDYYwrData_t.VDYYwrOffsData_t.YawRateOffset = VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.YawRateOffset \n 		VDYYwrData_t.VDYYwrOffsData_t.MaxQuality	 = VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.MaxQuality \n 		VDYYwrData_t.VDYYwrOffsData_t.OffsType		 = 1 \n 		VDYYwrData_t.VDYYwrOffsData_t.OffsElpsdTime = 0.F \n 		Autocode \n 		VDYYwrData_t.VDYYwrOffsData_t.ToAutocode.OffsData.offset = VDYYwrData_t.VDYYwrOffsData_t.YawRateOffset \n 		VDYYwrData_t.VDYYwrOffsData_t.ToAutocode.OffsData.state = 1 \n 		Maincode \n 		proPorts->pVDYOffsets->Ywr.StandStillOffset = VDYYwrData_t.VDYYwrOffsData_t.ToAutocode_t.vdy_yaw_offset_t.offset \n 		if ((VDYYwrData_t.VDYYwrOffsData_t.QualNoRed >= 0.75F) || (proPorts->pVDYOffsets->Ywr.StandStillState == 2) \n 		proPorts->pVDYOffsets->Ywr.StandStillState = 2 \n 		else \n 		proPorts->pVDYOffsets->Ywr.StandStillState = 1 \n							- When Ego speed is non-zero during Ignition-ON, Offset Type = 0 (initialized value) if signal sate is VALID and NVM read state is VALID for POS = 4 using Take Off function update Yaw rate offset and Offset type as follows, \n 		a. Yaw rate offset = EEPROM offset and Offset type = 5 once condition of EEPROM Quality > Quality time is satisfied subsequently in the Auto-code interface function set Offset type = 2 and in MAIN function set Offset type = 3 \n 		VDYYwrGlobData.Io.nv_read.State==valid \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillEepromOffs_t.VDYYwrEepromOffset_t.Offset1 = m_reqVDYPortList.pNVMRead->YwRate.ZeroRate; \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillEepromOffs_t.VDYYwrEepromOffset_t.Status1 = m_reqVDYPortList.pNVMRead->YwRate.CalStatus; \n 		VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillEepromOffs_t.VDYYwrEepromOffset_t.MaxQuality = Min(m_reqVDYPortList.pNVMRead->YwRate.CalStatus*0.33F, 1)	 \n 		Takeoff \n 		VDYYwrData_t.VDYYwrOffsData_t.YawRateOffset = VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillEepromOffs_t.VDYYwrEepromOffset_t.Offset1 \n 		VDYYwrData_t.VDYYwrOffsData_t.MaxQuality	 = VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillEepromOffs_t.VDYYwrEepromOffset_t.MaxQuality \n 		VDYYwrData_t.VDYYwrOffsData_t.OffsType		 = 5 \n 		VDYYwrData_t.VDYYwrOffsData_t.OffsElpsdTime = 0.F \n 		Autocode \n 		VDYYwrData_t.VDYYwrOffsData_t.ToAutocode.OffsData.offset = VDYYwrData_t.VDYYwrOffsData_t.YawRateOffset \n 		VDYYwrData_t.VDYYwrOffsData_t.ToAutocode.OffsData.state = 2 \n Info : Maincode \n proPorts->pVDYOffsets->Ywr.StandStillOffset = VDYYwrData_t.VDYYwrOffsData_t.ToAutocode_t.vdy_yaw_offset_t.offset \n proPorts->pVDYOffsets->Ywr.StandStillState = 3z
///							- If signal sate is INVALID Yaw rate offset and Offset type are updated as follows, \n 		a. Yaw rate offset = 0 and Offset type = 3 in the autocode interface and Offset type = 0 (Not estimated) in the MAIN.  \n 		Takeoff \n 		if(VDYYwrData_t.VDYYwrOffsData_t.VDYYwrStandStillOffs_t.MaxQuality>=VDYYwrData_t.VDYYwrOffsData_t.QualNoRed)->fails \n 		VDYYwrData_t.VDYYwrOffsData_t.YawRateOffset = 0 \n 0		VDYYwrData_t.VDYYwrOffsData_t.MaxQuality	 = 0 \n 		VDYYwrData_t.VDYYwrOffsData_t.OffsType		 = 0 \n 		Autocode \n 		VDYYwrData_t.VDYYwrOffsData_t.ToAutocode.OffsData.offset = 0.0F \n 		VDYYwrData_t.VDYYwrOffsData_t.ToAutocode.OffsData.state = 3 \n 		Maincode \n 		proPorts->pVDYOffsets->Ywr.StandStillOffset = VDYYwrData_t.VDYYwrOffsData_t.ToAutocode_t.vdy_yaw_offset_t.offset \n 		proPorts->pVDYOffsets->Ywr.StandStillState = 0 \n 
///
///	Goto : \ref YWRSensorSignalProcessingUnit \n
///	\page WheelSpeedSignalProcessing Wheel Speed Signal Processing
///	Goto : \ref WheelSpeedSignalProcessingUnit \n
///	\ref WheelSpeedSignalProcessing
///	vdy_whs.c : This module contains the wheel speeds signal processing
///	- Estimates the offset wheel velocity left / right for front and rear axis (K(fr) and K(re)).
///	- The offset of the wheel is calculated if within a defined velocity range and when the vehicle is driving straight (shown by the curve output from the ye module). \n The ratio between the left and right wheel on each axle is stored in a histogram.  There are 4 histograms evenly distributed from 40kph to 220kph.  A histogram is evaluated after 50 samples and the histogram reduced to 15%.  The new offset values used until a new offset was calculated by reaching 50 samples again in the current velocity range. \n The offset data including the histograms exist for front and rear axle separately and do not influence each other.
///	- The wheel offsets are not stored in NVM but calculated every startup from scratch.  The tires are heated after some driving, but maybe cold after start.  The difference in tire pressure will result in different offset values and they need to be recalculated again. \n The tires might also have been swapped or exchanged with different tires.
///	- Detect driving straightSet by setting the flag (VDYWhsOffsData_t.ExWspStatus) when Radius is greater than 3500m. \n (Note: VDYWhsTrackStraight())
///	- Computation of delta distance: 
///		- a. filtered curve gradient = input curve gradient if input curve gradient is more than last filtered curve gradient.
///		- b. filtered curve gradient = input curve gradient passed through Low Pass Filter, if input curve gradient is less than last filtered curve gradient.
///		- c. If filtered curve gradient is less than 1/1500(GradMax) and last DeltaDist is less than 150(maxDist_c), compute cumulative delta distance using VehSpeed * CycleTime
///		- d. Reset DeltaDist, when filtered curve gradient is greater than 1/1500(GradMax) \n (Note: VDYCalcDistStblGrad())
///	- Speed ranges is discritized into 4 intervals based on the VehicleSpeed(interval1 0-45 KMPH, interval2 90-135 KMPH, interval3 135 - 180 KMPH and interval4 180 - 225 KMPH) \n (Note: VDYWhsVehSpeedRange())
///	- Start computing offset (statistical ratio of left to right wheel speeds) if the VehicleSpeed is more than 0.83m/s and wheel speeds are valid \n (Note: VDYWhsCalcOffsetAxle())
///	- Criteria for offset compensation:
///		- a. TrackStatus should be ok(req 1)
///		- b. DeltaDist >=40/3.6 
///		- c. 3. 40kmph<=VehicleSpeed<=220kmph
///		- d. Wheel speed calibration mode is offset
///	- Start collecting the samples in Sampleinterval (VDYStatInterval_t.Sum, VDYStatInterval_t.Sqsum and VDYStatInterval_t.Volume) \n (Note: VDYStatIntervalAdd())
///	- Computing the mean(VDYStatInterval_t.mean) and dev(VDYStatInterval_t.dev) (by using VDYStatInterval_t.Sum, VDYStatInterval_t.Sqsum and VDYStatInterval_t.Volume) of sampleinterval after collecting the 50 samples. \n (Note: VDYStatIntervalMeanDev())
///	- check mean and standard deviation of SampleInterval is within the threshold values respectivly(mean threshold1.0247 and dev threshold 0.0015)
///		- a. Mean, Volume and Sqsum of Front and Rear axle speed ratio, for each speed range, are initialized with Sample-Interval data for the first 1000 samples
///		- Tuning factor is computed based on the deviation between Sample interval filtered mean and individual interval mean.
///			- a. if the Difference is less than WHS_MEAN_SMPL_DIFF_THR1(0.0002) set tuning factor = 1
///			- b. if the Difference is greater than WHS_MEAN_SMPL_DIFF_THR2(0.0004) set tuning factor = 15
///			- c. if the WHS_MEAN_SMPL_DIFF_THR1<=Difference<=WHS_MEAN_SMPL_DIFF_THR2 then tuning factor = interpolate b/w 1 and 15 \n (Note: VDYWhsCalcMeanFactor())
///	- SampleInterval and Interval sum, sqsum and volume of specific speed range is updated as follows
///		- a. Offset->SampleInterval.Sum = Offset->SampleInterval.Sum*Tuning factor, Offset->SampleInterval.sqSum = Offset->SampleInterval.sqSum*Tuning factor, Offset->SampleInterval.volume = Offset->SampleInterval.volume*Tuning factor
///		- b. Offset->Interval[IntSpeedRange].Sum = +Offset->SampleInterval.Sum, Offset->Interval[IntSpeedRange].sqSum = +Offset->SampleInterval.sqSum, Offset->Interval[IntSpeedRange].volume = +Offset->SampleInterval.volume \n Note: VDYStatIntervalReduce() and VDYStatIntervalMerge()
///	- Calculate interval mean and deviation for a particular speed range  \n (Note: VDYStatIntervalMeanDev())
///	- If the volume of a particular speed range crosses 10000, reduce the sum, sqsum and volume by 90%
///		- a. Offset->Interval[IntSpeedRange].Sum *=  0.9, Offset->Interval[IntSpeedRange].sqSum *=  0.9, Offset->Interval[IntSpeedRange].volume *=  0.9 \n (Note: VDYStatIntervalReduce())
///	- During Transition from one speed range to another speed range initialize the current speed range sum, sqsum and volume with the last speed range data and compute the mean and dev. \n 	(Note: VDYWhsSetOffIntLastRange() and VDYWhsSetOffIntLastRange()) \n 
///
///
///	Goto : \ref WheelSpeedSignalProcessingUnit \n
///	\page VDYVelCorr Velocity Correction
///	vdy_velcor.c : The velocity correction block corrects the vehicle velocity estimation from wheel speed sensors based on the relative velocity measurement of stationary objects.
///
///	@startuml
/// note left
///	Velocity Estimation and Correction
/// <img:images\VelocityEstimation.PNG>
/// end note
/// @enduml
/// The velocity correction in detail: 
///	@startuml
/// note left
///	Velocity Correction in detail
/// <img:images\VelocityCorrection.PNG>
/// end note
/// @enduml
/// Relative velocity histogram: 
///	@startuml
/// note left
///	Relative Velocity Histogram
/// <img:images\RelativeVelocityHistogram.PNG>
/// end note
/// @enduml
/// \n These histograms are accumulated in three additional histograms for the velocity range 0 - 60 [km/h], 60 - 140 [km/h] and 140 - 220 [km/h]. When any of these three histograms has accumulated up to 8000 objects, the median over the whole histogram delivers the correction factor. The correction factor c0 is memorized in non-volatile memory along with the average velocity for the correction value and the linear gradient c1 inside the velocity range.
/// \n At the current velocity v the correction value is f = c0 + v * c1.
/// \n Velcor module generates 3 fault events
/// 		- Sets the correction factor out off range fault if the estimated correction factor is above 1.1 or below 0.9 for 2 times in a row
/// 		- Set the measurements distribution error. 
/// 				- If the deviation of the accumulated histogramm is above 0.02 or the shape of the histogram is not well formed (first, second and median distances are too high...), the accumulated histogram is rejected. After 5 rejected historams in a row, fault errWin is set.
/// 		- Fault description:
/// 				- Unable to correct provided vehicle velocity by use of stationary targets of radar sensor. For that relative velocity rations of quasi stationary targets (= rel. velocity window around provided vehicle velocity). The correction factor is calculated as mean of normal distribution distribution among the collected velocity ratios.
/// 				- <b> Setup conditions </b> \n The collected distribution are 
/// 						- not normal distributed or 
/// 						- the majority of targets velocity ratios are outside the windows (0.6 .. 1.4) five times in row.  
/// 						- typ. duration of one sample interval = ~60 s while
/// 				- <b> Reset condition </b> \n One sample distribution with required attributes (see setup conditions)
/// 				- <b> Constraints  </b> \n There is ambiguity in lower vehicle speed range where lot surrounding vehicles aer driving slowly. This can spoil the distribution and trigger false alarms.
/// 				- <b> Criticality </b> \n Due to ambiguousness, event is not critical in all cases.
/// 		- <b> Velocity correction factor NVM Interface </b> \n The NVM velocity correction factor interface, consists of three velocity ranges (10 - 60 kmh, 60- 140 kmh and 140- 240 kmh), each of them has the follwing values:
/// 				- Velocity correction factor
/// 				- Mean velocity for this speed range [m/s]
/// 				- Standard deviation of the correction factor, max deviation is (0.1F/3.0F) if a value is learned is must be below this max value.
/// 		- <b> Node Initialization and Estimator Initialization: </b>
/// 				- a. Node description: \n Variables associated with correction factor are Node.Vel, Node.CF, Node.Dev, State
/// 				- b. State of each Node is initialized with Init during VDY Initialization
/// 				- c. Initialization of node values if NVM read state is VALID:
/// 						- a. Node State is Init and Stored node velocity is within range.
/// 						- b. Stored corrected deviation is within threshold
/// 						- c. Set the Node State to BACK-UP after initializaed with NVM data.
/// 				- d. Initialize covariance of estimator after estimator initialization. If states are out of range then states need to be initialized.
/// 				- e. Estimator shall not be initialized when "NVM read is INVALID" or "any of the node states is BACK-UP or READY"
/// 		- <b> Learning conditions of correction factor: </b> \n The samples shall be collected in the histogram for computing the Correction Factor only if the OBSERVABLE flag is TRUE. \n Set OBSERVABLE FLAG = FALSE if any of the following conditions are met,
/// 				- a. Velocity of the vehicle shall be les than 10 KMPH and greater than 240 KMPH
/// 				- b. If vehicle is moving in reverse direction
/// 				- c. Counter (timer) representing dynamic driving conditions is greater than zero,
/// 						- 1. Counter shall be reset to 1000 if absolute value of acceleration > 1 m/sec2 OR the difference between present and previous velocity > 0.2 OR the VDY estimated radius is less than 200 m and Counter shall be decreased by 20.
/// 		- <b> Initialization of Node.Vel: </b> \n Initialize all three Ego Velocities with Uncorrected velocity when node[0].state = INIT
/// 		- <b> Histogram Evaluation and Rejection: </b> \n The histogram distribution shall be considered for CF calculation only if following conditions are met, 
/// 				- a. If Second-highest index volume is less than 70% of max-index volume. \n OR \n If Second-highest index volume is greater than 70% of max-index volume and they are adjecent. 
/// 				- b. If Third-highest index volume is less than 50% of max-index volume. \n OR \n If Third-highest index volume is greater than 50% of max-index volume and they are adjecent with 2 bin difference.
/// 		- <b> Histogram Rejection: </b> \n If the above condiitons are not met then reset histogram by 
/// 				- a. reducing the sum of all volume to zero
/// 		- <b> Take Over of Correction Factor: </b> 
/// 				- a. Compute correction factor only if the sum of all bin volumes reaches more than 400 and if respective node.state is BACK-UP or READY
/// 				- b. Compute correction factor only if the sum of all bin volumes reaches more than 200 and if respective node.state is INIT. \n
/// 				- 1) If the histogram provides clear distribution, reduce measured ambiguous velocity distributions counter and set error errWin to inactive.
/// 				- 2) If the calculated Median is within range (greater than 0.9 and less than 1.1), take over learned values.
/// 						- Set the State to START-UP if the previous state is INIT.       
/// 						- Set the state to READY if the previous state is BACK-UP \n and also set error errFactRg to inactive. else increment correction factor out range counter by 1 and reinitiate histogram.
/// 				- 3) Once the CF is computed reduce the sum.volume to 20% of total volume collected if state is INIT else reduce the sum.volume to 40% of total volume collected if state is not INIT
/// 		- <b> Computation of Median and Standard deviation: </b> 
/// 				- A. Ten bins before and Ten bins after Max-Index bin along with Max-Index bin shall be considered for Median and Deviation computation.
/// 				- B. Compute first, second and third quarties, Second quartile is considered as median. 0.7413 of difference between first and third quartiles is considered as deviation.
/// 		- <b> NVM Write Conditions: </b> \n If new daviation computed is less than standard daviation, write the newly computed correction factor, daviation and velocity to NVM else keep the stored value.
/// 		- <b> Adding sample to histogram </b> \n Ratio of  ALN velocity and uncorrected Ego velocity is used to get the index of the bin to add sample. \n velcor = ALN velocity/ uncorrected Ego velocity \n BINS_CORR_FACTOR_START_VALUE = (1.0F - (((REF_SPEED_NO_BINS-1.0f)/2.0f) * BINS_CORR_FACTOR_STEP)) \n where REF_SPEED_NO_BINS = 81 and BINS_CORR_FACTOR_STEP = 0.01 \n Bin Index = ((velcor - BINS_CORR_FACTOR_START_VALUE) /BINS_CORR_FACTOR_STEP)+0.5 \n \n Note : Macros are defined in file  vdy_velcor.c
/// 		- <b> Resetting histogram: </b> 
/// 				- 1. Out-Of-Bound sample count shall be increased by one if the CF at a given instance is more than 1.4 and less than 0.6.
/// 				- 2. Reset histogram if Out-Of-Bound sample count is exceeding 30% of the required volume and the total samples collected is less than 50% of required volume. Required volume shall be 200 if the node state is INIT and it is 400 if the node state is not INIT. 
/// 		- <b> Velocity Correction Monitoring fault - </b> \n Condition:
/// 				- 1.	abs(ALN speed - VDYUncorrSpeed) – 4*(squareroot(Var(UncorrSpeed)+ std dev of ALN) > 10% UncorrSpeed
/// 				- 2.	If the difference between ALN speed and VDY uncorrected velocity is greater than 2m/s, \n \n
/// 				- A) Set Condition : \n If both Conditions 1 & 2 are satisfied for 333 radar cycles then error will be set. And set VDYFSVelCorrMon.fault active.
/// 				- B) Reset Condition: \n If any of the above condition is not satisfied then error will be reset (VDYFSVelCorrMon.fault = VDY_ERR_STATE_INACTIVE) 
/// 		- Set flag b_init_CorrFlag to TRUE, if VDYFSVelCorrMon.fault = VDY_ERR_STATE_INACTIVE first time.
/// 		- <b> VDYVelCorrCalcResult </b> \n If flag b_init_CorrFlag set to TRUE, \n CF variance = P[0]+(V^4*P[3])+(V^2*(P[1]+P[3])) 
/// 				- 1) if CF variance is greater than (0.1/3) , set CF variance = 0.1/3.
/// 				- 2)if CF variance is less than or equal to (0.1/3) and the difference between Ego velocity mean at which previous CF computed and current Ego velocity mean at which correction factor is calulated is less than 20 KM/h, \n set CF variance = 0.01 
/// 				- corrVeloVar1 = ((uncorrected velocity)^2* CF variance)+((CF^2) * Velocity variance) \n corrVeloVar = corrVeloVar1 * 0.1*uncorrected velocity
/// 				- else \n CF variance = VDY_CORR_INIT_STD_DEV_START*VDY_CORR_INIT_STD_DEV_STAR=0.0225;	\n corrVeloVar = (2.0F*uncorrected velocity * 0.1)^2 /12.0F;
/// 		- <b> Velocity confirmation check (confFault) </b> \n condition: \n abs(corrected velocity - Aln velocity)< (1+corrected velocity variance) \n \n Set condition: \n Above condition is not satisfied for 333 cycles. \n \n Reset condition: \n Above condition is satisfied.
/// \page CommonFunctions Common Functions 
/// Goto : \ref CommonFunctionsUnit \n \n \n 
/// \ref CommonFunctions
/// vdy_cofct.c : This module contains the commonly used function
///									- histogram building and maintenance, 
///									- interval building and maintenance
///									- filter funktions (low pass, high pass ..)
///									- Sorting  funktions (HeapSort) \n
///									.
///
/// \page VDYAye Yaw Rate Estimation With Lateral Acceleration
/// \ref VDYAye \n
/// vdy_aye.c : vdy ay yaw rate estimation, uses lateral acceleration signal and offset compensated yaw rate to calculate the ay yaw rate. \n \n
/// <b> Architecture Diagram: </b>
///	@startuml
/// note left
///	VDY Yaw Rate Estimation with Lateral Acceleration 
/// <img:images\aye.PNG>
/// end note
/// @enduml
///	- <b> Inputs & Outputs: </b> 
///			- <b> Inputs: </b> 
///					- <b> 1. From Input Signal Bus (VehSigMain) </b> 
///							- Lateral Acceleration (m/s2)
///							- Lateral Acceleration State
///							- Vehicle Velocity (m/s)
///							- Cycle Time (ms)
///					- <b> 2. From VDY internal processing: </b> 
///							- Gier Yaw Rate (rad/s)
///							- Gier Yaw Rate Variance (rad2/s2)
///							- Lateral Acceleration Offset (m/s2)
///							- Lateral Acceleration Offset State
///			- <b> Outputs: </b> 
///					- 1. Lateral Acceleration Yaw Rate (rad/s)
///					- 2. Lateral Acceleration Yaw Rate Variance (rad2/s2)
///					- 3. Track Bent (rad)
///					- 4. Track Bent Variance (rad2)
///					- 5. Ronoff 
///					.
///			.
///		\n \n
///
/// \page VDYGye Yaw Rate Estimation With Gier Sensor 
/// \ref VDYGye \n
/// vdy_gye.c : vdy gier yaw rate estimation, estimates the offset compensated gier yaw rate \n \n 
/// <b> Architecture Diagram: </b>
///	@startuml
/// note left
///	VDY Gier Sensor Yaw Rate Estimation
/// <img:images\gye.PNG>
/// end note
/// @enduml
///	- <b> Inputs & Outputs: </b> 
///			- <b> Inputs: </b> 
///					- <b> 1. From Input Signal Bus (VehSigMain) </b> 
///							- Gier yaw Rate
///							- Gier Yaw Rate State
///							- Cycle Time (ms)
///					- <b> 2. From VDY internal processing: </b> 
///							- Gier yaw rate standstill offset
///			- <b> Outputs: </b> 
///					- Gier yaw Rate
///					- Gier yaw Rate Variance
///					- Ronoff
///					.
///			.
/// \n \n \n
/// \page VDYSye Yaw Rate Estimation With Steerig Wheel Angle
/// \ref VDYSye \n
/// vdy_sye.c : vdy steering angle yaw rate estimation and driver intended curvature estimation \n \n 
/// <b> Architecture Diagram: </b>
///	@startuml
/// note left
///	VDY Yaw Rate Estimation With Steerig Wheel Angle
/// <img:images\sye.PNG>
/// end note
/// @enduml
///	- <b> Inputs & Outputs: </b> 
///			- <b> Inputs: </b> 
///					- <b> 1. From Input Signal Bus (VehSigMain) </b> 
///							- Steer Wheel Angle (rad)
///							- Steer Wheel Angle State
///							- CaliMode
///							- Cycle Time (ms)
///							- Steering Ratio
///							- Wheel Base
///					- <b> 2. From VDY internal processing: </b> 
///							- Gier Yaw Rate (rad/s)
///							- SWA Offset
///							- SWA Offset S
///							- Ve_Velocity(m/s)
///							- Ye_Lateral Acceleration(m/s2)
///					- <b> 3. From NVM - </b> 
///							- VDY_NV_Data_in
///			- <b> Outputs: </b> 
///					- stw_understeer_grad_var
///					- stw_understeer_grad_max
///					- stw_understeer_grad_min
///					- stw_understeer_grad
///					- stw_understeer_grad_disc
///					- stw_understeer_control
///					- VDY_NV_Data_out
/// - <b> Driver intended curvature : </b> \n This curvature points into the direction which is intend by the driver’s steering wheel. It is estimated in the steering wheel pre processing module and uses the offset compensated steering wheel signal. \n \n 
///
/// \page VDYWye Yaw Rate Estimation With Wheel Speeds 
/// \ref VDYWye \n
/// vdy_wye.c : vdy wheel yaw rate estimation, estimates the wheel yaw rate and the offset of the gyro sensor yaw rate. Therefore the four wheel speeds and the gyro yaw rate are used. \n \n
/// <b> Architecture Diagram: </b>
///	@startuml
/// note left
///	VDY Yaw Rate Estimation With Wheel Speeds 
/// <img:images\wye.PNG>
/// end note
/// @enduml
///	- <b> Inputs & Outputs: </b> 
///			- <b> Inputs: </b> 
///					- <b> 1. From Input Signal Bus (VehSigMain) </b> 
///							- YawRate
///							- YawRateState
///							- TrackWidthFront
///							- TrackWidthRear
///							- VehWeight
///							- CntrOfGravHeight
///							- AxisLoadDistr
///							- WhlLoadDepFrontAxle
///							- WhlLoadDepRearAxle
///							- CaliMode
///							- Cycle Time (ms)
///					- <b> 2. From VDY internal processing: </b> 
///							- Wheel Offset Ratio Front
///							- Wheel Offset Ratio Rear
///							- Wheel Offset Ratio Front Dev
///							- Wheel Offset Ratio Rear Dev
///							- Ve_Velocity(m/s)
///							- Ye_LateralAccel
///							- Wpp_whlVlFL
///							- Wpp_whlVlFL
///							- Wpp_whlVlRL
///							- Wpp_whlVlRR
///							- Wpp_whlVlFL_var
///							- Wpp_whlVlFL_var
///							- Wpp_whlVlRL_var
///							- Wpp_whlVlRR_var
///					- <b> 3. From NVM - </b> 
///							- VDY_NV_Data_in
///			- <b> Outputs: </b> 
///					- WLD_FrontAxle
///					- WLD_RearAxle
///					- WhlYawRate_FrontAxle
///					- WhlYawRate_RearAxle
///					- EstimatedWLD
///					- WLD_Control
///					- WhlYawDiff_FrontRear
///					- VDYNVData_out   
///					.
///			.
///
/// \page VDYYe Yaw Rate Estimation With AYE, GYE, SYE & WYE
///	\ref VDYYe \n
/// vdy_ye.c : Vdy yaw rate estimation for the vehicle, merges the four yaw rates to the vehicle yaw rate and merge this yaw rate with the driver intended curvature to a vehicle curve. \n All of the used input signals for yaw rate estimation are not error-free, whereas the influences are very different. Thus, the design goal is to combine all signals to achieve the best estimation. The yaw rate signal has the best overall properties, but only after a dynamic offset compensation. \n The yaw rate is estimated in two steps, first all four input signals are each preprocessed by single Kalman filters. In the second step the outputs of these filtered values are merged together by using the Mahalanobis distance and a Kalman filter. \n \n
/// <b> Architecture Diagram: </b>
///	@startuml
/// note left
///	VDY Yaw Rate Estimation
/// <img:images\ye.PNG>
/// end note
/// @enduml
///	- <b> Inputs & Outputs of Yaw rate Estimation: </b> 
///			- <b> Inputs: </b> 
///					- <b> 1. From Input Signal Bus (VehSigMain) </b> 
///							- Cycle Time (ms)
///					- <b> 2. From VDY internal processing: </b> 
///							- Gier Yaw Rate (rad/s)
///							- Gier Yaw Rate Variance (rad^2/s2)
///							- Steering Wheel Yaw Rate (rad/s)
///							- Steering Wheel Yaw Rate Variance (rad^2/s^2)
///							- Wheel Speeds Yaw Rate (rad/s)
///							- Wheel SpeedsYaw Rate Variance (rad^2/s^2)
///							- Lateral Acceleration Yaw Rate (rad/s)
///							- Lateral AccelerationYaw Rate Variance (rad^2/s^2)
///							- Vehicle Velocity (m/s)
///							- Ronoff (Gier , Wheel Speeds , SteeringWheel , Lateral Acceleration)
///			- <b> Outputs: </b> 
///					- Vehicle Yaw Rate (rad/s)
///					- Vehicle Yaw Rate Variance (rad^2/s^2)
/// - <b> Vehicle Curvature : </b> \n It is calculated in the yaw rate merging module, and merges the vehicle yaw rate and the Driver intended curvature. At low speed the vehicle curvature is more like the driver intended curvature. \n \n 
///
/// \page VDYMotSt Motion State Estimation
/// vdy_mot_st.c : vdy motion state estimation, use a bayes net to compute a motion state \n The motion state detemerination uses the yaw rate, estimated longitudinal velocity, wheel ticks deviation, brake torque, parking brake state and the gear shift position. \n \n
/// <b> Architecture Diagram: </b>
///	@startuml
/// note left
///	VDY Motion State Estimation
/// <img:images\mot_st.PNG>
/// end note
/// @enduml
///	- <b> Inputs & Outputs: </b> 
///			- <b> Inputs: </b> 
///					- The deviated wheel impulse of the four wheels
///					- The estimated vehicle velocity
///					- The wheel direction of the four wheels
///					- The actual brake torque
///					- The gear shift position
///					- The park brake state.
///			- <b> Outputs: </b> 
///					- Motion State
///					- Quality \n \n
///					.
///			.
///
/// \page VDYWpp Wheel Speeds PreProcessing
/// \ref VDYWpp \n
/// vdy_wpp.c : \n vdy_wpp module estimates and merges four wheel speeds \n 
/// <b> Architecture Diagram: </b>
///	@startuml
/// note left
///	VDY Wheel Speeds PreProcessing
/// <img:images\wpp.PNG>
/// end note
/// @enduml
///	- <b> Inputs & Outputs: </b> 
///			- <b> Inputs: </b> 
///					- <b> 1. From Input Signal Bus (VehSigMain) </b> 
///							- Four Wheel Velocities (m/s)
///							- States of Four Wheel Velocities
///							- Four Wheel Ticks
///							- States of Four Wheel Ticks
///							- ABS 
///							- ABS State
///							- TCS
///							- TCS State	
///							- Cycle Time (ms)
///					- <b> 2. From Input Parameter Bus (VehParMain) </b> 
///							- Wheel Ticks Per Revolution
///							- Wheel Circumference
///			- <b> Outputs: </b> 
///					- 1. Four Wheel Velocities (m/s)
///					- 2. Four Wheel Velocity Variances (m2/s2)
///					- 3. Four Wheel Accelerations (m/s2)
///					- 4. Four AquaSlip States
///					.
///			.
///			
/// \page VDYVe Velocity Estimation
/// \ref VDYVe \n
/// vdy_ve.c : vdy_ve module merges the four wheel speeds and estimates vehicle velocity and acceleration. \n  This function uses the wheel speed and wheel ticks deviation signals from the four wheels to estimate the longitudinal velocity and acceleration via Kalman Filtering. This velocity and the following signals, if available, are then used for the motion state detection. \n \n
/// <b> Architecture Diagram: </b>
///	@startuml
/// note left
///	VDY Velocity Estimation 
/// <img:images\ve.PNG>
/// end note
/// @enduml
///	- <b> Inputs & Outputs: </b> 
///			- <b> Inputs: </b> 
///					- 1. <b> From Input Signal Bus (VehSigMain) </b> 
///							- Four Wheel Velocities
///							- States of Four Wheel Velocities
///							- States of Four Wheel Ticks
///							- VehLongAccelExt
///							- VehLongAccelExt State
///							- Cycle Time (ms)
///					- 2. <b> From VDY internal processing: </b> 
///							- Four Wheel Velocities (m/s)
///							- Four Wheel Velocity Variances
///							- Four Wheel Accelerations	
///			- <b> Outputs: </b> 
///					- Vehicle Velocity (m/s)
///					- Vehicle Velocity Variance
///					- Vehicle Acceleration (m/s2)
///					- Vehicle Acceleration Variance
///					.
///			.
///
/// \page VDYSae Sideslip Angle Estimation
/// \ref VDYSae \n
/// vdy_sae.c : The Side slip angle is calculated out of the estimated yaw rate and longitudinal velocity. This is the input for a small Kalman filter. \n \n
/// <b> Architecture Diagram: </b>
///	@startuml
/// note left
///	VDY Sideslip Angle Estimation
/// <img:images\sae.PNG>
/// end note
/// @enduml
///	- <b> Inputs & Outputs: </b> 
///			- <b> Inputs: </b> 
///					- 1. <b> From Input Signal Bus (VehSigMain) </b> 
///							- Steer Wheel Angle (rad)
///							- Steer Wheel Angle State
///							- CaliMode
///							- Cycle Time (ms)
///							- Steering Ratio
///							- Wheel Base
///					- 2. <b> From VDY internal processing: </b> 
///							- Gier Yaw Rate (rad/s)
///							- SWA Offset
///							- SWA Offset S
///							- Ve_Velocity(m/s)
///							- Ye_Lateral Acceleration(m/s2)
///					- 3. <b> From NVM - </b> 
///							- VDY_NV_Data_in
///			- <b> Outputs: </b> 
///					- stw_understeer_grad_var
///					- stw_understeer_grad_max
///					- stw_understeer_grad_min
///					- stw_understeer_grad
///					- stw_understeer_grad_disc
///					- stw_understeer_control
///					- VDY_NV_Data_out
///					.
///			.
///