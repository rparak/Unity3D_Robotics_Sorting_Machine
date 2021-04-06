/* acp10man.h V5.12.2 */ 
/* COPYRIGHT (C) B&R Industrial Automation GmbH */ 

#ifndef ACP10MAN_H_VERSION 
#define ACP10MAN_H_VERSION 0x5122 

#include <ncglobal.h>
#include <acp10par.h>


/*** DATA TYPES *************************************************************/ 

typedef struct ACP10SWVER_typ {               /* SW Version ID [hexadecimal] */
   UINT               nc_manager;             /* NC manager */
   UINT               nc_system;              /* NC operating system */
   USINT              NOT_USE_1[4];
} ACP10SWVER_typ;

typedef struct ACP10OBIHW_typ {               /* Hardware information */
   USINT              init;                   /* Initialized */
   USINT              reserve1;               /* Reserved */
   USINT              acp_id;                 /* ACOPOS ID */
   USINT              acp_id_nr;              /* ACOPOS ID production number */
   USINT              acp_typ;                /* ACOPOS type */
   USINT              ax_num;                 /* Number of axes (power stages) */
   UINT               reserve2;               /* Reserved */
   UDINT              product_code;           /* Product code */
   UDINT              serial_nr;              /* Serial number */
} ACP10OBIHW_typ;

typedef struct ACP10OBINF_typ {               /* NC Object Information */
   UINT               net_if_typ;             /* Network interface type */
   UINT               net_if_idx;             /* Network interface index */
   UINT               node_nr;                /* Drive node number */
   UINT               nc_obj_typ;             /* NC object type */
   UINT               nc_obj_idx;             /* NC object index */
   UINT               reserve;                /* Reserved */
   USINT              nc_obj_name[48];        /* NC object name */
   ACP10OBIHW_typ     hardware;               /* Hardware information */
} ACP10OBINF_typ;

typedef struct ACP10SIMM1_typ {               /* Mass1 */
   REAL               inertia;                /* Mass moment of inertia */
   REAL               static_friction;        /* Static friction */
   REAL               viscous_friction;       /* Viscous friction */
} ACP10SIMM1_typ;

typedef struct ACP10SIMM2_typ {               /* Mass2 */
   REAL               inertia;                /* Mass moment of inertia */
   REAL               static_friction;        /* Static friction */
   REAL               viscous_friction;       /* Viscous friction */
   REAL               stiffness;              /* Stiffness of coupling */
   REAL               damping;                /* Damping of coupling */
} ACP10SIMM2_typ;

typedef struct ACP10SIMGB_typ {               /* Gearbox */
   USINT              direction;              /* Direction */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
   UDINT              in_rev;                 /* Input revolutions */
   UDINT              out_rev;                /* Output revolutions */
} ACP10SIMGB_typ;

typedef struct ACP10SIMPA_typ {               /* Parameters */
   UINT               mode;                   /* Mode */
   UINT               add_load_par_id;        /* Parameter ID for additive load */
   ACP10SIMM1_typ     mass1;                  /* Mass1 */
   ACP10SIMM2_typ     mass2;                  /* Mass2 */
   ACP10SIMGB_typ     gear;                   /* Gearbox */
} ACP10SIMPA_typ;

typedef struct ACP10SIM_typ {                 /* Simulation mode */
   USINT              init;                   /* Initialized */
   USINT              NOT_USE_1;
   USINT              status;                 /* Status */
   USINT              acp_sim;                /* ACOPOS simulation */
   USINT              NOT_USE_2[4];
   ACP10SIMPA_typ     parameter;              /* Parameters */
} ACP10SIM_typ;

typedef struct ACP10GLIPA_typ {               /* INIT Parameters */
   USINT              ok;                     /* Operation complete */
   USINT              error;                  /* Error */
   UINT               reserve;                /* Reserved */
   UDINT              datobj_ident;           /* Data object ident */
   USINT              data_modul[12];         /* Name of the data module */
} ACP10GLIPA_typ;

typedef struct ACP10GLINI_typ {               /* Global Initialization */
   USINT              init;                   /* Global Initialization complete */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
   ACP10GLIPA_typ     init_par;               /* INIT Parameters */
} ACP10GLINI_typ;

typedef struct ACP10NSVRQ_typ {               /* Request (to the drive) */
   UINT               par_id;                 /* Parameter ID */
   UINT               reserve;                /* Reserved */
} ACP10NSVRQ_typ;

typedef struct ACP10NSVRS_typ {               /* Response (from the drive) */
   UINT               par_id;                 /* Parameter ID */
   UINT               reserve;                /* Reserved */
} ACP10NSVRS_typ;

typedef struct ACP10NETSV_typ {               /* Service Interface */
   UDINT              data_adr;               /* Data address */
   USINT              data_text[32];          /* Data in text format */
   ACP10NSVRQ_typ     request;                /* Request (to the drive) */
   ACP10NSVRS_typ     response;               /* Response (from the drive) */
} ACP10NETSV_typ;

typedef struct ACP10NET_typ {                 /* Network */
   USINT              init;                   /* Network initialized */
   USINT              phase;                  /* Phase */
   USINT              init_allowed;           /* The NC action for network initialization is allowed */
   USINT              nc_sys_restart;         /* A Restart of the NC operating system was executed */
   UINT               reserve;                /* Reserved */
   UINT               reserve1;               /* Reserved */
   ACP10NETSV_typ     service;                /* Service Interface */
} ACP10NET_typ;

typedef struct ACP10AXDBS_typ {               /* Status */
   USINT              ok;                     /* Operation complete */
   USINT              error;                  /* Error */
   USINT              reserve1;               /* Reserved */
   USINT              reserve2;               /* Reserved */
   UDINT              data_len;               /* Length of data */
   UDINT              datobj_ident;           /* Data object ident */
   UDINT              datobj_datadr;          /* Address of the data object data */
} ACP10AXDBS_typ;

typedef struct ACP10AXDBP_typ {               /* Parameters */
   USINT              file_device[32];        /* Name of File Device */
   USINT              datobj_name[32];        /* Name of the data object */
   UINT               datobj_type;            /* Type of the data object */
   UINT               datblock_par_id;        /* Parameter ID of the data block */
   UINT               idx1_par_id;            /* Parameter ID of data block index 1 */
   UINT               idx1;                   /* Data block index 1 */
   UINT               idx2_par_id;            /* Parameter ID of data block index 2 */
   UINT               idx2;                   /* Data block index 2 */
   USINT              NOT_USE_1[8];
} ACP10AXDBP_typ;

typedef struct ACP10AXDBL_typ {               /* Data block operation */
   ACP10AXDBS_typ     status;                 /* Status */
   ACP10AXDBP_typ     parameter;              /* Parameters */
} ACP10AXDBL_typ;

typedef struct ACP10DISTA_typ {               /* Status */
   USINT              reference;              /* Reference switch */
   USINT              pos_hw_end;             /* Positive HW end switch */
   USINT              neg_hw_end;             /* Negative HW end switch */
   USINT              trigger1;               /* Trigger1 */
   USINT              trigger2;               /* Trigger2 */
   USINT              enable;                 /* Enable */
   UINT               reserve2;               /* Reserved */
} ACP10DISTA_typ;

typedef struct ACP10DILEV_typ {               /* Active Input Level */
   UINT               reference;              /* Reference switch */
   UINT               pos_hw_end;             /* Positive HW end switch */
   UINT               neg_hw_end;             /* Negative HW end switch */
   UINT               trigger1;               /* Trigger1 */
   UINT               trigger2;               /* Trigger2 */
   UINT               reserve;                /* Reserved */
} ACP10DILEV_typ;

typedef struct ACP10DIFRC_typ {               /* Set Status of digital Inputs via Force function */
   USINT              reference;              /* Reference switch */
   USINT              pos_hw_end;             /* Positive HW end switch */
   USINT              neg_hw_end;             /* Negative HW end switch */
   USINT              trigger1;               /* Trigger1 */
   USINT              trigger2;               /* Trigger2 */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
} ACP10DIFRC_typ;

typedef struct ACP10DIGIN_typ {               /* Digital Inputs */
   USINT              init;                   /* Digital inputs initialized */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
   ACP10DISTA_typ     status;                 /* Status */
   ACP10DILEV_typ     level;                  /* Active Input Level */
   ACP10DIFRC_typ     force;                  /* Set status of digital inputs via force function */
} ACP10DIGIN_typ;

typedef struct ACP10ENCSL_typ {               /* Load */
   UDINT              units;                  /* Units at the load */
   UDINT              rev_motor;              /* Motor revolutions */
} ACP10ENCSL_typ;

typedef struct ACP10ENCSC_typ {               /* Scaling */
   ACP10ENCSL_typ     load;                   /* Load */
} ACP10ENCSC_typ;

typedef struct ACP10ENCPA_typ {               /* Parameters */
   USINT              count_dir;              /* Count direction */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
   ACP10ENCSC_typ     scaling;                /* Scaling */
} ACP10ENCPA_typ;

typedef struct ACP10ENCIF_typ {               /* Encoder Interface */
   USINT              init;                   /* Encoder interface initialized */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
   ACP10ENCPA_typ     parameter;              /* Parameters */
} ACP10ENCIF_typ;

typedef struct ACP10AXLPA_typ {               /* Parameters */
   REAL               v_pos;                  /* Speed in positive direction */
   REAL               v_neg;                  /* Speed in negative direction */
   REAL               a1_pos;                 /* Acceleration in positive direction */
   REAL               a2_pos;                 /* Deceleration in positive direction */
   REAL               a1_neg;                 /* Acceleration in negative direction */
   REAL               a2_neg;                 /* Deceleration in negative direction */
   REAL               t_jolt;                 /* Jolt time */
   REAL               t_in_pos;               /* Settling time before message "In Position" */
   DINT               pos_sw_end;             /* Positive SW end */
   DINT               neg_sw_end;             /* Negative SW end */
   USINT              NOT_USE_1[4];
   REAL               ds_warning;             /* Lag error limit for display of a warning */
   REAL               ds_stop;                /* Lag error limit for stop of a movement */
   REAL               a_stop;                 /* Acceleration limit for stop of a movement */
   REAL               dv_stop;                /* Speed error limit for stop of a movement */
   UDINT              dv_stop_mode;           /* Mode for speed error monitoring */
} ACP10AXLPA_typ;

typedef struct ACP10AXLIM_typ {               /* Limit values */
   USINT              init;                   /* Axis limit values initialized */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
   ACP10AXLPA_typ     parameter;              /* Parameters */
} ACP10AXLIM_typ;

typedef struct ACP10CTRPO_typ {               /* Position controller */
   REAL               kv;                     /* Proportional amplification */
   REAL               tn;                     /* Integral action time */
   REAL               t_predict;              /* Prediction time */
   REAL               t_total;                /* Total time */
   REAL               p_max;                  /* Maximum proportional action */
   REAL               i_max;                  /* Maximum integral action */
} ACP10CTRPO_typ;

typedef struct ACP10ISQFI_typ {               /* ISQ Filter */
   UINT               type;                   /* Type */
   UINT               reserve;                /* Reserved */
   REAL               a0;                     /* Coefficient a0 */
   REAL               a1;                     /* Coefficient a1 */
   REAL               b0;                     /* Coefficient b0 */
   REAL               b1;                     /* Coefficient b1 */
   REAL               b2;                     /* Coefficient b2 */
   UINT               c0_par_id;              /* Parameter ID for coefficient c0 */
   UINT               c1_par_id;              /* Parameter ID for coefficient c1 */
} ACP10ISQFI_typ;

typedef struct ACP10CTRSP_typ {               /* Speed controller */
   REAL               kv;                     /* Proportional amplification */
   REAL               tn;                     /* Integral action time */
   REAL               t_filter;               /* Filter time constant */
   ACP10ISQFI_typ     isq_filter1;            /* ISQ Filter1 */
   ACP10ISQFI_typ     isq_filter2;            /* ISQ Filter2 */
   ACP10ISQFI_typ     isq_filter3;            /* ISQ Filter3 */
} ACP10CTRSP_typ;

typedef struct ACP10CTRUF_typ {               /* U/f Control */
   USINT              type;                   /* Type */
   USINT              auto_config;            /* Automatic configuration */
   UINT               reserve;                /* Reserved */
   REAL               u0;                     /* Boost voltage */
   REAL               un;                     /* Rated voltage */
   REAL               fn;                     /* Rated frequency */
   REAL               k_f_slip;               /* Slip compensation: Multiplication factor of compensated frequency */
} ACP10CTRUF_typ;

typedef struct ACP10CTRFF_typ {               /* Feed Forward Control */
   UINT               mode;                   /* Mode */
   UINT               reserve;                /* Reserved */
   REAL               torque_load;            /* Load torque */
   REAL               torque_pos;             /* Torque in positive direction */
   REAL               torque_neg;             /* Torque in negative direction */
   REAL               kv_torque;              /* Speed torque factor */
   REAL               inertia;                /* Mass moment of inertia */
   REAL               t_filter_a;             /* Acceleration filter time constant */
} ACP10CTRFF_typ;

typedef struct ACP10CTRFB_typ {               /* Feedback Control */
   UINT               mode;                   /* Mode */
   UINT               reserve;                /* Reserved */
   REAL               speed_mix_ratio;        /* Mixing ratio for speed */
   REAL               speed_kv;               /* Proportional amplification for speed */
} ACP10CTRFB_typ;

typedef struct ACP10CTRMODM1_typ {            /* Mass1 */
   REAL               inertia;                /* Mass moment of inertia */
   REAL               viscous_friction;       /* Viscous friction */
} ACP10CTRMODM1_typ;

typedef struct ACP10CTRMODM2_typ {            /* Mass2 */
   REAL               inertia;                /* Mass moment of inertia */
   REAL               viscous_friction;       /* Viscous friction */
   REAL               stiffness;              /* Stiffness of coupling */
   REAL               damping;                /* Damping of coupling */
} ACP10CTRMODM2_typ;

typedef struct ACP10CTRMODEL_typ {            /* Model */
   ACP10CTRMODM1_typ  mass1;                  /* Mass1 */
   ACP10CTRMODM2_typ  mass2;                  /* Mass2 */
} ACP10CTRMODEL_typ;

typedef struct ACP10CTRL_typ {                /* Controller */
   USINT              init;                   /* Controller initialized */
   USINT              ready;                  /* Ready */
   USINT              status;                 /* Status */
   USINT              mode;                   /* Mode */
   ACP10CTRPO_typ     position;               /* Position Controller */
   ACP10CTRSP_typ     speed;                  /* Speed Controller */
   ACP10CTRUF_typ     uf;                     /* U/f Control */
   ACP10CTRFF_typ     ff;                     /* Feed Forward Control */
   ACP10CTRFB_typ     fb;                     /* Feedback Control */
   ACP10CTRMODEL_typ  model;                  /* Model */
} ACP10CTRL_typ;

typedef struct ACP10AXSTI_typ {               /* Index of Parameter Record */
   USINT              command;                /* for the next stop command */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
} ACP10AXSTI_typ;

typedef struct ACP10AXSTP_typ {               /* Parameter Records */
   USINT              decel_ramp;             /* Deceleration ramp */
   USINT              controller;             /* Controller state after movement abortion */
   UINT               reserve;                /* Reserved */
} ACP10AXSTP_typ;

typedef struct ACP10AXSTQ_typ {               /* Quickstop */
   USINT              decel_ramp;             /* Deceleration ramp */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
   REAL               t_jolt;                 /* Jolt time */
} ACP10AXSTQ_typ;

typedef struct ACP10AXSTD_typ {               /* Drive error */
   USINT              decel_ramp;             /* Deceleration ramp */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
} ACP10AXSTD_typ;

typedef struct ACP10AXSTO_typ {               /* Stop Movement */
   USINT              init;                   /* Stop initialized */
   USINT              NOT_USE_1;
   UINT               reserve2;               /* Reserved */
   ACP10AXSTI_typ     index;                  /* Index */
   ACP10AXSTP_typ     parameter[4];           /* Parameter record */
   ACP10AXSTQ_typ     quickstop;              /* Quickstop */
   ACP10AXSTD_typ     drive_error;            /* Drive error */
} ACP10AXSTO_typ;

typedef struct ACP10HOMST_typ {               /* Status */
   USINT              ok;                     /* Reference position valid */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
   REAL               tr_s_rel;               /* Distance between activation of "triggering reference pulse" and the occurrence of the reference pulse */
   DINT               offset;                 /* Home offset after completion of homing procedure */
} ACP10HOMST_typ;

typedef struct ACP10HOMPA_typ {               /* Parameters */
   DINT               s;                      /* Reference position */
   REAL               v_switch;               /* Speed for searching the reference switch */
   REAL               v_trigger;              /* Trigger Speed */
   REAL               a;                      /* Acceleration */
   USINT              mode;                   /* Mode */
   USINT              edge_sw;                /* Edge of reference switch */
   USINT              start_dir;              /* Start direction */
   USINT              trigg_dir;              /* Trigger direction */
   USINT              ref_pulse;              /* Reference pulse */
   USINT              fix_dir;                /* Fixed direction */
   USINT              reserve1;               /* Reserved */
   USINT              reserve2;               /* Reserved */
   REAL               tr_s_block;             /* Distance for blocking the activation of "triggering reference pulse" */
   REAL               torque_lim;             /* Torque limit for homing on block */
   REAL               ds_block;               /* Lag error for block detection */
   REAL               ds_stop;                /* Lag error for stop of a movement */
} ACP10HOMPA_typ;

typedef struct ACP10HOME_typ {                /* Homing */
   USINT              init;                   /* Homing procedure initialized */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
   ACP10HOMST_typ     status;                 /* Status */
   ACP10HOMPA_typ     parameter;              /* Parameters */
} ACP10HOME_typ;

typedef struct ACP10BMVST_typ {               /* Status */
   USINT              in_pos;                 /* "In Position" (target position reached) */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
} ACP10BMVST_typ;

typedef struct ACP10BMVOV_typ {               /* Override */
   UINT               v;                      /* Speed override */
   UINT               a;                      /* Acceleration override */
} ACP10BMVOV_typ;

typedef struct ACP10BMVPA_typ {               /* Parameters */
   DINT               s;                      /* Target position or relative move distance */
   REAL               v_pos;                  /* Speed in positive direction */
   REAL               v_neg;                  /* Speed in negative direction */
   REAL               a1_pos;                 /* Acceleration in positive direction */
   REAL               a2_pos;                 /* Deceleration in positive direction */
   REAL               a1_neg;                 /* Acceleration in negative direction */
   REAL               a2_neg;                 /* Deceleration in negative direction */
} ACP10BMVPA_typ;

typedef struct ACP10TRSTP_typ {               /* Mode "Stop after trigger" */
   USINT              init;                   /* Initialized */
   USINT              event;                  /* Event */
   UINT               reserve;                /* Reserved */
   DINT               s_rest;                 /* Remaining distance after trigger */
   USINT              NOT_USE_1[12];
} ACP10TRSTP_typ;

typedef struct ACP10BAMOV_typ {               /* Basis Movements */
   USINT              init;                   /* Basis movements initialized */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
   ACP10BMVST_typ     status;                 /* Status */
   ACP10BMVOV_typ     override;               /* Override */
   ACP10BMVPA_typ     parameter;              /* Parameters */
   ACP10TRSTP_typ     trg_stop;               /* Mode "Stop after trigger" */
} ACP10BAMOV_typ;

typedef struct ACP10AXMOV_typ {               /* Movement */
   UINT               mode;                   /* Mode */
   UINT               detail;                 /* Detail */
   ACP10AXSTO_typ     stop;                   /* Stop Movement */
   ACP10HOME_typ      homing;                 /* Homing procedure */
   ACP10BAMOV_typ     basis;                  /* Basis movements */
} ACP10AXMOV_typ;

typedef struct ACP10SUOST_typ {               /* Status */
   UDINT              ident;                  /* Ident of data object */
   USINT              ok;                     /* Operation complete */
   USINT              error;                  /* Error */
   USINT              reserve1;               /* Reserved */
   USINT              reserve2;               /* Reserved */
} ACP10SUOST_typ;

typedef struct ACP10SUOPA_typ {               /* Parameters */
   USINT              name[12];               /* Name of data object */
} ACP10SUOPA_typ;

typedef struct ACP10SUOBJ_typ {               /* Data object */
   ACP10SUOST_typ     status;                 /* Status */
   ACP10SUOPA_typ     parameter;              /* Parameters */
} ACP10SUOBJ_typ;

typedef struct ACP10SUMAS_typ {               /* Status */
   UINT               mode;                   /* Mode */
   USINT              ok;                     /* Operation complete */
   USINT              error;                  /* Error */
   REAL               quality;                /* Quality of parameter identification */
} ACP10SUMAS_typ;

typedef struct ACP10SUMAO_typ {               /* Optional parameters */
   USINT              z_p;                    /* Number of polepairs */
   USINT              phase;                  /* Phase */
   UINT               reserve2;               /* Reserved */
   REAL               u_const;                /* Voltage constant */
   REAL               v_max;                  /* Maximum speed */
   REAL               trq_0;                  /* Stall  torque */
   REAL               trq_n;                  /* Rated torque */
   REAL               trq_max;                /* Peak  torque */
   REAL               trq_const;              /* Torque constant */
   REAL               i_0;                    /* Stall current */
   REAL               i_max;                  /* Peak current */
   REAL               i_m;                    /* Magnetizing current */
   REAL               phase_cross_sect ;      /* Cross section of a phase */
   REAL               invcl_a1;               /* Inverter characteristic: Gain factor */
   REAL               invcl_a2;               /* Inverter characteristic: Exponent */
} ACP10SUMAO_typ;

typedef struct ACP10SUMAP_typ {               /* Parameters */
   UINT               mode;                   /* Mode */
   UINT               reserve;                /* Reserved */
   REAL               u_n;                    /* Rated voltage */
   REAL               i_n;                    /* Rated current */
   REAL               v_n;                    /* Rated speed */
   REAL               f_n;                    /* Rated frequency */
   REAL               cos_phi;                /* Active power factor */
   REAL               t_tripping_therm;       /* Tripping time at thermal overload */
   ACP10SUMAO_typ     optional;               /* Optional parameters */
} ACP10SUMAP_typ;

typedef struct ACP10SUMA_typ {                /* Induction motor */
   ACP10SUMAS_typ     status;                 /* Status */
   ACP10SUMAP_typ     parameter;              /* Parameters */
} ACP10SUMA_typ;

typedef struct ACP10SUMSS_typ {               /* Status */
   UINT               mode;                   /* Mode */
   USINT              ok;                     /* Operation complete */
   USINT              error;                  /* Error */
   REAL               quality;                /* Quality of parameter identification */
} ACP10SUMSS_typ;

typedef struct ACP10SUMSO_typ {               /* Optional parameters */
   USINT              phase;                  /* Phase */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
   REAL               u_const;                /* Voltage constant */
   REAL               v_max;                  /* Maximum speed */
   REAL               trq_0;                  /* Stall  torque */
   REAL               trq_const;              /* Torque constant */
   REAL               i_0;                    /* Stall current */
   REAL               phase_cross_sect ;      /* Cross section of a phase */
   REAL               invcl_a1;               /* Inverter characteristic: Gain factor */
   REAL               invcl_a2;               /* Inverter characteristic: Exponent */
} ACP10SUMSO_typ;

typedef struct ACP10SUMSP_typ {               /* Parameters */
   UINT               mode;                   /* Mode */
   USINT              z_p;                    /* Number of polepairs */
   USINT              reserve;                /* Reserved */
   REAL               u_n;                    /* Rated voltage */
   REAL               i_n;                    /* Rated current */
   REAL               v_n;                    /* Rated speed */
   REAL               trq_n;                  /* Rated torque */
   REAL               trq_max;                /* Peak  torque */
   REAL               i_max;                  /* Peak current */
   REAL               t_tripping_therm;       /* Tripping time at thermal overload */
   ACP10SUMSO_typ     optional;               /* Optional parameters */
} ACP10SUMSP_typ;

typedef struct ACP10SUMS_typ {                /* Synchronous motor */
   ACP10SUMSS_typ     status;                 /* Status */
   ACP10SUMSP_typ     parameter;              /* Parameters */
} ACP10SUMS_typ;

typedef struct ACP10SUPHS_typ {               /* Status */
   UINT               mode;                   /* Mode */
   USINT              ok;                     /* Operation complete */
   USINT              error;                  /* Error */
   REAL               rho_0;                  /* Commutation offset */
   USINT              z_p;                    /* Number of polepairs */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
} ACP10SUPHS_typ;

typedef struct ACP10SUPHP_typ {               /* Parameters */
   UINT               mode;                   /* Mode */
   UINT               reserve;                /* Reserved */
   REAL               i;                      /* Current */
   REAL               t;                      /* Time */
} ACP10SUPHP_typ;

typedef struct ACP10SUPH_typ {                /* Motor phasing */
   ACP10SUPHS_typ     status;                 /* Status */
   ACP10SUPHP_typ     parameter;              /* Parameters */
} ACP10SUPH_typ;

typedef struct ACP10SUCST_typ {               /* Status */
   UINT               mode;                   /* Mode */
   USINT              ok;                     /* Operation complete */
   USINT              error;                  /* Error */
} ACP10SUCST_typ;

typedef struct ACP10SUCPA_typ {               /* Parameters */
   UINT               mode;                   /* Mode */
   USINT              orientation;            /* Orientation */
   USINT              operating_point;        /* Operating point */
   REAL               i_max_percent;          /* Maximum percentage for rated current */
   REAL               v_max_percent;          /* Maximum percentage for speed limit value */
   DINT               s_max;                  /* Maximum move distance */
   REAL               ds_max;                 /* Maximum lag error */
   REAL               kv_percent;             /* Percentage for proportional amplification */
   UDINT              signal_order;           /* Order of excitation signal */
   REAL               kv_max;                 /* Maximum proportional amplification */
   REAL               a;                      /* Acceleration */
   UINT               signal_type;            /* Type of the excitation signal */
   UINT               reserve;                /* Reserved */
   REAL               signal_f_start;         /* Start frequency of the excitation signal */
   REAL               signal_f_stop;          /* Stop frequency of the excitation signal */
   REAL               signal_time;            /* Duration of the excitation signal */
} ACP10SUCPA_typ;

typedef struct ACP10SUCTR_typ {               /* Controller */
   ACP10SUCST_typ     status;                 /* Status */
   ACP10SUCPA_typ     parameter;              /* Parameters */
} ACP10SUCTR_typ;

typedef struct ACP10SUIRS_typ {               /* Status */
   UINT               mode;                   /* Mode */
   USINT              ok;                     /* Operation complete */
   USINT              error;                  /* Error */
   REAL               quality;                /* Quality of parameter identification */
} ACP10SUIRS_typ;

typedef struct ACP10SUIRP_typ {               /* Parameters */
   UINT               mode;                   /* Mode */
   USINT              reserve;                /* Reserved */
   USINT              ref_system;             /* Reference system */
   REAL               pos_offset;             /* Position offset */
   REAL               v;                      /* Speed */
} ACP10SUIRP_typ;

typedef struct ACP10SUIR_typ {                /* ISQ-Ripple */
   ACP10SUIRS_typ     status;                 /* Status */
   ACP10SUIRP_typ     parameter;              /* Parameters */
} ACP10SUIR_typ;

typedef struct ACP10SUMOVST_typ {             /* Status */
   UINT               mode;                   /* Mode */
   USINT              ok;                     /* Operation complete */
   USINT              error;                  /* Error */
} ACP10SUMOVST_typ;

typedef struct ACP10SUMOPA_typ {              /* Parameters */
   UINT               mode;                   /* Mode */
   USINT              start_dir;              /* Start direction */
   USINT              fix_dir;                /* Fixed direction */
   DINT               s_max;                  /* Maximum move distance */
} ACP10SUMOPA_typ;

typedef struct ACP10SUMOV_typ {               /* Movement */
   ACP10SUMOVST_typ   status;                 /* Status */
   ACP10SUMOPA_typ    parameter;              /* Parameters */
} ACP10SUMOV_typ;

typedef struct ACP10SETUP_typ {               /* Setup */
   USINT              status;                 /* Status */
   USINT              active;                 /* Active */
   UINT               detail;                 /* Detail */
   ACP10SUOBJ_typ     datobj;                 /* Data object */
   ACP10SUMA_typ      motor_induction;        /* Induction motor */
   ACP10SUMS_typ      motor_synchron;         /* Synchronous motor */
   ACP10SUPH_typ      motor_phasing;          /* Motor phasing */
   ACP10SUCTR_typ     controller;             /* Controller */
   ACP10SUIR_typ      isq_ripple;             /* ISQ-Ripple */
   ACP10SUMOV_typ     move;                   /* Movement */
} ACP10SETUP_typ;

typedef struct ACP10AXMOS_typ {               /* Status Bits */
   USINT              error;                  /* Error occurred */
   USINT              warning;                /* Warning occurred */
   USINT              ds_warning;             /* Lag error limit for display of a warning */
   USINT              reserve;                /* Reserved */
} ACP10AXMOS_typ;

typedef struct ACP10AXMON_typ {               /* Monitor */
   DINT               s;                      /* Position */
   REAL               v;                      /* Velocity */
   ACP10AXMOS_typ     status;                 /* Status bits */
} ACP10AXMON_typ;

typedef struct ACP10MSCNT_typ {               /* Number of not acknowledged messages */
   USINT              error;                  /* Count of not acknowledged errors */
   USINT              warning;                /* Count of not acknowledged warnings */
   USINT              mc_fb_error;            /* Count of not acknowledged PLCopen MC FB errors */
   USINT              reserve;                /* Reserved */
} ACP10MSCNT_typ;

typedef struct ACP10MSREC_typ {               /* Current message record */
   UINT               par_id;                 /* Parameter ID */
   UINT               number;                 /* Error number */
   UDINT              info;                   /* Additional Info */
} ACP10MSREC_typ;

typedef struct ACP10MTXST_typ {               /* Status of text determination */
   UINT               lines;                  /* Lines of the determined text */
   UINT               error;                  /* Error */
} ACP10MTXST_typ;

typedef struct ACP10MTXPA_typ {               /* Parameters for text determination */
   UINT               format;                 /* Format */
   UINT               columns;                /* Number of columns per line */
   USINT              data_modul[12];         /* Name of the data module */
   UINT               data_len;               /* Length of data buffer in application program */
   UINT               reserve;                /* Reserved */
   UDINT              data_adr;               /* Data address */
   UDINT              record_adr;             /* Address of message record in application program */
} ACP10MTXPA_typ;

typedef struct ACP10MSTXT_typ {               /* Text determination for current message record */
   ACP10MTXST_typ     status;                 /* Status */
   ACP10MTXPA_typ     parameter;              /* Parameters */
} ACP10MSTXT_typ;

typedef struct ACP10MSCMDERR_typ {            /* Command: Execute error reaction */
   UINT               type;                   /* Type */
   USINT              ok;                     /* Operation complete */
   USINT              error;                  /* Error */
} ACP10MSCMDERR_typ;

typedef struct ACP10MSG_typ {                 /* Messages */
   ACP10MSCNT_typ     count;                  /* Count of not acknowledged messages */
   ACP10MSREC_typ     record;                 /* Error record */
   ACP10MSTXT_typ     text;                   /* Text determination for current message record */
   ACP10MSCMDERR_typ  cmd_error;              /* Command: Execute error reaction */
} ACP10MSG_typ;

typedef struct ACP10NCTST_typ {               /* NC Test */
   USINT              Open_UseApplNcObj;      /* Open test: Use the same NC object as the application */
   USINT              Close_NoMoveAbort;      /* Close test: No move abortion */
   USINT              reserve1;               /* Reserved */
   USINT              reserve2;               /* Reserved */
} ACP10NCTST_typ;

typedef struct ACP10AXIS_typ {                /* ACP10 - Real Axis */
   USINT              NOT_USE_1[4];
   UINT               size;                   /* Size of the corresponding NC manager data type */
   USINT              NOT_USE_2[2];
   ACP10SWVER_typ     sw_version;             /* SW Version ID [hexadecimal] */
   ACP10OBINF_typ     nc_obj_inf;             /* NC Object Information */
   ACP10SIM_typ       simulation;             /* Simulation Mode */
   ACP10GLINI_typ     global;                 /* Global Parameters */
   ACP10NET_typ       network;                /* Network */
   ACP10AXDBL_typ     datblock;               /* Data block operation */
   ACP10DIGIN_typ     dig_in;                 /* Digital Inputs */
   ACP10ENCIF_typ     encoder_if;             /* Encoder Interface */
   ACP10AXLIM_typ     limit;                  /* Limit value */
   ACP10CTRL_typ      controller;             /* Controller */
   ACP10AXMOV_typ     move;                   /* Movement */
   ACP10SETUP_typ     setup;                  /* Setup */
   ACP10AXMON_typ     monitor;                /* Monitor */
   ACP10MSG_typ       message;                /* Messages (errors, warnings) */
   ACP10NCTST_typ     nc_test;                /* NC Test */
   USINT              NOT_USE_3[60];
} ACP10AXIS_typ;

typedef struct ACP10MONET_typ {               /* Network */
   USINT              init;                   /* Initialized */
   USINT              phase;                  /* Phase */
   UINT               reserve;                /* Reserved */
} ACP10MONET_typ;

typedef struct ACP10TRCTR_typ {               /* Trigger */
   UINT               par_id;                 /* Parameter ID */
   USINT              event;                  /* Event */
   USINT              reserve;                /* Reserved */
   REAL               threshold;              /* Threshold */
   REAL               window;                 /* Window */
} ACP10TRCTR_typ;

typedef struct ACP10TRCDA_typ {               /* Test data */
   UINT               par_id;                 /* Parameter ID */
} ACP10TRCDA_typ;

typedef struct ACP10TRCSV_typ {               /* Operating System Variable */
   USINT              data_type;              /* Data type */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
   UDINT              address;                /* Address */
} ACP10TRCSV_typ;

typedef struct ACP10TRCSY_typ {               /* Configuration of Operating System Variables */
   ACP10TRCSV_typ     trigger;                /* Trigger */
   ACP10TRCSV_typ     test_dat[10];           /* Test data */
} ACP10TRCSY_typ;

typedef struct ACP10TRC_typ {                 /* Trace */
   USINT              status;                 /* Status */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
   UDINT              buf_size;               /* Size of trace data buffer on the drive */
   USINT              NOT_USE_1[4];
   REAL               t_trace;                /* Recording time */
   REAL               t_sampling;             /* Sampling time */
   REAL               t_delay;                /* Start delay */
   ACP10TRCTR_typ     trigger;                /* Trigger */
   ACP10TRCDA_typ     test_dat[10];           /* Test data */
   ACP10TRCSY_typ     system_var;             /* Configuration of Operating System Variables */
} ACP10TRC_typ;

typedef struct ACP10MODUL_typ {               /* ACP10 - NC Module */
   USINT              NOT_USE_1[4];
   UINT               size;                   /* Size of the corresponding NC manager data type */
   UINT               reserve;                /* Reserved */
   ACP10SWVER_typ     sw_version;             /* SW Version ID [hexadecimal] */
   ACP10OBINF_typ     nc_obj_inf;             /* NC Object Information */
   ACP10MONET_typ     network;                /* Network */
   ACP10TRC_typ       trace;                  /* Trace */
   ACP10MSG_typ       message;                /* Messages (errors, warnings) */
   USINT              NOT_USE_2[48];
} ACP10MODUL_typ;

typedef struct ACP10SWVMA_typ {               /* SW-Version (only NC Manager) */
   UINT               nc_manager;             /* NC manager */
   UINT               reserve;                /* Reserved */
   UINT               reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
} ACP10SWVMA_typ;

typedef struct ACP10MTRTR_typ {               /* Trigger */
   UDINT              nc_object;              /* NC object or ncOFF */
   UINT               par_id;                 /* Parameter ID */
   USINT              event;                  /* Event */
   USINT              reserve;                /* Reserved */
   REAL               threshold;              /* Threshold */
   REAL               window;                 /* Latch window */
} ACP10MTRTR_typ;

typedef struct ACP10MTRDA_typ {               /* Test data */
   UDINT              nc_object;              /* NC object or ncOFF */
   UINT               par_id;                 /* Parameter ID */
   UINT               reserve;                /* Reserved */
} ACP10MTRDA_typ;

typedef struct ACP10TROST_typ {               /* Status */
   UDINT              ident;                  /* Ident of data object */
   USINT              ok;                     /* Operation complete */
   USINT              error;                  /* Error */
   USINT              reserve1;               /* Reserved */
   USINT              reserve2;               /* Reserved */
} ACP10TROST_typ;

typedef struct ACP10TROPA_typ {               /* Parameters */
   USINT              name[32];               /* Name of data object */
   USINT              file_device[32];        /* Name of File Device */
   UINT               type;                   /* Type */
   UINT               format;                 /* Format */
} ACP10TROPA_typ;

typedef struct ACP10TROBJ_typ {               /* Data object */
   ACP10TROST_typ     status;                 /* Status */
   ACP10TROPA_typ     parameter;              /* Parameters */
} ACP10TROBJ_typ;

typedef struct ACP10MTR_typ {                 /* Trace */
   USINT              status;                 /* Status */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
   REAL               t_trace;                /* Recording time */
   REAL               t_sampling;             /* Sampling time */
   REAL               t_delay;                /* Start delay */
   REAL               t_add_net_trigger;      /* Start delay: Value to be added for network trigger */
   ACP10MTRTR_typ     trigger;                /* Trigger */
   ACP10MTRDA_typ     test_dat[100];          /* Test data */
   ACP10TROBJ_typ     datobj;                 /* Data object */
} ACP10MTR_typ;

typedef struct ACP10MUTRC_typ {               /* ACP10 - Multi Axes Trace */
   USINT              NOT_USE_1[4];
   UINT               size;                   /* Size of the corresponding NC manager data type */
   UINT               reserve;                /* Reserved */
   ACP10SWVMA_typ     sw_version;             /* SW Version ID [hexadecimal] */
   ACP10OBINF_typ     nc_obj_inf;             /* NC Object Information */
   ACP10MTR_typ       trace;                  /* Trace */
   ACP10MSG_typ       message;                /* Messages (errors, warnings) */
   USINT              NOT_USE_2[48];
} ACP10MUTRC_typ;

typedef struct ACP10PCYUT_typ {               /* Cyclic User Data to the Drive */
   USINT              cnt;                    /* Counter */
   USINT              reserve1;               /* Reserved */
   USINT              data[18];               /* Parameter Data */
} ACP10PCYUT_typ;

typedef struct ACP10PCYUF_typ {               /* Cyclic User Data from the Drive */
   USINT              cnt;                    /* Counter */
   USINT              reserve1;               /* Reserved */
   USINT              data[18];               /* Parameter Data */
} ACP10PCYUF_typ;

typedef struct ACP10PLCUS_typ {               /* ACP10 - Cyclic User Data for Powerlink */
   ACP10PCYUT_typ     to_drv;                 /* Cyclic User Data to the Drive */
   ACP10PCYUF_typ     fr_drv;                 /* Cyclic User Data from  the Drive */
} ACP10PLCUS_typ;

typedef struct ACP10DBLST_typ {               /* Status */
   UDINT              data_len;               /* Length of data */
   USINT              init;                   /* Data block initialized */
   USINT              ok;                     /* Operation complete */
   USINT              error;                  /* Error */
   USINT              stop;                   /* Stop */
   UDINT              datobj_ident;           /* Data object ident */
} ACP10DBLST_typ;

typedef struct ACP10DBLPA_typ {               /* Parameters */
   UDINT              data_len;               /* Length of data */
   UDINT              data_adr;               /* Data address */
   USINT              data_modul[12];         /* Name of the data module */
   UINT               index;                  /* Index */
   UINT               mode;                   /* Mode */
   UINT               format;                 /* Format */
   UINT               reserve;                /* Reserved */
} ACP10DBLPA_typ;

typedef struct ACP10DATBL_typ {               /* Data block operation */
   ACP10DBLST_typ     status;                 /* Status */
   ACP10DBLPA_typ     parameter;              /* Parameters */
} ACP10DATBL_typ;

typedef struct ACP10PRADR_typ {               /* Parameter record for format "ncFORMAT_ADR" */
   UINT               par_id;                 /* Parameter ID */
   UINT               reserve;                /* Reserved */
   UDINT              data_adr;               /* Data address */
} ACP10PRADR_typ;

typedef struct ACP10PRB06_typ {               /* Parameter record for format "ncFORMAT_B06" */
   UINT               par_id;                 /* Parameter ID */
   UINT               reserve1;               /* Reserved */
   USINT              data_byte[6];           /* Data bytes */
   UINT               reserve2;               /* Reserved */
} ACP10PRB06_typ;

typedef struct ACP10PRT10_typ {               /* Parameter record for format "ncFORMAT_T10" */
   UINT               par_id;                 /* Parameter ID */
   USINT              data_text[10];          /* Data in text format */
} ACP10PRT10_typ;

typedef struct ACP10PRT14_typ {               /* Parameter record for format "ncFORMAT_T14" */
   UINT               par_id;                 /* Parameter ID */
   USINT              data_text[14];          /* Data in text format */
} ACP10PRT14_typ;

typedef struct ACP10PRECS_typ {               /* Parameter records */
   ACP10PRADR_typ     format_adr;             /* Parameter record for format "ncFORMAT_ADR" */
   ACP10PRB06_typ     format_b06;             /* Parameter record for format "ncFORMAT_B06" */
   ACP10PRT10_typ     format_t10;             /* Parameter record for format "ncFORMAT_T10" */
   ACP10PRT14_typ     format_t14;             /* Parameter record for format "ncFORMAT_T14" */
} ACP10PRECS_typ;

typedef struct ACP10UCROP_typ {               /* Operate Read COB */
   UDINT              can_obj;                /* CAN Object (COB handle) from CAN_defineCOB() */
   UINT               can_id;                 /* CAN-ID */
   USINT              handshake;              /* Handshake */
   USINT              reserve;                /* Reserved */
   USINT              data[8];                /* Data */
} ACP10UCROP_typ;

typedef struct ACP10NGLNW_typ {               /* Network */
   USINT              enable;                 /* Enable */
   USINT              phase;                  /* Phase */
   USINT              init;                   /* Initialized */
   USINT              reserve;                /* Reserved */
} ACP10NGLNW_typ;

typedef struct ACP10NGNTR_typ {               /* Network Trace */
   USINT              status;                 /* Status */
   USINT              reset;                  /* Reset active */
   USINT              ring_startidx_auto;     /* The start index of the ring buffer was saved automatically */
   USINT              ring_startidx_action;   /* The start index of the ring buffer was saved via NC action */
   ACP10TROBJ_typ     datobj;                 /* Data object */
   USINT              NOT_USE_1[8];
} ACP10NGNTR_typ;

typedef struct ACP10NETGL_typ {               /* Network global (for all network interfaces) */
   USINT              NOT_USE_1[4];
   UINT               size;                   /* Size of the corresponding NC manager data type */
   UINT               reserve;                /* Reserved */
   ACP10SWVMA_typ     sw_version;             /* SW Version ID [hexadecimal] */
   ACP10OBINF_typ     nc_obj_inf;             /* NC Object Information */
   ACP10NGLNW_typ     network;                /* Network */
   ACP10NGNTR_typ     net_trace;              /* Network Trace */
   ACP10MSG_typ       message;                /* Messages (errors, warnings) */
} ACP10NETGL_typ;

typedef struct ACP10DAMST_typ {               /* Status */
   UDINT              datobj_ident;           /* Data object ident */
   USINT              ok;                     /* Operation complete */
   USINT              error;                  /* Error */
   USINT              reserve1;               /* Reserved */
   USINT              reserve2;               /* Reserved */
   ACP10MSREC_typ     error_record;           /* Error record */
} ACP10DAMST_typ;

typedef struct ACP10DAMPA_typ {               /* Parameters */
   USINT              name[32];               /* Name of the NC data module */
   UINT               type;                   /* Type */
   UINT               reserve;                /* Reserved */
   UINT               nc_sw_id;               /* NC Software ID */
   UINT               version;                /* Version */
   UDINT              data_len;               /* Length of data buffer in application program */
   UDINT              data_adr;               /* Address of data buffer in application program */
} ACP10DAMPA_typ;

typedef struct ACP10DATMO_typ {               /* NC data module */
   ACP10DAMST_typ     status;                 /* Status */
   ACP10DAMPA_typ     parameter;              /* Parameters */
} ACP10DATMO_typ;

typedef struct ACP10SMCCFGOUTDA_typ {         /* SafeMC configuration: SafeOUT data */
   USINT              data_byte[4];           /* Data bytes */
} ACP10SMCCFGOUTDA_typ;

typedef struct ACP10SMCCFGPLCE_typ {          /* SafeMC configuration: Powerlink Copy Entry */
   USINT              node_nr;                /* Node number */
   USINT              direction_id;           /* Direction ID */
   SINT               direction_char;         /* Direction character */
   USINT              reserve1;               /* Reserved */
   UDINT              ident;                  /* ident */
} ACP10SMCCFGPLCE_typ;

typedef struct ACP10SMCCFGOUT_typ {           /* SafeMC configuration: SafeOUT data structure */
   USINT                init_ok;              /* Initialization OK */
   USINT                net_dat_typ;          /* Type of network data */
   UINT                 init_error;           /* Initialization error */
   ACP10SMCCFGOUTDA_typ data;                 /* Data */
   UINT                 data_len;             /* Data length */
   UINT                 data_offset;          /* Data offset */
   UINT                 frame_len;            /* Frame length */
   UINT                 frame_offset;         /* Frame offset */
   ACP10SMCCFGPLCE_typ  plCE;                 /* POWERLINK Copy Entry */
} ACP10SMCCFGOUT_typ;

typedef struct ACP10SMCCFGINDA_typ {          /* SafeMC configuration: SafeIN data */
   USINT              data_byte[12];          /* Data bytes */
} ACP10SMCCFGINDA_typ;

typedef struct ACP10SMCCFGIN_typ {            /* SafeMC configuration: SafeIN data structure */
   USINT               init_ok;               /* Initialization OK */
   USINT               net_dat_typ;           /* Type of network data */
   UINT                init_error;            /* Initialization error */
   ACP10SMCCFGINDA_typ data;                  /* Data */
   UINT                data_len;              /* Data length */
   UINT                data_offset;           /* Data offset */
   UINT                frame_len;             /* Frame length */
   UINT                frame_offset;          /* Frame offset */
   ACP10SMCCFGPLCE_typ plCE;                  /* POWERLINK Copy Entry */
} ACP10SMCCFGIN_typ;

typedef struct ACP10SMCCFG_typ {              /* SafeMC configuration */
   USINT              nc_obj_name[48];        /* NC object name */
   ACP10SMCCFGOUT_typ SafeOUT;                /* SafeOUT data structure */
   ACP10SMCCFGIN_typ  SafeIN;                 /* SafeIN data structure */
} ACP10SMCCFG_typ;

typedef struct ACP10SAFEINDAT_typ {           /* SafeMC: SafeIN data */
   USINT              SafetyActiveSTO;        /* STO status bit */
   USINT              SafetyActiveSBC;        /* SBC status bit */
   USINT              SafetyActiveSOS;        /* SOS status bit */
   USINT              SafetyActiveSS1;        /* SS1 status bit */
   USINT              SafetyActiveSS2;        /* SS2 status bit */
   USINT              SafetyActiveSLS1;       /* SLS1 status bit */
   USINT              SafetyActiveSLS2;       /* SLS2 status bit */
   USINT              SafetyActiveSLS3;       /* SLS3 status bit */
   USINT              SafetyActiveSLS4;       /* SLS4 status bit */
   USINT              SafetyActiveSTO1;       /* STO1 status bit */
   USINT              SafetyActiveSDIpos;     /* SDIpos status bit */
   USINT              SafetyActiveSLI;        /* SLI status bit */
   USINT              SafetyActiveSDIneg;     /* SDIneg status bit */
   USINT              SafetyActiveSLP;        /* SLP status bit */
   USINT              SafetyActiveSMP;        /* SMP status bit */
   USINT              SafePositionValid;      /* SafePosition is valid */
   USINT              SafetyActiveSLA;        /* SLA status bit */
   USINT              StatusSetPosAlive;      /* Setposition is tested */
   USINT              StatusSFR;              /* At least one safety function is requested */
   USINT              AllReqFuncAct;          /* All requested safety functions are active */
   USINT              SafetyActiveSDC;        /* Deceleration monitoring status bit */
   USINT              Operational;            /* Function block is in state operational */
   USINT              NotErrENC;              /* Encoder error status bit */
   USINT              NotErrFUNC;             /* Functional Fail Safe status bit */
   USINT              SafetyActiveSBT;        /* SBT is active */
   USINT              SafetyStatusSBT;        /* SBT status bit */
   USINT              RSPValid;               /* RSP Valid bit */
   USINT              ReqHomingOK;            /* Request Homing OK bit */
   USINT              reserved_stat_b28;      /* reserved_stat_b28 */
   USINT              reserved_stat_b29;      /* reserved_stat_b29 */
   USINT              reserved_stat_b30;      /* reserved_stat_b30 */
   USINT              reserved_stat_b31;      /* reserved_stat_b31 */
   INT                ScaledSpeed;            /* Scaled safe speed */
   USINT              reserve1;               /* Reserved */
   USINT              reserve2;               /* Reserved */
   DINT               SafePosition;           /* Safe position */
} ACP10SAFEINDAT_typ;

typedef struct ACP10SAFEINDAT2_typ {          /* SafeMC: SafeIN data2 */
   USINT              NotErrFUNC;             /* Functional Fail Safe status bit */
   USINT              Operational;            /* Function block is in state operational */
   USINT              SafetyActiveSTO;        /* STO status bit */
   USINT              SafetyActiveSBC;        /* SBC status bit */
   USINT              SafetyActiveSS1;        /* SS1 status bit */
   USINT              NotErrENC;              /* Encoder error status bit */
   USINT              SafetyActiveSTO1;       /* STO1 status bit */
   USINT              SafetyActiveSDC;        /* Deceleration monitoring status bit */
   USINT              SafetyActiveSOS;        /* SOS status bit */
   USINT              SafetyActiveSS2;        /* SS2 status bit */
   USINT              SafetyActiveSLA;        /* SLA status bit */
   USINT              SafetyActiveSLS1;       /* SLS1 status bit */
   USINT              SafetyActiveSLS2;       /* SLS2 status bit */
   USINT              reserved_stat_b13;      /* reserved_stat_b13 */
   USINT              SafetyActiveSLS3;       /* SLS3 status bit */
   USINT              SafetyActiveSLS4;       /* SLS4 status bit */
   USINT              SafetyActiveSDIpos;     /* SDIpos status bit */
   USINT              SafetyActiveSDIneg;     /* SDIneg status bit */
   USINT              SafetyActiveSLI;        /* SLI status bit */
   USINT              SafetyStatusSBT;        /* SBT status bit */
   USINT              SafetyActiveSBT;        /* SBT is active */
   USINT              SafetyActiveSLT;        /* SLT status bit */
   USINT              StatusSFR;              /* At least one safety function is requested */
   USINT              AllReqFuncAct;          /* All requested safety functions are active */
   USINT              NotErrENC2;             /* Encoder error status bit2 */
   USINT              SafePositionValid;      /* SafePosition is valid */
   USINT              ReqHomingOK;            /* Request Homing OK bit */
   USINT              SafetyActiveSLP;        /* SLP status bit */
   USINT              SafetyActiveSMP;        /* SMP status bit */
   USINT              reserved_stat_b29;      /* reserved_stat_b29 */
   USINT              RSPValid;               /* RSP Valid bit */
   USINT              StatusSetPosAlive;      /* Setposition is tested */
   DINT               SafePosition;           /* Safe position */
   INT                ScaledSpeed;            /* Scaled safe speed */
   UINT               reserve1;               /* Reserved */
   UDINT              reserve2;               /* Reserved */
} ACP10SAFEINDAT2_typ;

typedef struct ACP10SAFEINDAT3_typ {          /* SafeMC: SafeIN data3 */
   USINT              NotErrFUNC;             /* Functional Fail Safe status bit */
   USINT              Operational;            /* Function block is in state operational */
   USINT              SafetyActiveSTO;        /* STO status bit */
   USINT              SafetyActiveSBC;        /* SBC status bit */
   USINT              SafetyActiveSS1;        /* SS1 status bit */
   USINT              NotErrENC;              /* Encoder error status bit */
   USINT              SafetyActiveSTO1;       /* STO1 status bit */
   USINT              SafetyActiveSDC;        /* Deceleration monitoring status bit */
   USINT              SafetyActiveSOS;        /* SOS status bit */
   USINT              SafetyActiveSS2;        /* SS2 status bit */
   USINT              SafetyActiveSLA;        /* SLA status bit */
   USINT              SafetyActiveSLS1;       /* SLS1 status bit */
   USINT              SafetyActiveSLS2;       /* SLS2 status bit */
   USINT              reserved_stat_b13;      /* reserved_stat_b13 */
   USINT              SafetyActiveSLS3;       /* SLS3 status bit */
   USINT              SafetyActiveSLS4;       /* SLS4 status bit */
   USINT              SafetyActiveSDIpos;     /* SDIpos status bit */
   USINT              SafetyActiveSDIneg;     /* SDIneg status bit */
   USINT              SafetyActiveSLI;        /* SLI status bit */
   USINT              SafetyStatusSBT;        /* SBT status bit */
   USINT              SafetyActiveSBT;        /* SBT is active */
   USINT              SafetyActiveSLT;        /* SLT status bit */
   USINT              StatusSFR;              /* At least one safety function is requested */
   USINT              AllReqFuncAct;          /* All requested safety functions are active */
   USINT              NotErrENC2;             /* Encoder error status bit2 */
   USINT              SafePositionValid;      /* SafePosition is valid */
   USINT              ReqHomingOK;            /* Request Homing OK bit */
   USINT              SafetyActiveSLP;        /* SLP status bit */
   USINT              SafetyActiveSMP;        /* SMP status bit */
   USINT              SafeUserData1Active;    /* SafeUserData1 is active */
   USINT              RSPValid;               /* RSP Valid bit */
   USINT              StatusSetPosAlive;      /* Setposition is tested */
   DINT               SafePosition;           /* Safe position */
   DINT               SafeSpeed;              /* Safe speed (SafeUserData1, if activated) */
   UDINT              reserve1;               /* Reserved */
   UDINT              reserve2;               /* Reserved */
} ACP10SAFEINDAT3_typ;

typedef struct ACP10SAFEOUTDAT_typ {          /* SafeMC: SafeOUT data */
   USINT              RequestSTO;             /* STO control bit */
   USINT              RequestSBC;             /* SBC control bit */
   USINT              RequestSOS;             /* SOS control bit */
   USINT              RequestSS1;             /* SS1 control bit */
   USINT              RequestSS2;             /* SS2 control bit */
   USINT              RequestSLS1;            /* SLS1 control bit */
   USINT              RequestSLS2;            /* SLS2 control bit */
   USINT              RequestSLS3;            /* SLS3 control bit */
   USINT              RequestSLS4;            /* SLS4 control bit */
   USINT              RequestSTO1;            /* STO1 control bit */
   USINT              RequestSDIpos;          /* SDI control bit (positive direction) */
   USINT              RequestSLI;             /* SLI control bit */
   USINT              RequestSDIneg;          /* SDI control bit (negative direction) */
   USINT              RequestSLP;             /* SLP control bit */
   USINT              RequestHoming;          /* Homing control bit */
   USINT              RequestSwitch;          /* Switch control bit */
   USINT              RequestSBT;             /* SBT control bit */
   USINT              RequestSLA;             /* SLA control bit */
   USINT              SwitchHomingMode;       /* Switch Homing Mode bit */
   USINT              reserved_ctrl_b19;      /* reserved_ctrl_b19 */
   USINT              reserved_ctrl_b20;      /* reserved_ctrl_b20 */
   USINT              reserved_ctrl_b21;      /* reserved_ctrl_b21 */
   USINT              Activate;               /* Activation of SafeMC module */
   USINT              Reset;                  /* Reset bit */
} ACP10SAFEOUTDAT_typ;

typedef struct ACP10SAFEOUTDAT2_typ {         /* SafeMC: SafeOUT data2 */
   USINT              Reset;                  /* Reset */
   USINT              Activate;               /* Activation of SafeMC module */
   USINT              RequestSTO;             /* STO control bit */
   USINT              RequestSBC;             /* SBC control bit */
   USINT              RequestSS1;             /* SS1 control bit */
   USINT              reserved_ctrl_b5;       /* reserved_ctrl_b5 */
   USINT              RequestSTO1;            /* STO1 control bit */
   USINT              reserved_ctrl_b7;       /* reserved_ctrl_b7 */
   USINT              RequestSOS;             /* SOS control bit */
   USINT              RequestSS2;             /* SS2 control bit */
   USINT              RequestSLA;             /* SLA control bit */
   USINT              RequestSLS1;            /* SLS1 control bit */
   USINT              RequestSLS2;            /* SLS2 control bit */
   USINT              reserved_ctrl_b13;      /* reserved_ctrl_b13 */
   USINT              RequestSLS3;            /* SLS3 control bit */
   USINT              RequestSLS4;            /* SLS4 control bit */
   USINT              RequestSDIpos;          /* SDI control bit (positive direction) */
   USINT              RequestSDIneg;          /* SDI control bit (negative direction) */
   USINT              RequestSLI;             /* SLI control bit */
   USINT              RequestSBT;             /* SBT control bit */
   USINT              reserved_ctrl_b20;      /* reserved_ctrl_b20 */
   USINT              RequestSLT;             /* SLT control bit */
   USINT              reserved_ctrl_b22;      /* reserved_ctrl_b22 */
   USINT              reserved_ctrl_b23;      /* reserved_ctrl_b23 */
   USINT              reserved_ctrl_b24;      /* reserved_ctrl_b24 */
   USINT              RequestHoming;          /* Homing control bit */
   USINT              RequestSwitch;          /* Switch control bit */
   USINT              RequestSLP;             /* SLP control bit */
   USINT              reserved_ctrl_b28;      /* reserved_ctrl_b28 */
   USINT              reserved_ctrl_b29;      /* reserved_ctrl_b29 */
   USINT              SwitchHomingMode;       /* Switch Homing Mode bit */
   USINT              reserved_ctrl_b31;      /* reserved_ctrl_b31 */
} ACP10SAFEOUTDAT2_typ;

typedef struct ACP10SAFEOUTDAT3_typ {         /* SafeMC: SafeOUT data3 */
   USINT              Reset;                  /* Reset */
   USINT              Activate;               /* Activation of SafeMC module */
   USINT              RequestSTO;             /* STO control bit */
   USINT              RequestSBC;             /* SBC control bit */
   USINT              RequestSS1;             /* SS1 control bit */
   USINT              reserved_ctrl_b5;       /* reserved_ctrl_b5 */
   USINT              RequestSTO1;            /* STO1 control bit */
   USINT              reserved_ctrl_b7;       /* reserved_ctrl_b7 */
   USINT              RequestSOS;             /* SOS control bit */
   USINT              RequestSS2;             /* SS2 control bit */
   USINT              RequestSLA;             /* SLA control bit */
   USINT              RequestSLS1;            /* SLS1 control bit */
   USINT              RequestSLS2;            /* SLS2 control bit */
   USINT              reserved_ctrl_b13;      /* reserved_ctrl_b13 */
   USINT              RequestSLS3;            /* SLS3 control bit */
   USINT              RequestSLS4;            /* SLS4 control bit */
   USINT              RequestSDIpos;          /* SDI control bit (positive direction) */
   USINT              RequestSDIneg;          /* SDI control bit (negative direction) */
   USINT              RequestSLI;             /* SLI control bit */
   USINT              RequestSBT;             /* SBT control bit */
   USINT              reserved_ctrl_b20;      /* reserved_ctrl_b20 */
   USINT              RequestSLT;             /* SLT control bit */
   USINT              RequestSafeUserData1;   /* SafeUserData1 control bit */
   USINT              reserved_ctrl_b23;      /* reserved_ctrl_b23 */
   USINT              reserved_ctrl_b24;      /* reserved_ctrl_b24 */
   USINT              RequestHoming;          /* Homing control bit */
   USINT              RequestSwitch;          /* Switch control bit */
   USINT              RequestSLP;             /* SLP control bit */
   USINT              reserved_ctrl_b28;      /* reserved_ctrl_b28 */
   USINT              reserved_ctrl_b29;      /* reserved_ctrl_b29 */
   USINT              SwitchHomingMode;       /* Switch Homing Mode bit */
   USINT              reserved_ctrl_b31;      /* reserved_ctrl_b31 */
   UDINT              reserve1;               /* Reserved */
} ACP10SAFEOUTDAT3_typ;

typedef struct ACP10APNWCST_typ {             /* Status */
   USINT              ok;                     /* Operation complete */
   USINT              error;                  /* Error */
   UINT               rx_par_id;              /* Parameter ID of receive data for coupling functions */
} ACP10APNWCST_typ;

typedef struct ACP10APNWCPA_typ {             /* Parameters */
   UDINT              tx_nc_object;           /* NC object of send data */
   UINT               tx_par_id;              /* Parameter ID of send data */
   USINT              tx_nr;                  /* Channel number of send data */
   USINT              rx_nr;                  /* Channel number of receive data */
   USINT              rx_ipl_mode;            /* Interpolation mode of receive data */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
} ACP10APNWCPA_typ;

typedef struct ACP10APNWC_typ {               /* ACOPOS Network Coupling */
   ACP10APNWCST_typ   status;                 /* Status */
   ACP10APNWCPA_typ   parameter;              /* Parameters */
} ACP10APNWC_typ;

typedef struct ACP10_HWIDRIVE_typ {           /* Hardware Information for drive */
   USINT              model_number[20];       /* Model number */
   USINT              serial_number[20];      /* Serial number */
   USINT              revision[4];            /* Revision */
   UDINT              mission_time_end;       /* End date of mission time (expiration date) */
} ACP10_HWIDRIVE_typ;

typedef struct ACP10_HWICARD_typ {            /* Hardware Information for plug-in card */
   USINT              model_number[20];       /* Model number */
   USINT              serial_number[20];      /* Serial number */
   USINT              revision[4];            /* Revision */
} ACP10_HWICARD_typ;

typedef struct ACP10_HWIMOTOR_typ {           /* Hardware Information for motor */
   USINT              model_number[36];       /* Model number */
   USINT              serial_number[20];      /* Serial number */
   USINT              revision[4];            /* Revision */
} ACP10_HWIMOTOR_typ;

typedef struct ACP10_HWINFO_typ {             /* ACOPOS Hardware Information */
   USINT              ok;                     /* Operation complete */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
   ACP10_HWIDRIVE_typ drive;                  /* Drive */
   ACP10_HWICARD_typ  card[4];                /* Plug-in card */
   ACP10_HWIMOTOR_typ motor[3];               /* Motor */
} ACP10_HWINFO_typ;

typedef struct ACP10TYPES_typ {               /* Data structure for additional data types */
   ACP10DATBL_typ       data_block;           /* Data block operation */
   ACP10PRECS_typ       par_recs;             /* Parameter records */
   ACP10UCROP_typ       read_cob_op;          /* Operate Read COB */
   ACP10NETGL_typ       network;              /* Network */
   ACP10DATMO_typ       nc_dat_mod;           /* NC data module */
   ACP10SMCCFG_typ      SafeMC_CFG;           /* SafeMC Configuration */
   ACP10SAFEINDAT_typ   SafeMC_SafeIN;        /* SafeMC SafeIN data structure */
   ACP10SAFEINDAT2_typ  SafeMC_SafeIN2;       /* SafeMC SafeIN2 data structure */
   ACP10SAFEINDAT3_typ  SafeMC_SafeIN3;       /* SafeMC SafeIN3 data structure */
   ACP10SAFEOUTDAT_typ  SafeMC_SafeOUT;       /* SafeMC SafeOUT data structure */
   ACP10SAFEOUTDAT2_typ SafeMC_SafeOUT2;      /* SafeMC SafeOUT2 data structure */
   ACP10SAFEOUTDAT3_typ SafeMC_SafeOUT3;      /* SafeMC SafeOUT3 data structure */
   ACP10APNWC_typ       acp_nw_coupling;      /* ACOPOS Network Coupling */
   USINT                NOT_USE_1[24];
   ACP10_HWINFO_typ     acp_hw_info;          /* ACOPOS hardware information */
} ACP10TYPES_typ;

typedef struct ACP10USBID_typ {               /* Basis CAN IDs for User CAN Objects */
   UINT               write_cob;              /* Write CAN Object */
   UINT               read_cob;               /* Read CAN Object */
} ACP10USBID_typ;

typedef struct ACP10WRCOB_typ {               /* Write CAN Object */
   UDINT              can_obj;                /* CAN Object (COB handle) from CAN_defineCOB() */
   UINT               status;                 /* Status */
   UINT               reserve;                /* Reserved */
} ACP10WRCOB_typ;

typedef struct ACP10UCRDF_typ {               /* Define Read COB */
   UINT               status;                 /* Status */
   UINT               node_nr;                /* Drive node number */
   UDINT              data_adr;               /* Data address */
} ACP10UCRDF_typ;

typedef struct ACP10UCWSN_typ {               /* Send Write COB */
   UINT               status;                 /* Status */
   USINT              cob_idx;                /* COB index */
   USINT              reserve;                /* Reserved */
   UDINT              data_adr;               /* Data address */
} ACP10UCWSN_typ;

typedef struct ACP10USCOB_typ {               /* ACP10 - User CAN Objects */
   USINT              NOT_USE_1[4];
   UINT               size;                   /* Size of the corresponding NC manager data type */
   UINT               reserve;                /* Reserved */
   ACP10SWVMA_typ     sw_version;             /* SW Version ID [hexadecimal] */
   ACP10OBINF_typ     nc_obj_inf;             /* NC Object Information */
   USINT              if_name[32];            /* Interface name */
   ACP10USBID_typ     basis_id;               /* Basis CAN IDs */
   ACP10WRCOB_typ     write_cob[8];           /* Write CAN Object */
   ACP10UCRDF_typ     read_cob_def;           /* Define Read COB */
   ACP10UCWSN_typ     write_cob_send;         /* Send Write COB */
} ACP10USCOB_typ;

typedef struct ACP10VALPA_typ {               /* Parameters */
   REAL               v_pos;                  /* Speed in positive direction */
   REAL               v_neg;                  /* Speed in negative direction */
   REAL               a1_pos;                 /* Acceleration in positive direction */
   REAL               a2_pos;                 /* Deceleration in positive direction */
   REAL               a1_neg;                 /* Acceleration in negative direction */
   REAL               a2_neg;                 /* Deceleration in negative direction */
   REAL               t_jolt;                 /* Jolt time */
   REAL               t_in_pos;               /* Settling time before message "In Position" */
   DINT               pos_sw_end;             /* Positive SW end */
   DINT               neg_sw_end;             /* Negative SW end */
   USINT              NOT_USE_1[4];
   REAL               ds_warning;             /* Lag error limit for display of a warning */
   REAL               ds_stop;                /* Lag error limit for stop of a movement */
   REAL               a_stop;                 /* Acceleration limit for stop of a movement */
   REAL               dv_stop;                /* Speed error limit for stop of a movement */
   UDINT              dv_stop_mode;           /* Mode for speed error monitoring */
} ACP10VALPA_typ;

typedef struct ACP10VALIM_typ {               /* Limit values */
   USINT              init;                   /* Initialized */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
   ACP10VALPA_typ     parameter;              /* Parameters */
} ACP10VALIM_typ;

typedef struct ACP10VASTP_typ {               /* Parameter Records */
   USINT              decel_ramp;             /* Deceleration ramp */
   USINT              controller;             /* Controller */
   UINT               reserve;                /* Reserved */
} ACP10VASTP_typ;

typedef struct ACP10VASTQ_typ {               /* Quickstop */
   USINT              decel_ramp;             /* Deceleration ramp */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
   REAL               t_jolt;                 /* Jolt time */
} ACP10VASTQ_typ;

typedef struct ACP10VASTD_typ {               /* Drive error */
   USINT              decel_ramp;             /* Deceleration ramp */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
} ACP10VASTD_typ;

typedef struct ACP10VASTO_typ {               /* Stop Movement */
   USINT              init;                   /* Initialized */
   USINT              NOT_USE_1;
   UINT               reserve2;               /* Reserved */
   ACP10AXSTI_typ     index;                  /* Index */
   ACP10VASTP_typ     parameter[4];           /* Parameters */
   ACP10VASTQ_typ     quickstop;              /* Quickstop */
   ACP10VASTD_typ     drive_error;            /* Drive error */
} ACP10VASTO_typ;

typedef struct ACP10VAHST_typ {               /* Status */
   USINT              ok;                     /* Reference position valid */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
   REAL               tr_s_rel;               /* Distance after activation of "triggering reference pulse" */
   DINT               offset;                 /* Offset */
} ACP10VAHST_typ;

typedef struct ACP10VAHPA_typ {               /* Parameters */
   DINT               s;                      /* Reference position */
   REAL               v_switch;               /* Speed for searching the reference switch */
   REAL               v_trigger;              /* Trigger Speed */
   REAL               a;                      /* Acceleration */
   USINT              mode;                   /* Mode */
   USINT              edge;                   /* Edge of reference switch */
   USINT              start_dir;              /* Start direction */
   USINT              trigg_dir;              /* Trigger direction */
   USINT              ref_pulse;              /* Reference pulse */
   USINT              fix_dir;                /* Fixed direction */
   USINT              reserve1;               /* Reserved */
   USINT              reserve2;               /* Reserved */
   REAL               tr_s_block;             /* Reference pulse block distance */
   REAL               torque_lim;             /* Torque limit for homing on block */
   REAL               ds_block;               /* Lag error for block detection */
   REAL               ds_stop;                /* Lag error for stop of a movement */
} ACP10VAHPA_typ;

typedef struct ACP10VAHOM_typ {               /* Homing */
   USINT              init;                   /* Initialized */
   USINT              reserve1;               /* Reserved */
   UINT               reserve2;               /* Reserved */
   ACP10VAHST_typ     status;                 /* Status */
   ACP10VAHPA_typ     parameter;              /* Parameters */
} ACP10VAHOM_typ;

typedef struct ACP10VAMOV_typ {               /* Movement */
   UINT               mode;                   /* Mode */
   UINT               detail;                 /* Detail */
   ACP10VASTO_typ     stop;                   /* Stop Movement */
   ACP10VAHOM_typ     homing;                 /* Homing procedure */
   ACP10BAMOV_typ     basis;                  /* Basis state */
} ACP10VAMOV_typ;

typedef struct ACP10VAMSCMDE_typ {            /* Command: Execute error reaction */
   UINT               type;                   /* Type */
   USINT              ok;                     /* Operation complete */
   USINT              error;                  /* Error */
} ACP10VAMSCMDE_typ;

typedef struct ACP10VAMSG_typ {               /* Messages */
   ACP10MSCNT_typ     count;                  /* Count */
   ACP10MSREC_typ     record;                 /* Error record */
   ACP10MSTXT_typ     text;                   /* Error text */
   ACP10VAMSCMDE_typ  cmd_error;              /* Command: Execute error reaction */
} ACP10VAMSG_typ;

typedef struct ACP10VAXIS_typ {               /* ACP10 - Virtual Axis */
   USINT              NOT_USE_1[4];
   UINT               size;                   /* Size of the corresponding NC manager data type */
   USINT              NOT_USE_2[2];
   ACP10SWVER_typ     sw_version;             /* SW Version ID [hexadecimal] */
   ACP10OBINF_typ     nc_obj_inf;             /* NC Object Information */
   ACP10SIM_typ       simulation;             /* Simulation Mode */
   ACP10GLINI_typ     global;                 /* Global Parameters */
   ACP10NET_typ       network;                /* Network */
   ACP10AXDBL_typ     datblock;               /* Data block operation */
   ACP10DIGIN_typ     dig_in;                 /* Digital Inputs */
   ACP10ENCIF_typ     encoder_if;             /* Encoder Interface */
   ACP10VALIM_typ     limit;                  /* Limit value */
   ACP10CTRL_typ      controller;             /* Controller */
   ACP10VAMOV_typ     move;                   /* Movement */
   ACP10SETUP_typ     setup;                  /* Setup */
   ACP10AXMON_typ     monitor;                /* Monitor */
   ACP10VAMSG_typ     message;                /* Messages (errors, warnings) */
   ACP10NCTST_typ     nc_test;                /* NC Test */
   USINT              NOT_USE_3[60];
} ACP10VAXIS_typ;


#endif /* ACP10MAN_H_VERSION */ 
