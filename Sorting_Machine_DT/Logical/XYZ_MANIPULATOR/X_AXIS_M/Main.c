/**
 * MIT License
 * Copyright(c) 2020 Roman Parak
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
/**
 * Author   : Roman Parak
 * Email    : Roman.Parak@outlook.com
 * File Name: Main.c
 */

#include <bur/plc.h>
#include <bur/plctypes.h>
#include "rp_funcx.h"

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

// {DEFINE - ABSOLUTE POSITION (Camera Conveyor AXIS}
#define Axis_XM_HOME_ABSOLUTE_POS 17700410;
// Camera Conveyor AXIS// MpAxis // STRUCT // 
// {Camera Conveyor AXIS}
_LOCAL struct MpAxisBasic MpAxisBasic_Axis_XM;
_LOCAL struct MpAxisBasicParType MpAxis_Axis_XM_ParType;
// {Camera Conveyor AXIS}
_LOCAL struct MpAxisCyclicSet MpAxisCyclicSet_Axis_XM;
_LOCAL struct MpAxisCyclicSetParType AxisCyclicPar_Axis_XM;
// Camera Conveyor AXIS // SMC_PAD // STRUCT // 
_LOCAL struct SMC_PAD Axis_XM_SMC_PAD;

void _INIT ProgramInit(void)
{
	// -------------------- INITIALIZATION MAPP AXIS -------------------- //
	// MpAxis SMC PAD //
	MpAxisBasic_Axis_XM.Enable         = 1;
	MpAxisBasic_Axis_XM.Axis           = &gAxis01_X;
	MpAxisBasic_Axis_XM.MpLink         = &gAxisBasic_Axis_M_X;
	MpAxisBasic_Axis_XM.Parameters     = &MpAxis_Axis_XM_ParType;
	// Cyclic Parameters {Read}
	MpAxis_Axis_XM_ParType.CyclicRead.MotorTempMode = mpAXIS_READ_CYCLIC;
	MpAxis_Axis_XM_ParType.CyclicRead.LagErrorMode  = mpAXIS_READ_CYCLIC;
	MpAxis_Axis_XM_ParType.CyclicRead.TorqueMode 	= mpAXIS_READ_CYCLIC;
	// MpAxisCyclicSet SMC PAD //
	MpAxisCyclicSet_Axis_XM.Enable 	= 1;
	MpAxisCyclicSet_Axis_XM.MpLink 	= &gAxisBasic_Axis_M_X;
	MpAxisCyclicSet_Axis_XM.Parameters = &AxisCyclicPar_Axis_XM;
	// MpAxisCyclicSet Parameters (initial) SMC PAD //
	AxisCyclicPar_Axis_XM.Acceleration            = 5000;
	AxisCyclicPar_Axis_XM.Deceleration            = 5000;
	AxisCyclicPar_Axis_XM.PositionModeMaxVelocity = 5000;
	
	// -------------------- INITIALIZATION SMCTrak -------------------- //
	// Camera Conveyor //
	// MpAxis & MpAxis Cyclic declaration
	Axis_XM_SMC_PAD.MpAxis              = &MpAxisBasic_Axis_XM;
	Axis_XM_SMC_PAD.MpAxisParType       = &MpAxis_Axis_XM_ParType;
	Axis_XM_SMC_PAD.MpAxisCyclic        = &MpAxisCyclicSet_Axis_XM;
	Axis_XM_SMC_PAD.MpAxisCyclicParType = &AxisCyclicPar_Axis_XM;
	// Set parameter
	Axis_XM_SMC_PAD.Absolute_Position 				= Axis_XM_HOME_ABSOLUTE_POS;
	Axis_XM_SMC_PAD.Default_parameters.MAX_POSITION = 4000;
	Axis_XM_SMC_PAD.Default_parameters.MIN_POSITION = 0;
	Axis_XM_SMC_PAD.Default_parameters.MAX_VELOCITY = 8000;
	Axis_XM_SMC_PAD.Default_parameters.MIN_VELOCITY = 100;
	// Enable Function block
	Axis_XM_SMC_PAD.Enable = 1;
}

void _CYCLIC ProgramCyclic(void)
{
	switch(dT_Main.xyz_manipulator.X.actual_state){
		case LINP_CTRL_WAIT_STATE:
			{
				if(dT_Main.xyz_manipulator.X.start == 1 && (Axis_XM_SMC_PAD.PowerOn == 1 && Axis_XM_SMC_PAD.IsHomed == 1)){
					dT_Main.xyz_manipulator.X.actual_state = LINP_CTRL_LOAD_PARAM_STATE;
				}
			}
			break;
		case LINP_CTRL_LOAD_PARAM_STATE:
			{
				Axis_XM_SMC_PAD.Set_Parameters.position = Axis_XM_SMC_PAD.Actual_Parameters.position;
				Axis_XM_SMC_PAD.Set_Parameters.velocity = dT_Main.xyz_manipulator.X.parameter.vel;
			
				Axis_XM_SMC_PAD.Mode.automatic.instruction = INSTR_REAL_TIME;
				Axis_XM_SMC_PAD.Mode.automatic.start = 1;
			
				dT_Main.xyz_manipulator.X.start = 0;
			
				if(Axis_XM_SMC_PAD.Internal.State == AUTO_MODE_STATE_RT_1){
					dT_Main.xyz_manipulator.X.actual_state = LINP_CTRL_SET_POSITION_STATE;
				}
			}
			break;
		case LINP_CTRL_SET_POSITION_STATE:
			{
				if(dT_Main.xyz_manipulator.X.stop == 1){
					dT_Main.xyz_manipulator.X.actual_state = LINP_CTRL_STOP_STATE;
				}
				
				Axis_XM_SMC_PAD.Mode.automatic.start = 0;
			
				Axis_XM_SMC_PAD.Set_Parameters.velocity = dT_Main.xyz_manipulator.X.parameter.vel;
				Axis_XM_SMC_PAD.Set_Parameters.position = dT_Main.xyz_manipulator.X.parameter.pos;
				
				dT_Main.xyz_manipulator.X.actual_position = Axis_XM_SMC_PAD.Actual_Parameters.position;
				dT_Main.xyz_manipulator.X.actual_velocity = Axis_XM_SMC_PAD.Actual_Parameters.velocity;
			}
			break;
		case LINP_CTRL_STOP_STATE:
			{
				dT_Main.xyz_manipulator.X.stop = 0;
			
				Axis_XM_SMC_PAD.Mode.stop = 1;
			
				if(Axis_XM_SMC_PAD.Internal.State == WAIT_STATE){
					dT_Main.xyz_manipulator.X.actual_state = LINP_CTRL_WAIT_STATE;
				}
			}
			break;
	}
	
	// Read Data from Main Control Program (Axis inputs)
	Axis_XM_SMC_PAD.Power = dT_Main.service.power;
	Axis_XM_SMC_PAD.Home  = dT_Main.service.home;
	// Write Data to Main Control Program (Information about axis outputs)
	dT_Main.xyz_manipulator.X.active   = Axis_XM_SMC_PAD.Active;
	dT_Main.xyz_manipulator.X.power_on = Axis_XM_SMC_PAD.PowerOn;
	dT_Main.xyz_manipulator.X.is_homed = Axis_XM_SMC_PAD.IsHomed;
	
	// -------------------- CALL FUNCTION -------------------- //
	// MpAxis - Camera Conveyor AXIS //
	MpAxisBasic(&MpAxisBasic_Axis_XM);
	// MpAxisCyclicSet - Camera Conveyor AXIS //
	MpAxisCyclicSet(&MpAxisCyclicSet_Axis_XM);
	// SMC PAD - Camera Conveyor AXIS //
	SMC_PAD(&Axis_XM_SMC_PAD);
}


