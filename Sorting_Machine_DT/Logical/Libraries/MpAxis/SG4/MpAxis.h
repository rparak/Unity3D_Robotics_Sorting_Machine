/* Automation Studio generated header file */
/* Do not edit ! */
/* MpAxis 1.75.0 */

#ifndef _MPAXIS_
#define _MPAXIS_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _MpAxis_VERSION
#define _MpAxis_VERSION 1.75.0
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG4
		#include "NcGlobal.h"
		#include "MpBase.h"
		#include "MpCom.h"
		#include "Acp10_MC.h"
#endif

#ifdef _SG3
		#include "NcGlobal.h"
		#include "MpBase.h"
		#include "MpCom.h"
		#include "Acp10_MC.h"
#endif

#ifdef _SGC
		#include "NcGlobal.h"
		#include "MpBase.h"
		#include "MpCom.h"
		#include "Acp10_MC.h"
#endif

/* Datatypes and datatypes of function blocks */
typedef enum MpAxisAutotuneModeEnum
{	mpAXIS_TUNE_AUTOMATIC = 0,
	mpAXIS_TUNE_SPEED = 2,
	mpAXIS_TUNE_POSITION = 1,
	mpAXIS_TUNE_TEST = 31,
	mpAXIS_TUNE_SPEED_ISQ_F1 = 130,
	mpAXIS_TUNE_SPEED_T_FLTR = 66,
	mpAXIS_TUNE_SPEED_T_FLTR_ISQ_F1 = 194,
	mpAXIS_TUNE_SPEED_FLTR = 6,
	mpAXIS_TUNE_ISQ_F1 = 128,
	mpAXIS_TUNE_ISQ_F1_F2 = 384,
	mpAXIS_TUNE_ISQ_F1_F2_F3 = 896,
	mpAXIS_TUNE_FF = 32,
	mpAXIS_TUNE_FF_ONLY_POS = 33,
	mpAXIS_TUNE_FF_ONLY_NEG = 34
} MpAxisAutotuneModeEnum;

typedef enum MpAxisFeedForwardModeEnum
{	mpAXIS_FF_DISABLED = 0,
	mpAXIS_FF_BOTH = 1,
	mpAXIS_FF_ONLY_POS = 2,
	mpAXIS_FF_ONLY_NEG = 3
} MpAxisFeedForwardModeEnum;

typedef enum MpAxisMoveDirectionEnum
{	mpAXIS_DIR_POSITIVE = 0,
	mpAXIS_DIR_NEGATIVE = 1,
	mpAXIS_DIR_CURRENT = 2,
	mpAXIS_DIR_SHORTEST_WAY = 3,
	mpAXIS_DIR_EXCEED_PERIOD = 8
} MpAxisMoveDirectionEnum;

typedef enum MpAxisHomeModeEnum
{	mpAXIS_HOME_MODE_DEFAULT = 0,
	mpAXIS_HOME_MODE_ABS_SWITCH = 2,
	mpAXIS_HOME_MODE_SWITCH_GATE = 8,
	mpAXIS_HOME_MODE_LIMIT_SWITCH = 3,
	mpAXIS_HOME_MODE_REF_PULSE = 5,
	mpAXIS_HOME_MODE_DIRECT = 1,
	mpAXIS_HOME_MODE_ABSOLUTE = 4,
	mpAXIS_HOME_MODE_ABSOLUTE_CORR = 6,
	mpAXIS_HOME_MODE_DCM = 9,
	mpAXIS_HOME_MODE_DCM_CORR = 10,
	mpAXIS_HOME_MODE_RESTORE_POS = 11,
	mpAXIS_HOME_MODE_AXIS_REF = 12,
	mpAXIS_HOME_MODE_BLOCK_TORQUE = 13,
	mpAXIS_HOME_MODE_BLOCK_DS = 14
} MpAxisHomeModeEnum;

typedef enum MpAxisHomeOptionEnum
{	mpAXIS_HOME_OPTION_OFF = 0,
	mpAXIS_HOME_OPTION_ON = 1
} MpAxisHomeOptionEnum;

typedef enum MpAxisHomeMoveDirectionEnum
{	mpAXIS_HOME_DIR_POSITIVE = 0,
	mpAXIS_HOME_DIR_NEGATIVE = 1
} MpAxisHomeMoveDirectionEnum;

typedef enum MpAxisTriggerSourceEnum
{	mpAXIS_TRIGGER1 = 20,
	mpAXIS_TRIGGER2 = 22
} MpAxisTriggerSourceEnum;

typedef enum MpAxisInputSourceEnum
{	mpAXIS_INPUT_NONE = 0,
	mpAXIS_INPUT_TRIGGER1 = 1,
	mpAXIS_INPUT_TRIGGER2 = 2,
	mpAXIS_INPUT_POS_LIMIT_SWITCH = 3,
	mpAXIS_INPUT_NEG_LIMIT_SWITCH = 4,
	mpAXIS_INPUT_HOMING_SWITCH = 5
} MpAxisInputSourceEnum;

typedef enum MpAxisTriggerEdgeEnum
{	mpAXIS_TRIGGER_EDGE_POS = 0,
	mpAXIS_TRIGGER_EDGE_NEG = 1
} MpAxisTriggerEdgeEnum;

typedef enum MpAxisReadInfoModeEnum
{	mpAXIS_READ_OFF = 0,
	mpAXIS_READ_CYCLIC = 1,
	mpAXIS_READ_MULTIPLEXED = 2,
	mpAXIS_READ_POLLING_1s = 3,
	mpAXIS_READ_POLLING_5s = 4
} MpAxisReadInfoModeEnum;

typedef enum MpAxisBootPhaseEnum
{	mpAXIS_BLP_NETWORK_INACTIVE = 0,
	mpAXIS_BLP_NETWORK_INIT_STARTED = 1,
	mpAXIS_BLP_WAIT_INIT_HIGH_PRIO = 5,
	mpAXIS_BLP_HW_WAIT = 9,
	mpAXIS_BLP_HW_LINKED = 10,
	mpAXIS_BLP_HW_START = 20,
	mpAXIS_BLP_HW_UPDATE = 30,
	mpAXIS_BLP_HW_UPDATE_OTHER_DRV = 31,
	mpAXIS_BLP_FW_UPDATE = 40,
	mpAXIS_BLP_FW_UPDATE_OTHER_DRV = 41,
	mpAXIS_BLP_FW_START = 50,
	mpAXIS_BLP_WAIT_INIT_LOW_PRIO = 55,
	mpAXIS_BLP_DOWNLOAD_DEF_PARAMS = 60,
	mpAXIS_BLP_DOWNLOAD_INI_PARAMS = 70,
	mpAXIS_BLP_HW_INFO_FROM_DRIVE = 80,
	mpAXIS_BLP_DONE = 90
} MpAxisBootPhaseEnum;

typedef enum MpAxisPlcOpenStateEnum
{	mpAXIS_DISABLED = 0,
	mpAXIS_STANDSTILL = 1,
	mpAXIS_ERRORSTOP = 10,
	mpAXIS_STOPPING = 9,
	mpAXIS_DISCRETE_MOTION = 2,
	mpAXIS_CONTINUOUS_MOTION = 3,
	mpAXIS_SYNCHRONIZED_MOTION = 4,
	mpAXIS_HOMING = 5
} MpAxisPlcOpenStateEnum;

typedef enum MpAxisExecutingCmdEnum
{	mpAXIS_CMD_IDLE = 0,
	mpAXIS_CMD_INIT = 1,
	mpAXIS_CMD_HOMING = 2,
	mpAXIS_CMD_STOP = 3,
	mpAXIS_CMD_HALT = 4,
	mpAXIS_CMD_MOVE_VELOCITY = 5,
	mpAXIS_CMD_MOVE_ABSOLUTE = 6,
	mpAXIS_CMD_GEAR_IN = 7,
	mpAXIS_CMD_GEAR_OUT = 8,
	mpAXIS_CMD_CAM_IN = 9,
	mpAXIS_CMD_CAM_OUT = 10,
	mpAXIS_CMD_DOWNLOAD_CAMS = 11,
	mpAXIS_CMD_MOVE_ADDITIVE = 12,
	mpAXIS_CMD_JOG_POSITIVE = 13,
	mpAXIS_CMD_JOG_NEGATIVE = 14,
	mpAXIS_CMD_STOP_PHASED = 15,
	mpAXIS_CMD_AUTOTUNE = 16,
	mpAXIS_CMD_REMOTE_CONTROL = 17,
	mpAXIS_CMD_MOVE_VEL_TRG_STOP = 18,
	mpAXIS_CMD_MOVE_ABS_TRG_STOP = 19,
	mpAXIS_CMD_MOVE_ADD_TRG_STOP = 20,
	mpAXIS_CMD_CAM_SEQUENCER = 50,
	mpAXIS_COUPLING_IDLE = 100,
	mpAXIS_CMD_PHASING = 101,
	mpAXIS_CMD_OFFSET = 102,
	mpAXIS_CMD_ABORT = 103,
	mpAXIS_CMD_UPDATE_GEAR = 104,
	mpAXIS_CMD_UPDATE_CAM = 105,
	mpAXIS_CMD_RECOVERY = 106,
	mpAXIS_CYCLIC_REF_IDLE = 200,
	mpAXIS_CMD_CYC_POSITION = 201,
	mpAXIS_CMD_CYC_VELOCITY = 202,
	mpAXIS_CMD_CYC_TORQUE = 203,
	mpAXIS_CMD_CYC_POSITION_UPDATE = 204,
	mpAXIS_CMD_CYC_VELOCITY_UPDATE = 205,
	mpAXIS_CMD_CYC_TORQUE_UPDATE = 206
} MpAxisExecutingCmdEnum;

typedef enum MpAxisNetworkTypeEnum
{	mpAXIS_CAN_NETWORK = 0,
	mpAXIS_PLK_NETWORK = 1,
	mpAXIS_SDC_NETWORK = 129
} MpAxisNetworkTypeEnum;

typedef enum MpAxisDeviceTypeEnum
{	mpAXIS_DEVICE_UNKNOWN = 0,
	mpAXIS_ACOPOS = 1,
	mpAXIS_VIRTUAL = 3,
	mpAXIS_ACOPOSmulti65m = 4,
	mpAXIS_ACOPOSmulti = 5,
	mpAXIS_ACOPOSmulti_PPS = 6,
	mpAXIS_ACOPOSmulti_PS = 2,
	mpAXIS_ACOPOSmicro = 7,
	mpAXIS_ACOPOSmulti65 = 8,
	mpAXIS_ACOPOS_P3 = 12,
	mpAXIS_ACOPOS_SDC = 128,
	mpAXIS_ACOPOS_SIM = 129
} MpAxisDeviceTypeEnum;

typedef enum MpAxisBaseTypeEnum
{	mpAXIS_LIMITED_LINEAR = 0,
	mpAXIS_LIMITED_ROTARY = 1,
	mpAXIS_PERIODIC_LINEAR = 2,
	mpAXIS_PERIODIC_ROTARY = 3,
	mpAXIS_LINEAR = 4,
	mpAXIS_ROTARY = 5
} MpAxisBaseTypeEnum;

typedef enum MpAxisMeasurementUnitEnum
{	mpAXIS_UNIT_DEGREES = 0,
	mpAXIS_UNIT_MM = 1,
	mpAXIS_UNIT_GENERIC = 2,
	mpAXIS_UNIT_GENERIC_NOT_SCALED = 3
} MpAxisMeasurementUnitEnum;

typedef enum MpAxisVelocityLimitModeEnum
{	mpAXIS_VEL_MODE_OFF = 0,
	mpAXIS_VEL_MODE_STOP_INIT = 1,
	mpAXIS_VEL_MODE_STOP_AUTO1 = 2,
	mpAXIS_VEL_MODE_STOP_AUTO2 = 3
} MpAxisVelocityLimitModeEnum;

typedef enum MpAxisControllerModeEnum
{	mpAXIS_CTRL_MODE_POSITION = 1,
	mpAXIS_CTRL_MODE_POSITION_FF = 33,
	mpAXIS_CTRL_MODE_UF = 7
} MpAxisControllerModeEnum;

typedef enum MpAxisControllerUFTypeEnum
{	mpAXIS_CTRL_UF_LINEAR = 1,
	mpAXIS_CTRL_UF_QUADRATIC = 2,
	mpAXIS_CTRL_UF_LINEAR2 = 3
} MpAxisControllerUFTypeEnum;

typedef enum MpAxisControllerUFAutoConfigEnum
{	mpAXIS_UF_CONFIG_OFF = 0,
	mpAXIS_UF_CONFIG_MOT_PAR = 1
} MpAxisControllerUFAutoConfigEnum;

typedef enum MpAxisControllerFilterTypeEnum
{	mpAXIS_LOOP_FILTER_NO_TRANSFERED = 0,
	mpAXIS_LOOP_FILTER_OFF = 1,
	mpAXIS_LOOP_FILTER_LOW_PASS = 2,
	mpAXIS_LOOP_FILTER_NOTCH = 3,
	mpAXIS_LOOP_FILTER_ZTRANSFER_FUN = 4,
	mpAXIS_LOOP_FILTER_COMPENSATION = 5,
	mpAXIS_LOOP_FILTER_BIQUADRATIC = 6,
	mpAXIS_LOOP_FILTER_LIMITER = 7,
	mpAXIS_LOOP_FILTER_LIMITER_LIN = 8,
	mpAXIS_LOOP_FILTER_LIMITER_RTIME = 9
} MpAxisControllerFilterTypeEnum;

typedef enum MpAxisLevelIOEnum
{	mpAXIS_IO_ACTIVE_LO = 0,
	mpAXIS_IO_ACTIVE_HI = 1,
	mpAXIS_IO_ACTIVE_LO_EXTERNAL = 288,
	mpAXIS_IO_ACTIVE_HI_EXTERNAL = 289
} MpAxisLevelIOEnum;

typedef enum MpAxisQuickStopEnum
{	mpAXIS_QUICK_STOP_DEC_LIMIT = 20,
	mpAXIS_QUICK_STOP_TORQUE_LIMIT = 30,
	mpAXIS_QUICK_STOP_INDUCTION = 40
} MpAxisQuickStopEnum;

typedef enum MpAxisErrorStopEnum
{	mpAXIS_ERROR_STOP_DEC_LIMIT = 20,
	mpAXIS_ERROR_STOP_INDUCTION = 40,
	mpAXIS_ERROR_STOP_CONTROL_OFF = 50
} MpAxisErrorStopEnum;

typedef enum MpAxisMotorDirectionEnum
{	mpAXIS_DIR_CLOCKWISE = 0,
	mpAXIS_DIR_COUNTERCLOCKWISE = 255
} MpAxisMotorDirectionEnum;

typedef enum MpAxisPosVelOutputTypeEnum
{	mpAXIS_OUTPUT_SET = 0,
	mpAXIS_OUTPUT_ACTUAL = 1
} MpAxisPosVelOutputTypeEnum;

typedef enum MpAxisShiftModeEnum
{	mpAXIS_SHIFT_MODE_ABS = 0,
	mpAXIS_SHIFT_MODE_REL = 1,
	mpAXIS_SHIFT_MODE_ABS_NO_RESET = 2,
	mpAXIS_SHIFT_MODE_REL_NO_RESET = 3
} MpAxisShiftModeEnum;

typedef enum MpAxisApplyModeEnum
{	mpAXIS_SHIFT_TIME_BASE = 1,
	mpAXIS_SHIFT_MSTR_POS_BASE = 2,
	mpAXIS_SHIFT_MSTR_DIST_BASE = 3,
	mpAXIS_SHIFT_VEL_CTRL = 4,
	mpAXIS_OFFS_TIME_MSTR = 257,
	mpAXIS_OFFS_MSTR_POS_BASE_MSTR = 258,
	mpAXIS_OFFS_MSTR_DIS_BASE_MSTR = 259,
	mpAXIS_OFFS_VEL_CTRL_MSTR = 260
} MpAxisApplyModeEnum;

typedef enum MpAxisProfileBasisEnum
{	mpAXIS_PROFILE_BASIS_SLAVE = 0,
	mpAXIS_PROFILE_BASIS_MASTER = 256
} MpAxisProfileBasisEnum;

typedef enum MpAxisRecoveryModeEnum
{	mpAXIS_RECOVERY_FORWARD = 0,
	mpAXIS_RECOVERY_BACKWARD = 2,
	mpAXIS_RECOVERY_SHORTEST_WAY = 3,
	mpAXIS_RECOVERY_FORWARD_WINDOW = 100,
	mpAXIS_RECOVERY_BACKWARD_WINDOW = 101,
	mpAXIS_RECOVERY_GET_POSITION = 102
} MpAxisRecoveryModeEnum;

typedef enum MpAxisTorqueModeEnum
{	mpAXIS_TORQUE_MODE_FF = 32,
	mpAXIS_TORQUE_MODE_LIMIT = 40,
	mpAXIS_TORQUE_MODE_RAMPED_CTRL = 48
} MpAxisTorqueModeEnum;

typedef enum MpAxisErrorEnum
{	mpAXIS_NO_ERROR = 0,
	mpAXIS_ERR_ACTIVATION = -1064239103,
	mpAXIS_ERR_MPLINK_NULL = -1064239102,
	mpAXIS_ERR_MPLINK_INVALID = -1064239101,
	mpAXIS_ERR_MPLINK_CHANGED = -1064239100,
	mpAXIS_ERR_MPLINK_CORRUPT = -1064239099,
	mpAXIS_ERR_MPLINK_IN_USE = -1064239098,
	mpAXIS_ERR_PAR_NULL = -1064239097,
	mpAXIS_ERR_CONFIG_NULL = -1064239096,
	mpAXIS_ERR_CONFIG_NO_PV = -1064239095,
	mpAXIS_ERR_CONFIG_LOAD = -1064239094,
	mpAXIS_WRN_CONFIG_LOAD = -2137980917,
	mpAXIS_ERR_CONFIG_SAVE = -1064239092,
	mpAXIS_ERR_CONFIG_INVALID = -1064239091,
	mpAXIS_ERR_AXIS_HANDLE_NULL = -1064074752,
	mpAXIS_WRN_ERROR_TABLE_MISSING = -2137816575,
	mpAXIS_WRN_CFG_WAIT_ERROR_RESET = -2137816574,
	mpAXIS_WRN_CFG_WAIT_POWER_OFF = -2137816573,
	mpAXIS_WRN_CFG_WAIT_STANDSTILL = -2137816572,
	mpAXIS_ERR_PLC_OPEN = -1064074747,
	mpAXIS_WRN_PLC_OPEN = -2137816570,
	mpAXIS_WRN_READ_TORQUE_OFF = -2137816569,
	mpAXIS_ERR_MAX_TORQUE_REACHED = -1064074744,
	mpAXIS_ERR_SLAVE_NOT_FOUND = -1064074732,
	mpAXIS_ERR_MASTER_NOT_FOUND = -1064074731,
	mpAXIS_ERR_WRONG_DENOMINATOR = -1064074730,
	mpAXIS_ERR_WRONG_NUMERATOR = -1064074729,
	mpAXIS_ERR_NO_CAM_NAME = -1064074728,
	mpAXIS_WRN_SLAVE_NOT_READY = -2137816551,
	mpAXIS_ERR_CHECK_SLAVE_STATUS = -1064074726,
	mpAXIS_ERR_CMD_WRONG_AXISTYPE = -1064074725,
	mpAXIS_WRN_PARAMETER_LIMITED = -2137816548,
	mpAXIS_WRN_MULTIPLE_COMMAND = -2137816547,
	mpAXIS_ERR_CAM_PARAMETER = -1064074722,
	mpAXIS_ERR_RECOVERY_NOT_ALLOWED = -1064074721
} MpAxisErrorEnum;

typedef enum MpAxisBasicAlarmEnum
{	mpAXIS_ALM_GENERAL_DRIVE_ERROR = 0,
	mpAXIS_ALM_INITIALIZATION = 1,
	mpAXIS_ALM_PARAMETERS_INVALID = 2,
	mpAXIS_ALM_MOTOR_OVERTEMP = 3,
	mpAXIS_ALM_LAG_ERROR = 4,
	mpAXIS_ALM_LIMIT_SWITCH_REACHED = 5,
	mpAXIS_ALM_DRIVE_ENABLE_LOW = 6,
	mpAXIS_ALM_ENCODER = 7,
	mpAXIS_ALM_MAIN_VOLTAGE = 8,
	mpAXIS_ALM_SAFETY = 9,
	mpAXIS_ALM_HOLDING_BRAKE = 10,
	mpAXIS_ALM_NO_COMMUNICATION = 11,
	mpAXIS_ALM_DRIVE_OVERLOAD = 12,
	mpAXIS_ALM_MOTOR_OVERLOAD = 13,
	mpAXIS_ALM_GENERAL_WARNING = 14,
	mpAXIS_ALM_TORQUE_LIMIT_REACHED = 15
} MpAxisBasicAlarmEnum;

typedef struct MpAxisHomingType
{	enum MpAxisHomeModeEnum Mode;
	double Position;
	float StartVelocity;
	float HomingVelocity;
	double SensorOffset;
	float Acceleration;
	enum MpAxisHomeMoveDirectionEnum StartDirection;
	enum MpAxisHomeMoveDirectionEnum HomingDirection;
	enum MpAxisHomeOptionEnum NoDirectionChange;
	enum MpAxisHomeMoveDirectionEnum SwitchEdge;
	enum MpAxisHomeOptionEnum ReferencePulse;
	double ReferencePulseBlockingDistance;
	float TorqueLimit;
	double BlockDetectionPositionError;
	double PositionErrorStopLimit;
	unsigned long EndlessPositionDataRef;
} MpAxisHomingType;

typedef struct MpAxisJogType
{	float Acceleration;
	float Deceleration;
	float Velocity;
	double LowerLimit;
	double UpperLimit;
} MpAxisJogType;

typedef struct MpAxisStopType
{	float Deceleration;
	plcbit StopInPhase;
	double Phase;
} MpAxisStopType;

typedef struct MpAxisStopAfterTriggerType
{	plcbit Enable;
	double TriggerDistance;
	plcbit ForceTriggerDistance;
	enum MpAxisTriggerSourceEnum Source;
	enum MpAxisTriggerEdgeEnum Edge;
} MpAxisStopAfterTriggerType;

typedef struct MpAxisTorqueLimitType
{	float Limit;
	float Window;
} MpAxisTorqueLimitType;

typedef struct MpAxisCyclicReadSetupType
{	enum MpAxisReadInfoModeEnum TorqueMode;
	enum MpAxisReadInfoModeEnum LagErrorMode;
	enum MpAxisReadInfoModeEnum MotorTempMode;
	enum MpAxisReadInfoModeEnum UserChannelMode;
} MpAxisCyclicReadSetupType;

typedef struct MpAxisAutotuneType
{	enum MpAxisAutotuneModeEnum Mode;
	enum MpAxisFeedForwardModeEnum FeedForward;
	plcbit Vertical;
	float MaxCurrentPercent;
	float MaxSpeedPercent;
	double MaxDistance;
	float ProportionalAmplification;
} MpAxisAutotuneType;

typedef struct MpAxisBasicParType
{	float Acceleration;
	float Deceleration;
	float Velocity;
	double Position;
	double Distance;
	enum MpAxisMoveDirectionEnum Direction;
	struct MpAxisHomingType Home;
	struct MpAxisJogType Jog;
	struct MpAxisStopType Stop;
	struct MpAxisStopAfterTriggerType StopAfterTrigger;
	struct MpAxisTorqueLimitType Torque;
	struct MpAxisCyclicReadSetupType CyclicRead;
	struct MpAxisAutotuneType Autotune;
} MpAxisBasicParType;

typedef struct MpAxisCyclicReadValueType
{	plcbit Valid;
	double Value;
} MpAxisCyclicReadValueType;

typedef struct MpAxisCyclicReadType
{	struct MpAxisCyclicReadValueType Torque;
	struct MpAxisCyclicReadValueType LagError;
	struct MpAxisCyclicReadValueType MotorTemperature;
	struct MpAxisCyclicReadValueType UserChannelParameterID;
} MpAxisCyclicReadType;

typedef struct MpAxisDigitalIOStatusType
{	plcbit DriveEnable;
	plcbit HomeSwitch;
	plcbit PositiveLimitSwitch;
	plcbit NegativeLimitSwitch;
	plcbit Trigger1;
	plcbit Trigger2;
} MpAxisDigitalIOStatusType;

typedef struct MpAxisAddInfoHardwareType
{	unsigned short NodeID;
	unsigned char Channel;
	enum MpAxisNetworkTypeEnum NetworkType;
	enum MpAxisDeviceTypeEnum DeviceType;
} MpAxisAddInfoHardwareType;

typedef struct MpAxisStatusIDType
{	enum MpAxisErrorEnum ID;
	MpComSeveritiesEnum Severity;
	unsigned short Code;
} MpAxisStatusIDType;

typedef struct MpAxisInternalType
{	signed long ID;
	MpComSeveritiesEnum Severity;
	MpComFacilitiesEnum Facility;
	unsigned short Code;
} MpAxisInternalType;

typedef struct MpAxisDiagExtType
{	struct MpAxisStatusIDType StatusID;
	struct MpAxisInternalType Internal;
	enum MpAxisExecutingCmdEnum ExecutingCommand;
} MpAxisDiagExtType;

typedef struct MpAxisBasicInfoType
{	plcbit AxisInitialized;
	plcbit ReadyToPowerOn;
	plcbit JogLimited;
	plcbit TorqueLimitActive;
	plcbit DriveRestarted;
	struct MpAxisCyclicReadType CyclicRead;
	enum MpAxisBootPhaseEnum BootState;
	enum MpAxisPlcOpenStateEnum PLCopenState;
	struct MpAxisDigitalIOStatusType DigitalInputsStatus;
	struct MpAxisAddInfoHardwareType HardwareInfo;
	struct MpAxisDiagExtType Diag;
	plcbit MoveDone;
} MpAxisBasicInfoType;

typedef struct MpAxisDiagType
{	struct MpAxisStatusIDType StatusID;
} MpAxisDiagType;

typedef struct MpAxisSoftwareLimitType
{	double LowerLimit;
	double UpperLimit;
} MpAxisSoftwareLimitType;

typedef struct MpAxisPeriodType
{	double Period;
} MpAxisPeriodType;

typedef struct MpAxisMovementLimitsType
{	float VelocityPositive;
	float VelocityNegative;
	float Acceleration;
	float Deceleration;
	float JerkTime;
	double PositionErrorStopLimit;
	float VelocityErrorStopLimit;
	enum MpAxisVelocityLimitModeEnum VelocityErrorStopLimitMode;
} MpAxisMovementLimitsType;

typedef struct MpAxisCyclicReadChannelsType
{	unsigned short UserChannelParameterID;
} MpAxisCyclicReadChannelsType;

typedef struct MpAxisBasicConfigAxisType
{	enum MpAxisBaseTypeEnum BaseType;
	enum MpAxisMeasurementUnitEnum MeasurementUnit;
	double MeasurementResolution;
	struct MpAxisSoftwareLimitType SoftwareLimitPositions;
	struct MpAxisPeriodType PeriodSettings;
	struct MpAxisMovementLimitsType MovementLimits;
	struct MpAxisCyclicReadChannelsType CyclicReadChannels;
} MpAxisBasicConfigAxisType;

typedef struct MpAxisGearboxType
{	unsigned long Input;
	unsigned long Output;
	enum MpAxisMotorDirectionEnum Direction;
	float MaximumTorque;
} MpAxisGearboxType;

typedef struct MpAxisTransformationType
{	double ReferenceDistance;
} MpAxisTransformationType;

typedef struct MpAxisControllerPositionType
{	float ProportionalGain;
	float IntegralTime;
	float PredictionTime;
	float TotalDelayTime;
} MpAxisControllerPositionType;

typedef struct MpAxisControllerSpeedType
{	float ProportionalGain;
	float IntegralTime;
	float FilterTime;
} MpAxisControllerSpeedType;

typedef struct MpAxisControllerFeedForwardType
{	float TorqueLoad;
	float TorquePositive;
	float TorqueNegative;
	float SpeedTorqueFactor;
	float Inertia;
	float AccelerationFilterTime;
} MpAxisControllerFeedForwardType;

typedef struct MpAxisControllerVoltageFreqType
{	enum MpAxisControllerUFTypeEnum Type;
	enum MpAxisControllerUFAutoConfigEnum AutoConfig;
	float BoostVoltage;
	float RatedVoltage;
	float RatedFrequency;
	float SlipCompensation;
} MpAxisControllerVoltageFreqType;

typedef struct MpAxisLoopFilterLowPassType
{	float CutOffFrequency;
} MpAxisLoopFilterLowPassType;

typedef struct MpAxisLoopFilterNotchType
{	float CenterFrequency;
	float Bandwidth;
} MpAxisLoopFilterNotchType;

typedef struct MpAxisLoopFilterZTransferFunType
{	float A0;
	float A1;
	float B0;
	float B1;
	float B2;
} MpAxisLoopFilterZTransferFunType;

typedef struct MpAxisLoopFilterCompensationType
{	unsigned short MultiplicationFactorParID;
	unsigned short AdditiveValueParID;
} MpAxisLoopFilterCompensationType;

typedef struct MpAxisLoopFilterBiquadraticType
{	float FrequencyNumerator;
	float DampingNumerator;
	float FrequencyDenominator;
	float DampingDenominator;
} MpAxisLoopFilterBiquadraticType;

typedef struct MpAxisLoopFilterLimiterType
{	float PositiveLimit;
	float NegativeLimit;
	unsigned short PositiveLimitParID;
	unsigned short NegativeLimitParID;
} MpAxisLoopFilterLimiterType;

typedef struct MpAxisLoopFilterLimiterLinType
{	unsigned short InputParID;
	float InputLimit;
	float Gradient;
} MpAxisLoopFilterLimiterLinType;

typedef struct MpAxisLoopFilterLimiterRTimeType
{	float RiseTime;
	float NormalizedLimit;
} MpAxisLoopFilterLimiterRTimeType;

typedef struct MpAxisControllerLoopFiltersType
{	enum MpAxisControllerFilterTypeEnum FilterType;
	struct MpAxisLoopFilterLowPassType LowPass;
	struct MpAxisLoopFilterNotchType Notch;
	struct MpAxisLoopFilterZTransferFunType ZTransferFunction;
	struct MpAxisLoopFilterCompensationType Compensation;
	struct MpAxisLoopFilterBiquadraticType Biquadratic;
	struct MpAxisLoopFilterLimiterType Limiter;
	struct MpAxisLoopFilterLimiterLinType LimiterLinear;
	struct MpAxisLoopFilterLimiterRTimeType LimiterRiseTime;
} MpAxisControllerLoopFiltersType;

typedef struct MpAxisControllerType
{	enum MpAxisControllerModeEnum Mode;
	struct MpAxisControllerPositionType Position;
	struct MpAxisControllerSpeedType Speed;
	struct MpAxisControllerFeedForwardType FeedForward;
	struct MpAxisControllerVoltageFreqType VoltageFrequency;
	struct MpAxisControllerLoopFiltersType LoopFilters[3];
} MpAxisControllerType;

typedef struct MpAxisStopReactionType
{	enum MpAxisQuickStopEnum Quickstop;
	enum MpAxisErrorStopEnum DriveError;
} MpAxisStopReactionType;

typedef struct MpAxisDigitalIOLevelType
{	enum MpAxisLevelIOEnum HomingSwitch;
	enum MpAxisLevelIOEnum PositiveLimitSwitch;
	enum MpAxisLevelIOEnum NegativeLimitSwitch;
	enum MpAxisLevelIOEnum Trigger1;
	enum MpAxisLevelIOEnum Trigger2;
} MpAxisDigitalIOLevelType;

typedef struct MpAxisDigitalIOType
{	struct MpAxisDigitalIOLevelType Level;
	enum MpAxisInputSourceEnum Quickstop;
} MpAxisDigitalIOType;

typedef struct MpAxisBasicConfigDriveType
{	struct MpAxisGearboxType Gearbox;
	struct MpAxisTransformationType Transformation;
	struct MpAxisControllerType Controller;
	struct MpAxisStopReactionType StopReaction;
	struct MpAxisDigitalIOType DigitalInputs;
} MpAxisBasicConfigDriveType;

typedef struct MpAxisBasicConfigType
{	plcstring AxisName[21];
	struct MpAxisBasicConfigAxisType Axis;
	struct MpAxisBasicConfigDriveType Drive;
	enum MpAxisPosVelOutputTypeEnum PositionOutput;
	enum MpAxisPosVelOutputTypeEnum VelocityOutput;
} MpAxisBasicConfigType;

typedef struct MpAxisInfoType
{	struct MpAxisDiagType Diag;
} MpAxisInfoType;

typedef struct MpAxisGearType
{	float Acceleration;
	float Deceleration;
} MpAxisGearType;

typedef struct MpAxisCamLeadType
{	double MasterOffset;
	double MasterDistance;
	double SlaveDistance;
	plcbit CamEnable;
	unsigned char CamTableID;
	double MasterScaling;
	double SlaveScaling;
} MpAxisCamLeadType;

typedef struct MpAxisCamType
{	unsigned char CamTableID;
	double MasterStartPosition;
	struct MpAxisCamLeadType LeadIn;
	struct MpAxisCamLeadType LeadOut;
	plcstring CamTable[5][13];
} MpAxisCamType;

typedef struct MpAxisRecoveryType
{	enum MpAxisRecoveryModeEnum Mode;
	float Velocity;
	float Acceleration;
	double ToleranceWindow;
	double PhaseShift;
	double OffsetShift;
} MpAxisRecoveryType;

typedef struct MpAxisOffsetInZoneType
{	plcbit Enable;
	double ZoneStartPosition;
	double ZoneEndPosition;
	double Period;
	enum MpAxisProfileBasisEnum ProfileBasis;
} MpAxisOffsetInZoneType;

typedef struct MpAxisOffsetType
{	enum MpAxisShiftModeEnum Mode;
	double Distance;
	float Velocity;
	float Acceleration;
	enum MpAxisApplyModeEnum ApplicationMode;
	plcbit EnableVelocityControl;
	double ApplicationDistance;
	unsigned short CyclicParID;
	struct MpAxisOffsetInZoneType WithinZone;
} MpAxisOffsetType;

typedef struct MpAxisPhasingType
{	enum MpAxisShiftModeEnum Mode;
	double Distance;
	float Velocity;
	float Acceleration;
	enum MpAxisApplyModeEnum ApplicationMode;
	plcbit EnableVelocityControl;
	double ApplicationDistance;
	unsigned short CyclicParID;
} MpAxisPhasingType;

typedef struct MpAxisCouplingParType
{	float RatioNumerator;
	float RatioDenominator;
	unsigned short MasterParID;
	struct MpAxisGearType Gear;
	struct MpAxisCamType Cam;
	struct MpAxisRecoveryType Recovery;
	struct MpAxisOffsetType OffsetShift;
	struct MpAxisPhasingType PhaseShift;
} MpAxisCouplingParType;

typedef struct MpAxisCouplingInfoType
{	plcbit MasterReady;
	plcbit SlaveReady;
	double SlavePosition;
	float SlaveVelocity;
	double ActualOffsetValue;
	double ActualPhasingValue;
	struct MpAxisDiagExtType Diag;
	double RecoveryPosition;
} MpAxisCouplingInfoType;

typedef struct MpAxisTorqueRampedControlType
{	float TorqueRamp;
	float PositiveMaxVelocity;
	float NegativeMaxVelocity;
	plcbit DisableVelocityLimits;
	plcbit CompensateVelocityLimits;
	plcbit EnableTimeLimit;
	float TimeLimit;
	unsigned short StartParID;
	unsigned short TorqueParID;
} MpAxisTorqueRampedControlType;

typedef struct MpAxisTorqueSetupType
{	enum MpAxisTorqueModeEnum Mode;
	float SctrlKv;
	float SctrlTn;
	struct MpAxisTorqueRampedControlType RampedControl;
} MpAxisTorqueSetupType;

typedef struct MpAxisCyclicSetParType
{	float Acceleration;
	float Deceleration;
	float PositionModeMaxVelocity;
	enum MpAxisMoveDirectionEnum VelocityModeDirection;
	unsigned short PositionParID;
	unsigned short VelocityParID;
	struct MpAxisTorqueSetupType TorqueSetup;
} MpAxisCyclicSetParType;

typedef struct MpAxisTorqueInfoType
{	plcbit InTorque;
	plcbit WaitingForStart;
	plcbit VelocityLimitActive;
} MpAxisTorqueInfoType;

typedef struct MpAxisCyclicSetInfoType
{	plcbit AxisReady;
	unsigned short PositionReceivedParID;
	unsigned short VelocityReceivedParID;
	double SlavePosition;
	float SlaveVelocity;
	struct MpAxisDiagExtType Diag;
	struct MpAxisTorqueInfoType TorqueControl;
} MpAxisCyclicSetInfoType;

typedef struct MpAxisCamSequencerParType
{	struct MC_AUTDATA_TYP Configuration;
	float Deceleration;
	unsigned char ParLock;
	unsigned char MaxStatePerCycle;
	plcstring CamTable[14][13];
	struct MpAxisRecoveryType Recovery;
	struct MpAxisOffsetType OffsetShift;
	struct MpAxisPhasingType PhaseShift;
} MpAxisCamSequencerParType;

typedef struct MpAxisCamSequencerInfoType
{	plcbit MasterReady;
	plcbit SlaveReady;
	plcbit ActiveSignal1;
	plcbit ActiveSignal2;
	plcbit ActiveSignal3;
	plcbit ActiveSignal4;
	float ActualOffsetValue;
	float ActualPhasingValue;
	struct MpAxisDiagExtType Diag;
	double RecoveryPosition;
} MpAxisCamSequencerInfoType;

typedef struct MpAxisBasic
{
	/* VAR_INPUT (analog) */
	struct MpComIdentType* MpLink;
	struct MpAxisBasicParType* Parameters;
	unsigned long Axis;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	double Position;
	float Velocity;
	struct MpAxisBasicInfoType Info;
	/* VAR (analog) */
	struct MpComInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit ErrorReset;
	plcbit Update;
	plcbit Power;
	plcbit Home;
	plcbit MoveVelocity;
	plcbit MoveAbsolute;
	plcbit MoveAdditive;
	plcbit Stop;
	plcbit JogPositive;
	plcbit JogNegative;
	plcbit Autotune;
	plcbit Simulate;
	plcbit TorqueLimit;
	plcbit ReleaseBrake;
	/* VAR_OUTPUT (digital) */
	plcbit Active;
	plcbit Error;
	plcbit UpdateDone;
	plcbit CommandBusy;
	plcbit CommandAborted;
	plcbit PowerOn;
	plcbit IsHomed;
	plcbit InVelocity;
	plcbit InPosition;
	plcbit MoveActive;
	plcbit Stopped;
	plcbit TuningDone;
	plcbit Simulation;
	plcbit TorqueLimited;
	plcbit BrakeReleased;
} MpAxisBasic_typ;

typedef struct MpAxisCamSequencer
{
	/* VAR_INPUT (analog) */
	struct MpComIdentType* MpLink;
	struct MpAxisCamSequencerParType* Parameters;
	struct MpComIdentType* MpLinkMaster;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	unsigned char ActualStateIndex;
	unsigned short ActualStateCamIndex;
	struct MpAxisCamSequencerInfoType Info;
	/* VAR (analog) */
	struct MpComInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit ErrorReset;
	plcbit Update;
	plcbit Signal1;
	plcbit Signal2;
	plcbit Signal3;
	plcbit Signal4;
	plcbit StartSequence;
	plcbit Continue;
	plcbit EndSequence;
	plcbit Recovery;
	plcbit OffsetShift;
	plcbit PhaseShift;
	/* VAR_OUTPUT (digital) */
	plcbit Active;
	plcbit Error;
	plcbit UpdateDone;
	plcbit Standby;
	plcbit CommandBusy;
	plcbit CommandAborted;
	plcbit InCompensation;
	plcbit InSync;
	plcbit RecoveryDone;
	plcbit OffsetDone;
	plcbit PhasingDone;
} MpAxisCamSequencer_typ;

typedef struct MpAxisCoupling
{
	/* VAR_INPUT (analog) */
	struct MpComIdentType* MpLink;
	struct MpAxisCouplingParType* Parameters;
	struct MpComIdentType* MpLinkMaster;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	struct MpAxisCouplingInfoType Info;
	/* VAR (analog) */
	struct MpComInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit ErrorReset;
	plcbit Update;
	plcbit Gear;
	plcbit Cam;
	plcbit Recovery;
	plcbit OffsetShift;
	plcbit PhaseShift;
	/* VAR_OUTPUT (digital) */
	plcbit Active;
	plcbit Error;
	plcbit UpdateDone;
	plcbit CommandBusy;
	plcbit CommandAborted;
	plcbit InCompensation;
	plcbit InSync;
	plcbit RecoveryDone;
	plcbit OffsetDone;
	plcbit PhasingDone;
} MpAxisCoupling_typ;

typedef struct MpAxisCyclicSet
{
	/* VAR_INPUT (analog) */
	struct MpComIdentType* MpLink;
	struct MpAxisCyclicSetParType* Parameters;
	double Position;
	double Velocity;
	double Torque;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	struct MpAxisCyclicSetInfoType Info;
	/* VAR (analog) */
	struct MpComInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit ErrorReset;
	plcbit Update;
	plcbit CyclicPosition;
	plcbit CyclicVelocity;
	plcbit CyclicTorque;
	/* VAR_OUTPUT (digital) */
	plcbit Active;
	plcbit Error;
	plcbit UpdateDone;
	plcbit CommandBusy;
	plcbit CommandAborted;
	plcbit CyclicSetActive;
} MpAxisCyclicSet_typ;

typedef struct MpAxisBasicConfig
{
	/* VAR_INPUT (analog) */
	struct MpComIdentType* MpLink;
	struct MpAxisBasicConfigType* Configuration;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	struct MpAxisInfoType Info;
	/* VAR (analog) */
	struct MpComInternalDataType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit ErrorReset;
	plcbit Load;
	plcbit Save;
	/* VAR_OUTPUT (digital) */
	plcbit Active;
	plcbit Error;
	plcbit CommandBusy;
	plcbit CommandDone;
} MpAxisBasicConfig_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void MpAxisBasic(struct MpAxisBasic* inst);
_BUR_PUBLIC void MpAxisCamSequencer(struct MpAxisCamSequencer* inst);
_BUR_PUBLIC void MpAxisCoupling(struct MpAxisCoupling* inst);
_BUR_PUBLIC void MpAxisCyclicSet(struct MpAxisCyclicSet* inst);
_BUR_PUBLIC void MpAxisBasicConfig(struct MpAxisBasicConfig* inst);


#ifdef __cplusplus
};
#endif
#endif /* _MPAXIS_ */

