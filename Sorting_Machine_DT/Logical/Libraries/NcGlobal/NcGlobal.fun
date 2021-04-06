FUNCTION nccnccom : UINT (* CNC-PLC-Communication *)
	VAR_INPUT
		nc_object	:UDINT;
	END_VAR
END_FUNCTION
FUNCTION ncda_dir : UINT (* Create a Directory of NC Data Modules *)
	VAR_INPUT
		mo_typ	:USINT;
		name_p	:UDINT;
		mo_dat_p_p	:UDINT;
		mo_ident_p	:UDINT;
	END_VAR
END_FUNCTION
FUNCTION ncda_inf : UINT (* Determine the Info of an NC Data Module *)
	VAR_INPUT
		mo_ident	:UDINT;
		mo_dat_p_p	:UDINT;
		dat_len_p	:UDINT;
		mem_typ_p	:UDINT;
	END_VAR
END_FUNCTION
FUNCTION ncda_id : UINT (* Determine the Ident of an NC Data Module *)
	VAR_INPUT
		mo_typ	:USINT;
		name_p	:UDINT;
		mo_ident_p	:UDINT;
	END_VAR
END_FUNCTION
FUNCTION ncda_wr : UINT (* Write into an NC Data Module *)
	VAR_INPUT
		mo_ident	:UDINT;
		dat_p	:UDINT;
		dat_len	:UDINT;
		mo_dat_off	:UDINT;
	END_VAR
END_FUNCTION
FUNCTION ncda_cr : UINT (* Create an NC Data Module *)
	VAR_INPUT
		mo_typ	:USINT;
		name_p	:UDINT;
		dat_len	:UDINT;
		dat_p	:UDINT;
		mo_dat_p_p	:UDINT;
		mo_ident_p	:UDINT;
	END_VAR
END_FUNCTION
FUNCTION ncaccess : UINT (* Allocate an NC Object with NC Access Name *)
	VAR_INPUT
		nc_sw_id	:UINT;
		nc_obj_name	:UDINT;
		p_nc_object	:UDINT;
	END_VAR
END_FUNCTION
FUNCTION ncalloc : UINT (* Allocate an NC Object *)
	VAR_INPUT
		bus_typ	:UINT;
		modul_adr	:UINT;
		object_typ	:UINT;
		channel	:UINT;
		object_adr	:UDINT;
	END_VAR
END_FUNCTION
FUNCTION ncaction : UINT (* Call an NC Action *)
	VAR_INPUT
		nc_object	:UDINT;
		subject	:UINT;
		action	:UINT;
	END_VAR
END_FUNCTION
FUNCTION ncglobal_action : UINT (* Global NC Action *)
	VAR_INPUT
		action_id	:UDINT;
		par_struct_adr	:UDINT;
		par_struct_size	:UDINT;
	END_VAR
END_FUNCTION
