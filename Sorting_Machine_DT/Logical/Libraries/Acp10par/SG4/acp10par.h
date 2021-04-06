/* acp10par.h V5.12.2 */ 
/* COPYRIGHT (C) B&R Industrial Automation GmbH */ 

#ifndef ACP10PAR_H_ 
#define ACP10PAR_H_ 

#define ACP10PAR_SAFEMC_STATUS                4 /* (UDINT) SafeMC: Status */
#define ACP10PAR_SAFEMC_CONTROL               5 /* (UDINT) SafeMC: Control */
#define ACP10PAR_SAFEMC_SPEED_ACT             6 /* (INT) SafeMC: Actual speed [sUnits/s] */
#define ACP10PAR_SAFEMC_SPEED_LIM             7 /* (INT) SafeMC: Speed limit [sUnits/s] */
#define ACP10PAR_BRAKE_STATUS                 8 /* (UDINT) Motor holding brake: Status */
#define ACP10PAR_R_BLEEDER_EXT               10 /* (REAL) Bleeder: External: Resistance [Ohm] */
#define ACP10PAR_TEMP_MAX_BLEEDER_EXT        11 /* (REAL) Bleeder: External: Limit temperature [°C] */
#define ACP10PAR_RTH_BLEEDER_AMB_EXT         12 /* (REAL) Bleeder: External: Thermal resistance [K/W] */
#define ACP10PAR_CTH_BLEEDER_EXT             13 /* (REAL) Bleeder: External: Thermal capacity [Ws/K] */
#define ACP10PAR_BRAKE_TEST_TORQUE           14 /* (REAL) Motor holding brake: Test torque [Nm] */
#define ACP10PAR_BRAKE_TEST_POS_LIM          15 /* (REAL) Motor holding brake: Position error limit [Rev.] */
#define ACP10PAR_ACOPOS_POWER_RATED          16 /* (REAL) Inverter: Rated power [W] */
#define ACP10PAR_ACOPOS_CURR_RATED           17 /* (REAL) Inverter: Rated current [A] */
#define ACP10PAR_ACOPOS_CURR_MAX             18 /* (REAL) Inverter: Peak current [A] */
#define ACP10PAR_PHASE_MON_PARID             19 /* (UINT) Power mains: Parameter ID of the phase failure signal */
#define ACP10PAR_STAT_PHASE_MON              20 /* (UDINT) Power mains: Status phase failure */
#define ACP10PAR_ENCOD_REF_DCM_DIFF          21 /* (DINT) Encoder1: DCM Distance difference [Lines] */
#define ACP10PAR_ENCOD2_REF_DCM_DIFF         22 /* (DINT) Encoder2: DCM Distance difference [Lines] */
#define ACP10PAR_ENCOD3_REF_DCM_DIFF         23 /* (DINT) Encoder3: DCM Distance difference [Lines] */
#define ACP10PAR_FFCTRL_KV_TORQUE            24 /* (REAL) CTRL Feed forward: Speed torque factor [Nms] */
#define ACP10PAR_PLIM_MODE                   25 /* (UDINT) Power limiter: Mode */
#define ACP10PAR_MOTOR_TYPE                  30 /* (UINT) Motor: Type */
#define ACP10PAR_MOTOR_COMPATIBILITY         31 /* (UINT) Motor: Software compatibility */
#define ACP10PAR_MOTOR_DATE                  32 /* (UDINT) Motor: Test date */
#define ACP10PAR_ENCOD_SERIAL_DATA           33 /* (DATA) Encoder1: Serial data block */
#define ACP10PAR_ENCOD_SERIAL_STATUS         34 /* (UINT) Encoder1: Serial status */
#define ACP10PAR_ENCOD2_SERIAL_DATA          35 /* (DATA) Encoder2: Serial data block */
#define ACP10PAR_ENCOD2_SERIAL_STATUS        36 /* (UINT) Encoder2: Serial status */
#define ACP10PAR_ENCOD3_SERIAL_DATA          37 /* (DATA) Encoder3: Serial data block */
#define ACP10PAR_ENCOD3_SERIAL_STATUS        38 /* (UINT) Encoder3: Serial status */
#define ACP10PAR_SAFEMC_ENCOD_REF_LEN        39 /* (UDINT) SafeMC: Encoder scaling: reference length [nm] */
#define ACP10PAR_MOTOR_ORDERTEXT             40 /* (STR32) Motor: Order text */
#define ACP10PAR_MOTOR_SERIALNUMBER          41 /* (STR16) Motor: Serial number */
#define ACP10PAR_MOTOR_BRAKE_CURR_RATED      42 /* (REAL) Motor holding brake: Rated current [A] */
#define ACP10PAR_MOTOR_BRAKE_TORQ_RATED      43 /* (REAL) Motor holding brake: Rated torque [Nm] */
#define ACP10PAR_MOTOR_BRAKE_ON_TIME         44 /* (REAL) Motor holding brake: Engaging delay [s] */
#define ACP10PAR_MOTOR_BRAKE_OFF_TIME        45 /* (REAL) Motor holding brake: Release delay [s] */
#define ACP10PAR_MOTOR_WIND_CONNECT          46 /* (USINT) Motor: Winding connection */
#define ACP10PAR_MOTOR_POLEPAIRS             47 /* (USINT) Motor: Number of pole-pairs */
#define ACP10PAR_MOTOR_VOLTAGE_RATED         48 /* (REAL) Motor: Rated voltage [V] */
#define ACP10PAR_MOTOR_VOLTAGE_CONST         49 /* (REAL) Motor: Voltage constant [mVmin] */
#define ACP10PAR_MOTOR_SPEED_RATED           50 /* (REAL) Motor: Rated speed [1/min] */
#define ACP10PAR_MOTOR_SPEED_MAX             51 /* (REAL) Motor: Maximum speed [1/min] */
#define ACP10PAR_MOTOR_TORQ_STALL            52 /* (REAL) Motor: Stall torque [Nm] */
#define ACP10PAR_MOTOR_TORQ_RATED            53 /* (REAL) Motor: Rated torque [Nm] */
#define ACP10PAR_MOTOR_TORQ_MAX              54 /* (REAL) Motor: Peak torque [Nm] */
#define ACP10PAR_MOTOR_TORQ_CONST            55 /* (REAL) Motor: Torque constant [Nm/A] */
#define ACP10PAR_MOTOR_CURR_STALL            56 /* (REAL) Motor: Stall current [A] */
#define ACP10PAR_MOTOR_CURR_RATED            57 /* (REAL) Motor: Rated current [A] */
#define ACP10PAR_MOTOR_CURR_MAX              58 /* (REAL) Motor: Peak current [A] */
#define ACP10PAR_MOTOR_WIND_CROSS_SECT       59 /* (REAL) Motor: Phase cross section [mm²] */
#define ACP10PAR_MOTOR_STATOR_RESISTANCE     60 /* (REAL) Motor: Stator resistance [Ohm] */
#define ACP10PAR_MOTOR_STATOR_INDUCTANCE     61 /* (REAL) Motor: Stator inductance [Henry] */
#define ACP10PAR_MOTOR_INERTIA               62 /* (REAL) Motor: Moment of inertia [kgm²] */
#define ACP10PAR_MOTOR_COMMUT_OFFSET         63 /* (REAL) Motor: Commutation offset [rad] */
#define ACP10PAR_MOTOR_TEMPSENS_PAR1         64 /* (REAL) Temperature sensor: Parameter 1 */
#define ACP10PAR_MOTOR_TEMPSENS_PAR2         65 /* (REAL) Temperature sensor: Parameter 2 */
#define ACP10PAR_MOTOR_TEMPSENS_PAR3         66 /* (REAL) Temperature sensor: Parameter 3 */
#define ACP10PAR_MOTOR_TEMPSENS_PAR4         67 /* (REAL) Temperature sensor: Parameter 4 */
#define ACP10PAR_MOTOR_TEMPSENS_PAR5         68 /* (REAL) Temperature sensor: Parameter 5 */
#define ACP10PAR_MOTOR_TEMPSENS_PAR6         69 /* (REAL) Temperature sensor: Parameter 6 */
#define ACP10PAR_MOTOR_TEMPSENS_PAR7         70 /* (REAL) Temperature sensor: Parameter 7 */
#define ACP10PAR_MOTOR_TEMPSENS_PAR8         71 /* (REAL) Temperature sensor: Parameter 8 */
#define ACP10PAR_MOTOR_TEMPSENS_PAR9         72 /* (REAL) Temperature sensor: Parameter 9 */
#define ACP10PAR_MOTOR_TEMPSENS_PAR10        73 /* (REAL) Temperature sensor: Parameter 10 */
#define ACP10PAR_MOTOR_WIND_TEMP_MAX         74 /* (REAL) Motor: Limit temperature [°C] */
#define ACP10PAR_MOTOR_THERMAL_CONST         75 /* (REAL) Motor: Thermal time constant (for MOTOR_COMPATIBILITY 0x0202) [s] */
#define ACP10PAR_MOTOR_ROTOR_RESISTANCE      76 /* (REAL) Motor: Rotor resistance [Ohm] */
#define ACP10PAR_MOTOR_ROTOR_INDUCTANCE      77 /* (REAL) Motor: Rotor inductance [Henry] */
#define ACP10PAR_MOTOR_MUTUAL_INDUCTANCE     78 /* (REAL) Motor: Mutual inductance [Henry] */
#define ACP10PAR_MOTOR_MAGNETIZING_CURR      79 /* (REAL) Motor: Magnetizing current [A] */
#define ACP10PAR_PHASE_MON_IGNORE            80 /* (UINT) Power mains: Ignore phase failure */
#define ACP10PAR_CMD_MOTOR_DATA              81 /* (UINT) Motor: Command */
#define ACP10PAR_ENCOD_STATUS                82 /* (UDINT) Encoder1: Status */
#define ACP10PAR_MOTOR_DATA_STATUS           84 /* (UINT) Motor: Encoder data transfer: Status */
#define ACP10PAR_ENCOD2_TYPE                 85 /* (USINT) Encoder2: Type */
#define ACP10PAR_CMD_BRAKE                   86 /* (UINT) Motor holding brake: Command */
#define ACP10PAR_FFCTRL_TORQUE_POS           87 /* (REAL) CTRL Feed forward: Torque in positive direction [Nm] */
#define ACP10PAR_ENCOD2_STATUS               88 /* (UDINT) Encoder2: Status */
#define ACP10PAR_FFCTRL_TORQUE_NEG           89 /* (REAL) CTRL Feed forward: Torque in negative direction [Nm] */
#define ACP10PAR_BRAKE_MODE                  90 /* (UINT) Motor holding brake: Mode */
#define ACP10PAR_ENCOD1_S_ACT                91 /* (DINT) Encoder1: Actual position [Units] */
#define ACP10PAR_PCTRL_V_ACT                 92 /* (REAL) CTRL Position controller: Actual speed [Units/s] */
#define ACP10PAR_CMD_CONTROLLER              93 /* (UINT) CTRL Controller: Command */
#define ACP10PAR_ENCOD_COUNT_DIR             96 /* (USINT) Encoder1: Load scaling: Count direction */
#define ACP10PAR_ENCOD_TYPE                  97 /* (USINT) Encoder1: Type */
#define ACP10PAR_AXLIM_DS_STOP               98 /* (REAL) Limit values: Lag error for stop of a movement [Units] */
#define ACP10PAR_AXLIM_DS_WARNING            99 /* (REAL) Limit values: Lag error for display of a warning [Units] */
#define ACP10PAR_POS_CTRL_KV                100 /* (REAL) CTRL Position controller: Proportional amplification [1/s] */
#define ACP10PAR_POS_CTRL_TN                101 /* (REAL) CTRL Position controller: Integral action time [s] */
#define ACP10PAR_POS_CTRL_T_PREDICT         102 /* (REAL) CTRL Position controller: Prediction time [s] */
#define ACP10PAR_POS_CTRL_T_TOTAL           103 /* (REAL) CTRL Position controller: Total delay time [s] */
#define ACP10PAR_POS_CTRL_P_MAX             104 /* (REAL) CTRL Position controller: Maximum proportional action [Units/s] */
#define ACP10PAR_POS_CTRL_I_MAX             105 /* (REAL) CTRL Position controller: Maximum integral action [Units/s] */
#define ACP10PAR_SCALE_LOAD_UNITS           106 /* (UDINT) Encoder1: Load scaling: Units per load revolution [Units] */
#define ACP10PAR_SCALE_LOAD_MOTOR_REV       107 /* (UDINT) Encoder1: Load scaling: Encoder revolutions per load revolution */
#define ACP10PAR_SCALE_ENCOD_MOTOR_REV      108 /* (UDINT) Encoder1: Encoder scaling: motor revolutions */
#define ACP10PAR_SCALE_ENCOD_INCR           109 /* (UDINT) Encoder1: Encoder scaling: increments per encoder revolution */
#define ACP10PAR_CMD_SIMULATION             110 /* (UINT) Simulation mode: Command */
#define ACP10PAR_PCTRL_S_ACT                111 /* (DINT) CTRL Position controller: Actual position [Units] */
#define ACP10PAR_PCTRL_LAG_ERROR            112 /* (REAL) CTRL Position controller: Lag error [Units] */
#define ACP10PAR_PCTRL_S_SET                113 /* (DINT) CTRL Position controller: Set position [Units] */
#define ACP10PAR_PCTRL_V_SET                114 /* (REAL) CTRL Position controller: Set speed [Units/s] */
#define ACP10PAR_CMD_ABS_MOVE               115 /* (BASIS_MOVE_S_ABS, BASIS_MOVE_MODE) Basis movements: Start movement with absolute target position */
#define ACP10PAR_OVERRIDE                   116 /* (V_OVERRIDE, A_OVERRIDE) Basis movements: Override */
#define ACP10PAR_V_OVERRIDE                 117 /* (INT) Basis movements: Speed override */
#define ACP10PAR_A_OVERRIDE                 118 /* (INT) Basis movements: Acceleration override */
#define ACP10PAR_AXLIM_V_POS                119 /* (REAL) Limit values: Maximum speed in positive direction [Units/s] */
#define ACP10PAR_AXLIM_V_NEG                120 /* (REAL) Limit values: Maximum speed in negative direction [Units/s] */
#define ACP10PAR_AXLIM_A1_POS               121 /* (REAL) Limit values: Maximum acceleration in positive direction [Units/s²] */
#define ACP10PAR_AXLIM_A2_POS               122 /* (REAL) Limit values: Maximum deceleration in positive direction [Units/s²] */
#define ACP10PAR_AXLIM_A1_NEG               123 /* (REAL) Limit values: Maximum acceleration in negative direction [Units/s²] */
#define ACP10PAR_AXLIM_A2_NEG               124 /* (REAL) Limit values: Maximum deceleration in negative direction [Units/s²] */
#define ACP10PAR_AXLIM_T_JOLT               125 /* (REAL) Limit values: Jolt time [s] */
#define ACP10PAR_AXLIM_POS_SW_END           126 /* (DINT) Limit values: Positive SW end position [Units] */
#define ACP10PAR_AXLIM_NEG_SW_END           127 /* (DINT) Limit values: Negative SW end position [Units] */
#define ACP10PAR_SGEN_SW_END_IGNORE         128 /* (USINT) Limit values: Ignore SW end positions */
#define ACP10PAR_STATUS_TRACE               129 /* (USINT) Trace: Status */
#define ACP10PAR_PCTRL_S_ACT_FRAC           130 /* (REAL) CTRL Position controller: Actual position fractional part [Units] */
#define ACP10PAR_TRACE_TRIGGER_PARID        131 /* (UINT) Trace: Parameter ID for trigger event */
#define ACP10PAR_TRACE_TRIGGER_EVENT        132 /* (USINT) Trace: Trigger event */
#define ACP10PAR_TRACE_TRIGGER_THRESHOLD    133 /* (REAL) Trace: Trigger threshold */
#define ACP10PAR_TRACE_TRIGGER_WINDOW       134 /* (REAL) Trace: Trigger window */
#define ACP10PAR_TRACE_TEST_PARID           135 /* (UINT) Trace: Parameter ID for test date */
#define ACP10PAR_TRACE_TEST_TYPE            136 /* (USINT) Trace: Data type for test date */
#define ACP10PAR_CMD_TRACE                  137 /* (UINT) Trace: Command */
#define ACP10PAR_CPU_TICKS_CYCLE_PEAK       139 /* (DINT) Diagnosis: Peak value CPU computing time per cycle  */
#define ACP10PAR_TRACE_TEST_INDEX           140 /* (UINT) Trace: Index for test date */
#define ACP10PAR_TRACE_T_TRACE              141 /* (REAL) Trace: Recording time [s] */
#define ACP10PAR_TRACE_T_SAMPLING           142 /* (REAL) Trace: Sampling time [s] */
#define ACP10PAR_TRACE_T_DELAY              143 /* (REAL) Trace: Delay time relative to trigger event [s] */
#define ACP10PAR_TRACE_MAX_DATLEN           144 /* (UDINT) Trace: Maximum length of data [Byte] */
#define ACP10PAR_CTRL_CYCLE_TIME_MODE       145 /* (USINT) CTRL Controller: Mode of controller cascade cycle times */
#define ACP10PAR_PCTRL_CYC_SET_PARID        146 /* (UINT) CTRL Position controller: Parameter ID for cyclic set position */
#define ACP10PAR_CMD_PCTRL_CYC_SET          147 /* (UINT) CTRL Position controller: Start movement with cyclic position set values */
#define ACP10PAR_AXLIM_T_INPOS              150 /* (REAL) Limit values: Waiting time before message 'target position reached' [s] */
#define ACP10PAR_HOMING_TR_S_REL            151 /* (REAL) Homing: Reference pulse distance [Rev.] */
#define ACP10PAR_HOMING_S                   152 /* (DINT) Homing: Reference position [Units] */
#define ACP10PAR_HOMING_V_SWITCH            153 /* (REAL) Homing: Speed for searching the reference switch [Units/s] */
#define ACP10PAR_HOMING_V_TRIGGER           154 /* (REAL) Homing: Trigger speed [Units/s] */
#define ACP10PAR_HOMING_A                   155 /* (REAL) Homing: Acceleration for homing procedure [Units/s²] */
#define ACP10PAR_HOMING_MODE                156 /* (USINT) Homing: Mode */
#define ACP10PAR_HOMING_MODE_BITS           157 /* (USINT) Homing: Mode control bits */
#define ACP10PAR_HOMING_TR_S_BLOCK          158 /* (REAL) Homing: Distance for blocking the reference pulse [Rev.] */
#define ACP10PAR_BASIS_MOVE_S_ABS           159 /* (DINT) Basis movements: Target position [Units] */
#define ACP10PAR_BASIS_MOVE_S_REL           160 /* (DINT) Basis movements: Relative move distance [Units] */
#define ACP10PAR_BASIS_MOVE_V_POS           161 /* (REAL) Basis movements: Speed in positive direction [Units/s] */
#define ACP10PAR_BASIS_MOVE_V_NEG           162 /* (REAL) Basis movements: Speed in negative direction [Units/s] */
#define ACP10PAR_BASIS_MOVE_A1_POS          163 /* (REAL) Basis movements: Acceleration in positive direction [Units/s²] */
#define ACP10PAR_BASIS_MOVE_A2_POS          164 /* (REAL) Basis movements: Deceleration in positive direction [Units/s²] */
#define ACP10PAR_BASIS_MOVE_A1_NEG          165 /* (REAL) Basis movements: Acceleration in negative direction [Units/s²] */
#define ACP10PAR_BASIS_MOVE_A2_NEG          166 /* (REAL) Basis movements: Deceleration in negative direction [Units/s²] */
#define ACP10PAR_CMD_HOMING                 167 /* (HOMING_S, HOMING_MODE, HOMING_MODE_BITS) Homing: Command start homing procedure */
#define ACP10PAR_CMD_REL_MOVE               168 /* (BASIS_MOVE_S_REL, BASIS_MOVE_MODE) Basis movements: Start movement with relative move distance */
#define ACP10PAR_CMD_POS_MOVE               169 /* (BASIS_MOVE_V_POS, BASIS_MOVE_MODE) Basis movements: Start movement in positive direction */
#define ACP10PAR_CMD_NEG_MOVE               170 /* (BASIS_MOVE_V_NEG, BASIS_MOVE_MODE) Basis movements: Start movement in negative direction */
#define ACP10PAR_STOP_CMD_CONF_INDEX        171 /* (USINT) Movement stop: Index of parameter record for the stop command */
#define ACP10PAR_HOMING_OFFSET              172 /* (DINT) Homing: Offset [Units] */
#define ACP10PAR_STOP_CONF_INDEX            173 /* (USINT) Movement stop: Index of parameter record for stop configuration */
#define ACP10PAR_STOP_CONF_DECEL_RAMP       174 /* (USINT) Movement stop: Deceleration ramp */
#define ACP10PAR_STOP_CONF_CTRL_STATE       175 /* (USINT) Movement stop: Controller state after movement stop */
#define ACP10PAR_CMD_MOVEMENT_STOP          176 /* (STOP_CMD_CONF_INDEX) Movement stop: Command stop movement */
#define ACP10PAR_STATUS_BITS                178 /* (UDINT) Status: General bits */
#define ACP10PAR_STATUS_CYCLIC_BITS         179 /* (UDINT) Status: Cyclic bits */
#define ACP10PAR_ERROR_NUMBER               180 /* (UINT) Messages: Error number */
#define ACP10PAR_ERROR_INFO                 181 /* (DINT) Messages: Additional error info */
#define ACP10PAR_ERROR_REC                  183 /* (ERROR_NUMBER, ERROR_INFO) Messages: Error record from drive */
#define ACP10PAR_DIG_IN_FORCE_ENABLE        184 /* (USINT) Digital inputs: Force enable bits */
#define ACP10PAR_CMD_DIG_IN_FORCE           185 /* (USINT) Digital inputs: Force function */
#define ACP10PAR_DIG_IN_ACTIVE_LEVEL        186 /* (USINT) Digital inputs: Active level bits */
#define ACP10PAR_NETWORK_LIVE_CTRL          189 /* (UDINT) Time for network live sign control [us] */
#define ACP10PAR_CMD_BASIS_MOVE_HALT        191 /* (NIL) Basis movements: Halt */
#define ACP10PAR_AUT_PAR_RESET              194 /* (USINT) Cam automat: Reset parameter */
#define ACP10PAR_AUT_PAR_RESET_VAX1         195 /* (USINT) VAX Cam automat: Reset parameter */
#define ACP10PAR_SAFEMC_SPEED_ACT_I4        196 /* (DINT) SafeMC: Actual speed (SafeUserData1, if activated) */
#define ACP10PAR_STOP_ERR_DECEL_RAMP        197 /* (USINT) Movement stop: Deceleration ramp after drive error */
#define ACP10PAR_CYCLIC_TODRV_T_CTRL        198 /* (DINT) Cyclic communication: Time for life sign monitoring of data to drive [us] */
#define ACP10PAR_ENCOD_POLEPAIRS            203 /* (USINT) Encoder1: Resolver polepairs per encoder revolution */
#define ACP10PAR_ENCOD2_POLEPAIRS           204 /* (USINT) Encoder2: Resolver polepairs per encoder revolution */
#define ACP10PAR_CYCLIC_TODRV_PARID         207 /* (UINT) Cyclic communication: Parameter ID of data to drive */
#define ACP10PAR_VCTRL_I1                   209 /* (REAL) Inverter: Phase 1: Current  [A] */
#define ACP10PAR_VCTRL_I2                   210 /* (REAL) Inverter: Phase 2: Current  [A] */
#define ACP10PAR_BRAKE_CTRL_MON_FILTER      211 /* (REAL) Motor holding brake: Control monitoring filter time  [s] */
#define ACP10PAR_ENCOD_DIAG1                212 /* (REAL) Encoder1: Diagnosis 1 */
#define ACP10PAR_ICTRL_ISQ_REF              213 /* (REAL) CTRL Current controller: Set stator current quadrature component [A] */
#define ACP10PAR_ICTRL_ISQ_ACT              214 /* (REAL) CTRL Current controller: Actual stator current quadrature component [A] */
#define ACP10PAR_ICTRL_USQ_REF              216 /* (REAL) CTRL Current controller: Stator voltage quadrature component [V] */
#define ACP10PAR_ICTRL_ISD_REF              218 /* (REAL) CTRL Current controller: Set stator current direct component [A] */
#define ACP10PAR_ICTRL_ISD_ACT              219 /* (REAL) CTRL Current controller: Actual stator current direct component [A] */
#define ACP10PAR_ICTRL_USD_REF              221 /* (REAL) CTRL Current controller: Stator voltage direct component [V] */
#define ACP10PAR_FCTRL_ISD_REF              222 /* (REAL) Flux controller: Manipulated variable [A] */
#define ACP10PAR_ICTRL_KV                   223 /* (REAL) CTRL Current controller: Proportional amplification factor [V/A] */
#define ACP10PAR_SAFEMC_SPEED_LIM_I4        224 /* (DINT) SafeMC: Speed limit [Units/s] */
#define ACP10PAR_ICTRL_TI                   225 /* (REAL) CTRL Current controller: Integral action time [s] */
#define ACP10PAR_SCTRL_FILTER_F0            226 /* (REAL) CTRL Speed controller: Notchfilter frequence [1/s] */
#define ACP10PAR_SCTRL_FILTER_B             227 /* (REAL) CTRL Speed controller: Notchfilter bandwidth [1/s] */
#define ACP10PAR_PCTRL_LAG2_ERROR           228 /* (REAL) CTRL Two encoder control: Position difference [Units] */
#define ACP10PAR_AXLIM_DS_STOP2             229 /* (REAL) CTRL Two encoder control: Position difference limit for stop of a movement [Units] */
#define ACP10PAR_PCTRL_S_ACT_PARID          230 /* (UINT) CTRL Position controller: Actual encoder position parameter ID */
#define ACP10PAR_PCTRL_ENABLE_PARID         231 /* (UINT) CTRL Position controller: Parameter ID enable input */
#define ACP10PAR_CYCLIC_TODRV_PAR_INDEX     232 /* (USINT) Cyclic communication: Parameter index of data to drive */
#define ACP10PAR_CYCLIC_FRDRV_REC_INDEX     234 /* (USINT) Cyclic communication: Index of parameter record for data from drive */
#define ACP10PAR_CYCLIC_FRDRV_PAR_INDEX     235 /* (USINT) Cyclic communication: Parameter index of data from drive */
#define ACP10PAR_CYCLIC_FRDRV_PARID         236 /* (UINT) Cyclic communication: Parameter ID of data from drive */
#define ACP10PAR_ENCOD_SSI_ZERO_BITS        237 /* (USINT) Encoder1: SSI Number of leading zeros */
#define ACP10PAR_ENCOD_SSI_BITS             238 /* (USINT) Encoder1: SSI Number of data bits */
#define ACP10PAR_ENCOD_SSI_CODE             239 /* (USINT) Encoder1: SSI, Data code */
#define ACP10PAR_ENCOD_SSI_PARITY_CHK       240 /* (USINT) Encoder1: SSI Parity check */
#define ACP10PAR_ENCOD2_SSI_ZERO_BITS       241 /* (USINT) Encoder2: SSI Number of leading zeros */
#define ACP10PAR_ENCOD2_SSI_BITS            242 /* (USINT) Encoder2: SSI Number of data bits */
#define ACP10PAR_ENCOD2_SSI_CODE            243 /* (USINT) Encoder2: SSI Data code */
#define ACP10PAR_ENCOD2_SSI_PARITY_CHK      244 /* (USINT) Encoder2: SSI Parity check */
#define ACP10PAR_ENCOD_POS_ACT              245 /* (DINT) Encoder1: Actual position per revolution [Incr] */
#define ACP10PAR_ENCOD2_POS_ACT             246 /* (DINT) Encoder2: Actual position per revolution [Incr] */
#define ACP10PAR_ICTRL_ADD_TRQ              247 /* (REAL) CTRL Current controller: Additive torque [Nm] */
#define ACP10PAR_LIM_T1_POS                 248 /* (REAL) CTRL Torque limiter: Maximum acceleration torque in positive direction [Nm] */
#define ACP10PAR_LIM_T1_NEG                 249 /* (REAL) CTRL Torque limiter: Maximum acceleration torque in negative direction [Nm] */
#define ACP10PAR_SCTRL_SPEED_REF            250 /* (REAL) CTRL Speed controller: Set speed [1/s] */
#define ACP10PAR_SCTRL_SPEED_ACT            251 /* (REAL) CTRL Speed controller: Actual speed [1/s] */
#define ACP10PAR_SCTRL_KV                   253 /* (REAL) CTRL Speed controller: Proportional amplification [As] */
#define ACP10PAR_SCTRL_TN                   255 /* (REAL) CTRL Speed controller: Integral action time [s] */
#define ACP10PAR_SCTRL_ISQ_REF              256 /* (REAL) CTRL Speed controller: Manipulated variable [A] */
#define ACP10PAR_FCTRL_IM_REF               257 /* (REAL) CTRL Flux: Set magnetizing current [A] */
#define ACP10PAR_FCTRL_IM_ACT               258 /* (REAL) CTRL Flux: Actual magnetizing current [A] */
#define ACP10PAR_FCTRL_KV                   259 /* (REAL) CTRL Flux: Proportional amplification factor */
#define ACP10PAR_FCTRL_TN                   260 /* (REAL) CTRL Flux: Integral action time [s] */
#define ACP10PAR_UCTRL_ISQ_ADD_PARID        261 /* (UINT) CTRL DC bus: Parameter ID additive active current */
#define ACP10PAR_POWER_SUPPLY_MODE          262 /* (UINT) Power mains: Mode */
#define ACP10PAR_PHASING_CURR               275 /* (REAL) Motor: Phasing: Current [A] */
#define ACP10PAR_PHASING_MODE               276 /* (UINT) Motor: Phasing: Mode */
#define ACP10PAR_TORQUE_ACT                 277 /* (REAL) Motor: Torque [Nm] */
#define ACP10PAR_POWER_ACT                  278 /* (REAL) Motor: Power [W] */
#define ACP10PAR_ENCOD_RATIO_MOTOR_REV      280 /* (UDINT) Encoder1: Gear ratio motor revolutions */
#define ACP10PAR_FFCTRL_ISQ                 281 /* (REAL) CTRL Feed forward: Set stator current [A] */
#define ACP10PAR_FFCTRL_TORQ_LOAD_PARID     282 /* (UINT) CTRL Feed forward: Parameter ID load torque */
#define ACP10PAR_SCTRL_TI_FIL               283 /* (REAL) CTRL Speed controller: Filter time constant [s] */
#define ACP10PAR_ENCOD3_POLEPAIRS           284 /* (USINT) Encoder3: Resolver polepairs per encoder revolution */
#define ACP10PAR_FFCTRL_INERTIA_PARID       285 /* (UINT) CTRL Feed forward: Parameter ID mass moment of inertia */
#define ACP10PAR_ENCOD_OUT_PARID            286 /* (UINT) Encoder1: Emulation: Output parameter ID */
#define ACP10PAR_STAT_BRAKE_CIRCUIT         287 /* (UDINT) Motor holding brake: Electrical state */
#define ACP10PAR_SCTRL_ADD_SET_PARID        288 /* (UINT) CTRL Speed controller: Parameter ID additive set value */
#define ACP10PAR_SCALE_ENCOD2_INCR          289 /* (UDINT) Encoder2: Encoder scaling: Increments per encoder revolution */
#define ACP10PAR_CONST_I4_ZERO              292 /* (DINT) Function block: Constant zero */
#define ACP10PAR_UDC_ACT                    298 /* (REAL) CTRL DC bus: Voltage [V] */
#define ACP10PAR_UDC_CTRL_TI_FIL            299 /* (REAL) CTRL DC bus: Filter time constant [s] */
#define ACP10PAR_UDC_DETECTION              300 /* (REAL) CTRL DC bus: Voltage detection: Lower limit [V] */
#define ACP10PAR_FFCTRL_INERTIA             301 /* (REAL) CTRL Feed forward: Mass moment of inertia [kgm²] */
#define ACP10PAR_UDC_FILTER                 302 /* (REAL) CTRL DC bus: Filtered voltage [V] */
#define ACP10PAR_ENCOD_ADC1                 303 /* (REAL) Encoder1: ADC1 value */
#define ACP10PAR_CONST_I4_SHRT_MIN          306 /* (DINT) Function block: Constant minimum value 2byte signed */
#define ACP10PAR_SAFEMC_POS_ACT             309 /* (DINT) SafeMC: Actual position [Units] */
#define ACP10PAR_CONST_I4_ONE               310 /* (DINT) Function block: Constant one */
#define ACP10PAR_ENABLE_CONFIG              311 /* (UDINT) ENABLE: Configuration */
#define ACP10PAR_FCTRL_IM_LIM_MAX           312 /* (REAL) CTRL Flux:  Magnetizing current limiter: Upper limit [A] */
#define ACP10PAR_SCTRL_SPEED_MON_LIM        313 /* (REAL) CTRL Speed controller: Monitoring: Speed limit [1/s] */
#define ACP10PAR_CHP_DUTY_CYCLE_MIN         314 /* (REAL) CTRL Chopper: Minimum pwm duty cycle */
#define ACP10PAR_JUNCTION_POWER_LOSS        315 /* (REAL) Inverter: Junction temperature model: Power loss [W] */
#define ACP10PAR_BRAKE_TEST_POS_DELTA       323 /* (REAL) Motor holding brake: Maximal position error [Rev.] */
#define ACP10PAR_ICTRL_ADD_SET_PARID        325 /* (UINT) CTRL Current controller: Additive set value parameter ID */
#define ACP10PAR_CONTROLLER_MODE            328 /* (USINT) CTRL Controller: Mode */
#define ACP10PAR_VCTRL_ENCOD_REV            330 /* (DINT) Motor encoder: Gear: Encoder revolutions */
#define ACP10PAR_VCTRL_MOTOR_REV            331 /* (DINT) Motor encoder: Gear: Motor revolutions */
#define ACP10PAR_CMD_PHASING                334 /* (UINT) Motor: Phasing: Command */
#define ACP10PAR_ENCOD_ERROR_STATE          336 /* (USINT) Encoder1: Error state */
#define ACP10PAR_ENCOD2_ERROR_STATE         337 /* (USINT) Encoder2: Error state */
#define ACP10PAR_ENCOD3_ERROR_STATE         338 /* (USINT) Encoder3: Error state */
#define ACP10PAR_CMD_ERR_STATE_INTO_FIFO    340 /* (NIL) Messages: Command write error state into error FIFO */
#define ACP10PAR_LOAD_MOTOR_MODEL           342 /* (REAL) Motor: Temperature model: Load [%] */
#define ACP10PAR_LIM_T_OVR_GRP              343 /* (LIM_T1_POS_OVR, LIM_T1_NEG_OVR, LIM_T2_POS_OVR, LIM_T2_NEG_OVR) CTRL Torque limiter: Override */
#define ACP10PAR_LIM_T1_POS_OVR             344 /* (USINT) CTRL Torque limiter: LIM_T1_POS override [%] */
#define ACP10PAR_UDC_BLEEDER_ON             345 /* (REAL) CTRL DC bus: Limiter: Switch on threshold [V] */
#define ACP10PAR_LIM_T1_NEG_OVR             346 /* (USINT) CTRL Torque limiter: LIM_T1_NEG override [%] */
#define ACP10PAR_F_SWITCH                   347 /* (REAL) Inverter: Switch frequency [cps] */
#define ACP10PAR_LIM_T2_POS                 348 /* (REAL) CTRL Torque limiter: Maximum deceleration torque in positive direction [Nm] */
#define ACP10PAR_LIM_T2_NEG                 349 /* (REAL) CTRL Torque limiter: Maximum deceleration torque in negative direction [Nm] */
#define ACP10PAR_RHO                        350 /* (REAL) Rotor flux angle [rad] */
#define ACP10PAR_ERRESP_UDC_POWERFAIL       351 /* (UDINT) Power mains: Error response */
#define ACP10PAR_LOAD_MOTOR_MODEL_MAX       352 /* (REAL) Motor: Temperature model: Maximum load [%] */
#define ACP10PAR_SYS_TIME                   355 /* (UDINT) Drive synchronisation: Total time [us] */
#define ACP10PAR_SYNC_SYS_TIME_DIFF         359 /* (DINT) Drive synchronisation: Deviation from master time */
#define ACP10PAR_STAT_UDC_POWERFAIL         367 /* (UDINT) Power mains: Status */
#define ACP10PAR_UVLIM_MODE                 368 /* (UDINT) CTRL DC bus: Limiter: Mode */
#define ACP10PAR_ENCOD_REF_PULSE_STATUS     369 /* (USINT) Encoder1: INC Reference pulse state */
#define ACP10PAR_ENCOD2_REF_PULSE_STATUS    370 /* (USINT) Encoder2: INC Reference pulse state */
#define ACP10PAR_ENCOD3_REF_PULSE_STATUS    371 /* (USINT) Encoder3: INC Reference pulse state */
#define ACP10PAR_ENCOD_RATIO_ENCOD_REV      372 /* (UDINT) Encoder1: Gear ratio encoder revolutions */
#define ACP10PAR_TEMP_MOTOR_MODEL_MODE      373 /* (UINT) Motor: Temperature model: Mode */
#define ACP10PAR_LIM_T2_POS_OVR             374 /* (USINT) CTRL Torque limiter: LIM_T2_POS override [%] */
#define ACP10PAR_LIM_T2_NEG_OVR             375 /* (USINT) CTRL Torque limiter: LIM_T2_NEG override [%] */
#define ACP10PAR_LOAD_CONT_CURR             377 /* (REAL) Inverter: Continuous current: Load [%] */
#define ACP10PAR_LOAD_CONT_CURR_MAX         378 /* (REAL) Inverter: Continuous current: Maximum load [%] */
#define ACP10PAR_LOAD_PEAK_CURR             379 /* (REAL) Inverter: Peak current: Load [%] */
#define ACP10PAR_TEMP_HEATSINK              380 /* (REAL) Power stage: Heatsink temperature sensor: Temperature [°C] */
#define ACP10PAR_TEMP_MOTOR                 381 /* (REAL) Temperature sensor: Temperature [°C] */
#define ACP10PAR_TEMP_JUNCTION              382 /* (REAL) Inverter: Junction temperature model: Temperature [°C] */
#define ACP10PAR_TEMP_BLEEDER               383 /* (REAL) Bleeder: Temperature model: Temperature [°C] */
#define ACP10PAR_TEMP_HEATSINK_MAX          384 /* (REAL) Power stage: Heatsink temperature sensor: Maximum temperature [°C] */
#define ACP10PAR_TEMP_MOTOR_MAX             385 /* (REAL) Temperature sensor: Maximum temperature [°C] */
#define ACP10PAR_TEMP_JUNCTION_MAX          386 /* (REAL) Inverter: Junction temperature model: Maximum temperature [°C] */
#define ACP10PAR_TEMP_BLEEDER_MAX           387 /* (REAL) Bleeder: Temperature model: Maximum temperature [°C] */
#define ACP10PAR_LOAD_PEAK_CURR_MAX         388 /* (REAL) Inverter: Peak current: Maximum load [%] */
#define ACP10PAR_EPROM_SERIAL_ID_TEXT       389 /* (STR16) FB EPROM: Serial-ID */
#define ACP10PAR_UDC_NOMINAL                390 /* (REAL) CTRL DC bus: Nominal voltage [V] */
#define ACP10PAR_TPRED_MODE                 391 /* (USINT) Temperature prediction: Mode */
#define ACP10PAR_TPRED_TRIG_PARID           392 /* (UINT) Temperature prediction: Trigger Parameter-ID */
#define ACP10PAR_TEMP_MOTOR_MODELL          393 /* (REAL) Motor: Temperature model: Temperature [°C] */
#define ACP10PAR_TEMP_MOTOR_MODELL_MAX      394 /* (REAL) Motor: Temperature model: Maximum temperature [°C] */
#define ACP10PAR_STAT_LOAD_RELAY            395 /* (UDINT) Power mains: Status main relay */
#define ACP10PAR_BLEEDER_SELECTOR_EXT       398 /* (USINT) Bleeder: Selector */
#define ACP10PAR_CMD_ABS_MOVE_VAX1          400 /* (BASIS_MOVE_S_ABS_VAX1) VAX Basis movements: Start movement with absolute target position */
#define ACP10PAR_CMD_REL_MOVE_VAX1          401 /* (BASIS_MOVE_S_REL_VAX1) VAX Basis movements: Start movement with relative move distance */
#define ACP10PAR_CMD_POS_MOVE_VAX1          402 /* (BASIS_MOVE_V_POS_VAX1) VAX Basis movements: Start movement in positive direction */
#define ACP10PAR_CMD_NEG_MOVE_VAX1          403 /* (BASIS_MOVE_V_NEG_VAX1) VAX Basis movements: Start movement in negative direction */
#define ACP10PAR_BASIS_MOVE_V_POS_VAX1      404 /* (REAL) VAX Basis movements: Speed in positive direction [Units/s] */
#define ACP10PAR_BASIS_MOVE_V_NEG_VAX1      405 /* (REAL) VAX Basis movements: Speed in negative direction [Units/s] */
#define ACP10PAR_BASIS_MOVE_A1_POS_VAX1     406 /* (REAL) VAX Basis movements: Acceleration in positive direction [Units/s²] */
#define ACP10PAR_BASIS_MOVE_A2_POS_VAX1     407 /* (REAL) VAX Basis movements: Deceleration in positive direction [Units/s²] */
#define ACP10PAR_BASIS_MOVE_A1_NEG_VAX1     408 /* (REAL) VAX Basis movements: Acceleration in negative direction [Units/s²] */
#define ACP10PAR_BASIS_MOVE_A2_NEG_VAX1     409 /* (REAL) VAX Basis movements: Deceleration in negative direction [Units/s²] */
#define ACP10PAR_BASIS_MOVE_S_ABS_VAX1      410 /* (DINT) VAX Basis movements: Target position [Units] */
#define ACP10PAR_BASIS_MOVE_S_REL_VAX1      411 /* (DINT) VAX Basis movements: Relative move distance [Units] */
#define ACP10PAR_S_SET_VAX1                 412 /* (DINT) VAX: Position [Units] */
#define ACP10PAR_V_SET_VAX1                 413 /* (REAL) VAX: Speed [Units/s] */
#define ACP10PAR_AXLIM_T_JOLT_VAX1          415 /* (REAL) VAX Limit values: Jolt time [s] */
#define ACP10PAR_BASIS_TRG_STOP             416 /* (BASIS_TRG_STOP_S_REST, BASIS_TRG_STOP_EVENT) Basis movements: Mode 'stop after trigger' */
#define ACP10PAR_BASIS_TRG_STOP_S_REST      417 /* (DINT) Basis movements: Remaining distance for mode 'stop after trigger' [Units] */
#define ACP10PAR_BASIS_TRG_STOP_EVENT       418 /* (USINT) Basis movements: Trigger event for mode 'stop after trigger' */
#define ACP10PAR_BASIS_MOVE_MODE            419 /* (USINT) Basis movements: Mode */
#define ACP10PAR_SCALE_ENCOD2_UNITS         420 /* (UDINT) Encoder2: Load scaling: Units per load revolution [Units] */
#define ACP10PAR_SCALE_ENCOD2_REV           421 /* (UDINT) Encoder2: Load scaling: Encoder revolutions */
#define ACP10PAR_ENCOD2_COUNT_DIR           422 /* (USINT) Encoder2: Load scaling: Count direction */
#define ACP10PAR_ENCOD2_S_ACT               423 /* (DINT) Encoder2: Actual position [Units] */
#define ACP10PAR_STAT_ENC2_HOMING_OK        427 /* (UDINT) Encoder2: Status home position valid */
#define ACP10PAR_SGEN_S_SET                 428 /* (DINT) CTRL Position controller: Input set position [Units] */
#define ACP10PAR_ENCOD2_S_FILTER_T10        429 /* (REAL) Encoder2: Time constant for actual position filter [s] */
#define ACP10PAR_AUT_INDEX_DATA             432 /* (AUT_DATA_INDEX, AUT_POLY_DATA) Cam automat: Index and data of polynomial cam */
#define ACP10PAR_TRACE_TEST_ADDR            451 /* (DINT) Trace: Address for test date */
#define ACP10PAR_CYCLIC_TOFRDRV_MODE        457 /* (USINT) Cyclic communication: Mode */
#define ACP10PAR_TRACE_TRIGGER_ADDR         458 /* (DINT) Trace: Address for trigger event */
#define ACP10PAR_LIMIT_SWITCH_IGNORE        459 /* (BOOL) Digital inputs: Ignore limit switch */
#define ACP10PAR_STAT_REFERENCE_SWITCH      460 /* (UDINT) Digital inputs: Status reference switch */
#define ACP10PAR_STAT_POS_LIMIT_SWITCH      461 /* (UDINT) Digital inputs: Status positive end switch */
#define ACP10PAR_STAT_NEG_LIMIT_SWITCH      462 /* (UDINT) Digital inputs: Status negative end switch */
#define ACP10PAR_STAT_TRIGGER1              463 /* (UDINT) Digital inputs: Status trigger1 */
#define ACP10PAR_STAT_TRIGGER2              464 /* (UDINT) Digital inputs: Status trigger2 */
#define ACP10PAR_STAT_CONTROLLER            465 /* (UDINT) Status: Controller */
#define ACP10PAR_STAT_HOMING_OK             466 /* (UDINT) Homing: Status home position valid */
#define ACP10PAR_STAT_TARGET_POS_REACHED    467 /* (UDINT) Basis movements: Status 'target position reached' */
#define ACP10PAR_STAT_MOVE_ACTIVE           468 /* (UDINT) Status: Movement active */
#define ACP10PAR_STAT_ERROR_NOT_READ        469 /* (UDINT) Messages: Status error record available */
#define ACP10PAR_STAT_WARNING_NOT_READ      470 /* (UDINT) Messages: Status warning record available */
#define ACP10PAR_STAT_DRIVE_READY           471 /* (UDINT) Status: Drive ready */
#define ACP10PAR_MA1_CYCLIC_SEND            484 /* (UINT) Network coupling: Parameter ID of send data master1 */
#define ACP10PAR_MA2_CYCLIC_SEND            485 /* (UINT) Network coupling: Parameter ID of send data master2 */
#define ACP10PAR_MA3_CYCLIC_SEND            494 /* (UINT) Network coupling: Parameter ID of send data master3 */
#define ACP10PAR_AUT_START_ST_INDEX         495 /* (USINT) Cam automat: Index for start state */
#define ACP10PAR_AUT_START_ST_INDEX_VAX1    496 /* (USINT) VAX Cam automat: Index for start state */
#define ACP10PAR_AUT_POLY_DATA              500 /* (DATA) Cam automat: Cam polynomial data */
#define ACP10PAR_AUT_DATA_INDEX             501 /* (UINT) Cam automat: Index of cam data for Upload/Download */
#define ACP10PAR_CMD_AUT_START              502 /* (UINT) Cam automat: Command */
#define ACP10PAR_AUT_MA_AXIS                503 /* (UINT) Cam automat: Master axis */
#define ACP10PAR_AUT_MA_S_START             504 /* (DINT) Cam automat: Start position of the master axis [Units] */
#define ACP10PAR_AUT_MA_IVSTART             505 /* (UDINT) Cam automat: Start interval of the master axis [Units] */
#define ACP10PAR_AUT_MA_V_MAX               506 /* (REAL) Cam automat: Maximum speed of master axis [Units/s] */
#define ACP10PAR_AUT_ST_INDEX               507 /* (USINT) Cam automat: Index of parameter record for one state */
#define ACP10PAR_AUT_EV_INDEX               508 /* (USINT) Cam automat: Index of parameter record for one event */
#define ACP10PAR_AUT_ST_DATA_INDEX          509 /* (UINT) Cam automat: Index of cam data for one state */
#define ACP10PAR_AUT_COMP_MODE              510 /* (USINT) Cam automat: Compensation gears mode */
#define ACP10PAR_AUT_COMP_MA_S              511 /* (DINT) Cam automat: Compensation distance of master axis [Units] */
#define ACP10PAR_AUT_COMP_SL_S              512 /* (DINT) Cam automat: Compensation distance of slave axis [Units] */
#define ACP10PAR_AUT_EVENT_TYPE             513 /* (USINT) Cam automat: Event type */
#define ACP10PAR_AUT_EVENT_ATTR             514 /* (USINT) Cam automat: Event attribute */
#define ACP10PAR_AUT_EVENT_ST_INDEX         515 /* (USINT) Cam automat: Index next state */
#define ACP10PAR_AUT_SIGNAL_SET             516 /* (USINT) Cam automat: Set signal */
#define ACP10PAR_AUT_ACT_ST_INDEX           517 /* (USINT) Cam automat: Index of the actual state */
#define ACP10PAR_AUT_SIGNAL_RESET           518 /* (USINT) Cam automat: Reset signal */
#define ACP10PAR_AUT_MA_FACTOR              519 /* (DINT) Cam automat: Multiplication factor of master axis */
#define ACP10PAR_AUT_SL_FACTOR              520 /* (DINT) Cam automat: Multiplication factor of slave axis */
#define ACP10PAR_AUT_ST_COUNT_INIT          521 /* (UINT) Cam automat: Initial count of state repetitions for event ncCOUNT */
#define ACP10PAR_AUT_ST_COUNT_SET           522 /* (UINT) Cam automat: Count of state repetitions for event ncCOUNT */
#define ACP10PAR_AUT_COMP_MA_S_MIN          523 /* (DINT) Cam automat: Minimum compensation distance of master axis [Units] */
#define ACP10PAR_CMD_QUICKSTOP              524 /* (NIL) Movement stop: Command quickstop */
#define ACP10PAR_AUT_ONL_PAR_LOCK           527 /* (USINT) Cam automat: Lock for consistent online parameter change */
#define ACP10PAR_AUT_EVENT_ACTION           528 /* (UDINT) Cam automat: Action at state transition */
#define ACP10PAR_AUT_ACT_CAM_TYPE           529 /* (USINT) Cam automat: Cam type of the actual state */
#define ACP10PAR_MA1_CYCLIC_POS             542 /* (DINT) Network coupling: Cyclic position master1 */
#define ACP10PAR_MA2_CYCLIC_POS             543 /* (DINT) Network coupling: Cyclic position master2 */
#define ACP10PAR_PAR_SEQU_INDEX_DATA        544 /* (PAR_SEQU_INDEX, PAR_SEQU) Parameter sequence: Index and data */
#define ACP10PAR_MA3_CYCLIC_POS             548 /* (DINT) Network coupling: Cyclic position master3 */
#define ACP10PAR_AUT_CAM_MA_S_REL           549 /* (DINT) Cam automat: Relative start distance of master axis within cam [Units] */
#define ACP10PAR_AUT_CAM_MA_S_REL_VAX1      550 /* (DINT) VAX Cam automat: Relative start distance of master axis within cam [Units] */
#define ACP10PAR_CMD_AUT_START_VAX1         551 /* (UINT) VAX Cam automat: Command */
#define ACP10PAR_AUT_MA_AXIS_VAX1           552 /* (UINT) VAX Cam automat: Master axis */
#define ACP10PAR_AUT_MA_S_START_VAX1        553 /* (DINT) VAX Cam automat: Start position of the master axis [Units] */
#define ACP10PAR_AUT_MA_IVSTART_VAX1        554 /* (UDINT) VAX Cam automat: Start interval of the master axis [Units] */
#define ACP10PAR_AUT_MA_V_MAX_VAX1          555 /* (REAL) VAX Cam automat: Maximum speed of master axis [Units/s] */
#define ACP10PAR_AUT_ST_INDEX_VAX1          556 /* (USINT) VAX Cam automat: Index of parameter record for one state */
#define ACP10PAR_AUT_EV_INDEX_VAX1          557 /* (USINT) VAX Cam automat: Index of parameter record for one event */
#define ACP10PAR_AUT_ST_DATA_INDEX_VAX1     558 /* (UINT) VAX Cam automat: Index of cam data for one state */
#define ACP10PAR_AUT_COMP_MODE_VAX1         559 /* (USINT) VAX Cam automat: Compensation gears mode */
#define ACP10PAR_AUT_COMP_MA_S_VAX1         560 /* (DINT) VAX Cam automat: Compensation distance of master axis [Units] */
#define ACP10PAR_AUT_COMP_SL_S_VAX1         561 /* (DINT) VAX Cam automat: Compensation distance of slave axis [Units] */
#define ACP10PAR_AUT_EVENT_TYPE_VAX1        562 /* (USINT) VAX Cam automat: Event type */
#define ACP10PAR_AUT_EVENT_ATTR_VAX1        563 /* (USINT) VAX Cam automat: Event attribute */
#define ACP10PAR_AUT_EVENT_ST_INDEX_VAX1    564 /* (USINT) VAX Cam automat: Index next state */
#define ACP10PAR_AUT_SIGNAL_SET_VAX1        565 /* (USINT) VAX Cam automat: Set signal */
#define ACP10PAR_AUT_ACT_ST_INDEX_VAX1      566 /* (USINT) VAX Cam automat: Index of the actual state */
#define ACP10PAR_AUT_SIGNAL_RESET_VAX1      567 /* (USINT) VAX Cam automat: Reset signal */
#define ACP10PAR_AUT_MA_FACTOR_VAX1         568 /* (DINT) VAX Cam automat: Multiplication factor of master axis */
#define ACP10PAR_AUT_SL_FACTOR_VAX1         569 /* (DINT) VAX Cam automat: Multiplication factor of slave axis */
#define ACP10PAR_AUT_ST_COUNT_INIT_VAX1     570 /* (UINT) VAX Cam automat: Initial count of state repetitions for event ncCOUNT */
#define ACP10PAR_AUT_ST_COUNT_SET_VAX1      571 /* (UINT) VAX Cam automat: Count of state repetitions for event ncCOUNT */
#define ACP10PAR_AUT_COMP_MA_S_MIN_VAX1     572 /* (DINT) VAX Cam automat: Minimum compensation distance of master axis [Units] */
#define ACP10PAR_AUT_ONL_PAR_LOCK_VAX1      573 /* (USINT) VAX Cam automat: Lock for consistent online parameter change */
#define ACP10PAR_AUT_EVENT_ACTION_VAX1      574 /* (UDINT) VAX Cam automat: Action at state transition */
#define ACP10PAR_AUT_ACT_CAM_TYPE_VAX1      575 /* (USINT) VAX Cam automat: Cam type of the actual state */
#define ACP10PAR_CMD_MOVEMENT_STOP_VAX1     576 /* (USINT) VAX Movement stop: Command stop movement */
#define ACP10PAR_CMD_HOMING_VAX1            577 /* (DINT) VAX: Command start homing procedure */
#define ACP10PAR_ENCOD2_S_ACT_FILTER        578 /* (DINT) Encoder2: Filtered actual position [Units] */
#define ACP10PAR_AUT_MA_ADD_AXIS            579 /* (UINT) Cam automat: Additive master axis */
#define ACP10PAR_AUT_MA_ADD_AXIS_VAX1       580 /* (UINT) VAX Cam automat: Additive master axis */
#define ACP10PAR_AUT_SL_ADD_AXIS            581 /* (UINT) Cam automat: Additive slave axis */
#define ACP10PAR_AUT_SL_ADD_AXIS_VAX1       582 /* (UINT) VAX Cam automat: Additive slave axis */
#define ACP10PAR_DIG_IN_QUICKSTOP_ENABLE    583 /* (USINT) Digital inputs: Quickstop enable bits */
#define ACP10PAR_USER_I4_VAR1               584 /* (DINT) Function block: User I4 variable1 */
#define ACP10PAR_USER_I4_VAR2               585 /* (DINT) Function block: User I4 variable2 */
#define ACP10PAR_USER_R4_VAR1               586 /* (REAL) Function block: User R4 variable1 */
#define ACP10PAR_USER_R4_VAR2               587 /* (REAL) Function block: User R4 variable2 */
#define ACP10PAR_AUT_TRIG1_T_DELAY          588 /* (DINT) Cam automat: Trigger1 delay time [us] */
#define ACP10PAR_AUT_TRIG2_T_DELAY          589 /* (DINT) Cam automat: Trigger2 delay time [us] */
#define ACP10PAR_STATION_NUMBER_CYCLIC      591 /* (UINT) Network coupling: Station number of sender */
#define ACP10PAR_MA_PARID_CYCLIC_POS        592 /* (UINT) Network coupling: Master Parameter ID of sender station */
#define ACP10PAR_CONFIG_MA1_CYCLIC_POS      593 /* (STATION_NUMBER_CYCLIC, MA_PARID_CYCLIC_POS) Network coupling: Configure station to receive on MA1_CYCLIC_POS */
#define ACP10PAR_CONFIG_MA2_CYCLIC_POS      594 /* (STATION_NUMBER_CYCLIC, MA_PARID_CYCLIC_POS) Network coupling: Configure station to receive on MA2_CYCLIC_POS */
#define ACP10PAR_CONFIG_MA3_CYCLIC_POS      595 /* (STATION_NUMBER_CYCLIC, MA_PARID_CYCLIC_POS) Network coupling: Configure station to receive on MA3_CYCLIC_POS */
#define ACP10PAR_SW_END_A2_POS              600 /* (REAL) Deceleration for positive SW end position [Units/s²] */
#define ACP10PAR_SW_END_A2_NEG              601 /* (REAL) Deceleration for negative SW end position [Units/s²] */
#define ACP10PAR_MA1_CYCLIC_IPL_MODE        602 /* (USINT) Network coupling: Interpolation mode for cyclic position master1 */
#define ACP10PAR_MA2_CYCLIC_IPL_MODE        603 /* (USINT) Network coupling: Interpolation mode for cyclic position master2 */
#define ACP10PAR_MA3_CYCLIC_IPL_MODE        604 /* (USINT) Network coupling: Interpolation mode for cyclic position master3 */
#define ACP10PAR_AUT_SL_LATCH_ID            605 /* (UINT) Cam automat: Parameter ID for latch value of slave axis */
#define ACP10PAR_AUT_SL_LATCH_ID_VAX1       606 /* (UINT) VAX Cam automat: Parameter ID for latch value of slave axis */
#define ACP10PAR_AUT_COMP_SL_S_MIN          607 /* (DINT) Cam automat: Minimum compensation distance of slave axis [Units] */
#define ACP10PAR_AUT_COMP_SL_S_MIN_VAX1     608 /* (DINT) VAX Cam automat: Minimum compensation distance of slave axis [Units] */
#define ACP10PAR_AUT_COMP_SL_S_MAX          609 /* (DINT) Cam automat: Maximum compensation distance of slave axis [Units] */
#define ACP10PAR_AUT_COMP_SL_S_MAX_VAX1     610 /* (DINT) VAX Cam automat: Maximum compensation distance of slave axis [Units] */
#define ACP10PAR_AUT_EVENT_ID               611 /* (UINT) Cam automat: Parameter ID for event */
#define ACP10PAR_AUT_EVENT_ID_VAX1          612 /* (UINT) VAX Cam automat: Parameter ID for event */
#define ACP10PAR_AUT_COMP_SL_V_MIN          613 /* (REAL) Cam automat: Minimum speed of slave axis within compensation gears [Units/s] */
#define ACP10PAR_AUT_COMP_SL_V_MIN_VAX1     614 /* (REAL) VAX Cam automat: Minimum speed of slave axis within compensation gears [Units/s] */
#define ACP10PAR_AUT_MA_CAM_OFFSET          619 /* (DINT) Cam automat: Cam offset of master axis [Units] */
#define ACP10PAR_AUT_SL_CAM_OFFSET          620 /* (DINT) Cam automat: Cam offset of slave axis [Units] */
#define ACP10PAR_AUT_MA_CAM_OFFSET_VAX1     621 /* (DINT) VAX Cam automat: Cam offset of master axis [Units] */
#define ACP10PAR_AUT_SL_CAM_OFFSET_VAX1     622 /* (DINT) VAX Cam automat: Cam offset of slave axis [Units] */
#define ACP10PAR_CMD_AUT_ABS_MOVE           623 /* (DINT) Cam automat: Start movement with absolute target position [Units] */
#define ACP10PAR_STOP_CONF_INDEX_VAX1       624 /* (USINT) VAX Movement stop: Index of parameter record for stop configuration */
#define ACP10PAR_STOP_CONF_RAMP_VAX1        625 /* (USINT) VAX Movement stop: Deceleration ramp */
#define ACP10PAR_MA_CYCLE_TIME_FACTOR       626 /* (UDINT) Network coupling: Multiplication factor of cycle time */
#define ACP10PAR_AUT_ST_EV_COUNT            627 /* (UDINT) Cam automat: State transition count */
#define ACP10PAR_AUT_ST_EV_COUNT_VAX1       628 /* (UDINT) VAX Cam automat: State transition count */
#define ACP10PAR_ERROR_NUMBER_VAX1          630 /* (UINT) VAX Messages: Error number */
#define ACP10PAR_ERROR_INFO_VAX1            631 /* (DINT) VAX Messages: Additional error info */
#define ACP10PAR_ERROR_REC_VAX1             632 /* (ERROR_NUMBER_VAX1, ERROR_INFO_VAX1) VAX Messages: Error record */
#define ACP10PAR_AUT_ACT_ST_DAT_IDX         633 /* (UINT) Cam automat: Index of cam data of the actual state */
#define ACP10PAR_AUT_ACT_ST_DAT_IDX_VAX1    634 /* (UINT) VAX Cam automat: Index of cam data of the actual state */
#define ACP10PAR_LIM_A_SET_STOP             635 /* (REAL) Limit values: Maximum acceleration for stop of a movement [Units/s²] */
#define ACP10PAR_CMD_PAR_SEQU_INIT_VAX1     636 /* (UINT) VAX: Initialize parameter sequence */
#define ACP10PAR_AUT_MA_ID                  637 /* (UINT) Cam automat: Parameter ID of master axis */
#define ACP10PAR_AUT_MA_ID_VAX1             638 /* (UINT) VAX Cam automat: Parameter ID of master axis */
#define ACP10PAR_AUT_COMP_SL_T_JOLT         639 /* (REAL) Cam automat: Jolt time of slave axis within compensation gears [s] */
#define ACP10PAR_AUT_COMP_SL_T_JOLT_VAX1    640 /* (REAL) VAX Cam automat: Jolt time of slave axis within compensation gears [s] */
#define ACP10PAR_CMD_CYC_V_MOVE             641 /* (UINT) Basis movements: Start movement with cyclic speed set values */
#define ACP10PAR_CMD_CYC_V_MOVE_VAX1        642 /* (UINT) VAX Basis movements: Start movement with cyclic speed set values */
#define ACP10PAR_CYC_V_MOVE_PARID           643 /* (UINT) Basis movements: Parameter ID for cyclic set speed */
#define ACP10PAR_CYC_V_MOVE_PARID_VAX1      644 /* (UINT) VAX Basis movements: Parameter ID for cyclic set speed */
#define ACP10PAR_KSCTRL_TORQUE_LIM          651 /* (REAL) CTRL Torque limiter: Induction stop: Maximum torque [Nm] */
#define ACP10PAR_MOTOR_ENCOD_ATTR           652 /* (UINT) Motor: Encoder: Attribute */
#define ACP10PAR_UFCTRL_TYPE                653 /* (USINT) CTRL U/f: Type */
#define ACP10PAR_UFCTRL_AUTO_CONFIG         654 /* (USINT) CTRL U/f: Automatic configuration */
#define ACP10PAR_UFCTRL_VOLT_BOOST          655 /* (REAL) CTRL U/f: Boost voltage [V] */
#define ACP10PAR_UFCTRL_VOLT_RATED          656 /* (REAL) CTRL U/f: Rated voltage [V] */
#define ACP10PAR_UFCTRL_FREQ_RATED          657 /* (REAL) CTRL U/f: Rated frequency [Hz] */
#define ACP10PAR_MOTOR_DATA_IDX             658 /* (UINT) Motor: Dataset index */
#define ACP10PAR_ENCOD_ADC2                 659 /* (REAL) Encoder1: ADC2 value */
#define ACP10PAR_SIM_MODE                   660 /* (UINT) Simulation mode: Model */
#define ACP10PAR_SIM_INERTIA1               661 /* (REAL) Simulation mode: Mass moment of inertia1 [kgm²] */
#define ACP10PAR_SIM_STATIC_FRICTION1       662 /* (REAL) Simulation mode: Static friction1 [Nm] */
#define ACP10PAR_SIM_VISCOUS_FRICTION1      663 /* (REAL) Simulation mode: Viscous friction1 [Nms] */
#define ACP10PAR_SIM_ADD_LOAD_PARID         664 /* (UINT) Simulation mode: Parameter for additive load */
#define ACP10PAR_ENCOD_REF_CHK_DELTA        665 /* (DINT) Encoder1: INC Reference pulse interval error [Incr] */
#define ACP10PAR_ENCOD2_REF_CHK_DELTA       666 /* (DINT) Encoder2: INC Reference pulse interval error [Incr] */
#define ACP10PAR_ENCOD3_REF_CHK_DELTA       667 /* (DINT) Encoder3: INC Reference pulse interval error [Incr] */
#define ACP10PAR_TEMP_MOTOR_AMB             668 /* (REAL) Motor: Ambient temperature [°C] */
#define ACP10PAR_LOAD_POWER                 670 /* (REAL) Inverter: Continuous power: Load [%] */
#define ACP10PAR_LOAD_POWER_MAX             671 /* (REAL) Inverter: Continuous power: Maximum load [%] */
#define ACP10PAR_VCTRL_ENCOD_COUNT_DIR      672 /* (USINT) Motor encoder: Load scaling: Count direction */
#define ACP10PAR_VCTRL_SCALE_LOAD_UNITS     673 /* (UDINT) Motor encoder: Load scaling: Units per load revolutions [Units] */
#define ACP10PAR_VCTRL_SCALE_LOAD_MOTREV    674 /* (UDINT) Motor encoder: Load scaling: Encoder revolutions per load revolution */
#define ACP10PAR_ENCOD_REF_CHK_MODE         675 /* (UINT) Encoder1: INC Reference pulse check mode */
#define ACP10PAR_ENCOD2_REF_CHK_MODE        676 /* (UINT) Encoder2: INC Reference pulse check mode */
#define ACP10PAR_ENCOD3_REF_CHK_MODE        677 /* (UINT) Encoder3: INC Reference pulse check mode */
#define ACP10PAR_ENCOD_REF_CHK_WINDOW       678 /* (UDINT) Encoder1: INC Reference pulse check window [Incr] */
#define ACP10PAR_ENCOD2_REF_CHK_WINDOW      679 /* (UDINT) Encoder2: INC Reference pulse check window [Incr] */
#define ACP10PAR_ENCOD3_REF_CHK_WINDOW      680 /* (UDINT) Encoder3: INC Reference pulse check window [Incr] */
#define ACP10PAR_ENCOD_REF_WIDTH            681 /* (UDINT) Encoder1: INC Reference pulse width [Incr] */
#define ACP10PAR_ENCOD2_REF_WIDTH           682 /* (UDINT) Encoder2: INC Reference pulse width [Incr] */
#define ACP10PAR_ENCOD3_REF_WIDTH           683 /* (UDINT) Encoder3: INC Reference pulse width [Incr] */
#define ACP10PAR_ENCOD_REF_INTERVAL         684 /* (UDINT) Encoder1: INC Reference pulse interval [Incr] */
#define ACP10PAR_ENCOD2_REF_INTERVAL        685 /* (UDINT) Encoder2: INC Reference pulse interval [Incr] */
#define ACP10PAR_ENCOD3_REF_INTERVAL        686 /* (UDINT) Encoder3: INC Reference pulse interval [Incr] */
#define ACP10PAR_SCTRL_LIM_V_POS            687 /* (REAL) CTRL Speed controller: Speed limit positive direction [1/s] */
#define ACP10PAR_SCTRL_LIM_V_NEG            688 /* (REAL) CTRL Speed controller: Speed limit negative direction [1/s] */
#define ACP10PAR_PCTRL_SPEED_REF_I          692 /* (REAL) CTRL Position controller: Manipulated variable of integrator [Units/s] */
#define ACP10PAR_ENCOD3_POS_ACT             693 /* (DINT) Encoder3: Actual position per revolution [Incr] */
#define ACP10PAR_SCALE_ENCOD3_UNITS         694 /* (UDINT) Encoder3: Load scaling: Units per load revolution [Units] */
#define ACP10PAR_SCALE_ENCOD3_REV           695 /* (UDINT) Encoder3: Load scaling: Encoder revolutions */
#define ACP10PAR_ENCOD3_COUNT_DIR           696 /* (USINT) Encoder3: Load scaling: Count direction */
#define ACP10PAR_ENCOD3_S_ACT               697 /* (DINT) Encoder3: Actual position [Units] */
#define ACP10PAR_ENCOD3_STATUS              698 /* (UDINT) Encoder3: Status */
#define ACP10PAR_ENCOD3_SSI_ZERO_BITS       699 /* (USINT) Encoder3: SSI Number of leading zeros */
#define ACP10PAR_ENCOD3_SSI_BITS            700 /* (USINT) Encoder3: SSI Number of data bits */
#define ACP10PAR_ENCOD3_SSI_CODE            701 /* (USINT) Encoder3: SSI Data code */
#define ACP10PAR_ENCOD3_SSI_PARITY_CHK      702 /* (USINT) Encoder3: SSI Parity check */
#define ACP10PAR_SCALE_ENCOD3_INCR          703 /* (UDINT) Encoder3: Encoder scaling: Increments per encoder revolution */
#define ACP10PAR_ENCOD3_TYPE                704 /* (USINT) Encoder3: Type */
#define ACP10PAR_ENCOD3_S_FILTER_T10        708 /* (REAL) Encoder3: Time constant for actual position filter [s] */
#define ACP10PAR_STAT_ENC3_HOMING_OK        709 /* (UDINT) Encoder3: Status home position valid */
#define ACP10PAR_ENCOD3_S_ACT_FILTER        710 /* (DINT) Encoder3: Filtered actual position [Units] */
#define ACP10PAR_ENCOD3_OUT_PARID           711 /* (UINT) Encoder3: Emulation: Output parameter ID */
#define ACP10PAR_ENCOD2_OUT_PARID           712 /* (UINT) Encoder2: Emulation: Output parameter ID */
#define ACP10PAR_ICTRL_SET_PARID            713 /* (UINT) CTRL Current controller: Set value parameter ID of stator current quadrature component  */
#define ACP10PAR_MA1_CYCLIC_ERROR_STATUS    714 /* (USINT) Network coupling: Error status for cyclic position master1 */
#define ACP10PAR_MA2_CYCLIC_ERROR_STATUS    715 /* (USINT) Network coupling: Error status for cyclic position master2 */
#define ACP10PAR_MA3_CYCLIC_ERROR_STATUS    716 /* (USINT) Network coupling: Error status for cyclic position master3 */
#define ACP10PAR_CMD_CTRL_OFF_BRAKE_ON      717 /* (NIL) CTRL Controller: Power off */
#define ACP10PAR_ENCOD_ERROR_MODE           718 /* (UINT) Encoder1: Error Mode */
#define ACP10PAR_ENCOD_CMD                  719 /* (UDINT) Encoder1: Encoder command */
#define ACP10PAR_VCTRL_S_ACT_PARID          722 /* (UINT) CTRL Vector controller: Actual position parameter ID */
#define ACP10PAR_ENCOD2_SSI_LINE_RES        723 /* (DINT) Encoder2: Serial resolution per sinus period */
#define ACP10PAR_ENCOD3_SSI_LINE_RES        724 /* (DINT) Encoder3: Serial resolution per sinus period */
#define ACP10PAR_ICTRL_ISD_SET_PARID        725 /* (UINT) CTRL Current controller: Set value parameter ID of stator current direct component  */
#define ACP10PAR_SCTRL_ENABLE_PARID         726 /* (UINT) CTRL Speed controller: Parameter ID enable input */
#define ACP10PAR_ENCOD_LINE_CHK_IGNORE      727 /* (UINT) Encoder1: Ignore check */
#define ACP10PAR_ENCOD2_LINE_CHK_IGNORE     728 /* (UINT) Encoder2: Ignore check */
#define ACP10PAR_ENCOD3_LINE_CHK_IGNORE     729 /* (UINT) Encoder3: Ignore check */
#define ACP10PAR_ENCOD_INC_MODE             730 /* (UINT) Encoder1: INC mode */
#define ACP10PAR_ENCOD2_INC_MODE            731 /* (UINT) Encoder2: INC mode */
#define ACP10PAR_ENCOD3_INC_MODE            732 /* (UINT) Encoder3: INC mode */
#define ACP10PAR_ENCOD_INC_SIN_AMP          733 /* (REAL) Encoder1: INC square of the standardized signal amplitude */
#define ACP10PAR_ENCOD2_INC_SIN_AMP         734 /* (REAL) Encoder2: INC square of the standardized signal amplitude */
#define ACP10PAR_ENCOD3_INC_SIN_AMP         735 /* (REAL) Encoder3: INC square of the standardized signal amplitude */
#define ACP10PAR_ENCOD_INC_SIN_KV           736 /* (DINT) Encoder1: EnDat Amplitude amplification */
#define ACP10PAR_ENCOD2_INC_SIN_KV          737 /* (DINT) Encoder2: EnDat Amplitude amplification */
#define ACP10PAR_ENCOD3_INC_SIN_KV          738 /* (DINT) Encoder3: EnDat Amplitude amplification */
#define ACP10PAR_ENCOD_REF_DCM_DISTANCE     739 /* (UDINT) Encoder1: DCM Basic distance [Lines] */
#define ACP10PAR_ENCOD2_REF_DCM_DISTANCE    740 /* (UDINT) Encoder2: DCM Basic distance [Lines] */
#define ACP10PAR_ENCOD3_REF_DCM_DISTANCE    741 /* (UDINT) Encoder3: DCM Basic distance [Lines] */
#define ACP10PAR_SLOT1_MODULE_ID            742 /* (UINT) System administration: Plug-in module: ID from slot 1 */
#define ACP10PAR_SLOT2_MODULE_ID            743 /* (UINT) System administration: Plug-in module: ID from slot 2 */
#define ACP10PAR_SLOT3_MODULE_ID            744 /* (UINT) System administration: Plug-in module: ID from slot 3 */
#define ACP10PAR_SLOT4_MODULE_ID            745 /* (UINT) System administration: Plug-in module: ID from slot 4 */
#define ACP10PAR_FFCTRL_TORQUE_LOAD         746 /* (REAL) CTRL Feed forward: Load torque [Nm] */
#define ACP10PAR_FFCTRL_T_FILTER_A          747 /* (REAL) CTRL Feed forward: Acceleration filter time constant [s] */
#define ACP10PAR_UDC_ISQ_LIM_MAX            748 /* (REAL) CTRL DC bus: Limiter: Upper current limit */
#define ACP10PAR_UDC_ISQ_LIM_MIN            749 /* (REAL) CTRL DC bus: Limiter: Lower current limit */
#define ACP10PAR_PAR_SEQU                   750 /* (DATA) Parameter sequence: Data */
#define ACP10PAR_PAR_SEQU_INDEX             751 /* (UINT) Parameter sequence: Index for Upload/Download */
#define ACP10PAR_CMD_PAR_SEQU_INIT          752 /* (UINT) Parameter sequence: Initialize parameter */
#define ACP10PAR_ENCOD1_S_FILTER_T10        755 /* (REAL) Encoder1: Time constant for actual position filter [s] */
#define ACP10PAR_ENCOD1_S_ACT_FILTER        756 /* (DINT) Encoder1: Filtered actual position [Units] */
#define ACP10PAR_PCTRL_SYS_TIME             757 /* (UDINT) Drive synchronisation: Total time within the position controller cycle [us] */
#define ACP10PAR_AUT_EV_STATUS_BITS         760 /* (UDINT) Cam automat: Event status bits */
#define ACP10PAR_AUT_EV_STATUS_BITS_VAX1    761 /* (UDINT) VAX Cam automat: Event status bits */
#define ACP10PAR_AUT_COMP_SL_V_MAX          764 /* (REAL) Cam automat: Maximum speed of slave axis within compensation gears [Units/s] */
#define ACP10PAR_AUT_COMP_SL_V_MAX_VAX1     765 /* (REAL) VAX Cam automat: Maximum speed of slave axis within compensation gears [Units/s] */
#define ACP10PAR_AUT_COMP_SL_A1_MAX         766 /* (REAL) Cam automat: Maximum acceleration of slave axis within compensation phase1 [Units/s²] */
#define ACP10PAR_AUT_COMP_SL_A1_MAX_VAX1    767 /* (REAL) VAX Cam automat: Maximum acceleration of slave axis within compensation phase1 [Units/s²] */
#define ACP10PAR_AUT_COMP_SL_A2_MAX         768 /* (REAL) Cam automat: Maximum acceleration of slave axis within compensation phase2 [Units/s²] */
#define ACP10PAR_AUT_COMP_SL_A2_MAX_VAX1    769 /* (REAL) VAX Cam automat: Maximum acceleration of slave axis within compensation phase2 [Units/s²] */
#define ACP10PAR_AUT_POLY_CHECK             770 /* (UINT) Cam automat: Check cam polynomial data */
#define ACP10PAR_AUT_S_SET                  771 /* (DINT) Cam automat: Set position [Units] */
#define ACP10PAR_CMD_AUT_ST_CHECK           772 /* (USINT) Cam automat: Check parameter record for one state */
#define ACP10PAR_CMD_AUT_ST_CHECK_VAX1      773 /* (USINT) VAX Cam automat: Check parameter record for one state */
#define ACP10PAR_ENCOD1_S_FILTER_TE         774 /* (REAL) Encoder1: Extrapolation time for actual position filter [s] */
#define ACP10PAR_ENCOD2_S_FILTER_TE         775 /* (REAL) Encoder2: Extrapolation time for actual position filter [s] */
#define ACP10PAR_ENCOD3_S_FILTER_TE         776 /* (REAL) Encoder3: Extrapolation time for actual position filter [s] */
#define ACP10PAR_FUNCTION_BLOCK_CREATE      777 /* (UINT) Function block: Create a FB instance */
#define ACP10PAR_CMD_CYC_ABS_MOVE           778 /* (UINT) Basis movements: Start movement with cyclic position set values */
#define ACP10PAR_CMD_CYC_ABS_MOVE_VAX1      779 /* (UINT) VAX Basis movements: Start movement with cyclic position set values */
#define ACP10PAR_CYC_ABS_MOVE_PARID         780 /* (UINT) Basis movements: Parameter ID for cyclic set position */
#define ACP10PAR_CYC_ABS_MOVE_PARID_VAX1    781 /* (UINT) VAX Basis movements: Parameter ID for cyclic set position */
#define ACP10PAR_OVERRIDE_VAX1              782 /* (V_OVERRIDE_VAX1, A_OVERRIDE_VAX1) VAX Basis movements: Override */
#define ACP10PAR_V_OVERRIDE_VAX1            783 /* (INT) VAX Basis movements: Speed override */
#define ACP10PAR_A_OVERRIDE_VAX1            784 /* (INT) VAX Basis movements: Acceleration override */
#define ACP10PAR_CYCLIC_MON_PAR_INDEX       787 /* (USINT) Cyclic communication: Parameter index of monitor data from drive */
#define ACP10PAR_CYCLIC_MON_PARID           788 /* (UINT) Cyclic communication: Parameter ID of monitor data from drive */
#define ACP10PAR_TRIG1_RISE_EDGE_TIME       789 /* (UDINT) Digital inputs: Time of rising edge trigger1 [us] */
#define ACP10PAR_TRIG1_FALL_EDGE_TIME       790 /* (UDINT) Digital inputs: Time of falling edge trigger1 [us] */
#define ACP10PAR_TRIG2_RISE_EDGE_TIME       791 /* (UDINT) Digital inputs: Time of rising edge trigger2 [us] */
#define ACP10PAR_TRIG2_FALL_EDGE_TIME       792 /* (UDINT) Digital inputs: Time of falling edge trigger2 [us] */
#define ACP10PAR_STAT_ENABLE                794 /* (UDINT) Digital inputs: Status enable */
#define ACP10PAR_AUT_SL_FACTOR_ID           795 /* (UINT) Cam automat: Parameter ID for multiplication factor of slave axis */
#define ACP10PAR_AUT_SL_FACTOR_ID_VAX1      796 /* (UINT) VAX Cam automat: Parameter ID for multiplication factor of slave axis */
#define ACP10PAR_AUT_MSG_MODE_BITS          798 /* (UDINT) Cam automat: Control bits for message mode */
#define ACP10PAR_SGEN_SW_END_IGNORE_VAX1    799 /* (USINT) VAX Limit values: Ignore SW end positions */
#define ACP10PAR_AXLIM_T_CTRL_STOP_END      800 /* (REAL) Limit values: Minimum time for 'controller active' after movement stop [s] */
#define ACP10PAR_OBS_POS2_PARA_A0           801 /* (REAL) Position observer 2: Parameter A0 */
#define ACP10PAR_OBS_POS2_PARA_A1           802 /* (REAL) Position observer 2: Parameter A1 */
#define ACP10PAR_OBS_POS2_PARA_A2           803 /* (REAL) Position observer 2: Parameter A2 */
#define ACP10PAR_ELC_TRANSFER_LEVEL         805 /* (REAL) Encoderless control: Transition level [1/s] */
#define ACP10PAR_ELC_TRANSFER_ZONE          806 /* (REAL) Encoderless control: Transition zone [1/s] */
#define ACP10PAR_INVCL_A1                   817 /* (REAL) Inverter adjustment: Amplification factor */
#define ACP10PAR_INVCL_A2                   818 /* (REAL) Inverter adjustment: Exponent [1/A] */
#define ACP10PAR_ENCOD2_ADC1                819 /* (REAL) Encoder2: ADC1 value */
#define ACP10PAR_ENCOD2_ADC2                820 /* (REAL) Encoder2: ADC2 value */
#define ACP10PAR_ENCOD3_ADC1                821 /* (REAL) Encoder3: ADC1 value */
#define ACP10PAR_ENCOD3_ADC2                822 /* (REAL) Encoder3: ADC2 value */
#define ACP10PAR_ENCOD2_DIAG1               823 /* (REAL) Encoder2: Diagnosis 1 */
#define ACP10PAR_ISQ_FILTER1_C0_PARID       824 /* (UINT) CTRL Speed controller: Set current filter1 parameter ID for coefficient C0 */
#define ACP10PAR_ISQ_FILTER2_C0_PARID       825 /* (UINT) CTRL Speed controller: Set current filter2 parameter ID for coefficient C0 */
#define ACP10PAR_ISQ_FILTER3_C0_PARID       826 /* (UINT) CTRL Speed controller: Set current filter3 parameter ID for coefficient C0 */
#define ACP10PAR_ISQ_FILTER1_C1_PARID       827 /* (UINT) CTRL Speed controller: Set current filter1 parameter ID for coefficient C1 */
#define ACP10PAR_ISQ_FILTER2_C1_PARID       828 /* (UINT) CTRL Speed controller: Set current filter2 parameter ID for coefficient C1 */
#define ACP10PAR_ISQ_FILTER3_C1_PARID       829 /* (UINT) CTRL Speed controller: Set current filter3 parameter ID for coefficient C1 */
#define ACP10PAR_TPRED_TIME                 830 /* (DINT) Temperature prediction: Observation time [us] */
#define ACP10PAR_TPRED_TIME_IV              831 /* (DINT) Temperature prediction: Observation period [us] */
#define ACP10PAR_TPRED_CNT                  832 /* (DINT) Temperature prediction: Counter */
#define ACP10PAR_TEMP_HEATSINK_PRED         833 /* (REAL) Power stage: Heatsink temperature sensor: Predicted temperature [°C] */
#define ACP10PAR_TEMP_JUNCTION_PRED         834 /* (REAL) Inverter: Junction temperature model: Predicted temperature [°C] */
#define ACP10PAR_TEMP_BLEEDER_PRED          835 /* (REAL) Bleeder: Temperature model: Predicted temperature [°C] */
#define ACP10PAR_LOAD_MOTOR_MODEL_PRED      836 /* (REAL) Motor: Temperature model: Predicted load [%] */
#define ACP10PAR_TEMP_MOTOR_MODEL_PRED      837 /* (REAL) Motor: Temperature model: Predicted temperature [°C] */
#define ACP10PAR_LOAD_CONT_CURR_PRED        838 /* (REAL) Inverter: Continuous current: Predicted load [%] */
#define ACP10PAR_LOAD_PEAK_CURR_PRED        839 /* (REAL) Inverter: Peak current: Predicted load [%] */
#define ACP10PAR_LOAD_POWER_PRED            840 /* (REAL) Inverter: Continuous power: Predicted load [%] */
#define ACP10PAR_TEMP_HEATSINK_LIM          841 /* (REAL) Power stage: Heatsink temperature sensor: Limit temperature [°C] */
#define ACP10PAR_TEMP_JUNCTION_LIM          842 /* (REAL) Inverter: Junction temperature model: Limit temperature [°C] */
#define ACP10PAR_TEMP_BLEEDER_LIM           843 /* (REAL) Bleeder: Temperature model: Limit temperature [°C] */
#define ACP10PAR_MOTOR_TERMINAL_POWER       844 /* (REAL) Inverter: Output: Power [W] */
#define ACP10PAR_VCTRL_USD_REF_PARID        845 /* (UINT) CTRL Voltage controller: Parameter ID of set value stator voltage direct component  */
#define ACP10PAR_VCTRL_USQ_REF_PARID        846 /* (UINT) CTRL Voltage controller: Parameter ID of set value stator voltage quadrature component  */
#define ACP10PAR_VCTRL_RHO_REF_PARID        847 /* (UINT) CTRL Vector controller: Parameter-ID of commutation angle */
#define ACP10PAR_FWCTRL_TN                  848 /* (REAL) CTRL Flux weakening: Integral action time [s] */
#define ACP10PAR_MOTOR_TAU_THERM            849 /* (REAL) Motor: Thermal time constant [s] */
#define ACP10PAR_UCTRL_KV                   850 /* (REAL) CTRL DC bus: Proportional amplification factor [A/V] */
#define ACP10PAR_UCTRL_UDC_REF              851 /* (REAL) CTRL DC bus: Set value voltage [V] */
#define ACP10PAR_UCTRL_ISQ_REF              852 /* (REAL) CTRL DC bus: Set value current [A] */
#define ACP10PAR_UCTRL_UDC_REF_PARID        853 /* (UINT) CTRL DC bus: Parameter ID set value voltage */
#define ACP10PAR_TEMP_MODUL3                859 /* (REAL) Power stage: Temperature sensor 3: Temperature [°C] */
#define ACP10PAR_TEMP_MODUL4                860 /* (REAL) Power stage: Temperature sensor 4: Temperature [°C] */
#define ACP10PAR_TEMP_AIRIN                 861 /* (REAL) Power stage: Temperature sensor 1: Temperature [°C] */
#define ACP10PAR_TEMP_AIROUT                862 /* (REAL) Power stage: Temperature sensor 2: Temperature [°C] */
#define ACP10PAR_VCTRL_I3                   863 /* (REAL) Inverter: Phase 3: Current [A] */
#define ACP10PAR_VCTRL_I0                   864 /* (REAL) Inverter: Summation current [A] */
#define ACP10PAR_MOTOR_AMB_TEMP_RATED       865 /* (REAL) Motor: Nominal ambient temperature [°C] */
#define ACP10PAR_MOTOR_TEST_MODE            866 /* (UDINT) Motor: Test mode */
#define ACP10PAR_MAINS_SWITCH_PARID         867 /* (UINT) Power mains: Parameter ID external main relay status */
#define ACP10PAR_POWERSTAGE_STAT            868 /* (UDINT) Power stage: Status */
#define ACP10PAR_ICTRL_MODE                 869 /* (UDINT) CTRL Current: Mode */
#define ACP10PAR_FCTRL_MODE                 870 /* (UDINT) CTRL Flux: Mode */
#define ACP10PAR_FCTRL_IM_LIM_MIN           871 /* (REAL) CTRL Flux:  Magnetizing current limiter: Lower limit [A] */
#define ACP10PAR_MOTOR_CURR_ROT_DIR         872 /* (USINT) Motor: Rotational direction of current */
#define ACP10PAR_UCTRL_TN                   873 /* (REAL) CTRL DC bus: Integral action time [s] */
#define ACP10PAR_PHASING_TIME               874 /* (REAL) Motor: Phasing: Time [s] */
#define ACP10PAR_TUNE_PHASE_CROSSOVER_F     875 /* (REAL) Autotuning: Phase crossover frequency of the plant [Hz] */
#define ACP10PAR_BLEEDER_POWER_LOSS         876 /* (REAL) Bleeder: Power loss [W] */
#define ACP10PAR_ISQ_RIPPLE_MODE            877 /* (UDINT) ISQ-Ripple compensation: Mode    */
#define ACP10PAR_PIDENT_SPEED               878 /* (REAL) Parameter identification: Speed [Units/s] */
#define ACP10PAR_COMMUT_CURR_FFTIME         880 /* (REAL) CTRL vector: Current feed forward time [s] */
#define ACP10PAR_ISQ_RIPPLE                 881 /* (REAL) ISQ-Ripple compensation: Current [A] */
#define ACP10PAR_ISQ_RIPPLE_DAT_IDX         882 /* (DINT) ISQ-Ripple compensation: Data: Index */
#define ACP10PAR_ISQ_RIPPLE_DAT_F           883 /* (REAL) ISQ-Ripple compensation: Data: Frequency [cps] */
#define ACP10PAR_ISQ_RIPPLE_DAT_A           884 /* (REAL) ISQ-Ripple compensation: Data: Parameter A */
#define ACP10PAR_ISQ_RIPPLE_DAT_PHI         885 /* (REAL) ISQ-Ripple compensation: Data: Angle [rad] */
#define ACP10PAR_ISQ_RIPPLE_SPEC_IDX        886 /* (DINT) ISQ-Ripple compensation: Data: Index of spectrum   */
#define ACP10PAR_ENCOD_RANGE_REV            887 /* (UDINT) Encoder1: Absolute measuring range [Rev.] */
#define ACP10PAR_ENCOD2_RANGE_REV           888 /* (UDINT) Encoder2: Absolute measuring range [Rev.] */
#define ACP10PAR_ENCOD3_RANGE_REV           889 /* (UDINT) Encoder3: Absolute measuring range [Rev.] */
#define ACP10PAR_SCTRL_SPEED_REF_SUM        890 /* (REAL) CTRL Speed controller: Sum of the set speeds [1/s] */
#define ACP10PAR_ENCOD_OUTPUT_FREQUENCY     891 /* (UDINT) Encoder1: Maximal expected output frequency [Hz] */
#define ACP10PAR_ENCOD_OUTPUT_STAGE         892 /* (USINT) Encoder1: Output stage */
#define ACP10PAR_ENCOD_DIAG2                893 /* (REAL) Encoder1: Diagnosis 2 */
#define ACP10PAR_ENCOD_DIAG3                894 /* (REAL) Encoder1: Diagnosis 3 */
#define ACP10PAR_ENCOD_TEMP                 895 /* (REAL) Encoder1: Temperature [°C] */
#define ACP10PAR_ENCOD_CRC_POLYNOMIAL       896 /* (UDINT) Encoder1: CRC Polynomial */
#define ACP10PAR_ENCOD2_CRC_POLYNOMIAL      897 /* (UDINT) Encoder2: CRC Polynomial */
#define ACP10PAR_ENCOD_ERR_CNT              898 /* (UDINT) Encoder1: Error count */
#define ACP10PAR_ENCOD3_CRC_POLYNOMIAL      899 /* (UDINT) Encoder3: CRC Polynomial */
#define ACP10PAR_AUT_STATUS                 900 /* (USINT) Cam automat: Status */
#define ACP10PAR_AUT_STATUS_VAX1            901 /* (USINT) VAX Cam automat: Status */
#define ACP10PAR_MA4_CYCLIC_POS             902 /* (DINT) Network coupling: Cyclic position master4 */
#define ACP10PAR_MA5_CYCLIC_POS             903 /* (DINT) Network coupling: Cyclic position master5 */
#define ACP10PAR_CONFIG_MA4_CYCLIC_POS      904 /* (STATION_NUMBER_CYCLIC, MA_PARID_CYCLIC_POS) Network coupling: Configure station to receive on MA4_CYCLIC_POS */
#define ACP10PAR_CONFIG_MA5_CYCLIC_POS      905 /* (STATION_NUMBER_CYCLIC, MA_PARID_CYCLIC_POS) Network coupling: Configure station to receive on MA5_CYCLIC_POS */
#define ACP10PAR_MA4_CYCLIC_IPL_MODE        906 /* (USINT) Network coupling: Interpolation mode for cyclic position master4 */
#define ACP10PAR_MA5_CYCLIC_IPL_MODE        907 /* (USINT) Network coupling: Interpolation mode for cyclic position master5 */
#define ACP10PAR_AXLIM_T_STOP_END           908 /* (REAL) Limit values: Minimum time induction stop [s] */
#define ACP10PAR_CYCLIC_TODRV_COUNT         909 /* (UDINT) Cyclic communication: Count of data to drive */
#define ACP10PAR_MOVE_CONF_IDX              910 /* (USINT) Move configuration: Index of parameter record */
#define ACP10PAR_MOVE_CONF_V_POS            911 /* (REAL) Move configuration: Maximum speed in positive direction [Units/s] */
#define ACP10PAR_MOVE_CONF_V_NEG            912 /* (REAL) Move configuration: Maximum speed in negative direction [Units/s] */
#define ACP10PAR_MOVE_CONF_A1_POS           913 /* (REAL) Move configuration: Maximum acceleration in positive direction [Units/s²] */
#define ACP10PAR_MOVE_CONF_A2_POS           914 /* (REAL) Move configuration: Maximum deceleration in positive direction [Units/s²] */
#define ACP10PAR_MOVE_CONF_A1_NEG           915 /* (REAL) Move configuration: Maximum acceleration in negative direction [Units/s²] */
#define ACP10PAR_MOVE_CONF_A2_NEG           916 /* (REAL) Move configuration: Maximum deceleration in negative direction [Units/s²] */
#define ACP10PAR_AUT_MOVE_CONF_IDX          917 /* (USINT) Cam automat: Index of parameter record of move configuration */
#define ACP10PAR_AUT_TRIG1_T_DELAY_VAX1     918 /* (DINT) VAX Cam automat: Trigger1 delay time [us] */
#define ACP10PAR_AUT_TRIG2_T_DELAY_VAX1     919 /* (DINT) VAX Cam automat: Trigger2 delay time [us] */
#define ACP10PAR_AUT_MODE_BITS              920 /* (UDINT) Cam automat: Control bits for function mode */
#define ACP10PAR_AUT_MODE_BITS_VAX1         921 /* (UDINT) VAX Cam automat: Control bits for function mode */
#define ACP10PAR_CYCLIC_DP_DATA_OFFSET      922 /* (UINT) Network coupling: Receive data point: Bit offset within the data field of the frame */
#define ACP10PAR_CYCLIC_DP_DATA_TYPE        923 /* (UINT) Network coupling: Receive data point: Data type */
#define ACP10PAR_AUT_S_SHIFT_START          924 /* (DINT) Cam automat: Position shift at the start [Units] */
#define ACP10PAR_CMD_MOVE_CONF_IDX          925 /* (USINT) Basis movements: Index of parameter record of move configuration */
#define ACP10PAR_AUT_S_START_MODE           926 /* (USINT) Cam automat: Mode for event type ncS_START */
#define ACP10PAR_AUT_S_START_MODE_VAX1      927 /* (USINT) VAX Cam automat: Mode for event type ncS_START */
#define ACP10PAR_MODULO_PERIOD              928 /* (DINT) Basis movements: Position period [Units] */
#define ACP10PAR_MODULO_OFFSET              929 /* (DINT) Basis movements: Offset of actual period [Units] */
#define ACP10PAR_MODULO_DIRECTION           930 /* (USINT) Basis movements: Movement direction in relation to the position period */
#define ACP10PAR_CMD_MODULO_MOVE            931 /* (BASIS_MOVE_S_ABS, BASIS_MOVE_MODE) Basis movements: Start movement with target position of a period */
#define ACP10PAR_MODULO_PERIOD_VAX1         932 /* (DINT) VAX Basis movements: Position period [Units] */
#define ACP10PAR_MODULO_OFFSET_VAX1         933 /* (DINT) VAX Basis movements: Offset of actual period [Units] */
#define ACP10PAR_MODULO_DIRECTION_VAX1      934 /* (USINT) VAX Basis movements: Movement direction in relation to the position period */
#define ACP10PAR_CMD_MODULO_MOVE_VAX1       935 /* (BASIS_MOVE_S_ABS_VAX1) VAX Basis movements: Start movement with target position of a period */
#define ACP10PAR_AUT_EVENT_ID1              936 /* (UINT) Cam automat: Parameter ID1 for event */
#define ACP10PAR_AUT_EVENT_ID2              937 /* (UINT) Cam automat: Parameter ID2 for event */
#define ACP10PAR_AUT_EVENT_ID3              938 /* (UINT) Cam automat: Parameter ID3 for event */
#define ACP10PAR_AUT_EVENT_ID4              939 /* (UINT) Cam automat: Parameter ID4 for event */
#define ACP10PAR_AUT_EVENT_ID1_VAX1         940 /* (UINT) VAX Cam automat: Parameter ID1 for event */
#define ACP10PAR_AUT_EVENT_ID2_VAX1         941 /* (UINT) VAX Cam automat: Parameter ID2 for event */
#define ACP10PAR_AUT_EVENT_ID3_VAX1         942 /* (UINT) VAX Cam automat: Parameter ID3 for event */
#define ACP10PAR_AUT_EVENT_ID4_VAX1         943 /* (UINT) VAX Cam automat: Parameter ID4 for event */
#define ACP10PAR_REFERENCE_SWITCH_PARID     944 /* (UINT) Digital inputs: Parameter ID for reference switch */
#define ACP10PAR_POS_LIMIT_SWITCH_PARID     945 /* (UINT) Digital inputs: Parameter ID for positive end switch */
#define ACP10PAR_NEG_LIMIT_SWITCH_PARID     946 /* (UINT) Digital inputs: Parameter ID for negative end switch */
#define ACP10PAR_MA1_SEND_DATA_OFFSET       947 /* (UINT) Network coupling: Send data master1: Bit offset within the data field of the frame */
#define ACP10PAR_MA4_CYCLIC_ERROR_STATUS    948 /* (USINT) Network coupling: Error status for cyclic position master4 */
#define ACP10PAR_MA5_CYCLIC_ERROR_STATUS    949 /* (USINT) Network coupling: Error status for cyclic position master5 */
#define ACP10PAR_KSCTRL_I                   950 /* (REAL) Induction stop: Short circuit current (synchronous motor) [A] */
#define ACP10PAR_ENCOD2_TRANS_RATIO         951 /* (REAL) Encoder2: Resolver transmission ratio */
#define ACP10PAR_ENCOD3_TRANS_RATIO         952 /* (REAL) Encoder3: Resolver transmission ratio */
#define ACP10PAR_ENCOD3_DIAG1               953 /* (REAL) Encoder3: Diagnosis 1 */
#define ACP10PAR_FWCTRL_ISD0                954 /* (REAL) CTRL Flux weakening: Demagnetizing current [A] */
#define ACP10PAR_UFCTRL_SLIP_COMP_K         957 /* (REAL) CTRL U/f: Slip compensation: Multiplication factor of compensated frequency */
#define ACP10PAR_FWCTRL_SPEED0              959 /* (REAL) CTRL Flux weakening: Start speed flux weakening [1/s] */
#define ACP10PAR_PIDENT_WIND_CROSS_SECT     974 /* (REAL) Parameter identification: Motor: Line cross section [mm²] */
#define ACP10PAR_PIDENT_MOTOR_TYPE          975 /* (UINT) Parameter identification: Motor: Type */
#define ACP10PAR_PIDENT_POLEPAIRS           976 /* (USINT) Parameter identification: Motor: Number of polepairs */
#define ACP10PAR_PIDENT_VOLTAGE_RATED       977 /* (REAL) Parameter identification: Motor: Rated voltage [V] */
#define ACP10PAR_PIDENT_VOLTAGE_CONST       978 /* (REAL) Parameter identification: Motor: Voltage constant [mVmin] */
#define ACP10PAR_PIDENT_SPEED_RATED         979 /* (REAL) Parameter identification: Motor: Rated speed [1/min] */
#define ACP10PAR_PIDENT_SPEED_MAX           980 /* (REAL) Parameter identification: Motor: Maximum speed [1/min] */
#define ACP10PAR_PIDENT_TORQ_STALL          981 /* (REAL) Parameter identification: Motor: Stall torque [Nm] */
#define ACP10PAR_PIDENT_TORQ_RATED          982 /* (REAL) Parameter identification: Motor: Rated torque [Nm] */
#define ACP10PAR_PIDENT_TORQ_MAX            983 /* (REAL) Parameter identification: Motor: Peak torque [Nm] */
#define ACP10PAR_PIDENT_TORQ_CONST          984 /* (REAL) Parameter identification: Motor: Torque constant [Nm/A] */
#define ACP10PAR_PIDENT_CURR_STALL          985 /* (REAL) Parameter identification: Motor: Stall current [A] */
#define ACP10PAR_PIDENT_CURR_RATED          986 /* (REAL) Parameter identification: Motor: Rated current [A] */
#define ACP10PAR_PIDENT_CURR_MAX            987 /* (REAL) Parameter identification: Motor: Peak current [A] */
#define ACP10PAR_PIDENT_MAGNETIZING_CURR    988 /* (REAL) Parameter identification: Motor: Magnetizing current [A] */
#define ACP10PAR_PIDENT_COS_PHI             989 /* (REAL) Parameter identification: Motor: Active power factor */
#define ACP10PAR_PIDENT_FREQ_RATED          990 /* (REAL) Parameter identification: Motor: Rated frequency [Hz] */
#define ACP10PAR_PIDENT_PHASE               991 /* (USINT) Parameter identification: Motor: Phase */
#define ACP10PAR_PIDENT_INVCL_A1            992 /* (REAL) Parameter identification: Inverter: Amplification factor */
#define ACP10PAR_PIDENT_INVCL_A2            993 /* (REAL) Parameter identification: Inverter: Exponent [1/A] */
#define ACP10PAR_PIDENT_MODE                995 /* (USINT) Parameter identification: Mode */
#define ACP10PAR_PIDENT_STATE               996 /* (USINT) Parameter identification: State */
#define ACP10PAR_CMD_PIDENT                 997 /* (UINT) Parameter identification: Command */
#define ACP10PAR_PIDENT_FIT                 998 /* (REAL) Parameter identification: Quality [%] */
#define ACP10PAR_ENCOD_POS_DATA             999 /* (DATA) Encoder: Position data block */
#define ACP10PAR_BRMOD_BSL                 1001 /* (BRMOD) System administration: Module: BsLoader */
#define ACP10PAR_BRMOD_NCSYS               1002 /* (BRMOD) System administration: Module: NC operating System */
#define ACP10PAR_PAR_REQU_DATA_OFFSET      1004 /* (UINT) System administration: Parameter Request: Bit offset within the data field of the frame */
#define ACP10PAR_PAR_RESP_DATA_OFFSET      1005 /* (UINT) System administration: Parameter Response: Bit offset within the data field of the frame */
#define ACP10PAR_CYC_TODRV_DATA_OFFSET     1006 /* (UINT) Cyclic communication: Data to drive: Bit offset within the data field of the frame */
#define ACP10PAR_CYC_FRDRV_DATA_OFFSET     1007 /* (UINT) Cyclic communication: Data from drive: Bit offset within the data field of the frame */
#define ACP10PAR_CYC_MON_DATA_OFFSET       1008 /* (UINT) Cyclic communication: Monitor data from drive: Bit offset within the data field of the frame */
#define ACP10PAR_CMD_MOVE_HALT_A2          1009 /* (REAL) Basis movements: Halt [Units/s²] */
#define ACP10PAR_BRMOD_VERSION             1010 /* (UINT) System administration: Module: Version */
#define ACP10PAR_BRMOD_DATE_TIME           1011 /* (T5) System administration: Module: Date and time */
#define ACP10PAR_BRMOD_RD_SECTION          1013 /* (DINT) System administration: Module: Section for read access */
#define ACP10PAR_EVMOVE_MODE               1015 /* (UINT) Basis movements: Event start: Mode */
#define ACP10PAR_EVMOVE_EV_PARID           1016 /* (UINT) Basis movements: Event start: Parameter ID for event */
#define ACP10PAR_EVMOVE_S_IN_PARID         1017 /* (UINT) Basis movements: event start: Parameter ID for target position */
#define ACP10PAR_EVMOVE_V_IN_PARID         1018 /* (UINT) Basis movements: event start: Parameter ID for target speed */
#define ACP10PAR_EVMOVE_WR_CMD             1019 /* (UINT) Basis movements: Event start: Command parameter ID */
#define ACP10PAR_EVMOVE_STATUS             1020 /* (USINT) Basis movements: Event start: Status */
#define ACP10PAR_EVMOVE_MODE_VAX1          1021 /* (UINT) VAX Basis movements: Event start: Mode */
#define ACP10PAR_EVMOVE_EV_PARID_VAX1      1022 /* (UINT) VAX Basis movements: Event start: Parameter ID for event */
#define ACP10PAR_EVMOVE_S_IN_PARID_VAX1    1023 /* (UINT) VAX Basis movements: Event start: Parameter ID for target position */
#define ACP10PAR_EVMOVE_V_IN_PARID_VAX1    1024 /* (UINT) VAX Basis movements: Event start: Parameter ID for target speed */
#define ACP10PAR_EVMOVE_WR_CMD_VAX1        1025 /* (UINT) VAX Basis movements: Event start: Command parameter ID */
#define ACP10PAR_EVMOVE_STATUS_VAX1        1026 /* (USINT) VAX Basis movements: Event start: Status */
#define ACP10PAR_CMD_MOVE_HALT_A2_VAX1     1027 /* (REAL) VAX Basis movements: Halt [Units/s²] */
#define ACP10PAR_CMD_V_SET_MOVE            1028 /* (NIL) Basis movements: Start movement with current speed */
#define ACP10PAR_CMD_V_SET_MOVE_VAX1       1029 /* (NIL) VAX Basis movements: Start movement with current speed */
#define ACP10PAR_ISQ_FILTER1_TYPE          1030 /* (UINT) CTRL Speed controller: Set current filter1 type */
#define ACP10PAR_ISQ_FILTER2_TYPE          1031 /* (UINT) CTRL Speed controller: Set current filter2 type */
#define ACP10PAR_ISQ_FILTER3_TYPE          1032 /* (UINT) CTRL Speed controller: Set current filter3 type */
#define ACP10PAR_ISQ_FILTER1_A0            1033 /* (REAL) CTRL Speed controller: Set current filter1 coefficient A0 */
#define ACP10PAR_ISQ_FILTER2_A0            1034 /* (REAL) CTRL Speed controller: Set current filter2 coefficient A0 */
#define ACP10PAR_ISQ_FILTER3_A0            1035 /* (REAL) CTRL Speed controller: Set current filter3 coefficient A0 */
#define ACP10PAR_ISQ_FILTER1_A1            1036 /* (REAL) CTRL Speed controller: Set current filter1 coefficient A1 */
#define ACP10PAR_ISQ_FILTER2_A1            1037 /* (REAL) CTRL Speed controller: Set current filter2 coefficient A1 */
#define ACP10PAR_ISQ_FILTER3_A1            1038 /* (REAL) CTRL Speed controller: Set current filter3 coefficient A1 */
#define ACP10PAR_ISQ_FILTER1_B0            1039 /* (REAL) CTRL Speed controller: Set current filter1 coefficient B0 */
#define ACP10PAR_ISQ_FILTER2_B0            1040 /* (REAL) CTRL Speed controller: Set current filter2 coefficient B0 */
#define ACP10PAR_ISQ_FILTER3_B0            1041 /* (REAL) CTRL Speed controller: Set current filter3 coefficient B0 */
#define ACP10PAR_ISQ_FILTER1_B1            1042 /* (REAL) CTRL Speed controller: Set current filter1 coefficient B1 */
#define ACP10PAR_ISQ_FILTER2_B1            1043 /* (REAL) CTRL Speed controller: Set current filter2 coefficient B1 */
#define ACP10PAR_ISQ_FILTER3_B1            1044 /* (REAL) CTRL Speed controller: Set current filter3 coefficient B1 */
#define ACP10PAR_ISQ_FILTER1_B2            1045 /* (REAL) CTRL Speed controller: Set current filter1 coefficient B2 */
#define ACP10PAR_ISQ_FILTER2_B2            1046 /* (REAL) CTRL Speed controller: Set current filter2 coefficient B2 */
#define ACP10PAR_ISQ_FILTER3_B2            1047 /* (REAL) CTRL Speed controller: Set current filter3 coefficient B2 */
#define ACP10PAR_ENCOD_TRANS_RATIO         1048 /* (REAL) Encoder1: Resolver transmission ratio */
#define ACP10PAR_SGEN_S_SET_FRAC           1049 /* (REAL) CTRL Position controller: Input set position fractional part [Units] */
#define ACP10PAR_CMD_SW_RESET              1050 /* (NIL) System administration: SW Reset */
#define ACP10PAR_CMD_BOOT_STATE            1051 /* (UINT) System administration: Change Boot State */
#define ACP10PAR_BOOT_STATE                1052 /* (UINT) System administration: Boot State */
#define ACP10PAR_CMD_BURN_SYSMOD           1053 /* (NIL) System administration: Module: Burn */
#define ACP10PAR_STAT_BURN_SYSMOD          1054 /* (USINT) System administration: Module: Burn status */
#define ACP10PAR_BSL_TEST_CMD              1055 /* (UINT) System administration: Test command */
#define ACP10PAR_BSL_TEST_STATUS           1056 /* (UINT) System administration: Test status */
#define ACP10PAR_BSL_TEST_PAR              1057 /* (UDINT) System administration: Test parameter */
#define ACP10PAR_ENCOD2_HOMING_OFFSET      1058 /* (DINT) Encoder2: Homing offset [Units] */
#define ACP10PAR_ENCOD3_HOMING_OFFSET      1059 /* (DINT) Encoder3: Homing offset [Units] */
#define ACP10PAR_RD_BLOCK_SEGM             1060 /* (BYTES6) Data block transfer: Read data block segment */
#define ACP10PAR_RD_BLOCK_LAST_SEGM        1061 /* (BYTES6) Data block transfer: Read last data block segment */
#define ACP10PAR_CMD_RD_BLOCK_ABORT        1062 /* (NIL) Data block transfer: Abort data block read access */
#define ACP10PAR_RD_BLOCK_OFFSET           1063 /* (UDINT) Data block transfer: Offset for data block read access */
#define ACP10PAR_RD_BLOCK_BYTES            1064 /* (UDINT) Data block transfer: Remaining bytes for data block read access */
#define ACP10PAR_CMD_MOVE_STOP_A2          1065 /* (REAL) Movement stop: Command stop movement [Units/s²] */
#define ACP10PAR_CMD_MOVE_STOP_A2_VAX1     1066 /* (REAL) VAX Movement stop: Command stop movement [Units/s²] */
#define ACP10PAR_AUT_SL_S                  1067 /* (DINT) Cam automat: Position of slave axis [Units] */
#define ACP10PAR_AUT_SL_S_VAX1             1068 /* (DINT) VAX Cam automat: Position of slave axis [Units] */
#define ACP10PAR_WR_BLOCK_SEGM             1070 /* (BYTES6) Data block transfer: Write data block segment */
#define ACP10PAR_WR_BLOCK_LAST_SEGM        1071 /* (BYTES6) Data block transfer: Write last data block segment */
#define ACP10PAR_CMD_WR_BLOCK_ABORT        1072 /* (NIL) Data block transfer: Abort data block write access */
#define ACP10PAR_ENCOD2_CMD_HOMING         1073 /* (HOMING_S, HOMING_MODE, HOMING_MODE_BITS) Encoder2: Command start homing procedure */
#define ACP10PAR_ENCOD3_CMD_HOMING         1074 /* (HOMING_S, HOMING_MODE, HOMING_MODE_BITS) Encoder3: Command start homing procedure */
#define ACP10PAR_AUT_MA_CAM_REL            1075 /* (REAL) Cam automat: Relative distance of master axis within cam [Units] */
#define ACP10PAR_AUT_MA_CAM_REL_VAX1       1076 /* (REAL) VAX Cam automat: Relative distance of master axis within cam [Units] */
#define ACP10PAR_AUT_MA_CAM_LEADIN         1077 /* (DINT) Cam automat: Relative entry distance of master axis within cam [Units] */
#define ACP10PAR_AUT_MA_CAM_LEADIN_VAX1    1078 /* (DINT) VAX Cam automat: Relative entry distance of master axis within cam [Units] */
#define ACP10PAR_AUT_MSG_MODE_BITS_VAX1    1079 /* (UDINT) VAX Cam automat: Control bits for message mode */
#define ACP10PAR_TRACE_DATA                1100 /* (DATA) Trace: Data */
#define ACP10PAR_TUNE_I_MAX_PERCENT        1101 /* (REAL) Autotuning: Maximum percentage for rated current [%] */
#define ACP10PAR_TUNE_V_MAX_PERCENT        1102 /* (REAL) Autotuning: Maximum percentage for speed limit value [%] */
#define ACP10PAR_TUNE_S_MAX                1103 /* (REAL) Autotuning: Maximum movement distance [Units] */
#define ACP10PAR_TUNE_DS_MAX               1104 /* (REAL) Autotuning: Maximum lag error [Units] */
#define ACP10PAR_TUNE_SIGNAL_PERIODS       1106 /* (UDINT) Autotuning: Number of excitation periods */
#define ACP10PAR_TUNE_DRIVE_INERTIA        1109 /* (REAL) Autotuning: Estimated drive inertia [kgm^2] */
#define ACP10PAR_TUNE_SIGNAL_ORDER         1110 /* (UDINT) Autotuning: Order of excitation signal */
#define ACP10PAR_TUNE_OPTION_BITS          1111 /* (UDINT) Autotuning: Option control bits */
#define ACP10PAR_TUNE_KV_PERCENT           1112 /* (REAL) Autotuning: Percentage for proportional amplification [%] */
#define ACP10PAR_TUNE_RESONANCE_FACTOR     1113 /* (REAL) Autotuning: Factor for detection of a resonance */
#define ACP10PAR_TUNE_INERTIA_F_LOWER      1114 /* (REAL) Autotuning: Lower frequency for estimation of drive inertia [Hz] */
#define ACP10PAR_TUNE_INERTIA_F_UPPER      1115 /* (REAL) Autotuning: Upper frequency for estimation of drive inertia [Hz] */
#define ACP10PAR_TUNE_DELAY_TIME           1116 /* (REAL) Autotuning: Delay time during transients [s] */
#define ACP10PAR_TUNE_KV_MAX               1119 /* (REAL) Autotuning: Maximum proportional amplification [As, 1/s] */
#define ACP10PAR_TUNE_A                    1120 /* (REAL) Autotuning: Acceleration [Units/s²] */
#define ACP10PAR_PIDENT_SIGNAL_F_START     1121 /* (REAL) Parameter identification: Start frequency of the excitation signal [Hz] */
#define ACP10PAR_PIDENT_SIGNAL_F_STOP      1122 /* (REAL) Parameter identification: Stop frequency of the excitation signal [Hz] */
#define ACP10PAR_PIDENT_SIGNAL_TIME        1123 /* (REAL) Parameter identification: Duration of the excitation signal [s] */
#define ACP10PAR_PIDENT_SIGNAL_TYPE        1124 /* (UINT) Parameter identification: Type of the excitation signal */
#define ACP10PAR_PIDENT_SUB_MODE           1125 /* (UDINT) Parameter identification: Sub-mode */
#define ACP10PAR_PIDENT_STATE_BITS         1126 /* (UDINT) Parameter identification: State bits */
#define ACP10PAR_ISQ_RIPPLE_DAT_A_POS      1127 /* (REAL) ISQ-Ripple compensation: Data: Amplitude for quadrant I [A] */
#define ACP10PAR_ISQ_RIPPLE_DAT_PHI_POS    1128 /* (REAL) ISQ-Ripple compensation: Data: Angle for quadrant I */
#define ACP10PAR_ISQ_RIPPLE_DAT_A_NEG      1129 /* (REAL) ISQ-Ripple compensation: Data: Amplitude for quadrant III [A] */
#define ACP10PAR_ISQ_RIPPLE_DAT_PHI_NEG    1130 /* (REAL) ISQ-Ripple compensation: Data: Angle for quadrant III */
#define ACP10PAR_ISQ_RIPPLE_REFSYSTEM      1131 /* (USINT) ISQ-Ripple compensation: Reference system */
#define ACP10PAR_ISQ_RIPPLE_DAT_B          1132 /* (REAL) ISQ-Ripple compensation: Data:  Parameter B */
#define ACP10PAR_ISQ_RIPPLE_POS_OFFSET     1134 /* (REAL) ISQ-Ripple compensation: Position offset [rad] */
#define ACP10PAR_ENCOD_MODE                1135 /* (UDINT) Encoder: Mode */
#define ACP10PAR_ENCOD2_MODE               1136 /* (UDINT) Encoder2: Mode */
#define ACP10PAR_ENCOD3_MODE               1137 /* (UDINT) Encoder3: Mode */
#define ACP10PAR_PIDENT_ITER_CNT           1138 /* (UDINT) Parameter identification: Iteration counter */
#define ACP10PAR_PMET_MODE                 1139 /* (USINT) PowerMeter: Mode */
#define ACP10PAR_PMET_TIME_IV              1140 /* (DINT) PowerMeter: Observation period [us] */
#define ACP10PAR_PMET_TRIG_PARID           1141 /* (UINT) PowerMeter: Trigger parameter-ID */
#define ACP10PAR_PMET_CYCLE_TIME           1142 /* (DINT) PowerMeter: Actual cycle time [us] */
#define ACP10PAR_PMET_CNT                  1143 /* (UINT) PowerMeter: Cycle counter */
#define ACP10PAR_PMET_P_MEAN               1144 /* (REAL) PowerMeter: Mean active power  [W] */
#define ACP10PAR_PMET_P_MIN                1145 /* (REAL) PowerMeter: Minimum active power [W] */
#define ACP10PAR_PMET_P_MAX                1146 /* (REAL) PowerMeter: Maximum active power  [W] */
#define ACP10PAR_PMET_Q_MEAN               1147 /* (REAL) PowerMeter: Mean reactive power [var] */
#define ACP10PAR_PMET_E_CONS               1148 /* (REAL) PowerMeter: Consumed energy [Ws] */
#define ACP10PAR_PMET_E_PROD               1149 /* (REAL) PowerMeter: Produced energy [Ws] */
#define ACP10PAR_AXLIM_DV_STOP             1150 /* (REAL) Limit values: Speed error for stop of a movement [1/s] */
#define ACP10PAR_MAINS_U1                  1151 /* (REAL) Power mains: Phase 1: Voltage [V] */
#define ACP10PAR_MAINS_U2                  1152 /* (REAL) Power mains: Phase 2: Voltage [V] */
#define ACP10PAR_MAINS_U3                  1153 /* (REAL) Power mains: Phase 3: Voltage [V] */
#define ACP10PAR_RECT_CURR                 1154 /* (REAL) Power stage: Rectifier: Current [A] */
#define ACP10PAR_UDC_CHOP_CURR             1155 /* (REAL) CTRL Chopper: Current [A] */
#define ACP10PAR_FCTRL_IM_REF_PARID        1156 /* (UINT) CTRL Flux: Parameter-ID Set magnetizing current */
#define ACP10PAR_TEMPSENS_RESISTANCE       1157 /* (REAL) Temperature sensor: Resistance [Ohm] */
#define ACP10PAR_TEMPSENS_PARID            1158 /* (UINT) Temperature sensor: Parameter-ID Resistance */
#define ACP10PAR_SCTRL_SPEED_ERROR         1159 /* (REAL) CTRL Speed controller: Speed error [1/s] */
#define ACP10PAR_POWER_STAGE_NO            1162 /* (USINT) Inverter: Number of power stages */
#define ACP10PAR_AXLIM_DV_STOP_MODE        1163 /* (UDINT) Limit values: Speed error monitoring: Mode */
#define ACP10PAR_PLIM_POWER_LIM            1165 /* (REAL) Power limiter: Limit value [W] */
#define ACP10PAR_ICTRL_AUTO_CONFIG         1166 /* (UINT) CTRL Current: Automatic configuration */
#define ACP10PAR_ENCOD_DIAG_ID             1167 /* (USINT) Encoder1: Diagnosis ID */
#define ACP10PAR_ENCOD_DIAG                1168 /* (USINT) Encoder1: Diagnosis */
#define ACP10PAR_POWERFAIL_DETECT_RATIO    1169 /* (REAL) CTRL DC bus: Minimum-to-nominal voltage ratio */
#define ACP10PAR_SLOT_NO                   1170 /* (USINT) Number of modul slots */
#define ACP10PAR_EPROM_ORDERTEXT           1171 /* (STR32) Order text */
#define ACP10PAR_TEMP_MOTOR_MODEL_LIM      1172 /* (REAL) Motor: Temperature model: Limit temperature [°C] */
#define ACP10PAR_ENCOD_COMP_MODE           1173 /* (UINT) Encoder1: Compensation: Mode */
#define ACP10PAR_ENCOD_DAT_IDX             1174 /* (DINT) Encoder1: Data: Index */
#define ACP10PAR_ENCOD_DAT_A0              1175 /* (REAL) Encoder1: Data: Parameter A0 */
#define ACP10PAR_ENCOD_DAT_A1              1176 /* (REAL) Encoder1: Data: Parameter A1 */
#define ACP10PAR_ENCOD_DAT_A2              1177 /* (REAL) Encoder1: Data: Parameter A2 */
#define ACP10PAR_T_STOP_EVENT_BIT          1179 /* (DINT) Movement stop: Minimum time for cyclic bit 'stop after drive event' [us] */
#define ACP10PAR_PCTRL_ENABLE_A2_POS       1180 /* (REAL) CTRL Position controller: Deceleration in positive direction at activating the enable input [Units/s²] */
#define ACP10PAR_PCTRL_ENABLE_A2_NEG       1181 /* (REAL) CTRL Position controller: Deceleration in negative direction at activating the enable input [Units/s²] */
#define ACP10PAR_HOMING_DS_STOP            1182 /* (REAL) Homing: Lag error for stop of a movement [Units] */
#define ACP10PAR_CYCLIC_DP_CYCLE_TIME      1183 /* (UDINT) Network coupling: Receive data point: Cycle time [us] */
#define ACP10PAR_HOMING_RESTORE_MODE       1184 /* (UINT) Homing: Mode for saving and restoring position data */
#define ACP10PAR_SGEN_PROF_S_SET           1186 /* (DINT) Basis movements: Profile generator set position [Units] */
#define ACP10PAR_SGEN_PROF_VTA_SET         1187 /* (REAL) Basis-Bewegungen: Profile generator change of set position per cycle */
#define ACP10PAR_HOMING_DS_BLOCK           1188 /* (REAL) Homing: Lag error for block detection [Units] */
#define ACP10PAR_HOMING_TORQUE_LIM         1189 /* (REAL) Homing: Torque limit [Nm] */
#define ACP10PAR_ENCOD_SSI_TRAIL_BITS      1190 /* (USINT) Encoder1: SSI Number of trailing bits */
#define ACP10PAR_ENCOD2_SSI_TRAIL_BITS     1191 /* (USINT) Encoder2: SSI Number of trailing bits */
#define ACP10PAR_ENCOD3_SSI_TRAIL_BITS     1192 /* (USINT) Encoder3: SSI Number of trailing bits */
#define ACP10PAR_QUICKSTOP_DECEL_RAMP      1193 /* (USINT) Digital inputs: Quickstop deceleration ramp */
#define ACP10PAR_NETWORK_SYS_TIME          1194 /* (UDINT) Drive synchronisation: Total time within the network cycle [us] */
#define ACP10PAR_PCTRL_MODE_BITS           1196 /* (UDINT) CTRL Position controller: Mode bits */
#define ACP10PAR_CROSSLINK_AXIS            1197 /* (UINT) Axis crosslink: Axis number */
#define ACP10PAR_CROSSLINK_PARID           1198 /* (UINT) Axis crosslink: Parameter ID */
#define ACP10PAR_STOP_T_JOLT               1199 /* (REAL) Movement stop: Jolt time [s] */
#define ACP10PAR_AUT_MA_S_START_IDX        1204 /* (USINT) Cam automat: Index for relative start position of the master axis within interval */
#define ACP10PAR_AUT_MA_S_START_IV         1205 /* (DINT) Cam automat: Relative start position of the master axis within interval [Units] */
#define ACP10PAR_AUT_MA_S_START_IDX_VAX1   1206 /* (USINT) VAX Cam automat: Index for relative start position of the master axis within interval */
#define ACP10PAR_AUT_MA_S_START_IV_VAX1    1207 /* (DINT) VAX Cam automat: Relative start position of the master axis within interval [Units] */
#define ACP10PAR_MOTOR_NUM_PHASES          1208 /* (USINT) Motor: Number of motor phases */
#define ACP10PAR_MOTOR_ENCOD_TEMP_LIM      1209 /* (UINT) Motor: Encoder: Limit temperature [°C] */
#define ACP10PAR_MOTOR_TEMPMODEL_REFSENS   1210 /* (UINT) Motor: Temperature model: Reference sensor: Parameter ID */
#define ACP10PAR_MOTOR_TEMPMODEL_RES1      1211 /* (REAL) Motor: Temperature model: Thermal resistance 1 [K/W] */
#define ACP10PAR_MOTOR_TEMPMODEL_CAP1      1212 /* (REAL) Motor: Temperature model: Thermal capacity 1 [Ws/K] */
#define ACP10PAR_MOTOR_TEMPMODEL_RES2      1213 /* (REAL) Motor: Temperature model: Thermal resistance 2 [K/W] */
#define ACP10PAR_MOTOR_TEMPMODEL_CAP2      1214 /* (REAL) Motor: Temperature model: Thermal capacity 2 [Ws/K] */
#define ACP10PAR_MOTOR_TEMPSENS_TYPE       1215 /* (UINT) Temperature sensor: Type */
#define ACP10PAR_MOTOR_TEMPSENS_LIM        1216 /* (UINT) Temperature sensor: Limit temperature [°C] */
#define ACP10PAR_ENCOD_POS_DATA_IDX        1219 /* (UINT) Encoder: Index of position data block */
#define ACP10PAR_UDC_OVMON_CTRL_OFF_LIM    1220 /* (REAL) CTRL DC bus: Overvoltage monitoring: Threshold for torque off [V] */
#define ACP10PAR_UDC_OVMON_STOP_LIM        1221 /* (REAL) CTRL DC bus: Overvoltage monitoring: Threshold for stop on [V] */
#define ACP10PAR_TEMP_POWERSTAGE           1222 /* (REAL) Inverter: Temperature model: Temperature [°C] */
#define ACP10PAR_MAINS_FREQ_TOL            1223 /* (REAL) Power mains: Frequency tolerance [%] */
#define ACP10PAR_MOTOR_VENDOR_ID           1224 /* (UINT) Motor: Vendor ID */
#define ACP10PAR_ENCOD_SSI_LINE_OFF        1225 /* (DINT) Encoder1: Serial position phase shift */
#define ACP10PAR_ENCOD2_SSI_LINE_OFF       1226 /* (DINT) Encoder2: Serial position phase shift */
#define ACP10PAR_ENCOD3_SSI_LINE_OFF       1227 /* (DINT) Encoder3: Serial position phase shift */
#define ACP10PAR_ENCOD_SSI_LINE_RES        1228 /* (DINT) Encoder1: Serial resolution per sinus period */
#define ACP10PAR_ENCOD_COMP_B0             1230 /* (REAL) Encoder1: Compensation: Parameter 1 */
#define ACP10PAR_ENCOD_COMP_B1             1231 /* (REAL) Encoder1: Compensation: Parameter 2 */
#define ACP10PAR_ENCOD_COMP_B2             1232 /* (REAL) Encoder1: Compensation: Parameter 3 */
#define ACP10PAR_ENCOD_COMP_B3             1233 /* (REAL) Encoder1: Compensation: Parameter 4 */
#define ACP10PAR_ENCOD_COMP_ID_CURR_MAX    1234 /* (REAL) Encoder1: Compensation: Maximal current for identification [A] */
#define ACP10PAR_MTPC_ISQ_REF              1235 /* (REAL) CTRL Current: MTPC control: Torque proportional set current [A] */
#define ACP10PAR_MTPC_ISD_REF              1236 /* (REAL) CTRL Current: MTPC control: Input direct component [A] */
#define ACP10PAR_CMD_SCTRL_RC              1237 /* (UINT) CTRL Speed controller: Repetitive Control: Command */
#define ACP10PAR_SCTRL_RC_T_PREDICT        1238 /* (REAL) CTRL Speed controller: Repetitive Control: Prediction time [s] */
#define ACP10PAR_SCTRL_RC_SPEED_MIN        1239 /* (REAL) CTRL Speed controller: Repetitive Control: Minimal speed [1/s] */
#define ACP10PAR_SCTRL_RC_FILT_CUTOFF      1240 /* (REAL) CTRL Speed controller: Repetitive Control: Cutoff frequency of filter [Hz] */
#define ACP10PAR_SCTRL_RC_FILT_ORDER       1241 /* (USINT) CTRL Speed controller: Repetitive Control: Order of filter */
#define ACP10PAR_SCTRL_RC_STATUS           1242 /* (USINT) CTRL Speed controller: Repetitive Control: State */
#define ACP10PAR_SCTRL_RC_FILT_TYPE        1243 /* (USINT) CTRL Speed controller: Repetitive Control: Type of filter */
#define ACP10PAR_SCTRL_RC_RES              1244 /* (UINT) CTRL Speed controller: Repetitive Control: Resolution */
#define ACP10PAR_SCTRL_RC_VALUE            1245 /* (REAL) CTRL Speed controller: Repetitive Control: Output value [A] */
#define ACP10PAR_SCTRL_RC_PAR0             1246 /* (UDINT) CTRL Speed: Repetitive Control: Parameter 1 */
#define ACP10PAR_SCTRL_RC_PAR1             1247 /* (UDINT) CTRL Speed: Repetitive Control: Parameter 2 */
#define ACP10PAR_SCTRL_RC_MODE             1248 /* (UDINT) CTRL Speed: Repetitive Control: Mode */
#define ACP10PAR_FFCTRL_FORCE              1249 /* (REAL) CTRL Feed forward: Set motor force [N] */
#define ACP10PAR_FWCTRL_ULIM_SCALE         1250 /* (REAL) CTRL Flux weakening: Voltage limit reserve */
#define ACP10PAR_MOTOR_BRAKE_TYPE          1260 /* (UINT) Motor holding brake: Type */
#define ACP10PAR_MOTOR_BRAKE_RESISTANCE    1261 /* (REAL) Motor holding brake: Resistance [Ohm] */
#define ACP10PAR_MOTOR_BRAKE_INDUCTANCE    1262 /* (REAL) Motor holding brake: Inductance [Henry] */
#define ACP10PAR_FFCTRL_MASS               1263 /* (REAL) CTRL Feed forward: Total mass [kg] */
#define ACP10PAR_FFCTRL_FORCE_LOAD         1264 /* (REAL) CTRL Feed forward: External load [N] */
#define ACP10PAR_BRAKE_TEST_DURATION       1266 /* (REAL) Motor holding brake test: Test duration [s] */
#define ACP10PAR_BRAKE_TEST_TORQUE_RATE    1269 /* (REAL) Motor holding brake test: Torque slew rate [Nm/s] */
#define ACP10PAR_TLIM_ISQ_POS              1270 /* (REAL) CTRL Torque limiter: Absolute value of positive current limit [A] */
#define ACP10PAR_TLIM_ISQ_NEG              1271 /* (REAL) CTRL Torque limiter: Absolute value of negative current limit [A] */
#define ACP10PAR_MOTOR_SALIENCY_RATIO      1277 /* (REAL) Motor: Magnetic saliency ratio */
#define ACP10PAR_UDC_OFFSET                1278 /* (REAL) CTRL DC bus: Voltage offset [V] */
#define ACP10PAR_VCTRL_I0_LIM              1279 /* (REAL) Inverter: Summation current: Limit [A] */
#define ACP10PAR_PIDENT_THERM_TRIP_TIME    1283 /* (REAL) Parameter identification: Tripping time at thermal overload  [s] */
#define ACP10PAR_VCTRL_RHO_ADD_PARID       1293 /* (UINT) CTRL Vector controller: Parameter ID of the additive commutation angle */
#define ACP10PAR_VCTRL_RHO_ADD             1294 /* (REAL) CTRL Vector controller: Additive commutation angle [rad] */
#define ACP10PAR_OBS_VOLT_US1              1295 /* (REAL) Voltage observer: Phase voltage U [V] */
#define ACP10PAR_OBS_VOLT_US2              1296 /* (REAL) Voltage observer: Phase voltage V [V] */
#define ACP10PAR_OBS_VOLT_US3              1297 /* (REAL) Voltage observer: Phase voltage W [V] */
#define ACP10PAR_OBS_VOLT_INVCL_A1         1298 /* (REAL) Voltage observer: Inverter adjustment amplification factor */
#define ACP10PAR_OBS_VOLT_INVCL_A2         1299 /* (REAL) Voltage observer: Inverter adjustment exponent [1/A] */
#define ACP10PAR_ENCOD_OUT_OFFSET          1300 /* (DINT) Encoder1: Emulation: Offset */
#define ACP10PAR_ENCOD2_OUT_OFFSET         1301 /* (DINT) Encoder2: Emulation: Offset */
#define ACP10PAR_ENCOD3_OUT_OFFSET         1302 /* (DINT) Encoder3: Emulation: Offset */
#define ACP10PAR_ENCOD_ADC1_OFFSET         1303 /* (DINT) Encoder: ADC1: Offset */
#define ACP10PAR_ENCOD_ADC2_OFFSET         1304 /* (DINT) Encoder: ADC2: Offset */
#define ACP10PAR_ENCOD_ADC1_GAIN           1305 /* (REAL) Encoder: ADC1: Gain */
#define ACP10PAR_PIDENT_S                  1306 /* (DINT) Parameter identification: Move distance [Units] */
#define ACP10PAR_ENCOD0_POS_RANGE_LW       1308 /* (UDINT) Virtual Encoder: Range of encoder position low word [Incr] */
#define ACP10PAR_ENCOD0_POS_RANGE_HW       1309 /* (UDINT) Virtual Encoder: Range of encoder position high word [Incr] */
#define ACP10PAR_ENCOD0_CMD_HOMING         1310 /* (HOMING_S, HOMING_MODE, HOMING_MODE_BITS) Virtual Encoder: Command start homing procedure */
#define ACP10PAR_ENCOD0_MAX_CYCLE_TIME     1311 /* (DINT) Virtual Encoder: Maximum cycle time */
#define ACP10PAR_ENCOD0_POS1_IN_PARID      1312 /* (UINT) Virtual Encoder: Parameter ID of input value position 1 */
#define ACP10PAR_ENCOD0_POS2_IN_PARID      1313 /* (UINT) Virtual Encoder: Parameter ID of input value position 1 */
#define ACP10PAR_ENCOD0_TIME_IN_PARID      1314 /* (UINT) Virtual Encoder: Parameter ID of input value time */
#define ACP10PAR_ENCOD0_S_FILTER_T10       1315 /* (REAL) Virtual Encoder: Time constant for actual position filter [s] */
#define ACP10PAR_ENCOD0_S_FILTER_TE        1316 /* (REAL) Virtual Encoder: Extrapolation time for actual position filter [s] */
#define ACP10PAR_ENCOD1_COMMUT_OFFSET      1317 /* (REAL) Encoder1: Commutation offset [rad] */
#define ACP10PAR_ELC_TRANSFER_PARID        1318 /* (UINT) Encoderless control: Parameter-ID Transition  */
#define ACP10PAR_ENCOD0_MODE               1320 /* (UDINT) Virtual Encoder: Mode */
#define ACP10PAR_ENCOD0_POS_ACT            1321 /* (DINT) Virtual Encoder: Actual position per revolution [Incr] */
#define ACP10PAR_ENCOD0_S_ACT              1322 /* (DINT) Virtual Encoder: Actual position [Units] */
#define ACP10PAR_SCALE_ENCOD0_UNITS        1323 /* (UDINT) Virtual Encoder: Encoder scaling: Units per SCALE_ENCOD0_REV encoder revolutions [Units] */
#define ACP10PAR_SCALE_ENCOD0_REV          1324 /* (UDINT) Virtual Encoder: Encoder scaling: encoder revolutions */
#define ACP10PAR_ENCOD0_COUNT_DIR          1325 /* (USINT) Virtual Encoder: Encoder scaling: Count direction */
#define ACP10PAR_STAT_ENC0_HOMING_OK       1326 /* (UDINT) Virtual Encoder: Status home position valid */
#define ACP10PAR_ENCOD0_IN_PARID           1327 /* (UINT) Virtual Encoder: Parameter ID of input value */
#define ACP10PAR_ENCOD0_STATUS_PARID       1328 /* (UINT) Virtual Encoder: Parameter ID of status */
#define ACP10PAR_ENCOD0_STATUS             1329 /* (UDINT) Virtual Encoder: Status */
#define ACP10PAR_SCALE_ENCOD0_INCR         1330 /* (UDINT) Virtual Encoder: Encoder scaling: increments per motor revolution */
#define ACP10PAR_ENCOD0_ELC_IN_FILTER      1332 /* (REAL) Virtual Encoder: Filter time constant for Pos2 in ELC mode [s] */
#define ACP10PAR_ELC_STALL_DETECT_TIME     1333 /* (REAL) Encoderless control: Stop monitoring: Triggering time [s] */
#define ACP10PAR_ELC_TRANSFER              1334 /* (REAL) Encoderless control: Transition  */
#define ACP10PAR_ELC_TRANSFER_TIME         1335 /* (REAL) Encoderless control: Transition time   [s] */
#define ACP10PAR_OBS_POS_PSI_REF           1336 /* (REAL) Position observer: Reference flux */
#define ACP10PAR_ELC_ISD_REF_PARID         1337 /* (UINT) Encoderless control: Parameter-ID Set current direct component */
#define ACP10PAR_ELC_ISD_REF               1338 /* (REAL) Encoderless control: Set current direct component [A] */
#define ACP10PAR_OBS_POS_PSI_ACT           1339 /* (REAL) Position observer: Actual flux */
#define ACP10PAR_FWCTRL_ULIM_OFFS          1340 /* (REAL) CTRL Flux weakening: Offset voltage limitation [V] */
#define ACP10PAR_PIDENT_SIGNAL_F_ACT       1342 /* (REAL) Parameter identification: Actual frequency of the excitation signal [Hz] */
#define ACP10PAR_PIDENT_TRACE_VAR1         1343 /* (REAL) Parameter identification: Trace variable 1 */
#define ACP10PAR_PIDENT_TRACE_VAR2         1344 /* (REAL) Parameter identification: Trace variable 2 */
#define ACP10PAR_OBS_POS1_MODE             1345 /* (UINT) Position observer 1: Mode */
#define ACP10PAR_OBS_POS2_MODE             1346 /* (UINT) Position observer 2: Mode */
#define ACP10PAR_OBS_POS1_RHO              1347 /* (REAL) Position observer 1: Estimated electrical flux angle [rad] */
#define ACP10PAR_OBS_POS2_RHO              1348 /* (REAL) Position observer 2: Estimated electrical flux angle [rad] */
#define ACP10PAR_OBS_POS1_PARA_A0          1351 /* (REAL) Position observer 1: Parameter A0 */
#define ACP10PAR_OBS_POS1_PARA_A1          1352 /* (REAL) Position observer 1: Parameter A1 */
#define ACP10PAR_OBS_POS1_PARA_A2          1353 /* (REAL) Position observer 1: Parameter A2 */
#define ACP10PAR_OBS_MODE_BITS             1354 /* (UDINT) Observer: Mode bits */
#define ACP10PAR_OBS_POS2_PARA_B0_PARID    1357 /* (UINT) Position observer 2: Parameter B0 Parameter-ID */
#define ACP10PAR_OBS_POS2_PARA_B1_PARID    1358 /* (UINT) Position observer 2: Parameter B1 Parameter-ID */
#define ACP10PAR_ENCOD2_DIAG_ID            1360 /* (USINT) Encoder2: Diagnosis ID */
#define ACP10PAR_ENCOD2_DIAG               1361 /* (USINT) Encoder2: Diagnosis */
#define ACP10PAR_ENCOD3_DIAG_ID            1362 /* (USINT) Encoder3: Diagnosis ID */
#define ACP10PAR_ENCOD3_DIAG               1363 /* (USINT) Encoder3: Diagnosis */
#define ACP10PAR_ENCOD2_CMD                1364 /* (UDINT) Encoder2: Encoder command */
#define ACP10PAR_ENCOD3_CMD                1365 /* (UDINT) Encoder3: Encoder command */
#define ACP10PAR_ENCOD2_TEMP               1366 /* (REAL) Encoder2: Temperature [°C] */
#define ACP10PAR_ENCOD3_TEMP               1367 /* (REAL) Encoder3: Temperature [°C] */
#define ACP10PAR_ENCOD2_ERR_CNT            1368 /* (UDINT) Encoder2: Error count */
#define ACP10PAR_ENCOD3_ERR_CNT            1369 /* (UDINT) Encoder3: Error count */
#define ACP10PAR_ENCOD_SSI_CONTENT_IDX     1370 /* (USINT) Encoder1: SSI content index */
#define ACP10PAR_ENCOD_SSI_CONTENT_TYPE    1371 /* (USINT) Encoder1: SSI content type */
#define ACP10PAR_ENCOD2_SSI_CONTENT_IDX    1372 /* (USINT) Encoder2: SSI content index */
#define ACP10PAR_ENCOD2_SSI_CONTENT_TYPE   1373 /* (USINT) Encoder2: SSI content type */
#define ACP10PAR_ENCOD3_SSI_CONTENT_IDX    1374 /* (USINT) Encoder3: SSI content index */
#define ACP10PAR_ENCOD3_SSI_CONTENT_TYPE   1375 /* (USINT) Encoder3: SSI content type */
#define ACP10PAR_ENCOD0_S_ACT_FILTER       1379 /* (DINT) Virtual Encoder: Filtered actual position [Units] */
#define ACP10PAR_PWM_CONFIG                1388 /* (UINT) PWM: Configuration */
#define ACP10PAR_UCTRL_T_RAMP              1389 /* (REAL) CTRL DC bus: Set value rise time [s] */
#define ACP10PAR_ENCOD_BAUDRATE            1390 /* (DINT) Encoder1: Baud rate [kBaud] */
#define ACP10PAR_ENCOD2_BAUDRATE           1391 /* (DINT) Encoder2: Baud rate [kBaud] */
#define ACP10PAR_ENCOD3_BAUDRATE           1392 /* (DINT) Encoder3: Baud rate [kBaud] */
#define ACP10PAR_FFCTRL_MODE               1393 /* (UINT) CTRL Feed forward: Mode */
#define ACP10PAR_ENCOD_REF_DCM_MODE        1400 /* (UINT) Encoder1: DCM Mode */
#define ACP10PAR_ENCOD_ABS_RES             1401 /* (DINT) Encoder1: Absolute resolution of an encoder revolution */
#define ACP10PAR_ENCOD2_ABS_RES            1402 /* (DINT) Encoder2: Absolute resolution of an encoder revolution */
#define ACP10PAR_ENCOD3_ABS_RES            1403 /* (DINT) Encoder3: Absolute resolution of an encoder revolution */
#define ACP10PAR_ENCOD_SINAMP_LIMIT_MAX    1404 /* (REAL) Encoder1: Signal amplitude upper limit [%] */
#define ACP10PAR_ENCOD_SINAMP_LIMIT_MIN    1405 /* (REAL) Encoder1: Signal amplitude lower limit [%] */
#define ACP10PAR_ENCOD2_SINAMP_LIMIT_MAX   1406 /* (REAL) Encoder2: Signal amplitude upper limit [%] */
#define ACP10PAR_ENCOD2_SINAMP_LIMIT_MIN   1407 /* (REAL) Encoder2: Signal amplitude lower limit [%] */
#define ACP10PAR_ENCOD3_SINAMP_LIMIT_MAX   1408 /* (REAL) Encoder3: Signal amplitude upper limit [%] */
#define ACP10PAR_ENCOD3_SINAMP_LIMIT_MIN   1409 /* (REAL) Encoder3: Signal amplitude lower limit [%] */
#define ACP10PAR_FFCTRL_KV_FORCE           1410 /* (REAL) CTRL Feed forward: Speed force factor [Ns/m] */
#define ACP10PAR_FFCTRL_FORCE_POS          1411 /* (REAL) CTRL Feed forward: Force in positive direction [N] */
#define ACP10PAR_FFCTRL_FORCE_NEG          1412 /* (REAL) CTRL Feed forward: Force in negative direction [N] */
#define ACP10PAR_ENCOD1_CMD_HOMING         1414 /* (HOMING_S, HOMING_MODE, HOMING_MODE_BITS) Encoder1: Command start homing procedure */
#define ACP10PAR_STAT_ENC1_HOMING_OK       1415 /* (UDINT) Encoder1: Status home position valid */
#define ACP10PAR_ENCOD1_HOMING_OFFSET      1416 /* (DINT) Encoder1: Homing offset [Units] */
#define ACP10PAR_TARGET_S_ABS              1417 /* (DINT) Basis movements: Absolute target position [Units] */
#define ACP10PAR_TARGET_S_ABS_VAX1         1418 /* (DINT) VAX Basis movements: Absolute target position [Units] */
#define ACP10PAR_CROSSLINK_ENC1_S_ACT      1419 /* (UINT) Axis crosslink: Encoder1: Actual position */
#define ACP10PAR_ACOPOS_IDENT_DATA         1438 /* (DATA) System administration: ACOPOS identification data */
#define ACP10PAR_OPTIONAL_CTRL_CMD         1440 /* (UDINT) Optional IO: Control command */
#define ACP10PAR_OPTIONAL_IN1              1441 /* (DINT) Optional IO: Input1 */
#define ACP10PAR_OPTIONAL_IN2              1442 /* (DINT) Optional IO: Input2 */
#define ACP10PAR_OPTIONAL_IN3              1443 /* (DINT) Optional IO: Input3 */
#define ACP10PAR_OPTIONAL_IN4              1444 /* (DINT) Optional IO: Input4 */
#define ACP10PAR_OPTIONAL_IN5              1445 /* (DINT) Optional IO: Input5 */
#define ACP10PAR_OPTIONAL_IN6              1446 /* (DINT) Optional IO: Input6 */
#define ACP10PAR_OPTIONAL_IN7              1447 /* (DINT) Optional IO: Input7 */
#define ACP10PAR_OPTIONAL_IN8              1448 /* (DINT) Optional IO: Input8 */
#define ACP10PAR_OPTIONAL_IN9              1449 /* (DINT) Optional IO: Input9 */
#define ACP10PAR_OPTIONAL_IN10             1450 /* (DINT) Optional IO: Input10 */
#define ACP10PAR_OPTIONAL_OUT1             1451 /* (DINT) Optional IO: Output1 */
#define ACP10PAR_OPTIONAL_OUT2             1452 /* (DINT) Optional IO: Output2 */
#define ACP10PAR_OPTIONAL_OUT3             1453 /* (DINT) Optional IO: Output3 */
#define ACP10PAR_OPTIONAL_OUT4             1454 /* (DINT) Optional IO: Output4 */
#define ACP10PAR_OPTIONAL_OUT5             1455 /* (DINT) Optional IO: Output5 */
#define ACP10PAR_OPTIONAL_OUT6             1456 /* (DINT) Optional IO: Output6 */
#define ACP10PAR_OPTIONAL_OUT7             1457 /* (DINT) Optional IO: Output7 */
#define ACP10PAR_OPTIONAL_OUT8             1458 /* (DINT) Optional IO: Output8 */
#define ACP10PAR_OPTIONAL_OUT9             1459 /* (DINT) Optional IO: Output9 */
#define ACP10PAR_OPTIONAL_OUT10            1460 /* (DINT) Optional IO: Output10 */
#define ACP10PAR_OPTIONAL_OUT1_PARID       1461 /* (DINT) Optional IO: Parameter ID output1 */
#define ACP10PAR_OPTIONAL_OUT2_PARID       1462 /* (DINT) Optional IO: Parameter ID output2 */
#define ACP10PAR_OPTIONAL_OUT3_PARID       1463 /* (DINT) Optional IO: Parameter ID output3 */
#define ACP10PAR_OPTIONAL_OUT4_PARID       1464 /* (DINT) Optional IO: Parameter ID output4 */
#define ACP10PAR_OPTIONAL_OUT5_PARID       1465 /* (DINT) Optional IO: Parameter ID output5 */
#define ACP10PAR_OPTIONAL_OUT6_PARID       1466 /* (DINT) Optional IO: Parameter ID output6 */
#define ACP10PAR_OPTIONAL_OUT7_PARID       1467 /* (DINT) Optional IO: Parameter ID output7 */
#define ACP10PAR_OPTIONAL_OUT8_PARID       1468 /* (DINT) Optional IO: Parameter ID output8 */
#define ACP10PAR_OPTIONAL_OUT9_PARID       1469 /* (DINT) Optional IO: Parameter ID output9 */
#define ACP10PAR_OPTIONAL_OUT10_PARID      1470 /* (DINT) Optional IO: Parameter ID output10 */
#define ACP10PAR_TLIM_MODE                 1480 /* (UINT) CTRL Torque limiter: Mode */
#define ACP10PAR_TLIM_STAT                 1481 /* (UINT) CTRL Torque limiter: Status */
#define ACP10PAR_TLIM_ISQ_REF              1482 /* (REAL) CTRL Torque limiter: Output current [A] */
#define ACP10PAR_TLIM_ISQ_ADD_PARID        1483 /* (UINT) CTRL Torque limiter: Parameter ID additiv output current */
#define ACP10PAR_LIM_T1_POS_PARID          1484 /* (UINT) CTRL Torque limiter: Parameter ID LIM_T1_POS */
#define ACP10PAR_LIM_T1_NEG_PARID          1485 /* (UINT) CTRL Torque limiter: Parameter ID LIM_T1_NEG */
#define ACP10PAR_LIM_T2_POS_PARID          1486 /* (UINT) CTRL Torque limiter: Parameter ID LIM_T2_POS */
#define ACP10PAR_LIM_T2_NEG_PARID          1487 /* (UINT) CTRL Torque limiter: Parameter ID LIM_T2_NEG */
#define ACP10PAR_MOTOR_TEMPMODEL_LOSS1     1489 /* (REAL) Motor: Speed-dependent power loss: Linear coefficient [Ws] */
#define ACP10PAR_MOTOR_TEMPMODEL_LOSS2     1490 /* (REAL) Motor: Speed-dependent power loss: Quadratic coefficient [Ws²] */
#define ACP10PAR_UDC_PRECHARGE_THRESHOLD   1491 /* (REAL) CTRL DC bus: Pre-charge: Enable voltage [V] */
#define ACP10PAR_SIM_INERTIA2              1492 /* (REAL) Simulation mode: Mass moment of inertia2 [kgm²] */
#define ACP10PAR_SIM_STATIC_FRICTION2      1493 /* (REAL) Simulation mode: Static friction2 [Nm] */
#define ACP10PAR_SIM_VISCOUS_FRICTION2     1494 /* (REAL) Simulation mode: Viscous friction2 [Nms] */
#define ACP10PAR_SIM_STIFFNESS             1495 /* (REAL) Simulation mode: Stiffness of coupling [Nm/rad] */
#define ACP10PAR_SIM_DAMPING               1496 /* (REAL) Simulation mode: Damping of coupling [Nms/rad] */
#define ACP10PAR_SIM_TORSION               1497 /* (REAL) Simulation mode: Torsion of coupling [Units] */
#define ACP10PAR_SIM_SPEED2                1498 /* (REAL) Simulation mode: Speed of mass 2 [1/s] */
#define ACP10PAR_CMD_ERROR                 1501 /* (UINT) Messages: Command execute error reaction  */
#define ACP10PAR_CMD_ERROR_VAX1            1502 /* (UINT) VAX Messages: Command execute error reaction  */
#define ACP10PAR_MOTOR_TEMPMODEL_MODE      1503 /* (UINT) Motor: Temperature model: Mode */
#define ACP10PAR_MOTOR_BRAKE_VOLT_REL      1504 /* (REAL) Motor holding brake: Release voltage [V] */
#define ACP10PAR_MOTOR_BRAKE_VOLT_HOLD     1505 /* (REAL) Motor holding brake: Hold voltage [V] */
#define ACP10PAR_MOTOR_BRAKE_VOLT_MAX      1506 /* (REAL) Motor holding brake: Overvoltage limit [V] */
#define ACP10PAR_TRIGGER1_PARID            1507 /* (UINT) Digital inputs: Parameter ID for trigger1 */
#define ACP10PAR_TRIGGER2_PARID            1508 /* (UINT) Digital inputs: Parameter ID for trigger2 */
#define ACP10PAR_CROSSLINK_ENC2_S_ACT      1509 /* (UINT) Axis crosslink: Encoder2: Actual position */
#define ACP10PAR_PBC_MODE                  1510 /* (UINT) Pitch error-backlash compensation: Mode */
#define ACP10PAR_PBC_TC                    1511 /* (REAL) Pitch error-backlash compensation: Compensation time [s] */
#define ACP10PAR_PBC_INERTIA1              1512 /* (REAL) Pitch error-backlash compensation: Inertia in backlash [kgm²] */
#define ACP10PAR_PBC_NOISELIMIT            1513 /* (REAL) Pitch error-backlash compensation: Noise limit [%] */
#define ACP10PAR_PBC_APOS_PARID            1514 /* (UINT) Pitch error-backlash compensation: Parameter ID for positive arrester */
#define ACP10PAR_PBC_ANEG_PARID            1515 /* (UINT) Pitch error-backlash compensation: Parameter ID for negative arrester */
#define ACP10PAR_PBC_S_COMP                1516 /* (DINT) Pitch error-backlash compensation: Load position [Units] */
#define ACP10PAR_PBC_SPEEDREF              1517 /* (REAL) Pitch error-backlash compensation: Compensation output [1/s] */
#define ACP10PAR_UCTRL_ENABLE_THR_LO       1518 /* (REAL) CTRL DC bus: Controller: Lower enable threshold */
#define ACP10PAR_UCTRL_ENABLE_THR_UP       1519 /* (REAL) CTRL DC bus: Controller: Upper enable threshold */
#define ACP10PAR_ENCOD_MAX_SYNC_SPEED      1521 /* (REAL) Encoder1: Maximum speed vor serial position [1/s] */
#define ACP10PAR_ENCOD2_DIAG2              1528 /* (REAL) Encoder2: Diagnosis 2 */
#define ACP10PAR_ENCOD2_DIAG3              1529 /* (REAL) Encoder2: Diagnosis 3 */
#define ACP10PAR_ENCOD3_DIAG2              1530 /* (REAL) Encoder3: Diagnosis 2 */
#define ACP10PAR_ENCOD3_DIAG3              1531 /* (REAL) Encoder3: Diagnosis 3 */
#define ACP10PAR_ENCOD2_MAX_SYNC_SPEED     1532 /* (REAL) Encoder2: Maximum speed vor serial position [1/s] */
#define ACP10PAR_ENCOD3_MAX_SYNC_SPEED     1533 /* (REAL) Encoder3: Maximum speed vor serial position [1/s] */
#define ACP10PAR_TEMP_MODUL5               1538 /* (REAL) Power stage: Temperature sensor 5: Temperature [°C] */
#define ACP10PAR_RECT_TEMP                 1539 /* (REAL) Power stage: Rectifier: Temperature [°C] */
#define ACP10PAR_DCREL_TEMP                1540 /* (REAL) DC bus: Relay: Temperature [°C] */
#define ACP10PAR_PBC_MAX_RATE              1541 /* (REAL) Pitch error-backlash compensation: Maximal speed of flange change [Units/s] */
#define ACP10PAR_PBC_STATUS                1542 /* (UINT) Pitch error-backlash compensation: Status */
#define ACP10PAR_DCCON_TEMP                1543 /* (REAL) DC bus: DC connector: Temperature [°C] */
#define ACP10PAR_DCCAP_TEMP                1544 /* (REAL) DC bus: Capacitor: Temperature [°C] */
#define ACP10PAR_INVR_TPOW_CONT_LOAD       1545 /* (REAL) Inverter: Continuous total power: Load [%] */
#define ACP10PAR_INVR_TPOW_PEAK_LOAD       1546 /* (REAL) Inverter: Peak total power: Load [%] */
#define ACP10PAR_MOTOR_HWINFO_DATA         1547 /* (DATA) Motor: Data for hardware information */
#define ACP10PAR_BASIS_TRG_STOP_S_DIFF     1549 /* (DINT) Basis movements: Target position difference for mode 'stop after trigger' [Units] */
#define ACP10PAR_ENCOD_SUPPLY_VOLTAGE      1556 /* (REAL) Encoder1: Output voltage of the sensor supply [V] */
#define ACP10PAR_UCTRL_CMD                 1557 /* (UINT) CTRL DC bus: Controller: Command */
#define ACP10PAR_INVR_TPOW                 1558 /* (REAL) Inverter: Total power [W] */
#define ACP10PAR_INVR_TPOW_CONT_LIM        1559 /* (REAL) Inverter: Continuous total power: Limit power [W] */
#define ACP10PAR_INVR_TPOW_PEAK_LIM        1560 /* (REAL) Inverter: Peak total power: Limit power [W] */
#define ACP10PAR_DCCAP_CURR_LOW_FREQ       1561 /* (REAL) DC bus: Capacitor: Low frequent Current [A] */
#define ACP10PAR_DCCAP_CURR_PWM_FREQ       1562 /* (REAL) DC bus: Capacitor: Pulse frequent Current [A] */
#define ACP10PAR_DCCON_CURR                1563 /* (REAL) DC bus: DC connector: Current [A] */
#define ACP10PAR_RECT_TEMP_LIM             1564 /* (REAL) Power stage: Rectifier: Limit temperature [°C] */
#define ACP10PAR_DCREL_TEMP_LIM            1565 /* (REAL) DC bus: Relay: Limit temperature [°C] */
#define ACP10PAR_DCCON_TEMP_LIM            1566 /* (REAL) DC bus: DC connector: Limit temperature [°C] */
#define ACP10PAR_DCCAP_TEMP_LIM            1567 /* (REAL) DC bus: Capacitor: Limit temperature [°C] */
#define ACP10PAR_ICTRL_US_FILTER_TYPE      1568 /* (UDINT) CTRL Current: Set voltage filter type */
#define ACP10PAR_ICTRL_US_FILTER1_A0       1569 /* (REAL) CTRL Current: Set voltage filter coefficient A0 */
#define ACP10PAR_ICTRL_US_FILTER1_A1       1570 /* (REAL) CTRL Current: Set voltage filter coefficient A1 */
#define ACP10PAR_ENCOD_LINES_PER_REVO      1571 /* (UDINT) Encoder1: Encoder scaling: Lines/signal periods per encoder revolution */
#define ACP10PAR_ENCOD2_LINES_PER_REVO     1572 /* (UDINT) Encoder2: Encoder scaling: Lines/signal periods per encoder revolution */
#define ACP10PAR_ENCOD3_LINES_PER_REVO     1573 /* (UDINT) Encoder3: Encoder scaling: Lines/signal periods per encoder revolution */
#define ACP10PAR_ADDRESS_MAPPER_CONFIG     1574 /* (UDINT) Address mapper: Configuration for address assignment */
#define ACP10PAR_ADDRESS_MAPPER_INDEX      1575 /* (UDINT) Address mapper: Index of address */
#define ACP10PAR_ENCOD2_SUPPLY_VOLTAGE     1576 /* (REAL) Encoder2: Output voltage of the encoder supply [V] */
#define ACP10PAR_ENCOD2_LINE_RESISTANCE    1584 /* (REAL) Encoder2: Line resistance of the encoder supply [Ohm] */
#define ACP10PAR_FBCTRL_SPEED_KV           1585 /* (REAL) CTRL Model based: Proportional amplification for speed [As] */
#define ACP10PAR_UFCTRL_TLIM_TN            1586 /* (REAL) CTRL U/f: Torque limiter: Integral action time [s] */
#define ACP10PAR_ENCOD_DPOS_ACT            1593 /* (DINT) Encoder1: Position difference per sample [Incr] */
#define ACP10PAR_ENCOD2_DPOS_ACT           1594 /* (DINT) Encoder2: Position difference per sample [Incr] */
#define ACP10PAR_FFCTRL_FRICTION_C0        1595 /* (REAL) CTRL Feed forward: Friction model: Coefficient C0 */
#define ACP10PAR_FFCTRL_FRICTION_C1        1596 /* (REAL) CTRL Feed forward: Friction model: Coefficient C1 */
#define ACP10PAR_FFCTRL_FRICTION_C2        1597 /* (REAL) CTRL Feed forward: Friction model: Coefficient C2 */
#define ACP10PAR_STAT_ONBOARD_TRIGGER1     1598 /* (UDINT) Digital inputs: Status onboard trigger1 */
#define ACP10PAR_STAT_ONBOARD_TRIGGER2     1599 /* (UDINT) Digital inputs: Status onboard trigger2 */
#define ACP10PAR_MODEL_INERTIA1            1600 /* (REAL) CTRL Model based: Mass moment of inertia1 [kgm^2] */
#define ACP10PAR_MODEL_INERTIA2            1601 /* (REAL) CTRL Model based: Mass moment of inertia2 [kgm^2] */
#define ACP10PAR_MODEL_STIFFNESS           1602 /* (REAL) CTRL Model based: Stiffness of coupling [Nm/rad] */
#define ACP10PAR_MODEL_DAMPING             1603 /* (REAL) CTRL Model based: Damping of coupling [Nms/rad] */
#define ACP10PAR_FAN_CTRL_MODE             1617 /* (USINT) Fan control: Mode */
#define ACP10PAR_QUICKSTOP_T_JOLT          1618 /* (REAL) Digital inputs: Jolt time for quickstop deceleration ramp [s] */
#define ACP10PAR_SIM_GEAR_IN_REV           1619 /* (UDINT) Simulation mode: Gearbox input revolutions */
#define ACP10PAR_SIM_GEAR_OUT_REV          1620 /* (UDINT) Simulation mode: Gearbox output revolutions */
#define ACP10PAR_SIM_GEAR_DIR              1621 /* (USINT) Simulation mode: Gearbox direction */
#define ACP10PAR_SIM_LOADENC_S_ACT_PARID   1622 /* (UINT) Simulation mode: Parameter ID for the encoder of load position */
#define ACP10PAR_CHP_CMD                   1623 /* (UINT) CTRL Chopper: Command */
#define ACP10PAR_CHP_MODE                  1624 /* (UINT) CTRL Chopper: Mode */
#define ACP10PAR_MODEL_VISCOUS_FRICTION1   1626 /* (REAL) CTRL Model based: Viscous friction1 [Nms] */
#define ACP10PAR_MODEL_VISCOUS_FRICTION2   1627 /* (REAL) CTRL Model based: Viscous friction2 [Nms] */
#define ACP10PAR_FBCTRL_SPEED_MIX_RATIO    1628 /* (REAL) CTRL Model based: Mixing ratio for speed */
#define ACP10PAR_FBCTRL_MODE               1630 /* (UINT) CTRL Model based: Feedback mode */
#define ACP10PAR_ENCOD2_OUTPUT_STAGE       1635 /* (USINT) Encoder2: Output stage */
#define ACP10PAR_ENCOD2_OUTPUT_FREQUENCY   1636 /* (UDINT) Encoder2: Maximal expected output frequency [Hz] */
#define ACP10PAR_TCTRANS_MODE              1637 /* (UINT) Torque Current Transformation: Mode */
#define ACP10PAR_MOTOR_UDC_MAX             1641 /* (REAL) Motor: Maximum permissible DC bus voltage [V] */
#define ACP10PAR_ENCOD2_COMP_MODE          1645 /* (UINT) Encoder2: Compensation: Mode */
#define ACP10PAR_ENCOD2_DAT_IDX            1646 /* (DINT) Encoder2: Data: Index */
#define ACP10PAR_ENCOD2_DAT_A0             1647 /* (REAL) Encoder2: Data: Parameter A0 */
#define ACP10PAR_ENCOD2_DAT_A1             1648 /* (REAL) Encoder2: Data: Parameter A1 */
#define ACP10PAR_ENCOD2_DAT_A2             1649 /* (REAL) Encoder2: Data: Parameter A2 */
#define ACP10PAR_ENCOD2_ADC1_OFFSET        1650 /* (DINT) Encoder2: ADC1: Offset */
#define ACP10PAR_ENCOD2_ADC2_OFFSET        1651 /* (DINT) Encoder2: ADC2: Offset */
#define ACP10PAR_ENCOD2_ADC1_GAIN          1652 /* (REAL) Encoder2: ADC1: Gain */
#define ACP10PAR_MOTOR_TEMPMODEL_RES3      1653 /* (REAL) Motor: Temperature model: Thermal resistance 3 [K/W] */
#define ACP10PAR_MOTOR_TEMPMODEL_LOSS1_W   1654 /* (REAL) Motor: Winding: Speed-dependent power loss: Linear coefficient [Ws] */
#define ACP10PAR_MOTOR_TEMPMODEL_LOSS2_W   1655 /* (REAL) Motor: Winding: Speed-dependent power loss: Quadratic coefficient [Ws²] */
#define ACP10PAR_PCTRL_CYC_SET_INDEX       1661 /* (UINT) CTRL Position controller: Index of parameter ID for cyclic set position */
#define ACP10PAR_ENCOD_ERROR_TIMEOUT       1662 /* (REAL) Encoder1: Timeout for position estimation [s] */
#define ACP10PAR_ENCOD2_ERROR_TIMEOUT      1663 /* (REAL) Encoder2: Timeout for position estimation [s] */
#define ACP10PAR_LOGIC_MODE                3072 /* (UINT) FB LOGIC: Mode */
#define ACP10PAR_LOGIC_IN1_PARID           3080 /* (UINT) FB LOGIC: Parameter ID of input1 */
#define ACP10PAR_LOGIC_IN2_PARID           3088 /* (UINT) FB LOGIC: Parameter ID of input2 */
#define ACP10PAR_LOGIC_VALUE               3096 /* (USINT) FB LOGIC: Result value */
#define ACP10PAR_LOGIC_IN3_PARID           3104 /* (UINT) FB LOGIC: Parameter ID of input3 */
#define ACP10PAR_LOGIC_IN4_PARID           3112 /* (UINT) FB LOGIC: Parameter ID of input4 */
#define ACP10PAR_ARITH_MODE                3584 /* (UINT) FB ARITH: Mode */
#define ACP10PAR_ARITH_IN1_PARID           3592 /* (UINT) FB ARITH: Parameter ID of input1 */
#define ACP10PAR_ARITH_IN2_PARID           3600 /* (UINT) FB ARITH: Parameter ID of input2 */
#define ACP10PAR_ARITH_VALUE_I4            3608 /* (DINT) FB ARITH: Result value I4 */
#define ACP10PAR_ARITH_VALUE_FRAC          3616 /* (REAL) FB ARITH: Result value I4 fractional part */
#define ACP10PAR_ARITH_VALUE_R4            3624 /* (REAL) FB ARITH: Result value R4 */
#define ACP10PAR_ARITH_K1                  3632 /* (REAL) FB ARITH: Multiplication factor1 */
#define ACP10PAR_ARITH_K2                  3640 /* (REAL) FB ARITH: Multiplication factor2 */
#define ACP10PAR_VAR_I4_0                  4096 /* (DINT) FB VAR: Variable0 I4 */
#define ACP10PAR_VAR_I4_1                  4104 /* (DINT) FB VAR: Variable1 I4 */
#define ACP10PAR_VAR_I4_2                  4112 /* (DINT) FB VAR: Variable2 I4 */
#define ACP10PAR_VAR_I4_3                  4120 /* (DINT) FB VAR: Variable3 I4 */
#define ACP10PAR_VAR_R4_0                  4128 /* (REAL) FB VAR: Variable0 R4 */
#define ACP10PAR_VAR_R4_1                  4136 /* (REAL) FB VAR: Variable1 R4 */
#define ACP10PAR_VAR_R4_2                  4144 /* (REAL) FB VAR: Variable2 R4 */
#define ACP10PAR_VAR_R4_3                  4152 /* (REAL) FB VAR: Variable3 R4 */
#define ACP10PAR_VAR_I2_0                  4160 /* (INT) FB VAR: Variable0 I2 */
#define ACP10PAR_VAR_I2_1                  4168 /* (INT) FB VAR: Variable1 I2 */
#define ACP10PAR_VAR_I2_2                  4176 /* (INT) FB VAR: Variable2 I2 */
#define ACP10PAR_VAR_I2_3                  4184 /* (INT) FB VAR: Variable3 I2 */
#define ACP10PAR_VAR_UI1_0                 4192 /* (USINT) FB VAR: Variable0 UI1 */
#define ACP10PAR_VAR_UI1_1                 4200 /* (USINT) FB VAR: Variable1 UI1 */
#define ACP10PAR_VAR_UI1_2                 4208 /* (USINT) FB VAR: Variable2 UI1 */
#define ACP10PAR_VAR_UI1_3                 4216 /* (USINT) FB VAR: Variable3 UI1 */
#define ACP10PAR_EVWR_EVENT_PARID          4608 /* (UINT) FB EVWR: Parameter ID of event input */
#define ACP10PAR_EVWR_IN_PARID             4616 /* (UINT) FB EVWR: Parameter ID of input */
#define ACP10PAR_EVWR_EVENT_LEVEL          4624 /* (DINT) FB EVWR: Event level */
#define ACP10PAR_EVWR_WR_PARID             4632 /* (UINT) FB EVWR: Parameter ID of output value */
#define ACP10PAR_EVWR_MODE                 4640 /* (UINT) FB EVWR: Mode */
#define ACP10PAR_MPGEN_MODE                5120 /* (UINT) FB MPGEN: Mode */
#define ACP10PAR_MPGEN_SET_VALUE           5128 /* (DINT) FB MPGEN: Target position [Units] */
#define ACP10PAR_MPGEN_VALUE_I4            5136 /* (DINT) FB MPGEN: Output value I4 [Units] */
#define ACP10PAR_MPGEN_VALUE_FRAC          5144 /* (REAL) FB MPGEN: Output value I4 fractional part */
#define ACP10PAR_MPGEN_VALUE_R4            5152 /* (REAL) FB MPGEN: Output value R4 */
#define ACP10PAR_MPGEN_STATUS              5160 /* (USINT) FB MPGEN: Status */
#define ACP10PAR_MPGEN_MA_PARID            5168 /* (UINT) FB MPGEN: Parameter ID of master position */
#define ACP10PAR_MPGEN_MA_V_MAX            5176 /* (REAL) FB MPGEN: Maximum master speed [Units/s] */
#define ACP10PAR_MPGEN_V_MAX               5184 /* (REAL) FB MPGEN: Maximum speed [Units/s] */
#define ACP10PAR_MPGEN_A_MAX               5192 /* (REAL) FB MPGEN: Maximum acceleration [Units/s²] */
#define ACP10PAR_MPGEN_MA_S_COMP           5200 /* (DINT) FB MPGEN: Master compensation distance [Units] */
#define ACP10PAR_MPGEN_SET_VALUE_PARID     5208 /* (UINT) FB MPGEN: Parameter ID of target position */
#define ACP10PAR_MPGEN_V_SET_VALUE         5216 /* (REAL) FB MPGEN: Target speed [Units/s] */
#define ACP10PAR_MPGEN_V_SET_VALUE_PARID   5224 /* (UINT) FB MPGEN: Parameter ID of target speed */
#define ACP10PAR_MPGEN_ERROR_COUNT         5232 /* (USINT) FB MPGEN: Error counter */
#define ACP10PAR_MPGEN_MA_S_START          5240 /* (DINT) FB MPGEN: Master start position [Units] */
#define ACP10PAR_MPGEN_MA_S_IV             5248 /* (DINT) FB MPGEN: Master interval [Units] */
#define ACP10PAR_MPGEN_MA_S1               5256 /* (REAL) FB MPGEN: Master start position within interval [Units] */
#define ACP10PAR_MPGEN_MA_S2               5264 /* (REAL) FB MPGEN: Master end position within interval [Units] */
#define ACP10PAR_DIO_IN                    5632 /* (UINT) FB DIO: input values */
#define ACP10PAR_DIO_OUT                   5640 /* (UINT) FB DIO: output values */
#define ACP10PAR_DIO_IN1                   5648 /* (USINT) FB DIO: input value 1 */
#define ACP10PAR_DIO_IN2                   5656 /* (USINT) FB DIO: input value 2 */
#define ACP10PAR_DIO_IN3                   5664 /* (USINT) FB DIO: input value 3 */
#define ACP10PAR_DIO_IN4                   5672 /* (USINT) FB DIO: input value 4 */
#define ACP10PAR_DIO_IN5                   5680 /* (USINT) FB DIO: input value 5 */
#define ACP10PAR_DIO_IN6                   5688 /* (USINT) FB DIO: input value 6 */
#define ACP10PAR_DIO_IN7                   5696 /* (USINT) FB DIO: input value 7 */
#define ACP10PAR_DIO_IN8                   5704 /* (USINT) FB DIO: input value 8 */
#define ACP10PAR_DIO_IN9                   5712 /* (USINT) FB DIO: input value 9 */
#define ACP10PAR_DIO_IN10                  5720 /* (USINT) FB DIO: input value 10 */
#define ACP10PAR_DIO_IN11                  5728 /* (USINT) FB DIO: input value 11 */
#define ACP10PAR_DIO_IN12                  5736 /* (USINT) FB DIO: input value 12 */
#define ACP10PAR_DIO_IN13                  5744 /* (USINT) FB DIO: input value 13 */
#define ACP10PAR_DIO_IN14                  5752 /* (USINT) FB DIO: input value 14 */
#define ACP10PAR_DIO_IN15                  5760 /* (USINT) FB DIO: input value 15 */
#define ACP10PAR_DIO_IN16                  5768 /* (USINT) FB DIO: input value 16 */
#define ACP10PAR_DIO_OUT1_PARID            5776 /* (UINT) FB DIO: parameter ID of output 1 */
#define ACP10PAR_DIO_OUT2_PARID            5784 /* (UINT) FB DIO: parameter ID of output 2 */
#define ACP10PAR_DIO_OUT3_PARID            5792 /* (UINT) FB DIO: parameter ID of output 3 */
#define ACP10PAR_DIO_OUT4_PARID            5800 /* (UINT) FB DIO: parameter ID of output 4 */
#define ACP10PAR_DIO_OUT5_PARID            5808 /* (UINT) FB DIO: parameter ID of output 5 */
#define ACP10PAR_DIO_OUT6_PARID            5816 /* (UINT) FB DIO: parameter ID of output 6 */
#define ACP10PAR_DIO_OUT7_PARID            5824 /* (UINT) FB DIO: parameter ID of output 7 */
#define ACP10PAR_DIO_OUT8_PARID            5832 /* (UINT) FB DIO: parameter ID of output 8 */
#define ACP10PAR_DIO_OUT9_PARID            5840 /* (UINT) FB DIO: parameter ID of output 9 */
#define ACP10PAR_DIO_OUT10_PARID           5848 /* (UINT) FB DIO: parameter ID of output 10 */
#define ACP10PAR_DIO_OUT11_PARID           5856 /* (UINT) FB DIO: parameter ID of output 11 */
#define ACP10PAR_DIO_OUT12_PARID           5864 /* (UINT) FB DIO: parameter ID of output 12 */
#define ACP10PAR_DIO_OUT13_PARID           5872 /* (UINT) FB DIO: Parameter ID of output 13 */
#define ACP10PAR_DIO_OUT14_PARID           5880 /* (UINT) FB DIO: parameter ID of output 14 */
#define ACP10PAR_DIO_OUT15_PARID           5888 /* (UINT) FB DIO: parameter ID of output 15 */
#define ACP10PAR_DIO_OUT16_PARID           5896 /* (UINT) FB DIO: parameter ID of output 16 */
#define ACP10PAR_DIO_CMD_SET_OUT           5904 /* (UINT) FB DIO: Command set outputs */
#define ACP10PAR_DIO_CMD_CLR_OUT           5912 /* (UINT) FB DIO: Command clear outputs */
#define ACP10PAR_DIO_DIR                   5920 /* (UINT) FB DIO: IO configuration */
#define ACP10PAR_DIO_CNT1                  5928 /* (UDINT) FB DIO: Counter input 1 */
#define ACP10PAR_DIO_CNT2                  5936 /* (UDINT) FB DIO: Counter input 2 */
#define ACP10PAR_DIO_CHK                   5944 /* (UINT) FB DIO: Checks */
#define ACP10PAR_DIO_OUT_MASK              5952 /* (UINT) FB DIO: output mask */
#define ACP10PAR_DIO_IN_FILTER_TIME        5960 /* (REAL) FB DIO: input filter: filter time [s] */
#define ACP10PAR_DIO_IN7_RISE_EDGE_TIME    5968 /* (UDINT) FB DIO: input 7: Time of the rising edge [us] */
#define ACP10PAR_DIO_IN7_FALL_EDGE_TIME    5976 /* (UDINT) FB DIO: input 7: Time of the falling edge [us] */
#define ACP10PAR_DIO_IN8_RISE_EDGE_TIME    5984 /* (UDINT) FB DIO: input 8: Time of the rising edge [us] */
#define ACP10PAR_DIO_IN8_FALL_EDGE_TIME    5992 /* (UDINT) FB DIO: input 8: Time of the falling edge [us] */
#define ACP10PAR_DIO_OUT_ENABLED           6000 /* (UDINT) FB DIO: Read output configuration */
#define ACP10PAR_DIO_CMD_SET_OUT_ENABLE    6008 /* (UDINT) FB DIO: Command set output configuration */
#define ACP10PAR_DIO_CMD_CLR_OUT_ENABLE    6016 /* (UDINT) FB DIO: Command clear output configuration */
#define ACP10PAR_DIO_IN_ENABLED            6024 /* (UDINT) FB DIO: Read input configuration */
#define ACP10PAR_DIO_CMD_SET_IN_ENABLE     6032 /* (UDINT) FB DIO: Command set input configuration */
#define ACP10PAR_DIO_CMD_CLR_IN_ENABLE     6040 /* (UDINT) FB DIO: Command clear input configuration */
#define ACP10PAR_DIO_OUT_FB                6048 /* (UINT) FB DIO: output feedback */
#define ACP10PAR_DIO_STATUS                6056 /* (UDINT) FB DIO: State */
#define ACP10PAR_DIO_IDX                   6064 /* (USINT) FB DIO: Index of the current digital IO */
#define ACP10PAR_DIO_CNT_MODE              6072 /* (UDINT) FB DIO: Event counter mode */
#define ACP10PAR_AIO_IN1                   6144 /* (INT) FB AIO: channel 1: Analog value */
#define ACP10PAR_AIO_IN2                   6152 /* (INT) FB AIO: channel 2: Analog value */
#define ACP10PAR_AIO_CMP1_THRESH_PARID     6160 /* (UINT) FB AIO: channel 1: Comparator threshold pointer parameter */
#define ACP10PAR_AIO_CMP2_THRESH_PARID     6168 /* (UINT) FB AIO: channel 2: Comparator threshold pointer parameter */
#define ACP10PAR_AIO_CMP1_FILTER           6176 /* (REAL) FB AIO: channel 1: Comparator filter time [s] */
#define ACP10PAR_AIO_CMP2_FILTER           6184 /* (REAL) FB AIO: channel 2: Comparator filter time [s] */
#define ACP10PAR_AIO_CMP1_RISE_EDGE_TIME   6192 /* (UDINT) FB AIO: channel 1: Time of the rising edge of the comparator output [us] */
#define ACP10PAR_AIO_CMP2_RISE_EDGE_TIME   6200 /* (UDINT) FB AIO: channel 2: Time of the rising edge of the comparator output [us] */
#define ACP10PAR_AIO_CMP1_FALL_EDGE_TIME   6208 /* (UDINT) FB AIO: channel 1: Time of the falling edge of the comparator output [us] */
#define ACP10PAR_AIO_CMP2_FALL_EDGE_TIME   6216 /* (UDINT) FB AIO: channel 2: Time of the falling edge of the comparator output [us] */
#define ACP10PAR_AIO_CMP1_MODE             6224 /* (UINT) FB AIO: channel 1: Comparator mode */
#define ACP10PAR_AIO_CMP2_MODE             6232 /* (UINT) FB AIO: channel 2: Comparator mode */
#define ACP10PAR_AIO_CMP1_MINMAX           6240 /* (INT) FB AIO: channel 1: Comparator extremum (minimum, maximum) */
#define ACP10PAR_AIO_CMP2_MINMAX           6248 /* (INT) FB AIO: channel 2: Comparator extremum (minimum, maximum) */
#define ACP10PAR_AIO_CMP1_VALUE            6256 /* (USINT) FB AIO: channel 1: Comparator output */
#define ACP10PAR_AIO_CMP2_VALUE            6264 /* (USINT) FB AIO: channel 2: Comparator output */
#define ACP10PAR_AIO_STATUS                6272 /* (UINT) FB AIO: state */
#define ACP10PAR_AIO_IN1_FILTER            6280 /* (REAL) FB AIO: channel 1: Filter [s] */
#define ACP10PAR_AIO_IN2_FILTER            6288 /* (REAL) FB AIO: channel 2: Filter [s] */
#define ACP10PAR_AIO_IN3                   6296 /* (INT) FB AIO: channel 3: Analog value */
#define ACP10PAR_AIO_IN4                   6304 /* (INT) FB AIO: channel 4: Analog value */
#define ACP10PAR_AIO_OUT_ENABLED           6312 /* (UDINT) FB AIO: Read output configuration */
#define ACP10PAR_AIO_CMD_SET_OUT_ENABLE    6320 /* (UDINT) FB AIO: Command set output configuration */
#define ACP10PAR_AIO_CMD_CLR_OUT_ENABLE    6328 /* (UDINT) FB AIO: Command clear output configuration */
#define ACP10PAR_AIO_IN_ENABLED            6336 /* (UDINT) FB AIO: Read input configuration */
#define ACP10PAR_AIO_CMD_SET_IN_ENABLE     6344 /* (UDINT) FB AIO: Command set input configuration */
#define ACP10PAR_AIO_CMD_CLR_IN_ENABLE     6352 /* (UDINT) FB AIO: Command clear input configuration */
#define ACP10PAR_AIO_IDX                   6360 /* (USINT) FB AIO: Index of the current analog IO */
#define ACP10PAR_AIO_OUT_PARID             6368 /* (UINT) FB AIO: parameter ID of output (Index) */
#define ACP10PAR_AIO_OUT_MODE              6376 /* (UDINT) FB AIO: output mode (Index) */
#define ACP10PAR_AIO_CMD                   6384 /* (UDINT) FB AIO: IO-Command */
#define ACP10PAR_AIO_CHK                   6392 /* (UDINT) FB AIO: Checks */
#define ACP10PAR_AIO_IN_FILTER_CONFIG      6400 /* (UDINT) FB AIO: Input: Filter: Configuration (Index) */
#define ACP10PAR_AIO_IN_FILTER_SLEWRATE    6408 /* (REAL) FB AIO: Input: Filter: Maximal Slew Rate (Index) [V/s] */
#define ACP10PAR_CMP_IN_PARID              6656 /* (UINT) FB CMP: parameter ID of input */
#define ACP10PAR_CMP_THRESHOLD             6664 /* (REAL) FB CMP: threshold */
#define ACP10PAR_CMP_WINDOW                6672 /* (REAL) FB CMP: window */
#define ACP10PAR_CMP_HYSTERESIS            6680 /* (REAL) FB CMP: hysteresis window */
#define ACP10PAR_CMP_MODE                  6688 /* (UINT) FB CMP: mode */
#define ACP10PAR_CMP_VALUE                 6696 /* (USINT) FB CMP: result value */
#define ACP10PAR_DELAY_IN_PARID            7168 /* (UINT) FB DELAY: parameter ID of input */
#define ACP10PAR_DELAY_TIME                7176 /* (REAL) FB DELAY: time [s] */
#define ACP10PAR_DELAY_VALUE_I4            7184 /* (DINT) FB DELAY: I4 result value */
#define ACP10PAR_DELAY_VALUE_FRAC          7192 /* (REAL) FB DELAY: I4 result value fractional part */
#define ACP10PAR_DELAY_VALUE_R4            7200 /* (REAL) FB DELAY: R4 result value */
#define ACP10PAR_PID_IN_PARID              7680 /* (UINT) FB PID: parameter ID of input */
#define ACP10PAR_PID_KP                    7688 /* (REAL) FB PID: proportional amplification factor */
#define ACP10PAR_PID_TI                    7696 /* (REAL) FB PID: integral action time [s] */
#define ACP10PAR_PID_I_MAX                 7704 /* (REAL) FB PID: maximum integral action */
#define ACP10PAR_PID_TD                    7712 /* (REAL) FB PID: derivative action time [s] */
#define ACP10PAR_PID_T1                    7720 /* (REAL) FB PID: time delay constant [s] */
#define ACP10PAR_PID_VALUE                 7728 /* (REAL) FB PID: result value */
#define ACP10PAR_PID_ENABLE_PARID          7736 /* (UINT) FB PID: parameter ID of enable input */
#define ACP10PAR_PID_P_VALUE               7744 /* (REAL) FB PID: result of P part */
#define ACP10PAR_PID_I_VALUE               7752 /* (REAL) FB PID: result of I part */
#define ACP10PAR_PID_DT1_VALUE             7760 /* (REAL) FB PID: result of DT1 part */
#define ACP10PAR_CURVE_MODE                8192 /* (UINT) FB CURVE: Mode */
#define ACP10PAR_CURVE_IN_PARID            8200 /* (UINT) FB CURVE: Parameter ID of input */
#define ACP10PAR_CURVE_AUT_DATA_INDEX      8208 /* (UINT) FB CURVE: Index of cam data */
#define ACP10PAR_CURVE_VALUE_I4            8216 /* (DINT) FB CURVE: Result value I4 */
#define ACP10PAR_CURVE_VALUE_FRAC          8224 /* (REAL) FB CURVE: Result value I4 fractional part */
#define ACP10PAR_CURVE_VALUE_R4            8232 /* (REAL) FB CURVE: Result value R4 */
#define ACP10PAR_CURVE_VALUE_REL_I4        8240 /* (DINT) FB CURVE: Result value I4 relative within interval */
#define ACP10PAR_CURVE_VALUE_REL_FRAC      8248 /* (REAL) FB CURVE: Result value I4 relative fractional part */
#define ACP10PAR_CURVE_VALUE_REL_R4        8256 /* (REAL) FB CURVE: Result value R4 relative within interval */
#define ACP10PAR_CURVE_VALUE_OFFSET        8264 /* (DINT) FB CURVE: Result value interval offset */
#define ACP10PAR_CURVE_X_FACTOR            8272 /* (DINT) FB CURVE: Multiplication factor for input interval */
#define ACP10PAR_CURVE_Y_FACTOR            8280 /* (DINT) FB CURVE: Multiplication factor for output interval */
#define ACP10PAR_CURVE_COMP_CMD            8288 /* (UINT) FB CURVE: Compensation gears command */
#define ACP10PAR_CURVE_COMP_MA_S           8296 /* (DINT) FB CURVE: Compensation distance of master axis, input interval [Units] */
#define ACP10PAR_CURVE_COMP_SL_S           8304 /* (DINT) FB CURVE: Compensation distance of slave axis, output interval [Units] */
#define ACP10PAR_CURVE_COMP_K1             8312 /* (REAL) FB CURVE: Entrance gradient in the compensation gears */
#define ACP10PAR_CURVE_COMP_K2             8320 /* (REAL) FB CURVE: Exit gradient from the compensation gears */
#define ACP10PAR_CURVE_COMP_MA_V_MAX       8328 /* (REAL) FB CURVE: Maximum speed of master axis [Units/s] */
#define ACP10PAR_CURVE_COMP_SL_V_MAX       8336 /* (REAL) FB CURVE: Maximum speed of slave axis within compensation gears [Units/s] */
#define ACP10PAR_CURVE_COMP_SL_V_MIN       8344 /* (REAL) FB CURVE: Minimum speed of slave axis within compensation gears [Units/s] */
#define ACP10PAR_CURVE_COMP_SL_A1_MAX      8352 /* (REAL) FB CURVE: Maximum acceleration of slave axis within compensation phase1 [Units/s²] */
#define ACP10PAR_CURVE_COMP_SL_A2_MAX      8360 /* (REAL) FB CURVE: Maximum acceleration of slave axis within compensation phase2 [Units/s²] */
#define ACP10PAR_CURVE_COMP_CMD_STATUS     8368 /* (USINT) FB CURVE: Compensation gears command status */
#define ACP10PAR_CURVE_COMP_RESULT         8376 /* (REAL) FB CURVE: Compensation gears command result */
#define ACP10PAR_CURVE_X_ADD               8384 /* (DINT) FB CURVE: Additive input value */
#define ACP10PAR_CURVE_Y_ADD               8392 /* (DINT) FB CURVE: Additive output value */
#define ACP10PAR_IPL_MODE                  8704 /* (UINT) FB IPL: Mode */
#define ACP10PAR_IPL_IN_PARID              8712 /* (UINT) FB IPL: Parameter ID of input */
#define ACP10PAR_IPL_CYCLE_TIME            8720 /* (UDINT) FB IPL: Cycle time [us] */
#define ACP10PAR_IPL_EXTRAPOLATION_TIME    8728 /* (UDINT) FB IPL: Extrapolation time [us] */
#define ACP10PAR_IPL_VALUE_I4              8736 /* (DINT) FB IPL: Result value I4 */
#define ACP10PAR_IPL_VALUE_FRAC            8744 /* (REAL) FB IPL: Result value I4 fractional part */
#define ACP10PAR_IPL_VALUE_R4              8752 /* (REAL) FB IPL: Result value R4 */
#define ACP10PAR_IPL_EV_PARID              8760 /* (UINT) FB IPL: Parameter ID of event input */
#define ACP10PAR_VARITH_MODE               9216 /* (UINT) FB VARITH: Mode */
#define ACP10PAR_VARITH_DIMENSION          9224 /* (UINT) FB VARITH: Dimension */
#define ACP10PAR_VARITH_IN_A1_PARID        9232 /* (UINT) FB VARITH: Parameter ID of input, element a1 */
#define ACP10PAR_VARITH_IN_A2_PARID        9240 /* (UINT) FB VARITH: Parameter ID of input, element a2 */
#define ACP10PAR_VARITH_IN_A3_PARID        9248 /* (UINT) FB VARITH: Parameter ID of input, element a3 */
#define ACP10PAR_VARITH_IN_A4_PARID        9256 /* (UINT) FB VARITH: Parameter ID of input, element a4 */
#define ACP10PAR_VARITH_IN_A5_PARID        9264 /* (UINT) FB VARITH: Parameter ID of input, element a5 */
#define ACP10PAR_VARITH_IN_B1_PARID        9272 /* (UINT) FB VARITH: Parameter ID of input, element b1 */
#define ACP10PAR_VARITH_IN_B2_PARID        9280 /* (UINT) FB VARITH: Parameter ID of input, element b2 */
#define ACP10PAR_VARITH_IN_B3_PARID        9288 /* (UINT) FB VARITH: Parameter ID of input, element b3 */
#define ACP10PAR_VARITH_IN_B4_PARID        9296 /* (UINT) FB VARITH: Parameter ID of input, element b4 */
#define ACP10PAR_VARITH_IN_B5_PARID        9304 /* (UINT) FB VARITH: Parameter ID of input, element b5 */
#define ACP10PAR_VARITH_VALUE1             9312 /* (REAL) FB VARITH: Result value1 */
#define ACP10PAR_VARITH_VALUE2             9320 /* (REAL) FB VARITH: Result value2 */
#define ACP10PAR_VARITH_VALUE3             9328 /* (REAL) FB VARITH: Result value3 */
#define ACP10PAR_VARITH_VALUE4             9336 /* (REAL) FB VARITH: Result value4 */
#define ACP10PAR_VARITH_VALUE5             9344 /* (REAL) FB VARITH: Result value5 */
#define ACP10PAR_LATCH_MODE                9728 /* (UINT) FB LATCH: Mode */
#define ACP10PAR_LATCH_IN_PARID            9736 /* (UINT) FB LATCH: Parameter ID of input */
#define ACP10PAR_LATCH_EV_PARID            9744 /* (UINT) FB LATCH: Parameter ID of trigger event input */
#define ACP10PAR_LATCH_EV_TYPE             9752 /* (USINT) FB LATCH: Trigger event type */
#define ACP10PAR_LATCH_EV_WIDTH_MIN        9760 /* (DINT) FB LATCH: Minimal signal width of trigger event */
#define ACP10PAR_LATCH_EV_WIDTH_MAX        9768 /* (DINT) FB LATCH: Maximum signal width of trigger event */
#define ACP10PAR_LATCH_WINDOW              9776 /* (DINT) FB LATCH: Window */
#define ACP10PAR_LATCH_WINDOW_POS          9784 /* (DINT) FB LATCH: Window position */
#define ACP10PAR_LATCH_POS_IV              9792 /* (DINT) FB LATCH: Interval of window position */
#define ACP10PAR_LATCH_POS_IV_ELONG        9800 /* (DINT) FB LATCH: Interval elongation of window position */
#define ACP10PAR_LATCH_T_DELAY             9808 /* (DINT) FB LATCH: Delay time [us] */
#define ACP10PAR_LATCH_EV_WIDTH            9816 /* (DINT) FB LATCH: Signal width of trigger event */
#define ACP10PAR_LATCH_VALUE               9824 /* (DINT) FB LATCH: Result value */
#define ACP10PAR_LATCH_DELTA_IV            9832 /* (DINT) FB LATCH: Difference: Window position minus result value */
#define ACP10PAR_LATCH_STATUS              9840 /* (USINT) FB LATCH: Status */
#define ACP10PAR_LATCH_ERROR_COUNT         9848 /* (USINT) FB LATCH: Error counter */
#define ACP10PAR_LATCH_WINDOW1             9856 /* (DINT) FB LATCH: Window1 */
#define ACP10PAR_LATCH_WINDOW2             9864 /* (DINT) FB LATCH: Window2 */
#define ACP10PAR_LATCH_STATUS_COUNT        9872 /* (USINT) FB LATCH: Status counter */
#define ACP10PAR_EPROM_ID                 10240 /* (UINT) FB EPROM: ID */
#define ACP10PAR_EPROM_BLOCK_INDEX        10248 /* (UINT) FB EPROM: Data block index */
#define ACP10PAR_EPROM_BLOCK              10256 /* (DATA) FB EPROM: Data block */
#define ACP10PAR_EPROM_PRODUCT_CODE       10264 /* (UDINT) FB EPROM: Product code */
#define ACP10PAR_EPROM_SERIAL_NO          10272 /* (UDINT) FB EPROM: Serial number */
#define ACP10PAR_EPROM_PRODUCT_TYPE       10280 /* (UDINT) FB EPROM: Product type */
#define ACP10PAR_EPROM_HW_REVISION        10288 /* (UINT) FB EPROM: Hardware revision */
#define ACP10PAR_EPROM_HW_VARIANT         10296 /* (UDINT) FB EPROM: Hardware variant */
#define ACP10PAR_EPROM_STAT               10304 /* (UDINT) FB EPROM: Status */
#define ACP10PAR_EPROM_MISSION_TIME_END   10312 /* (UDINT) FB EPROM: End date of mission time */
#define ACP10PAR_CAMCON_MODE              10752 /* (UINT) FB CAMCON: Mode */
#define ACP10PAR_CAMCON_IN_PARID          10760 /* (UINT) FB CAMCON: Parameter ID of input */
#define ACP10PAR_CAMCON_S_START           10768 /* (DINT) FB CAMCON: Start position */
#define ACP10PAR_CAMCON_S_IV              10776 /* (DINT) FB CAMCON: Interval */
#define ACP10PAR_CAMCON_T_DELAY_ON        10784 /* (REAL) FB CAMCON: Delay time to switch output ON [s] */
#define ACP10PAR_CAMCON_T_DELAY_OFF       10792 /* (REAL) FB CAMCON: Delay time to switch output OFF [s] */
#define ACP10PAR_CAMCON_T1_DELAY          10800 /* (REAL) FB CAMCON: Switch delay: Filter time constant [s] */
#define ACP10PAR_CAMCON_HYSTERESIS        10808 /* (REAL) FB CAMCON: Hysteresis window */
#define ACP10PAR_CAMCON_MAX_CAM           10816 /* (UINT) FB CAMCON: Maximum number of cams */
#define ACP10PAR_CAMCON_CAM_INDEX         10824 /* (UINT) FB CAMCON: Index of parameter record for one cam */
#define ACP10PAR_CAMCON_CAM_S1            10832 /* (REAL) FB CAMCON: Start position of cam within interval */
#define ACP10PAR_CAMCON_CAM_S2            10840 /* (REAL) FB CAMCON: End position of cam within interval */
#define ACP10PAR_CAMCON_VALUE             10848 /* (USINT) FB CAMCON: Output value */
#define ACP10PAR_CAMCON_V_IN              10856 /* (REAL) FB CAMCON: Input speed */
#define ACP10PAR_CAMCON_EV_PARID          10864 /* (UINT) FB CAMCON: Parameter ID start event */
#define ACP10PAR_CAMCON_PAR_REC           10872 /* (USINT) FB CAMCON: Parameter record for one track */
#define ACP10PAR_CAMCON_SELECT_REC        10880 /* (USINT) FB CAMCON: Select parameter record for one track */
#define ACP10PAR_CAMCON_SELECT_MODE       10888 /* (USINT) FB CAMCON: Mode to select a parameter record for one track */
#define ACP10PAR_CAMCON_ACT_REC           10896 /* (USINT) FB CAMCON: Active parameter record for one track */
#define ACP10PAR_MUX_MODE                 11264 /* (UINT) FB MUX: Mode */
#define ACP10PAR_MUX_SELECTOR_PARID       11272 /* (UINT) FB MUX: Parameter ID of selector input */
#define ACP10PAR_MUX_SELECTOR_MAX         11280 /* (UINT) FB MUX: Maximum selector value */
#define ACP10PAR_MUX_VALUE_I4             11288 /* (DINT) FB MUX: Output value I4 */
#define ACP10PAR_MUX_VALUE_R4             11296 /* (REAL) FB MUX: Output value R4 */
#define ACP10PAR_MUX_VALUE_OFFSET_I4      11304 /* (DINT) FB MUX: Output value offset I4 */
#define ACP10PAR_MUX_VALUE_OFFSET_R4      11312 /* (REAL) FB MUX: Output value offset R4 */
#define ACP10PAR_MUX_IN0_PARID            11320 /* (UINT) FB MUX: Parameter ID of input0 */
#define ACP10PAR_MUX_IN1_PARID            11328 /* (UINT) FB MUX: Parameter ID of input1 */
#define ACP10PAR_MUX_IN2_PARID            11336 /* (UINT) FB MUX: Parameter ID of input2 */
#define ACP10PAR_MUX_IN3_PARID            11344 /* (UINT) FB MUX: Parameter ID of input3 */
#define ACP10PAR_MUX_IN4_PARID            11352 /* (UINT) FB MUX: Parameter ID of input4 */
#define ACP10PAR_MUX_IN5_PARID            11360 /* (UINT) FB MUX: Parameter ID of input5 */
#define ACP10PAR_MUX_IN6_PARID            11368 /* (UINT) FB MUX: Parameter ID of input6 */
#define ACP10PAR_MUX_IN7_PARID            11376 /* (UINT) FB MUX: Parameter ID of input7 */
#define ACP10PAR_MUX_IN8_PARID            11384 /* (UINT) FB MUX: Parameter ID of input8 */
#define ACP10PAR_MUX_IN9_PARID            11392 /* (UINT) FB MUX: Parameter ID of input9 */
#define ACP10PAR_MUX_IN10_PARID           11400 /* (UINT) FB MUX: Parameter ID of input10 */
#define ACP10PAR_MUX_IN11_PARID           11408 /* (UINT) FB MUX: Parameter ID of input11 */
#define ACP10PAR_MUX_IN12_PARID           11416 /* (UINT) FB MUX: Parameter ID of input12 */
#define ACP10PAR_MUX_IN13_PARID           11424 /* (UINT) FB MUX: Parameter ID of input13 */
#define ACP10PAR_MUX_IN14_PARID           11432 /* (UINT) FB MUX: Parameter ID of input14 */
#define ACP10PAR_MUX_IN15_PARID           11440 /* (UINT) FB MUX: Parameter ID of input15 */
#define ACP10PAR_MUX_OFFSET_K             11448 /* (REAL) FB MUX: Gradient of offset ramp [1/s] */
#define ACP10PAR_MUX_OFFSET_T             11456 /* (UDINT) FB MUX: Time of offset ramp [us] */
#define ACP10PAR_FIFO_MODE                11776 /* (UINT) FB FIFO: Mode */
#define ACP10PAR_FIFO_MAX_LENGTH          11784 /* (UINT) FB FIFO: Maximum length */
#define ACP10PAR_FIFO_VALUE2_DISTANCE     11792 /* (UINT) FB FIFO: Distance for output value2 */
#define ACP10PAR_FIFO_IN_PARID            11800 /* (UINT) FB FIFO: Parameter ID input */
#define ACP10PAR_FIFO_IN_EV_PARID         11808 /* (UINT) FB FIFO: Parameter ID input event */
#define ACP10PAR_FIFO_OUT_EV_PARID        11816 /* (UINT) FB FIFO: Parameter ID output event */
#define ACP10PAR_FIFO_ACT_LENGTH          11824 /* (UINT) FB FIFO: Actual length */
#define ACP10PAR_FIFO_VALUE_I4            11832 /* (DINT) FB FIFO: Output value I4 */
#define ACP10PAR_FIFO_VALUE_R4            11840 /* (REAL) FB FIFO: Output value R4 */
#define ACP10PAR_FIFO_VALUE2_I4           11848 /* (DINT) FB FIFO: Output value2 I4 */
#define ACP10PAR_FIFO_VALUE2_R4           11856 /* (REAL) FB FIFO: Output value2 R4 */
#define ACP10PAR_MINMAX_MODE              12288 /* (UINT) FB MINMAX: Mode */
#define ACP10PAR_MINMAX_VALUE_I4          12296 /* (DINT) FB MINMAX: Output value I4 */
#define ACP10PAR_MINMAX_VALUE_R4          12304 /* (REAL) FB MINMAX: Output value R4 */
#define ACP10PAR_MINMAX_IN1_PARID         12312 /* (UINT) FB MINMAX: Parameter ID of input1 */
#define ACP10PAR_MINMAX_IN2_PARID         12320 /* (UINT) FB MINMAX: Parameter ID of input2 */
#define ACP10PAR_MINMAX_IN3_PARID         12328 /* (UINT) FB MINMAX: Parameter ID of input3 */
#define ACP10PAR_MINMAX_IN4_PARID         12336 /* (UINT) FB MINMAX: Parameter ID of input4 */
#define ACP10PAR_BIT_MODE                 12800 /* (UINT) FB BIT: Mode */
#define ACP10PAR_BIT_A1                   12808 /* (UDINT) FB BIT: Operand a1 */
#define ACP10PAR_BIT_A2                   12816 /* (UDINT) FB BIT: Operand a2 */
#define ACP10PAR_BIT_A3                   12824 /* (UDINT) FB BIT: Operand a3 */
#define ACP10PAR_BIT_A4                   12832 /* (UDINT) FB BIT: Operand a4 */
#define ACP10PAR_BIT_A5                   12840 /* (UDINT) FB BIT: Operand a5 */
#define ACP10PAR_BIT_A6                   12848 /* (UDINT) FB BIT: Operand a6 */
#define ACP10PAR_BIT_A7                   12856 /* (UDINT) FB BIT: Operand a7 */
#define ACP10PAR_BIT_A8                   12864 /* (UDINT) FB BIT: Operand a8 */
#define ACP10PAR_BIT_B1                   12872 /* (UDINT) FB BIT: Operand b1 */
#define ACP10PAR_BIT_B2                   12880 /* (UDINT) FB BIT: Operand b2 */
#define ACP10PAR_BIT_B3                   12888 /* (UDINT) FB BIT: Operand b3 */
#define ACP10PAR_BIT_B4                   12896 /* (UDINT) FB BIT: Operand b4 */
#define ACP10PAR_BIT_B5                   12904 /* (UDINT) FB BIT: Operand b5 */
#define ACP10PAR_BIT_B6                   12912 /* (UDINT) FB BIT: Operand b6 */
#define ACP10PAR_BIT_B7                   12920 /* (UDINT) FB BIT: Operand b7 */
#define ACP10PAR_BIT_B8                   12928 /* (UDINT) FB BIT: Operand b8 */
#define ACP10PAR_BIT_IN1_PARID            12936 /* (UINT) FB BIT: Parameter ID of input1 */
#define ACP10PAR_BIT_IN2_PARID            12944 /* (UINT) FB BIT: Parameter ID of input2 */
#define ACP10PAR_BIT_IN3_PARID            12952 /* (UINT) FB BIT: Parameter ID of input3 */
#define ACP10PAR_BIT_IN4_PARID            12960 /* (UINT) FB BIT: Parameter ID of input4 */
#define ACP10PAR_BIT_IN5_PARID            12968 /* (UINT) FB BIT: Parameter ID of input5 */
#define ACP10PAR_BIT_IN6_PARID            12976 /* (UINT) FB BIT: Parameter ID of input6 */
#define ACP10PAR_BIT_IN7_PARID            12984 /* (UINT) FB BIT: Parameter ID of input7 */
#define ACP10PAR_BIT_IN8_PARID            12992 /* (UINT) FB BIT: Parameter ID of input8 */
#define ACP10PAR_BIT_VALUE1_UI1           13000 /* (USINT) FB BIT: Result value1 UI1 */
#define ACP10PAR_BIT_VALUE1_UI2           13008 /* (UINT) FB BIT: Result value1 UI2 */
#define ACP10PAR_BIT_VALUE1               13016 /* (UDINT) FB BIT: Result value1 */
#define ACP10PAR_BIT_VALUE2               13024 /* (UDINT) FB BIT: Result value2 */
#define ACP10PAR_BIT_VALUE3               13032 /* (UDINT) FB BIT: Result value3 */
#define ACP10PAR_BIT_VALUE4               13040 /* (UDINT) FB BIT: Result value4 */
#define ACP10PAR_BIT_VALUE5               13048 /* (UDINT) FB BIT: Result value5 */
#define ACP10PAR_BIT_VALUE6               13056 /* (UDINT) FB BIT: Result value6 */
#define ACP10PAR_BIT_VALUE7               13064 /* (UDINT) FB BIT: Result value7 */
#define ACP10PAR_BIT_VALUE8               13072 /* (UDINT) FB BIT: Result value8 */
#define ACP10PAR_COUNT_MODE               13824 /* (UINT) FB COUNT: Mode */
#define ACP10PAR_COUNT_EV1_PARID          13832 /* (UINT) FB COUNT: Parameter ID of event input1 */
#define ACP10PAR_COUNT_EV2_PARID          13840 /* (UINT) FB COUNT: Parameter ID of event input2 */
#define ACP10PAR_COUNT_SET_TRIG_PARID     13848 /* (UINT) FB COUNT: Parameter ID trigger input to set counter value */
#define ACP10PAR_COUNT_SET_VALUE          13856 /* (UDINT) FB COUNT: Value to set counter */
#define ACP10PAR_COUNT_MAX_VALUE          13864 /* (UDINT) FB COUNT: Maximum counter value */
#define ACP10PAR_COUNT_CMP_VALUE          13872 /* (UDINT) FB COUNT: Comparator compare value */
#define ACP10PAR_COUNT_VALUE              13880 /* (UDINT) FB COUNT: Result value */
#define ACP10PAR_COUNT_CMP_STATUS         13888 /* (USINT) FB COUNT: Comparator status */
#define ACP10PAR_COUNT_EV_STATUS          13896 /* (USINT) FB COUNT: Event status  */
#define ACP10PAR_COUNT_ENABLE_PARID       13904 /* (UINT) FB COUNT: Parameter ID of enable input */
#define ACP10PAR_DYNSYS_MODE              14336 /* (UINT) FB DYNSYS: Mode */
#define ACP10PAR_DYNSYS_PAR_A             14344 /* (REAL) FB DYNSYS: System parameter A */
#define ACP10PAR_DYNSYS_PAR_B             14352 /* (REAL) FB DYNSYS: System parameter B */
#define ACP10PAR_DYNSYS_PAR_C             14360 /* (REAL) FB DYNSYS: System parameter C */
#define ACP10PAR_DYNSYS_PAR_D             14368 /* (REAL) FB DYNSYS: System parameter D */
#define ACP10PAR_DYNSYS_TUNE1             14376 /* (REAL) FB DYNSYS: Tuning parameter 1 for observer design */
#define ACP10PAR_DYNSYS_TUNE2             14384 /* (REAL) FB DYNSYS: Tuning parameter 2 for observer design */
#define ACP10PAR_DYNSYS_TUNE3             14392 /* (REAL) FB DYNSYS: Tuning parameter 1 for output design */
#define ACP10PAR_DYNSYS_TUNE4             14400 /* (REAL) FB DYNSYS: Tuning parameter 2 for output design */
#define ACP10PAR_DYNSYS_IN1_PARID         14408 /* (UINT) FB DYNSYS: Parameter ID for input 1 */
#define ACP10PAR_DYNSYS_IN2_PARID         14416 /* (UINT) FB DYNSYS: Parameter ID for input 2 */
#define ACP10PAR_DYNSYS_OUT1_VALUE        14424 /* (REAL) FB DYNSYS: Output 1 */
#define ACP10PAR_DYNSYS_OUT2_VALUE        14432 /* (REAL) FB DYNSYS: Output 2 */
#define ACP10PAR_DYNSYS_OUT1_SCALE_PARID  14440 /* (UINT) FB DYNSYS: Multiplier for output 1 */
#define ACP10PAR_DYNSYS_OUT2_SCALE_PARID  14448 /* (UINT) FB DYNSYS: Multiplier for output 2 */
#define ACP10PAR_DYNSYS_STATE1            14456 /* (REAL) FB DYNSYS: System state 1 */
#define ACP10PAR_DYNSYS_STATE2            14464 /* (REAL) FB DYNSYS: System state 2 */
#define ACP10PAR_DYNSYS_STATE3            14472 /* (REAL) FB DYNSYS: System state 3 */
#define ACP10PAR_DYNSYS_STATE4            14480 /* (REAL) FB DYNSYS: System state 4 */
#define ACP10PAR_DYNSYS_STATE5            14488 /* (REAL) FB DYNSYS: System state 5 */
#define ACP10PAR_DYNSYS_STATUS            14496 /* (UINT) FB DYNSYS: Status */
#define ACP10PAR_FILTER_MODE              14848 /* (UINT) FB FILTER: Mode */
#define ACP10PAR_FILTER_A0                14856 /* (REAL) FB FILTER: Coefficient A0 */
#define ACP10PAR_FILTER_A1                14864 /* (REAL) FB FILTER: Coefficient A1 */
#define ACP10PAR_FILTER_B0                14872 /* (REAL) FB FILTER: Coefficient B0 */
#define ACP10PAR_FILTER_B1                14880 /* (REAL) FB FILTER: Coefficient B1 */
#define ACP10PAR_FILTER_B2                14888 /* (REAL) FB FILTER: Coefficient B2 */
#define ACP10PAR_FILTER_IN_PARID          14896 /* (UINT) FB FILTER: Parameter ID of input */
#define ACP10PAR_FILTER_C_PARID           14904 /* (UINT) FB FILTER: Parameter ID of coefficient C */
#define ACP10PAR_FILTER_VALUE_I4          14912 /* (DINT) FB FILTER: Result value I4 */
#define ACP10PAR_FILTER_VALUE_FRAC        14920 /* (REAL) FB FILTER: Result value I4 fractional part */
#define ACP10PAR_FILTER_VALUE_R4          14928 /* (REAL) FB FILTER: Result value R4 */
#define ACP10PAR_SHTL_INIT_POSITION_INFO  63488 /* (DINT) Parameter identification: Additional information of initial shuttle position */
#define ACP10PAR_SHTL_INIT_POSITION_QVAL  63490 /* (REAL) Parameter identification: Quality of the initial shuttle position */
#define ACP10PAR_UDC_MIDDLE_FILTER        63491 /* (REAL) DC-Bus: Filtered middle voltage [V] */
#define ACP10PAR_UDC_MIDDLE_ACT           63492 /* (REAL) DC-Bus: Middle voltage [V] */
#define ACP10PAR_SHTL_INIT_POSITION       63493 /* (REAL) Parameter identification: Initial shuttle position */
#define ACP10PAR_SHTL_INIT_POSITION_IDX   63494 /* (USINT) Parameter identification: Index of the initial shuttle position */
#define ACP10PAR_ISC_STATE                63495 /* (UDINT) Inter-segment communication: State */
#define ACP10PAR_ISC_ERR_TOLERANCE        63496 /* (USINT) Inter-segment communication: Fault tolerance */
#define ACP10PAR_PHASE_IS_ACT_1           63501 /* (REAL) CTRL Current controller: Actual phase current of phase 1 [A] */
#define ACP10PAR_PHASE_IS_ACT_2           63502 /* (REAL) CTRL Current controller: Actual phase current of phase 2 [A] */
#define ACP10PAR_PHASE_IS_ACT_3           63503 /* (REAL) CTRL Current controller: Actual phase current of phase 3 [A] */
#define ACP10PAR_PHASE_IS_ACT_4           63504 /* (REAL) CTRL Current controller: Actual phase current of phase 4 [A] */
#define ACP10PAR_PHASE_IS_ACT_5           63505 /* (REAL) CTRL Current controller: Actual phase current of phase 5 [A] */
#define ACP10PAR_PHASE_IS_ACT_6           63506 /* (REAL) CTRL Current controller: Actual phase current of phase 6 [A] */
#define ACP10PAR_PHASE_IS_ACT_7           63507 /* (REAL) CTRL Current controller: Actual phase current of phase 7 [A] */
#define ACP10PAR_PHASE_IS_ACT_8           63508 /* (REAL) CTRL Current controller: Actual phase current of phase 8 [A] */
#define ACP10PAR_PHASE_IS_ACT_9           63509 /* (REAL) CTRL Current controller: Actual phase current of phase 9 [A] */
#define ACP10PAR_PHASE_IS_ACT_10          63510 /* (REAL) CTRL Current controller: Actual phase current of phase 10 [A] */
#define ACP10PAR_PHASE_IS_ACT_11          63511 /* (REAL) CTRL Current controller: Actual phase current of phase 11 [A] */
#define ACP10PAR_PHASE_IS_ACT_12          63512 /* (REAL) CTRL Current controller: Actual phase current of phase 12 [A] */
#define ACP10PAR_PHASE_IS_ACT_13          63513 /* (REAL) CTRL Current controller: Actual phase current of phase 13 [A] */
#define ACP10PAR_PHASE_IS_ACT_14          63514 /* (REAL) CTRL Current controller: Actual phase current of phase 14 [A] */
#define ACP10PAR_PHASE_IS_ACT_15          63515 /* (REAL) CTRL Current controller: Actual phase current of phase 15 [A] */
#define ACP10PAR_PHASE_IS_ACT_16          63516 /* (REAL) CTRL Current controller: Actual phase current of phase 16 [A] */
#define ACP10PAR_PHASE_IS_ACT_17          63517 /* (REAL) CTRL Current controller: Actual phase current of phase 17 [A] */
#define ACP10PAR_PHASE_IS_ACT_18          63518 /* (REAL) CTRL Current controller: Actual phase current of phase 18 [A] */
#define ACP10PAR_PHASE_IS_ACT_19          63519 /* (REAL) CTRL Current controller: Actual phase current of phase 19 [A] */
#define ACP10PAR_PHASE_IS_ACT_20          63520 /* (REAL) CTRL Current controller: Actual phase current of phase 20 [A] */
#define ACP10PAR_PHASE_IS_ACT_21          63521 /* (REAL) CTRL Current controller: Actual phase current of phase 21 [A] */
#define ACP10PAR_PHASE_IS_ACT_22          63522 /* (REAL) CTRL Current controller: Actual phase current of phase 22 [A] */
#define ACP10PAR_PHASE_IS_ACT_23          63523 /* (REAL) CTRL Current controller: Actual phase current of phase 23 [A] */
#define ACP10PAR_PHASE_IS_ACT_24          63524 /* (REAL) CTRL Current controller: Actual phase current of phase 24 [A] */
#define ACP10PAR_PHASE_IS_ACT_25          63525 /* (REAL) CTRL Current controller: Actual phase current of phase 25 [A] */
#define ACP10PAR_PHASE_IS_ACT_26          63526 /* (REAL) CTRL Current controller: Actual phase current of phase 26 [A] */
#define ACP10PAR_PHASE_IS_ACT_27          63527 /* (REAL) CTRL Current controller: Actual phase current of phase 27 [A] */
#define ACP10PAR_PHASE_IS_ACT_28          63528 /* (REAL) CTRL Current controller: Actual phase current of phase 28 [A] */
#define ACP10PAR_PHASE_IS_ACT_29          63529 /* (REAL) CTRL Current controller: Actual phase current of phase 29 [A] */
#define ACP10PAR_PHASE_IS_ACT_30          63530 /* (REAL) CTRL Current controller: Actual phase current of phase 30 [A] */
#define ACP10PAR_PHASE_IS_ACT_31          63531 /* (REAL) CTRL Current controller: Actual phase current of phase 31 [A] */
#define ACP10PAR_PHASE_IS_ACT_32          63532 /* (REAL) CTRL Current controller: Actual phase current of phase 32 [A] */
#define ACP10PAR_PHASE_IS_ACT_33          63533 /* (REAL) CTRL Current controller: Actual phase current of phase 33 [A] */
#define ACP10PAR_PHASE_IS_ACT_34          63534 /* (REAL) CTRL Current controller: Actual phase current of phase 34 [A] */
#define ACP10PAR_PHASE_IS_ACT_35          63535 /* (REAL) CTRL Current controller: Actual phase current of phase 35 [A] */
#define ACP10PAR_PHASE_IS_ACT_36          63536 /* (REAL) CTRL Current controller: Actual phase current of phase 36 [A] */
#define ACP10PAR_PHASE_IS_ACT_37          63537 /* (REAL) CTRL Current controller: Actual phase current of phase 37 [A] */
#define ACP10PAR_PHASE_IS_ACT_38          63538 /* (REAL) CTRL Current controller: Actual phase current of phase 38 [A] */
#define ACP10PAR_PHASE_IS_ACT_39          63539 /* (REAL) CTRL Current controller: Actual phase current of phase 39 [A] */
#define ACP10PAR_PHASE_IS_ACT_40          63540 /* (REAL) CTRL Current controller: Actual phase current of phase 40 [A] */
#define ACP10PAR_PHASE_IS_ACT_41          63541 /* (REAL) CTRL Current controller: Actual phase current of phase 41 [A] */
#define ACP10PAR_PHASE_IS_ACT_42          63542 /* (REAL) CTRL Current controller: Actual phase current of phase 42 [A] */
#define ACP10PAR_PHASE_IS_ACT_43          63543 /* (REAL) CTRL Current controller: Actual phase current of phase 43 [A] */
#define ACP10PAR_PHASE_IS_ACT_44          63544 /* (REAL) CTRL Current controller: Actual phase current of phase 44 [A] */
#define ACP10PAR_PHASE_IS_REF_1           63551 /* (REAL) CTRL Current controller: Set phase current of phase 1 [A] */
#define ACP10PAR_PHASE_IS_REF_2           63552 /* (REAL) CTRL Current controller: Set phase current of phase 2 [A] */
#define ACP10PAR_PHASE_IS_REF_3           63553 /* (REAL) CTRL Current controller: Set phase current of phase 3 [A] */
#define ACP10PAR_PHASE_IS_REF_4           63554 /* (REAL) CTRL Current controller: Set phase current of phase 4 [A] */
#define ACP10PAR_PHASE_IS_REF_5           63555 /* (REAL) CTRL Current controller: Set phase current of phase 5 [A] */
#define ACP10PAR_PHASE_IS_REF_6           63556 /* (REAL) CTRL Current controller: Set phase current of phase 6 [A] */
#define ACP10PAR_PHASE_IS_REF_7           63557 /* (REAL) CTRL Current controller: Set phase current of phase 7 [A] */
#define ACP10PAR_PHASE_IS_REF_8           63558 /* (REAL) CTRL Current controller: Set phase current of phase 8 [A] */
#define ACP10PAR_PHASE_IS_REF_9           63559 /* (REAL) CTRL Current controller: Set phase current of phase 9 [A] */
#define ACP10PAR_PHASE_IS_REF_10          63560 /* (REAL) CTRL Current controller: Set phase current of phase 10 [A] */
#define ACP10PAR_PHASE_IS_REF_11          63561 /* (REAL) CTRL Current controller: Set phase current of phase 11 [A] */
#define ACP10PAR_PHASE_IS_REF_12          63562 /* (REAL) CTRL Current controller: Set phase current of phase 12 [A] */
#define ACP10PAR_PHASE_IS_REF_13          63563 /* (REAL) CTRL Current controller: Set phase current of phase 13 [A] */
#define ACP10PAR_PHASE_IS_REF_14          63564 /* (REAL) CTRL Current controller: Set phase current of phase 14 [A] */
#define ACP10PAR_PHASE_IS_REF_15          63565 /* (REAL) CTRL Current controller: Set phase current of phase 15 [A] */
#define ACP10PAR_PHASE_IS_REF_16          63566 /* (REAL) CTRL Current controller: Set phase current of phase 16 [A] */
#define ACP10PAR_PHASE_IS_REF_17          63567 /* (REAL) CTRL Current controller: Set phase current of phase 17 [A] */
#define ACP10PAR_PHASE_IS_REF_18          63568 /* (REAL) CTRL Current controller: Set phase current of phase 18 [A] */
#define ACP10PAR_PHASE_IS_REF_19          63569 /* (REAL) CTRL Current controller: Set phase current of phase 19 [A] */
#define ACP10PAR_PHASE_IS_REF_20          63570 /* (REAL) CTRL Current controller: Set phase current of phase 20 [A] */
#define ACP10PAR_PHASE_IS_REF_21          63571 /* (REAL) CTRL Current controller: Set phase current of phase 21 [A] */
#define ACP10PAR_PHASE_IS_REF_22          63572 /* (REAL) CTRL Current controller: Set phase current of phase 22 [A] */
#define ACP10PAR_PHASE_IS_REF_23          63573 /* (REAL) CTRL Current controller: Set phase current of phase 23 [A] */
#define ACP10PAR_PHASE_IS_REF_24          63574 /* (REAL) CTRL Current controller: Set phase current of phase 24 [A] */
#define ACP10PAR_PHASE_IS_REF_25          63575 /* (REAL) CTRL Current controller: Set phase current of phase 25 [A] */
#define ACP10PAR_PHASE_IS_REF_26          63576 /* (REAL) CTRL Current controller: Set phase current of phase 26 [A] */
#define ACP10PAR_PHASE_IS_REF_27          63577 /* (REAL) CTRL Current controller: Set phase current of phase 27 [A] */
#define ACP10PAR_PHASE_IS_REF_28          63578 /* (REAL) CTRL Current controller: Set phase current of phase 28 [A] */
#define ACP10PAR_PHASE_IS_REF_29          63579 /* (REAL) CTRL Current controller: Set phase current of phase 29 [A] */
#define ACP10PAR_PHASE_IS_REF_30          63580 /* (REAL) CTRL Current controller: Set phase current of phase 30 [A] */
#define ACP10PAR_PHASE_IS_REF_31          63581 /* (REAL) CTRL Current controller: Set phase current of phase 31 [A] */
#define ACP10PAR_PHASE_IS_REF_32          63582 /* (REAL) CTRL Current controller: Set phase current of phase 32 [A] */
#define ACP10PAR_PHASE_IS_REF_33          63583 /* (REAL) CTRL Current controller: Set phase current of phase 33 [A] */
#define ACP10PAR_PHASE_IS_REF_34          63584 /* (REAL) CTRL Current controller: Set phase current of phase 34 [A] */
#define ACP10PAR_PHASE_IS_REF_35          63585 /* (REAL) CTRL Current controller: Set phase current of phase 35 [A] */
#define ACP10PAR_PHASE_IS_REF_36          63586 /* (REAL) CTRL Current controller: Set phase current of phase 36 [A] */
#define ACP10PAR_PHASE_IS_REF_37          63587 /* (REAL) CTRL Current controller: Set phase current of phase 37 [A] */
#define ACP10PAR_PHASE_IS_REF_38          63588 /* (REAL) CTRL Current controller: Set phase current of phase 38 [A] */
#define ACP10PAR_PHASE_IS_REF_39          63589 /* (REAL) CTRL Current controller: Set phase current of phase 39 [A] */
#define ACP10PAR_PHASE_IS_REF_40          63590 /* (REAL) CTRL Current controller: Set phase current of phase 40 [A] */
#define ACP10PAR_PHASE_IS_REF_41          63591 /* (REAL) CTRL Current controller: Set phase current of phase 41 [A] */
#define ACP10PAR_PHASE_IS_REF_42          63592 /* (REAL) CTRL Current controller: Set phase current of phase 42 [A] */
#define ACP10PAR_PHASE_IS_REF_43          63593 /* (REAL) CTRL Current controller: Set phase current of phase 43 [A] */
#define ACP10PAR_PHASE_IS_REF_44          63594 /* (REAL) CTRL Current controller: Set phase current of phase 44 [A] */
#define ACP10PAR_PHASE_US_REF_1           63601 /* (REAL) CTRL Current controller: Set phase voltage of phase 1 [V] */
#define ACP10PAR_PHASE_US_REF_2           63602 /* (REAL) CTRL Current controller: Set phase voltage of phase 2 [V] */
#define ACP10PAR_PHASE_US_REF_3           63603 /* (REAL) CTRL Current controller: Set phase voltage of phase 3 [V] */
#define ACP10PAR_PHASE_US_REF_4           63604 /* (REAL) CTRL Current controller: Set phase voltage of phase 4 [V] */
#define ACP10PAR_PHASE_US_REF_5           63605 /* (REAL) CTRL Current controller: Set phase voltage of phase 5 [V] */
#define ACP10PAR_PHASE_US_REF_6           63606 /* (REAL) CTRL Current controller: Set phase voltage of phase 6 [V] */
#define ACP10PAR_PHASE_US_REF_7           63607 /* (REAL) CTRL Current controller: Set phase voltage of phase 7 [V] */
#define ACP10PAR_PHASE_US_REF_8           63608 /* (REAL) CTRL Current controller: Set phase voltage of phase 8 [V] */
#define ACP10PAR_PHASE_US_REF_9           63609 /* (REAL) CTRL Current controller: Set phase voltage of phase 9 [V] */
#define ACP10PAR_PHASE_US_REF_10          63610 /* (REAL) CTRL Current controller: Set phase voltage of phase 10 [V] */
#define ACP10PAR_PHASE_US_REF_11          63611 /* (REAL) CTRL Current controller: Set phase voltage of phase 11 [V] */
#define ACP10PAR_PHASE_US_REF_12          63612 /* (REAL) CTRL Current controller: Set phase voltage of phase 12 [V] */
#define ACP10PAR_PHASE_US_REF_13          63613 /* (REAL) CTRL Current controller: Set phase voltage of phase 13 [V] */
#define ACP10PAR_PHASE_US_REF_14          63614 /* (REAL) CTRL Current controller: Set phase voltage of phase 14 [V] */
#define ACP10PAR_PHASE_US_REF_15          63615 /* (REAL) CTRL Current controller: Set phase voltage of phase 15 [V] */
#define ACP10PAR_PHASE_US_REF_16          63616 /* (REAL) CTRL Current controller: Set phase voltage of phase 16 [V] */
#define ACP10PAR_PHASE_US_REF_17          63617 /* (REAL) CTRL Current controller: Set phase voltage of phase 17 [V] */
#define ACP10PAR_PHASE_US_REF_18          63618 /* (REAL) CTRL Current controller: Set phase voltage of phase 18 [V] */
#define ACP10PAR_PHASE_US_REF_19          63619 /* (REAL) CTRL Current controller: Set phase voltage of phase 19 [V] */
#define ACP10PAR_PHASE_US_REF_20          63620 /* (REAL) CTRL Current controller: Set phase voltage of phase 20 [V] */
#define ACP10PAR_PHASE_US_REF_21          63621 /* (REAL) CTRL Current controller: Set phase voltage of phase 21 [V] */
#define ACP10PAR_PHASE_US_REF_22          63622 /* (REAL) CTRL Current controller: Set phase voltage of phase 22 [V] */
#define ACP10PAR_PHASE_US_REF_23          63623 /* (REAL) CTRL Current controller: Set phase voltage of phase 23 [V] */
#define ACP10PAR_PHASE_US_REF_24          63624 /* (REAL) CTRL Current controller: Set phase voltage of phase 24 [V] */
#define ACP10PAR_PHASE_US_REF_25          63625 /* (REAL) CTRL Current controller: Set phase voltage of phase 25 [V] */
#define ACP10PAR_PHASE_US_REF_26          63626 /* (REAL) CTRL Current controller: Set phase voltage of phase 26 [V] */
#define ACP10PAR_PHASE_US_REF_27          63627 /* (REAL) CTRL Current controller: Set phase voltage of phase 27 [V] */
#define ACP10PAR_PHASE_US_REF_28          63628 /* (REAL) CTRL Current controller: Set phase voltage of phase 28 [V] */
#define ACP10PAR_PHASE_US_REF_29          63629 /* (REAL) CTRL Current controller: Set phase voltage of phase 29 [V] */
#define ACP10PAR_PHASE_US_REF_30          63630 /* (REAL) CTRL Current controller: Set phase voltage of phase 30 [V] */
#define ACP10PAR_PHASE_US_REF_31          63631 /* (REAL) CTRL Current controller: Set phase voltage of phase 31 [V] */
#define ACP10PAR_PHASE_US_REF_32          63632 /* (REAL) CTRL Current controller: Set phase voltage of phase 32 [V] */
#define ACP10PAR_PHASE_US_REF_33          63633 /* (REAL) CTRL Current controller: Set phase voltage of phase 33 [V] */
#define ACP10PAR_PHASE_US_REF_34          63634 /* (REAL) CTRL Current controller: Set phase voltage of phase 34 [V] */
#define ACP10PAR_PHASE_US_REF_35          63635 /* (REAL) CTRL Current controller: Set phase voltage of phase 35 [V] */
#define ACP10PAR_PHASE_US_REF_36          63636 /* (REAL) CTRL Current controller: Set phase voltage of phase 36 [V] */
#define ACP10PAR_PHASE_US_REF_37          63637 /* (REAL) CTRL Current controller: Set phase voltage of phase 37 [V] */
#define ACP10PAR_PHASE_US_REF_38          63638 /* (REAL) CTRL Current controller: Set phase voltage of phase 38 [V] */
#define ACP10PAR_PHASE_US_REF_39          63639 /* (REAL) CTRL Current controller: Set phase voltage of phase 39 [V] */
#define ACP10PAR_PHASE_US_REF_40          63640 /* (REAL) CTRL Current controller: Set phase voltage of phase 40 [V] */
#define ACP10PAR_PHASE_US_REF_41          63641 /* (REAL) CTRL Current controller: Set phase voltage of phase 41 [V] */
#define ACP10PAR_PHASE_US_REF_42          63642 /* (REAL) CTRL Current controller: Set phase voltage of phase 42 [V] */
#define ACP10PAR_PHASE_US_REF_43          63643 /* (REAL) CTRL Current controller: Set phase voltage of phase 43 [V] */
#define ACP10PAR_PHASE_US_REF_44          63644 /* (REAL) CTRL Current controller: Set phase voltage of phase 44 [V] */
#define ACP10PAR_TEMP_POWERSTAGE_SENS3    63645 /* (REAL) Temperature sensor: Temperature 3 [°C] */
#define ACP10PAR_TEMP_POWERSTAGE_SENS4    63646 /* (REAL) Temperature sensor: Temperature 4 [°C] */
#define ACP10PAR_TEMP_POWERSTAGE_AIR      63647 /* (REAL) Temperature sensor: Powerstage air [°C] */
#define ACP10PAR_TEMP_POWERSTAGE_BAL      63648 /* (REAL) Temperature sensor: Powerstage balancer [°C] */
#define ACP10PAR_LLM_SCTRL_SPEED_REF      63665 /* (REAL) CTRL Speed controller: Shuttle set speed [m/s] */
#define ACP10PAR_LLM_SCTRL_SPEED_ACT      63666 /* (REAL) CTRL Speed controller: Shuttle actual speed [m/s] */
#define ACP10PAR_LLM_SCTRL_KV             63667 /* (REAL) CTRL Speed controller: Proportional amplification [As/m] */
#define ACP10PAR_LLM_SCTRL_TN             63668 /* (REAL) CTRL Speed controller: Integral action time [s] */
#define ACP10PAR_LLM_SCTRL_SPEED_REF_SUM  63669 /* (REAL) CTRL Speed controller: Sum of the set speeds [m/s] */
#define ACP10PAR_LLM_SCTRL_SPEED_ERROR    63670 /* (REAL) CTRL Speed controller: Speed error [m/s] */
#define ACP10PAR_LLM_SCTRL_THR_FORCE_REF  63671 /* (REAL) CTRL Speed controller: Reference value of thrust force [N] */
#define ACP10PAR_TEMP_POWERSTAGE_SENS5    63673 /* (REAL) Temperature sensor: Temperature 5 [°C] */
#define ACP10PAR_TEMP_POWERSTAGE_SENS6    63674 /* (REAL) Temperature sensor: Temperature 6 [°C] */
#define ACP10PAR_TEMP_POWERSTAGE_SENS7    63675 /* (REAL) Temperature sensor: Temperature 7 [°C] */
#define ACP10PAR_TEMP_POWERSTAGE_SENS8    63676 /* (REAL) Temperature sensor: Temperature 8 [°C] */
#define ACP10PAR_TEMP_POWERSTAGE_SENS9    63677 /* (REAL) Temperature sensor: Temperature 9 [°C] */
#define ACP10PAR_TEMP_POWERSTAGE_SENS10   63678 /* (REAL) Temperature sensor: Temperature 10 [°C] */
#define ACP10PAR_TEMP_POWERSTAGE_SENS11   63679 /* (REAL) Temperature sensor: Temperature 11 [°C] */
#define ACP10PAR_TEMP_MOTOR_MUX_IDX       63680 /* (USINT) Motor: Temperature sensor: MUX-index (0-based) */
#define ACP10PAR_TEMP_MOTOR_MUX           63681 /* (REAL) Motor: Temperature sensor: MUX temperature [°C] */
#define ACP10PAR_FCTRL_ISD_SWITCH         63682 /* (REAL) CTRL Flux controller: Reference value of switch release current [A] */
#define ACP10PAR_MOT_TEMPMODEL_TEMP       63690 /* (REAL) Motor: Temperature model: Temperature [°C] */
#define ACP10PAR_MOT_TEMPMODEL_TEMP_ERR   63691 /* (REAL) Motor: Temperature model: Stop limit [°C] */
#define ACP10PAR_MOT_TEMPMODEL_TEMP_WRN   63692 /* (REAL) Motor: Temperature model: warning limit [°C] */
#define ACP10PAR_MOT_TEMPMODEL_COIL_IDX   63693 /* (USINT) Motor: Temperature model: Coil index (0-based) */
#define ACP10PAR_MOT_TEMPMODEL_COIL_TEMP  63694 /* (REAL) Motor: Temperature model: Coil temperature [°C] */
#define ACP10PAR_PHASE_IS_ACT_SUM         63806 /* (REAL) CTRL Current controller: Sum of actual phase currents [A] */
#define ACP10PAR_LLM_PAR_CONF_IDX         63879 /* (USINT) CTRL Controller: Configuration: Index of parameter record */
#define ACP10PAR_LLM_PCTRL_S_ACT          63880 /* (LREAL) CTRL Position controller: Actual position of shuttle on segment [m] */
#define ACP10PAR_LLM_CYC_SET_VALUE        63882 /* (LREAL) CTRL Controller: Cyclic set position of the shuttle  [m] */
#define ACP10PAR_LLM_PCTRL_S_SET          63883 /* (LREAL) CTRL Position controller: Set position of shuttle on segment [m] */
#define ACP10PAR_LLM_SET_CYCLE_TIME       63884 /* (UDINT) CTRL Position controller: Network: Cycle time of set values [us] */
#define ACP10PAR_LLM_CYC_CH_STATUS_BITS   63885 /* (USINT) CTRL Controller: Cyclic channel status bits */
#define ACP10PAR_LLM_CYC_SEG_CTRL_BITS    63886 /* (USINT) CTRL Controller: Cyclic segment control bits */
#define ACP10PAR_LLM_CYC_CH_CTRL_BITS     63887 /* (UINT) CTRL Controller: Cyclic channel control bits */
#define ACP10PAR_LLM_CYC_SEG_STATUS_BITS  63888 /* (UDINT) CTRL Controller: Cyclic segment status bits */
#define ACP10PAR_SERVO_V_MAX_OUTPUT       64201 /* (REAL) Servo drive adjustment: Velocity at maximum output value [Units/s] */
#define ACP10PAR_ENCOD_POS_RANGE          64225 /* (UDINT) Encoder1: Range of encoder position [Incr] */
#define ACP10PAR_SM_SCALE_STEP            64232 /* (UDINT) Stepper motor: Step scaling: Steps per motor revolution */
#define ACP10PAR_SM_SCALE_LOAD_UNITS      64233 /* (UDINT) Stepper motor: Load scaling: Units per SM_SCALE_LOAD_MOTREV motor revolutions [Units] */
#define ACP10PAR_SM_SCALE_LOAD_MOTREV     64234 /* (UDINT) Stepper motor: Load scaling: Motor revolutions */
#define ACP10PAR_ENCOD2_POS_RANGE         64237 /* (UDINT) Encoder2: Range of encoder position [Incr] */
#define ACP10PAR_ERROR_RESPONSE           65535 /* (ERROR_NUMBER, ERROR_INFO) Messages: Error response */

#endif /* ACP10PAR_H_ */ 
