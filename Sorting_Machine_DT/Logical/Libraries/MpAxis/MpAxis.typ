
TYPE
	MpAxisBasicParType : 	STRUCT  (*Axis runtime parameters*)
		Acceleration : REAL := 200.0; (*Acceleration [Units/sec²]*)
		Deceleration : REAL := 200.0; (*Deceleration [Units/sec²]*)
		Velocity : REAL := 100.0; (*Velocity [Units/sec]*)
		Position : LREAL := 0.0; (*Position [Units]*)
		Distance : LREAL := 0.0; (*Distance [Units]*)
		Direction : MpAxisMoveDirectionEnum := mpAXIS_DIR_POSITIVE; (*Direction of movement*)
		Home : MpAxisHomingType; (*All homing parameters*)
		Jog : MpAxisJogType; (*All jog parameters*)
		Stop : MpAxisStopType; (*All stop parameters*)
		StopAfterTrigger : MpAxisStopAfterTriggerType; (*All stop parameters for stopping after a trigger*)
		Torque : MpAxisTorqueLimitType; (*All torque parameters*)
		CyclicRead : MpAxisCyclicReadSetupType; (*Settings for the cyclic reading of axis information*)
		Autotune : MpAxisAutotuneType; (*All tuning parameters*)
	END_STRUCT;
	MpAxisHomingType : 	STRUCT  (*Homing parameters*)
		Mode : MpAxisHomeModeEnum := mpAXIS_HOME_MODE_DIRECT; (*Homing mode*)
		Position : LREAL := 0.0; (*Position or offset [units]*)
		StartVelocity : REAL := 50.0; (*Velocity when searching for the reference switch [units/s]*)
		HomingVelocity : REAL := 5.0; (*(Trigger) velocity after the reference switch has been found [units/s]*)
		SensorOffset : LREAL := 0.0; (*At the end of the homing procedure, the axis will start a movement to reach this offset [units]*)
		Acceleration : REAL := 500.0; (*Acceleration during homing [units/s²]*)
		StartDirection : MpAxisHomeMoveDirectionEnum := mpAXIS_HOME_DIR_POSITIVE; (*Starting direction to search for the homing reference (FALSE = Default, TRUE = Inverse)*)
		HomingDirection : MpAxisHomeMoveDirectionEnum := mpAXIS_HOME_DIR_POSITIVE; (*Trigger direction after the homing reference has been found (FALSE = Default, TRUE = Inverse)*)
		NoDirectionChange : MpAxisHomeOptionEnum := mpAXIS_HOME_OPTION_OFF; (*Specifies whether the direction can be changed during the homing procedure*)
		SwitchEdge : MpAxisHomeMoveDirectionEnum := mpAXIS_HOME_DIR_POSITIVE; (*Edge for the reference switch*)
		ReferencePulse : MpAxisHomeOptionEnum := mpAXIS_HOME_OPTION_OFF; (*Specifies whether the reference pulse is looked for during the homing movement*)
		ReferencePulseBlockingDistance : LREAL := 0.0; (*After the block has been reached, the axis will move at least this distance (stopping at the next reference pulse)*)
		TorqueLimit : REAL := 0.0; (*Torque limiting for block homing [Nm]*)
		BlockDetectionPositionError : LREAL := 0.0; (*Lag error for block detection [units]*)
		PositionErrorStopLimit : LREAL := 0.0; (*Lag error at which the movement is stopped [units]*)
		EndlessPositionDataRef : UDINT := 0; (*Optional: The address of the "EndlessPositionData" (MC_ENDLESS_POSITION) structure for absolute encoders. If >0, the "InitEndlessPosition" function is enabled during initialization (restore position from permanent memory)*)
	END_STRUCT;
	MpAxisJogType : 	STRUCT  (*Parameters for jogging command*)
		Acceleration : REAL := 400.0; (*Acceleration [Units/sec²]*)
		Deceleration : REAL := 400.0; (*Deceleration [Units/sec²]*)
		Velocity : REAL := 100.0; (*Velocity [Units/sec]*)
		LowerLimit : LREAL := 0.0; (*Lower position limit used while jogging. If upper and lower limits are both zero, limits are not considered, If the axis is not periodic, axis software  limits are used instead*)
		UpperLimit : LREAL := 0.0; (*Upper position limit used while jogging. If upper and lower limits are both zero, limits are not considered, If the axis is not periodic, axis software  limits are used instead*)
	END_STRUCT;
	MpAxisStopType : 	STRUCT  (*Parameters for stop command*)
		Deceleration : REAL := 5000.0; (*Deceleration [Units/sec²]*)
		StopInPhase : BOOL := FALSE; (*Optional for a stop command. Axis stops at a defined position*)
		Phase : LREAL := 0.0; (*Position at which the axis should halt if the option is used [units]	*)
	END_STRUCT;
	MpAxisStopAfterTriggerType : 	STRUCT  (*Trigger stop option setup for the movement*)
		Enable : BOOL := FALSE; (*Enables a stop after a trigger*)
		TriggerDistance : LREAL := 0.0; (*Distance after a trigger signal [units]*)
		ForceTriggerDistance : BOOL := FALSE; (*Axis moves the "TriggerDistance" even if the target position has already been exceeded (target position to the destination of absolute or relative movements)*)
		Source : MpAxisTriggerSourceEnum := mpAXIS_TRIGGER1; (*Source for the trigger event*)
		Edge : MpAxisTriggerEdgeEnum := mpAXIS_TRIGGER_EDGE_POS; (*Selects the edge watched by the trigger*)
	END_STRUCT;
	MpAxisTorqueLimitType : 	STRUCT  (*Torque limitation thresholds*)
		Limit : REAL := 0.0; (*Threshold for torque limiting [Nm]*)
		Window : REAL := 0.0; (*Threshold after which an error is output (torque exceeded) [Nm]*)
	END_STRUCT;
	MpAxisCyclicReadSetupType : 	STRUCT  (*Cyclic information setup*)
		TorqueMode : MpAxisReadInfoModeEnum := mpAXIS_READ_OFF; (*Reads the torque*)
		LagErrorMode : MpAxisReadInfoModeEnum := mpAXIS_READ_OFF; (*Reads the lag error*)
		MotorTempMode : MpAxisReadInfoModeEnum := mpAXIS_READ_OFF; (*Reads the motor temperature*)
		UserChannelMode : MpAxisReadInfoModeEnum := mpAXIS_READ_OFF; (*Channel for read cyclically a custom parameter defined in configuration*)
	END_STRUCT;
	MpAxisAutotuneType : 	STRUCT  (*Autotuning setup*)
		Mode : MpAxisAutotuneModeEnum := mpAXIS_TUNE_AUTOMATIC; (*Tuning mode*)
		FeedForward : MpAxisFeedForwardModeEnum := mpAXIS_FF_DISABLED; (*Feed forward mode*)
		Vertical : BOOL := FALSE; (*Axis aligned vertically*)
		MaxCurrentPercent : REAL := 80.0; (*Percentage of the rated current used for autotuning [%]*)
		MaxSpeedPercent : REAL := 80.0; (*Maximum velocity of the movement with respect to the limit parameters [%]*)
		MaxDistance : LREAL := 100.0; (*Maximum movement distance during tuning [units]*)
		ProportionalAmplification : REAL := 100.0; (*Percentage of the additional gain factor (defined by the configuration) being used for closed-loop control [%]*)
	END_STRUCT;
	MpAxisBasicInfoType : 	STRUCT  (*Additional info about the axis*)
		AxisInitialized : BOOL; (*The axis has been completely initialized at least once (configuration loaded to the drive)*)
		ReadyToPowerOn : BOOL; (*Axis ready for "PowerOn" command*)
		JogLimited : BOOL; (*Indicates whether jog movements are stopped by the software limit position*)
		TorqueLimitActive : BOOL; (*Indicates whether torque limiting is active (torque currently being limited)*)
		DriveRestarted : BOOL; (*The drive was restarted, all externally operated drive functions were reset (e.g. SPT networks or ParIDs loaded to the drive later)*)
		CyclicRead : MpAxisCyclicReadType; (*Cyclic information*)
		BootState : MpAxisBootPhaseEnum; (*Current boot state of the drive*)
		PLCopenState : MpAxisPlcOpenStateEnum; (*PLCopen status*)
		DigitalInputsStatus : MpAxisDigitalIOStatusType; (*Digital inputs status*)
		HardwareInfo : MpAxisAddInfoHardwareType; (*Hardware information*)
		Diag : MpAxisDiagExtType; (*Diagnostic structure for the status ID*)
		MoveDone : BOOL; (*Discrete movement done*)
	END_STRUCT;
	MpAxisDigitalIOStatusType : 	STRUCT  (*Digital inputs status*)
		DriveEnable : BOOL; (*Enable input of the drive is closed*)
		HomeSwitch : BOOL; (*Reference switch is active*)
		PositiveLimitSwitch : BOOL; (*Positive limit switch is active*)
		NegativeLimitSwitch : BOOL; (*Negative limit switch is active*)
		Trigger1 : BOOL; (*First trigger input is active*)
		Trigger2 : BOOL; (*Second trigger input is active*)
	END_STRUCT;
	MpAxisAddInfoHardwareType : 	STRUCT  (*Hardware information*)
		NodeID : UINT; (*POWERLINK/CAN node number*)
		Channel : USINT; (*Channel on ACOPOSmulti dual-axis modules*)
		NetworkType : MpAxisNetworkTypeEnum; (*Type of network*)
		DeviceType : MpAxisDeviceTypeEnum; (*Drive type*)
	END_STRUCT;
	MpAxisCyclicReadType : 	STRUCT  (*Cyclic information*)
		Torque : MpAxisCyclicReadValueType; (*Torque value*)
		LagError : MpAxisCyclicReadValueType; (*Lag error value*)
		MotorTemperature : MpAxisCyclicReadValueType; (*Motor temperature value*)
		UserChannelParameterID : MpAxisCyclicReadValueType; (*Custom parameter value*)
	END_STRUCT;
	MpAxisCyclicReadValueType : 	STRUCT  (*Cyclic information*)
		Valid : BOOL; (*The information is valid*)
		Value : LREAL; (*Current value Lag error [units] Temperature [°C] Torque [Nm] Custom [depends of parID]*)
	END_STRUCT;
	MpAxisDiagExtType : 	STRUCT  (*Extended component diagnostics*)
		StatusID : MpAxisStatusIDType; (*StatusID diagnostic structure*)
		Internal : MpAxisInternalType; (*Internal error diagnostic structure*)
		ExecutingCommand : MpAxisExecutingCmdEnum; (*Command currently being executed*)
	END_STRUCT;
	MpAxisDiagType : 	STRUCT  (*Component diagnostics*)
		StatusID : MpAxisStatusIDType; (*StatusID diagnostic structure*)
	END_STRUCT;
	MpAxisStatusIDType : 	STRUCT  (*StatusID structure*)
		ID : MpAxisErrorEnum; (*Error code for mapp component*)
		Severity : MpComSeveritiesEnum; (*Describes the type of information supplied by the status ID (success, information, warning, error)*)
		Code : UINT; (*Code for the status ID. This error number can be used to search for additional information in the help system*)
	END_STRUCT;
	MpAxisInternalType : 	STRUCT  (*Component status internal*)
		ID : DINT; (*HRESULT value as numeric related to internal error*)
		Severity : MpComSeveritiesEnum; (*Severity of internal error*)
		Facility : MpComFacilitiesEnum; (*Facility of internal error*)
		Code : UINT; (*Error ID contained into internal error*)
	END_STRUCT;
	MpAxisAutotuneModeEnum : 
		( (*Autotuning modes*)
		mpAXIS_TUNE_AUTOMATIC := 0, (*Performs a complete autotuning sequence*)
		mpAXIS_TUNE_SPEED := 2, (*Speed controller tuning*)
		mpAXIS_TUNE_POSITION := 1, (*Position controller tuning*)
		mpAXIS_TUNE_TEST := 31, (*Tests system stability*)
		mpAXIS_TUNE_SPEED_ISQ_F1 := 130, (*Speed controller tuning with ISQ filter 1 as a notch filter*)
		mpAXIS_TUNE_SPEED_T_FLTR := 66, (*Speed controller tuning with T_Filter*)
		mpAXIS_TUNE_SPEED_T_FLTR_ISQ_F1 := 194, (*Speed controller tuning with T_Filter and ISQ filter 1 as a notch filter*)
		mpAXIS_TUNE_SPEED_FLTR := 6, (*Speed controller tuning with current filter parameters*)
		mpAXIS_TUNE_ISQ_F1 := 128, (*Tuning of filter 1 as a notch filter*)
		mpAXIS_TUNE_ISQ_F1_F2 := 384, (*Tuning of filters 1 and 2 as a notch filter*)
		mpAXIS_TUNE_ISQ_F1_F2_F3 := 896, (*Tuning of filters 1, 2 and 3 as a notch filter*)
		mpAXIS_TUNE_FF := 32, (*Tuning of feed-forward in both directions*)
		mpAXIS_TUNE_FF_ONLY_POS := 33, (*Tuning of feed-forward in the positive direction*)
		mpAXIS_TUNE_FF_ONLY_NEG := 34 (*Tuning of feed-forward in the negative direction*)
		);
	MpAxisFeedForwardModeEnum : 
		( (*Feed forward tuning modes*)
		mpAXIS_FF_DISABLED := 0, (*Feed-forward tuning switched off*)
		mpAXIS_FF_BOTH := 1, (*Feed-forward tuning for both directions*)
		mpAXIS_FF_ONLY_POS := 2, (*Feed-forward tuning in positive direction only*)
		mpAXIS_FF_ONLY_NEG := 3 (*Feed-forward tuning in negative direction only*)
		);
	MpAxisMoveDirectionEnum : 
		( (*Movement direction options list*)
		mpAXIS_DIR_POSITIVE := 0, (*Movement in the positive direction*)
		mpAXIS_DIR_NEGATIVE := 1, (*Movement in the negative direction*)
		mpAXIS_DIR_CURRENT := 2, (*Movement in the current direction*)
		mpAXIS_DIR_SHORTEST_WAY := 3, (*Movement in the direction offering the shortest path to the destination*)
		mpAXIS_DIR_EXCEED_PERIOD := 8 (*Destination can be outside the axis period*)
		);
	MpAxisHomeModeEnum : 
		( (*Homing mode options list*)
		mpAXIS_HOME_MODE_DEFAULT := 0, (*Reads all parameters except "Position" from the INIT parameter module*)
		mpAXIS_HOME_MODE_ABS_SWITCH := 2, (*Homing using an absolute reference switch*)
		mpAXIS_HOME_MODE_SWITCH_GATE := 8, (*Homing using an absolute reference switch and direction change when the limit switch is reached*)
		mpAXIS_HOME_MODE_LIMIT_SWITCH := 3, (*Homing with limit switches*)
		mpAXIS_HOME_MODE_REF_PULSE := 5, (*Homing with the reference signal in the encoder*)
		mpAXIS_HOME_MODE_DIRECT := 1, (*Direct homing, axis position receives the value on the "Position" input*)
		mpAXIS_HOME_MODE_ABSOLUTE := 4, (*Homing by setting the offset for the absolute encoder*)
		mpAXIS_HOME_MODE_ABSOLUTE_CORR := 6, (*Homing by setting the offset for the absolute encoder with counting range correction*)
		mpAXIS_HOME_MODE_DCM := 9, (*Homing with distance-coded reference marks*)
		mpAXIS_HOME_MODE_DCM_CORR := 10, (*Homing using distance-coded reference marks with counting range correction*)
		mpAXIS_HOME_MODE_RESTORE_POS := 11, (*Homing with the recovery of the absolute position from remanent memory on the controller (used together with absolute encoder)*)
		mpAXIS_HOME_MODE_AXIS_REF := 12, (*Reads all parameters (including "Position") from the INIT parameter module*)
		mpAXIS_HOME_MODE_BLOCK_TORQUE := 13, (*Homing with a torque threshold. If a mechanical block is reached, the axis is considered homed*)
		mpAXIS_HOME_MODE_BLOCK_DS := 14 (*Homing with a lag error threshold. If a mechanical block is reached, the axis is considered homed*)
		);
	MpAxisHomeOptionEnum : 
		( (*Enable / disable options*)
		mpAXIS_HOME_OPTION_OFF := 0, (*Disable the option*)
		mpAXIS_HOME_OPTION_ON := 1 (*Enable the option*)
		);
	MpAxisHomeMoveDirectionEnum : 
		( (*Movement direction options list*)
		mpAXIS_HOME_DIR_POSITIVE := 0, (*Movement in the positive direction*)
		mpAXIS_HOME_DIR_NEGATIVE := 1 (*Movement in the negative direction*)
		);
	MpAxisTriggerSourceEnum : 
		( (*Trigger source options list*)
		mpAXIS_TRIGGER1 := 20, (*Trigger 1 as source*)
		mpAXIS_TRIGGER2 := 22 (*Trigger 2 as source*)
		);
	MpAxisInputSourceEnum : 
		( (*Trigger source options list*)
		mpAXIS_INPUT_NONE := 0, (*Source input not defined (functionality not active)*)
		mpAXIS_INPUT_TRIGGER1 := 1, (*Trigger 1 as source*)
		mpAXIS_INPUT_TRIGGER2 := 2, (*Trigger 2 as source*)
		mpAXIS_INPUT_POS_LIMIT_SWITCH := 3, (*Positive limit switch as source*)
		mpAXIS_INPUT_NEG_LIMIT_SWITCH := 4, (*Negative limit switch as source*)
		mpAXIS_INPUT_HOMING_SWITCH := 5 (*Homing switch as source*)
		);
	MpAxisTriggerEdgeEnum : 
		( (*Trigger edge options list*)
		mpAXIS_TRIGGER_EDGE_POS := 0, (*Trigger evaluated if the input is high*)
		mpAXIS_TRIGGER_EDGE_NEG := 1 (*Trigger evaluated if the input is low*)
		);
	MpAxisReadInfoModeEnum : 
		( (*Cyclic reading mode options list*)
		mpAXIS_READ_OFF := 0, (*Cyclic reading disabled*)
		mpAXIS_READ_CYCLIC := 1, (*Cyclic reading returns a new value in each cycle*)
		mpAXIS_READ_MULTIPLEXED := 2, (*Cyclic reading returns a new value that is multiplexed by POWERLINK*)
		mpAXIS_READ_POLLING_1s := 3, (*Cyclic reading returns a new value every second*)
		mpAXIS_READ_POLLING_5s := 4 (*Cyclic reading returns a new value every five seconds*)
		);
	MpAxisBootPhaseEnum : 
		( (*Acopos boot phase values list*)
		mpAXIS_BLP_NETWORK_INACTIVE := 0, (*Communication with the ACOPOS drive is not active*)
		mpAXIS_BLP_NETWORK_INIT_STARTED := 1, (*Network initialization has been started for this ACOPOS drive*)
		mpAXIS_BLP_WAIT_INIT_HIGH_PRIO := 5, (*Waiting for the network initialization of stations with higher priority (lower node numbers) to complete*)
		mpAXIS_BLP_HW_WAIT := 9, (*Waiting for communication to BsLoader*)
		mpAXIS_BLP_HW_LINKED := 10, (*Communication to BsLoader established*)
		mpAXIS_BLP_HW_START := 20, (*ACOPOS drive starting the BsLoader*)
		mpAXIS_BLP_HW_UPDATE := 30, (*BsLoader being downloaded to this ACOPOS drive*)
		mpAXIS_BLP_HW_UPDATE_OTHER_DRV := 31, (*BsLoader being downloaded to other ACOPOS modules*)
		mpAXIS_BLP_FW_UPDATE := 40, (*Downloading ACOPOS operating system*)
		mpAXIS_BLP_FW_UPDATE_OTHER_DRV := 41, (*Loading ACOPOS operating system to other stations*)
		mpAXIS_BLP_FW_START := 50, (*Booting ACOPOS operating system*)
		mpAXIS_BLP_WAIT_INIT_LOW_PRIO := 55, (*Waiting for the network initialization of stations with lower priority (higher node numbers) to complete*)
		mpAXIS_BLP_DOWNLOAD_DEF_PARAMS := 60, (*Loads default parameters to the ACOPOS drive*)
		mpAXIS_BLP_DOWNLOAD_INI_PARAMS := 70, (*Loading INIT parameter table to the ACOPOS drive*)
		mpAXIS_BLP_HW_INFO_FROM_DRIVE := 80, (*Hardware information are read from the drive*)
		mpAXIS_BLP_DONE := 90 (*Network initialization completed*)
		);
	MpAxisPlcOpenStateEnum : 
		( (*PLCopen status values list*)
		mpAXIS_DISABLED := 0, (*Axis not switched on or switched off after an error*)
		mpAXIS_STANDSTILL := 1, (*No movement active but switched on*)
		mpAXIS_ERRORSTOP := 10, (*An error is active. The state will change once all errors have been acknowledged. If the error causes the axis to be cut off, the new state is Disabled. If not, the state is Standstill*)
		mpAXIS_STOPPING := 9, (*Axis stopping*)
		mpAXIS_DISCRETE_MOTION := 2, (*An absolute or relative movement is active*)
		mpAXIS_CONTINUOUS_MOTION := 3, (*A movement with constant velocity is active*)
		mpAXIS_SYNCHRONIZED_MOTION := 4, (*The axis is synchronous with the master*)
		mpAXIS_HOMING := 5 (*Homing active*)
		);
	MpAxisExecutingCmdEnum : 
		( (*Command in execution values list*)
		mpAXIS_CMD_IDLE := 0, (*Axis waiting for command*)
		mpAXIS_CMD_INIT := 1, (*Initialization active*)
		mpAXIS_CMD_HOMING := 2, (*Homing active*)
		mpAXIS_CMD_STOP := 3, (*Stopping active*)
		mpAXIS_CMD_HALT := 4, (*Halting active*)
		mpAXIS_CMD_MOVE_VELOCITY := 5, (*Movement at defined velocity active*)
		mpAXIS_CMD_MOVE_ABSOLUTE := 6, (*Movement with absolute destination active*)
		mpAXIS_CMD_GEAR_IN := 7, (*Axis following master signal using linear movement*)
		mpAXIS_CMD_GEAR_OUT := 8, (*Gear ratio inactive, axis halting*)
		mpAXIS_CMD_CAM_IN := 9, (*Axis following master signal using cam*)
		mpAXIS_CMD_CAM_OUT := 10, (*Synchronization (with cam) inactive, axis halting*)
		mpAXIS_CMD_DOWNLOAD_CAMS := 11, (*Cam (cam profile) download active*)
		mpAXIS_CMD_MOVE_ADDITIVE := 12, (*Performing relative movement*)
		mpAXIS_CMD_JOG_POSITIVE := 13, (*Axis jogging in positive direction*)
		mpAXIS_CMD_JOG_NEGATIVE := 14, (*Axis jogging in negative direction*)
		mpAXIS_CMD_STOP_PHASED := 15, (*Phase stopped*)
		mpAXIS_CMD_AUTOTUNE := 16, (*Autotuning active*)
		mpAXIS_CMD_REMOTE_CONTROL := 17, (*Axis being controlled by another function block*)
		mpAXIS_CMD_MOVE_VEL_TRG_STOP := 18, (*Constant movement with trigger stop active*)
		mpAXIS_CMD_MOVE_ABS_TRG_STOP := 19, (*Absolute movement with trigger stop active*)
		mpAXIS_CMD_MOVE_ADD_TRG_STOP := 20, (*Relative movement with trigger stop active*)
		mpAXIS_CMD_CAM_SEQUENCER := 50, (*CAM sequencer is active*)
		mpAXIS_COUPLING_IDLE := 100, (*Coupling function block waiting for new command*)
		mpAXIS_CMD_PHASING := 101, (*Applying phase shift*)
		mpAXIS_CMD_OFFSET := 102, (*Applying offset shift*)
		mpAXIS_CMD_ABORT := 103, (*Previous command was aborted from an external source*)
		mpAXIS_CMD_UPDATE_GEAR := 104, (* Updating gear ratio (Gear) parameters*)
		mpAXIS_CMD_UPDATE_CAM := 105, (*Updating cam profile (Cam) parameters*)
		mpAXIS_CMD_RECOVERY := 106, (*Recovering normal state active*)
		mpAXIS_CYCLIC_REF_IDLE := 200, (*Cyclic reference function block waiting for new command*)
		mpAXIS_CMD_CYC_POSITION := 201, (*Axis following a cyclic position*)
		mpAXIS_CMD_CYC_VELOCITY := 202, (*Axis following a cyclic velocity*)
		mpAXIS_CMD_CYC_TORQUE := 203, (*Axis following a cyclic torque*)
		mpAXIS_CMD_CYC_POSITION_UPDATE := 204, (*Updating position parameters*)
		mpAXIS_CMD_CYC_VELOCITY_UPDATE := 205, (*Updating velocity parameters*)
		mpAXIS_CMD_CYC_TORQUE_UPDATE := 206 (*Updating torque parameter*)
		);
	MpAxisNetworkTypeEnum : 
		( (*Network type values list*)
		mpAXIS_CAN_NETWORK := 0, (*CAN Interface*)
		mpAXIS_PLK_NETWORK := 1, (*POWERLINK Interface*)
		mpAXIS_SDC_NETWORK := 129 (*SDC intercace*)
		);
	MpAxisDeviceTypeEnum : 
		( (*B&R motion devices*)
		mpAXIS_DEVICE_UNKNOWN := 0, (*Device not recognized*)
		mpAXIS_ACOPOS := 1, (*Default ACOPOS*)
		mpAXIS_VIRTUAL := 3, (*Virtual axis*)
		mpAXIS_ACOPOSmulti65m := 4, (*ACOPOSmulti65m (ACOPOSmotor)*)
		mpAXIS_ACOPOSmulti := 5, (*ACOPOSmulti*)
		mpAXIS_ACOPOSmulti_PPS := 6, (*ACOPOSmulti Passive Power Supply*)
		mpAXIS_ACOPOSmulti_PS := 2, (*ACOPOSmulti Active Power Supply*)
		mpAXIS_ACOPOSmicro := 7, (*ACOPOSmicro*)
		mpAXIS_ACOPOSmulti65 := 8, (*ACOPOSmulti65 (ACOPOSremote)*)
		mpAXIS_ACOPOS_P3 := 12, (*ACOPOS P3*)
		mpAXIS_ACOPOS_SDC := 128, (*ACOPOS with SDC-Interface*)
		mpAXIS_ACOPOS_SIM := 129 (*ACOPOS simulation*)
		);
	MpAxisBasicConfigType : 	STRUCT  (*Global MpAxis configuration*)
		AxisName : STRING[20] := 'Axis'; (*Axis Name*)
		Axis : MpAxisBasicConfigAxisType; (*Axis configuration*)
		Drive : MpAxisBasicConfigDriveType; (*Drive configuration*)
		PositionOutput : MpAxisPosVelOutputTypeEnum := mpAXIS_OUTPUT_SET; (*Defines if the value provided by Position output is the set profile generated or real motor position*)
		VelocityOutput : MpAxisPosVelOutputTypeEnum := mpAXIS_OUTPUT_SET; (*Defines if the value provided by Velocity output is the set profile generated or real motor velocity*)
	END_STRUCT;
	MpAxisBasicConfigAxisType : 	STRUCT  (*Axis configuration*)
		BaseType : MpAxisBaseTypeEnum := mpAXIS_PERIODIC_ROTARY; (*Defines whether the axis is linear or rotary. Also defines whether the axis is periodic*)
		MeasurementUnit : MpAxisMeasurementUnitEnum := mpAXIS_UNIT_DEGREES; (*Defines the unit of measurement*)
		MeasurementResolution : LREAL := 0.01; (*Minimum distance that can be used for a movement. It is designed to be configured as result from 1e(-X) where X is the exponent and represents the minimum digit (1.0, 0.1, 0.01, 0.001...)*)
		SoftwareLimitPositions : MpAxisSoftwareLimitType; (*Software position limit values*)
		PeriodSettings : MpAxisPeriodType; (*Period definition*)
		MovementLimits : MpAxisMovementLimitsType; (*Limits configuration*)
		CyclicReadChannels : MpAxisCyclicReadChannelsType; (*Channel for cyclic read a custom parameter*)
	END_STRUCT;
	MpAxisCyclicReadChannelsType : 	STRUCT 
		UserChannelParameterID : UINT := 214; (*ParID of drive that should be cyclically read (Default 214: CTRL Current controller: Actual stator current quadrature component)*)
	END_STRUCT;
	MpAxisSoftwareLimitType : 	STRUCT  (*Software position limits*)
		LowerLimit : LREAL := -8388608.0; (*Software limit value in the negative direction [units]*)
		UpperLimit : LREAL := 8388607.0; (*Software limit value in the positive direction [units]*)
	END_STRUCT;
	MpAxisPeriodType : 	STRUCT  (*Period definition*)
		Period : LREAL := 360.0; (*Motor period [units]*)
	END_STRUCT;
	MpAxisMovementLimitsType : 	STRUCT  (*MovementLimits configuration*)
		VelocityPositive : REAL := 1000.0; (*Maximum velocity for discrete movements in the positive direction [units/s]*)
		VelocityNegative : REAL := 1000.0; (*Maximum velocity for discrete movements in the negative direction [units/s]*)
		Acceleration : REAL := 5000.0; (*Maximum acceleration for discrete movements [units/s]²*)
		Deceleration : REAL := 5000.0; (*Maximum deceleration for discrete movements [units/s]²*)
		JerkTime : REAL := 0.0; (*Limit for acceleration slope [s]*)
		PositionErrorStopLimit : LREAL := 2.0; (*Maximum lag error [units]*)
		VelocityErrorStopLimit : REAL := 0.0; (*Maximum velocity [units/s]*)
		VelocityErrorStopLimitMode : MpAxisVelocityLimitModeEnum := mpAXIS_VEL_MODE_OFF; (*Velocity limit mode*)
	END_STRUCT;
	MpAxisBasicConfigDriveType : 	STRUCT  (*Drive configuration*)
		Gearbox : MpAxisGearboxType; (*Scaling configuration*)
		Transformation : MpAxisTransformationType; (*Transformation configuration for rotary and linear axes*)
		Controller : MpAxisControllerType; (*Tuning configuration*)
		StopReaction : MpAxisStopReactionType; (*Stop configuration*)
		DigitalInputs : MpAxisDigitalIOType; (*Configuration of digital inputs*)
	END_STRUCT;
	MpAxisGearboxType : 	STRUCT  (*Scaling configuration*)
		Input : UDINT := 1; (*Input ratio*)
		Output : UDINT := 1; (*Output ratio*)
		Direction : MpAxisMotorDirectionEnum := mpAXIS_DIR_CLOCKWISE; (*Direction of rotation of the motor*)
		MaximumTorque : REAL; (*Maximum torque allowed*)
	END_STRUCT;
	MpAxisTransformationType : 	STRUCT  (*Transformation configuration*)
		ReferenceDistance : LREAL := 360.0; (*Linear axis: Defines the distance moved by the linear axis while the output after the gearbox (on the load side) moves one rotation [units]
Rotary axis: Defines the physical units in relation to one rotation of the gearbox output [units]*)
	END_STRUCT;
	MpAxisControllerType : 	STRUCT  (*Controller configuration*)
		Mode : MpAxisControllerModeEnum := mpAXIS_CTRL_MODE_POSITION; (*Controller mode*)
		Position : MpAxisControllerPositionType; (*Control parameters for the position controller*)
		Speed : MpAxisControllerSpeedType; (*Control parameters for the speed controller*)
		FeedForward : MpAxisControllerFeedForwardType; (*Control parameters for the feed-forward*)
		VoltageFrequency : MpAxisControllerVoltageFreqType; (*Control parameters for the voltage frequency*)
		LoopFilters : ARRAY[0..2]OF MpAxisControllerLoopFiltersType; (*Loop filters*)
	END_STRUCT;
	MpAxisControllerPositionType : 	STRUCT  (*Controller for position loop*)
		ProportionalGain : REAL := 50.0; (*Gain factor [1/s]*)
		IntegralTime : REAL := 0.0; (*Integral time [s]*)
		PredictionTime : REAL := 0.0004; (*Prediction time [s]*)
		TotalDelayTime : REAL := 0.0004; (*Total delay time [s]*)
	END_STRUCT;
	MpAxisControllerSpeedType : 	STRUCT  (*Controller for speed loop*)
		ProportionalGain : REAL := 2.0; (*Gain factor [Asec]*)
		IntegralTime : REAL := 0.0; (*Integral time [s]*)
		FilterTime : REAL := 0.0; (*Filter time constant [s]*)
	END_STRUCT;
	MpAxisControllerFeedForwardType : 	STRUCT  (*Controller for feed forward*)
		TorqueLoad : REAL := 0.0; (*Load torque [Nm]*)
		TorquePositive : REAL := 0.0; (*Torque in positive direction [Nm]*)
		TorqueNegative : REAL := 0.0; (*Torque in negative direction [Nm]*)
		SpeedTorqueFactor : REAL := 0.0; (*Speed/torque factor [Nms]*)
		Inertia : REAL := 0.0; (*Mass moment of inertia [kgm²]*)
		AccelerationFilterTime : REAL := 0.0; (*Acceleration filter time constant [sec]*)
	END_STRUCT;
	MpAxisControllerVoltageFreqType : 	STRUCT  (*Controller for voltage frequency*)
		Type : MpAxisControllerUFTypeEnum := mpAXIS_CTRL_UF_LINEAR; (*Type of characteristic curve*)
		AutoConfig : MpAxisControllerUFAutoConfigEnum := mpAXIS_UF_CONFIG_OFF; (*Automatic configuration*)
		BoostVoltage : REAL; (*Gain voltage [V]*)
		RatedVoltage : REAL; (*Rated voltage [V]*)
		RatedFrequency : REAL; (*Rated frequency [cps]*)
		SlipCompensation : REAL; (*Slip compensation factor*)
	END_STRUCT;
	MpAxisControllerLoopFiltersType : 	STRUCT 
		FilterType : MpAxisControllerFilterTypeEnum := mpAXIS_LOOP_FILTER_NO_TRANSFERED; (*Filter type*)
		LowPass : MpAxisLoopFilterLowPassType; (*Low pass*)
		Notch : MpAxisLoopFilterNotchType; (*Notch*)
		ZTransferFunction : MpAxisLoopFilterZTransferFunType; (*Z Tranfer function*)
		Compensation : MpAxisLoopFilterCompensationType; (*Compensation*)
		Biquadratic : MpAxisLoopFilterBiquadraticType; (*Biquadratic*)
		Limiter : MpAxisLoopFilterLimiterType; (*Filter limiter*)
		LimiterLinear : MpAxisLoopFilterLimiterLinType; (*Filter limited*)
		LimiterRiseTime : MpAxisLoopFilterLimiterRTimeType; (*Limiter Rise Time*)
	END_STRUCT;
	MpAxisLoopFilterLowPassType : 	STRUCT 
		CutOffFrequency : REAL; (*Cut off frequency*)
	END_STRUCT;
	MpAxisLoopFilterNotchType : 	STRUCT 
		CenterFrequency : REAL; (*Center frequency*)
		Bandwidth : REAL; (*Bandwidth*)
	END_STRUCT;
	MpAxisLoopFilterZTransferFunType : 	STRUCT 
		A0 : REAL; (*Coefficient a0 of denominator polynomial*)
		A1 : REAL; (*Coefficient a1 of denominator polynomial*)
		B0 : REAL; (*Coefficient b0 of numerator polynominal*)
		B1 : REAL; (*Coefficient b1 of numerator polynomial*)
		B2 : REAL; (*Coefficient b2 of numerator polynomial*)
	END_STRUCT;
	MpAxisLoopFilterCompensationType : 	STRUCT 
		MultiplicationFactorParID : UINT; (*Multiplication factor ParID*)
		AdditiveValueParID : UINT; (*Additive value ParID*)
	END_STRUCT;
	MpAxisLoopFilterBiquadraticType : 	STRUCT  (*Frequency numerator*)
		FrequencyNumerator : REAL; (*Frequency numerator*)
		DampingNumerator : REAL; (*Damping numerator*)
		FrequencyDenominator : REAL; (*Frequency denominator*)
		DampingDenominator : REAL; (*Damping denominator*)
	END_STRUCT;
	MpAxisLoopFilterLimiterType : 	STRUCT 
		PositiveLimit : REAL; (*Fixed value for the positive limit*)
		NegativeLimit : REAL; (*Fixed value for the negative limit*)
		PositiveLimitParID : UINT; (*ParID the positive limit value is used from*)
		NegativeLimitParID : UINT; (*ParID the negative limit value is used from*)
	END_STRUCT;
	MpAxisLoopFilterLimiterLinType : 	STRUCT 
		InputParID : UINT; (*ACOPOS ParID for the input*)
		InputLimit : REAL; (*Input limit value for full limitation*)
		Gradient : REAL; (*Gradient*)
	END_STRUCT;
	MpAxisLoopFilterLimiterRTimeType : 	STRUCT 
		RiseTime : REAL; (*Rise time*)
		NormalizedLimit : REAL; (*Normalized limit*)
	END_STRUCT;
	MpAxisStopReactionType : 	STRUCT  (*Stop configuration*)
		Quickstop : MpAxisQuickStopEnum; (*Deceleration ramp after a quick stop has been enabled*)
		DriveError : MpAxisErrorStopEnum; (*Deceleration ramp after an axis error occurs*)
	END_STRUCT;
	MpAxisDigitalIOType : 	STRUCT  (*Digital inputs configuration*)
		Level : MpAxisDigitalIOLevelType; (*Level configuration*)
		Quickstop : MpAxisInputSourceEnum := mpAXIS_INPUT_NONE; (*Defines which input works as quickstop*)
	END_STRUCT;
	MpAxisDigitalIOLevelType : 	STRUCT  (*Input level configuration*)
		HomingSwitch : MpAxisLevelIOEnum := mpAXIS_IO_ACTIVE_HI; (*Reference switch*)
		PositiveLimitSwitch : MpAxisLevelIOEnum := mpAXIS_IO_ACTIVE_HI; (*Positive limit switch*)
		NegativeLimitSwitch : MpAxisLevelIOEnum := mpAXIS_IO_ACTIVE_HI; (*Negative limit switch*)
		Trigger1 : MpAxisLevelIOEnum := mpAXIS_IO_ACTIVE_HI; (*Trigger 1*)
		Trigger2 : MpAxisLevelIOEnum := mpAXIS_IO_ACTIVE_HI; (*Trigger 2 *)
	END_STRUCT;
	MpAxisInfoType : 	STRUCT  (*Additional info about the axis config*)
		Diag : MpAxisDiagType; (*Diagnostic structure about errors*)
	END_STRUCT;
	MpAxisBaseTypeEnum : 
		( (*System type options list*)
		mpAXIS_LIMITED_LINEAR := 0, (*The system is linear with active software limit positions*)
		mpAXIS_LIMITED_ROTARY := 1, (*The system is rotary with active software limit positions*)
		mpAXIS_PERIODIC_LINEAR := 2, (*The system is linear without active software limit positions but with a defined period*)
		mpAXIS_PERIODIC_ROTARY := 3, (*The system is rotary without active software limit positions but with a defined period*)
		mpAXIS_LINEAR := 4, (*The system is linear without active software limit positions and without period*)
		mpAXIS_ROTARY := 5 (*The system is rotary without active software limit positions and without period*)
		);
	MpAxisMeasurementUnitEnum : 
		( (*Units type options list*)
		mpAXIS_UNIT_DEGREES := 0, (*Degrees as the unit of measurement*)
		mpAXIS_UNIT_MM := 1, (*Millimeters as the unit of measurement*)
		mpAXIS_UNIT_GENERIC := 2, (*User-defined unit of measurement*)
		mpAXIS_UNIT_GENERIC_NOT_SCALED := 3 (*User-defined unit of measurement. Changing the MeasurementResolution, the system doesn't perform automatic scaling of configuration*)
		);
	MpAxisVelocityLimitModeEnum : 
		( (*Velocity limit mode options list*)
		mpAXIS_VEL_MODE_OFF := 0, (*Velocity error monitoring switched off*)
		mpAXIS_VEL_MODE_STOP_INIT := 1, (*Velocity error monitoring configured to "PeakVelocity"*)
		mpAXIS_VEL_MODE_STOP_AUTO1 := 2, (*Velocity error monitoring calculated with algorithm 1 *)
		mpAXIS_VEL_MODE_STOP_AUTO2 := 3 (*Velocity error monitoring calculated with algorithm 2*)
		);
	MpAxisControllerModeEnum : 
		( (*Controller mode options list*)
		mpAXIS_CTRL_MODE_POSITION := 1, (*Closed-loop control configured for position controller*)
		mpAXIS_CTRL_MODE_POSITION_FF := 33, (*Closed-loop control configured for feed-forward*)
		mpAXIS_CTRL_MODE_UF := 7 (*Closed-loop control configured for frequency inverter*)
		);
	MpAxisControllerUFTypeEnum : 
		( (*Voltage frequency type of characteristic curve*)
		mpAXIS_CTRL_UF_LINEAR := 1, (*Linear*)
		mpAXIS_CTRL_UF_QUADRATIC := 2, (*Quadratic*)
		mpAXIS_CTRL_UF_LINEAR2 := 3 (*Linear type 2*)
		);
	MpAxisControllerUFAutoConfigEnum : 
		( (*Automatic configuration*)
		mpAXIS_UF_CONFIG_OFF := 0, (*Automatic configuration disabled*)
		mpAXIS_UF_CONFIG_MOT_PAR := 1 (*Automatic configuration using the motor parameters*)
		);
	MpAxisControllerFilterTypeEnum : 
		(
		mpAXIS_LOOP_FILTER_NO_TRANSFERED := 0,
		mpAXIS_LOOP_FILTER_OFF := 1,
		mpAXIS_LOOP_FILTER_LOW_PASS := 2,
		mpAXIS_LOOP_FILTER_NOTCH := 3,
		mpAXIS_LOOP_FILTER_ZTRANSFER_FUN := 4,
		mpAXIS_LOOP_FILTER_COMPENSATION := 5,
		mpAXIS_LOOP_FILTER_BIQUADRATIC := 6,
		mpAXIS_LOOP_FILTER_LIMITER := 7,
		mpAXIS_LOOP_FILTER_LIMITER_LIN := 8,
		mpAXIS_LOOP_FILTER_LIMITER_RTIME := 9
		);
	MpAxisLevelIOEnum : 
		( (*Digital inputs configuration options list*)
		mpAXIS_IO_ACTIVE_LO := 0, (*Input configured as active low*)
		mpAXIS_IO_ACTIVE_HI := 1, (*Input configured as active high*)
		mpAXIS_IO_ACTIVE_LO_EXTERNAL := 288, (*Input configured as active low, forced externally*)
		mpAXIS_IO_ACTIVE_HI_EXTERNAL := 289 (*Input configured as active high, forced externally*)
		);
	MpAxisQuickStopEnum : 
		( (*Quick stop options list*)
		mpAXIS_QUICK_STOP_DEC_LIMIT := 20, (*Quick stop with the deceleration value defined in the axis limits*)
		mpAXIS_QUICK_STOP_TORQUE_LIMIT := 30, (*Quick stop using the torque limit*)
		mpAXIS_QUICK_STOP_INDUCTION := 40 (*Induction quick stop*)
		);
	MpAxisErrorStopEnum : 
		( (*Error stop options list*)
		mpAXIS_ERROR_STOP_DEC_LIMIT := 20, (*Stops with the deceleration value defined in the axis limits*)
		mpAXIS_ERROR_STOP_INDUCTION := 40, (*Induction stop*)
		mpAXIS_ERROR_STOP_CONTROL_OFF := 50 (*Immediate cutoff of power supply (drive no longer has electric torque)*)
		);
	MpAxisMotorDirectionEnum : 
		( (*Motor direction options list*)
		mpAXIS_DIR_CLOCKWISE := 0, (*Motor rotates clockwise*)
		mpAXIS_DIR_COUNTERCLOCKWISE := 255 (*Motor rotates counterclockwise*)
		);
	MpAxisPosVelOutputTypeEnum : 
		( (*Motor direction options list*)
		mpAXIS_OUTPUT_SET := 0, (*The value provided by Position or Velocity output is the set profile generated*)
		mpAXIS_OUTPUT_ACTUAL := 1 (*The value provided by Position or Velocity output is the real motor feedback*)
		);
	MpAxisCouplingParType : 	STRUCT  (*Standard coupling parameters structure*)
		RatioNumerator : REAL := 360.0; (*Numerator*)
		RatioDenominator : REAL := 360.0; (*Denominator*)
		MasterParID : UINT := 0; (*ParID that can be used in place of a master axis*)
		Gear : MpAxisGearType; (*Parameters for linear movements (Gear)*)
		Cam : MpAxisCamType; (*Parameters for nonlinear movements / cams (Cam)*)
		Recovery : MpAxisRecoveryType; (*Parameters in the event the "Recovery" command is issued*)
		OffsetShift : MpAxisOffsetType; (*Parameters for a shift based on the slave position*)
		PhaseShift : MpAxisPhasingType; (*Parameters for a shift based on the master position being used by the slave*)
	END_STRUCT;
	MpAxisCamType : 	STRUCT  (*Cam coupling specific parameters*)
		CamTableID : USINT := 0; (*ID of the cam that should be used (array index)*)
		MasterStartPosition : LREAL := 0.0; (*Offset for starting the cam profile [master units]*)
		LeadIn : MpAxisCamLeadType; (*Defines the starting behavior a the cam profile*)
		LeadOut : MpAxisCamLeadType; (*Defines the stopping behavior a the cam profile*)
		CamTable : ARRAY[0..4]OF STRING[12]; (*Array with the cam profile names*)
	END_STRUCT;
	MpAxisCamLeadType : 	STRUCT 
		MasterOffset : LREAL := 0.0; (*Offset of the master axis [master units]*)
		MasterDistance : LREAL := 0.0; (*Distance between the cam profile at which the cam is started or stopping begins [slave units]*)
		SlaveDistance : LREAL := 0.0; (*Distance covered by the slave during starting/stopping [slave units]*)
		CamEnable : BOOL := FALSE; (*Enables the usage of a predefined cam profile*)
		CamTableID : USINT := 0; (*ID of the cam profile in the array ("CamTable")*)
		MasterScaling : LREAL := 1.0; (*Scaling factor for the cam profile [master units]*)
		SlaveScaling : LREAL := 0.0; (*Scaling factor for the cam profile [slave units]*)
	END_STRUCT;
	MpAxisGearType : 	STRUCT  (*Gear coupling specific parameters*)
		Acceleration : REAL := 1000.0; (*Acceleration when coupling during runtime [units/s²]*)
		Deceleration : REAL := 5000.0; (*Deceleration when decoupling during runtime [units/s²]*)
	END_STRUCT;
	MpAxisOffsetType : 	STRUCT  (*Performs an offset shift of the slave axis*)
		Mode : MpAxisShiftModeEnum := mpAXIS_SHIFT_MODE_ABS; (*Defines how the "Shift" input should be used*)
		Distance : LREAL := 0.0; (*Offset shift [slave units]*)
		Velocity : REAL := 1000.0; (*Velocity for achieving this shift [slave units/s]*)
		Acceleration : REAL := 5000.0; (*Acceleration for achieving this shift [slave units/s²]*)
		ApplicationMode : MpAxisApplyModeEnum := mpAXIS_SHIFT_TIME_BASE; (*Motion profile based on the mode selected here*)
		EnableVelocityControl : BOOL := FALSE; (*Only relevant for mapAXIS_SHIFT_VEL_CTRL. Applies the shift when starting a synchronous movement*)
		ApplicationDistance : LREAL := 0.0; (*Only relevant for mapAXIS_SHIFT_MSTR_DIST_BASE. Distance to which the shift is applied [master units]*)
		CyclicParID : UINT := 0; (*ParID from which the offset shift is read*)
		WithinZone : MpAxisOffsetInZoneType; (*Configures the offset in a defined zone*)
	END_STRUCT;
	MpAxisOffsetInZoneType : 	STRUCT  (*Offset within zone option configuration*)
		Enable : BOOL := FALSE; (*Enables an offset zone*)
		ZoneStartPosition : LREAL := 0.0; (*Position for the start of the zone [units]*)
		ZoneEndPosition : LREAL := 0.0; (*Position for the end of the zone [units]*)
		Period : LREAL := 0.0; (*Period for defining a zone [units]*)
		ProfileBasis : MpAxisProfileBasisEnum := mpAXIS_PROFILE_BASIS_SLAVE; (*Configures how the offset is applied (master or slave)*)
	END_STRUCT;
	MpAxisRecoveryType : 	STRUCT  (*Recovery procedure configuration*)
		Mode : MpAxisRecoveryModeEnum := mpAXIS_RECOVERY_FORWARD; (*Different modes for recovering the normal state*)
		Velocity : REAL := 1000.0; (*Velocity during recovery [units/s]*)
		Acceleration : REAL := 5000.0; (*Acceleration during recovery [units/s²]*)
		ToleranceWindow : LREAL := 50.0; (*Tolerance window, used by several modes*)
		PhaseShift : LREAL := 0; (*Phase shift master side: at the end of recovery is the master position value corresponding to the first position of cam profile*)
		OffsetShift : LREAL := 0; (*Offset shift slave side: considering the slave position out of cam porfile, the slave position following master is shifted by this value*)
	END_STRUCT;
	MpAxisPhasingType : 	STRUCT  (*Performs a phase shift in reference to the master axis*)
		Mode : MpAxisShiftModeEnum := mpAXIS_SHIFT_MODE_ABS; (*Defines how the "Shift" input should be used*)
		Distance : LREAL := 0.0; (*Offset shift [slave units]*)
		Velocity : REAL := 1000.0; (*Velocity for achieving this shift [slave units/s]*)
		Acceleration : REAL := 5000.0; (*Acceleration for achieving this shift [slave units/s²]*)
		ApplicationMode : MpAxisApplyModeEnum := mpAXIS_SHIFT_TIME_BASE; (*Motion profile based on the mode selected here*)
		EnableVelocityControl : BOOL := FALSE; (*Only relevant for mapAXIS_SHIFT_VEL_CTRL. Applies the shift when starting a synchronous movement*)
		ApplicationDistance : LREAL := 0.0; (*Only relevant for mapAXIS_SHIFT_MSTR_DIST_BASE. Distance to which the shift is applied [master units]*)
		CyclicParID : UINT := 0; (*ParID from which the offset shift is read*)
	END_STRUCT;
	MpAxisCouplingInfoType : 	STRUCT  (*Additional info about the axis*)
		MasterReady : BOOL; (*The axis has been completely initialized at least once*)
		SlaveReady : BOOL; (*The axis has been completely initialized at least once*)
		SlavePosition : LREAL; (*Current slave position [units]*)
		SlaveVelocity : REAL; (*Current slave velocity [units]*)
		ActualOffsetValue : LREAL; (*Current shift of the axis [slave units]*)
		ActualPhasingValue : LREAL; (*Current shift of the axis [master units]*)
		Diag : MpAxisDiagExtType; (*Diagnostic structure for the status ID*)
		RecoveryPosition : LREAL; (*Target position for recovery the slave. It is shown with all recovery mode types*)
	END_STRUCT;
	MpAxisShiftModeEnum : 
		( (*Shift mode options list*)
		mpAXIS_SHIFT_MODE_ABS := 0, (*The value on the "Shift" input is interpreted as an absolute value*)
		mpAXIS_SHIFT_MODE_REL := 1, (*The value on the "Shift" input is interpreted as a relative value*)
		mpAXIS_SHIFT_MODE_ABS_NO_RESET := 2, (*Same as mpAXIS_SHIFT_MODE_ABS, but if the axis leaves the Synchronized Motion state, the shift is not reset to 0*)
		mpAXIS_SHIFT_MODE_REL_NO_RESET := 3 (*Same as mpAXIS_SHIFT_MODE_REL, but if the axis leaves the Synchronized Motion state, the shift is not reset to 0*)
		);
	MpAxisApplyModeEnum : 
		( (*Appllicatrion mode options list*)
		mpAXIS_SHIFT_TIME_BASE := 1, (*Calculates a profile using the "Velocity" and "Acceleration" inputs. The duration of the shift is independent of the slave's velocity*)
		mpAXIS_SHIFT_MSTR_POS_BASE := 2, (*Calculates a profile using the "Velocity" and "Acceleration" inputs as well as the velocity of the slave when starting the offset shift*)
		mpAXIS_SHIFT_MSTR_DIST_BASE := 3, (*Calculates a profile using the "ApplicationDistance" input based on the master's position*)
		mpAXIS_SHIFT_VEL_CTRL := 4, (*In this mode, the shift is executed with the velocity on the "Velocity" input as long as the "PerformVelocityControl" input is set to 1*)
		mpAXIS_OFFS_TIME_MSTR := 257, (*Calculates a profile using the "Velocity" and "Acceleration" inputs. The duration of the shift is independent of the slave's velocity*)
		mpAXIS_OFFS_MSTR_POS_BASE_MSTR := 258, (*Calculates a profile using the "Velocity" and "Acceleration" inputs as well as the velocity of the slave when starting the offset shift*)
		mpAXIS_OFFS_MSTR_DIS_BASE_MSTR := 259, (*Calculates a profile using the "ApplicationDistance" input based on the master's position*)
		mpAXIS_OFFS_VEL_CTRL_MSTR := 260 (*In this mode, the shift is executed with the velocity on the "Velocity" input as long as the "PerformVelocityControl" input is set TRUE*)
		);
	MpAxisProfileBasisEnum : 
		( (*Options list for how the profile is based*)
		mpAXIS_PROFILE_BASIS_SLAVE := 0, (*The profile for the shift is based on the position of the slave axis*)
		mpAXIS_PROFILE_BASIS_MASTER := 256 (*The profile for the shift is based on the position of the master axis*)
		);
	MpAxisRecoveryModeEnum : 
		( (*Recovery mode options list*)
		mpAXIS_RECOVERY_FORWARD := 0, (*The process only moves the slave forward in order to find the correct position again in accordance with the cam*)
		mpAXIS_RECOVERY_BACKWARD := 2, (*The process only moves the slave backward in order to find the correct position again in accordance with the cam*)
		mpAXIS_RECOVERY_SHORTEST_WAY := 3, (*The process moves the slave to the correct position using the shortest path in accordance with the cam*)
		mpAXIS_RECOVERY_FORWARD_WINDOW := 100, (*The process moves the slave to the correct position using the shortest path in accordance with the cam in a defined window; otherwise only forward*)
		mpAXIS_RECOVERY_BACKWARD_WINDOW := 101, (*The process moves the slave to the correct position using the shortest path in accordance with the cam in a defined window; otherwise only backward*)
		mpAXIS_RECOVERY_GET_POSITION := 102 (*The process only calculate the target position (shown inside Info structure) according with setup but it doesn't perform any movement. The movement could be launched by MoveAbsolute or different recovery mode*)
		);
	MpAxisTorqueModeEnum : 
		( (*Torque mode options list*)
		mpAXIS_TORQUE_MODE_FF := 32, (*Feed-forward control (standard)*)
		mpAXIS_TORQUE_MODE_LIMIT := 40, (*Torque limiter (standard)*)
		mpAXIS_TORQUE_MODE_RAMPED_CTRL := 48 (*Ramped torque control*)
		);
	MpAxisCyclicSetParType : 	STRUCT  (*Cyclic Ref parameters structure*)
		Acceleration : REAL := 100.0; (*Maximum acceleration [units/s²]*)
		Deceleration : REAL := 100.0; (*Maximum deceleration [units/s²]*)
		PositionModeMaxVelocity : REAL := 500.0; (*Maximum velocity [units/s]*)
		VelocityModeDirection : MpAxisMoveDirectionEnum := mpAXIS_DIR_POSITIVE; (*Direction of movement*)
		PositionParID : UINT; (*ParID from which the cyclic position is read*)
		VelocityParID : UINT; (*ParID from which the cyclic velocity is read*)
		TorqueSetup : MpAxisTorqueSetupType; (*Configuration structure for cyclic torque*)
	END_STRUCT;
	MpAxisTorqueSetupType : 	STRUCT  (*Torque mode configuration structure*)
		Mode : MpAxisTorqueModeEnum := mpAXIS_TORQUE_MODE_FF; (*Specifies how the "CyclicTorque" input is used*)
		SctrlKv : REAL := 5.0; (*Proportional gain of the speed controller while cyclic torque control is active. This value is reset when disabled*)
		SctrlTn : REAL := 0.1; (*Integral time of the speed controller while cyclic torque control is active. This value is reset when disabled [s]*)
		RampedControl : MpAxisTorqueRampedControlType; (*Ramped torque control parameters*)
	END_STRUCT;
	MpAxisCyclicSetInfoType : 	STRUCT  (*Additional info about the axis*)
		AxisReady : BOOL; (*The axis has been completely initialized at least once.*)
		PositionReceivedParID : UINT; (*ParID from which the position for the axis is taken (MAX_CYCLIC_POS)*)
		VelocityReceivedParID : UINT; (*ParID from which the velocity for the axis is taken (MAX_CYCLIC_POS)*)
		SlavePosition : LREAL; (*Position of the slave axis [units/s]*)
		SlaveVelocity : REAL; (*Velocity of the slave axis [units/s]*)
		Diag : MpAxisDiagExtType; (*Diagnostic structure for the status ID*)
		TorqueControl : MpAxisTorqueInfoType; (*Torque control information*)
	END_STRUCT;
	MpAxisCamSequencerParType : 	STRUCT  (*Cam sequencer parameters structure*)
		Configuration : MC_AUTDATA_TYP := (MaxMasterVelocity:=1000.0,State:=[15((RepeatCounterInit:=1))]); (*Configuration of CAM states*)
		Deceleration : REAL; (*Deceleration used to stop the slave [units/s² of the slave]*)
		ParLock : USINT; (*Locks parameter changes during runtime*)
		MaxStatePerCycle : USINT := 5; (*"MaxStatesPerCycle" can be used to define the maximum number of automat states change detection should run through per task class cycle*)
		CamTable : ARRAY[0..13]OF STRING[12]; (*Array of cam names*)
		Recovery : MpAxisRecoveryType; (*Parameters in the event the "Recovery" command is issued*)
		OffsetShift : MpAxisOffsetType; (*Parameters for a shift based on the slave position*)
		PhaseShift : MpAxisPhasingType; (*Parameters for a shift based on the master position being used by the slave*)
	END_STRUCT;
	MpAxisCamSequencerInfoType : 	STRUCT  (*Additional info about the axis*)
		MasterReady : BOOL; (*The axis has been completely initialized at least once*)
		SlaveReady : BOOL; (*The axis has been completely initialized at least once*)
		ActiveSignal1 : BOOL; (*Signal 1 active, not yet being used*)
		ActiveSignal2 : BOOL; (*Signal 2 active, not yet being used*)
		ActiveSignal3 : BOOL; (*Signal 3 active, not yet being used*)
		ActiveSignal4 : BOOL; (*Signal 4 active, not yet being used*)
		ActualOffsetValue : REAL; (*Current shift of the axis [slave units]*)
		ActualPhasingValue : REAL; (*Current shift of the axis [master units]*)
		Diag : MpAxisDiagExtType; (*Diagnostic structure for the status ID*)
		RecoveryPosition : LREAL; (*Target position for recovery the slave. It is shown with all recovery mode types*)
	END_STRUCT;
	MpAxisTorqueInfoType : 	STRUCT  (*Torque control information parameters*)
		InTorque : BOOL; (*Setpoint reached*)
		WaitingForStart : BOOL; (*Function initialized, ready for StartParID"*)
		VelocityLimitActive : BOOL; (*Axis velocity limit active*)
	END_STRUCT;
	MpAxisTorqueRampedControlType : 	STRUCT  (*Ramped torque control parameters*)
		TorqueRamp : REAL := 0.0; (*Increase in torque until "Torque" value is reached [Nm/s]*)
		PositiveMaxVelocity : REAL := 0.0; (*Upper velocity limit in the positive direction of rotation or lower velocity limit in the negative direction of rotation [PLCopen units/s]*)
		NegativeMaxVelocity : REAL := 0.0; (*Upper velocity limit in the negative direction of rotation or lower velocity limit in the positive direction of rotation [PLCopen units/s]*)
		DisableVelocityLimits : BOOL := FALSE; (*If TRUE, the "NegativeMaxVelocity" and "PositiveMaxVelocity" velocity limits are disabled. These parameters can be set to with any value and no longer have any effect.*)
		CompensateVelocityLimits : BOOL := FALSE; (*If TRUE,  the velocity limits on the drive will be set to a calculated factor that is less or greater than specified for the "XxxMaxVelocity" parameters. The result of this configuration is that the configured velocity limits will not be exceeded*)
		EnableTimeLimit : BOOL := FALSE; (*If TRUE, when the axis moves at the limit velocity for a certain amount of time (in seconds), then function will be terminated automatically with an error message*)
		TimeLimit : REAL := 0.0; (*Time limit for how long the axis can move at the velocity or acceleration limit before it is stopped automatically [s]*)
		StartParID : UINT := 0; (*Torque controlled movement starts via ParID when the value changes from 0 to !=0*)
		TorqueParID : UINT := 0; (*Preset value of the torque setpoint from a ParID instead of the PLC via "Torque" [Nm]*)
	END_STRUCT;
END_TYPE
