/* ncglobal.h V5.12.2 */ 
/* COPYRIGHT (C) B&R Industrial Automation GmbH */ 

/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _NCGLOBAL_
#define _NCGLOBAL_

#include <bur/plctypes.h>

#ifndef _IEC_CONST
#define _IEC_CONST _WEAK const
#endif

/* Constants */
#ifdef _REPLACE_CONST
 #define BASIS2005 1U
 #define FAST_BOOT 16384U
 #define FB_MC_AbortTrigger 2U
 #define FB_MC_BR_AutCommand 99U
 #define FB_MC_BR_AutControl 3U
 #define FB_MC_BR_AutoCamDwell 65U
 #define FB_MC_BR_AxisErrorCollector 104U
 #define FB_MC_BR_BrakeControl 110U
 #define FB_MC_BR_BrakeOperation 4U
 #define FB_MC_BR_CalcCamFromPoints 93U
 #define FB_MC_BR_CalcCamFromSections 73U
 #define FB_MC_BR_CalcPointsFromCam 123U
 #define FB_MC_BR_CalcSectionsFromCam 122U
 #define FB_MC_BR_CamDwell 64U
 #define FB_MC_BR_CamIn 146U
 #define FB_MC_BR_CamTransition 94U
 #define FB_MC_BR_CheckAutCompensation 103U
 #define FB_MC_BR_CheckEndlessPosition 130U
 #define FB_MC_BR_CommandError 140U
 #define FB_MC_BR_ConfigPowerStageCheck 137U
 #define FB_MC_BR_CreateCamProfileObj 74U
 #define FB_MC_BR_CrossCutterControl 114U
 #define FB_MC_BR_CyclicRead 69U
 #define FB_MC_BR_CyclicReadDataInfo 98U
 #define FB_MC_BR_CyclicWrite 70U
 #define FB_MC_BR_DigitalCamSwitch 106U
 #define FB_MC_BR_DownloadCamProfileData 5U
 #define FB_MC_BR_DownloadCamProfileObj 6U
 #define FB_MC_BR_DownloadParSequ 7U
 #define FB_MC_BR_EventMoveAbsolute 61U
 #define FB_MC_BR_EventMoveAdditive 62U
 #define FB_MC_BR_EventMoveVelocity 63U
 #define FB_MC_BR_GearIn 126U
 #define FB_MC_BR_GetCamMasterPosition 86U
 #define FB_MC_BR_GetCamSlavePosition 85U
 #define FB_MC_BR_GetErrorText 77U
 #define FB_MC_BR_GetHardwareInfo 109U
 #define FB_MC_BR_GetParIDInfo 107U
 #define FB_MC_BR_GetParIDTransferInfo 121U
 #define FB_MC_BR_HomeAcpEncoder 68U
 #define FB_MC_BR_InitAutData 76U
 #define FB_MC_BR_InitAutEvent 8U
 #define FB_MC_BR_InitAutPar 9U
 #define FB_MC_BR_InitAutState 10U
 #define FB_MC_BR_InitAxisPar 54U
 #define FB_MC_BR_InitAxisSubjectPar 57U
 #define FB_MC_BR_InitCyclicRead 11U
 #define FB_MC_BR_InitCyclicWrite 12U
 #define FB_MC_BR_InitEndlessPosAcpEnc 138U
 #define FB_MC_BR_InitEndlessPosition 82U
 #define FB_MC_BR_InitMasterParIDTransfer 13U
 #define FB_MC_BR_InitModPos 14U
 #define FB_MC_BR_InitParList 15U
 #define FB_MC_BR_InitParSequ 16U
 #define FB_MC_BR_InitParTabObj 17U
 #define FB_MC_BR_InitReceiveNetworkData 115U
 #define FB_MC_BR_InitReceiveNetworkEnc 141U
 #define FB_MC_BR_InitReceiveParID 112U
 #define FB_MC_BR_InitSendParID 111U
 #define FB_MC_BR_JogLimitPosition 119U
 #define FB_MC_BR_JogTargetPosition 120U
 #define FB_MC_BR_JogVelocity 118U
 #define FB_MC_BR_LimitLoad 134U
 #define FB_MC_BR_LimitLoadCam 135U
 #define FB_MC_BR_LoadAxisPar 56U
 #define FB_MC_BR_MechPosDeviationComp 147U
 #define FB_MC_BR_MoveAbsoluteTriggStop 18U
 #define FB_MC_BR_MoveAdditiveTriggStop 19U
 #define FB_MC_BR_MoveCyclicPosition 84U
 #define FB_MC_BR_MoveCyclicPositionExt 124U
 #define FB_MC_BR_MoveCyclicVelocity 92U
 #define FB_MC_BR_MoveCyclicVelocityExt 125U
 #define FB_MC_BR_MoveVelocityTriggStop 20U
 #define FB_MC_BR_NetTrace 78U
 #define FB_MC_BR_NetworkInit 139U
 #define FB_MC_BR_Offset 58U
 #define FB_MC_BR_OffsetVelocity 127U
 #define FB_MC_BR_OffsetZone 128U
 #define FB_MC_BR_ParTrace 80U
 #define FB_MC_BR_ParTraceConfig 102U
 #define FB_MC_BR_Phasing 59U
 #define FB_MC_BR_PowerMeter 89U
 #define FB_MC_BR_ReadAutPosition 75U
 #define FB_MC_BR_ReadAxisError 105U
 #define FB_MC_BR_ReadCyclicPosition 83U
 #define FB_MC_BR_ReadDriveStatus 72U
 #define FB_MC_BR_ReadLoadSimInputData 131U
 #define FB_MC_BR_ReadLoadSimTorque 142U
 #define FB_MC_BR_ReadNetTraceStatus 79U
 #define FB_MC_BR_ReadParID 21U
 #define FB_MC_BR_ReadParIDText 90U
 #define FB_MC_BR_ReadParList 148U
 #define FB_MC_BR_ReadParTraceStatus 81U
 #define FB_MC_BR_ReceiveParIDOnPLC 113U
 #define FB_MC_BR_RegMarkCalc001 67U
 #define FB_MC_BR_RegMarkCapture001 66U
 #define FB_MC_BR_RegMarkCapture002 117U
 #define FB_MC_BR_ResetAutPar 136U
 #define FB_MC_BR_SaveAxisPar 55U
 #define FB_MC_BR_SaveCamProfileObj 116U
 #define FB_MC_BR_SetHardwareInputs 108U
 #define FB_MC_BR_SetupController 88U
 #define FB_MC_BR_SetupFromParTabObj 145U
 #define FB_MC_BR_SetupInductionMotor 87U
 #define FB_MC_BR_SetupIsqRipple 101U
 #define FB_MC_BR_SetupMotorPhasing 97U
 #define FB_MC_BR_SetupSynchronMotor 129U
 #define FB_MC_BR_Simulation 71U
 #define FB_MC_BR_TorqueControl 100U
 #define FB_MC_BR_TouchProbe 60U
 #define FB_MC_BR_VelocityControl 95U
 #define FB_MC_BR_WriteLoadSimOutputData 132U
 #define FB_MC_BR_WriteLoadSimPosition 143U
 #define FB_MC_BR_WriteLoadSimTorque 144U
 #define FB_MC_BR_WriteLoadSimTwoEncPos 149U
 #define FB_MC_BR_WriteParID 22U
 #define FB_MC_BR_WriteParIDText 91U
 #define FB_MC_CamIn 23U
 #define FB_MC_CamOut 24U
 #define FB_MC_CamTableSelect 25U
 #define FB_MC_DigitalCamSwitch 26U
 #define FB_MC_GearIn 27U
 #define FB_MC_GearInPos 28U
 #define FB_MC_GearOut 29U
 #define FB_MC_Halt 30U
 #define FB_MC_Home 31U
 #define FB_MC_LimitLoad 133U
 #define FB_MC_MoveAbsolute 32U
 #define FB_MC_MoveAdditive 33U
 #define FB_MC_MoveRelative 34U
 #define FB_MC_MoveVelocity 35U
 #define FB_MC_Phasing 36U
 #define FB_MC_Power 37U
 #define FB_MC_ReadActualPosition 39U
 #define FB_MC_ReadActualTorque 38U
 #define FB_MC_ReadActualVelocity 40U
 #define FB_MC_ReadAxisError 41U
 #define FB_MC_ReadBoolParameter 42U
 #define FB_MC_ReadDigitalInput 43U
 #define FB_MC_ReadDigitalOutput 44U
 #define FB_MC_ReadParameter 45U
 #define FB_MC_ReadStatus 46U
 #define FB_MC_Reset 47U
 #define FB_MC_SetOverride 48U
 #define FB_MC_Stop 49U
 #define FB_MC_TorqueControl 96U
 #define FB_MC_TouchProbe 50U
 #define FB_MC_WriteBoolParameter 51U
 #define FB_MC_WriteDigitalOutput 52U
 #define FB_MC_WriteParameter 53U
 #define IO_2005 1152U
 #define IO_2010 1024U
 #define MC_InitFunction 1U
 #define MOD_UPDATE 32768U
 #define nc100KHZ 1U
 #define nc154CAN 5U
 #define nc156CAN 6U
 #define nc157CAN 9U
 #define nc158CAN 7U
 #define nc20KHZ 0U
 #define nc2ENCOD_SPEED 5U
 #define ncA_LIMIT 20U
 #define ncA_MOVE 10U
 #define ncABORT_DATA 8U
 #define ncABORT_LINE 4U
 #define ncABOVE_WINDOW 40U
 #define ncABS 1U
 #define ncABS_MOVE 132U
 #define ncABS_SWITCH 2U
 #define ncABSOLUTE 0U
 #define ncACCEL 1U
 #define ncACK 257U
 #define ncACKNOWLEDGE 257U
 #define ncACOPOS_1 0U
 #define ncACOPOS_2 1U
 #define ncACOPOS_INFO 322U
 #define ncACOPOS_P3 12U
 #define ncACOPOS_SDC 128U
 #define ncACOPOS_SIM 129U
 #define ncACOPOSmicro 7U
 #define ncACOPOSmotor 4U
 #define ncACOPOSmotor_C 18U
 #define ncACOPOSmulti 5U
 #define ncACOPOSmulti_PPS 6U
 #define ncACOPOSmulti3 9U
 #define ncACOPOSmulti65 8U
 #define ncACOPOSmulti65m 4U
 #define ncACOPOSremote 8U
 #define ncACP_PAR 401U
 #define ncACP_PAR_INIT_BRC_DP 355U
 #define ncACP_PAR_INIT_BRC_DP64 354U
 #define ncACP_PAR_RECEIVE 353U
 #define ncACP_PAR_SEND 352U
 #define ncACP_SIM_COMPLETE 2U
 #define ncACP_SIM_STANDARD 1U
 #define ncACP_TYP_INV 1U
 #define ncACP_TYP_PPS 2U
 #define ncACP_TYP_PS 0U
 #define ncACP_TYP_SDC 128U
 #define ncACP_TYP_SIM 129U
 #define ncACP10MAN 32768U
 #define ncACP10USCOB 255U
 #define ncACT_POS 120U
 #define ncACTIV_HI 1U
 #define ncACTIV_LO 0U
 #define ncACTIVE 1U
 #define ncADD_DATE_TIME 1U
 #define ncAIL_DUMP 220U
 #define ncALL 373U
 #define ncANALOG 0U
 #define ncAND_N2E 15U
 #define ncARNC0MAN 36864U
 #define ncAT_ONCE 0U
 #define ncAUT_END 10U
 #define ncAUTO 1U
 #define ncAUTOMAT 122U
 #define ncAUTOSAVE 64U
 #define ncAXES 213U
 #define ncAXIS 1U
 #define ncBASIS 1U
 #define ncBASIS_MOVE 130U
 #define ncBASIS_TRG_STOP 137U
 #define ncBELOW_WINDOW 50U
 #define ncBIDIR 4U
 #define ncBINARY 1U
 #define ncBIQUAD 9U
 #define ncBISS 9U
 #define ncBL 1U
 #define ncBLOCK 202U
 #define ncBLOCK_DS 10U
 #define ncBLOCK_TORQUE 9U
 #define ncBLOCKMON 371U
 #define ncBLOCKMONITOR 4U
 #define ncBLOCKNUMBER 1U
 #define ncBLOCKSEARCH 277U
 #define ncBRAKE 171U
 #define ncBREAK 2U
 #define ncBREAKPOINT 370U
 #define ncBURN 340U
 #define ncBYTEOFFSET 3U
 #define ncCALCULATION 11U
 #define ncCAM_BEG 6U
 #define ncCAM_PROF 117U
 #define ncCAMPRDAT 24U
 #define ncCAMPRPOL 25U
 #define ncCAMPRPOL_ACOPOS 27U
 #define ncCAN_IF 0U
 #define ncCLOSED 1U
 #define ncCMD_ERROR 281U
 #define ncCMD_ERROR_COAST_TO_STANDSTILL 5U
 #define ncCMD_ERROR_INDUCTION_HALT 6U
 #define ncCMD_ERROR_ONLY 1U
 #define ncCMD_ERROR_STOP 2U
 #define ncCMD_ERROR_STOP_CTRL_OFF 3U
 #define ncCMD_ERROR_V_STOP_CTRL_OFF 4U
 #define ncCMD_WARNING_ONLY 0U
 #define ncCNC 0U
 #define ncCNC_C_AX 199U
 #define ncCNC_PLC 212U
 #define ncCNC_PROG 20U
 #define ncCNCSYS 2U
 #define ncCOMP 125U
 #define ncCOMP_ERR 14U
 #define ncCOMPAR 115U
 #define ncCONTINUE 263U
 #define ncCONTINUE_ 263U
 #define ncCONTROL 105U
 #define ncCONTROLLER 105U
 #define ncCORRECTION 128U
 #define ncCOUNT 11U
 #define ncCOUPLING 274U
 #define ncCSTRF 1U
 #define ncCTRL_OFF 50U
 #define ncCYCL_USER_FRDRV 257U
 #define ncCYCL_USER_FRDRV_AT_STARTUP 259U
 #define ncCYCL_USER_TODRV 256U
 #define ncCYCL_USER_TODRV_AT_STARTUP 258U
 #define ncCYCLIC 8U
 #define ncD_POS 13U
 #define ncD_SINGLE 207U
 #define ncDAT_MOD 301U
 #define ncDATA 0U
 #define ncDATA_TEXT 1024U
 #define ncDATBLOCK 162U
 #define ncDATMOD_ACP_CAM_POLY 27U
 #define ncDATMOD_ACP_PAR 16U
 #define ncDATMOD_ACP_PAR_TRACE 31U
 #define ncDATMOD_CNC_CAM_POLY 25U
 #define ncDATMOD_CNC_CAM_TAB 24U
 #define ncDATMOD_CNC_PROG 20U
 #define ncDATMOD_CNC_R_PAR 23U
 #define ncDATMOD_CNC_TOOL 22U
 #define ncDATMOD_DATBLOCK 33U
 #define ncDATMOD_NC_MAPPING 28U
 #define ncDATMOD_NET_TRACE 30U
 #define ncDATMOD_ZERO_P_OFF 21U
 #define ncDATOBJ_BRMOD 0U
 #define ncDATOBJ_BRMOD_DEFAULT 65535U
 #define ncDATOBJ_FILE 1U
 #define ncDATOBJ_FORMAT_BIN 0U
 #define ncDATOBJ_FORMAT_CSV 1U
 #define ncDATOBJ_FORMAT_TXT 2U
 #define ncDCM 7U
 #define ncDECEL 4U
 #define ncDECODER 206U
 #define ncDEFINE 369U
 #define ncDELETE 342U
 #define ncDIAGNOSE 321U
 #define ncDIG_IN 102U
 #define ncDIRECT 0U
 #define ncDM16BIT 8192U
 #define ncDNC 2U
 #define ncDOWNLOAD 339U
 #define ncDPR_OVR 217U
 #define ncDPR_TRACE 306U
 #define ncDRAM 65U
 #define ncDRIVE 166U
 #define ncDRIVE_ID 123U
 #define ncDRIVE_IF 104U
 #define ncDRIVE_READY 255U
 #define ncDV_STOP_AUTO1 2U
 #define ncDV_STOP_AUTO2 3U
 #define ncDV_STOP_INIT 1U
 #define ncE_STOP 262U
 #define ncEDGE2 12U
 #define ncEMPTY 0U
 #define ncENABLE 170U
 #define ncENCOD_IF 103U
 #define ncENCODER_IF 103U
 #define ncEND_SWITCH 4U
 #define ncENDAT 4U
 #define ncENDAT_SafeMOTION 14U
 #define ncENDAT3 16U
 #define ncENGLISH 1U
 #define ncENTRY 4U
 #define ncEPROM 2U
 #define ncERR_CL0 215U
 #define ncERROR 1U
 #define ncETEL 2U
 #define ncEVEN 3U
 #define ncEVENT 136U
 #define ncEX_PARAM 214U
 #define ncEXECUTE 374U
 #define ncEXPRESSION 375U
 #define ncEXTENCOD 8U
 #define ncEXTERN 128U
 #define ncFALSE 0U
 #define ncFC 1U
 #define ncFF 32U
 #define ncFF_NEG_MOVE 34U
 #define ncFF_POS_MOVE 33U
 #define ncFILE 3U
 #define ncFILE_XL 1U
 #define ncFILEOFFSET 0U
 #define ncFINISH 282U
 #define ncFIXRAM 5U
 #define ncFORCE 288U
 #define ncFORMAT_ADR 0U
 #define ncFORMAT_B06 2U
 #define ncFORMAT_T10 1U
 #define ncFORMAT_T14 3U
 #define ncG00 0U
 #define ncG01 1U
 #define ncG02 2U
 #define ncG03 3U
 #define ncGANTRY 1U
 #define ncGATE 1U
 #define ncGEARS 111U
 #define ncGEARS_V 116U
 #define ncGEARSABS 124U
 #define ncGERMAN 0U
 #define ncGETINFO 376U
 #define ncGLOBAL 4U
 #define ncglobal_action_ACP10MSG_TEXT 5U
 #define ncglobal_action_NCDA_CREATE 1U
 #define ncglobal_action_NCDA_DIR 4U
 #define ncglobal_action_NCDA_INFO 2U
 #define ncglobal_action_NCDA_WRITE 3U
 #define ncGO_HOME 106U
 #define ncGRAY 0U
 #define ncHALT 219U
 #define ncHALT_ERR 32U
 #define ncHALT_EXEC_ERR 64U
 #define ncHALT_OK 135U
 #define ncHALT_PLC 4U
 #define ncHALT_POS 8U
 #define ncHALT_PRG 2U
 #define ncHALT_RST 16U
 #define ncHALT_SST 1U
 #define ncHIGH 1U
 #define ncHIPERFACE 8U
 #define ncHIPERFACE_DSL 13U
 #define ncHOME_OFFSET 5U
 #define ncHOMING 106U
 #define ncHORIZONTAL 0U
 #define ncHW_END 4096U
 #define ncI_LIMIT 30U
 #define ncIDENTIFICATION 10U
 #define ncIN_WINDOW 20U
 #define ncINC 2U
 #define ncINC_COMP 252U
 #define ncINC_OUTPUT 7U
 #define ncINC_SSI 10U
 #define ncINCH 1U
 #define ncINCLUDE 2U
 #define ncINDIRECT 255U
 #define ncINDRAMAT 0U
 #define ncINDUCTION 40U
 #define ncINFO 268U
 #define ncINIT 512U
 #define ncINIT_SET_POS 6U
 #define ncINTERPRETER 41U
 #define ncINVERSE 255U
 #define ncIP_INFO_AS_WARNING 222U
 #define ncIPGLOBAL 385U
 #define ncISQ_F1_LOW_PASS 1024U
 #define ncISQ_F1_NOTCH 128U
 #define ncISQ_F2_LOW_PASS 2048U
 #define ncISQ_F2_NOTCH 256U
 #define ncISQ_F3_LOW_PASS 4096U
 #define ncISQ_F3_NOTCH 512U
 #define ncISQ_RIPPLE 144U
 #define ncISQF_COMP 6U
 #define ncISQF_LIM 5U
 #define ncISQF_LIM2 7U
 #define ncISQF_LIM3 4U
 #define ncISQF_TRQ_ADDLIM 8U
 #define ncISQR_MODE_A_PHI 20U
 #define ncISQR_REF_SYSTEM_ENCODER 0U
 #define ncISQR_REF_SYSTEM_FLUX 1U
 #define ncLAG_ERR 2U
 #define ncLATCH1 108U
 #define ncLATCH2 109U
 #define ncLATCHPOS 32U
 #define ncLEFT 2U
 #define ncLIMITER 114U
 #define ncLIMITS 2U
 #define ncLINE 372U
 #define ncLINEAR 1U
 #define ncLINEAR2 3U
 #define ncLINENUMBER 4U
 #define ncLINK 343U
 #define ncLINMOT 11U
 #define ncLOAD 276U
 #define ncLOAD_ABORT 278U
 #define ncLOW 0U
 #define ncLOW_PASS 1U
 #define ncM_GRP_TAB 126U
 #define ncM1_STOP 203U
 #define ncMA_LATCHPOS 32U
 #define ncMA_S_START_I32 2048U
 #define ncMA_SL_ABS 40U
 #define ncMA_TO_SL 16384U
 #define ncMA_V_COMP 32768U
 #define ncMAGNESCALE 12U
 #define ncMAINPROG (-1)
 #define ncMC_STATE_CONTINUOUS_MOTION 7U
 #define ncMC_STATE_DISABLED 1U
 #define ncMC_STATE_DISCRETE_MOTION 6U
 #define ncMC_STATE_ERROR 10U
 #define ncMC_STATE_ERRORSTOP 4U
 #define ncMC_STATE_GroupDisabled 6U
 #define ncMC_STATE_GroupErrorstop 3U
 #define ncMC_STATE_GroupHoming 2U
 #define ncMC_STATE_GroupMoving 1U
 #define ncMC_STATE_GroupStandby 4U
 #define ncMC_STATE_GroupStopping 5U
 #define ncMC_STATE_HOMING 3U
 #define ncMC_STATE_MOTION 9U
 #define ncMC_STATE_NET_INIT 0U
 #define ncMC_STATE_STANDSTILL 2U
 #define ncMC_STATE_STOPPING 5U
 #define ncMC_STATE_SYNCHRONIZED_MOTION 8U
 #define ncMEMCARD 4U
 #define ncMESSAGE 1U
 #define ncMM 0U
 #define ncMOD_DIR 128U
 #define ncMOD_SYNC 303U
 #define ncMODEL_1MASS 4U
 #define ncMODEL_2MASS 3U
 #define ncMODULE 3U
 #define ncMOTOR 140U
 #define ncMOTOR_INDUCTION 141U
 #define ncMOTOR_PAR 1U
 #define ncMOTOR_PHASING 143U
 #define ncMOTOR_SYNCHRON 142U
 #define ncMOTPH_DITHER 32U
 #define ncMOTPH_SATURATION 30U
 #define ncMOTPH_SET_OFFSET 34U
 #define ncMOTPH_STEPPER 31U
 #define ncMOVE 3U
 #define ncMOVE_BEG 1U
 #define ncMOVE_CMD 5U
 #define ncMOVE_END 2U
 #define ncMP_LOG 221U
 #define ncMTC 305U
 #define ncMULTI_AX_TRACE 11U
 #define ncN_EDGE 1U
 #define ncN_PERIOD 1U
 #define ncN_THRESH 4U
 #define ncNC_SYS_RESTART 32768U
 #define ncNCBLOCKNO 22U
 #define ncNCGLOBAL 384U
 #define ncNCPR_POS 218U
 #define ncNCRECNO 22U
 #define ncNEG_MOVE 133U
 #define ncNEG_THRESH 2U
 #define ncNEGATIVE 1U
 #define ncNET_GLOBAL 12U
 #define ncNET_TRACE 404U
 #define ncNETWORK 403U
 #define ncNO_CHECK 30U
 #define ncNO_NET_TRACE 32768U
 #define ncNOFEED 64U
 #define ncNOSTOP 16U
 #define ncNOTCH 2U
 #define ncNP_EDGE 11U
 #define ncOBJ_PTR 64U
 #define ncODD 2U
 #define ncOFF 0U
 #define ncOK 0U
 #define ncON 1U
 #define ncONL_POS 107U
 #define ncONL_V 113U
 #define ncONLYCOMP 30U
 #define ncONLYCOMP_DIRECT 35U
 #define ncONTHEFLY 3U
 #define ncOPEN 0U
 #define ncOUT_WINDOW 30U
 #define ncP_EDGE 0U
 #define ncP_LATCH1 1U
 #define ncP_LATCH2 2U
 #define ncP_THRESH 3U
 #define ncPACSI 1U
 #define ncPAR_ID 16U
 #define ncPAR_ID1 16U
 #define ncPAR_ID2 17U
 #define ncPAR_ID3 18U
 #define ncPAR_ID4 19U
 #define ncPAR_LIST 402U
 #define ncPAR_LIST_MOVE 16384U
 #define ncPAR_SEQU 400U
 #define ncPAR_TYP_BOOL 1U
 #define ncPAR_TYP_BRMOD 14U
 #define ncPAR_TYP_BYTES 11U
 #define ncPAR_TYP_DATA 13U
 #define ncPAR_TYP_DINT 4U
 #define ncPAR_TYP_GRP 12U
 #define ncPAR_TYP_INT 3U
 #define ncPAR_TYP_LREAL 17U
 #define ncPAR_TYP_NIL 0U
 #define ncPAR_TYP_REAL 8U
 #define ncPAR_TYP_SINT 2U
 #define ncPAR_TYP_STR16 4106U
 #define ncPAR_TYP_STR32 8202U
 #define ncPAR_TYP_T5 9U
 #define ncPAR_TYP_UDINT 7U
 #define ncPAR_TYP_UINT 6U
 #define ncPAR_TYP_USINT 5U
 #define ncPAR_TYP_VOID 65535U
 #define ncPAR_TYP_VOID_NO_NET_TRACE 65534U
 #define ncPARID_TRACE 10U
 #define ncPASSIVE 4U
 #define ncPATH 386U
 #define ncPATHDISTANCE 0U
 #define ncPI_PRED 0U
 #define ncPLC_ITR 302U
 #define ncPN_EDGE 10U
 #define ncPOLAR_PHI 8U
 #define ncPOLAR_RAD 4U
 #define ncPOS_ERR 4U
 #define ncPOS_MOVE 134U
 #define ncPOS_THRESH 1U
 #define ncPOSITION 1U
 #define ncPOSITIVE 0U
 #define ncPOSMON 216U
 #define ncPOWERLINK_IF 1U
 #define ncPRELOAD 4U
 #define ncPROGRAM 201U
 #define ncPULL 2U
 #define ncPUSH 1U
 #define ncPUSHPULL 0U
 #define ncQUADRATIC 2U
 #define ncQUADRATIC_NO_OVERSHOOT 4U
 #define ncQUICKSTOP 2U
 #define ncQUICKSTOP_T_JOLT 2U
 #define ncR_PAR 23U
 #define ncR_PARAM 211U
 #define ncR_PARTAB 210U
 #define ncR_PULSE 2U
 #define ncRAM 1U
 #define ncREAD 265U
 #define ncREAD_COB 321U
 #define ncRECORD 202U
 #define ncREL_MOVE 131U
 #define ncREL_POS 119U
 #define ncRELATIVE 1U
 #define ncRELEASE 387U
 #define ncREPLACE 1U
 #define ncRESET 320U
 #define ncRESOLVER 5U
 #define ncRESTART 273U
 #define ncRESTORE_POS 8U
 #define ncRIGHT 3U
 #define ncRING_STARTIDX 4096U
 #define ncROTARY 32U
 #define ncS_ACT 11U
 #define ncS_ACT_TO_S_SET 279U
 #define ncS_JUMP_T 8U
 #define ncS_MOTOR 1U
 #define ncS_NCBLOCK 23U
 #define ncS_NCBLOCK_N1 25U
 #define ncS_NCBLOCK_TOT 24U
 #define ncS_NCPROG 21U
 #define ncS_REST 4096U
 #define ncS_SET 10U
 #define ncS_SET_COMP 16U
 #define ncS_START 10U
 #define ncS_START_IV1 41U
 #define ncS_START_IV2 42U
 #define ncS_START_IV3 43U
 #define ncS_START_IV4 44U
 #define ncSAVE 341U
 #define ncSBL_CONTROL 2U
 #define ncSCALE 180U
 #define ncSDC_IF 129U
 #define ncSEND 368U
 #define ncSERCOS 2U
 #define ncSERCOS_LIN 128U
 #define ncSERCOSIF 310U
 #define ncSERVICE 165U
 #define ncSET 264U
 #define ncSET_GEN_ONLY 1024U
 #define ncSETUP 16384U
 #define ncSETUP_MOVE_T_JOLT 16U
 #define ncSHORT_PATH 1U
 #define ncSIG_LINE 110U
 #define ncSIGNAL 4U
 #define ncSIGNAL_CHIRP 1U
 #define ncSIGNAL_CHIRP_TRAPEZOID 2U
 #define ncSIGNAL_PRBS 0U
 #define ncSIGNAL1 91U
 #define ncSIGNAL2 92U
 #define ncSIGNAL3 93U
 #define ncSIGNAL4 94U
 #define ncSIM_1MASS 1U
 #define ncSIM_1MASS_AUTO 0U
 #define ncSIM_1MASS_GEAR 3U
 #define ncSIM_2MASS 2U
 #define ncSIM_2MASS_GEAR 4U
 #define ncSIM_START 127U
 #define ncSIMULAT 150U
 #define ncSIMULATION 150U
 #define ncSINGLE 204U
 #define ncSKIP_FCN 205U
 #define ncSKIP_PARSE 10U
 #define ncSL_ABS 33U
 #define ncSL_LATCHPOS 34U
 #define ncSPEED 2U
 #define ncSPOSSTDZ 160U
 #define ncSSE 2U
 #define ncSSI 6U
 #define ncSSI_CONT_TYP_END 0U
 #define ncSSI_CONT_TYP_ERR 2U
 #define ncSSI_CONT_TYP_ERR_INV 3U
 #define ncSSI_CONT_TYP_FILL 6U
 #define ncSSI_CONT_TYP_POS 1U
 #define ncSSI_CONT_TYP_WRN 4U
 #define ncSSI_CONT_TYP_WRN_INV 5U
 #define ncSSI_PARITY_CHK_EVEN 6U
 #define ncSSI_PARITY_CHK_ODD 7U
 #define ncSSI_SEND 3U
 #define ncST_CAMPR 2U
 #define ncST_COMP 4U
 #define ncST_END 12U
 #define ncSTANDARD 0U
 #define ncSTART 260U
 #define ncSTART_CG 269U
 #define ncSTART_CYC_TRACE_CTRL_BITS 289U
 #define ncSTART_IV 270U
 #define ncSTART_NETWORK_REQU_PARCMD 280U
 #define ncSTART_T 275U
 #define ncSTARTABS 272U
 #define ncSTARTDIR 267U
 #define ncSTATE 128U
 #define ncSTEP_INTO 221U
 #define ncSTEP_OVER 220U
 #define ncSTOP 261U
 #define ncSW_END 1U
 #define ncSW_OFF 259U
 #define ncSW_ON 258U
 #define ncSWITCH 2U
 #define ncSWITCH_GATE 1U
 #define ncSWITCH_OFF 259U
 #define ncSWITCH_ON 258U
 #define ncSYNC 266U
 #define ncSYSROM 0U
 #define ncT_FILTER 64U
 #define ncT_FILTER_2 65U
 #define ncT_FORMAT 15U
 #define ncT_JOLT 1U
 #define ncT_TOTAL 128U
 #define ncTANGENT 2U
 #define ncTEST 31U
 #define ncTEST_POSITION 16386U
 #define ncTEST_SPEED 16385U
 #define ncTEXT 271U
 #define ncTHRESHLD 0U
 #define ncTOOL 22U
 #define ncTOOL_TAB 209U
 #define ncTOOLDAT 2U
 #define ncTR_DELAY 6U
 #define ncTR_END 1U
 #define ncTR_REST 5U
 #define ncTR_RING 4U
 #define ncTR_SAVE 7U
 #define ncTR_SDM 21U
 #define ncTR_START 20U
 #define ncTR_TRACE 2U
 #define ncTR_TRIGG 3U
 #define ncTRACE 304U
 #define ncTRACE_DAT_WR 2050U
 #define ncTRACE_PAR_SEC_REC 2048U
 #define ncTRG_STOP 8192U
 #define ncTRG_STOP_NORMAL 1U
 #define ncTRG_STOP_S_REST 2U
 #define ncTRGPOS_S 118U
 #define ncTRIGGER 0U
 #define ncTRIGGER_2 6U
 #define ncTRIGGER1 20U
 #define ncTRIGGER2 22U
 #define ncTRIGGER3 24U
 #define ncTRIGGER4 26U
 #define ncTRIGGER5 28U
 #define ncTRIGGER6 30U
 #define ncTRIGGER7 32U
 #define ncTRIGGER8 34U
 #define ncTRIGGPOS 112U
 #define ncTRQ_LIMIT 30U
 #define ncTRUE 1U
 #define ncTUNE_FBCTRL_MODEL_2MASS 8192U
 #define ncTUNE_MODEL_2MASS 32768U
 #define ncTUNE_MODEL_FRICTION 8192U
 #define ncTUNE_STANDSTILL 0U
 #define ncTUNE_TN 16U
 #define ncTUNE_V_CONSTANT 1U
 #define ncU_LIMIT 40U
 #define ncU_SET 13U
 #define ncUF 7U
 #define ncUNLINK 344U
 #define ncUPLOAD 338U
 #define ncUSE_FILTER_PAR 4U
 #define ncUSE_TN 8U
 #define ncUSER 1U
 #define ncUSERROM 2U
 #define ncV_ACT 14U
 #define ncV_AXIS 4U
 #define ncV_COMP_A_CYC 39U
 #define ncV_COMP_A_SL 36U
 #define ncV_COMP_S_MA 37U
 #define ncV_COMP_S_SL 38U
 #define ncV_CONST 2U
 #define ncV_JUMP 1U
 #define ncV_JUMP_T 4U
 #define ncV_SET 12U
 #define ncV_SET_COMP 17U
 #define ncV_TRAJ 20U
 #define ncVARIABLE 377U
 #define ncVERTICAL 1U
 #define ncVIRTUAL_IF 128U
 #define ncWINDOW 1U
 #define ncWITH_CAM 31U
 #define ncWITH_INDEX 0U
 #define ncWITHOUT_INDEX 1U
 #define ncWRITE_COB 320U
 #define ncWRITE_HPRIO 290U
 #define ncXY 0U
 #define ncYZ 2U
 #define ncZ_TRANS 3U
 #define ncZERO 1U
 #define ncZERO_DAT 21U
 #define ncZERO_TAB 208U
 #define ncZEROPMON 216U
 #define ncZX 1U
 #define RIO1_2005 1408U
 #define RIO2_2005 2432U
 #define RIO3_2005 3456U
 #define RIO4_2005 4480U
 #define SafeMC_action_GET_CFG_PTR 1U
 #define SafeMC_action_READ_SAFEIN_DATA 3U
 #define SafeMC_action_READ_SAFEIN_DATA2 5U
 #define SafeMC_action_READ_SAFEIN_DATA3 7U
 #define SafeMC_action_READ_SAFEOUT_DATA 2U
 #define SafeMC_action_READ_SAFEOUT_DATA2 4U
 #define SafeMC_action_READ_SAFEOUT_DATA3 6U
#else
 _IEC_CONST unsigned short BASIS2005 = 1U;
 _IEC_CONST unsigned short FAST_BOOT = 16384U;
 _IEC_CONST unsigned short FB_MC_AbortTrigger = 2U;
 _IEC_CONST unsigned short FB_MC_BR_AutCommand = 99U;
 _IEC_CONST unsigned short FB_MC_BR_AutControl = 3U;
 _IEC_CONST unsigned short FB_MC_BR_AutoCamDwell = 65U;
 _IEC_CONST unsigned short FB_MC_BR_AxisErrorCollector = 104U;
 _IEC_CONST unsigned short FB_MC_BR_BrakeControl = 110U;
 _IEC_CONST unsigned short FB_MC_BR_BrakeOperation = 4U;
 _IEC_CONST unsigned short FB_MC_BR_CalcCamFromPoints = 93U;
 _IEC_CONST unsigned short FB_MC_BR_CalcCamFromSections = 73U;
 _IEC_CONST unsigned short FB_MC_BR_CalcPointsFromCam = 123U;
 _IEC_CONST unsigned short FB_MC_BR_CalcSectionsFromCam = 122U;
 _IEC_CONST unsigned short FB_MC_BR_CamDwell = 64U;
 _IEC_CONST unsigned short FB_MC_BR_CamIn = 146U;
 _IEC_CONST unsigned short FB_MC_BR_CamTransition = 94U;
 _IEC_CONST unsigned short FB_MC_BR_CheckAutCompensation = 103U;
 _IEC_CONST unsigned short FB_MC_BR_CheckEndlessPosition = 130U;
 _IEC_CONST unsigned short FB_MC_BR_CommandError = 140U;
 _IEC_CONST unsigned short FB_MC_BR_ConfigPowerStageCheck = 137U;
 _IEC_CONST unsigned short FB_MC_BR_CreateCamProfileObj = 74U;
 _IEC_CONST unsigned short FB_MC_BR_CrossCutterControl = 114U;
 _IEC_CONST unsigned short FB_MC_BR_CyclicRead = 69U;
 _IEC_CONST unsigned short FB_MC_BR_CyclicReadDataInfo = 98U;
 _IEC_CONST unsigned short FB_MC_BR_CyclicWrite = 70U;
 _IEC_CONST unsigned short FB_MC_BR_DigitalCamSwitch = 106U;
 _IEC_CONST unsigned short FB_MC_BR_DownloadCamProfileData = 5U;
 _IEC_CONST unsigned short FB_MC_BR_DownloadCamProfileObj = 6U;
 _IEC_CONST unsigned short FB_MC_BR_DownloadParSequ = 7U;
 _IEC_CONST unsigned short FB_MC_BR_EventMoveAbsolute = 61U;
 _IEC_CONST unsigned short FB_MC_BR_EventMoveAdditive = 62U;
 _IEC_CONST unsigned short FB_MC_BR_EventMoveVelocity = 63U;
 _IEC_CONST unsigned short FB_MC_BR_GearIn = 126U;
 _IEC_CONST unsigned short FB_MC_BR_GetCamMasterPosition = 86U;
 _IEC_CONST unsigned short FB_MC_BR_GetCamSlavePosition = 85U;
 _IEC_CONST unsigned short FB_MC_BR_GetErrorText = 77U;
 _IEC_CONST unsigned short FB_MC_BR_GetHardwareInfo = 109U;
 _IEC_CONST unsigned short FB_MC_BR_GetParIDInfo = 107U;
 _IEC_CONST unsigned short FB_MC_BR_GetParIDTransferInfo = 121U;
 _IEC_CONST unsigned short FB_MC_BR_HomeAcpEncoder = 68U;
 _IEC_CONST unsigned short FB_MC_BR_InitAutData = 76U;
 _IEC_CONST unsigned short FB_MC_BR_InitAutEvent = 8U;
 _IEC_CONST unsigned short FB_MC_BR_InitAutPar = 9U;
 _IEC_CONST unsigned short FB_MC_BR_InitAutState = 10U;
 _IEC_CONST unsigned short FB_MC_BR_InitAxisPar = 54U;
 _IEC_CONST unsigned short FB_MC_BR_InitAxisSubjectPar = 57U;
 _IEC_CONST unsigned short FB_MC_BR_InitCyclicRead = 11U;
 _IEC_CONST unsigned short FB_MC_BR_InitCyclicWrite = 12U;
 _IEC_CONST unsigned short FB_MC_BR_InitEndlessPosAcpEnc = 138U;
 _IEC_CONST unsigned short FB_MC_BR_InitEndlessPosition = 82U;
 _IEC_CONST unsigned short FB_MC_BR_InitMasterParIDTransfer = 13U;
 _IEC_CONST unsigned short FB_MC_BR_InitModPos = 14U;
 _IEC_CONST unsigned short FB_MC_BR_InitParList = 15U;
 _IEC_CONST unsigned short FB_MC_BR_InitParSequ = 16U;
 _IEC_CONST unsigned short FB_MC_BR_InitParTabObj = 17U;
 _IEC_CONST unsigned short FB_MC_BR_InitReceiveNetworkData = 115U;
 _IEC_CONST unsigned short FB_MC_BR_InitReceiveNetworkEnc = 141U;
 _IEC_CONST unsigned short FB_MC_BR_InitReceiveParID = 112U;
 _IEC_CONST unsigned short FB_MC_BR_InitSendParID = 111U;
 _IEC_CONST unsigned short FB_MC_BR_JogLimitPosition = 119U;
 _IEC_CONST unsigned short FB_MC_BR_JogTargetPosition = 120U;
 _IEC_CONST unsigned short FB_MC_BR_JogVelocity = 118U;
 _IEC_CONST unsigned short FB_MC_BR_LimitLoad = 134U;
 _IEC_CONST unsigned short FB_MC_BR_LimitLoadCam = 135U;
 _IEC_CONST unsigned short FB_MC_BR_LoadAxisPar = 56U;
 _IEC_CONST unsigned short FB_MC_BR_MechPosDeviationComp = 147U;
 _IEC_CONST unsigned short FB_MC_BR_MoveAbsoluteTriggStop = 18U;
 _IEC_CONST unsigned short FB_MC_BR_MoveAdditiveTriggStop = 19U;
 _IEC_CONST unsigned short FB_MC_BR_MoveCyclicPosition = 84U;
 _IEC_CONST unsigned short FB_MC_BR_MoveCyclicPositionExt = 124U;
 _IEC_CONST unsigned short FB_MC_BR_MoveCyclicVelocity = 92U;
 _IEC_CONST unsigned short FB_MC_BR_MoveCyclicVelocityExt = 125U;
 _IEC_CONST unsigned short FB_MC_BR_MoveVelocityTriggStop = 20U;
 _IEC_CONST unsigned short FB_MC_BR_NetTrace = 78U;
 _IEC_CONST unsigned short FB_MC_BR_NetworkInit = 139U;
 _IEC_CONST unsigned short FB_MC_BR_Offset = 58U;
 _IEC_CONST unsigned short FB_MC_BR_OffsetVelocity = 127U;
 _IEC_CONST unsigned short FB_MC_BR_OffsetZone = 128U;
 _IEC_CONST unsigned short FB_MC_BR_ParTrace = 80U;
 _IEC_CONST unsigned short FB_MC_BR_ParTraceConfig = 102U;
 _IEC_CONST unsigned short FB_MC_BR_Phasing = 59U;
 _IEC_CONST unsigned short FB_MC_BR_PowerMeter = 89U;
 _IEC_CONST unsigned short FB_MC_BR_ReadAutPosition = 75U;
 _IEC_CONST unsigned short FB_MC_BR_ReadAxisError = 105U;
 _IEC_CONST unsigned short FB_MC_BR_ReadCyclicPosition = 83U;
 _IEC_CONST unsigned short FB_MC_BR_ReadDriveStatus = 72U;
 _IEC_CONST unsigned short FB_MC_BR_ReadLoadSimInputData = 131U;
 _IEC_CONST unsigned short FB_MC_BR_ReadLoadSimTorque = 142U;
 _IEC_CONST unsigned short FB_MC_BR_ReadNetTraceStatus = 79U;
 _IEC_CONST unsigned short FB_MC_BR_ReadParID = 21U;
 _IEC_CONST unsigned short FB_MC_BR_ReadParIDText = 90U;
 _IEC_CONST unsigned short FB_MC_BR_ReadParList = 148U;
 _IEC_CONST unsigned short FB_MC_BR_ReadParTraceStatus = 81U;
 _IEC_CONST unsigned short FB_MC_BR_ReceiveParIDOnPLC = 113U;
 _IEC_CONST unsigned short FB_MC_BR_RegMarkCalc001 = 67U;
 _IEC_CONST unsigned short FB_MC_BR_RegMarkCapture001 = 66U;
 _IEC_CONST unsigned short FB_MC_BR_RegMarkCapture002 = 117U;
 _IEC_CONST unsigned short FB_MC_BR_ResetAutPar = 136U;
 _IEC_CONST unsigned short FB_MC_BR_SaveAxisPar = 55U;
 _IEC_CONST unsigned short FB_MC_BR_SaveCamProfileObj = 116U;
 _IEC_CONST unsigned short FB_MC_BR_SetHardwareInputs = 108U;
 _IEC_CONST unsigned short FB_MC_BR_SetupController = 88U;
 _IEC_CONST unsigned short FB_MC_BR_SetupFromParTabObj = 145U;
 _IEC_CONST unsigned short FB_MC_BR_SetupInductionMotor = 87U;
 _IEC_CONST unsigned short FB_MC_BR_SetupIsqRipple = 101U;
 _IEC_CONST unsigned short FB_MC_BR_SetupMotorPhasing = 97U;
 _IEC_CONST unsigned short FB_MC_BR_SetupSynchronMotor = 129U;
 _IEC_CONST unsigned short FB_MC_BR_Simulation = 71U;
 _IEC_CONST unsigned short FB_MC_BR_TorqueControl = 100U;
 _IEC_CONST unsigned short FB_MC_BR_TouchProbe = 60U;
 _IEC_CONST unsigned short FB_MC_BR_VelocityControl = 95U;
 _IEC_CONST unsigned short FB_MC_BR_WriteLoadSimOutputData = 132U;
 _IEC_CONST unsigned short FB_MC_BR_WriteLoadSimPosition = 143U;
 _IEC_CONST unsigned short FB_MC_BR_WriteLoadSimTorque = 144U;
 _IEC_CONST unsigned short FB_MC_BR_WriteLoadSimTwoEncPos = 149U;
 _IEC_CONST unsigned short FB_MC_BR_WriteParID = 22U;
 _IEC_CONST unsigned short FB_MC_BR_WriteParIDText = 91U;
 _IEC_CONST unsigned short FB_MC_CamIn = 23U;
 _IEC_CONST unsigned short FB_MC_CamOut = 24U;
 _IEC_CONST unsigned short FB_MC_CamTableSelect = 25U;
 _IEC_CONST unsigned short FB_MC_DigitalCamSwitch = 26U;
 _IEC_CONST unsigned short FB_MC_GearIn = 27U;
 _IEC_CONST unsigned short FB_MC_GearInPos = 28U;
 _IEC_CONST unsigned short FB_MC_GearOut = 29U;
 _IEC_CONST unsigned short FB_MC_Halt = 30U;
 _IEC_CONST unsigned short FB_MC_Home = 31U;
 _IEC_CONST unsigned short FB_MC_LimitLoad = 133U;
 _IEC_CONST unsigned short FB_MC_MoveAbsolute = 32U;
 _IEC_CONST unsigned short FB_MC_MoveAdditive = 33U;
 _IEC_CONST unsigned short FB_MC_MoveRelative = 34U;
 _IEC_CONST unsigned short FB_MC_MoveVelocity = 35U;
 _IEC_CONST unsigned short FB_MC_Phasing = 36U;
 _IEC_CONST unsigned short FB_MC_Power = 37U;
 _IEC_CONST unsigned short FB_MC_ReadActualPosition = 39U;
 _IEC_CONST unsigned short FB_MC_ReadActualTorque = 38U;
 _IEC_CONST unsigned short FB_MC_ReadActualVelocity = 40U;
 _IEC_CONST unsigned short FB_MC_ReadAxisError = 41U;
 _IEC_CONST unsigned short FB_MC_ReadBoolParameter = 42U;
 _IEC_CONST unsigned short FB_MC_ReadDigitalInput = 43U;
 _IEC_CONST unsigned short FB_MC_ReadDigitalOutput = 44U;
 _IEC_CONST unsigned short FB_MC_ReadParameter = 45U;
 _IEC_CONST unsigned short FB_MC_ReadStatus = 46U;
 _IEC_CONST unsigned short FB_MC_Reset = 47U;
 _IEC_CONST unsigned short FB_MC_SetOverride = 48U;
 _IEC_CONST unsigned short FB_MC_Stop = 49U;
 _IEC_CONST unsigned short FB_MC_TorqueControl = 96U;
 _IEC_CONST unsigned short FB_MC_TouchProbe = 50U;
 _IEC_CONST unsigned short FB_MC_WriteBoolParameter = 51U;
 _IEC_CONST unsigned short FB_MC_WriteDigitalOutput = 52U;
 _IEC_CONST unsigned short FB_MC_WriteParameter = 53U;
 _IEC_CONST unsigned short IO_2005 = 1152U;
 _IEC_CONST unsigned short IO_2010 = 1024U;
 _IEC_CONST unsigned short MC_InitFunction = 1U;
 _IEC_CONST unsigned short MOD_UPDATE = 32768U;
 _IEC_CONST unsigned char nc100KHZ = 1U;
 _IEC_CONST unsigned short nc154CAN = 5U;
 _IEC_CONST unsigned short nc156CAN = 6U;
 _IEC_CONST unsigned short nc157CAN = 9U;
 _IEC_CONST unsigned short nc158CAN = 7U;
 _IEC_CONST unsigned char nc20KHZ = 0U;
 _IEC_CONST unsigned short nc2ENCOD_SPEED = 5U;
 _IEC_CONST unsigned char ncA_LIMIT = 20U;
 _IEC_CONST unsigned char ncA_MOVE = 10U;
 _IEC_CONST unsigned char ncABORT_DATA = 8U;
 _IEC_CONST unsigned char ncABORT_LINE = 4U;
 _IEC_CONST unsigned char ncABOVE_WINDOW = 40U;
 _IEC_CONST unsigned char ncABS = 1U;
 _IEC_CONST unsigned short ncABS_MOVE = 132U;
 _IEC_CONST unsigned char ncABS_SWITCH = 2U;
 _IEC_CONST unsigned char ncABSOLUTE = 0U;
 _IEC_CONST unsigned char ncACCEL = 1U;
 _IEC_CONST unsigned short ncACK = 257U;
 _IEC_CONST unsigned short ncACKNOWLEDGE = 257U;
 _IEC_CONST unsigned char ncACOPOS_1 = 0U;
 _IEC_CONST unsigned char ncACOPOS_2 = 1U;
 _IEC_CONST unsigned short ncACOPOS_INFO = 322U;
 _IEC_CONST unsigned char ncACOPOS_P3 = 12U;
 _IEC_CONST unsigned char ncACOPOS_SDC = 128U;
 _IEC_CONST unsigned char ncACOPOS_SIM = 129U;
 _IEC_CONST unsigned char ncACOPOSmicro = 7U;
 _IEC_CONST unsigned char ncACOPOSmotor = 4U;
 _IEC_CONST unsigned char ncACOPOSmotor_C = 18U;
 _IEC_CONST unsigned char ncACOPOSmulti = 5U;
 _IEC_CONST unsigned char ncACOPOSmulti_PPS = 6U;
 _IEC_CONST unsigned char ncACOPOSmulti3 = 9U;
 _IEC_CONST unsigned char ncACOPOSmulti65 = 8U;
 _IEC_CONST unsigned char ncACOPOSmulti65m = 4U;
 _IEC_CONST unsigned char ncACOPOSremote = 8U;
 _IEC_CONST unsigned short ncACP_PAR = 401U;
 _IEC_CONST unsigned short ncACP_PAR_INIT_BRC_DP = 355U;
 _IEC_CONST unsigned short ncACP_PAR_INIT_BRC_DP64 = 354U;
 _IEC_CONST unsigned short ncACP_PAR_RECEIVE = 353U;
 _IEC_CONST unsigned short ncACP_PAR_SEND = 352U;
 _IEC_CONST unsigned char ncACP_SIM_COMPLETE = 2U;
 _IEC_CONST unsigned char ncACP_SIM_STANDARD = 1U;
 _IEC_CONST unsigned char ncACP_TYP_INV = 1U;
 _IEC_CONST unsigned char ncACP_TYP_PPS = 2U;
 _IEC_CONST unsigned char ncACP_TYP_PS = 0U;
 _IEC_CONST unsigned char ncACP_TYP_SDC = 128U;
 _IEC_CONST unsigned char ncACP_TYP_SIM = 129U;
 _IEC_CONST unsigned short ncACP10MAN = 32768U;
 _IEC_CONST unsigned short ncACP10USCOB = 255U;
 _IEC_CONST unsigned short ncACT_POS = 120U;
 _IEC_CONST unsigned char ncACTIV_HI = 1U;
 _IEC_CONST unsigned char ncACTIV_LO = 0U;
 _IEC_CONST unsigned short ncACTIVE = 1U;
 _IEC_CONST unsigned short ncADD_DATE_TIME = 1U;
 _IEC_CONST unsigned short ncAIL_DUMP = 220U;
 _IEC_CONST unsigned short ncALL = 373U;
 _IEC_CONST unsigned char ncANALOG = 0U;
 _IEC_CONST unsigned char ncAND_N2E = 15U;
 _IEC_CONST unsigned short ncARNC0MAN = 36864U;
 _IEC_CONST unsigned char ncAT_ONCE = 0U;
 _IEC_CONST unsigned char ncAUT_END = 10U;
 _IEC_CONST unsigned char ncAUTO = 1U;
 _IEC_CONST unsigned short ncAUTOMAT = 122U;
 _IEC_CONST unsigned char ncAUTOSAVE = 64U;
 _IEC_CONST unsigned short ncAXES = 213U;
 _IEC_CONST unsigned short ncAXIS = 1U;
 _IEC_CONST unsigned char ncBASIS = 1U;
 _IEC_CONST unsigned short ncBASIS_MOVE = 130U;
 _IEC_CONST unsigned short ncBASIS_TRG_STOP = 137U;
 _IEC_CONST unsigned char ncBELOW_WINDOW = 50U;
 _IEC_CONST unsigned char ncBIDIR = 4U;
 _IEC_CONST unsigned char ncBINARY = 1U;
 _IEC_CONST unsigned short ncBIQUAD = 9U;
 _IEC_CONST unsigned char ncBISS = 9U;
 _IEC_CONST unsigned char ncBL = 1U;
 _IEC_CONST unsigned short ncBLOCK = 202U;
 _IEC_CONST unsigned char ncBLOCK_DS = 10U;
 _IEC_CONST unsigned char ncBLOCK_TORQUE = 9U;
 _IEC_CONST unsigned short ncBLOCKMON = 371U;
 _IEC_CONST unsigned char ncBLOCKMONITOR = 4U;
 _IEC_CONST unsigned char ncBLOCKNUMBER = 1U;
 _IEC_CONST unsigned short ncBLOCKSEARCH = 277U;
 _IEC_CONST unsigned short ncBRAKE = 171U;
 _IEC_CONST unsigned short ncBREAK = 2U;
 _IEC_CONST unsigned short ncBREAKPOINT = 370U;
 _IEC_CONST unsigned short ncBURN = 340U;
 _IEC_CONST unsigned char ncBYTEOFFSET = 3U;
 _IEC_CONST unsigned short ncCALCULATION = 11U;
 _IEC_CONST unsigned char ncCAM_BEG = 6U;
 _IEC_CONST unsigned short ncCAM_PROF = 117U;
 _IEC_CONST unsigned char ncCAMPRDAT = 24U;
 _IEC_CONST unsigned char ncCAMPRPOL = 25U;
 _IEC_CONST unsigned char ncCAMPRPOL_ACOPOS = 27U;
 _IEC_CONST unsigned short ncCAN_IF = 0U;
 _IEC_CONST unsigned char ncCLOSED = 1U;
 _IEC_CONST unsigned short ncCMD_ERROR = 281U;
 _IEC_CONST unsigned short ncCMD_ERROR_COAST_TO_STANDSTILL = 5U;
 _IEC_CONST unsigned short ncCMD_ERROR_INDUCTION_HALT = 6U;
 _IEC_CONST unsigned short ncCMD_ERROR_ONLY = 1U;
 _IEC_CONST unsigned short ncCMD_ERROR_STOP = 2U;
 _IEC_CONST unsigned short ncCMD_ERROR_STOP_CTRL_OFF = 3U;
 _IEC_CONST unsigned short ncCMD_ERROR_V_STOP_CTRL_OFF = 4U;
 _IEC_CONST unsigned short ncCMD_WARNING_ONLY = 0U;
 _IEC_CONST unsigned char ncCNC = 0U;
 _IEC_CONST unsigned short ncCNC_C_AX = 199U;
 _IEC_CONST unsigned short ncCNC_PLC = 212U;
 _IEC_CONST unsigned char ncCNC_PROG = 20U;
 _IEC_CONST unsigned short ncCNCSYS = 2U;
 _IEC_CONST unsigned short ncCOMP = 125U;
 _IEC_CONST unsigned char ncCOMP_ERR = 14U;
 _IEC_CONST unsigned short ncCOMPAR = 115U;
 _IEC_CONST unsigned short ncCONTINUE = 263U;
 _IEC_CONST unsigned short ncCONTINUE_ = 263U;
 _IEC_CONST unsigned short ncCONTROL = 105U;
 _IEC_CONST unsigned short ncCONTROLLER = 105U;
 _IEC_CONST unsigned char ncCORRECTION = 128U;
 _IEC_CONST unsigned char ncCOUNT = 11U;
 _IEC_CONST unsigned short ncCOUPLING = 274U;
 _IEC_CONST unsigned char ncCSTRF = 1U;
 _IEC_CONST unsigned char ncCTRL_OFF = 50U;
 _IEC_CONST unsigned short ncCYCL_USER_FRDRV = 257U;
 _IEC_CONST unsigned short ncCYCL_USER_FRDRV_AT_STARTUP = 259U;
 _IEC_CONST unsigned short ncCYCL_USER_TODRV = 256U;
 _IEC_CONST unsigned short ncCYCL_USER_TODRV_AT_STARTUP = 258U;
 _IEC_CONST unsigned char ncCYCLIC = 8U;
 _IEC_CONST unsigned char ncD_POS = 13U;
 _IEC_CONST unsigned short ncD_SINGLE = 207U;
 _IEC_CONST unsigned short ncDAT_MOD = 301U;
 _IEC_CONST unsigned char ncDATA = 0U;
 _IEC_CONST unsigned short ncDATA_TEXT = 1024U;
 _IEC_CONST unsigned short ncDATBLOCK = 162U;
 _IEC_CONST unsigned char ncDATMOD_ACP_CAM_POLY = 27U;
 _IEC_CONST unsigned char ncDATMOD_ACP_PAR = 16U;
 _IEC_CONST unsigned char ncDATMOD_ACP_PAR_TRACE = 31U;
 _IEC_CONST unsigned char ncDATMOD_CNC_CAM_POLY = 25U;
 _IEC_CONST unsigned char ncDATMOD_CNC_CAM_TAB = 24U;
 _IEC_CONST unsigned char ncDATMOD_CNC_PROG = 20U;
 _IEC_CONST unsigned char ncDATMOD_CNC_R_PAR = 23U;
 _IEC_CONST unsigned char ncDATMOD_CNC_TOOL = 22U;
 _IEC_CONST unsigned char ncDATMOD_DATBLOCK = 33U;
 _IEC_CONST unsigned char ncDATMOD_NC_MAPPING = 28U;
 _IEC_CONST unsigned char ncDATMOD_NET_TRACE = 30U;
 _IEC_CONST unsigned char ncDATMOD_ZERO_P_OFF = 21U;
 _IEC_CONST unsigned short ncDATOBJ_BRMOD = 0U;
 _IEC_CONST unsigned short ncDATOBJ_BRMOD_DEFAULT = 65535U;
 _IEC_CONST unsigned short ncDATOBJ_FILE = 1U;
 _IEC_CONST unsigned short ncDATOBJ_FORMAT_BIN = 0U;
 _IEC_CONST unsigned short ncDATOBJ_FORMAT_CSV = 1U;
 _IEC_CONST unsigned short ncDATOBJ_FORMAT_TXT = 2U;
 _IEC_CONST unsigned char ncDCM = 7U;
 _IEC_CONST unsigned char ncDECEL = 4U;
 _IEC_CONST unsigned short ncDECODER = 206U;
 _IEC_CONST unsigned short ncDEFINE = 369U;
 _IEC_CONST unsigned short ncDELETE = 342U;
 _IEC_CONST unsigned short ncDIAGNOSE = 321U;
 _IEC_CONST unsigned short ncDIG_IN = 102U;
 _IEC_CONST unsigned char ncDIRECT = 0U;
 _IEC_CONST unsigned short ncDM16BIT = 8192U;
 _IEC_CONST unsigned char ncDNC = 2U;
 _IEC_CONST unsigned short ncDOWNLOAD = 339U;
 _IEC_CONST unsigned short ncDPR_OVR = 217U;
 _IEC_CONST unsigned short ncDPR_TRACE = 306U;
 _IEC_CONST unsigned char ncDRAM = 65U;
 _IEC_CONST unsigned short ncDRIVE = 166U;
 _IEC_CONST unsigned short ncDRIVE_ID = 123U;
 _IEC_CONST unsigned short ncDRIVE_IF = 104U;
 _IEC_CONST unsigned char ncDRIVE_READY = 255U;
 _IEC_CONST unsigned long ncDV_STOP_AUTO1 = 2U;
 _IEC_CONST unsigned long ncDV_STOP_AUTO2 = 3U;
 _IEC_CONST unsigned long ncDV_STOP_INIT = 1U;
 _IEC_CONST unsigned short ncE_STOP = 262U;
 _IEC_CONST unsigned char ncEDGE2 = 12U;
 _IEC_CONST unsigned short ncEMPTY = 0U;
 _IEC_CONST unsigned short ncENABLE = 170U;
 _IEC_CONST unsigned short ncENCOD_IF = 103U;
 _IEC_CONST unsigned short ncENCODER_IF = 103U;
 _IEC_CONST unsigned char ncEND_SWITCH = 4U;
 _IEC_CONST unsigned char ncENDAT = 4U;
 _IEC_CONST unsigned char ncENDAT_SafeMOTION = 14U;
 _IEC_CONST unsigned char ncENDAT3 = 16U;
 _IEC_CONST unsigned short ncENGLISH = 1U;
 _IEC_CONST unsigned char ncENTRY = 4U;
 _IEC_CONST unsigned char ncEPROM = 2U;
 _IEC_CONST unsigned short ncERR_CL0 = 215U;
 _IEC_CONST unsigned short ncERROR = 1U;
 _IEC_CONST unsigned char ncETEL = 2U;
 _IEC_CONST unsigned char ncEVEN = 3U;
 _IEC_CONST unsigned short ncEVENT = 136U;
 _IEC_CONST unsigned short ncEX_PARAM = 214U;
 _IEC_CONST unsigned short ncEXECUTE = 374U;
 _IEC_CONST unsigned short ncEXPRESSION = 375U;
 _IEC_CONST unsigned short ncEXTENCOD = 8U;
 _IEC_CONST unsigned char ncEXTERN = 128U;
 _IEC_CONST unsigned char ncFALSE = 0U;
 _IEC_CONST unsigned char ncFC = 1U;
 _IEC_CONST unsigned char ncFF = 32U;
 _IEC_CONST unsigned short ncFF_NEG_MOVE = 34U;
 _IEC_CONST unsigned short ncFF_POS_MOVE = 33U;
 _IEC_CONST unsigned char ncFILE = 3U;
 _IEC_CONST unsigned char ncFILE_XL = 1U;
 _IEC_CONST unsigned char ncFILEOFFSET = 0U;
 _IEC_CONST unsigned short ncFINISH = 282U;
 _IEC_CONST unsigned char ncFIXRAM = 5U;
 _IEC_CONST unsigned short ncFORCE = 288U;
 _IEC_CONST unsigned short ncFORMAT_ADR = 0U;
 _IEC_CONST unsigned short ncFORMAT_B06 = 2U;
 _IEC_CONST unsigned short ncFORMAT_T10 = 1U;
 _IEC_CONST unsigned short ncFORMAT_T14 = 3U;
 _IEC_CONST unsigned char ncG00 = 0U;
 _IEC_CONST unsigned char ncG01 = 1U;
 _IEC_CONST unsigned char ncG02 = 2U;
 _IEC_CONST unsigned char ncG03 = 3U;
 _IEC_CONST unsigned char ncGANTRY = 1U;
 _IEC_CONST unsigned char ncGATE = 1U;
 _IEC_CONST unsigned short ncGEARS = 111U;
 _IEC_CONST unsigned short ncGEARS_V = 116U;
 _IEC_CONST unsigned short ncGEARSABS = 124U;
 _IEC_CONST unsigned short ncGERMAN = 0U;
 _IEC_CONST unsigned short ncGETINFO = 376U;
 _IEC_CONST unsigned short ncGLOBAL = 4U;
 _IEC_CONST unsigned long ncglobal_action_ACP10MSG_TEXT = 5U;
 _IEC_CONST unsigned long ncglobal_action_NCDA_CREATE = 1U;
 _IEC_CONST unsigned long ncglobal_action_NCDA_DIR = 4U;
 _IEC_CONST unsigned long ncglobal_action_NCDA_INFO = 2U;
 _IEC_CONST unsigned long ncglobal_action_NCDA_WRITE = 3U;
 _IEC_CONST unsigned short ncGO_HOME = 106U;
 _IEC_CONST unsigned char ncGRAY = 0U;
 _IEC_CONST unsigned short ncHALT = 219U;
 _IEC_CONST unsigned char ncHALT_ERR = 32U;
 _IEC_CONST unsigned char ncHALT_EXEC_ERR = 64U;
 _IEC_CONST unsigned short ncHALT_OK = 135U;
 _IEC_CONST unsigned char ncHALT_PLC = 4U;
 _IEC_CONST unsigned char ncHALT_POS = 8U;
 _IEC_CONST unsigned char ncHALT_PRG = 2U;
 _IEC_CONST unsigned char ncHALT_RST = 16U;
 _IEC_CONST unsigned char ncHALT_SST = 1U;
 _IEC_CONST unsigned char ncHIGH = 1U;
 _IEC_CONST unsigned char ncHIPERFACE = 8U;
 _IEC_CONST unsigned char ncHIPERFACE_DSL = 13U;
 _IEC_CONST unsigned char ncHOME_OFFSET = 5U;
 _IEC_CONST unsigned short ncHOMING = 106U;
 _IEC_CONST unsigned char ncHORIZONTAL = 0U;
 _IEC_CONST unsigned short ncHW_END = 4096U;
 _IEC_CONST unsigned char ncI_LIMIT = 30U;
 _IEC_CONST unsigned short ncIDENTIFICATION = 10U;
 _IEC_CONST unsigned char ncIN_WINDOW = 20U;
 _IEC_CONST unsigned char ncINC = 2U;
 _IEC_CONST unsigned char ncINC_COMP = 252U;
 _IEC_CONST unsigned char ncINC_OUTPUT = 7U;
 _IEC_CONST unsigned char ncINC_SSI = 10U;
 _IEC_CONST unsigned char ncINCH = 1U;
 _IEC_CONST unsigned char ncINCLUDE = 2U;
 _IEC_CONST unsigned char ncINDIRECT = 255U;
 _IEC_CONST unsigned char ncINDRAMAT = 0U;
 _IEC_CONST unsigned char ncINDUCTION = 40U;
 _IEC_CONST unsigned short ncINFO = 268U;
 _IEC_CONST unsigned short ncINIT = 512U;
 _IEC_CONST unsigned char ncINIT_SET_POS = 6U;
 _IEC_CONST unsigned char ncINTERPRETER = 41U;
 _IEC_CONST unsigned char ncINVERSE = 255U;
 _IEC_CONST unsigned short ncIP_INFO_AS_WARNING = 222U;
 _IEC_CONST unsigned short ncIPGLOBAL = 385U;
 _IEC_CONST unsigned short ncISQ_F1_LOW_PASS = 1024U;
 _IEC_CONST unsigned short ncISQ_F1_NOTCH = 128U;
 _IEC_CONST unsigned short ncISQ_F2_LOW_PASS = 2048U;
 _IEC_CONST unsigned short ncISQ_F2_NOTCH = 256U;
 _IEC_CONST unsigned short ncISQ_F3_LOW_PASS = 4096U;
 _IEC_CONST unsigned short ncISQ_F3_NOTCH = 512U;
 _IEC_CONST unsigned short ncISQ_RIPPLE = 144U;
 _IEC_CONST unsigned short ncISQF_COMP = 6U;
 _IEC_CONST unsigned short ncISQF_LIM = 5U;
 _IEC_CONST unsigned short ncISQF_LIM2 = 7U;
 _IEC_CONST unsigned short ncISQF_LIM3 = 4U;
 _IEC_CONST unsigned short ncISQF_TRQ_ADDLIM = 8U;
 _IEC_CONST unsigned short ncISQR_MODE_A_PHI = 20U;
 _IEC_CONST unsigned char ncISQR_REF_SYSTEM_ENCODER = 0U;
 _IEC_CONST unsigned char ncISQR_REF_SYSTEM_FLUX = 1U;
 _IEC_CONST unsigned char ncLAG_ERR = 2U;
 _IEC_CONST unsigned short ncLATCH1 = 108U;
 _IEC_CONST unsigned short ncLATCH2 = 109U;
 _IEC_CONST unsigned char ncLATCHPOS = 32U;
 _IEC_CONST unsigned char ncLEFT = 2U;
 _IEC_CONST unsigned short ncLIMITER = 114U;
 _IEC_CONST unsigned short ncLIMITS = 2U;
 _IEC_CONST unsigned short ncLINE = 372U;
 _IEC_CONST unsigned char ncLINEAR = 1U;
 _IEC_CONST unsigned char ncLINEAR2 = 3U;
 _IEC_CONST unsigned char ncLINENUMBER = 4U;
 _IEC_CONST unsigned short ncLINK = 343U;
 _IEC_CONST unsigned char ncLINMOT = 11U;
 _IEC_CONST unsigned short ncLOAD = 276U;
 _IEC_CONST unsigned short ncLOAD_ABORT = 278U;
 _IEC_CONST unsigned char ncLOW = 0U;
 _IEC_CONST unsigned short ncLOW_PASS = 1U;
 _IEC_CONST unsigned short ncM_GRP_TAB = 126U;
 _IEC_CONST unsigned short ncM1_STOP = 203U;
 _IEC_CONST unsigned char ncMA_LATCHPOS = 32U;
 _IEC_CONST unsigned short ncMA_S_START_I32 = 2048U;
 _IEC_CONST unsigned char ncMA_SL_ABS = 40U;
 _IEC_CONST unsigned short ncMA_TO_SL = 16384U;
 _IEC_CONST unsigned short ncMA_V_COMP = 32768U;
 _IEC_CONST unsigned char ncMAGNESCALE = 12U;
 _IEC_CONST signed long ncMAINPROG = -1;
 _IEC_CONST unsigned char ncMC_STATE_CONTINUOUS_MOTION = 7U;
 _IEC_CONST unsigned char ncMC_STATE_DISABLED = 1U;
 _IEC_CONST unsigned char ncMC_STATE_DISCRETE_MOTION = 6U;
 _IEC_CONST unsigned char ncMC_STATE_ERROR = 10U;
 _IEC_CONST unsigned char ncMC_STATE_ERRORSTOP = 4U;
 _IEC_CONST unsigned char ncMC_STATE_GroupDisabled = 6U;
 _IEC_CONST unsigned char ncMC_STATE_GroupErrorstop = 3U;
 _IEC_CONST unsigned char ncMC_STATE_GroupHoming = 2U;
 _IEC_CONST unsigned char ncMC_STATE_GroupMoving = 1U;
 _IEC_CONST unsigned char ncMC_STATE_GroupStandby = 4U;
 _IEC_CONST unsigned char ncMC_STATE_GroupStopping = 5U;
 _IEC_CONST unsigned char ncMC_STATE_HOMING = 3U;
 _IEC_CONST unsigned char ncMC_STATE_MOTION = 9U;
 _IEC_CONST unsigned char ncMC_STATE_NET_INIT = 0U;
 _IEC_CONST unsigned char ncMC_STATE_STANDSTILL = 2U;
 _IEC_CONST unsigned char ncMC_STATE_STOPPING = 5U;
 _IEC_CONST unsigned char ncMC_STATE_SYNCHRONIZED_MOTION = 8U;
 _IEC_CONST unsigned char ncMEMCARD = 4U;
 _IEC_CONST unsigned short ncMESSAGE = 1U;
 _IEC_CONST unsigned char ncMM = 0U;
 _IEC_CONST unsigned char ncMOD_DIR = 128U;
 _IEC_CONST unsigned short ncMOD_SYNC = 303U;
 _IEC_CONST unsigned short ncMODEL_1MASS = 4U;
 _IEC_CONST unsigned short ncMODEL_2MASS = 3U;
 _IEC_CONST unsigned short ncMODULE = 3U;
 _IEC_CONST unsigned short ncMOTOR = 140U;
 _IEC_CONST unsigned short ncMOTOR_INDUCTION = 141U;
 _IEC_CONST unsigned char ncMOTOR_PAR = 1U;
 _IEC_CONST unsigned short ncMOTOR_PHASING = 143U;
 _IEC_CONST unsigned short ncMOTOR_SYNCHRON = 142U;
 _IEC_CONST unsigned short ncMOTPH_DITHER = 32U;
 _IEC_CONST unsigned short ncMOTPH_SATURATION = 30U;
 _IEC_CONST unsigned short ncMOTPH_SET_OFFSET = 34U;
 _IEC_CONST unsigned short ncMOTPH_STEPPER = 31U;
 _IEC_CONST unsigned short ncMOVE = 3U;
 _IEC_CONST unsigned char ncMOVE_BEG = 1U;
 _IEC_CONST unsigned char ncMOVE_CMD = 5U;
 _IEC_CONST unsigned char ncMOVE_END = 2U;
 _IEC_CONST unsigned short ncMP_LOG = 221U;
 _IEC_CONST unsigned short ncMTC = 305U;
 _IEC_CONST unsigned short ncMULTI_AX_TRACE = 11U;
 _IEC_CONST unsigned char ncN_EDGE = 1U;
 _IEC_CONST unsigned char ncN_PERIOD = 1U;
 _IEC_CONST unsigned char ncN_THRESH = 4U;
 _IEC_CONST unsigned short ncNC_SYS_RESTART = 32768U;
 _IEC_CONST unsigned char ncNCBLOCKNO = 22U;
 _IEC_CONST unsigned short ncNCGLOBAL = 384U;
 _IEC_CONST unsigned short ncNCPR_POS = 218U;
 _IEC_CONST unsigned char ncNCRECNO = 22U;
 _IEC_CONST unsigned short ncNEG_MOVE = 133U;
 _IEC_CONST unsigned char ncNEG_THRESH = 2U;
 _IEC_CONST unsigned char ncNEGATIVE = 1U;
 _IEC_CONST unsigned short ncNET_GLOBAL = 12U;
 _IEC_CONST unsigned short ncNET_TRACE = 404U;
 _IEC_CONST unsigned short ncNETWORK = 403U;
 _IEC_CONST unsigned char ncNO_CHECK = 30U;
 _IEC_CONST unsigned short ncNO_NET_TRACE = 32768U;
 _IEC_CONST unsigned char ncNOFEED = 64U;
 _IEC_CONST unsigned char ncNOSTOP = 16U;
 _IEC_CONST unsigned short ncNOTCH = 2U;
 _IEC_CONST unsigned char ncNP_EDGE = 11U;
 _IEC_CONST unsigned short ncOBJ_PTR = 64U;
 _IEC_CONST unsigned char ncODD = 2U;
 _IEC_CONST unsigned char ncOFF = 0U;
 _IEC_CONST unsigned short ncOK = 0U;
 _IEC_CONST unsigned char ncON = 1U;
 _IEC_CONST unsigned short ncONL_POS = 107U;
 _IEC_CONST unsigned short ncONL_V = 113U;
 _IEC_CONST unsigned char ncONLYCOMP = 30U;
 _IEC_CONST unsigned char ncONLYCOMP_DIRECT = 35U;
 _IEC_CONST unsigned char ncONTHEFLY = 3U;
 _IEC_CONST unsigned char ncOPEN = 0U;
 _IEC_CONST unsigned char ncOUT_WINDOW = 30U;
 _IEC_CONST unsigned char ncP_EDGE = 0U;
 _IEC_CONST unsigned char ncP_LATCH1 = 1U;
 _IEC_CONST unsigned char ncP_LATCH2 = 2U;
 _IEC_CONST unsigned char ncP_THRESH = 3U;
 _IEC_CONST unsigned char ncPACSI = 1U;
 _IEC_CONST unsigned char ncPAR_ID = 16U;
 _IEC_CONST unsigned char ncPAR_ID1 = 16U;
 _IEC_CONST unsigned char ncPAR_ID2 = 17U;
 _IEC_CONST unsigned char ncPAR_ID3 = 18U;
 _IEC_CONST unsigned char ncPAR_ID4 = 19U;
 _IEC_CONST unsigned short ncPAR_LIST = 402U;
 _IEC_CONST unsigned short ncPAR_LIST_MOVE = 16384U;
 _IEC_CONST unsigned short ncPAR_SEQU = 400U;
 _IEC_CONST unsigned short ncPAR_TYP_BOOL = 1U;
 _IEC_CONST unsigned short ncPAR_TYP_BRMOD = 14U;
 _IEC_CONST unsigned short ncPAR_TYP_BYTES = 11U;
 _IEC_CONST unsigned short ncPAR_TYP_DATA = 13U;
 _IEC_CONST unsigned short ncPAR_TYP_DINT = 4U;
 _IEC_CONST unsigned short ncPAR_TYP_GRP = 12U;
 _IEC_CONST unsigned short ncPAR_TYP_INT = 3U;
 _IEC_CONST unsigned short ncPAR_TYP_LREAL = 17U;
 _IEC_CONST unsigned short ncPAR_TYP_NIL = 0U;
 _IEC_CONST unsigned short ncPAR_TYP_REAL = 8U;
 _IEC_CONST unsigned short ncPAR_TYP_SINT = 2U;
 _IEC_CONST unsigned short ncPAR_TYP_STR16 = 4106U;
 _IEC_CONST unsigned short ncPAR_TYP_STR32 = 8202U;
 _IEC_CONST unsigned short ncPAR_TYP_T5 = 9U;
 _IEC_CONST unsigned short ncPAR_TYP_UDINT = 7U;
 _IEC_CONST unsigned short ncPAR_TYP_UINT = 6U;
 _IEC_CONST unsigned short ncPAR_TYP_USINT = 5U;
 _IEC_CONST unsigned short ncPAR_TYP_VOID = 65535U;
 _IEC_CONST unsigned short ncPAR_TYP_VOID_NO_NET_TRACE = 65534U;
 _IEC_CONST unsigned short ncPARID_TRACE = 10U;
 _IEC_CONST unsigned short ncPASSIVE = 4U;
 _IEC_CONST unsigned short ncPATH = 386U;
 _IEC_CONST unsigned char ncPATHDISTANCE = 0U;
 _IEC_CONST unsigned char ncPI_PRED = 0U;
 _IEC_CONST unsigned short ncPLC_ITR = 302U;
 _IEC_CONST unsigned char ncPN_EDGE = 10U;
 _IEC_CONST unsigned char ncPOLAR_PHI = 8U;
 _IEC_CONST unsigned char ncPOLAR_RAD = 4U;
 _IEC_CONST unsigned char ncPOS_ERR = 4U;
 _IEC_CONST unsigned short ncPOS_MOVE = 134U;
 _IEC_CONST unsigned char ncPOS_THRESH = 1U;
 _IEC_CONST unsigned char ncPOSITION = 1U;
 _IEC_CONST unsigned char ncPOSITIVE = 0U;
 _IEC_CONST unsigned short ncPOSMON = 216U;
 _IEC_CONST unsigned short ncPOWERLINK_IF = 1U;
 _IEC_CONST unsigned char ncPRELOAD = 4U;
 _IEC_CONST unsigned short ncPROGRAM = 201U;
 _IEC_CONST unsigned char ncPULL = 2U;
 _IEC_CONST unsigned char ncPUSH = 1U;
 _IEC_CONST unsigned char ncPUSHPULL = 0U;
 _IEC_CONST unsigned char ncQUADRATIC = 2U;
 _IEC_CONST unsigned char ncQUADRATIC_NO_OVERSHOOT = 4U;
 _IEC_CONST unsigned char ncQUICKSTOP = 2U;
 _IEC_CONST unsigned char ncQUICKSTOP_T_JOLT = 2U;
 _IEC_CONST unsigned char ncR_PAR = 23U;
 _IEC_CONST unsigned short ncR_PARAM = 211U;
 _IEC_CONST unsigned short ncR_PARTAB = 210U;
 _IEC_CONST unsigned char ncR_PULSE = 2U;
 _IEC_CONST unsigned char ncRAM = 1U;
 _IEC_CONST unsigned short ncREAD = 265U;
 _IEC_CONST unsigned short ncREAD_COB = 321U;
 _IEC_CONST unsigned short ncRECORD = 202U;
 _IEC_CONST unsigned short ncREL_MOVE = 131U;
 _IEC_CONST unsigned short ncREL_POS = 119U;
 _IEC_CONST unsigned char ncRELATIVE = 1U;
 _IEC_CONST unsigned short ncRELEASE = 387U;
 _IEC_CONST unsigned char ncREPLACE = 1U;
 _IEC_CONST unsigned short ncRESET = 320U;
 _IEC_CONST unsigned char ncRESOLVER = 5U;
 _IEC_CONST unsigned short ncRESTART = 273U;
 _IEC_CONST unsigned char ncRESTORE_POS = 8U;
 _IEC_CONST unsigned char ncRIGHT = 3U;
 _IEC_CONST unsigned short ncRING_STARTIDX = 4096U;
 _IEC_CONST unsigned char ncROTARY = 32U;
 _IEC_CONST unsigned char ncS_ACT = 11U;
 _IEC_CONST unsigned short ncS_ACT_TO_S_SET = 279U;
 _IEC_CONST unsigned char ncS_JUMP_T = 8U;
 _IEC_CONST unsigned char ncS_MOTOR = 1U;
 _IEC_CONST unsigned char ncS_NCBLOCK = 23U;
 _IEC_CONST unsigned char ncS_NCBLOCK_N1 = 25U;
 _IEC_CONST unsigned char ncS_NCBLOCK_TOT = 24U;
 _IEC_CONST unsigned char ncS_NCPROG = 21U;
 _IEC_CONST unsigned short ncS_REST = 4096U;
 _IEC_CONST unsigned char ncS_SET = 10U;
 _IEC_CONST unsigned char ncS_SET_COMP = 16U;
 _IEC_CONST unsigned char ncS_START = 10U;
 _IEC_CONST unsigned char ncS_START_IV1 = 41U;
 _IEC_CONST unsigned char ncS_START_IV2 = 42U;
 _IEC_CONST unsigned char ncS_START_IV3 = 43U;
 _IEC_CONST unsigned char ncS_START_IV4 = 44U;
 _IEC_CONST unsigned short ncSAVE = 341U;
 _IEC_CONST unsigned char ncSBL_CONTROL = 2U;
 _IEC_CONST unsigned short ncSCALE = 180U;
 _IEC_CONST unsigned short ncSDC_IF = 129U;
 _IEC_CONST unsigned short ncSEND = 368U;
 _IEC_CONST unsigned char ncSERCOS = 2U;
 _IEC_CONST unsigned char ncSERCOS_LIN = 128U;
 _IEC_CONST unsigned short ncSERCOSIF = 310U;
 _IEC_CONST unsigned short ncSERVICE = 165U;
 _IEC_CONST unsigned short ncSET = 264U;
 _IEC_CONST unsigned short ncSET_GEN_ONLY = 1024U;
 _IEC_CONST unsigned short ncSETUP = 16384U;
 _IEC_CONST unsigned short ncSETUP_MOVE_T_JOLT = 16U;
 _IEC_CONST unsigned char ncSHORT_PATH = 1U;
 _IEC_CONST unsigned short ncSIG_LINE = 110U;
 _IEC_CONST unsigned char ncSIGNAL = 4U;
 _IEC_CONST unsigned short ncSIGNAL_CHIRP = 1U;
 _IEC_CONST unsigned short ncSIGNAL_CHIRP_TRAPEZOID = 2U;
 _IEC_CONST unsigned short ncSIGNAL_PRBS = 0U;
 _IEC_CONST unsigned char ncSIGNAL1 = 91U;
 _IEC_CONST unsigned char ncSIGNAL2 = 92U;
 _IEC_CONST unsigned char ncSIGNAL3 = 93U;
 _IEC_CONST unsigned char ncSIGNAL4 = 94U;
 _IEC_CONST unsigned short ncSIM_1MASS = 1U;
 _IEC_CONST unsigned short ncSIM_1MASS_AUTO = 0U;
 _IEC_CONST unsigned short ncSIM_1MASS_GEAR = 3U;
 _IEC_CONST unsigned short ncSIM_2MASS = 2U;
 _IEC_CONST unsigned short ncSIM_2MASS_GEAR = 4U;
 _IEC_CONST unsigned char ncSIM_START = 127U;
 _IEC_CONST unsigned short ncSIMULAT = 150U;
 _IEC_CONST unsigned short ncSIMULATION = 150U;
 _IEC_CONST unsigned short ncSINGLE = 204U;
 _IEC_CONST unsigned short ncSKIP_FCN = 205U;
 _IEC_CONST unsigned char ncSKIP_PARSE = 10U;
 _IEC_CONST unsigned char ncSL_ABS = 33U;
 _IEC_CONST unsigned char ncSL_LATCHPOS = 34U;
 _IEC_CONST unsigned char ncSPEED = 2U;
 _IEC_CONST unsigned short ncSPOSSTDZ = 160U;
 _IEC_CONST unsigned char ncSSE = 2U;
 _IEC_CONST unsigned char ncSSI = 6U;
 _IEC_CONST unsigned char ncSSI_CONT_TYP_END = 0U;
 _IEC_CONST unsigned char ncSSI_CONT_TYP_ERR = 2U;
 _IEC_CONST unsigned char ncSSI_CONT_TYP_ERR_INV = 3U;
 _IEC_CONST unsigned char ncSSI_CONT_TYP_FILL = 6U;
 _IEC_CONST unsigned char ncSSI_CONT_TYP_POS = 1U;
 _IEC_CONST unsigned char ncSSI_CONT_TYP_WRN = 4U;
 _IEC_CONST unsigned char ncSSI_CONT_TYP_WRN_INV = 5U;
 _IEC_CONST unsigned char ncSSI_PARITY_CHK_EVEN = 6U;
 _IEC_CONST unsigned char ncSSI_PARITY_CHK_ODD = 7U;
 _IEC_CONST unsigned char ncSSI_SEND = 3U;
 _IEC_CONST unsigned char ncST_CAMPR = 2U;
 _IEC_CONST unsigned char ncST_COMP = 4U;
 _IEC_CONST unsigned char ncST_END = 12U;
 _IEC_CONST unsigned char ncSTANDARD = 0U;
 _IEC_CONST unsigned short ncSTART = 260U;
 _IEC_CONST unsigned short ncSTART_CG = 269U;
 _IEC_CONST unsigned short ncSTART_CYC_TRACE_CTRL_BITS = 289U;
 _IEC_CONST unsigned short ncSTART_IV = 270U;
 _IEC_CONST unsigned short ncSTART_NETWORK_REQU_PARCMD = 280U;
 _IEC_CONST unsigned short ncSTART_T = 275U;
 _IEC_CONST unsigned short ncSTARTABS = 272U;
 _IEC_CONST unsigned short ncSTARTDIR = 267U;
 _IEC_CONST unsigned char ncSTATE = 128U;
 _IEC_CONST unsigned char ncSTEP_INTO = 221U;
 _IEC_CONST unsigned char ncSTEP_OVER = 220U;
 _IEC_CONST unsigned short ncSTOP = 261U;
 _IEC_CONST unsigned char ncSW_END = 1U;
 _IEC_CONST unsigned short ncSW_OFF = 259U;
 _IEC_CONST unsigned short ncSW_ON = 258U;
 _IEC_CONST unsigned char ncSWITCH = 2U;
 _IEC_CONST unsigned char ncSWITCH_GATE = 1U;
 _IEC_CONST unsigned short ncSWITCH_OFF = 259U;
 _IEC_CONST unsigned short ncSWITCH_ON = 258U;
 _IEC_CONST unsigned short ncSYNC = 266U;
 _IEC_CONST unsigned char ncSYSROM = 0U;
 _IEC_CONST unsigned short ncT_FILTER = 64U;
 _IEC_CONST unsigned short ncT_FILTER_2 = 65U;
 _IEC_CONST unsigned char ncT_FORMAT = 15U;
 _IEC_CONST unsigned char ncT_JOLT = 1U;
 _IEC_CONST unsigned char ncT_TOTAL = 128U;
 _IEC_CONST unsigned char ncTANGENT = 2U;
 _IEC_CONST unsigned short ncTEST = 31U;
 _IEC_CONST unsigned short ncTEST_POSITION = 16386U;
 _IEC_CONST unsigned short ncTEST_SPEED = 16385U;
 _IEC_CONST unsigned short ncTEXT = 271U;
 _IEC_CONST unsigned char ncTHRESHLD = 0U;
 _IEC_CONST unsigned char ncTOOL = 22U;
 _IEC_CONST unsigned short ncTOOL_TAB = 209U;
 _IEC_CONST unsigned char ncTOOLDAT = 2U;
 _IEC_CONST unsigned char ncTR_DELAY = 6U;
 _IEC_CONST unsigned char ncTR_END = 1U;
 _IEC_CONST unsigned char ncTR_REST = 5U;
 _IEC_CONST unsigned char ncTR_RING = 4U;
 _IEC_CONST unsigned char ncTR_SAVE = 7U;
 _IEC_CONST unsigned char ncTR_SDM = 21U;
 _IEC_CONST unsigned char ncTR_START = 20U;
 _IEC_CONST unsigned char ncTR_TRACE = 2U;
 _IEC_CONST unsigned char ncTR_TRIGG = 3U;
 _IEC_CONST unsigned short ncTRACE = 304U;
 _IEC_CONST unsigned short ncTRACE_DAT_WR = 2050U;
 _IEC_CONST unsigned short ncTRACE_PAR_SEC_REC = 2048U;
 _IEC_CONST unsigned short ncTRG_STOP = 8192U;
 _IEC_CONST unsigned char ncTRG_STOP_NORMAL = 1U;
 _IEC_CONST unsigned char ncTRG_STOP_S_REST = 2U;
 _IEC_CONST unsigned short ncTRGPOS_S = 118U;
 _IEC_CONST unsigned char ncTRIGGER = 0U;
 _IEC_CONST unsigned char ncTRIGGER_2 = 6U;
 _IEC_CONST unsigned char ncTRIGGER1 = 20U;
 _IEC_CONST unsigned char ncTRIGGER2 = 22U;
 _IEC_CONST unsigned char ncTRIGGER3 = 24U;
 _IEC_CONST unsigned char ncTRIGGER4 = 26U;
 _IEC_CONST unsigned char ncTRIGGER5 = 28U;
 _IEC_CONST unsigned char ncTRIGGER6 = 30U;
 _IEC_CONST unsigned char ncTRIGGER7 = 32U;
 _IEC_CONST unsigned char ncTRIGGER8 = 34U;
 _IEC_CONST unsigned short ncTRIGGPOS = 112U;
 _IEC_CONST unsigned char ncTRQ_LIMIT = 30U;
 _IEC_CONST unsigned char ncTRUE = 1U;
 _IEC_CONST unsigned short ncTUNE_FBCTRL_MODEL_2MASS = 8192U;
 _IEC_CONST unsigned short ncTUNE_MODEL_2MASS = 32768U;
 _IEC_CONST unsigned short ncTUNE_MODEL_FRICTION = 8192U;
 _IEC_CONST unsigned char ncTUNE_STANDSTILL = 0U;
 _IEC_CONST unsigned short ncTUNE_TN = 16U;
 _IEC_CONST unsigned char ncTUNE_V_CONSTANT = 1U;
 _IEC_CONST unsigned char ncU_LIMIT = 40U;
 _IEC_CONST unsigned char ncU_SET = 13U;
 _IEC_CONST unsigned char ncUF = 7U;
 _IEC_CONST unsigned short ncUNLINK = 344U;
 _IEC_CONST unsigned short ncUPLOAD = 338U;
 _IEC_CONST unsigned short ncUSE_FILTER_PAR = 4U;
 _IEC_CONST unsigned short ncUSE_TN = 8U;
 _IEC_CONST unsigned char ncUSER = 1U;
 _IEC_CONST unsigned char ncUSERROM = 2U;
 _IEC_CONST unsigned char ncV_ACT = 14U;
 _IEC_CONST unsigned short ncV_AXIS = 4U;
 _IEC_CONST unsigned char ncV_COMP_A_CYC = 39U;
 _IEC_CONST unsigned char ncV_COMP_A_SL = 36U;
 _IEC_CONST unsigned char ncV_COMP_S_MA = 37U;
 _IEC_CONST unsigned char ncV_COMP_S_SL = 38U;
 _IEC_CONST unsigned char ncV_CONST = 2U;
 _IEC_CONST unsigned char ncV_JUMP = 1U;
 _IEC_CONST unsigned char ncV_JUMP_T = 4U;
 _IEC_CONST unsigned char ncV_SET = 12U;
 _IEC_CONST unsigned char ncV_SET_COMP = 17U;
 _IEC_CONST unsigned char ncV_TRAJ = 20U;
 _IEC_CONST unsigned short ncVARIABLE = 377U;
 _IEC_CONST unsigned char ncVERTICAL = 1U;
 _IEC_CONST unsigned short ncVIRTUAL_IF = 128U;
 _IEC_CONST unsigned char ncWINDOW = 1U;
 _IEC_CONST unsigned char ncWITH_CAM = 31U;
 _IEC_CONST unsigned short ncWITH_INDEX = 0U;
 _IEC_CONST unsigned short ncWITHOUT_INDEX = 1U;
 _IEC_CONST unsigned short ncWRITE_COB = 320U;
 _IEC_CONST unsigned short ncWRITE_HPRIO = 290U;
 _IEC_CONST unsigned char ncXY = 0U;
 _IEC_CONST unsigned char ncYZ = 2U;
 _IEC_CONST unsigned short ncZ_TRANS = 3U;
 _IEC_CONST unsigned short ncZERO = 1U;
 _IEC_CONST unsigned char ncZERO_DAT = 21U;
 _IEC_CONST unsigned short ncZERO_TAB = 208U;
 _IEC_CONST unsigned short ncZEROPMON = 216U;
 _IEC_CONST unsigned char ncZX = 1U;
 _IEC_CONST unsigned short RIO1_2005 = 1408U;
 _IEC_CONST unsigned short RIO2_2005 = 2432U;
 _IEC_CONST unsigned short RIO3_2005 = 3456U;
 _IEC_CONST unsigned short RIO4_2005 = 4480U;
 _IEC_CONST unsigned long SafeMC_action_GET_CFG_PTR = 1U;
 _IEC_CONST unsigned long SafeMC_action_READ_SAFEIN_DATA = 3U;
 _IEC_CONST unsigned long SafeMC_action_READ_SAFEIN_DATA2 = 5U;
 _IEC_CONST unsigned long SafeMC_action_READ_SAFEIN_DATA3 = 7U;
 _IEC_CONST unsigned long SafeMC_action_READ_SAFEOUT_DATA = 2U;
 _IEC_CONST unsigned long SafeMC_action_READ_SAFEOUT_DATA2 = 4U;
 _IEC_CONST unsigned long SafeMC_action_READ_SAFEOUT_DATA3 = 6U;
#endif





/* Datatypes and datatypes of function blocks */
typedef struct NCDA_DATMO_typ
{
	unsigned char name[12];
	unsigned char type;
	unsigned char mem_type;
} NCDA_DATMO_typ;

typedef struct NCDA_MDDIR_typ
{
	unsigned short count;
	unsigned long free_ram;
	unsigned long free_prom;
	struct NCDA_DATMO_typ data_modul[100];
} NCDA_MDDIR_typ;

typedef struct NCDA_TPREC_typ
{
	float length;
	float radius;
	float offset[3];
} NCDA_TPREC_typ;

typedef struct NCDA_TPTAB_typ
{
	unsigned short record_cnt;
	unsigned short startindex;
	struct NCDA_TPREC_typ record[255];
} NCDA_TPTAB_typ;

typedef struct NCDA_RPTAB_typ
{
	unsigned short r_par_cnt;
	unsigned short startindex;
	float r_par[1000];
} NCDA_RPTAB_typ;

typedef struct NCDA_ZPREC_typ
{
	float offset[3];
} NCDA_ZPREC_typ;

typedef struct NCDA_ZPTAB_typ
{
	unsigned short record_cnt;
	unsigned short startindex;
	struct NCDA_ZPREC_typ record[200];
} NCDA_ZPTAB_typ;

typedef struct NCGLACT_NCDA_CR_STA_typ
{
	unsigned char ok;
	unsigned char error;
	unsigned char reserved1;
	unsigned char reserved2;
	unsigned long error_number;
	unsigned long ident;
	unsigned long data_adr;
} NCGLACT_NCDA_CR_STA_typ;

typedef struct NCGLACT_NCDA_CR_PAR_typ
{
	unsigned char name[32];
	unsigned short version;
	unsigned short reserved;
	unsigned short type;
	unsigned short nc_sw_id;
	unsigned long data_len;
	unsigned long data_adr;
} NCGLACT_NCDA_CR_PAR_typ;

typedef struct NCGLACT_NCDA_CREATE_typ
{
	struct NCGLACT_NCDA_CR_STA_typ status;
	struct NCGLACT_NCDA_CR_PAR_typ parameter;
} NCGLACT_NCDA_CREATE_typ;

typedef struct NCGLACT_NCDA_INF_STA_typ
{
	unsigned char ok;
	unsigned char error;
	unsigned char reserved1;
	unsigned char reserved2;
	unsigned long error_number;
	unsigned long ident;
	unsigned long data_len;
	unsigned long data_adr;
	unsigned short version;
	unsigned short mem_type;
	unsigned short type;
	unsigned short nc_sw_id;
	unsigned short data_sections;
	unsigned short reserved;
} NCGLACT_NCDA_INF_STA_typ;

typedef struct NCGLACT_NCDA_INF_PAR_typ
{
	unsigned char name[32];
	unsigned short data_section_idx;
	unsigned short reserved;
} NCGLACT_NCDA_INF_PAR_typ;

typedef struct NCGLACT_NCDA_INFO_typ
{
	struct NCGLACT_NCDA_INF_STA_typ status;
	struct NCGLACT_NCDA_INF_PAR_typ parameter;
} NCGLACT_NCDA_INFO_typ;

typedef struct NCGLACT_NCDA_WR_STA_typ
{
	unsigned char ok;
	unsigned char error;
	unsigned char reserved1;
	unsigned char reserved2;
	unsigned long error_number;
} NCGLACT_NCDA_WR_STA_typ;

typedef struct NCGLACT_NCDA_WR_PAR_typ
{
	unsigned long ident;
	unsigned long data_len;
	unsigned long data_adr;
	unsigned long data_offset;
} NCGLACT_NCDA_WR_PAR_typ;

typedef struct NCGLACT_NCDA_WRITE_typ
{
	struct NCGLACT_NCDA_WR_STA_typ status;
	struct NCGLACT_NCDA_WR_PAR_typ parameter;
} NCGLACT_NCDA_WRITE_typ;

typedef struct NCGLACT_NCDA_DIR_STA_typ
{
	unsigned char ok;
	unsigned char error;
	unsigned char reserved1;
	unsigned char reserved2;
	unsigned long error_number;
	unsigned long ident;
	unsigned long data_adr;
} NCGLACT_NCDA_DIR_STA_typ;

typedef struct NCGLACT_NCDA_DIR_PAR_typ
{
	unsigned char name[32];
	unsigned short type;
	unsigned short reserved;
} NCGLACT_NCDA_DIR_PAR_typ;

typedef struct NCGLACT_NCDA_DIR_typ
{
	struct NCGLACT_NCDA_DIR_STA_typ status;
	struct NCGLACT_NCDA_DIR_PAR_typ parameter;
} NCGLACT_NCDA_DIR_typ;







#endif /* _NCGLOBAL_ */



#ifndef _NCGLOBAL_FUN_H_
#define _NCGLOBAL_FUN_H_

#ifdef __cplusplus
extern "C"
{
#endif

UINT ncaccess (UINT nc_sw_id, char *nc_obj_name, UDINT *p_nc_object);
UINT ncaction (UDINT nc_object, UINT subject, UINT action);
UINT ncalloc  (UINT bus_typ, UINT modul_adr, UINT object_typ, UINT channel, UDINT object_adr);
UINT nccnccom (UDINT nc_object);
UINT ncda_cr  (USINT mo_typ, USINT *name_p, UDINT dat_len, void *dat_p, void **mo_dat_p_p, void *mo_ident_p);
UINT ncda_dir (USINT mo_typ, USINT *name_p, void **mo_dat_p_p, void *mo_ident_p);
UINT ncda_id  (USINT mo_typ, USINT *name_p, void *mo_ident_p);
UINT ncda_inf (UDINT mo_ident, void **mo_dat_p_p, void *dat_len_p, void *mem_typ_p);
UINT ncda_wr  (UDINT mo_ident, void *dat_p, UDINT dat_len, UDINT mo_dat_off);
UINT ncglobal_action (UDINT action_id, void *par_struct_adr, UDINT par_struct_size);

#ifdef __cplusplus
};
#endif

#endif /* _NCGLOBAL_FUN_H_ */

