
TYPE
	default_param_smcT_str : 	STRUCT 
		MAX_POSITION : LREAL;
		MIN_POSITION : LREAL;
		MAX_VELOCITY : LREAL;
		MIN_VELOCITY : LREAL;
	END_STRUCT;
	param_lim_struct : 	STRUCT 
		velocity : LREAL;
		position_end : LREAL;
		position_start : LREAL;
		mode : limit_sequence_enum;
		time : ARRAY[0..1]OF TIME;
		signal : BOOL;
		signal_inPos : ARRAY[0..1]OF BOOL;
		elapsed_time : ARRAY[0..1]OF TIME;
		time_signal : ARRAY[0..1]OF USINT;
	END_STRUCT;
	parameters_structure_set : 	STRUCT 
		position : LREAL;
		velocity : LREAL;
		limit : param_lim_struct;
		sequence : param_sv_struct;
		MAX_VELOCITY : LREAL := 0;
		MIN_VELOCITY : LREAL := 0;
		MAX_POSITION : LREAL := 0;
		MIN_POSITION : LREAL := 0;
		default_parameters : BOOL;
		set_velocity : LREAL;
		set_position : LREAL;
	END_STRUCT;
	parameters_structure_actual : 	STRUCT 
		position : LREAL;
		velocity : REAL;
		torque : LREAL;
		motorTemperature : LREAL;
		lagError : LREAL;
		profinet_pos : ARRAY[0..5]OF USINT;
		profinet_vel : ARRAY[0..5]OF USINT;
	END_STRUCT;
	param_sv_struct : 	STRUCT 
		position : ARRAY[0..4]OF LREAL;
		velocity : ARRAY[0..4]OF LREAL;
		mode : limit_sequence_enum;
		signal : BOOL;
		time : ARRAY[0..4]OF TIME;
		signal_inPos : ARRAY[0..4]OF BOOL;
		elapsed_time : ARRAY[0..4]OF TIME;
		time_signal : ARRAY[0..4]OF USINT;
	END_STRUCT;
	mode_structure : 	STRUCT 
		manual : instruction_structure_manual;
		automatic : instruction_structure_auto;
		stop : BOOL;
		home : BOOL;
		mode : USINT;
	END_STRUCT;
	SMCTrak_enum : 
		(
		INITIALIZATION_STATE := 0,
		POWER_STATE := 10,
		HOME_STATE_1 := 20,
		HOME_STATE_2 := 21,
		HOME_STATE_3 := 22,
		WAIT_STATE := 30,
		MOVE_HOME_1 := 35,
		MOVE_HOME_2 := 36,
		AUTO_MODE_STATE_RT_1 := 40,
		AUTO_MODE_STATE_RT_2 := 41,
		AUTO_MODE_STATE_RT_3 := 42,
		AUTO_MODE_STATE_UL_1 := 50,
		AUTO_MODE_STATE_UL_2 := 51,
		AUTO_MODE_STATE_UL_3 := 52,
		AUTO_MODE_STATE_SS_1 := 60,
		AUTO_MODE_STATE_SS_2 := 62,
		MANUAL_MODE_STATE_1 := 70,
		MANUAL_MODE_STATE_2 := 71,
		ERROR_STATE_1 := 100,
		ERROR_STATE_2 := 101,
		ERROR_STATE_3 := 102,
		ERROR_STATE_4 := 103,
		ERROR_STATE_5 := 104
		);
	limit_sequence_enum : 
		(
		INSTR_SIGNAL := 0,
		INSTR_TIME := 1
		);
	Internal_structure_SMCtrak : 	STRUCT 
		Before_state : SMCTrak_enum;
		State : SMCTrak_enum;
		Local : internal_local_smctrak;
		Timer : internal_smctrak_timer;
	END_STRUCT;
	internal_smctrak_timer : 	STRUCT 
		enable_time : BOOL;
		output_time : BOOL;
		wait_time : TIME;
		elapsed_time : {REDUND_UNREPLICABLE} TIME;
	END_STRUCT;
	internal_local_smctrak : 	STRUCT 
		set_position : LREAL;
		set_velocity : LREAL;
		before_position : LREAL;
		before_velocity : LREAL;
		sum_position : LREAL;
		sum_velocity : LREAL;
		count_sequence : USINT;
		pos_sequence : LREAL;
	END_STRUCT;
	instruction_structure_manual : 	STRUCT 
		start : BOOL;
	END_STRUCT;
	instruction_structure_auto : 	STRUCT 
		start : BOOL;
		instruction : automatic_instruction_enum;
	END_STRUCT;
	automatic_instruction_enum : 
		(
		INSTR_REAL_TIME := 0,
		INSTR_LOWER_UPPER_LIMIT := 1,
		INSTR_SEQUENCE := 2
		);
END_TYPE
