
FUNCTION_BLOCK MpAxisBasic (*Covers all basic functions of an axis*) (* $GROUP=mapp,$CAT=Single Axis,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpAxis.png *)
	VAR_INPUT
		MpLink : REFERENCE TO MpComIdentType; (*Incoming communication handle (mapp standard interface)*) (* *) (*#PAR#;*)
		Enable : BOOL; (*Enables/Disables the function block*) (* *) (*#PAR#;*)
		ErrorReset : BOOL; (*Resets function block errors*) (* *) (*#PAR#;*)
		Parameters : REFERENCE TO MpAxisBasicParType; (*Function block parameters*) (* *) (*#PAR#;*)
		Update : BOOL; (*Updates the parameters*) (* *) (*#PAR#;*)
		Axis : UDINT; (*Axis reference*) (* *) (*#PAR#;*)
		Power : BOOL; (*Level-sensitive command for turning an axis on/off. In the event of an error, a new rising edge is required to restart the axis*) (* *) (*#CMD#;*)
		Home : BOOL; (*Command for homing the axis*) (* *) (*#CMD#;*)
		MoveVelocity : BOOL; (*Starts a constant movement with a defined velocity*) (* *) (*#CMD#;*)
		MoveAbsolute : BOOL; (*Starts an absolute movement*) (* *) (*#CMD#;*)
		MoveAdditive : BOOL; (*Starts a relative movement*) (* *) (*#CMD#;*)
		Stop : BOOL; (*Stops the axis*) (* *) (*#CMD#;*)
		JogPositive : BOOL; (*Movement in the positive direction. Stops automatically at the software limit position*) (* *) (*#CMD#OPT#;*)
		JogNegative : BOOL; (*Movement in the negative direction. Stops automatically at the software limit position*) (* *) (*#CMD#OPT#;*)
		Autotune : BOOL; (*Starts autotuning*) (* *) (*#CMD#OPT#;*)
		Simulate : BOOL; (*Enables motor simulation*) (* *) (*#CMD#OPT#;*)
		TorqueLimit : BOOL; (*Enables torque limiting*) (* *) (*#CMD#OPT#;*)
		ReleaseBrake : BOOL; (*Locks or unlocks the holding brake (only when the axis is switched off)*) (* *) (*#CMD#OPT#;*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*Indicates whether the function block is active*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates that the function block is in an error state or a command was not executed correctly*) (* *) (*#PAR#;*)
		StatusID : DINT; (*Status information about the function block*) (* *) (*#PAR#;*)
		UpdateDone : BOOL; (*Parameter update completed*) (* *) (*#PAR#;*)
		Position : LREAL; (*Current position of the axis [units]*) (* *) (*#CYC#;*)
		Velocity : REAL; (*Current velocity of the axis [units/s]*) (* *) (*#CYC#;*)
		CommandBusy : BOOL; (*Function block currently executing command*) (* *) (*#CMD#OPT#;*)
		CommandAborted : BOOL; (*Function block interrupted while executing a command*) (* *) (*#CMD#OPT#;*)
		PowerOn : BOOL; (*Switches on the axis*) (* *) (*#CMD#;*)
		IsHomed : BOOL; (*Homes the axis*) (* *) (*#CMD#;*)
		InVelocity : BOOL; (*Axis running with defined velocity*) (* *) (*#CMD#;*)
		InPosition : BOOL; (*Axis reached the desired position*) (* *) (*#CMD#;*)
		MoveActive : BOOL; (*Movement active*) (* *) (*#CMD#;*)
		Stopped : BOOL; (*Axis stopped*) (* *) (*#CMD#;*)
		TuningDone : BOOL; (*Autotuning completed successfully*) (* *) (*#CMD#OPT#;*)
		Simulation : BOOL; (*Motor simulation active*) (* *) (*#CMD#OPT#;*)
		TorqueLimited : BOOL; (*Torque limiting function active*) (* *) (*#CMD#OPT#;*)
		BrakeReleased : BOOL; (*Holding brake manually released*) (* *) (*#CMD#OPT#;*)
		Info : MpAxisBasicInfoType; (*Additional information about the component*) (* *) (*#CMD#;*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} MpComInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MpAxisCamSequencer (*Flexibly sequence various (user-defined or predefined) cam profiles together*) (* $GROUP=mapp,$CAT=Multi Axis,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpAxis1.png *)
	VAR_INPUT
		MpLink : REFERENCE TO MpComIdentType; (*Connection to mapp, slave axis for the coupling*) (* *) (*#PAR#;*)
		Enable : BOOL; (*Enables/Disables the function block*) (* *) (*#PAR#;*)
		ErrorReset : BOOL; (*Resets function block errors*) (* *) (*#PAR#;*)
		Parameters : REFERENCE TO MpAxisCamSequencerParType; (*Function block parameters*) (* *) (*#PAR#;*)
		Update : BOOL; (*Update command for the parameters*) (* *) (*#PAR#;*)
		MpLinkMaster : REFERENCE TO MpComIdentType; (*Master axis for the coupling*) (* *) (*#PAR#;*)
		Signal1 : BOOL; (*Sets the signal for the sequencer on a rising edge, resets the signal on a falling edge (if it has not already completed)*) (* *) (*#CYC#;*)
		Signal2 : BOOL; (*Sets the signal for the sequencer on a rising edge, resets the signal on a falling edge (if it has not already completed)*) (* *) (*#CYC#;*)
		Signal3 : BOOL; (*Sets the signal for the sequencer on a rising edge, resets the signal on a falling edge (if it has not already completed)*) (* *) (*#CYC#;*)
		Signal4 : BOOL; (*Sets the signal for the sequencer on a rising edge, resets the signal on a falling edge (if it has not already completed)*) (* *) (*#CYC#;*)
		StartSequence : BOOL; (*Starts the cam sequencer*) (* *) (*#CMD#;*)
		Continue : BOOL; (*If "Standby" is active, the cam sequencer starts where it stopped. If not, this pin has the same effect as "StartSequence"*) (* *) (*#CMD#;*)
		EndSequence : BOOL; (*Stops the cam sequencer*) (* *) (*#CMD#;*)
		Recovery : BOOL; (*Begins to undo all shifts made*) (* *) (*#CMD#OPT#;*)
		OffsetShift : BOOL; (*Starts a phase shift to the slave position (offset)*) (* *) (*#CMD#OPT#;*)
		PhaseShift : BOOL; (*Starts a phase shift to the master position with which the slave is working (phase); the master remains unaffected*) (* *) (*#CMD#OPT#;*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*Indicates whether the function block is active*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates that the function block is in an error state or a command was not executed correctly*) (* *) (*#PAR#;*)
		StatusID : DINT; (*Status information about the function block*) (* *) (*#PAR#;*)
		UpdateDone : BOOL; (*Parameter update completed*) (* *) (*#PAR#;*)
		ActualStateIndex : USINT; (*Index for the current state*) (* *) (*#CYC#;*)
		ActualStateCamIndex : UINT; (*Index of the curve being used in the current state*) (* *) (*#CYC#;*)
		Standby : BOOL; (*The cam sequencer can be restarted using the "Continue" command*) (* *) (*#CYC#;*)
		CommandBusy : BOOL; (*Function block currently executing command*) (* *) (*#CMD#OPT#;*)
		CommandAborted : BOOL; (*Function block interrupted while executing a command*) (* *) (*#CMD#OPT#;*)
		InCompensation : BOOL; (*Axis currently performing a compensating movement*) (* *) (*#CMD#;*)
		InSync : BOOL; (*Slave synchronous with the master*) (* *) (*#CMD#;*)
		RecoveryDone : BOOL; (*Axis in phase with the master*) (* *) (*#CMD#OPT#;*)
		OffsetDone : BOOL; (*Shift to slave position performed successfully (offset)*) (* *) (*#CMD#OPT#;*)
		PhasingDone : BOOL; (*Shift to the master position with which the slave is working performed successfully (phase)*) (* *) (*#CMD#OPT#;*)
		Info : MpAxisCamSequencerInfoType; (*Additional information about the component*) (* *) (*#CMD#;*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} MpComInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MpAxisCoupling (*Create simple couplings between axes*) (* $GROUP=mapp,$CAT=Multi Axis,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpAxis1.png *)
	VAR_INPUT
		MpLink : REFERENCE TO MpComIdentType; (*Connection to mapp, slave axis for the coupling*) (* *) (*#PAR#;*)
		Enable : BOOL; (*Enables/Disables the function block*) (* *) (*#PAR#;*)
		ErrorReset : BOOL; (*Resets function block errors*) (* *) (*#PAR#;*)
		Parameters : REFERENCE TO MpAxisCouplingParType; (*Function block parameters*) (* *) (*#PAR#;*)
		Update : BOOL; (*Update command for the parameters*) (* *) (*#PAR#;*)
		MpLinkMaster : REFERENCE TO MpComIdentType; (*Master axis for the coupling*) (* *) (*#PAR#;*)
		Gear : BOOL; (*Starts a linear gear ratio between the master and slave*) (* *) (*#CMD#;*)
		Cam : BOOL; (*Starts a cam profile used by the slave to follow the master*) (* *) (*#CMD#;*)
		Recovery : BOOL; (*Begins to undo all shifts made*) (* *) (*#CMD#OPT#;*)
		OffsetShift : BOOL; (*Starts a phase shift to the slave position (offset)*) (* *) (*#CMD#OPT#;*)
		PhaseShift : BOOL; (*Starts a phase shift to the master position with which the slave is working (phase); the master remains unaffected*) (* *) (*#CMD#OPT#;*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*Indicates whether the function block is active*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates that the function block is in an error state or a command was not executed correctly*) (* *) (*#PAR#;*)
		StatusID : DINT; (*Status information about the function block*) (* *) (*#PAR#;*)
		UpdateDone : BOOL; (*Parameter update completed*) (* *) (*#PAR#;*)
		CommandBusy : BOOL; (*Function block currently executing command*) (* *) (*#CMD#OPT#;*)
		CommandAborted : BOOL; (*Function block interrupted while executing a command*) (* *) (*#CMD#OPT#;*)
		InCompensation : BOOL; (*Axis currently performing a compensating movement*) (* *) (*#CMD#;*)
		InSync : BOOL; (*Slave synchronous with the master*) (* *) (*#CMD#;*)
		RecoveryDone : BOOL; (*Axis in phase with the master*) (* *) (*#CMD#OPT#;*)
		OffsetDone : BOOL; (*Shift to slave position performed successfully (offset)*) (* *) (*#CMD#OPT#;*)
		PhasingDone : BOOL; (*Shift to the master position with which the slave is working performed successfully (phase)*) (* *) (*#CMD#OPT#;*)
		Info : MpAxisCouplingInfoType; (*Additional information about the component*) (* *) (*#CMD#;*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} MpComInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MpAxisCyclicSet (*Controls a single axis via cyclic setpoints*) (* $GROUP=mapp,$CAT=Multi Axis,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpAxis1.png *)
	VAR_INPUT
		MpLink : REFERENCE TO MpComIdentType; (*Connection to mapp*) (* *) (*#PAR#;*)
		Enable : BOOL; (*Enables/Disables the function block*) (* *) (*#PAR#;*)
		ErrorReset : BOOL; (*Resets function block errors*) (* *) (*#PAR#;*)
		Parameters : REFERENCE TO MpAxisCyclicSetParType; (*Function block parameters*) (* *) (*#PAR#;*)
		Update : BOOL; (*Update command for the parameters*) (* *) (*#PAR#;*)
		Position : LREAL; (*Reference to a cyclic position*) (* *) (*#CYC#;*)
		Velocity : LREAL; (*Reference to a cyclic velocity*) (* *) (*#CYC#;*)
		Torque : LREAL; (*Reference to a cyclic torque*) (* *) (*#CYC#;*)
		CyclicPosition : BOOL; (*The axis follows a cyclic position setpoint on a rising edge. This is stopped on a falling edge*) (* *) (*#CMD#;*)
		CyclicVelocity : BOOL; (*The axis follows a cyclic velocity setpoint on a rising edge. This is stopped on a falling edge*) (* *) (*#CMD#;*)
		CyclicTorque : BOOL; (*The axis follows a cyclic torque setpoint on a rising edge. This is stopped on a falling edge*) (* *) (*#CMD#;*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*Indicates whether the function block is active*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates that the function block is in an error state or a command was not executed correctly*) (* *) (*#PAR#;*)
		StatusID : DINT; (*Status information about the function block*) (* *) (*#PAR#;*)
		UpdateDone : BOOL; (*Parameter update completed*) (* *) (*#PAR#;*)
		CommandBusy : BOOL; (*Function block currently executing command*) (* *) (*#CMD#OPT#;*)
		CommandAborted : BOOL; (*Function block interrupted while executing a command*) (* *) (*#CMD#OPT#;*)
		CyclicSetActive : BOOL; (*Axis follows a cyclic signal*) (* *) (*#CMD#;*)
		Info : MpAxisCyclicSetInfoType; (*Additional information about the component*) (* *) (*#CMD#;*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} MpComInternalDataType; (*Internal data*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MpAxisBasicConfig (*Configuration of an axis (I/O points, triggers, limit switches, etc.)*) (* $GROUP=mapp,$CAT=Single Axis,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpAxis.png *)
	VAR_INPUT
		MpLink : REFERENCE TO MpComIdentType; (*Connection to mapp*) (* *) (*#PAR#;*)
		Enable : BOOL; (*Enables/Disables the function block*) (* *) (*#PAR#;*)
		ErrorReset : BOOL; (*Resets function block errors*) (* *) (*#PAR#;*)
		Configuration : REFERENCE TO MpAxisBasicConfigType; (*Structure used to specify the configuration*) (* *) (*#PAR#;*)
		Load : BOOL; (*Loads the configuration of the component*) (* *) (*#CMD#;*)
		Save : BOOL; (*Saves the configuration of the component*) (* *) (*#CMD#;*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*Indicates whether the function block is active*) (* *) (*#PAR#;*)
		Error : BOOL; (*Indicates that the function block is in an error state or a command was not executed correctly*) (* *) (*#PAR#;*)
		StatusID : DINT; (*Status information about the function block*) (* *) (*#PAR#;*)
		CommandBusy : BOOL; (*Function block currently executing command*) (* *) (*#CMD#OPT#;*)
		CommandDone : BOOL; (*Command successfully executed by function block*) (* *) (*#CMD#;*)
		Info : MpAxisInfoType; (*Additional information about the component*) (* *) (*#CMD#;*)
	END_VAR
	VAR
		Internal : {REDUND_UNREPLICABLE} MpComInternalDataType;
	END_VAR
END_FUNCTION_BLOCK
