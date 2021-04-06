TYPE
	NCDA_DATMO_typ : STRUCT
		name	: ARRAY[0..11] OF USINT ;
		type	: USINT ;
		mem_type	: USINT ;
	END_STRUCT;
	NCDA_MDDIR_typ : STRUCT
		count	: UINT ;
		free_ram	: UDINT ;
		free_prom	: UDINT ;
		data_modul	: ARRAY[0..99] OF NCDA_DATMO_typ ;
	END_STRUCT;
	NCDA_TPREC_typ : STRUCT
		length	: REAL ;
		radius	: REAL ;
		offset	: ARRAY[0..2] OF REAL ;
	END_STRUCT;
	NCDA_TPTAB_typ : STRUCT
		record_cnt	: UINT ;
		startindex	: UINT ;
		record	: ARRAY[0..254] OF NCDA_TPREC_typ ;
	END_STRUCT;
	NCDA_RPTAB_typ : STRUCT
		r_par_cnt	: UINT ;
		startindex	: UINT ;
		r_par	: ARRAY[0..999] OF REAL ;
	END_STRUCT;
	NCDA_ZPREC_typ : STRUCT
		offset	: ARRAY[0..2] OF REAL ;
	END_STRUCT;
	NCDA_ZPTAB_typ : STRUCT
		record_cnt	: UINT ;
		startindex	: UINT ;
		record	: ARRAY[0..199] OF NCDA_ZPREC_typ ;
	END_STRUCT;
	NCGLACT_NCDA_CR_STA_typ : 	STRUCT 
		ok : USINT;
		error : USINT;
		reserved1 : USINT;
		reserved2 : USINT;
		error_number : UDINT;
		ident : UDINT;
		data_adr : UDINT;
	END_STRUCT;
	NCGLACT_NCDA_CR_PAR_typ : 	STRUCT 
		name : ARRAY[0..31]OF USINT;
		version : UINT;
		reserved : UINT;
		type : UINT;
		nc_sw_id : UINT;
		data_len : UDINT;
		data_adr : UDINT;
	END_STRUCT;
	NCGLACT_NCDA_CREATE_typ : 	STRUCT 
		status : NCGLACT_NCDA_CR_STA_typ;
		parameter : NCGLACT_NCDA_CR_PAR_typ;
	END_STRUCT;
	NCGLACT_NCDA_INF_STA_typ : 	STRUCT 
		ok : USINT;
		error : USINT;
		reserved1 : USINT;
		reserved2 : USINT;
		error_number : UDINT;
		ident : UDINT;
		data_len : UDINT;
		data_adr : UDINT;
		version : UINT;
		mem_type : UINT;
		type : UINT;
		nc_sw_id : UINT;
		data_sections : UINT;
		reserved : UINT;
	END_STRUCT;
	NCGLACT_NCDA_INF_PAR_typ : 	STRUCT 
		name : ARRAY[0..31]OF USINT;
		data_section_idx : UINT;
		reserved : UINT;
	END_STRUCT;
	NCGLACT_NCDA_INFO_typ : 	STRUCT
		status : NCGLACT_NCDA_INF_STA_typ;
		parameter : NCGLACT_NCDA_INF_PAR_typ;
	END_STRUCT;
	NCGLACT_NCDA_WR_STA_typ : 	STRUCT 
		ok : USINT;
		error : USINT;
		reserved1 : USINT;
		reserved2 : USINT;
		error_number : UDINT;
	END_STRUCT;
	NCGLACT_NCDA_WR_PAR_typ : 	STRUCT 
		ident : UDINT;
		data_len : UDINT;
		data_adr : UDINT;
		data_offset : UDINT;
	END_STRUCT;
	NCGLACT_NCDA_WRITE_typ : 	STRUCT
		status : NCGLACT_NCDA_WR_STA_typ;
		parameter : NCGLACT_NCDA_WR_PAR_typ;
	END_STRUCT;
	NCGLACT_NCDA_DIR_STA_typ : 	STRUCT 
		ok : USINT;
		error : USINT;
		reserved1 : USINT;
		reserved2 : USINT;
		error_number : UDINT;
		ident : UDINT;
		data_adr : UDINT;
	END_STRUCT;
	NCGLACT_NCDA_DIR_PAR_typ : 	STRUCT 
		name : ARRAY[0..31]OF USINT;
		type : UINT;
		reserved : UINT;
	END_STRUCT;
	NCGLACT_NCDA_DIR_typ : 	STRUCT 
		status : NCGLACT_NCDA_DIR_STA_typ;
		parameter : NCGLACT_NCDA_DIR_PAR_typ;
	END_STRUCT;
END_TYPE
