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
 * File Name: SMC_PAD.c
 */

#include <bur/plctypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <MpAxis.h>
#include <math.h>
#include <standard.h> 

#ifdef __cplusplus
	extern "C"
	{
#endif
#include "rp_funcx.h"
#ifdef __cplusplus
	};
#endif

// ************************************************************************************************************************************ //
// -------------------------------------------------------------  DECLARATIONS -------------------------------------------------------- //
// ************************************************************************************************************************************ //
// Timer
_LOCAL TON_typ ton_1;
// FUNCTION // DECLARATION //
void update_cyclicParameters(struct SMC_PAD* smc_pad, LREAL position, LREAL velocity);
BOOL set_time(BOOL enable, TIME t);
// INITIALIZATION // RESET //
void initialization_smc_pad(struct SMC_PAD* smc_pad);
void reset_parameters(struct SMC_PAD* smc_pad);
void parameters_null(struct SMC_PAD* smc_pad);

// ************************************************************************************************************************************ //
// --------------------------------------------------------------  MAIN --------------------------------------------------------------- //
// ************************************************************************************************************************************ //
void SMC_PAD(struct SMC_PAD* smc_pad)
{
	// *********************************************************//
	// ---------------- INITIALIZATION  ----------------------- //
	// *********************************************************//
	if(smc_pad->Enable != 1){
		initialization_smc_pad(smc_pad);
	}
	
	
	// *********************************************************//
	// ---------------- PAD MAIN STATE  ----------------------- //
	// *********************************************************//
	switch(smc_pad->Internal.State){
		case INITIALIZATION_STATE:
			{
				/*************************************** INITIALIZATION STATE ******************************************/	
				if((smc_pad->MpAxis->Error != 0 || smc_pad->MpAxisCyclic->Error != 0) || (smc_pad->MpAxis->StatusID != 0 || smc_pad->MpAxisCyclic->StatusID != 0)){
					smc_pad->Internal.Before_state = smc_pad->Internal.State;
					smc_pad->Internal.State 	   = ERROR_STATE_1;
				}
			
				if(smc_pad->MpAxis->Active == 1 && smc_pad->MpAxisCyclic->Active == 1){
					smc_pad->Active 	    = 1;
					smc_pad->Internal.State = POWER_STATE;
				}else{
					smc_pad->Active = 0;
				}
			}
			break;
		case POWER_STATE:
			{
				/*************************************** POWER STATE ******************************************/
				if((smc_pad->MpAxis->Error != 0 || smc_pad->MpAxisCyclic->Error != 0) || (smc_pad->MpAxis->StatusID != 0 || smc_pad->MpAxisCyclic->StatusID != 0)){
					smc_pad->Internal.Before_state = smc_pad->Internal.State;
					smc_pad->Internal.State 	   = ERROR_STATE_1;
				}
			
				if(smc_pad->Power == 1){
					// power state
					smc_pad->MpAxis->Power = 1;
				
					if(smc_pad->MpAxis->PowerOn == 1){
						smc_pad->Internal.State = HOME_STATE_1;
					}
				}
			}
			break;
		case HOME_STATE_1:
			{
				/*************************************** HOME (1) STATE ******************************************/
				if((smc_pad->MpAxis->Error != 0 || smc_pad->MpAxisCyclic->Error != 0) || (smc_pad->MpAxis->StatusID != 0 || smc_pad->MpAxisCyclic->StatusID != 0)){
					smc_pad->Internal.Before_state = smc_pad->Internal.State;
					smc_pad->Internal.State 	   = ERROR_STATE_1;
				}
			
				if(smc_pad->Home == 1){
					if(smc_pad->MpAxis->Position == 0 || (fabs(smc_pad->MpAxis->Position) == smc_pad->Absolute_Position)){
						// home state
						smc_pad->MpAxis->Home = 1;
			
						if(smc_pad->MpAxis->IsHomed == 1){
							smc_pad->MpAxis->Home   = 0;
							smc_pad->Internal.State = WAIT_STATE;
						}
					}else{
						smc_pad->Internal.State = HOME_STATE_2;
					}
				}
			
			}
			break;
		case HOME_STATE_2:
			{
				/*************************************** HOME (2) STATE ******************************************/
				if((smc_pad->MpAxis->Error != 0 || smc_pad->MpAxisCyclic->Error != 0) || (smc_pad->MpAxis->StatusID != 0 || smc_pad->MpAxisCyclic->StatusID != 0)){
					smc_pad->Internal.Before_state = smc_pad->Internal.State;
					smc_pad->Internal.State 	   = ERROR_STATE_1;
				}
				
				smc_pad->MpAxisParType->Home.Position = fabs(fabs(smc_pad->MpAxis->Position) - smc_pad->Absolute_Position);
				smc_pad->MpAxis->Update = 1;
				
				if(smc_pad->MpAxis->UpdateDone == 1){
					smc_pad->MpAxis->Update = 0;
					smc_pad->Internal.State = HOME_STATE_3;
				}
				
			}
			break;
		case HOME_STATE_3:
			{
				/*************************************** HOME (3) STATE ******************************************/
				if((smc_pad->MpAxis->Error != 0 || smc_pad->MpAxisCyclic->Error != 0) || (smc_pad->MpAxis->StatusID != 0 || smc_pad->MpAxisCyclic->StatusID != 0)){
					smc_pad->Internal.Before_state = smc_pad->Internal.State;
					smc_pad->Internal.State 	   = ERROR_STATE_1;
				}
				
				smc_pad->MpAxis->Home = 1;
				
				if(smc_pad->MpAxis->IsHomed == 1){
					smc_pad->MpAxis->Home   = 0;
					smc_pad->Internal.State = MOVE_HOME_1;	
				}
			}
			break;
		case WAIT_STATE:
			{
				/*************************************** WAIT STATE ******************************************/
				if((smc_pad->MpAxis->Error != 0 || smc_pad->MpAxisCyclic->Error != 0) || (smc_pad->MpAxis->StatusID != 0 || smc_pad->MpAxisCyclic->StatusID != 0)){
					smc_pad->Internal.Before_state = smc_pad->Internal.State;
					smc_pad->Internal.State 	   = ERROR_STATE_1;
				}
			
				if(smc_pad->Mode.automatic.start == 1){
					smc_pad->MpAxis->Stop = 0;
					smc_pad->Mode.stop    = 0;
					if(smc_pad->Mode.automatic.instruction == INSTR_REAL_TIME){
						// real time {0}
						smc_pad->Internal.State  = AUTO_MODE_STATE_RT_1;
					}else if(smc_pad->Mode.automatic.instruction == INSTR_LOWER_UPPER_LIMIT){
						// upper / lower limit {1}		
						// Set time parameters
						int i;
						for(i = 0; i < (int)(sizeof(smc_pad->Set_Parameters.limit.time)/sizeof(smc_pad->Set_Parameters.limit.time[0])); i++){
							if(smc_pad->Set_Parameters.limit.time_signal[i] == 0){
								smc_pad->Set_Parameters.limit.time[i] = 500;
							}else{
								smc_pad->Set_Parameters.limit.time[i] = smc_pad->Set_Parameters.limit.time_signal[0]*500;
							}
						}
						smc_pad->Internal.State  = AUTO_MODE_STATE_UL_1;
					}else if(smc_pad->Mode.automatic.instruction == INSTR_SEQUENCE){
						// sequence of steps {2}
						// Set time parameters
						int i;
						for(i = 0; i < (int)(sizeof(smc_pad->Set_Parameters.sequence.time)/sizeof(smc_pad->Set_Parameters.sequence.time[0])); i++){
							if(smc_pad->Set_Parameters.sequence.time_signal[i] == 0){
								smc_pad->Set_Parameters.sequence.time[i] = 500;
							}else{
								smc_pad->Set_Parameters.sequence.time[i] = smc_pad->Set_Parameters.sequence.time_signal[0]*500;
							}
						}
						smc_pad->Internal.State  = AUTO_MODE_STATE_SS_1;
					}
				}else if(smc_pad->Mode.manual.start == 1){
					smc_pad->Mode.stop      = 0;
					smc_pad->Internal.State = MANUAL_MODE_STATE_1;
				}else if(smc_pad->Mode.home == 1){
					if(smc_pad->MpAxisCyclic->Info.SlavePosition != 0){
						smc_pad->Internal.State = MOVE_HOME_1;
					}
				}else{
					smc_pad->Mode.stop = 0;
				}
			}
			break;
		case MOVE_HOME_1:
			{
				/*************************************** MOVE HOME (1) STATE ******************************************/
				if((smc_pad->MpAxis->Error != 0 || smc_pad->MpAxisCyclic->Error != 0) || (smc_pad->MpAxis->StatusID != 0 || smc_pad->MpAxisCyclic->StatusID != 0)){
					smc_pad->Internal.Before_state = smc_pad->Internal.State;
					smc_pad->Internal.State 	   = ERROR_STATE_1;
				}
			
				update_cyclicParameters(smc_pad, smc_pad->MpAxisCyclic->Info.SlavePosition, (smc_pad->Set_Parameters.MIN_VELOCITY*30));
				
				smc_pad->MpAxisCyclic->Update = 1;
			
				if(smc_pad->MpAxisCyclic->UpdateDone == 1){
					smc_pad->MpAxisCyclic->Update = 0;
					smc_pad->Internal.State       = MOVE_HOME_2;
				}
			}
			break;
		case MOVE_HOME_2:
			{
				/*************************************** MOVE HOME (2) STATE ******************************************/
				if((smc_pad->MpAxis->Error != 0 || smc_pad->MpAxisCyclic->Error != 0) || (smc_pad->MpAxis->StatusID != 0 || smc_pad->MpAxisCyclic->StatusID != 0)){
					smc_pad->Internal.Before_state = smc_pad->Internal.State;
					smc_pad->Internal.State 	   = ERROR_STATE_1;
				}
				
				if(smc_pad->MpAxisCyclic->CyclicPosition == 0){
					smc_pad->MpAxisCyclic->CyclicPosition = 1;
				}
			
				smc_pad->MpAxisCyclic->Position = smc_pad->Set_Parameters.MIN_POSITION;
				
				if(smc_pad->MpAxisCyclic->Info.SlavePosition == 0){
					smc_pad->Mode.home      = 0;
					smc_pad->Internal.State = WAIT_STATE;
				}
			}
			break;
		case AUTO_MODE_STATE_RT_1:
			{
				/*************************************** AUTO MODE Real-Time (1) STATE ******************************************/
				if((smc_pad->MpAxis->Error != 0 || smc_pad->MpAxisCyclic->Error != 0) || (smc_pad->MpAxis->StatusID != 0 || smc_pad->MpAxisCyclic->StatusID != 0)){
					smc_pad->Internal.Before_state = smc_pad->Internal.State;
					smc_pad->Internal.State 	   = ERROR_STATE_1;
				}
			
				if(smc_pad->Set_Parameters.position != smc_pad->Internal.Local.before_position){
					smc_pad->MpAxisCyclic->Position 	 = smc_pad->Set_Parameters.position;
					smc_pad->Internal.Local.set_position = smc_pad->Set_Parameters.position;
					smc_pad->Internal.Local.set_velocity = smc_pad->Set_Parameters.velocity;
					
					if((fabs(smc_pad->Set_Parameters.position - smc_pad->Internal.Local.before_position) == smc_pad->Internal.Local.sum_position) && (fabs(smc_pad->Set_Parameters.velocity - smc_pad->Internal.Local.before_velocity) == smc_pad->Internal.Local.sum_velocity)){
						smc_pad->Internal.State = AUTO_MODE_STATE_RT_2;
					}else{			
						smc_pad->Internal.Local.sum_position  = fabs(smc_pad->Set_Parameters.position - smc_pad->Internal.Local.before_position);
						smc_pad->Internal.Local.sum_velocity  = fabs(smc_pad->Set_Parameters.velocity - smc_pad->Internal.Local.before_velocity);
						smc_pad->Internal.State         	  = AUTO_MODE_STATE_RT_3;
					}
				}
			}
			break;
		case AUTO_MODE_STATE_RT_2:
			{
				/*************************************** AUTO MODE Real-Time (2) STATE ******************************************/
				if((smc_pad->MpAxis->Error != 0 || smc_pad->MpAxisCyclic->Error != 0) || (smc_pad->MpAxis->StatusID != 0 || smc_pad->MpAxisCyclic->StatusID != 0)){
					smc_pad->Internal.Before_state = smc_pad->Internal.State;
					smc_pad->Internal.State 	   = ERROR_STATE_1;
				}
			
				if(smc_pad->MpAxisCyclic->CyclicPosition == 0){
					smc_pad->MpAxisCyclic->CyclicPosition = 1;
				}
			
				if(smc_pad->MpAxisCyclic->Info.SlavePosition == smc_pad->Internal.Local.set_position){
					smc_pad->Internal.Local.before_position = smc_pad->Internal.Local.set_position;
					smc_pad->Internal.Local.before_velocity = smc_pad->Internal.Local.set_velocity;
					smc_pad->Internal.State           	    = AUTO_MODE_STATE_RT_1;
				}
			}
			break;
		case AUTO_MODE_STATE_RT_3:
			{
				/*************************************** AUTO MODE Real-Time (3) STATE ******************************************/
				if((smc_pad->MpAxis->Error != 0 || smc_pad->MpAxisCyclic->Error != 0) || (smc_pad->MpAxis->StatusID != 0 || smc_pad->MpAxisCyclic->StatusID != 0)){
					smc_pad->Internal.Before_state = smc_pad->Internal.State;
					smc_pad->Internal.State 	   = ERROR_STATE_1;
				}
				
				update_cyclicParameters(smc_pad, fabs(smc_pad->Set_Parameters.position - smc_pad->MpAxisCyclic->Info.SlavePosition), smc_pad->Set_Parameters.velocity);
			
				smc_pad->MpAxisCyclic->Update = 1;
			
				if(smc_pad->MpAxisCyclic->UpdateDone == 1){
					smc_pad->MpAxisCyclic->Update = 0;
					smc_pad->Internal.State       = AUTO_MODE_STATE_RT_2;
				}
			}
			break;
		case MANUAL_MODE_STATE_1:
			{
				/*************************************** MANUAL MODE (1) STATE ******************************************/
				if((smc_pad->MpAxis->Error != 0 || smc_pad->MpAxisCyclic->Error != 0) || (smc_pad->MpAxis->StatusID != 0 || smc_pad->MpAxisCyclic->StatusID != 0)){
					smc_pad->Internal.Before_state = smc_pad->Internal.State;
					smc_pad->Internal.State 	   = ERROR_STATE_1;
				}
				
				update_cyclicParameters(smc_pad, smc_pad->Set_Parameters.MAX_POSITION, smc_pad->Set_Parameters.MAX_VELOCITY);
				
				smc_pad->MpAxisCyclic->Update = 1;
			
				if(smc_pad->MpAxisCyclic->UpdateDone == 1){
					smc_pad->MpAxisCyclic->Update = 0;
					smc_pad->Internal.State       = MANUAL_MODE_STATE_2;
				}
			}
			break;
		case MANUAL_MODE_STATE_2:
			{
				/*************************************** MANUAL MODE (2) STATE ******************************************/
				if((smc_pad->MpAxis->Error != 0 || smc_pad->MpAxisCyclic->Error != 0) || (smc_pad->MpAxis->StatusID != 0 || smc_pad->MpAxisCyclic->StatusID != 0)){
					smc_pad->Internal.Before_state = smc_pad->Internal.State;
					smc_pad->Internal.State 	   = ERROR_STATE_1;
				}
			
				if(smc_pad->MpAxisCyclic->CyclicPosition == 0){
					smc_pad->MpAxisCyclic->CyclicPosition = 1;
				}
			
				smc_pad->MpAxisCyclic->Position = smc_pad->Set_Parameters.position;
			}
			break;
		case AUTO_MODE_STATE_UL_1:
			{
				/*************************************** AUTO MODE Upper/Lower (1) STATE ******************************************/
				if((smc_pad->MpAxis->Error != 0 || smc_pad->MpAxisCyclic->Error != 0) || (smc_pad->MpAxis->StatusID != 0 || smc_pad->MpAxisCyclic->StatusID != 0)){
					smc_pad->Internal.Before_state = smc_pad->Internal.State;
					smc_pad->Internal.State 	   = ERROR_STATE_1;
				}
			
				update_cyclicParameters(smc_pad, (smc_pad->Set_Parameters.limit.position_start - smc_pad->Set_Parameters.limit.position_end), smc_pad->Set_Parameters.limit.velocity);
				
				smc_pad->MpAxisCyclic->Update = 1;
			
				if(smc_pad->MpAxisCyclic->UpdateDone == 1){
					smc_pad->MpAxisCyclic->Update = 0;
					smc_pad->Internal.State       = AUTO_MODE_STATE_UL_2;
				}
			}
			break;
		case AUTO_MODE_STATE_UL_2:
			{
				/*************************************** AUTO MODE Upper/Lower (2) STATE ******************************************/
				if((smc_pad->MpAxis->Error != 0 || smc_pad->MpAxisCyclic->Error != 0) || (smc_pad->MpAxis->StatusID != 0 || smc_pad->MpAxisCyclic->StatusID != 0)){
					smc_pad->Internal.Before_state = smc_pad->Internal.State;
					smc_pad->Internal.State 	   = ERROR_STATE_1;
				}
			
				if(smc_pad->MpAxisCyclic->CyclicPosition == 0){
					smc_pad->MpAxisCyclic->CyclicPosition = 1;
				}
			
				if(smc_pad->MpAxisCyclic->Info.SlavePosition != smc_pad->Set_Parameters.limit.position_start){
					smc_pad->MpAxisCyclic->Position = smc_pad->Set_Parameters.limit.position_start;
				}
				
				if(smc_pad->MpAxisCyclic->Info.SlavePosition == smc_pad->Set_Parameters.limit.position_start){
					if(smc_pad->Set_Parameters.limit.mode == INSTR_SIGNAL){
						smc_pad->Set_Parameters.limit.signal_inPos[0] = 1;
					}
					if(smc_pad->Set_Parameters.limit.mode == INSTR_SIGNAL && smc_pad->Set_Parameters.limit.signal == 1){
						// {SIGNAL}
						smc_pad->Internal.State  					  = AUTO_MODE_STATE_UL_3;
						smc_pad->Set_Parameters.limit.signal_inPos[0] = 0;
					}else if(smc_pad->Set_Parameters.limit.mode == INSTR_TIME){
						// {TIME}
						smc_pad->Internal.Timer.enable_time 		  = 1;
						smc_pad->Internal.Timer.wait_time   		  = smc_pad->Set_Parameters.limit.time[0];
						smc_pad->Set_Parameters.limit.elapsed_time[0] = smc_pad->Internal.Timer.elapsed_time;
						if(smc_pad->Internal.Timer.output_time == 1){
							smc_pad->Set_Parameters.limit.elapsed_time[0] = 0;
							smc_pad->Internal.Timer.enable_time   		  = 0;
							smc_pad->Internal.State 			  		  = AUTO_MODE_STATE_UL_3;
						}
					}
				}
			}
			break;
		case AUTO_MODE_STATE_UL_3:
			{
				/*************************************** AUTO MODE Upper/Lower (1) STATE ******************************************/
				if((smc_pad->MpAxis->Error != 0 || smc_pad->MpAxisCyclic->Error != 0) || (smc_pad->MpAxis->StatusID != 0 || smc_pad->MpAxisCyclic->StatusID != 0)){
					smc_pad->Internal.Before_state = smc_pad->Internal.State;
					smc_pad->Internal.State 	   = ERROR_STATE_1;
				}
			
				if(smc_pad->MpAxisCyclic->CyclicPosition == 0){
					smc_pad->MpAxisCyclic->CyclicPosition = 1;
				}
			
				smc_pad->MpAxisCyclic->Position = smc_pad->Set_Parameters.limit.position_end;
				
				if(smc_pad->MpAxisCyclic->Info.SlavePosition == smc_pad->Set_Parameters.limit.position_end){
					if(smc_pad->Set_Parameters.limit.mode == INSTR_SIGNAL){
						smc_pad->Set_Parameters.limit.signal_inPos[1] = 1;
					}
					if(smc_pad->Set_Parameters.limit.mode == INSTR_SIGNAL && smc_pad->Set_Parameters.limit.signal == 1){
						smc_pad->Set_Parameters.limit.signal_inPos[1] = 0;
						smc_pad->Internal.State 				      = AUTO_MODE_STATE_UL_2;
					}else if(smc_pad->Set_Parameters.limit.mode == INSTR_TIME){
						// {TIME}
						smc_pad->Internal.Timer.enable_time 		  = 1;
						smc_pad->Internal.Timer.wait_time   		  = smc_pad->Set_Parameters.limit.time[1];
						smc_pad->Set_Parameters.limit.elapsed_time[1] = smc_pad->Internal.Timer.elapsed_time;
						if(smc_pad->Internal.Timer.output_time == 1){
							smc_pad->Set_Parameters.limit.elapsed_time[1] = 0;
							smc_pad->Internal.Timer.enable_time   		  = 0;
							smc_pad->Internal.State 			  		  = AUTO_MODE_STATE_UL_2;
						}
					}
				}
			}
			break;
		case AUTO_MODE_STATE_SS_1:
			{
				/*************************************** AUTO MODE Sequence Step (1) STATE ******************************************/
				if((smc_pad->MpAxis->Error != 0 || smc_pad->MpAxisCyclic->Error != 0) || (smc_pad->MpAxis->StatusID != 0 || smc_pad->MpAxisCyclic->StatusID != 0)){
					smc_pad->Internal.Before_state = smc_pad->Internal.State;
					smc_pad->Internal.State 	   = ERROR_STATE_1;
				}
			
				update_cyclicParameters(smc_pad, (smc_pad->Set_Parameters.sequence.position[smc_pad->Internal.Local.count_sequence] - smc_pad->MpAxisCyclic->Info.SlavePosition), smc_pad->Set_Parameters.sequence.velocity[smc_pad->Internal.Local.count_sequence]);
				
				smc_pad->MpAxisCyclic->Update = 1;
			
				if(smc_pad->MpAxisCyclic->UpdateDone == 1){
					smc_pad->MpAxisCyclic->Update = 0;
					smc_pad->Internal.State       = AUTO_MODE_STATE_SS_2;
				}
			}
			break;
		case AUTO_MODE_STATE_SS_2:
			{
				/*************************************** AUTO MODE Sequence Step (2) STATE ******************************************/
				if((smc_pad->MpAxis->Error != 0 || smc_pad->MpAxisCyclic->Error != 0) || (smc_pad->MpAxis->StatusID != 0 || smc_pad->MpAxisCyclic->StatusID != 0)){
					smc_pad->Internal.Before_state = smc_pad->Internal.State;
					smc_pad->Internal.State 	   = ERROR_STATE_1;
				}
			
				if(smc_pad->MpAxisCyclic->CyclicPosition == 0){
					smc_pad->MpAxisCyclic->CyclicPosition = 1;
				}
			
				smc_pad->MpAxisCyclic->Position = smc_pad->Set_Parameters.sequence.position[smc_pad->Internal.Local.count_sequence];
				
				if(smc_pad->MpAxisCyclic->Info.SlavePosition == smc_pad->Set_Parameters.sequence.position[smc_pad->Internal.Local.count_sequence]){
					if(smc_pad->Set_Parameters.sequence.mode == INSTR_SIGNAL){
						smc_pad->Set_Parameters.sequence.signal_inPos[smc_pad->Internal.Local.count_sequence] = 1;
					}
					if(smc_pad->Set_Parameters.sequence.mode == INSTR_SIGNAL && smc_pad->Set_Parameters.sequence.signal == 1){
						// {SIGNAL}
						smc_pad->Set_Parameters.sequence.signal_inPos[smc_pad->Internal.Local.count_sequence] = 0;
						if(smc_pad->Internal.Local.count_sequence == 4){
							smc_pad->Internal.Local.count_sequence = 0;
						
							if(fabs(smc_pad->Set_Parameters.sequence.position[smc_pad->Internal.Local.count_sequence + 1] - smc_pad->MpAxisCyclic->Info.SlavePosition) != smc_pad->Internal.Local.pos_sequence){
								smc_pad->Internal.State = AUTO_MODE_STATE_SS_1;
							}
						}else{
							if(fabs(smc_pad->Set_Parameters.sequence.position[smc_pad->Internal.Local.count_sequence + 1] - smc_pad->MpAxisCyclic->Info.SlavePosition) != smc_pad->Internal.Local.pos_sequence){
								smc_pad->Internal.State = AUTO_MODE_STATE_SS_1;
							}
							smc_pad->Internal.Local.count_sequence++;
						}
					}else if(smc_pad->Set_Parameters.sequence.mode == INSTR_TIME){
						// {TIME}
						smc_pad->Internal.Timer.enable_time 												  = 1;
						smc_pad->Internal.Timer.wait_time  													  = smc_pad->Set_Parameters.sequence.time[smc_pad->Internal.Local.count_sequence];
						smc_pad->Set_Parameters.sequence.elapsed_time[smc_pad->Internal.Local.count_sequence] = smc_pad->Internal.Timer.elapsed_time;
						if(smc_pad->Internal.Timer.output_time == 1){
							smc_pad->Set_Parameters.sequence.elapsed_time[smc_pad->Internal.Local.count_sequence] = 0;
							smc_pad->Internal.Timer.enable_time 												  = 0;
							if(smc_pad->Internal.Local.count_sequence == 4){
								smc_pad->Internal.Local.count_sequence = 0;
						
								if(fabs(smc_pad->Set_Parameters.sequence.position[smc_pad->Internal.Local.count_sequence + 1] - smc_pad->MpAxisCyclic->Info.SlavePosition) != smc_pad->Internal.Local.pos_sequence){
									smc_pad->Internal.State = AUTO_MODE_STATE_SS_1;
								}
							}else{
								if(fabs(smc_pad->Set_Parameters.sequence.position[smc_pad->Internal.Local.count_sequence + 1] - smc_pad->MpAxisCyclic->Info.SlavePosition) != smc_pad->Internal.Local.pos_sequence){
									smc_pad->Internal.State = AUTO_MODE_STATE_SS_1;
								}
								smc_pad->Internal.Local.count_sequence++;
							}
						}
					}
				}

			}
			break;
		
		case ERROR_STATE_1:
			{
				/*************************************** ERROR (1) STATE ******************************************/
				if(smc_pad->MpAxisCyclic->CyclicPosition != 0){
					smc_pad->MpAxisCyclic->CyclicPosition = 0;
				}
				
				smc_pad->MpAxis->Stop = 0;

				if(smc_pad->MpAxis->Stopped == 0){
					smc_pad->Internal.State = ERROR_STATE_2;
				}
			
			}
			break;
		case ERROR_STATE_2:
			{
				/*************************************** ERROR (2) STATE ******************************************/
				smc_pad->MpAxis->Power = 0;
				
				if(smc_pad->MpAxis->PowerOn == 0){
					smc_pad->Internal.State = ERROR_STATE_3;
				}

			}
			break;
		case ERROR_STATE_3:
			{
				/*************************************** ERROR (3) STATE ******************************************/
				smc_pad->MpAxisCyclic->ErrorReset = 1;
			
				if(smc_pad->MpAxisCyclic->Error == 0 && smc_pad->MpAxisCyclic->StatusID == 0){
					smc_pad->MpAxisCyclic->ErrorReset = 0;
					smc_pad->Internal.State           = ERROR_STATE_4;
				}
			}
			break;
		case ERROR_STATE_4:
			{
				/*************************************** ERROR (4) STATE ******************************************/
				smc_pad->MpAxis->ErrorReset 	  = 1;
			
				if(smc_pad->MpAxis->Error == 0 && smc_pad->MpAxis->StatusID == 0){
					smc_pad->MpAxis->ErrorReset = 0;
					if(smc_pad->Power == 1){
						smc_pad->Internal.State = ERROR_STATE_5;
					}else{
						smc_pad->Internal.State = smc_pad->Internal.Before_state;
					}
				}
			}
			break;
		case ERROR_STATE_5:
			{
				/*************************************** ERROR (5) STATE ******************************************/
				smc_pad->MpAxis->Power = 1;
			
				if((smc_pad->MpAxis->Error != 0 || smc_pad->MpAxisCyclic->Error != 0) || (smc_pad->MpAxis->StatusID != 0 || smc_pad->MpAxisCyclic->StatusID != 0)){
					smc_pad->Internal.State 	   = ERROR_STATE_1;
				}
			
				if(smc_pad->MpAxis->PowerOn == 1){
					smc_pad->MpAxisCyclic->CyclicPosition = 1;
					smc_pad->Internal.State               = smc_pad->Internal.Before_state;
				}
			}
			break;
		
	} // end switch
	
	// **************** STOP MODE SMC PAD **********************//
	if(smc_pad->Mode.stop == 1){
		// Mapp axis
		smc_pad->MpAxisCyclic->CyclicPosition = 0;
		smc_pad->MpAxis->Stop                 = 1;
		
		parameters_null(smc_pad);
		
		if(smc_pad->MpAxis->Stopped == 1){
			// state
			smc_pad->Internal.State = WAIT_STATE;
		}
	}
		
	//********************** BORDER CONTROLS **********************//
	if(smc_pad->Mode.automatic.start == 1 || smc_pad->Mode.manual.start == 1){
		if(smc_pad->Mode.automatic.instruction == INSTR_REAL_TIME){
			// Automatic/Manual {position}
			if(smc_pad->Set_Parameters.position > smc_pad->Set_Parameters.MAX_POSITION){
				smc_pad->Set_Parameters.position = smc_pad->Set_Parameters.MAX_POSITION;
			}else if(smc_pad->Set_Parameters.position < smc_pad->Set_Parameters.MIN_POSITION){
				smc_pad->Set_Parameters.position = smc_pad->Set_Parameters.MIN_POSITION;
			}
			
			// Automatic/Manual {velocity}
			if(smc_pad->Set_Parameters.velocity > smc_pad->Set_Parameters.MAX_VELOCITY){
				smc_pad->Set_Parameters.velocity  = smc_pad->Set_Parameters.MAX_VELOCITY;
			}else if(smc_pad->Set_Parameters.velocity < smc_pad->Set_Parameters.MIN_VELOCITY){
				smc_pad->Set_Parameters.velocity  = smc_pad->Set_Parameters.MIN_VELOCITY;
			}
		}
	}
		
	if(smc_pad->Mode.automatic.start == 1 && smc_pad->Mode.automatic.instruction == INSTR_LOWER_UPPER_LIMIT){
		// Limit {position}
		if(smc_pad->Set_Parameters.limit.position_end > smc_pad->Set_Parameters.MAX_POSITION){
			smc_pad->Set_Parameters.limit.position_end = smc_pad->Set_Parameters.MAX_POSITION;
		}else if(smc_pad->Set_Parameters.limit.position_start < smc_pad->Set_Parameters.MIN_POSITION){
			smc_pad->Set_Parameters.limit.position_start = smc_pad->Set_Parameters.MIN_POSITION;
		}
		// Limit {velocity}
		if(smc_pad->Set_Parameters.limit.velocity > smc_pad->Set_Parameters.MAX_VELOCITY){
			smc_pad->Set_Parameters.limit.velocity = smc_pad->Set_Parameters.MAX_VELOCITY;
		}else if(smc_pad->Set_Parameters.limit.velocity < smc_pad->Set_Parameters.MIN_VELOCITY){
			smc_pad->Set_Parameters.limit.velocity  = smc_pad->Set_Parameters.MIN_VELOCITY;
		}
	}
	
	if(smc_pad->Mode.automatic.start == 1 && smc_pad->Mode.automatic.instruction == INSTR_SEQUENCE){
		// Sequence {position}
		int i_pos;
		for(i_pos = 0; i_pos < 5; i_pos++){
			if(smc_pad->Set_Parameters.sequence.position[i_pos] > smc_pad->Set_Parameters.MAX_POSITION){
				smc_pad->Set_Parameters.sequence.position[i_pos] = smc_pad->Set_Parameters.MAX_POSITION;
			}else if(smc_pad->Set_Parameters.sequence.position[i_pos] < smc_pad->Set_Parameters.MIN_POSITION){
				smc_pad->Set_Parameters.sequence.position[i_pos] = smc_pad->Set_Parameters.MIN_POSITION;
			}
		}
		// Sequence {velocity}
		int i_vel;
		for(i_vel = 0; i_vel < 5; i_vel++){
			if(smc_pad->Set_Parameters.sequence.velocity[i_vel] > smc_pad->Set_Parameters.MAX_POSITION){
				smc_pad->Set_Parameters.sequence.velocity[i_vel] = smc_pad->Set_Parameters.MAX_POSITION;
			}else if(smc_pad->Set_Parameters.sequence.velocity[i_vel] < smc_pad->Set_Parameters.MIN_POSITION){
				smc_pad->Set_Parameters.sequence.velocity[i_vel] = smc_pad->Set_Parameters.MIN_POSITION;
			}
		}
	}
	
	//**************** OUTPUT VARIABLES **********************//
	// SMC PAD
	smc_pad->Actual_Parameters.position 		= smc_pad->MpAxisCyclic->Info.SlavePosition;	
	smc_pad->Actual_Parameters.velocity 		= smc_pad->MpAxisCyclic->Info.SlaveVelocity;
	smc_pad->Actual_Parameters.lagError 		= smc_pad->MpAxis->Info.CyclicRead.LagError.Value;
	smc_pad->Actual_Parameters.motorTemperature = smc_pad->MpAxis->Info.CyclicRead.MotorTemperature.Value;
	smc_pad->Actual_Parameters.torque  			= smc_pad->MpAxis->Info.CyclicRead.Torque.Value;
	
	smc_pad->Set_Parameters.set_position = smc_pad->MpAxisCyclic->Position;
	if(smc_pad->MpAxis->Velocity >= 0){
		smc_pad->Set_Parameters.set_velocity = smc_pad->MpAxisCyclicParType->PositionModeMaxVelocity;
	}else{
		smc_pad->Set_Parameters.set_velocity = (-1)*smc_pad->MpAxisCyclicParType->PositionModeMaxVelocity;
	}
	
	smc_pad->PowerOn      = smc_pad->MpAxis->PowerOn;
	smc_pad->IsHomed      = smc_pad->MpAxis->IsHomed;
	smc_pad->Actual_State = smc_pad->Internal.State;
	smc_pad->Status       = smc_pad->MpAxis->StatusID;
	smc_pad->InPosition   = smc_pad->MpAxis->InPosition;
	
	// Set default parameters
	if(smc_pad->Set_Parameters.default_parameters == 1){
		smc_pad->Set_Parameters.MAX_POSITION = smc_pad->Default_parameters.MAX_POSITION;
		smc_pad->Set_Parameters.MIN_POSITION = smc_pad->Default_parameters.MIN_POSITION;
		smc_pad->Set_Parameters.MAX_VELOCITY = smc_pad->Default_parameters.MAX_VELOCITY;
		smc_pad->Set_Parameters.MIN_VELOCITY = smc_pad->Default_parameters.MIN_VELOCITY;
	}
	// Parameters - round function
	smc_pad->Set_Parameters.position = round(smc_pad->Set_Parameters.position);
	smc_pad->Set_Parameters.velocity = round(smc_pad->Set_Parameters.velocity);
	smc_pad->Set_Parameters.limit.position_start = round(smc_pad->Set_Parameters.limit.position_start);
	smc_pad->Set_Parameters.limit.position_end   = round(smc_pad->Set_Parameters.limit.position_end);
	smc_pad->Set_Parameters.limit.velocity       = round(smc_pad->Set_Parameters.limit.velocity);
	smc_pad->Set_Parameters.sequence.position[0] = round(smc_pad->Set_Parameters.sequence.position[0]);
	smc_pad->Set_Parameters.sequence.position[1] = round(smc_pad->Set_Parameters.sequence.position[1]);
	smc_pad->Set_Parameters.sequence.position[2] = round(smc_pad->Set_Parameters.sequence.position[2]);
	smc_pad->Set_Parameters.sequence.position[3] = round(smc_pad->Set_Parameters.sequence.position[3]);
	smc_pad->Set_Parameters.sequence.position[4] = round(smc_pad->Set_Parameters.sequence.position[4]);
	smc_pad->Set_Parameters.sequence.velocity[0] = round(smc_pad->Set_Parameters.sequence.velocity[0]);
	smc_pad->Set_Parameters.sequence.velocity[1] = round(smc_pad->Set_Parameters.sequence.velocity[1]);
	smc_pad->Set_Parameters.sequence.velocity[2] = round(smc_pad->Set_Parameters.sequence.velocity[2]);
	smc_pad->Set_Parameters.sequence.velocity[3] = round(smc_pad->Set_Parameters.sequence.velocity[3]);
	smc_pad->Set_Parameters.sequence.velocity[4] = round(smc_pad->Set_Parameters.sequence.velocity[4]);
	
	// *********************************************************//
	// -------------------- CALL FUNCTIONS -------------------- //
	// *********************************************************//
	// Set wait time {Global}
	if(smc_pad->Set_Parameters.limit.mode == INSTR_TIME || smc_pad->Set_Parameters.sequence.mode == INSTR_TIME){
		smc_pad->Internal.Timer.output_time  = set_time(smc_pad->Internal.Timer.enable_time, smc_pad->Internal.Timer.wait_time);
		smc_pad->Internal.Timer.elapsed_time = ton_1.ET;
	}
}// end function block

// ************************************************************************************************************************************ //
// ------------------------------------------------------------  FUNCTIONS ------------------------------------------------------------ //
// ************************************************************************************************************************************ //

// ****************INITIALIZATION PARAMETERS **********************//
void initialization_smc_pad(struct SMC_PAD* smc_pad)
{
	// initialization state
	smc_pad->Internal.State 	   = INITIALIZATION_STATE;
	smc_pad->Internal.Before_state = INITIALIZATION_STATE;
	// reset parameters
	reset_parameters(smc_pad);
	
} // end function

// ****************RESET PARAMETERS **********************//
void reset_parameters(struct SMC_PAD* smc_pad){
	// Power & Home {Input}
	smc_pad->Power = 0;
	smc_pad->Home  = 0;
	// Parameters {Input}
	smc_pad->Absolute_Position 			 = 0;
	// Parameters Mode structure {Input}
	smc_pad->Mode.home = 0;
	smc_pad->Mode.stop = 0;
	// Mode {automatic}
	smc_pad->Mode.automatic.instruction = INSTR_REAL_TIME;
	smc_pad->Mode.automatic.start       = 0;
	// Mode {manual}
	smc_pad->Mode.manual.start          = 0;
	// Set parameters structure {Input}
	smc_pad->Set_Parameters.position = 0;
	smc_pad->Set_Parameters.velocity = 0;
	// Set parameters {limit}
	smc_pad->Set_Parameters.limit.mode = INSTR_SIGNAL;
	smc_pad->Set_Parameters.limit.position_end   = 0;
	smc_pad->Set_Parameters.limit.position_start = 0;
	smc_pad->Set_Parameters.limit.signal         = 0;
	smc_pad->Set_Parameters.limit.time[0]        = 0;
	smc_pad->Set_Parameters.limit.time[1]        = 0;
	smc_pad->Set_Parameters.limit.velocity       = 0;
	// Signal {limit/in position}
	smc_pad->Set_Parameters.limit.signal_inPos[0] = 0;
	smc_pad->Set_Parameters.limit.signal_inPos[1] = 0;
	// Set parameters {sequence}
	smc_pad->Set_Parameters.sequence.mode = INSTR_SIGNAL;
	// Set parameters {sequence/position}
	smc_pad->Set_Parameters.sequence.position[0] = 0;
	smc_pad->Set_Parameters.sequence.position[1] = 0;
	smc_pad->Set_Parameters.sequence.position[2] = 0;
	smc_pad->Set_Parameters.sequence.position[3] = 0;
	smc_pad->Set_Parameters.sequence.position[4] = 0;
	// Set parameters {sequence/velocity}
	smc_pad->Set_Parameters.sequence.velocity[0] = 0;
	smc_pad->Set_Parameters.sequence.velocity[1] = 0;
	smc_pad->Set_Parameters.sequence.velocity[2] = 0;
	smc_pad->Set_Parameters.sequence.velocity[3] = 0;
	smc_pad->Set_Parameters.sequence.velocity[4] = 0;
	// Set parameters {sequence/time}
	smc_pad->Set_Parameters.sequence.time[0] = 0;
	smc_pad->Set_Parameters.sequence.time[1] = 0;
	smc_pad->Set_Parameters.sequence.time[2] = 0;
	smc_pad->Set_Parameters.sequence.time[3] = 0;
	smc_pad->Set_Parameters.sequence.time[4] = 0;
	// Signal {sequence/in position}
	smc_pad->Set_Parameters.sequence.signal_inPos[0] = 0;
	smc_pad->Set_Parameters.sequence.signal_inPos[1] = 0;
	smc_pad->Set_Parameters.sequence.signal_inPos[2] = 0;
	smc_pad->Set_Parameters.sequence.signal_inPos[3] = 0;
	smc_pad->Set_Parameters.sequence.signal_inPos[4] = 0;
	// Actual parameters structure {output}
	smc_pad->Set_Parameters.MAX_POSITION = 0;
	smc_pad->Set_Parameters.MIN_POSITION = 0;
	smc_pad->Set_Parameters.MAX_VELOCITY = 0;
	smc_pad->Set_Parameters.MIN_POSITION = 0;
	smc_pad->Actual_Parameters.motorTemperature = 0;
	smc_pad->Actual_Parameters.position = 0;
	smc_pad->Actual_Parameters.torque = 0;
	smc_pad->Actual_Parameters.velocity = 0;
	// Other output parameters}
	smc_pad->Active = 0;
	smc_pad->Actual_State = 0;
	smc_pad->PowerOn = 0;
	smc_pad->Status = 0;
	smc_pad->InPosition = 0;
} // end function

// **************** PARAMETERS {NULL} **********************//
void parameters_null(struct SMC_PAD* smc_pad){
	// Parameters Mode structure {Input}
	smc_pad->Mode.home = 0;
	// Mode {automatic}
	smc_pad->Mode.automatic.instruction = INSTR_REAL_TIME;
	smc_pad->Mode.automatic.start       = 0;
	// Mode {manual}
	smc_pad->Mode.manual.start          = 0;
	// Set parameters structure {Input}
	smc_pad->Set_Parameters.position = 0;
	smc_pad->Set_Parameters.velocity = 0;
	// Set parameters {limit}
	smc_pad->Set_Parameters.limit.mode = INSTR_SIGNAL;
	smc_pad->Set_Parameters.limit.position_end   = 0;
	smc_pad->Set_Parameters.limit.position_start = 0;
	smc_pad->Set_Parameters.limit.signal         = 0;
	smc_pad->Set_Parameters.limit.time[0]        = 0;
	smc_pad->Set_Parameters.limit.time[1]        = 0;
	smc_pad->Set_Parameters.limit.velocity       = 0;
	// Signal {limit/in position}
	smc_pad->Set_Parameters.limit.signal_inPos[0] = 0;
	smc_pad->Set_Parameters.limit.signal_inPos[1] = 0;	
	// Set parameters {sequence}
	smc_pad->Set_Parameters.sequence.mode = INSTR_SIGNAL;
	// Set parameters {sequence/position}
	smc_pad->Set_Parameters.sequence.position[0] = 0;
	smc_pad->Set_Parameters.sequence.position[1] = 0;
	smc_pad->Set_Parameters.sequence.position[2] = 0;
	smc_pad->Set_Parameters.sequence.position[3] = 0;
	smc_pad->Set_Parameters.sequence.position[4] = 0;
	// Set parameters {sequence/velocity}
	smc_pad->Set_Parameters.sequence.velocity[0] = 0;
	smc_pad->Set_Parameters.sequence.velocity[1] = 0;
	smc_pad->Set_Parameters.sequence.velocity[2] = 0;
	smc_pad->Set_Parameters.sequence.velocity[3] = 0;
	smc_pad->Set_Parameters.sequence.velocity[4] = 0;
	// Set parameters {sequence/time}
	smc_pad->Set_Parameters.sequence.time[0] = 0;
	smc_pad->Set_Parameters.sequence.time[1] = 0;
	smc_pad->Set_Parameters.sequence.time[2] = 0;
	smc_pad->Set_Parameters.sequence.time[3] = 0;
	smc_pad->Set_Parameters.sequence.time[4] = 0;
	// Signal {sequence/in position}
	smc_pad->Set_Parameters.sequence.signal_inPos[0] = 0;
	smc_pad->Set_Parameters.sequence.signal_inPos[1] = 0;
	smc_pad->Set_Parameters.sequence.signal_inPos[2] = 0;
	smc_pad->Set_Parameters.sequence.signal_inPos[3] = 0;
	smc_pad->Set_Parameters.sequence.signal_inPos[4] = 0;
} // end function

// **************** UPDATE CYCLIC PARAMETERS **********************//
void update_cyclicParameters(struct SMC_PAD* smc_pad, LREAL position, LREAL velocity){
	if(smc_pad->MpAxisCyclic->CyclicSetActive == 1){
		smc_pad->MpAxisCyclic->CyclicPosition = 0;
	}
	
	if(smc_pad->MpAxisCyclic->CyclicSetActive == 0){
		smc_pad->MpAxisCyclicParType->PositionModeMaxVelocity = (REAL)(velocity);
		smc_pad->MpAxisCyclicParType->Acceleration            = (REAL)(smc_pad->MpAxisCyclicParType->PositionModeMaxVelocity/(fabs(position)/velocity));
		smc_pad->MpAxisCyclicParType->Deceleration            = (REAL)(smc_pad->MpAxisCyclicParType->PositionModeMaxVelocity/(fabs(position)/velocity));
	}
} // end function

// **************** SET TIME **********************//
BOOL set_time(BOOL enable, TIME t){	
	ton_1.IN = enable;
	ton_1.PT = t;
	
	TON(&ton_1);
	
	return ton_1.Q;
} // end function