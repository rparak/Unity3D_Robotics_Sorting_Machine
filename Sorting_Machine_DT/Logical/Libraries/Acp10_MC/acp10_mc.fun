
FUNCTION_BLOCK MC_AbortTrigger (*aborts FBs connected to trigger events*)
	VAR_INPUT
		Axis : UDINT; (*axis reference, defines on which axis the trigger should be aborted*)
		TriggerInput : MC_TRIGGER_REF; (*trigger input signal source*)
		Execute : BOOL; (*aborts the trigger at rising edge*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*FB with trigger has been aborted*)
		Busy : BOOL; (*the function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		state : USINT; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_AutCommand (*transferes commands for the cam automat to the drive*)
	VAR_INPUT
		Slave : UDINT; (*axis reference of the slave axis*)
		Enable : BOOL; (*activates the function block*)
		Start : BOOL; (*starts the cam automat*)
		Stop : BOOL; (*stops the movement on the slave axis*)
		Deceleration : REAL; (*deceleration for the stop command*)
		Restart : BOOL; (*reengages the slave axis to the automat*)
		EndAutomat : BOOL; (*aborts the automat in the background*)
		SetSignal1 : BOOL; (*sets the automat signal1*)
		SetSignal2 : BOOL; (*sets the automat signal2*)
		SetSignal3 : BOOL; (*sets the automat signal3*)
		SetSignal4 : BOOL; (*sets the automat signal4*)
		ResetSignal1 : BOOL; (*resets the automat signal1*)
		ResetSignal2 : BOOL; (*resets the automat signal2*)
		ResetSignal3 : BOOL; (*resets the automat signal3*)
		ResetSignal4 : BOOL; (*resets the automat signal4*)
		TransferParLock : BOOL; (*transfer the par lock parameter*)
		SelectParLock : USINT; (*select the par lock parameter*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*function block is active and waits for command*)
		Busy : BOOL; (*function block is enabled*)
		CommandAborted : BOOL; (*function block was aborted by another function block*)
		Error : BOOL; (*error occurred in the function block*)
		ErrorID : UINT; (*error number*)
		Running : BOOL; (*slave is engaged to the automat*)
		StandBy : BOOL; (*cam automat is active in the background*)
		ParLockTransferred : BOOL; (*par lock parameter transferred*)
		ActualStateIndex : USINT; (*actual state of the cam automat*)
		ActualStateCamIndex : UINT; (*actual cam index of the actual state*)
		InCam : BOOL; (*automat is in cam*)
		InCompensation : BOOL; (*automat is in compensation*)
	END_VAR
	VAR
		C_Slave : UDINT; (*internal variable*)
		IS : MC_0099_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_AutControl (*controls the cam automat functions*)
	VAR_INPUT
		Enable : BOOL; (*enables the functionality of this FB*)
		Slave : UDINT; (*axis reference of the slave axis*)
		ParLock : USINT; (*lock for consistent online change*)
		Signal1 : BOOL; (*set signal1*)
		Signal2 : BOOL; (*set signal2*)
		Signal3 : BOOL; (*set signal3*)
		Signal4 : BOOL; (*set signal4*)
		Start : BOOL; (*start automat*)
		Stop : BOOL; (*stop automat*)
		Deceleration : REAL; (*deceleration for stop command*)
		Restart : BOOL; (*restart command*)
		AdrAutData : UDINT; (*address of optional cam automat data structure*)
		InitAutData : BOOL; (*initialize the parameters of the optional cam automat data structure*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*automat control function block activated*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		AutDataInitialized : BOOL; (*cam automat data structure initialized*)
		Running : BOOL; (*cam automat is running*)
		ActualStateIndex : USINT; (*index of the actual state*)
		ActualCamType : USINT; (*cam type of the actual state*)
	END_VAR
	VAR
		C_Slave : UDINT; (*internal variable*)
		ParLockOld : USINT; (*internal variable*)
		LockID : USINT; (*internal variable*)
		CmdParLock : BOOL; (*internal variable*)
		EdgeSignal1 : BOOL; (*internal variable*)
		EdgeSignal2 : BOOL; (*internal variable*)
		EdgeSignal3 : BOOL; (*internal variable*)
		EdgeSignal4 : BOOL; (*internal variable*)
		EdgeStart : BOOL; (*internal variable*)
		CmdStart : BOOL; (*internal variable*)
		EdgeStop : BOOL; (*internal variable*)
		CmdStop : BOOL; (*internal variable*)
		C_Deceleration : REAL; (*internal variable*)
		EdgeRestart : BOOL; (*internal variable*)
		CmdRestart : BOOL; (*internal variable*)
		EdgeInitAutData : BOOL; (*internal variable*)
		CmdInitAutData : BOOL; (*internal variable*)
		C_AutData : MC_AUTDATA_TYP; (*internal variable*)
		C_Master : UDINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		CC_ErrorID : UINT; (*internal variable*)
		SignalSet : USINT; (*internal variable*)
		SignalReset : USINT; (*internal variable*)
		CmdAutStart : UINT; (*internal variable*)
		AutStatusValid : BOOL; (*internal variable*)
		AutStateDld : USINT; (*internal variable*)
		AutStatusOffset : UINT; (*internal variable*)
		AutStatusRecIndex : USINT; (*internal variable*)
		LockIDSend : USINT; (*internal variable*)
		AutActualStateIndexOffset : UINT; (*internal variable*)
		AutActualStateIndexRecIndex : USINT; (*internal variable*)
		C_Busy : BOOL; (*internal variable*)
		AutActualCamTypeOffset : UINT; (*internal variable*)
		AutActualCamTypeRecIndex : USINT; (*internal variable*)
		LockIDMa : USINT; (*internal variable*)
		sendSlot : USINT; (*internal variable*)
		readSlot : USINT; (*internal variable*)
		state : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		MoveID : USINT; (*internal variable*)
		LockIDReceive : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_AutoCamDwell (*starts a link between master and slave with a self calculated cam profile*)
	VAR_INPUT
		Master : UDINT; (*axis reference of the master axis*)
		Slave : UDINT; (*axis reference of the slave axis*)
		Enable : BOOL; (*function block is activated*)
		InitData : BOOL; (*start transferring the parameters*)
		LeadInMasterDistance : REAL; (*master axis compensation distance for the lead in*)
		LeadInSlaveDistance : REAL; (*slave axis compensation distance for the lead in*)
		LeadOutMasterDistance : REAL; (*master axis compensation distance for the lead out*)
		LeadOutSlaveDistance : REAL; (*slave axis compensation distance for the lead out*)
		MasterStartPosition : REAL; (*master position where the cam profile starts*)
		MasterDwellDistance : REAL; (*master length of the optional dwell section*)
		MasterLength : REAL; (*master side length of the automatically calculated cam profile*)
		SlaveLength : REAL; (*slave side length of the automatically calculated cam profile*)
		MasterParID : UINT; (*use this ParID for the master axis instead of the set position*)
		MasterParIDMaxVelocity : REAL; (*maximum speed of the master ParID value*)
		LeadInSignal : BOOL; (*signal from the control to start the lead in*)
		LeadOutSignal : BOOL; (*signal from the control to start the lead out*)
		LeadInParID : UINT; (*ParID that can be used by the drive to start the lead in*)
		LeadOutParID : UINT; (*ParID that can be used by the drive to start the lead out*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*parameters are transferred and FB is active*)
		Busy : BOOL; (*function block is enabled*)
		CommandAborted : BOOL; (*function block aborted by another FB*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		DataInitialized : BOOL; (*parameters are transferred*)
		InSync : BOOL; (*cam profile is synchronized with the master*)
		InCam : BOOL; (*the coupling is within the cam range*)
		InDwell : BOOL; (*the coupling is within the dwell range*)
	END_VAR
	VAR
		C_Master : UDINT; (*internal variable*)
		C_Slave : UDINT; (*internal variable*)
		EdgeInitData : BOOL; (*internal variable*)
		C_LeadInMasterDistance : DINT; (*internal variable*)
		C_LeadInSlaveDistance : DINT; (*internal variable*)
		C_LeadOutMasterDistance : DINT; (*internal variable*)
		C_LeadOutSlaveDistance : DINT; (*internal variable*)
		C_MasterStartPosition : DINT; (*internal variable*)
		C_MasterDwellDistance : DINT; (*internal variable*)
		C_MasterLength : DINT; (*internal variable*)
		C_SlaveLength : DINT; (*internal variable*)
		C_MasterParID : UINT; (*internal variable*)
		C_MasterParIDMaxVelocity : REAL; (*internal variable*)
		C_LeadInParID : UINT; (*internal variable*)
		C_LeadOutParID : UINT; (*internal variable*)
		EdgeLeadInSignal : BOOL; (*internal variable*)
		EdgeLeadOutSignal : BOOL; (*internal variable*)
		LeadInSignalUsed : BOOL; (*internal variable*)
		LeadOutSignalUsed : BOOL; (*internal variable*)
		C_Active : BOOL; (*internal variable*)
		C_Busy : BOOL; (*internal variable*)
		C_CommandAborted : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		CC_ErrorID : UINT; (*internal variable*)
		C_InSync : BOOL; (*internal variable*)
		C_InCam : BOOL; (*internal variable*)
		C_InDwell : BOOL; (*internal variable*)
		RunningMasterDwellDistance : DINT; (*internal variable*)
		ArithIndex : UINT; (*internal variable*)
		CmpIndex : UINT; (*internal variable*)
		MuxIndex : UINT; (*internal variable*)
		EvWrIndex : UINT; (*internal variable*)
		VarIndex : UINT; (*internal variable*)
		LogicIndex : UINT; (*internal variable*)
		AutStatusValid : BOOL; (*internal variable*)
		AutActualStateIndexOffset : UINT; (*internal variable*)
		AutActualStateIndexRecIndex : USINT; (*internal variable*)
		LockIDMa : USINT; (*internal variable*)
		sendSlot : USINT; (*internal variable*)
		readSlot : USINT; (*internal variable*)
		state : USINT; (*internal variable*)
		LockID : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		LockIDSend : USINT; (*internal variable*)
		MoveID : USINT; (*internal variable*)
		LockIDReceive : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_AxisErrorCollector (*collects information if a FB or axis error occured and if an axis is in state Errorstop*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*function block is activated*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*if set, the data of the other outputs is valid*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		FunctionBlockError : BOOL; (*at least one function block reported an error*)
		AxisError : BOOL; (*at least one axis error was reported*)
		AxisWarning : BOOL; (*at least one axis warning was reported*)
		Errorstop : BOOL; (*the axis is in state Errorstop*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0104_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_BrakeControl (*executes several commands for holding brake*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*execute brake command at rising edge*)
		Command : USINT; (*brake command*)
		Configuration : MC_BRAKE_CONFIG_REF; (*brake configuration*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*brake command done*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occured in FB*)
		ErrorID : UINT; (*error number*)
		PositionError : REAL; (*position error of holding brake test*)
		BrakeStatus : BOOL; (*actual brake status*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0110_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_BrakeOperation (*opens and closes the holding brake when the controller is off*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*execute brake command at rising edge*)
		BrakeCommand : USINT; (*brake command, open or close*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*brake command done*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_BrakeCommand : USINT; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CalcCamFromPoints (*calculates a cam profile from a list of points*)
	VAR_INPUT
		Execute : BOOL; (*calculation starts at rising edge*)
		MasterPointsAddress : UDINT; (*data address of the master points list*)
		SlavePointsAddress : UDINT; (*data address of the slave points list*)
		NumberOfPoints : UINT; (*number of master and slave points*)
		CamProfileAddress : UDINT; (*data address for the calculated cam profile*)
		Configuration : MC_CALC_CAM_CONFIG_REF; (*optional additional configuration*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*calculation is complete*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		IS : MC_0093_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CalcCamFromSections (*calculates from a list of points a cam profile*)
	VAR_INPUT
		Execute : BOOL; (*calculation starts at rising edge*)
		DataAddress : UDINT; (*data address of the input data with the list of points*)
		CamProfileAddress : UDINT; (*data address for the calculated cam profile*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*calculation is complete*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		ErrorInSection : UINT; (*index of section with error*)
	END_VAR
	VAR
		C_ErrorID : UINT; (*internal variable*)
		C_ErrorInSection : UINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CalcPointsFromCam (*calculates a list of points from a cam profile*)
	VAR_INPUT
		Execute : BOOL; (*calculation starts at rising edge*)
		DataObjectName : STRING[12]; (*name of the cam table*)
		MasterPointsAddress : UDINT; (*data address of the master points list*)
		SlavePointsAddress : UDINT; (*data address of the slave points list*)
		NumberOfPoints : UINT; (*number of master and slave points*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*calculation is complete*)
		Busy : BOOL; (*function block is not finished *)
		Error : BOOL; (*error occured in FB*)
		ErrorID : UINT; (*error number*)
		AdditionalInfo : MC_CALC_CAM_CONFIG_REF; (*additional information about the cam profile*)
	END_VAR
	VAR
		IS : MC_0123_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CalcSectionsFromCam (*calculates the sections from a cam profile *)
	VAR_INPUT
		Execute : BOOL; (*calculation starts at rising edge*)
		DataObjectName : STRING[12]; (*name of the cam table*)
		DataAddress : UDINT; (*address of the variable for the sections*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*calculation is complete*)
		Busy : BOOL; (*function block is not finished *)
		Error : BOOL; (*error occured in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		IS : MC_0122_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CamIn (*starts a cam profile link between the master and the slave axis*)
	VAR_INPUT
		Master : UDINT; (*axis reference of the master axis*)
		Slave : UDINT; (*axis reference of the slave axis*)
		Enable : BOOL; (*function block is activated*)
		InitData : BOOL; (*starts transferring the parameters*)
		CamTableID : USINT; (*ID number of the cam profile*)
		MasterStartPosition : REAL; (*master position where the cam profile starts*)
		MasterScaling : DINT; (*factor of the master profile*)
		SlaveScaling : DINT; (*factor of the slave scaling*)
		EnterCam : BOOL; (*signal from the control to start the coupling*)
		ExitCam : BOOL; (*signal from the control to end the coupling*)
		Restart : BOOL; (*signal from the control to restart the coupling*)
        AdvancedParameters: MC_ADVANCED_CAM_PAR_REF; (*additional inputs for advanced usage of FB*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*parameters are transferred and FB is active*)
		Busy : BOOL; (*function block is enabled*)
		CommandAborted : BOOL; (*function block aborted by another FB*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		DataInitialized : BOOL; (*transferring parameters is completed*)
		Running : BOOL; (*cam coupling is running*)
		StandBy : BOOL; (*cam coupling is active in the background*)
		InLeadIn : BOOL; (*the coupling is within the leadin range*)
		InCam : BOOL; (*the coupling is within the cam range*)
		InLeadOut : BOOL; (*the coupling is within the leadout range*)
		EndOfProfile : BOOL; (*pulsed output signaling the cyclic end of the cam profile*)
	END_VAR
	VAR
		C_Master : UDINT; (*internal variable*)
		C_Slave : UDINT; (*internal variable*)
		IS: MC_0146_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CamDwell (*starts a cam profile link between the master and the slave axis*)
	VAR_INPUT
		Master : UDINT; (*axis reference of the master axis*)
		Slave : UDINT; (*axis reference of the slave axis*)
		Enable : BOOL; (*function block is activated*)
		InitData : BOOL; (*starts transferring the parameters*)
		LeadInMasterDistance : REAL; (*master axis compensation distance for the lead in*)
		LeadInSlaveDistance : REAL; (*slave axis compensation distance for the lead in*)
		LeadInMasterOffset : REAL; (*master side offset within the cam profile*)
		LeadOutMasterDistance : REAL; (*master axis compensation distance for the lead out*)
		LeadOutSlaveDistance : REAL; (*slave axis compensation distance for the lead out*)
		LeadOutMasterOffset : REAL; (*master side offset within the cam profile*)
		MasterStartPosition : REAL; (*master position where the cam profile starts*)
		MasterDwellDistance : REAL; (*master length of the optional dwell section*)
		MasterScaling : REAL; (*factor of the master profile*)
		SlaveScaling : REAL; (*factor of the slave scaling*)
		CamTableID : USINT; (*ID number of the cam profile*)
		MasterParID : UINT; (*use this ParID for the master axis instead of the set position*)
		MasterParIDMaxVelocity : REAL; (*maximum speed of the master ParID value*)
		LeadInSignal : BOOL; (*signal from the control to start the lead in*)
		LeadOutSignal : BOOL; (*signal from the control to start the lead out*)
		LeadInParID : UINT; (*ParID that can be used by the drive to start the lead out movement*)
		LeadOutParID : UINT; (*ParID that can be used by the drive to start the lead out movement*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*parameters are transferred and FB is active*)
		Busy : BOOL; (*function block is enabled*)
		CommandAborted : BOOL; (*function block aborted by another FB*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		DataInitialized : BOOL; (*transferring parameters is completed*)
		InSync : BOOL; (*cam profile is synchronized with the master*)
		InCam : BOOL; (*the coupling is within the cam range*)
		InDwell : BOOL; (*the coupling is within the dwell range*)
	END_VAR
	VAR
		C_Master : UDINT; (*internal variable*)
		C_Slave : UDINT; (*internal variable*)
		EdgeInitData : BOOL; (*internal variable*)
		C_LeadInMasterDistance : DINT; (*internal variable*)
		C_LeadInSlaveDistance : DINT; (*internal variable*)
		C_LeadInMasterOffset : DINT; (*internal variable*)
		C_LeadOutMasterDistance : DINT; (*internal variable*)
		C_LeadOutSlaveDistance : DINT; (*internal variable*)
		C_LeadOutMasterOffset : DINT; (*internal variable*)
		C_MasterStartPosition : DINT; (*internal variable*)
		C_MasterDwellDistance : DINT; (*internal variable*)
		C_MasterScaling : DINT; (*internal variable*)
		C_SlaveScaling : DINT; (*internal variable*)
		C_CamTableID : UINT; (*internal variable*)
		C_MasterParID : UINT; (*internal variable*)
		C_MasterParIDMaxVelocity : REAL; (*internal variable*)
		C_LeadInParID : UINT; (*internal variable*)
		C_LeadOutParID : UINT; (*internal variable*)
		EdgeLeadInSignal : BOOL; (*internal variable*)
		EdgeLeadOutSignal : BOOL; (*internal variable*)
		LeadInSignalUsed : BOOL; (*internal variable*)
		LeadOutSignalUsed : BOOL; (*internal variable*)
		C_Active : BOOL; (*internal variable*)
		C_Busy : BOOL; (*internal variable*)
		C_CommandAborted : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		CC_ErrorID : UINT; (*internal variable*)
		C_InSync : BOOL; (*internal variable*)
		C_InCam : BOOL; (*internal variable*)
		C_InDwell : BOOL; (*internal variable*)
		RunningMasterDwellDistance : DINT; (*internal variable*)
		ArithIndex : UINT; (*internal variable*)
		CmpIndex : UINT; (*internal variable*)
		MuxIndex : UINT; (*internal variable*)
		EvWrIndex : UINT; (*internal variable*)
		VarIndex : UINT; (*internal variable*)
		LogicIndex : UINT; (*internal variable*)
		AutStatusValid : BOOL; (*internal variable*)
		AutActualStateIndexOffset : UINT; (*internal variable*)
		AutActualStateIndexRecIndex : USINT; (*internal variable*)
		LockIDMa : USINT; (*internal variable*)
		AutActualCamTypeOffset : UINT; (*internal variable*)
		AutActualCamTypeRecIndex : USINT; (*internal variable*)
		LockIDSend : USINT; (*internal variable*)
		sendSlot : USINT; (*internal variable*)
		readSlot : USINT; (*internal variable*)
		state : USINT; (*internal variable*)
		LockID : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		LockIDReceive : USINT; (*internal variable*)
		MoveID : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CamTransition (*starts a cam profile link between the master and the slave axis*)
	VAR_INPUT
		Master : UDINT; (*axis reference of the master axis*)
		Slave : UDINT; (*axis reference of the slave axis*)
		Enable : BOOL; (*function block is activated*)
		InitData : BOOL; (*starts transferring the parameters*)
		LeadInMasterDistance : REAL; (*master axis compensation distance for the lead in*)
		LeadInSlaveDistance : REAL; (*slave axis compensation distance for the lead in*)
		LeadInMasterOffset : REAL; (*master side offset within the cam profile*)
		LeadOutMasterDistance : REAL; (*master axis compensation distance for the lead out*)
		LeadOutSlaveDistance : REAL; (*slave axis compensation distance for the lead out*)
		LeadOutMasterOffset : REAL; (*master side offset within the cam profile*)
		ReverseSlaveDistance : REAL; (*slaves moves this distence in reverse direction during transition*)
		MasterInterval : REAL; (*interval length of master movement: cam + transition*)
		SlaveInterval : REAL; (*interval length of slave movement: cam + transition*)
		MasterStartPosition : REAL; (*master position where the cam profile starts*)
		MasterScaling : REAL; (*factor of the master profile*)
		SlaveScaling : REAL; (*factor of the slave scaling*)
		CamTableID : USINT; (*ID number of the cam profile*)
		MasterParID : UINT; (*use this ParID for the master axis instead of the set position*)
		MasterParIDMaxVelocity : REAL; (*maximum speed of the master ParID value*)
		LeadInSignal : BOOL; (*signal from the control to start the lead in*)
		LeadOutSignal : BOOL; (*signal from the control to start the lead out*)
		LeadInParID : UINT; (*ParID that can be used by the drive to start the lead out movement*)
		LeadOutParID : UINT; (*ParID that can be used by the drive to start the lead out movement*)
		TransitionMode : UINT; (*mode for transition movement*)
		CamMode : UINT; (*mode for cam movement*)
		CamTime : REAL; (*time for cam movement in mode mcTIME_BASED*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*parameters are transferred and FB is active*)
		Busy : BOOL; (*function block is enabled*)
		CommandAborted : BOOL; (*function block aborted by another FB*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		DataInitialized : BOOL; (*transferring parameters is completed*)
		InSync : BOOL; (*cam profile is synchronized with the master*)
		InLeadIn : BOOL; (*the coupling is within the leadin range*)
		InCam : BOOL; (*the coupling is within the cam range*)
		InTransition : BOOL; (*the coupling is within the transition range*)
		InReverse : BOOL; (*the coupling is within the reverse reange*)
		InLeadOut : BOOL; (*the coupling is within the leadout range*)
	END_VAR
	VAR
		C_Master : UDINT; (*internal variable*)
		C_Slave : UDINT; (*internal variable*)
		EdgeInitData : BOOL; (*internal variable*)
		C_LeadInMasterDistance : DINT; (*internal variable*)
		C_LeadInSlaveDistance : DINT; (*internal variable*)
		C_LeadInMasterOffset : DINT; (*internal variable*)
		C_LeadOutMasterDistance : DINT; (*internal variable*)
		C_LeadOutSlaveDistance : DINT; (*internal variable*)
		C_LeadOutMasterOffset : DINT; (*internal variable*)
		C_ReverseSlaveDistance : DINT; (*internal variable*)
		C_MasterInterval : DINT; (*internal variable*)
		C_SlaveInterval : DINT; (*internal variable*)
		C_MasterStartPosition : DINT; (*internal variable*)
		C_MasterScaling : DINT; (*internal variable*)
		C_SlaveScaling : DINT; (*internal variable*)
		C_CamTableID : UINT; (*internal variable*)
		C_MasterParID : UINT; (*internal variable*)
		C_MasterParIDMaxVelocity : REAL; (*internal variable*)
		C_LeadInParID : UINT; (*internal variable*)
		C_LeadOutParID : UINT; (*internal variable*)
		C_TransitionMode : UINT; (*internal variable*)
		C_CamMode : UINT; (*internal variable*)
		C_CamTime : REAL; (*internal variable*)
		EdgeLeadInSignal : BOOL; (*internal variable*)
		EdgeLeadOutSignal : BOOL; (*internal variable*)
		LeadInSignalUsed : BOOL; (*internal variable*)
		LeadOutSignalUsed : BOOL; (*internal variable*)
		C_Active : BOOL; (*internal variable*)
		C_Busy : BOOL; (*internal variable*)
		C_CommandAborted : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		CC_ErrorID : UINT; (*internal variable*)
		C_InSync : BOOL; (*internal variable*)
		C_InCam : BOOL; (*internal variable*)
		C_InTransition : BOOL; (*internal variable*)
		C_InReverse : BOOL; (*internal variable*)
		C_InLeadIn : BOOL; (*internal variable*)
		C_InLeadOut : BOOL; (*internal variable*)
		C_MasterCompDistance : DINT; (*internal variable*)
		C_SlaveCompDistance : DINT; (*internal variable*)
		C_OldMasterCompDistance : DINT; (*internal variable*)
		C_OldSlaveCompDistance : DINT; (*internal variable*)
		C_CamMasterPeriod : DINT; (*internal variable*)
		C_CamSlavePeriod : DINT; (*internal variable*)
		ArithIndex : UINT; (*internal variable*)
		CmpIndex : UINT; (*internal variable*)
		MuxIndex : UINT; (*internal variable*)
		EvWrIndex : UINT; (*internal variable*)
		VarIndex : UINT; (*internal variable*)
		LogicIndex : UINT; (*internal variable*)
		PidIndex : UINT; (*internal variable*)
		AutStatusValid : BOOL; (*internal variable*)
		InitDataUsed : BOOL; (*internal variable*)
		AutActualStateIndexOffset : UINT; (*internal variable*)
		AutActualStateIndexRecIndex : USINT; (*internal variable*)
		oldAutomatState : USINT; (*internal variable*)
		MasterVelocityOffset : UINT; (*internal variable*)
		MasterVelocityRecIndex : USINT; (*internal variable*)
		LockIDMa : USINT; (*internal variable*)
		AutActualCamTypeOffset : UINT; (*internal variable*)
		AutActualCamTypeRecIndex : USINT; (*internal variable*)
		ChangePending : BOOL; (*internal variable*)
		sendSlot : USINT; (*internal variable*)
		readSlot : USINT; (*internal variable*)
		state : USINT; (*internal variable*)
		LockID : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		MoveID : USINT; (*internal variable*)
		LockIDSend : USINT; (*internal variable*)
		Reserve3 : UDINT; (*internal variable*)
		nextState : USINT; (*internal variable*)
		Reserve4 : USINT; (*internal variable*)
		LockIDReceive : USINT; (*internal variable*)
		Reserve6 : BOOL; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CheckAutCompensation (*checks the compensation data of a cam profile automat*)
	VAR_INPUT
		Master : UDINT; (*axis reference of the master axis*)
		Slave : UDINT; (*axis reference of the slave axis*)
		Execute : BOOL; (*check the compensation data at rising edge*)
		Mode : UINT; (*choose the mode*)
		CompensationData : MC_AUT_COMP_DATA_REF; (*compensation data for the check or calculation*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*check or calculation is successfully finished*)
		Busy : BOOL; (*function block is not finished yet*)
		Error : BOOL; (*error occured in FB*)
		ErrorID : UINT; (*error number*)
		Result : REAL; (*result of the calculation*)
	END_VAR
	VAR
		C_Master : UDINT; (*internal variable*)
		C_Slave : UDINT; (*internal variable*)
		IS : MC_0103_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CheckEndlessPosition (*checks the endless position data for restoring the axis position*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*check the endless position data at rising edge*)
		DataAddress : UDINT; (*data address of momory storage for endless position*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*memory storage for endless position was checked*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		EndlessPositionInitialized : BOOL; (*address of memory storage already initialized*)
		DataValid : BOOL; (*axis position can be restored from the endless position data*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0130_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CommandError (*transfers error commands to the drive, where they are entered*)
	VAR_INPUT
		Axis  : UDINT; (*axis reference*)
		Execute : BOOL; (*transfer command at rising edge*)
		Command : UINT; (*error command*)
	END_VAR
	VAR_OUTPUT
		Done  : BOOL; (*command was successfully transferred *)
		Busy  : BOOL; (*function block is not finished yet*)
		Error : BOOL; (*error occured in FB*)
		ErrorID : UINT; (*error number *)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0140_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ConfigPowerStageCheck (*configurates the power stage checks of the ACOPOS*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*transfer configuration at rising edge *)
		Configuration : MC_POWER_STAGE_CHECK_REF; (*configuration data*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*configuration is successfully finished*)
		Busy : BOOL; (*function block is not finished yet*)
		Error : BOOL; (*error occured in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0137_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CrossCutterControl (*controls a cutter axis linked to a master axis*)
	VAR_INPUT
		Master : UDINT; (*axis reference of the master axis*)
		Slave : UDINT; (*axis reference of the slave/cutter axis*)
		Enable : BOOL; (*function block is activated*)
		InitData : BOOL; (*starts transferring the parameters*)
		EnableCut : BOOL; (*start/stop synchronizing slave to master*)
		CutRangeMaster : REAL; (*cut area on master axis, where the cutter needs to run synchronous to master*)
		CutRangeSlave : REAL; (*area around cut point on slave axis, where the cutter needs to run synchronous to master*)
		ProductLength : REAL; (*distance (master based) in which the cutter needs to make one cut*)
		ProductLengthCorrection : REAL; (*this value is added to ProductLength and then downloaded*)
		AdvancedParameters : MC_ADVANCED_CUT_PAR_REF; (*additional inputs for advanced usage of FB*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*parameters are transferred and FB is active*)
		Busy : BOOL; (*function block is enabled*)
		CommandAborted : BOOL; (*function block aborted by another FB*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		DataInitialized : BOOL; (*transferring parameters is completed*)
		StandBy : BOOL; (*FB can be restarted*)
		InCompensation : BOOL; (*axis outside CutRange, and synchronized*)
		InCut : BOOL; (*axis is within CutRange*)
		CutCount : UDINT; (*information about how many cuts have been made*)
		CutMasterPosition : DINT; (*latched master position at cut for registration mark control*)
	END_VAR
	VAR
		C_Master : UDINT; (*internal variable*)
		C_Slave : UDINT; (*internal variable*)
		IS : MC_0114_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CyclicRead (*enters the specified ParID in the cyclic data from drive and returns it*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*specified ParID is read from the drive as long as enable is TRUE*)
		ParID : UINT; (*ParID which should be read from the drive*)
		DataAddress : UDINT; (*data address of the variable for the value of the ParID*)
		DataType : UINT; (*data type of the ParID*)
		Mode : UINT; (*mode for configuration of records*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*when set the output is valid*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0069_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CyclicReadDataInfo (*Read administrative information of cyclic read data*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*function block is activated*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*if set, the data of the other outputs is valid*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		RecordCount : UINT; (*number of configured records from the drive*)
		ParIDCount : UINT; (*number of configured ParIDs from the drive*)
		RecordUpdateTime : DINT; (*update time of one single record from the drive*)
		TotalUpdateTime : DINT; (*update time of all records from the drive*)
		RecordIndex : UINT; (*index of currently read record from the drive*)
		RecordInfo : MC_RECORD_INFO_REF; (*detailed information about all records from the drive*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0098_IS_TYP; (*internal structure*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CyclicWrite (*enters a specified ParID in the cyclic data to drive*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*specified ParID is written to the drive as long as enable is TRUE*)
		ParID : UINT; (*ParID which should be written to the drive*)
		DataAddress : UDINT; (*data address of the variable with the value for the ParID*)
		DataType : UINT; (*data type of the ParID*)
		Mode : UINT; (*currently not used*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*when set the output is valid*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0070_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_DigitalCamSwitch (*allows a digital output (Track) to be set whenever the axis is inside a position window*)
	VAR_INPUT
		Enable : BOOL; (*when set the FB parameters are downloaded*)
		Switches : MC_MASTER_SWITCHES_REF; (*reference to the switching actions*)
		OutputOptions : MC_OUTPUT_OPTIONS_REF; (*reference to the output options*)
		TrackOptions : MC_TRACK_OPTIONS_REF; (*reference to the track options*)
		SwitchSelector : USINT; (*selection of the switching data*)
		EnableValue : BOOL; (*enable the output of the state of the track on the FB output*)
		EnableParID : BOOL; (*enable the output of the state of the track on the specified ParID*)
		EnableDigOut : BOOL; (*enable the output of of the state of the track on a plug-in module*)
		ChangeSwitches : BOOL; (*change the active switching data*)
		InitSwitches : BOOL; (*initialize new switching parameters*)
		InitTrackOptions : BOOL; (*initialize new track options*)
	END_VAR
	VAR_OUTPUT
		InOperation : BOOL; (*is set after all parameters are transferred*)
		Busy : BOOL; (*the function block is active*)
		Error : BOOL; (*error occured in FB*)
		ErrorID : UINT; (*error number*)
		SwitchesChanged : BOOL; (*the active switching data has been changed*)
		SwitchesInitialized : BOOL; (*new switching parameters are initialized*)
		TrackOptionsInitialized : BOOL; (*new track options initialized*)
		Value : BOOL; (*actual state of the track*)
		ActualSwitches : USINT; (*actual active switches*)
	END_VAR
	VAR
		IS : MC_0107_IS_TYP; (*internal variable*)
		C_Master : UDINT; (*internal variable*)
		C_Slave : UDINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_DownloadCamProfileObj (*transfers a cam profile object to the drive*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*download camprofile at rising edge*)
		DataObjectName : STRING[12]; (*name of the data object*)
		Index : UINT; (*index for cam profile data object*)
		Periodic : BOOL; (*select if paeriodic or non periodic*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*download completed*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_DataObjectName : STRING[12]; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_Index : UINT; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_Periodic : BOOL; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_DownloadCamProfileData (*transfers cam profile data to the drive*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*download cam profile at rising edge*)
		DataAddress : UDINT; (*address of cam profile data*)
		Index : UINT; (*index for cam profile data object*)
		Periodic : BOOL; (*decides if periodic or not*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*download completed*)
		Busy : BOOL; (*function block is not fnished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_DataAddress : UDINT; (*internal variable*)
		C_Index : UINT; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_Periodic : BOOL; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_DownloadParSequ (*downloads a parameter sequence*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*download parameter sequence at rising edge*)
		DataAddress : UDINT; (*data address of the parameter sequence*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*download completed*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		Reserve1 : UINT; (*internal variable*)
		C_Axis : UDINT; (*internal variable*)
		C_DataAddress : UDINT; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		Reserve2 : USINT; (*internal variable*)
		SizeOfFormat : UDINT; (*internal variable*)
		Reserve3 : UDINT; (*internal variable*)
		index : USINT; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_EventMoveAbsolute (*starts an absolute positioning on the drive after a specified event*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*wait for the event at rising edge*)
		EventInput : MC_BR_EVINPUT_REF; (*input that is used as event source*)
		Position : REAL; (*target position for the movement*)
		Velocity : REAL; (*maximum velocity*)
		Acceleration : REAL; (*maximum acceleration*)
		Deceleration : REAL; (*maximum deceleration*)
		Direction : USINT; (*direction of movement*)
		Mode : UINT; (*mcONCE or mcCYCLIC or mcCYCLIC_ALL_EVENTS*)
		PositionParID : UINT; (*ParID from which the target position is read*)
	END_VAR
	VAR_OUTPUT
		InPosition : BOOL; (*target position reached*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		WaitingForEvent : BOOL; (*waiting for event*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)		
		C_EventInput : MC_BR_EVINPUT_REF; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_Position : DINT; (*internal variable*)
		C_Velocity : REAL; (*internal variable*)
		C_Acceleration : REAL; (*internal variable*)
		C_Deceleration : REAL; (*internal variable*)		
		C_Mode : UINT; (*internal variable*)
		C_PositionParID : UINT; (*internal variable*)
		C_InPosition : BOOL; (*internal variable*)
		C_WaitingForEvent : BOOL; (*internal variable*)
		C_Busy : BOOL; (*internal variable*)
		C_CommandAborted : BOOL; (*internal variable*)		
        C_ErrorID : UINT; (*internal variable*)
        C_Error : BOOL; (*internal variable*)
        C_Direction : USINT; (*internal variable*)
		C_CommandedOffset : DINT; (*internal variable*)
		CmpIndex : UINT; (*internal variable*)
		VarIndex : UINT; (*internal variable*)
		EvMoveStatusOffset : UINT; (*internal variable*)
		EvMoveStatusRecIndex : USINT; (*internal variable*)
		SavedFrDrvCnt : USINT; (*internal variable*)
		WaitEvMoveStatusValid : BOOL; (*internal variable*)
		C_MoveActive : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
		LockID : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		MoveID : USINT; (*internal variable*)
		WaitForTelegrams : BOOL; (*internal variable*)
        oldMoveID : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_EventMoveAdditive (*starts a movement on the drive by a set distance after a specified event*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*wait for the event at rising edge*)
		EventInput : MC_BR_EVINPUT_REF; (*input that is used as event source*)
		Distance : REAL; (*relative distance of the movement*)
		Velocity : REAL; (*maximum velocity*)
		Acceleration : REAL; (*maximum acceleration*)
		Deceleration : REAL; (*maximum deceleration*)
		Mode : UINT; (*mcONCE or mcCYCLIC or mcCYCLIC_ALL_EVENTS*)
		DistanceParID : UINT; (*ParID from which the distance is read*)
	END_VAR
	VAR_OUTPUT
		InPosition : BOOL; (*target position reached*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		WaitingForEvent : BOOL; (*waiting for the event*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_EventInput : MC_BR_EVINPUT_REF; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_Distance : DINT; (*internal variable*)
		C_Velocity : REAL; (*internal variable*)
		C_Acceleration : REAL; (*internal variable*)
		C_Deceleration : REAL; (*internal variable*)
		C_Mode : UINT; (*internal variable*)
		C_DistanceParID : UINT; (*internal variable*)
		C_InPosition : BOOL; (*internal variable*)
		C_WaitingForEvent : BOOL; (*internal variable*)
		C_Busy : BOOL; (*internal variable*)
		C_CommandAborted : BOOL; (*internal variable*)	
        C_ErrorID : UINT; (*internal variable*)
        C_Error : BOOL; (*internal variable*)
        Reserve : USINT; (*internal variable*)
		C_CommandedOffset : DINT; (*internal variable*)
		C_CommandedPosition : DINT; (*internal variable*)
		CmpIndex : UINT; (*internal variable*)
		VarIndex : UINT; (*internal variable*)
		EvMoveStatusOffset : UINT; (*internal variable*)
		EvMoveStatusRecIndex : USINT; (*internal variable*)
		SavedFrDrvCnt : USINT; (*internal variable*)
		WaitEvMoveStatusValid : BOOL; (*internal variable*)
		C_MoveActive : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
		LockID : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		MoveID : USINT; (*internal variable*)
        WaitForTelegrams : BOOL; (*internal variable*)
        oldMoveID : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_EventMoveVelocity (*starts a controlled movement with a specified velocity after a specified event*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*wait for the event at rising edge*)
		EventInput : MC_BR_EVINPUT_REF; (*input that is used as event source*)
		Velocity : REAL; (*target velocity*)
		Acceleration : REAL; (*maximum acceleration*)
		Deceleration : REAL; (*maximum deceleration*)
		Direction : USINT; (*direction of movement*)
		Mode : UINT; (*mcONCE or mcCYCLIC_ALL_EVENTS*)
		VelocityParID : UINT; (*ParID from which the velocity is read*)
	END_VAR
	VAR_OUTPUT
		InVelocity : BOOL; (*specified velocity achieved*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		WaitingForEvent : BOOL; (*waiting for the event*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_EventInput : MC_BR_EVINPUT_REF; (*internal variable*)
		C_Velocity : REAL; (*internal variable*)
		C_Acceleration : REAL; (*internal variable*)
		C_Deceleration : REAL; (*internal variable*)
		C_Direction : USINT; (*internal variable*)
		LockID : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		C_Mode : UINT; (*internal variable*)
		C_VelocityParID : UINT; (*internal variable*)
		C_InVelocity : BOOL; (*internal variable*)
		C_WaitingForEvent : BOOL; (*internal variable*)
		C_Busy : BOOL; (*internal variable*)
		C_CommandAborted : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		CmpIndex : UINT; (*internal variable*)
		VarIndex : UINT; (*internal variable*)
		EvMoveStatusOffset : UINT; (*internal variable*)
		EvMoveStatusRecIndex : USINT; (*internal variable*)
		Reserve1 : USINT; (*internal variable*)
		VelocityOffset : UINT; (*internal variable*)
		VelocityRecIndex : USINT; (*internal variable*)
		SavedFrDrvCnt : USINT; (*internal variable*)
		WaitEvMoveStatusValid : BOOL; (*internal variable*)
		C_MoveActive : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
		MoveID : USINT; (*internal variable*)
		WaitForTelegrams : BOOL; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_GearIn (*commands a ratio between the velocity of the master and slave axes*)
	VAR_INPUT
		Master : UDINT; (*axis reference of the master axis *)
		Slave : UDINT; (*axis reference of the slave axis *)
		Enable : BOOL; (*the gear ratio is active as long as this input is set*)
		InitData : BOOL; (*starts transferring the parameters*)
		RatioNumerator : DINT; (*gear ratio numerator*)
		RatioDenominator : DINT; (*gear ratio denominator*)
		AdvancedParameters : MC_ADVANCED_GEAR_PAR_REF; (*additional inputs for advanced usage of FB*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*parameters are transferred and FB is active*)
		Busy : BOOL; (*function block is enabled *)
		CommandAborted : BOOL; (*function block aborted by another FB*)
		Error : BOOL; (*error occured in FB*)
		ErrorID : UINT; (*error number*)
		DataInitialized : BOOL; (*transferring parameters is completed *)
		InGear : BOOL; (*commanded gear ratio reached*)
	END_VAR
	VAR
		C_Master : UDINT; (*internal variable*)
		C_Slave : UDINT; (*internal variable*)
		IS : MC_0126_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_GetCamMasterPosition (*get the master position according to cam profile and slave position*)
	VAR_INPUT
		Master : UDINT; (*master axis reference*)
		Slave : UDINT; (*slave axis reference*)
		Execute : BOOL; (*start master position determination*)
		DataObjectName : STRING[12]; (*name of cam profile data object*)
		DataAddress : UDINT; (*address of cam profile data*)
		MasterStartPosition : REAL; (*master position within cam to start determination of slave position*)
		SlavePosition : REAL; (*slave position within cam to determine master position*)
		MasterFactor : UDINT; (*multiplication factor of the cam on the master axis*)
		SlaveFactor : DINT; (*multiplication factor of the cam on the slave axis*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*master position determination finished*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		MasterPosition : REAL; (*determined master position*)
	END_VAR
	VAR
		C_Master : UDINT; (*internal variable*)
		C_Slave : UDINT; (*internal variable*)
		IS : MC_0084_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_GetCamSlavePosition (*get the slave position according to cam profile and master position*)
	VAR_INPUT
		Master : UDINT; (*master axis reference*)
		Slave : UDINT; (*slave axis reference*)
		Execute : BOOL; (*start slave position determination*)
		DataObjectName : STRING[12]; (*name of cam profile data object*)
		DataAddress : UDINT; (*address of cam profile data*)
		MasterPosition : REAL; (*master position within cam to determine slave position*)
		MasterFactor : UDINT; (*multiplication factor of the cam on the master axis*)
		SlaveFactor : DINT; (*multiplication factor of the cam on the slave axis*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*slave position determination finished*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		SlavePosition : REAL; (*determined slave position*)
	END_VAR
	VAR
		C_Master : UDINT; (*internal variable*)
		C_Slave : UDINT; (*internal variable*)
		IS : MC_0083_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_GetErrorText (*determines the error text for an error record*)
	VAR_INPUT
		Execute : BOOL; (*error text determined after a rising edge*)
		Configuration : MC_ERRORTEXTCONFIG_REF; (*FB configuration*)
		ErrorRecord : MC_ERRORRECORD_REF; (*error record for which the error text should be determined*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*error text determined*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		IS : MC_0077_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_GetHardwareInfo (*determines hardware information of drive components*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*determine ParID information at rising edge*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*command executed*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		HardwareInfo : MC_HARDWARE_INFO_REF; (*hardware information of drive components*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0109_IS_TYP; (*intern variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_GetParIDTransferInfo (*determines ParID transfer information of an axis*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*determine ParID transfer information at rising edge*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*command executed*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		FreeSendChannels : USINT; (*number of free send channels on the axis*)
		FreeReceiveChannels : USINT; (*number of free receive channels on the axis*)
		ParIDTransferInfo : MC_TRANSFER_INFO_REF; (*ParID transfer information of the axis*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0121_IS_TYP; (*intern variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_HomeAcpEncoder (*homes an external encoder*)
	VAR_INPUT
		AcpEncoder : MC_ACP_ENCOD_REF; (*ACOPOS encoder*)
		Execute : BOOL; (*starts homing the encoder*)
		HomingParameters : MC_ACP_ENCOD_PARAM_REF; (*parameter for homing the encoder*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*homing procedur is completed*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		EncoderOffset : DINT; (*home offset after homing procedur*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0068_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_InitAutData (*initialize the parameters of cam profile automat*)
	VAR_INPUT
		Slave : UDINT; (*slave axis*)
		Execute : BOOL; (*starts initialization at rising edge*)
		InitOptions : MC_AUTINITOPTIONS_REF; (*configuration of the FB*)
		AdrAutData : UDINT; (*address of the automat data structure*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*initialization complete*)
		Busy : BOOL; (*initialization active*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Master : UDINT; (*internal variable*)
		C_Slave : UDINT; (*internal variable*)
		IS : MC_0076_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_InitAutEvent (*initializes the parameters of an event for the specified cam automat state*)
	VAR_INPUT
		Slave : UDINT; (*axis reference of the slave axis*)
		Execute : BOOL; (*initialize parameter at rising edge*)
		StateIndex : USINT; (*state index for this event*)
		EventIndex : USINT; (*index for parameter set for an event*)
		Type : USINT; (*event type*)
		Attribute : USINT; (*event attribute*)
		Action : UDINT; (*action at state transition*)
		NextState : USINT; (*index for the next state*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*automat event initialized*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Slave : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_StateIndex : USINT; (*internal variable*)
		C_EventIndex : USINT; (*internal variable*)
		C_Type : USINT; (*internal variable*)
		C_Attribute : USINT; (*internal variable*)
		C_Action : UDINT; (*internal variable*)
		C_NextState : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		Reserve : UDINT; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_InitAutPar (*initializes the general parameters of the cam automat*)
	VAR_INPUT
		Master : UDINT; (*axis reference of the master axis*)
		Slave : UDINT; (*axis reference of the slave axis*)
		Execute : BOOL; (*initialize parameter at rising edge*)
		StartPosition : REAL; (*start position of the master axis*)
		StartInterval : REAL; (*start interval for the master axis*)
		StartState : USINT; (*index for the start state*)
		StartMaRelPos : REAL; (*relative master position in the cam profile*)
		MaxMasterVelocity : REAL; (*maximum speed of the master axis*)
		MasterParID : UINT; (*use this ParID from the master axis instead of the set position*)
		AddMasterParID : UINT; (*ParID of the additive master axis*)
		AddSlaveParID : UINT; (*ParID of the additive slave axis*)
		SlaveFactorParID : UINT; (*ParID for multiplication factor of the slave axis*)
		EventParID : UINT; (*ParID for event input*)
		SlaveLatchParID : UINT; (*ParID for the latch value of the slave axis*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*automat parameters initialized*)
		Busy : BOOL; (*function block not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		Reserve1 : USINT; (*internal variable*)
		LockIDReceive : USINT; (*internal variable*)
		C_Master : UDINT; (*internal variable*)
		C_Slave : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_StartPosition : DINT; (*internal variable*)
		C_StartInterval : DINT; (*internal variable*)
		C_StartState : USINT; (*internal variable*)
		LockIDMa : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		LockIDSend : USINT; (*internal variable*)
		C_StartMaRelPos : DINT; (*internal variable*)
		C_MaxMasterVelocity : REAL; (*internal variable*)
		Reserve2 : UDINT; (*internal variable*)
		C_MasterParID : UINT; (*internal variable*)
		C_AddMasterParID : UINT; (*internal variable*)
		C_AddSlaveParID : UINT; (*internal variable*)
		C_SlaveFactorParID : UINT; (*internal variable*)
		C_EventParID : UINT; (*internal variable*)
		C_SlaveLatchParID : UINT; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		sendSlot : USINT; (*internal variable*)
		readSlot : USINT; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_InitAutState (*initializes the parameters of a cam automat state*)
	VAR_INPUT
		Master : UDINT; (*axis reference of the master axis*)
		Slave : UDINT; (*axis reference of the slave axis*)
		Execute : BOOL; (*initialize parameter at rising edge*)
		StateIndex : USINT; (*index of a parameter set for a state*)
		CamProfileIndex : UINT; (*index of cam profile data for one state*)
		MasterFactor : UDINT; (*multiplication factor for the master axis*)
		SlaveFactor : DINT; (*multiplication factor for the slave axis*)
		RepeatCounterInit : UINT; (*start value state repeats for the ncCOUNT event*)
		RepeatCounterSet : UINT; (*counter state repeats for the ncCOUNT event*)
		CompMode : USINT; (*compensation gear mode*)
		MasterCompDistance : REAL; (*compensation distance for the master axis*)
		SlaveCompDistance : REAL; (*compensation distance for the slave axis*)
		ExtendedCompLimits : USINT; (*extended compensation limits*)
		MinMasterCompDistance : REAL; (*minimum compensation distance for the master axis*)
		MinSlaveCompDistance : REAL; (*minimum compensation distance for the slave axis*)
		MaxSlaveCompDistance : REAL; (*maximum compensation distance for the slave axis*)
		MinSlaveCompVelocity : REAL; (*minimum speed of the slave axis in the compensation*)
		MaxSlaveCompVelocity : REAL; (*maximum speed of the slave axis in the compensation*)
		MaxSlaveAccelComp1 : REAL; (*maximum acceleration of the slave axis in compensation phase 1*)
		MaxSlaveAccelComp2 : REAL; (*maximum acceleration of the slave axis in compensation phase 2*)
		SlaveCompJoltTime : REAL; (*jolt time of the slave axis in the compensation*)
		MasterParID : UINT; (*master ParID for this state*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*automat state parameters initialized*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Master : UDINT; (*internal variable*)
		C_Slave : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_StateIndex : USINT; (*internal variable*)
		Reserve1 : USINT; (*internal variable*)
		C_CamProfileIndex : UINT; (*internal variable*)
		C_MasterFactor : DINT; (*internal variable*)
		C_SlaveFactor : DINT; (*internal variable*)
		C_RepeatCounterInit : UINT; (*internal variable*)
		Reserve2 : UINT; (*internal variable*)
		C_RepeatCounterSet : UINT; (*internal variable*)
		C_CompMode : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		C_MasterCompDistance : DINT; (*internal variable*)
		C_SlaveCompDistance : DINT; (*internal variable*)
		C_ExtendedCompLimits : USINT; (*internal variable*)
		Reserve3 : USINT; (*internal variable*)
		Reserve4 : UINT; (*internal variable*)
		C_MinMasterCompDistance : DINT; (*internal variable*)
		C_MinSlaveCompDistance : DINT; (*internal variable*)
		C_MaxSlaveCompDistance : DINT; (*internal variable*)
		C_MinSlaveCompVelocity : REAL; (*internal variable*)
		C_MaxSlaveCompVelocity : REAL; (*internal variable*)
		C_MaxSlaveAccelComp1 : REAL; (*internal variable*)
		C_MaxSlaveAccelComp2 : REAL; (*internal variable*)
		C_SlaveCompJoltTime : REAL; (*internal variable*)
		C_MasterParID : UINT; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		Reserve5 : UDINT; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_InitAxisPar (*initializes the axis parameter in the axis data structure*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*initializes the axis parameter at rising edge*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*initialization of the data is finished*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		state : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		pInit : REFERENCE TO USINT; (*internal variable*)
		pError : REFERENCE TO USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_InitAxisSubjectPar (*enables the user to selectively initialize structure elements from the axis data structure*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*initializes the axis parameters in the selected axis structure*)
		Subject : UINT; (*subject of the axis structure whose data should be initialized*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*initialization of the data finished*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in function block*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Subject : UINT; (*internal variable*)
		C_ErrorID : UINT; (*internal varaible*)
		C_Error : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		pInit : REFERENCE TO USINT; (*internal variable*)
		pError : REFERENCE TO USINT; (*internal variable*)
		CheckModeBits : UDINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_InitCyclicRead (*adds the specified ParID to the cyclic data from drive*)
	VAR_INPUT
		Axis : UDINT; (*axis refrence*)
		Execute : BOOL; (*initialize cyclic data read at rising edge*)
		ParID : UINT; (*number of the parameter ID to read cyclically*)
		DataAddress : UDINT; (*address of the user variable*)
		DataType : UINT; (*data type of user variable*)
		Mode : UINT; (*currently not used*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*requested parameter is available*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		LockID : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		C_Axis : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_ParID : UINT; (*internal variable*)
		Reserve1 : UINT; (*internal variable*)
		C_DataAddress : UDINT; (*internal variable*)
		C_DataType : UINT; (*internal variable*)
		C_Mode : UINT; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		ParIDOffset : UINT; (*internal variable*)
		Reserve2 : UDINT; (*internal variable*)
		Reserve3 : USINT; (*internal variable*)
		ParIDRecIndex : USINT; (*internal variable*)
		Reserve4 : USINT; (*internal variable*)
		DataLength : USINT; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_InitCyclicWrite (*adds the specified ParID to the cyclic data to the drive*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*initialize cyclic data write at rising edge*)
		ParID : UINT; (*number of the Parameter ID to write cyclically*)
		DataAddress : UDINT; (*address of the user variable*)
		DataType : UINT; (*data type of the user variable*)
		Mode : UINT; (*currently not used*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*initialization of the data write command is done*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		LockID : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		C_Axis : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_ParID : UINT; (*internal variable*)
		Reserve1 : UINT; (*internal variable*)
		C_DataAddress : UDINT; (*internal variable*)
		C_DataType : UINT; (*internal variable*)
		C_Mode : UINT; (*internal variable*)
		Reserve2 : UDINT; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		ParIDParIndex : USINT; (*internal variable*)
		DataLength : USINT; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_InitEndlessPosition (*initialize memory for endless position storage*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*initialize memory storage at rising edge*)
		DataAddress : UDINT; (*data address of momory storage for endless position*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*memory storage for endless position was initialized*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_InitEndlessPosAcpEnc (*initialize memory for endless position storage for external encoder*)
	VAR_INPUT
		AcpEncoder : MC_ACP_ENCOD_REF; (*ACOPOS encoder*)
		Execute : BOOL; (*initialize memory storage at rising edge*)
		DataAddress : UDINT; (*data address of memory storage for endless position*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*memory storage for endless position was initialized*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		DataValid : BOOL; (*axis position can be restored from the endless position data*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0138_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_InitMasterParIDTransfer (*initializes a cyclic ParID transfer from master to slave*)
	VAR_INPUT
		Master : UDINT; (*axis reference of the master axis*)
		Slave : UDINT; (*axis reference of the slave axis*)
		Execute : BOOL; (*initialize transfer at rising edge*)
		MasterParID : UINT; (*use this ParID from the master axis instead of the set position*)
		SlaveChannel : USINT; (*choose a slave channel*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*parameter transfer initialized*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		ReceiveParID : UINT; (*ParID on Slave axis to use as master ParID*)
	END_VAR
	VAR
		C_Master : UDINT; (*internal variable*)
		C_Slave : UDINT; (*internal variable*)
		Reserve1 : UINT; (*internal variable*)
		Reserve2 : USINT; (*internal variable*)
		LockIDReceive : USINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_MasterParID : UINT; (*internal variable*)
		C_SlaveChannel : USINT; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		LockIDSend : USINT; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_ReceiveParID : UINT; (*internal variable*)
		sendSlot : USINT; (*internal variable*)
		readSlot : USINT; (*internal variable*)
		state : USINT; (*internal variable*)
		LockIDMa : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_InitModPos (*initializes the modulo position parameters*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*initialize the modulo position parameter with rising edge*)
		Period : UDINT; (*axis period*)
		Factor : UDINT; (*factor for conversion into init parameter module units*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*modulo position parameters were initialized*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Period : UDINT; (*internal variable*)
		C_Factor : UDINT; (*internal variable*)
		C_ErrorID : UINT; (*internal varaible*)
		C_Error : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_InitParList (*initializes a parameter list*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*initialize parameter list at rising edge*)
		DataAddress : UDINT; (*address of the parameter list*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*init completed*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		LockIDPar : USINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_Axis : UDINT; (*internal variable*)
		C_DataAddress : UDINT; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_InitParSequ (*initializes a parameter sequence*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*initialize parameter sequence at rising edge*)
		DataAddress : UDINT; (*address of the parameter sequence*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*init completed*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_DataAddress : UDINT; (*internal variable*)
		Reserve1 : UINT; (*internal variable*)
		Reserve2 : UDINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		Reserve3 : UDINT; (*internal variable*)
		index : USINT; (*internal variable*)
		Reserve4 : UINT; (*internal variable*)
		state : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_InitParTabObj (*transfers and initializes the parameters contained in "DataObjName" on the specified axis*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*initialize parameter table at rising edge*)
		DataObjectName : STRING[12]; (*name of the data object*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*initialization completed*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_DataObjectName : STRING[12]; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_InitReceiveNetworkData (*initializes receiving of 4-Byte data from a network station*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*initialize receiving of data at the rising edge*)
		NodeNumber : USINT; (*node number of sending network station*)
		BitOffset : UINT; (*bit offset of the data inside the telegram*)
		DataType : UINT; (*data type of the received data*)
		InterpolationMode : USINT; (*interpolation mode of value on receiving drive*)
		ReceiveChannel : USINT; (*receive channel on which the data should be read*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*receiving of data initialized*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		ReceiveParID : UINT; (*ParID on drive that holds received value*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0115_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_InitReceiveNetworkEnc (*initializes receiving of an encoder over the network*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*initialize receiving of data at the rising edge*)
		EncoderInformation : MC_NET_ENC_INFO_REF; (*information about the encoder*)
		EncoderParameters : MC_NET_ENC_PARAM_REF; (*parameters for the encoder*)
        ReceiveConfiguration : MC_NET_ENC_CONFIG_REF; (*configuration for processing received encoder values*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*receiving of data initialized*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		PositionParID : UINT; (*ParID on drive that holds evaluated encoder position*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0141_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_InitReceiveParID (*initializes receiving of a ParID on a drive*)
	VAR_INPUT
		Master : UDINT; (*axis reference*)
		Slave : UDINT; (*axis reference*)
		Execute : BOOL; (*initialize receiving of ParID at the rising edge*)
		ParID : UINT; (*ParID that should be received by the drive*)
		InterpolationMode : USINT; (*interpolation mode of value on receiving drive*)
		SendChannel : USINT; (*send channel on which the ParID is sent*)
		ReceiveChannel : USINT; (*receive channel on which the ParID should be read*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*receiving of ParID initialized*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		ReceiveParID : UINT; (*ParID on slave axis drive that holds received value*)
	END_VAR
	VAR
		C_Master : UDINT; (*internal variable*)
		C_Slave : UDINT; (*internal variable*)
		IS : MC_0112_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_InitSendParID (*initializes sending of a ParID on a drive*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*initialize sending of ParID at the rising edge*)
		ParID : UINT; (*ParID that should be sent by the drive*)
		SendChannel : USINT; (*send channel on which the ParID should be sent*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*sending of ParID initialized*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		AssignedSendChannel : USINT; (*automatically assigned send channel*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0111_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_JogVelocity (*enables and executes jog movements*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*enables execution of jog movements*)
		Velocity : REAL; (*maximum velocity*)
		Acceleration : REAL; (*maximum acceleration*)
		Deceleration : REAL; (*maximum deceleration*)
		JogPositive : BOOL; (*executes positive movement at high level*)
		JogNegative : BOOL; (*executes negative movement at high level*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*function block is active*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		Jogging : BOOL; (*jog movement is active*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0118_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_JogLimitPosition (*enables and executes jog movements between two limit positions*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*enables execution of jog movements*)
		Velocity : REAL; (*maximum velocity*)
		Acceleration : REAL; (*maximum acceleration*)
		Deceleration : REAL; (*maximum deceleration*)
		FirstPosition : REAL; (*lower limit position*)
		LastPosition : REAL; (*higher limit position*)
		JogPositive : BOOL; (*executes positive movement at high level*)
		JogNegative : BOOL; (*executes negative movement at high level*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*function block is active*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		Jogging : BOOL; (*jog movement is active*)
		LimitReached : BOOL; (*limit position is reached*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0119_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_JogTargetPosition (*enables and executes jog movements with a defined target position*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*enables executeion of jog movements*)
		Velocity : REAL; (*maximum velocity*)
		Acceleration : REAL; (*maximum acceleration*)
		Deceleration : REAL; (*maximum deceleration*)
		TargetPosition : REAL; (*target position*)
		JogToTarget : BOOL; (*moves to target position at high level*)
		JogPositive : BOOL; (*executes positive movement at high level*)
		JogNegative : BOOL; (*executes negative movement at high level*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*function block is active*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		Jogging : BOOL; (*jog movement is acitve*)
		MovingToTarget : BOOL; (*axis is moveing to target*)
		TargetReached : BOOL; (*target is reached*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0120_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_LimitLoad (*limits the motor torque to set values*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*when set limitation is activated*)
		InitData : BOOL; (*initialize the input data*)
		LoadPosAccel : REAL; (*limit value for the motor torque [Nm]*)
		LoadPosDecel : REAL; (*limit value for the motor torque [Nm]*)
		LoadNegAccel : REAL; (*limit value for the motor torque [Nm]*)
		LoadNegDecel : REAL; (*limit value for the motor torque [Nm]*)
		Mode : USINT; (*mode for torque limitation*)
		AdvancedParameters : MC_ADV_LIMITLOAD_REF; (*advanced parameters for torque limitation*)
	END_VAR
	VAR_OUTPUT
		Busy : BOOL; (*function block is not finished*)
		Ready : BOOL; (*parameters initialized*)
		Active : BOOL; (*torque is limited*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		DataInitialized : BOOL; (*input data initialized*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0134_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_LimitLoadCam (*limits the motor torque to value from cam profile*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*when set limitation is activated*)
		InitData : BOOL; (*initialize the input data*)
		CamProfileIndexPos : UINT; (*index of cam profile for positive direction*)
		PositionFactorPos : DINT; (*position multiplication factor of cam profile for positive direction*)
		LoadFactorPos : DINT; (*load multiplication factor of cam profile for positive direction*)
		CamProfileIndexNeg : UINT; (*index of cam profile for negative direction*)
		PositionFactorNeg : DINT; (*position multiplication factor of cam profile for negative direction*)
		LoadFactorNeg : DINT; (*load multiplication factor of cam profile for negative direction*)
		Mode : USINT; (*mode for torque limitation*)
	END_VAR
	VAR_OUTPUT
		Busy : BOOL; (*function block is not finished*)
		Ready : BOOL; (*parameters initialized*)
		Active : BOOL; (*torque is limited*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		DataInitialized : BOOL; (*input data initialized*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0135_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_LoadAxisPar (*loads axis parameter from a specified init parameter module to the axis data structure*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*loads the init parameter module at rising edge*)
		DataObjectName : STRING[12]; (*name of the init parameter module*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*loading the data is finished*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_DataObjectName : STRING[12]; (*internal variable*)
		state : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		pInit : REFERENCE TO USINT; (*internal variable*)
		pError : REFERENCE TO USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_MoveAbsoluteTriggStop (*starts a movement to specified Position, at trigger event it moves the TriggerDistance*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*start movement at rising edge*)
		TriggerInput : MC_TRIGGER_REF; (*trigger input signal source*)
		Position : REAL; (*target position for the motion*)
		Velocity : REAL; (*maximum velocity*)
		Acceleration : REAL; (*maximum acceleration*)
		Deceleration : REAL; (*maximum deceleration*)
		Direction : USINT; (*movement direction*)
		TriggerDistance : REAL; (*distance after trigger signal*)
		ForceTriggerDistance : BOOL; (*move trigger distance, even when target position is exceeded*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*absolute move stopped after trigger event or commanded position reached*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)		
		C_Position : DINT; (*internal variable*)
		C_Velocity : REAL; (*internal variable*)
		C_Acceleration : REAL; (*internal variable*)
		C_Deceleration : REAL; (*internal variable*)		
		C_TriggerDistance : DINT; (*internal variable*)
		C_TriggerInput : MC_TRIGGER_REF; (*internal variable*)
		C_ForceTriggerDistance : BOOL; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		cmdExecute : BOOL; (*internal variable*)
		C_Direction : USINT; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_CommandAborted : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_CommandedOffset : DINT; (*internal variable*)
		state : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		MoveID : USINT; (*internal variable*)
		oldMoveID : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_MoveAdditiveTriggStop (*starts a movement for the specified distance, at trigger event it moves the TriggerDistance*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*start movement at rising edge*)
		TriggerInput : MC_TRIGGER_REF; (*trigger input signal source*)
		Distance : REAL; (*relative distance for the motion*)
		Velocity : REAL; (*value of maximum velocity*)
		Acceleration : REAL; (*value of maximum acceleration*)
		Deceleration : REAL; (*value of maximum deceleration*)
		TriggerDistance : REAL; (*distance after trigger signal*)
		ForceTriggerDistance : BOOL; (*move trigger distance, even when target position is exceeded*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*absolute move stopped after trigger event or commanded position reached*)
		Busy : BOOL; (*function block not finished*)
		CommandAborted : BOOL; (*function block aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Distance : DINT; (*internal variable*)
		C_Velocity : REAL; (*internal variable*)
		C_Acceleration : REAL; (*internal variable*)
		C_Deceleration : REAL; (*internal variable*)
		C_TriggerDistance : DINT; (*internal variable*)
		C_TriggerInput : MC_TRIGGER_REF; (*internal variable*)
		C_ForceTriggerDistance : BOOL; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		cmdExecute : BOOL; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_CommandAborted : BOOL; (*internal variable*)		
		C_ErrorID : UINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
		C_CommandedOffset : DINT; (*internal variable*)
		C_CommandedPosition : REAL; (*internal variable*)		
		LockIDPar : USINT; (*internal variable*)
		MoveID : USINT; (*internal variable*)
		oldMoveID : USINT; (*internal variable*)
		reserve : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_MoveCyclicPosition (*commands the axis to follow a cyclically transferred position*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*as long as Enable is TRUE the cyclic position is transferred to the axis*)
		CyclicPosition : MC_CYCLIC_POSITION; (*cyclic position that is transferred to the axis*)
		Velocity : REAL; (*value of maximum velocity to reach the position*)
		Acceleration : REAL; (*value of maximum acceleration to reach the position*)
		Deceleration : REAL; (*value of maximum deceleration to reach the position*)
		PositionParID : UINT; (*use this ParID as position source instead of CyclicPosition input*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*position is beeing transferred to the axis*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		ReceiveParID : UINT; (*ParID that receives the cyclic position*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		Reserve : USINT; (*internal variable*)
		IS : MC_0081_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_MoveCyclicPositionExt (*commands the axis to follow a cyclically transferred position*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*as long as Enable is TRUE the cyclic position is transferred to the axis*)
		CyclicPosition : MC_CYCLIC_POSITION_REF; (*cyclic position that is transferred to the axis*)
		InterpolationMode : USINT; (*interpolation mode of cyclic position on receiving drive*)
		AdvancedParameters : MC_ADVANCED_MOVE_CYC_REF; (*structure for using additional functions*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*position is beeing transferred to the axis*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		ReceiveParID : UINT; (*ParID that receives the cyclic position*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0124_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_MoveCyclicVelocity (*commands the axis to move with a cyclically transferred velocity*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*as long as Enable is TRUE the cyclic velocity is transferred to the axis*)
		CyclicVelocity : REAL; (*cyclic velocity that is transferred to the axis*)
		Direction : USINT; (*direction of movement*)
		Acceleration : REAL; (*value of maximum acceleration to reach the velocity*)
		Deceleration : REAL; (*value of maximum deceleration to reach the velocity*)
		VelocityParID : UINT; (*use this ParID as velocity source instead of CyclicVelocity input*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*velocity is beeing transferred to the axis*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred in function block*)
		ErrorID : UINT; (*error number*)
		ReceiveParID : UINT; (*ParId that receives the cyclic velocity*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0092_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_MoveCyclicVelocityExt (*commands the axis to move with a cyclically transferred velocity*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*as long as Enable is TRUE the cyclic velocity is transferred to the axis*)
		CyclicVelocity : REAL; (*cyclic velocity that is transferred to the axis*)
		Direction : USINT; (*direction of movement*)
		InterpolationMode : USINT; (*interpolation mode of cyclic position on receiving drive*)
		AdvancedParameters : MC_ADVANCED_MOVE_CYC_REF; (*structure for using additional functions*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*velocity is beeing transferred to the axis*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred in function block*)
		ErrorID : UINT; (*error number*)
		ReceiveParID : UINT; (*ParId that receives the cyclic velocity*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0125_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_MoveVelocityTriggStop (*starts a movement with specified velocity in specified direction, a trigger stops the axis*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*start movement at rising edge*)
		TriggerInput : MC_TRIGGER_REF; (*trigger input signal source*)
		Velocity : REAL; (*maximum velocity*)
		Acceleration : REAL; (*maximum acceleration*)
		Deceleration : REAL; (*maximum deceleration*)
		Direction : USINT; (*movement direction*)
		TriggerDistance : REAL; (*distance after trigger event*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*velocity move stopped after trigger event*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Velocity : REAL; (*internal variable*)		
		C_Acceleration : REAL; (*internal variable*)
		C_Deceleration : REAL; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		cmdExecute : BOOL; (*internal variable*)
		C_Direction : USINT; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_CommandAborted : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)				
		C_TriggerInput : MC_TRIGGER_REF; (*internal variable*)
		state : USINT; (*internal variable*)	
		C_TriggerDistance : DINT; (*internal variable*)		
		LockIDPar : USINT; (*internal variable*)
		MoveID : USINT; (*internal variable*)
		oldMoveID : USINT; (*internal variable*)
		reserve : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_NetTrace (*controls the network command trace*)
	VAR_INPUT
		Execute : BOOL; (*execute command at rising edge*)
		Command : UINT; (*select the command for the network command trace*)
		Configuration : MC_NETTRACECONFIG_REF; (*FB configuration*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*command executed*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		ErrorRecord : MC_ERRORRECORD_REF; (*error messages that can occur after executing the command*)
	END_VAR
	VAR
		IS : MC_0078_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_NetworkInit (*controls the network initilization*)
	VAR_INPUT
	    Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*execute command at rising edge*)
		Command : UINT; (*select the command for the network initialization*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*command executed*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Object : UDINT; (*internal variable*)
		IS : MC_0139_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_Offset (*adds an offset to the position of the slave axis*)
	VAR_INPUT
		Slave : UDINT; (*axis reference of the slave axis*)
		Enable : BOOL; (*enable the function block*)
		InitData : BOOL; (*initialize the input data*)
		PerformVelocityControl : BOOL; (*enable the phase shift*)
		Shift : REAL; (*offset shift value*)
		Velocity : REAL; (*velocity for reaching the offset shift*)
		Acceleration : REAL; (*acceleration for reaching the offset shift*)
		ApplicationDistance : REAL; (*distance within which the offset shift occurs*)
		ApplicationMode : UINT; (*basis of movement profile*)
		ShiftMode : UINT; (*definition of how the value on the "Shift" input should be used*)
		AdvancedParameters : MC_ADVANCEDSHIFTPAR_REF; (*structure for using additional functions*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*a offset shift can be executed*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		ShiftAttained : BOOL; (*offset shift executed*)
		DataInitialized : BOOL; (*input data initialized*)
		ActualShiftValue : REAL; (*current value of shift on the drive*)
	END_VAR
	VAR
		C_Slave : UDINT; (*internal variable*)
		C_InitData : BOOL; (*internal variable*)
		C_PerformVelocityControl : BOOL; (*internal variable*)
		C_Shift : DINT; (*internal variable*)
		C_Velocity : REAL; (*internal variable*)
		C_Acceleration : REAL; (*internal variable*)
		C_ApplicationDistance : DINT; (*internal variable*)
		C_ApplicationMode : UINT; (*internal variable*)
		C_SelectedMaster : UINT; (*internal variable*)
		C_ShiftMode : UINT; (*internal variable*)
		C_AdvancedParameters : MC_ADVANCEDSHIFTPAR_REF; (*internal variable*)
		C_Active : BOOL; (*internal variable*)
		C_Busy : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		CC_ErrorID : UINT; (*internal variable*)
		C_ShiftAttained : BOOL; (*internal variable*)
		C_DataInitialized : BOOL; (*internal variable*)
		C_AxisState : UINT; (*internal variable*)
		NextState : USINT; (*internal variable*)
		state : USINT; (*internal variable*)
		LockID : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		Factor : UDINT; (*internal variable*)
		RtN : REAL; (*internal variable*)
		C_StartShiftValue : DINT; (*internal variable*)
		VarIndex : UINT; (*internal variable*)
		MpgenIndex : UINT; (*internal variable*)
		C_MpgenStatus : USINT; (*internal variable*)
		MpgenStatusOffset : UINT; (*internal variable*)
		MpgenStatusRecIndex : USINT; (*internal variable*)
		Reserve : USINT; (*internal variable*)
		MpgenValueOffset : UINT; (*internal variable*)
		MpgenValueRecIndex : USINT; (*internal variable*)
		FbID : USINT; (*internal variable*)
		InitDataActive : BOOL; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_OffsetVelocity (*adds a velocity offset to the velocity of the slave axis*)
	VAR_INPUT
		Slave : UDINT; (*axis reference of the slave axis*)
		Enable : BOOL; (*enable the function block*)
		CyclicVelocity : REAL; (*additive velocity*)
		Acceleration : REAL; (*acceleration for reaching the additive velocity*)
		AdvancedParameters : MC_ADV_OFFSETVELOCITY_REF; (*structure for using additional functions*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*a velocity offset can be executed*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		VelocityAttained : BOOL; (*additive velocity offset reached*)
		ActualShiftValue : REAL; (*current value of velocity offset on the drive*)
	END_VAR
	VAR
		C_Slave : UDINT; (*internal variable*)
		IS : MC_0127_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_OffsetZone (*adds an offset to the position of the slave axis*)
	VAR_INPUT
		Slave : UDINT; (*axis reference of the slave axis*)
		Enable : BOOL; (*enable the function block*)
		InitData : BOOL; (*initialize the input data*)
		Shift : REAL; (*offset shift value*)
		Velocity : REAL; (*velocity for reaching the offset shift*)
		Acceleration : REAL; (*acceleration for reaching the offset shift*)
		ZoneStartPosition : REAL; (*start position of the offset shift zone*)
		ZoneEndPosition : REAL; (*end position of the offset shift zone*)
		AdvancedParameters : MC_ADV_OFFSETZONE_REF; (*structure for using additional functions*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*a offset shift can be executed*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		ShiftAttained : BOOL; (*offset shift executed*)
		DataInitialized : BOOL; (*input data initialized*)
		ActualShiftValue : REAL; (*current value of shift on the drive*)
	END_VAR
	VAR
		C_Slave : UDINT; (*internal variable*)
		IS : MC_0128_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_GetParIDInfo (*determines data type and data length of a ParID*)
	VAR_INPUT
		Execute : BOOL; (*determine ParID information at rising edge*)
		ParID : UINT; (*ParID of which the information should be determined*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*command executed*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		ParIDInfo : MC_PARID_INFO_REF; (*information about ParID*)
	END_VAR
	VAR
		IS : MC_0106_IS_TYP; (*intern variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ParTrace (*controls the parameter trace*)
	VAR_INPUT
		Execute : BOOL; (*execute command at rising edge*)
		Command : UINT; (*select the command for the trace*)
		Configuration : MC_PARTRACECONFIG_REF; (*FB configuration*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*command executed*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		ErrorRecord : MC_ERRORRECORD_REF; (*error messages that can occur after executing the command*)
	END_VAR
	VAR
		IS : MC_0080_IS_TYP; (*intern variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ParTraceConfig (*load and save axis trace configuration*)
	VAR_INPUT
		Execute : BOOL; (*execute command at rising edge*)
		Command : UINT; (*select the command for the trace*)
		AdrTraceConfig : UDINT; (*adress of axis trace configuration*)
		DataObject : MC_DATOBJ_REF; (*data object parameters*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*command executed*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		ErrorRecord : MC_ERRORRECORD_REF; (*error messages that can occur after executing the command*)
	END_VAR
	VAR
		IS : MC_0102_IS_TYP; (*intern variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_Phasing (*causes a phase shift in the master position of the slave axis*)
	VAR_INPUT
		Slave : UDINT; (*axis reference of the slave axis*)
		Enable : BOOL; (*enable the function block*)
		InitData : BOOL; (*initialize the input data*)
		PerformVelocityControl : BOOL; (*enable the phase shift*)
		Shift : REAL; (*phase shift value*)
		Velocity : REAL; (*velocity for reaching the phase shift*)
		Acceleration : REAL; (*acceleration for reaching the phase shift*)
		ApplicationDistance : REAL; (*distance within which the phase shift occurs*)
		ApplicationMode : UINT; (*basis for movement profile*)
		ShiftMode : UINT; (*definition of how the value on the "Shift" input should be used*)
		AdvancedParameters : MC_ADVANCEDSHIFTPAR_REF; (*structure for using additional functions*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*a phase shift can be executed*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		ShiftAttained : BOOL; (*phase shift executed*)
		DataInitialized : BOOL; (*input data initialized*)
		ActualShiftValue : REAL; (*current value of shift on the drive*)
	END_VAR
	VAR
		C_Slave : UDINT; (*internal variable*)
		C_InitData : BOOL; (*internal variable*)
		C_PerformVelocityControl : BOOL; (*internal variable*)
		C_Shift : DINT; (*internal variable*)
		C_Velocity : REAL; (*internal variable*)
		C_Acceleration : REAL; (*internal variable*)
		C_ApplicationDistance : DINT; (*internal variable*)
		C_ApplicationMode : UINT; (*internal variable*)
		C_SelectedMaster : UINT; (*internal variable*)
		C_ShiftMode : UINT; (*internal variable*)
		C_AdvancedParameters : MC_ADVANCEDSHIFTPAR_REF; (*internal variable*)
		C_Active : BOOL; (*internal variable*)
		C_Busy : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		CC_ErrorID : UINT; (*internal variable*)
		C_ShiftAttained : BOOL; (*internal variable*)
		C_DataInitialized : BOOL; (*internal variable*)
		C_AxisState : UINT; (*internal variable*)
		NextState : USINT; (*internal variable*)
		state : USINT; (*internal variable*)
		LockID : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		Factor : UDINT; (*internal variable*)
		RtN : REAL; (*internal variable*)
		C_StartShiftValue : DINT; (*internal variable*)
		VarIndex : UINT; (*internal variable*)
		MpgenIndex : UINT; (*internal variable*)
		C_MpgenStatus : USINT; (*internal variable*)
		MpgenStatusOffset : UINT; (*internal variable*)
		MpgenStatusRecIndex : USINT; (*internal variable*)
		Reserve : USINT; (*internal variable*)
		MpgenValueOffset : UINT; (*internal variable*)
		MpgenValueRecIndex : USINT; (*internal variable*)
		FbID : USINT; (*internal variable*)
		InitDataActive : BOOL; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_MechPosDeviationComp (*handles mechanics position deviation compensation*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*as long as Enable is TRUE the FB is active*)
		Parameters : MC_MPDC_PARAM_REF; (*parameters for mechanics position deviation compensation*)
		AdvancedParameters : MC_ADV_MPDC_REF; (*advanced parameters for mechanics deviation position compensation*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*if set, the mechanics deviation position compensation is active*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		AdvancedInfo : MC_ADV_INFO_MPDC_REF; (*structure with additional information*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0147_IS_TYP; (*internal structure*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_PowerMeter (*executes the evaluation of the powerdata of a PSM*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*as long as Enable is TRUE the power evaluation is active*)
		Mode : USINT; (*choose the mode for the power evaluation*)
		IntervalTime : UINT; (*duration of the interval*)
		RestartInterval : BOOL; (*a new interval is startet at rising edge of this input*)
		EventInput : MC_BR_EVINPUT_REF; (*if this is used, the Trigger input will not be considered*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*if set, the data on Output PowerData are valid*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		PowerData : MC_POWERDATA_REF; (*structure for the power data*)
		MissedIntervals : UINT; (*count of missed intervalls*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0089_IS_TYP; (*internal structure*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ReadAutPosition (*reads the cam profile automat position*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*automat position is read at rising edge*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*reading automat position is finished*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		AutPosition : REAL; (*automat position*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		Reserve1 : USINT; (*internal variable*)
		C_AutPosition : DINT; (*internal variable*)
		C_DataAddress : UDINT; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ReadAxisError (*reads and acknowledges an axis error record and reads the error text*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*read error record/text*)
		Acknowledge : BOOL; (*acknowledge current axis error*)
		Mode : UINT; (*operating mode of FB*)
		Configuration : MC_ERRORTEXTCONFIG_REF; (*FB configuration*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*if set, the data of the other outputs is valid*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		ErrorRecordAvailable : BOOL; (*a new error record is available*)
		ErrorRecord : MC_ERRORRECORD_REF; (*detailed axis error information*)
		FunctionBlockErrorCount : UINT; (*number of not acknowledged function block errors*)
		AxisErrorCount : UINT; (*number of not acknowledged axis errors*)
		AxisWarningCount : UINT; (*number of not acknowledged axis warnings*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0105_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ReadCyclicPosition (*read the position of an axis cyclically*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*as long as Enable is TRUE the cyclic position is read from the axis*)
		ParID : UINT; (*ParID that is read cyclically, 0... set position*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*position is beeing read from the axis*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		CyclicPosition : MC_CYCLIC_POSITION; (*cyclic position that is read from the axis*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0082_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ReadDriveStatus (*checks the status of a drive*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*when set the status is read*)
		AdrDriveStatus : UDINT; (*address of the structur where the status is written on*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*output of FB is valid*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		state : USINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_AdrDriveStatus : UDINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ReadNetTraceStatus (*determines the current status of the network command trace*)
	VAR_INPUT
		Enable : BOOL; (*the status of the network command trace is read as long as the input is enabled*)
		Configuration : MC_NETTRACECONFIG_REF; (*FB configuration. Only the element "NetTrace" is evaluated*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*the status information is valid*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		TraceState : UINT; (*status of the NWCT*)
	END_VAR
	VAR
		C_ErrorID : UINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ReadParID (*reads a ParID from the specified axis*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*read data at rising edge*)
		ParID : UINT; (*number of the parameter ID to read*)
		DataAddress : UDINT; (*address of the user variable*)
		DataType : UINT; (*data type of the user variable*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*value of ParID has been copied to the user variable*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in function block*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_ParID : UINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		Reserve1 : USINT; (*internal variable*)
		C_DataAddress : UDINT; (*internal variable*)
		Reserve2 : UDINT; (*internal variable*)
		C_DataType : UINT; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ReadParIDText (*reads a ParID from the specified axis in text format*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*read data at rising edge*)
		ParID : UINT; (*number of the parameter ID to read*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*value of ParID has been read*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in function block*)
		ErrorID : UINT; (*error number*)
		DataText : STRING[33]; (*value of ParID in text format *)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_ParID : UINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ReadParList (*read a parameter list*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*read parameter list at rising edge*)
		DataAddress : UDINT; (*address of the parameter list*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*transfer completed*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		LockIDPar : USINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_Axis : UDINT; (*internal variable*)
		C_DataAddress : UDINT; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ReadParTraceStatus (*determines the current status of the axis trace*)
	VAR_INPUT
		Enable : BOOL; (*the status of the axis trace is read as long as the input is enabled*)
		Configuration : MC_PARTRACECONFIG_REF; (*FB configuration. Only the element "ParTrace" is evaluated*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*the status information is valid*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		TraceState : UINT; (*status of the trace*)
	END_VAR
	VAR
		C_ErrorID : UINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ReceiveParIDOnPLC (*initializes receiving of a ParID on the PLC*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*as long as Enable is TRUE the ParID is read from the axis*)
		ParID : UINT; (*ParID that is read cyclically*)
		SendChannel : USINT; (*send channel on which the ParID is sent*)
		Mode : USINT; (*convertion of ParID-value into PLCopen-units can be activated*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*ParID is beeing read from the axis*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		CyclicValue : MC_CYCLIC_VALUE_REF; (*cyclic ParID value that is read from the axis*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0113_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ResetAutPar (*initializes the general parameters of the cam automat*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*set parameter to default values at rising edge*)
		GlobalParams : USINT; (*selection of the global parameter*)
		StateIndex : USINT; (*selection of the automat state*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*automat parameters set to default values*)
		Busy : BOOL; (*function block not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0136_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_SaveAxisPar (*writes the axis parameters in the axis data structure*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*write axis parameter from the axis structure to a init parameter module at rising edge*)
		DataObjectName : STRING[12]; (*name of the init parameter module*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*saving the data is finished*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		DataObjectIdent : UDINT; (*init parameter module data object ID for the function blocks in the DataObj library*)
	END_VAR
	VAR
		C_Axis : UDINT;
		C_DataObjectName : STRING[12]; (*internal variable*)
		state : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		pInit : REFERENCE TO USINT; (*internal variable*)
		pError : REFERENCE TO USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_SaveCamProfileObj (*saves the data of a cam profile into a data module*)
	VAR_INPUT
		Execute : BOOL; (*save the cam profile at rising edge*)
		DataObjectName : STRING[12]; (*name for the data module in which the cam profile is saved*)
		DataAddress : UDINT; (*address of the cam profile data*)
		DataObjectVersion : UINT; (*version for the data module*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*data module was saved*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		ErrorRecord : MC_ERRORRECORD_REF; (*error messages that can occur after executing the command*)
		DataObjectIdent : UDINT; (*ident of the data module*)
	END_VAR
	VAR
		IS : MC_0116_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_SetHardwareInputs (*forces the hardware inputs*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*set the status of the hardware inputs as long as the input is enabled*)
		HomeSwitch : BOOL; (*if TRUE the reference hardware input is activated*)
		PosHWSwitch : BOOL; (*if TRUE the positive limit switch input is activated*)
		NegHWSwitch : BOOL; (*if TRUE the negative limit switch input is activated*)
		Trigger1 : BOOL; (*if TRUE the trigger1 input is activated*)
		Trigger2 : BOOL; (*if TRUE the trigger2 input is activated*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*function block is active and waits for changes on the inputs*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		InputsSet : BOOL; (*the actual input status was transferred*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0108_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_SetupController (*starts a controller setup and saves the parameters*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*starts the command action at rising edge*)
		Command : UINT; (*choose the command for the setup*)
		Configuration : MC_SETUP_CONTROLLER_CFG_REF; (*FB-Configuration*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*command successfully completed*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		SetupOutput : MC_SETUP_OUTPUT_REF; (*structure for output values*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0090_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_SetupFromParTabObj (*starts a setup with parameter from an ACOPOS parameter table*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*starts the commanded action at rising edge*)
		Command : UINT; (*choose the command for the setup*)
		DataObjectName : STRING[12]; (*name of the ACOPOS parameter table*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*command succesfully completed*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		SetupOutput : MC_SETUP_OUTPUT_REF; (*structure for output values*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0145_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_SetupInductionMotor (*starts the motorsetup for an induction motor and saves the parameters*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*starts the commanded action at rising edge*)
		Command : UINT; (*choose the command for the setup*)
		Configuration : MC_SETUP_IND_MOTOR_CFG_REF; (*FB-Configuration*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*command succesfully completed*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		SetupOutput : MC_SETUP_OUTPUT_REF; (*structure for output values*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0088_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_SetupIsqRipple (*starts the setup for isq ripple compensation  and saves the parameters*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*starts the commanded action at rising edge*)
		Command : UINT; (*choose the command for the setup*)
		Configuration : MC_SETUP_ISQ_RIPPLE_CFG_REF; (*FB-Configuration*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*command successfully completed*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		SetupOutput : MC_SETUP_OUTPUT_REF; (*structure for the output values*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0101_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_SetupMotorPhasing (*starts a phasing setup and saves the parameters*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*starts the commanded action at rising edge*)
		Command : UINT; (*choose the command for the setup*)
		Configuration : MC_SETUP_MOTOR_PHA_CFG_REF; (*FB-Configuration*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*command successfully completed*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number *)
		SetupOutput : MC_SETUP_OUTPUT_REF; (*structure for output values*)
		SetupResult : MC_SETUP_PHASING_RESULT_REF; (*structure for results of the setup*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0097_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_SetupSynchronMotor (*starts the motorsetup for a synchron motor and saves the parameters*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*starts the commanded action at rising edge*)
		Command : UINT; (*choose the command for the setup*)
		Configuration : MC_SETUP_SYNC_MOTOR_CFG_REF; (*FB-Configuration*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*command successfully completed*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		SetupOutput : MC_SETUP_OUTPUT_REF; (*structure for output values*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0129_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_Simulation (*turns on or off simulation mode for a drive*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*switch simulation mode on or off at rising edge*)
		SimulationCommand : UINT; (*choose if switch on or off simulation mode*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*simulation mode is on or off*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0071_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_TouchProbe (*saves the values of ParIDs when a specified event occurs*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		TriggerInput : MC_BR_TRIGGER_REF; (*input that is used as event source*)
		Enable : BOOL; (*as long as enable is TRUE, a value is saved every time a trigger event occurs*)
		Period : REAL; (*interval between two expected trigger positions*)
		PeriodChange : REAL; (*if no valid event occurs within an interval, the window is shifted by the value of Period*)
		ExpectedValue : REAL; (*expected position of the trigger event within the Period*)
		WindowNegative : REAL; (*range before the expected position in which the trigger signal may occur*)
		WindowPositive : REAL; (*range after the expected position in which the trigger signal may occur*)
		Mode : UINT; (*the way the FB works can be determined with this input*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*waits for a trigger event*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occured in FB*)
		ErrorID : UINT; (*error number*)
		RecordedPeriodicValue : REAL; (*result value within the configured period*)
		RecordedValue : DINT; (*result value*)
		DeltaExpectedValue : REAL; (*deviation: expected position - result value*)
		ProbeCounter : UDINT; (*number of valid trigger events since "Enable" was set to TRUE*)
		MissedTriggers : UDINT; (*number of invalid or missing trigger events since "Enable" was set to TRUE*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_TriggerInput : MC_BR_TRIGGER_REF; (*internal variable*)
		C_Period : DINT; (*internal variable*)
		C_PeriodChange : DINT; (*internal variable*)
		C_ExpectedValue : DINT; (*internal variable*)
		C_WindowNegative : DINT; (*internal variable*)
		C_WindowPositive : DINT; (*internal variable*)
		C_Mode : UINT; (*internal variable*)
		C_Active : BOOL; (*internal variable*)
		C_Busy : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_RecordedPeriodicValue : REAL; (*internal variable*)
		C_RecordedValue : DINT; (*internal variable*)
		C_DeltaExpectedValue : REAL; (*internal variable*)
		C_ProbeCounter : UDINT; (*internal variable*)
		C_MissedTriggers : UDINT; (*internal variable*)
		PeriodOffset : DINT; (*internal variable*)
		LatchValue : DINT; (*internal variable*)
		LatchDeltaIv : DINT; (*internal variable*)
		NewValue : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
		NextState : USINT; (*internal variable*)
		DataTyp : UINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		LockID : USINT; (*internal variable*)
		ActualPosition : DINT; (*internal variable*)
		LatchIndex : UINT; (*internal variable*)
		BitIndex : UINT; (*internal variable*)
		BitValueOffset : UINT; (*internal variable*)
		BitValueRecIndex : USINT; (*internal variable*)
		SptID : USINT; (*internal variable*)
		UpdatePeriod : BOOL; (*internal variable*)
		UseAxisPeriod : BOOL; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_VelocityControl (*sends cyclic speed set value for velocity control*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*when set the FB will activate torque control*)
		CyclicVelocity : REAL; (*Parameter input for set speed*)
		CyclicVelocityCorrection : REAL; (*Parameter input for additive set speed*)
		CyclicTorque : REAL; (*Parameter input for limit or additive torque*)
		TorqueMode : USINT; (*Mode setting (limit or additive torque)*)
		Acceleration : REAL; (*Value of maximum acceleration*)
		Deceleration : REAL; (*Value of maximum deceleration*)
		SctrlKv : REAL; (*Value of proportional part of speed controller*)
		SctrlTn : REAL; (*Value of integral part of speed controller*)
		InitSctrl : BOOL; (*Command for downloading values for sctrl*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*Functionality of FB enabled*)
		Busy : BOOL; (*Function Block is not finished*)
		CommandAborted : BOOL; (*FB was aborted from MC_Power or an Error*)
		Error : BOOL; (*Error occured in FB*)
		ErrorID : UINT; (*PLCopen error number*)
		SctrlInitialized : BOOL; (*Parameters to speed controller downloaded*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0095_IS_TYP; (*internal structure*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_WriteParID (*writes a ParID to specified axis*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*write data at rising edge*)
		ParID : UINT; (*number of the parameter ID to write*)
		DataAddress : UDINT; (*address of the user variable*)
		DataType : UINT; (*data type of user variable*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*value of the user variable has been copied to the ParID*)
		Busy : BOOL; (*parameter write is in progress*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_ParID : UINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		Reserve1 : USINT; (*internal variable*)
		C_DataAddress : UDINT; (*internal variable*)
		Reserve2 : UDINT; (*internal variable*)
		C_DataType : UINT; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_WriteParIDText (*writes a ParID from the specified axis in text format*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*write data at rising edge*)
		ParID : UINT; (*number of the parameter ID to write*)
		DataText : STRING[33]; (*value of ParID in text format *)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*value of ParID has been written*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in function block*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_ParID : UINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_CamIn (*engages a cam coupling between master and slave axis*)
	VAR_INPUT
		Master : UDINT; (*axis reference of the master axis*)
		Slave : UDINT; (*axis reference of the slave axis*)
		Execute : BOOL; (*start at rising edge*)
		MasterOffset : REAL; (*offset on master axis*)
		SlaveOffset : REAL; (*offset on slave axis*)
		MasterScaling : REAL; (*factor for the master profile*)
		SlaveScaling : REAL; (*factor for the slave profile*)
		StartMode : USINT; (*start mode*)
		CamTableID : USINT; (*identifier of cam table*)
		MasterParID : UINT; (*use this ParID instead of the set position*)
	END_VAR
	VAR_OUTPUT
		InSync : BOOL; (*cam is engaged for the first time*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		EndOfProfile : BOOL; (*pulsed output signaling the cyclic end of the cam profile*)
	END_VAR
	VAR
		LockID : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		LockIDInSync : USINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_Master : UDINT; (*internal variable*)
		C_Slave : UDINT; (*internal variable*)
		C_MasterOffset : DINT; (*internal variable*)
		C_SlaveOffset : DINT; (*internal variable*)
		C_MasterScaling : DINT; (*internal variable*)
		C_SlaveScaling : DINT; (*internal variable*)
		C_CamTableID : UINT; (*internal variable*)
		C_StartMode : USINT; (*internal variable*)
		C_Periodic : BOOL; (*internal variable*)
		C_MasterParID : UINT; (*internal variable*)
		C_InSync : BOOL; (*internal variable*)
		C_CommandAborted : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_EndOfProfile : BOOL; (*internal variable*)
		OldMaCamOffset : DINT; (*internal variable*)
		MaPosition : DINT; (*internal variable*)
		DataTyp : UINT; (*internal variable*)
		MpgenIndex : UINT; (*internal variable*)
		AutActualStateIndexOffset : UINT; (*internal variable*)
		AutActualStateIndexRecIndex : USINT; (*internal variable*)
		LockIDReceive : USINT; (*internal variable*)
		AutActualCamIndexOffset : UINT; (*internal variable*)
		AutActualCamIndexRecIndex : USINT; (*internal variable*)
		LockIDSend : USINT; (*internal variable*)
		AutMaCamOffsetOffset : UINT; (*internal variable*)
		AutMaCamOffsetRecIndex : USINT; (*internal variable*)
		LockIDMa : USINT; (*internal variable*)
		sendSlot : USINT; (*internal variable*)
		readSlot : USINT; (*internal variable*)
		state : USINT; (*internal variable*)
		MoveID : USINT; (*internal variable*)
		CC_ErrorID : UINT; (*internal variable*)
		oldMoveID : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_CamOut (*disengages the cam slave from the master axis*)
	VAR_INPUT
		Slave : UDINT; (*axis reference of the slave axis*)
		Execute : BOOL; (*start to disengage the slave from the master*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*disengaging complete*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Slave : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		state : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		MoveID : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_CamTableSelect (*prepares the cam tables that will be used by the function block "MC_CamIn"*)
	VAR_INPUT
		Master : UDINT; (*axis reference of the master axis*)
		Slave : UDINT; (*axis reference of the slave axis*)
		CamTable : STRING[12]; (*name of the cam table*)
		Execute : BOOL; (*selection at rising edge*)
		Periodic : BOOL; (*select if periodic cam or non periodic cam*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*pre-selection done*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		CamTableID : USINT; (*identifier of the cam table*)
	END_VAR
	VAR
		C_Master : UDINT; (*internal variable*)
		C_Slave : UDINT; (*internal variable*)
		C_CamTable : STRING[12]; (*internal variable*)
		Reserve : USINT; (*internal variable*)
		C_Periodic : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		state : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_DigitalCamSwitch (*allows a digital output (Track) to be set whenever the axis is inside a position window*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Switches : MC_CAMSWITCH_REF; (*reference to the switching actions*)
		Outputs : MC_OUTPUT_REF; (*reference to the signal outputs*)
		TrackOptions : MC_TRACK_REF; (*reference to the track related properties*)
		Enable : BOOL; (*when set the FB parameters are downloaded*)
		EnableMask : UDINT; (*when set the digital outputs will be switched to ON and OFF*)
		InitSwitches : BOOL; (*initialize new switching action*)
		InitTrackOptions : BOOL; (*initialize new track related properties while switching is active*)
	END_VAR
	VAR_OUTPUT
		InOperation : BOOL; (*is set after all parameters have transferred*)
		Busy : BOOL; (*the function block is active*)
		SwitchesInitialized : BOOL; (*new switching actions initialized*)
		TrackOptionsInitialized : BOOL; (*new track related properties initialized*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Master : UDINT; (*internal variable*)
		C_Slave : UDINT; (*internal variable*)
		C_Switches : MC_CAMSWITCH_REF; (*internal variable*)
		C_Outputs : MC_OUTPUT_REF; (*internal variable*)
		C_TrackOptions : MC_TRACK_REF; (*internal variable*)
		C_EnableMask : UDINT; (*internal variable*)
		C_CamConActRec : USINT; (*internal variable*)
		nextParRec : USINT; (*internal variable*)
		SelectRecMode : USINT; (*internal variable*)
		LockIDSend : USINT; (*internal variable*)
		C_InOperation : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_Busy : BOOL; (*internal variable*)
		CC_ErrorID : UINT; (*internal variable*)
		EdgeInitSwitches : BOOL; (*internal variable*)
		EdgeInitTrackOptions : BOOL; (*internal variable*)
		CamConIndex : UINT; (*internal variable*)
		LogicIndex : UINT; (*internal variable*)
		VarIndex : UINT; (*internal variable*)
		CamConActRecOffset : UINT; (*internal variable*)
		CamConActRecRecIndex : USINT; (*internal variable*)
		LockIDMa : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		LockID : USINT; (*internal variable*)
		sendSlot : USINT; (*internal variable*)
		readSlot : USINT; (*internal variable*)
		state : USINT; (*internal variable*)
		SptID : USINT; (*internal variable*)
		LockIDReceive : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_GearIn (*commands a ratio between the velocity of the master and slave axes*)
	VAR_INPUT
		Master : UDINT; (*axis reference of the master axis*)
		Slave : UDINT; (*axis reference of the slave axis*)
		Execute : BOOL; (*start the gearing process at the rising edge*)
		RatioNumerator : INT; (*gear ratio numerator*)
		RatioDenominator : UINT; (*gear ratio denominator*)
		Acceleration : REAL; (*maximum acceleration for gearing in*)
		Deceleration : REAL; (*maximum deceleration for gearing in*)
		MasterParID : UINT; (*use this master ParID instead of the set position*)
		MasterParIDMaxVelocity : REAL; (*maximum velocity of the master ParID*)
	END_VAR
	VAR_OUTPUT
		InGear : BOOL; (*commanded gearing complete*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		LockID : USINT; (*internal variable*)
		C_Master : UDINT; (*internal variable*)
		C_Slave : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_RatioNumerator : DINT; (*internal variable*)
		C_RatioDenominator : DINT; (*internal variable*)
		C_Acceleration : REAL; (*internal variable*)
		C_Deceleration : REAL; (*internal variable*)
		C_MasterParID : UINT; (*internal variable*)
		CC_ErrorID : UINT; (*internal variable*)
		C_MasterParIDMaxVelocity : REAL; (*internal variable*)
		C_InGear : BOOL; (*internal variable*)
		C_CommandAborted : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		MpgenIndex : UINT; (*internal variable*)
		AutActualStateIndexOffset : UINT; (*internal variable*)
		AutActualStateIndexRecIndex : USINT; (*internal variable*)
		LockIDMa : USINT; (*internal variable*)
		sendSlot : USINT; (*internal variable*)
		readSlot : USINT; (*internal variable*)
		state : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		MoveID : USINT; (*internal variable*)
		LockIDSend : USINT; (*internal variable*)
		LockIDReceive : USINT; (*internal variable*)
		SavedFrDrvCnt : USINT; (*internal variable*)
		WaitForTelegrams : BOOL; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_GearInPos (*commands a gear ratio between the position of the slave and master axis*)
	VAR_INPUT
		Master : UDINT; (*axis reference of the master axis*)
		Slave : UDINT; (*axis reference of the slave axis*)
		Execute : BOOL; (*start the gearing process at the rising edge*)
		RatioNumerator : INT; (*gear ration numerator*)
		RatioDenominator : UINT; (*gear ratio denominator*)
		MasterSyncPosition : REAL; (*master position at which the axes are running in sync*)
		SlaveSyncPosition : REAL; (*slave position at which the axes are running in sync*)
		SyncMode : USINT; (*defines the way to syncronize*)
		MasterStartDistance : REAL; (*master distance for preparation*)
		Velocity : REAL; (*maximum velocity during the time difference "StartSync" and "InSync"*)
		Acceleration : REAL; (*maximum acceleration during the time difference "StartSync" and "InSync"*)
		MasterParID : UINT; (*use this ParID from the master axis instead of the set position*)
		MasterParIDMaxVelocity : REAL; (*maximum value of the master ParID value*)
	END_VAR
	VAR_OUTPUT
		StartSync : BOOL; (*command gearing starts*)
		InSync : BOOL; (*commanded gearing is completed*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Master : UDINT; (*internal variable*)
		C_Slave : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_RatioNumerator : DINT; (*internal variable*)
		C_RatioDenominator : DINT; (*internal variable*)
		Reserve1 : DINT; (*internal variable*)
		Reserve2 : DINT; (*internal variable*)
		C_SyncMode : USINT; (*internal variable*)
		LockID : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		C_MasterStartDistance : DINT; (*internal variable*)
		C_MasterSyncPosition : DINT; (*internal variable*)
		C_SlaveSyncPosition : DINT; (*internal variable*)
		C_Velocity : REAL; (*internal variable*)
		C_Acceleration : REAL; (*internal variable*)
		C_MasterParID : UINT; (*internal variable*)
		C_MasterParIDMaxVelocity : REAL; (*internal variable*)
		C_StartSync : BOOL; (*internal variable*)
		C_InSync : BOOL; (*internal variable*)
		C_CommandAborted : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		CC_Error : BOOL; (*internal variable*)
		MaPosition : DINT; (*internal variable*)
		DataTyp : UINT; (*internal variable*)
		MA_LastSyncPosition : DINT; (*internal variable*)
		SL_LastSyncPosition : DINT; (*internal variable*)
		MpgenIndex : UINT; (*internal variable*)
		Reserve3 : USINT; (*internal variable*)
		LockIDReceive : USINT; (*internal variable*)
		AutActualCamTypeOffset : UINT; (*internal variable*)
		AutActualCamTypeRecIndex : USINT; (*internal variable*)
		LockIDSend : USINT; (*internal variable*)
		AutActualStateIndexOffset : UINT; (*internal variable*)
		AutActualStateIndexRecIndex : USINT; (*internal variable*)
		LockIDMa : USINT; (*internal variable*)
		sendSlot : USINT; (*internal variable*)
		readSlot : USINT; (*internal variable*)
		state : USINT; (*internal variable*)
		MoveID : USINT; (*internal variable*)
		CC_ErrorID : UINT; (*internal variable*)
		Reserve4 : UINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_GearOut (*disengages the geared slave from the master axis*)
	VAR_INPUT
		Slave : UDINT; (*axis reference of slave axis*)
		Execute : BOOL; (*start disengaging process at rising edge*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*disengaging completed*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Slave : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		state : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		MoveID : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_Halt (*commands a controlled motion stop*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*start the action at rising edge*)
		Deceleration : REAL; (*value of deceleration*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*zero velocity is reached*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block aborted by calling another movement function block*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		cmdExecute : BOOL; (*internal variable*)		
		C_Done : BOOL; (*internal variable*)
        C_CommandAborted : BOOL; (*internal variable*)
        C_Deceleration : REAL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
		MoveID : USINT; (*internal variable*)
        LockIDPar : USINT; (*internal variable*)        
        Reserve : UINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_Home (*starts the homing movement of an axis according to the homing parameters*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*start movement at rising edge*)
		Position : REAL; (*absolute position when the reference signal is detected*)
		HomingMode : USINT; (*select the homing mode*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*homing procedure has finished successfully*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_Position : DINT; (*internal variable*)
		C_HomingMode : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_CommandAborted : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		state : USINT; (*internal variable*)
		MoveID : USINT; (*internal variable*)
		CC_Position : REAL; (*internal variable*)
		C_StatusFlags : UDINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_LimitLoad (*limits the motor torque to a set value*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*when set limitation is activated*)
		Load : REAL; (*limit value for the motor torque [Nm]*)
		Direction : USINT; (*movement direction*)
	END_VAR
	VAR_OUTPUT
		Busy : BOOL; (*function block is not finished*)
		Ready : BOOL; (*parameters initialized*)
		Active : BOOL; (*torque is limited*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0133_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_MoveAbsolute (*commands a controlled motion at a specified absolute position*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*start movement at rising edge*)
		Position : REAL; (*target position for the motion*)
		Velocity : REAL; (*maximum velocity*)
		Acceleration : REAL; (*maximum acceleration*)
		Deceleration : REAL; (*maximum deceleration*)
		Direction : USINT; (*movement direction*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*commanded position reached*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		cmdExecute : BOOL; (*internal variable*)	
        C_Direction : USINT; (*internal variable*)
        LockIDPar : USINT; (*internal variable*)
        C_Position : DINT; (*internal variable*)
        C_Velocity : REAL; (*internal variable*)
        C_Acceleration : REAL; (*internal variable*)
        C_Deceleration : REAL; (*internal variable*)
        C_Done : BOOL; (*internal variable*)
		C_CommandAborted : BOOL; (*internal variable*)
        C_Error : BOOL; (*internal variable*)
        state : USINT; (*internal variable*)
        C_CommandedOffset : DINT; (*internal variable*)	
		C_ErrorID : UINT; (*internal variable*)			
        MoveID : USINT; (*internal variable*)
        oldMoveID : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_MoveAdditive (*commands a controlled motion of a specified relative distance*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*start movement at rising edge*)
		Distance : REAL; (*relative distance for the motion*)
		Velocity : REAL; (*maximum velocity for the motion*)
		Acceleration : REAL; (*maximum acceleration for the motion*)
		Deceleration : REAL; (*maximum deceleration for the motion*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*commanded position reached*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Distance : DINT; (*internal variable*)
		C_Velocity : REAL; (*internal variable*)
		C_Acceleration : REAL; (*internal variable*)
        C_Deceleration : REAL; (*internal variable*)
        C_Execute : BOOL; (*internal variable*)
		cmdExecute : BOOL; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_CommandAborted : BOOL; (*internal variable*)
		C_CommandedPosition : DINT; (*internal variable*)
        C_CommandedOffset : DINT; (*internal variable*)        
        C_ErrorID : UINT; (*internal variable*)
        C_Error : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
        MoveID : USINT; (*internal variable*)
        oldMoveID : USINT; (*internal variable*)
        Reserve : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_MoveVelocity (*commands a motion with specified velocity*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*start movement at rising edge*)
		Velocity : REAL; (*Value of maximum velocity*)
		Acceleration : REAL; (*Value of maximum acceleration*)
		Deceleration : REAL; (*Value of maximum deceleration*)
		Direction : USINT; (*direction of movement*)
	END_VAR
	VAR_OUTPUT
		InVelocity : BOOL; (*commanded velocity reached*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		cmdExecute : BOOL; (*internal variable*)
		C_Velocity : REAL; (*internal variable*)
		C_Acceleration : REAL; (*internal variable*)
		C_Deceleration : REAL; (*internal variable*)
		C_Direction : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		C_InVelocity : BOOL; (*internal variable*)
		C_CommandAborted : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		state : USINT; (*internal variable*)
		MoveID : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_Phasing (*creates a phase shift in the master position of a slave axis*)
	VAR_INPUT
		Master : UDINT; (*axis reference of the master axis*)
		Slave : UDINT; (*axis reference of the slave axis*)
		Execute : BOOL; (*start the phasing process at rising edge*)
		PhaseShift : REAL; (*phase difference*)
		Velocity : REAL; (*maximum velocity to reach phase difference*)
		Acceleration : REAL; (*maximum acceleration to reach phase difference*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*commanded phasing reached*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Master : UDINT; (*internal variable*)
		C_Slave : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_PhaseShift : DINT; (*internal variable*)
		C_Velocity : REAL; (*internal variable*)
		C_Acceleration : REAL; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_CommandAborted : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		MpgenIndex : UINT; (*internal variable*)
		MpgenStatusOffset : UINT; (*internal variable*)
		MpgenStatusRecIndex : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		SavedFrDrvCnt : USINT; (*internal variable*)
		state : USINT; (*internal variable*)
		FbID : USINT; (*internal variable*)
		WaitForTelegrams : BOOL; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_Power (*switches on the controller of the axis*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*as long as "Enable" is TRUE, the drive power stage is enabled*)
	END_VAR
	VAR_OUTPUT
		Status : BOOL; (*effective status of the power stage*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		state : USINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_Axis : UDINT; (*internal variable*)
		startTicks : UDINT; (*internal variable*)
		AxisTypeCtrlOffAxisState : UINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_ReadActualPosition (*returns the actual axis position*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*when set the position is read*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*output of FB is valid*)
		Busy : BOOL; (*the function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		Position : REAL; (*actual position of the axis*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_ReadActualTorque (*returns the axis torque*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*read the actual torque continuously while enabled*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*output is available*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		Torque : REAL; (*value of the actual torque*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		TorqueOffset : UINT; (*internal variable*)
		TorqueRecIndex : USINT; (*internal variable*)
		LockID : USINT; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_ReadActualVelocity (*returns the axis velocity*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*read the velocity continuously while enabled*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*output is available*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		Velocity : REAL; (*value of actual velocity*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_ReadAxisError (*returns the actual axis error as long as "Enable" is TRUE*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*read error number/text*)
		Acknowledge : BOOL; (*acknowledge current axis error*)
		DataAddress : UDINT; (*address of error text string*)
		DataLength : UINT; (*length of error text string*)
		DataObjectName : STRING[12]; (*name of error text module*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*error text is valid*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		AxisErrorID : UINT; (*axis error number*)
		AxisErrorCount : UINT; (*count of axis error*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Acknowledge : BOOL; (*internal variable*)
		C_OldAcknowledge : BOOL; (*internal variable*)
		C_DataObjectName : STRING[12]; (*internal variable*)
		Reserve : UINT; (*internal variable*)
		writeText : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_ReadBoolParameter (*returns the value of one Boolean PLCopen parameter*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*get the value of the parameter while enabled*)
		ParameterNumber : INT; (*number of the parameter*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*parameter available*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		Value : BOOL; (*value of requested parameter*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_ReadDigitalInput (*reads an digital input on an ACOPOS plug-in module*)
	VAR_INPUT
		Input : MC_INPUT_REF; (*reference to input signal source*)
		Enable : BOOL; (*get value of selected input signal continuously while enabled*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*input signal value is valid*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		Value : BOOL; (*value of selected input signal*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Input : MC_INPUT_REF; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		ReadDigitalInputOffset : UINT; (*internal variable*)
		ReadDigitalInputRecIndex : USINT; (*internal variable*)
		LockID : USINT; (*internal variable*)
		ReadDigitalInputValue : UINT; (*internal variable*)
		ReadDigitalInputMask : UINT; (*internal variable*)
		state : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_ReadDigitalOutput (*reads a digital output*)
	VAR_INPUT
		Output : MC_OUTPUT_REF; (*reference to signal outputs*)
		Enable : BOOL; (*get value of selected output signal continouosly while enabled*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*output signal value is valid*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		Value : BOOL; (*value of selected output signal*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Output : MC_OUTPUT_REF; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		ReadDigitalOutputOffset : UINT; (*internal variable*)
		ReadDigitalOutputRecIndex : USINT; (*internal variable*)
		LockID : USINT; (*internal variable*)
		ReadDigitalOutputValue : UINT; (*internal variable*)
		ReadDigitalOutputMask : UINT; (*internal variable*)
		state : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_ReadParameter (*returns the value of a specific PLCopen parameter*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*get the value of the parameter while enabled*)
		ParameterNumber : INT; (*number of parameter*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*parameter available*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		Value : REAL; (*value of the requested parameter*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_ReadStatus (*returns the detailed status of the motion currently in progress*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*read the axis status continuously while enabled*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*true if valid outputs available*)
		Busy : BOOL; (*the function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		Errorstop : BOOL; (*an error occurred on the drive*)
		Disabled : BOOL; (*controller is switched off*)
		Stopping : BOOL; (*MC_Stop is active*)
		StandStill : BOOL; (*controller is switched on but no motion is active*)
		DiscreteMotion : BOOL; (*axis executes an absolute or an additive motion*)
		ContinuousMotion : BOOL; (*axis is in permanent motion*)
		SynchronizedMotion : BOOL; (*axis is synchronized with another axis*)
		Homing : BOOL; (*MC_Home has started homing the axis*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_Reset (*makes transition from Errorstop to Standstill or Disabled by resetting internal axis related errors*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*resets the axis at the rising edge*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*standstill state is reached*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_SetOverride (*sets the values of override parameters for velocity and acceleration/deceleration*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*write the value of the override at the rising edge*)
		VelFactor : REAL; (*new override factor for the velocity*)
		AccFactor : REAL; (*new override factor for the acceleration/deceleration*)
	END_VAR
	VAR_OUTPUT
		Enabled : BOOL; (*override successfully written*)
		Busy : BOOL; (*function block not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_VelFactor : REAL; (*internal variable*)
		C_AccFactor : REAL; (*internal variable*)
		OldVelFactor : REAL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_Stop (*commands a controlled motion stop and transfers the axis to the state Stopping*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*start the action at rising edge*)
		Deceleration : REAL; (*value of deceleration *)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*zero velocity is reached*)
		Busy : BOOL; (*function block is not finished*)
		CommandAborted : BOOL; (*function block is aborted by switching off power*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_Deceleration : REAL; (*internal variable*)
		C_CommandAborted : BOOL; (*internal variable*)
		state : USINT; (*internal variable*)
		MoveID : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_TouchProbe (*records an axis position at a trigger event*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		TriggerInput : MC_TRIGGER_REF; (*trigger input signal source*)
		Execute : BOOL; (*transfer parameters at rising edge*)
		WindowOnly : BOOL; (*if set, only use the window to accept trigger events*)
		FirstPosition : REAL; (*start position from where trigger events are accepted*)
		LastPosition : REAL; (*end position of the window*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*trigger event recorded*)
		Busy : BOOL; (*function block not finished*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
		RecordedPosition : REAL; (*position where the trigger event occurred*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_Busy : BOOL; (*internal variable*)
		C_TriggerInput : MC_TRIGGER_REF; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_WindowOnly : BOOL; (*internal variable*)
		C_FirstPosition : DINT; (*internal variable*)
		C_LastPosition : DINT; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		C_CommandAborted : BOOL; (*internal variable*)
		C_RecordedPosition : DINT; (*internal variable*)
		InputSourceChanged : BOOL; (*internal variable*)
		EdgeChanged : BOOL; (*internal variable*)
		PosSourceChanged : BOOL; (*internal variable*)
		SavedToDrvCnt : USINT; (*internal variable*)
		Reserve2 : USINT; (*internal variable*)
		state : USINT; (*internal variable*)
		LockID : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
		cycleTime : UINT; (*internal variable*)
		LatchPos : DINT; (*internal variable*)
		LatchStatusOffset : UINT; (*internal variable*)
		LatchStatusRecIndex : USINT; (*internal variable*)
		Reserve1 : USINT; (*internal variable*)
		LatchPosOffset : UINT; (*internal variable*)
		LatchPosRecIndex : USINT; (*internal variable*)
		SptID : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_TorqueControl (*starts a torque movement with limited speed*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*start movement at rising edge*)
		Torque : REAL; (*signed set torque value for the axis [Nm]*)
		TorqueRamp : REAL; (*torque increase while reaching "Torque" [Nm/s]*)
		Velocity : REAL; (*velocity limit for axis*)
		Acceleration : REAL; (*maximum acceleration or deceleration*)
	END_VAR
	VAR_OUTPUT
		InTorque : BOOL; (*set torque value reached*)
		Busy : BOOL; (*function block is not finished*)
		Active : BOOL; (*function block is controlling the axis*)
		CommandAborted : BOOL; (*command is aborted by another command*)
		Error : BOOL; (*error occured in FB*)
		ErrorID : UINT; (*error number*)
		AxisLimitActive : BOOL; (*axis velocity limited*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0096_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_TorqueControl (*starts a torque movement with limited speed*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Enable : BOOL; (*function block is activated*)
		InitData : BOOL; (*parameter change while the FB is active*)
		StartSignal : BOOL; (*starts torque-controlled movement*)
		Torque : REAL; (*signed set torque value for the axis [Nm]*)
		TorqueRamp : REAL; (*torque increase while reaching "Torque" [Nm/s]*)
		PosMaxVelocity : REAL; (*velocity limit for axis*)
		NegMaxVelocity : REAL; (*velocity limit for axis*)
		Acceleration : REAL; (*maximum acceleration or deceleration*)
		Mode : UINT; (*mode selection (bit coded)*)
		TimeLimit : REAL; (*maximum movement time with limited speed or acceleration*)
		StartParID : UINT; (*not used at the moment*)
		TorqueParID : UINT; (*set torque value from ParID*)
	END_VAR
	VAR_OUTPUT
		InTorque : BOOL; (*set torque reached*)
		Busy : BOOL; (*function block is not finished*)
		Active : BOOL; (*function block is controlling the axis*)
		CommandAborted : BOOL; (*command is aborted by another command*)
		Error : BOOL; (*error occured in FB*)
		ErrorID : UINT; (*error number*)
		DataInitialized : BOOL; (*parameter online change done*)
		WaitingForStart : BOOL; (*ready for start via "StartSignal"*)
		AxisLimitActive : BOOL; (*axis velocity or acceleration limited*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		IS : MC_0100_IS_TYP; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_WriteBoolParameter (*writes the value of one Boolean PLCopen parameter*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*write the value of the parameter at rising edge*)
		ParameterNumber : INT; (*number of the parameter*)
		Value : BOOL; (*new value of specified parameter*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*parameter successfully written*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_ParameterNumber : INT; (*internal variable*)
		Reserve : UINT; (*internal variable*)
		state : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_WriteDigitalOutput (*writes a digital output*)
	VAR_INPUT
		Output : MC_OUTPUT_REF; (*reference to signal output*)
		Execute : BOOL; (*write the value of selected output*)
		Value : BOOL; (*the value of the selected output*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*writing of the output signal value is done*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Output : MC_OUTPUT_REF; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_Value : BOOL; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		WriteDigitalOutputMask : UINT; (*internal variable*)
		state : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_WriteParameter (*writes the value to a specific PLCopen parameter*)
	VAR_INPUT
		Axis : UDINT; (*axis reference*)
		Execute : BOOL; (*write the value of the parameter at the rising edge*)
		ParameterNumber : INT; (*number of the parameter*)
		Value : REAL; (*new value of specified parameter*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*parameter succesfully written*)
		Busy : BOOL; (*function block is not finished*)
		Error : BOOL; (*error occurred in FB*)
		ErrorID : UINT; (*error number*)
	END_VAR
	VAR
		C_Axis : UDINT; (*internal variable*)
		C_Execute : BOOL; (*internal variable*)
		C_ParameterNumber : INT; (*internal variable*)
		C_Value : REAL; (*internal variable*)
		C_Done : BOOL; (*internal variable*)
		C_Error : BOOL; (*internal variable*)
		C_ErrorID : UINT; (*internal variable*)
		state : USINT; (*internal variable*)
		LockIDPar : USINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
