
TYPE
	mapp_view_str : 	STRUCT 
		active : BOOL;
		is_homed : BOOL;
		power_on : BOOL;
		cam_obj_id : USINT;
		br_pad_obj_id : ARRAY[0..3]OF USINT;
		smc_pad_obj_id : ARRAY[0..3]OF USINT;
	END_STRUCT;
	object_str : 	STRUCT 
		write : object_w_str;
		read : object_r_str;
	END_STRUCT;
	object_w_str : 	STRUCT 
		set_object_id : USINT;
		reset : BOOL;
		detach : BOOL;
		attach : BOOL;
	END_STRUCT;
	object_r_str : 	STRUCT 
		object_id : USINT;
		object_type : USINT;
	END_STRUCT;
	digT_service_control_str : 	STRUCT 
		power : BOOL;
		home : BOOL;
		start : BOOL;
		actual_state : USINT;
		object : object_str;
		mapp_view : mapp_view_str;
	END_STRUCT;
	digT_control_llinp_str : 	STRUCT 
		pos : LREAL;
		vel : LREAL;
	END_STRUCT;
	digT_control_linp_enum : 
		(
		LINP_CTRL_WAIT_STATE := 0,
		LINP_CTRL_LOAD_PARAM_STATE := 10,
		LINP_CTRL_SET_POSITION_STATE := 11,
		LINP_CTRL_STOP_STATE := 12
		);
	axis_str : 	STRUCT 
		actual_velocity : LREAL;
		actual_position : LREAL;
		actual_state : digT_control_linp_enum;
		parameter : digT_control_llinp_str;
		start : BOOL;
		stop : BOOL;
		active : BOOL;
		power_on : BOOL;
		is_homed : BOOL;
	END_STRUCT;
	camera_conv_str : 	STRUCT 
		X : axis_str;
	END_STRUCT;
	xyz_manip_str : 	STRUCT 
		X : axis_str;
		Y : axis_str;
		Z : axis_str;
	END_STRUCT;
	dt_main_str : 	STRUCT 
		camera : camera_str;
		xyz_manipulator : xyz_manip_str;
		camera_conveyor : camera_conv_str;
		service : digT_service_control_str;
	END_STRUCT;
	camera_str : 	STRUCT 
		scan : BOOL;
	END_STRUCT;
END_TYPE
