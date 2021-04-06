
FUNCTION_BLOCK SMC_PAD (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		Enable : {REDUND_UNREPLICABLE} BOOL;
		Power : BOOL;
		Home : BOOL;
		Absolute_Position : LREAL;
		MpAxis : REFERENCE TO MpAxisBasic;
		MpAxisParType : REFERENCE TO MpAxisBasicParType;
		MpAxisCyclic : REFERENCE TO MpAxisCyclicSet;
		MpAxisCyclicParType : REFERENCE TO MpAxisCyclicSetParType;
		Mode : mode_structure;
		Default_parameters : default_param_smcT_str;
		Set_Parameters : parameters_structure_set;
	END_VAR
	VAR_OUTPUT
		Actual_State : SMCTrak_enum;
		PowerOn : BOOL;
		IsHomed : BOOL;
		Actual_Parameters : parameters_structure_actual;
		InPosition : BOOL;
		Active : BOOL;
		Status : DINT;
	END_VAR
	VAR
		Internal : Internal_structure_SMCtrak;
	END_VAR
END_FUNCTION_BLOCK
