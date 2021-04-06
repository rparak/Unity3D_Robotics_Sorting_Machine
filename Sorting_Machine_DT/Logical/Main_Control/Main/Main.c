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

#include <bur/plctypes.h>
#include <standard.h> 

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

// Time Function Block
_LOCAL TON_typ ton_1;
// Output Variable
_LOCAL BOOL wait_var;
// Time in ms
_LOCAL TIME wait_time;
// Auxliliary variables (Counter)
_LOCAL USINT aux_counter_main_sm_act, aux_counter_main_sm_bef;
_LOCAL USINT aux_counter_brP_sm_act, aux_counter_brP_sm_bef;
_LOCAL USINT aux_counter_smcP_sm_act, aux_counter_smcP_sm_bef;
// Offset Variables
// Initialization Pad (Start Positon)
_LOCAL LREAL offset_init_pad_x[9];
_LOCAL LREAL offset_init_pad_y[9];
// BR Pad (End Position Warehouse)
_LOCAL LREAL offset_br_pad_x[4];
_LOCAL LREAL offset_br_pad_y[4];
// SMC Pad (End Position Warehouse)
_LOCAL LREAL offset_smc_pad_x[4];
_LOCAL LREAL offset_smc_pad_y[4];

// FUNCTION // DECLARATION //
BOOL set_time(BOOL enable, TIME t);

// OBJECT TYPE
const BOOL OBJ_TYPE_BR  = 2;
const BOOL OBJ_TYPE_SMC = 1;
const BOOL OBJ_TYPE_ERR = 10;
// XYZ MANIPULATOR
const LREAL INIT_PAD_OFFSET_X  = 345.0;
const LREAL INIT_PAD_OFFSET_Y  = 660.0;
const LREAL INIT_PAD_OFFSET_Z  = 1255.0;
const LREAL INIT_CC_OFFSET_X   = 6425.0;
const LREAL INIT_CC_OFFSET_Y   = 2960.0;
const LREAL INIT_CC_OFFSET_Z   = 1072.0;
const LREAL INIT_BRW_OFFSET_X  = 2895.0;
const LREAL INIT_BRW_OFFSET_Y  = 4060.0;
const LREAL INIT_BRW_OFFSET_Z  = 1255.0;
const LREAL INIT_SMCW_OFFSET_X = 395.0;
const LREAL INIT_SMCW_OFFSET_Y = 4060.0;
const LREAL INIT_SMCW_OFFSET_Z = 1255.0;
// CAMEA CONVEYOR
const LREAL INIT_CC_MAIN_OFFSET_X = 3500;
// BOTH
const LREAL HOME_POS = 0.0;

void _INIT ProgramInit(void)
{	
	// -------------------- INITIALIZATION Digita-Twin Main Global Variable -------------------- //
	// Camera Scanning Variable
	dT_Main.camera.scan = 0;
	// Actual Position of the XYZ Manipulator and Camera Conveyor (Read from task X_AXIS_M, etc.)
	dT_Main.camera_conveyor.X.actual_position = 0;
	dT_Main.xyz_manipulator.X.actual_position = 0;
	dT_Main.xyz_manipulator.Y.actual_position = 0;
	dT_Main.xyz_manipulator.Z.actual_position = 0;
	// Mani Control State Variable
	dT_Main.service.actual_state = 0;
	// Object Control (Read / Write Variable)
	dT_Main.service.object.write.attach        = 0;
	dT_Main.service.object.write.detach        = 0;
	dT_Main.service.object.write.reset         = 0;
	dT_Main.service.object.write.set_object_id = 0;
	dT_Main.service.object.read.object_id   = 0;
	dT_Main.service.object.read.object_type = 0;
	// Initial Parameters (Velocity, Start State)
	dT_Main.xyz_manipulator.X.parameter.vel = 3500;
	dT_Main.xyz_manipulator.X.actual_state  = LINP_CTRL_WAIT_STATE;
	dT_Main.xyz_manipulator.Y.parameter.vel = 2500;
	dT_Main.xyz_manipulator.Y.actual_state  = LINP_CTRL_WAIT_STATE;
	dT_Main.xyz_manipulator.Z.parameter.vel = 2000;
	dT_Main.xyz_manipulator.Z.actual_state  = LINP_CTRL_WAIT_STATE;
	dT_Main.camera_conveyor.X.parameter.vel = 2500;
	dT_Main.camera_conveyor.X.actual_state  = LINP_CTRL_WAIT_STATE;
	
	// -------------------- INITIALIZATION Offset Parameter for the Motion -------------------- //
	// Initialization Pad (Start Positon)
	offset_init_pad_x[0] = 0.0; offset_init_pad_y[0]    = 0.0;
	offset_init_pad_x[1] = 0.0; offset_init_pad_y[1]    = 800.0;
	offset_init_pad_x[2] = 0.0; offset_init_pad_y[2]    = 1600.0;
	offset_init_pad_x[3] = 600.0; offset_init_pad_y[3]  = 0.0;
	offset_init_pad_x[4] = 600.0; offset_init_pad_y[4]  = 800.0;
	offset_init_pad_x[5] = 600.0; offset_init_pad_y[5]  = 1600.0;
	offset_init_pad_x[6] = 1200.0; offset_init_pad_y[6] = 0.0;
	offset_init_pad_x[7] = 1200.0; offset_init_pad_y[7] = 800.0;
	offset_init_pad_x[8] = 1200.0; offset_init_pad_y[8] = 1600.0;
	// BR Pad (End Position Warehouse)
	offset_br_pad_x[0] = 0.0; offset_br_pad_y[0]   = 0.0;
	offset_br_pad_x[1] = 0.0; offset_br_pad_y[1]   = 800.0;
	offset_br_pad_x[2] = 600.0; offset_br_pad_y[2] = 0.0;
	offset_br_pad_x[3] = 600.0; offset_br_pad_y[3] = 800.0;
	// SMC Pad (End Position Warehouse)
	offset_smc_pad_x[0] = 0.0; offset_smc_pad_y[0]   = 0.0;
	offset_smc_pad_x[1] = 0.0; offset_smc_pad_y[1]   = 800.0;
	offset_smc_pad_x[2] = 600.0; offset_smc_pad_y[2] = 0.0;
	offset_smc_pad_x[3] = 600.0; offset_smc_pad_y[3] = 800.0;
	
	// Wait 1 second at a certain step
	wait_time = 1000;
	
	// Reset Counters
	aux_counter_main_sm_act = aux_counter_main_sm_bef = 0;
	aux_counter_brP_sm_act  = aux_counter_brP_sm_bef  = 0;
	aux_counter_smcP_sm_act = aux_counter_smcP_sm_bef = 0;
	
}

void _CYCLIC ProgramCyclic(void)
{
	switch(dT_Main.service.actual_state){
		case 0: // INITIALIZATION STAT
			{
				if(dT_Main.camera_conveyor.X.active == 1 && dT_Main.xyz_manipulator.X.active == 1 && dT_Main.xyz_manipulator.Y.active == 1 && dT_Main.xyz_manipulator.Z.active == 1){
					dT_Main.service.mapp_view.active = 1;
					dT_Main.service.actual_state = 1;
				}
			}
			break;
		
		case 1: // POWER STATE
			{
				if(dT_Main.service.power == 1){
					if(dT_Main.camera_conveyor.X.power_on == 1 && dT_Main.xyz_manipulator.X.power_on == 1 && dT_Main.xyz_manipulator.Y.power_on == 1 && dT_Main.xyz_manipulator.Z.power_on == 1){
						dT_Main.service.mapp_view.power_on = 1;
						dT_Main.service.actual_state = 2;
					}
				}
			}
			break;
		
		case 2: // HOME STATE
			{
				if(dT_Main.service.home == 1){
					if(dT_Main.camera_conveyor.X.is_homed == 1 && dT_Main.xyz_manipulator.X.is_homed == 1 && dT_Main.xyz_manipulator.Y.is_homed == 1 && dT_Main.xyz_manipulator.Z.is_homed == 1){
						dT_Main.service.mapp_view.is_homed = 1;
						dT_Main.service.actual_state = 3;
					}
				}
			}
			break;
		
		case 3: // START STATE
			{
				if(dT_Main.service.start == 1){
					dT_Main.camera_conveyor.X.start = 1;
					dT_Main.xyz_manipulator.X.start = 1;
					dT_Main.xyz_manipulator.Y.start = 1;
					dT_Main.xyz_manipulator.Z.start = 1;	
					dT_Main.service.actual_state = 4;
				}
			}
			break;
		
		case 4: // MOVE INIT POS (1) -> OBJECT_{i} DETACHED
			{
				aux_counter_main_sm_bef = aux_counter_main_sm_act;
				aux_counter_brP_sm_bef  = aux_counter_brP_sm_act;
				aux_counter_smcP_sm_bef = aux_counter_smcP_sm_act;
			
				dT_Main.service.start = 0;
			
				dT_Main.xyz_manipulator.X.parameter.pos = INIT_PAD_OFFSET_X + offset_init_pad_x[dT_Main.service.object.read.object_id];
				dT_Main.xyz_manipulator.Y.parameter.pos = INIT_PAD_OFFSET_Y + offset_init_pad_y[dT_Main.service.object.read.object_id];
				dT_Main.xyz_manipulator.Z.parameter.pos = HOME_POS;
				dT_Main.camera_conveyor.X.parameter.pos = HOME_POS;
			
				if((dT_Main.xyz_manipulator.X.actual_position == dT_Main.xyz_manipulator.X.parameter.pos) && (dT_Main.xyz_manipulator.Y.actual_position == dT_Main.xyz_manipulator.Y.parameter.pos) && (dT_Main.xyz_manipulator.Z.actual_position == dT_Main.xyz_manipulator.Z.parameter.pos) 
				&& (dT_Main.camera_conveyor.X.actual_position == dT_Main.camera_conveyor.X.parameter.pos)){
					dT_Main.service.actual_state = 5;
				}
			
			}
			break;
		
		case 5: // MOVE INIT POS (2) -> OBJECT_{i} DETACHED
			{
				dT_Main.xyz_manipulator.Z.parameter.pos = INIT_PAD_OFFSET_Z;
			
				if(dT_Main.xyz_manipulator.Z.actual_position == dT_Main.xyz_manipulator.Z.parameter.pos){
					dT_Main.service.actual_state = 6;
				}
			
			}
			break;
		
		case 6: // MOVE INIT POS (3) -> OBJECT_{i} ATTACHED (Wait 1s)
			{
				dT_Main.service.object.write.attach = 1;
				wait_var = set_time(1, wait_time); 
			
				if(wait_var == 1){
					dT_Main.service.actual_state = 7;
					dT_Main.service.object.write.attach = 0;
					wait_var = set_time(0, wait_time);
				}
			}
			break;
		
		case 7: // MOVE INIT POS (4) -> OBJECT_{i} ATTACHED
			{
				dT_Main.xyz_manipulator.Z.parameter.pos = HOME_POS;
			
				if(dT_Main.xyz_manipulator.Z.actual_position == dT_Main.xyz_manipulator.Z.parameter.pos){
					dT_Main.service.actual_state = 8;
				}
			}
			break;
		
		case 8: // MOVE CAMERA CONVEYOR POS (1) -> OBJECT_{i} ATTACHED
			{
				dT_Main.xyz_manipulator.X.parameter.pos = INIT_CC_OFFSET_X;
				dT_Main.xyz_manipulator.Y.parameter.pos = INIT_CC_OFFSET_Y;
			
				if((dT_Main.xyz_manipulator.X.actual_position == dT_Main.xyz_manipulator.X.parameter.pos) && (dT_Main.xyz_manipulator.Y.actual_position == dT_Main.xyz_manipulator.Y.parameter.pos)){
					dT_Main.service.actual_state = 9;
				}
			}
			break;
		
		case 9: // MOVE CAMERA CONVEYOR POS (2) -> OBJECT_{i} ATTACHED
			{
				dT_Main.xyz_manipulator.Z.parameter.pos = INIT_CC_OFFSET_Z;
			
				if(dT_Main.xyz_manipulator.Z.actual_position == dT_Main.xyz_manipulator.Z.parameter.pos){
					dT_Main.service.actual_state = 10;
				}
			}
			break;
		
		case 10: // MOVE CAMERA CONVEYOR POS (3) -> OBJECT_{i} DETACHED XYZ and ATTACHED CAMERA CONVEYOR
			{
				dT_Main.service.object.write.detach = 1;
				wait_var     = set_time(1, wait_time); 
			
				if(wait_var == 1){
					dT_Main.service.actual_state = 11;
					dT_Main.service.object.write.detach = 0;
					wait_var     = set_time(0, wait_time);
				}
			}
			break;
		
		case 11: // MOVE CAMERA CONVEYOR POS (4) -> OBJECT_{i} DETACHED XYZ and ATTACHED CAMERA CONVEYOR
			{
				dT_Main.xyz_manipulator.Z.parameter.pos = HOME_POS;
				dT_Main.camera_conveyor.X.parameter.pos = INIT_CC_MAIN_OFFSET_X;
			
				if((dT_Main.xyz_manipulator.Z.actual_position == dT_Main.xyz_manipulator.Z.parameter.pos) && (dT_Main.camera_conveyor.X.actual_position == dT_Main.camera_conveyor.X.parameter.pos)){
					dT_Main.service.actual_state = 12;
				}
			}
			break;
		
		case 12: // MOVE CAMERA CONVEYOR POS (5) -> OBJECT_{i} DETACHED XYZ and ATTACHED CAMERA CONVEYOR (Wait 0.5s)
			{
				dT_Main.camera.scan          = 1;
				wait_var     = set_time(1, wait_time / 2); 
			
				if(wait_var == 1){
					dT_Main.service.actual_state = 13;
					dT_Main.camera.scan          = 0;
					wait_var     = set_time(0, wait_time);
				}
			}
			break;
		
		case 13: // MOVE CAMERA CONVEYOR POS (6) -> OBJECT_{i} DETACHED XYZ and ATTACHED CAMERA CONVEYOR
			{
				dT_Main.xyz_manipulator.Z.parameter.pos = HOME_POS;
				dT_Main.camera_conveyor.X.parameter.pos = HOME_POS;
			
				if((dT_Main.xyz_manipulator.Z.actual_position == dT_Main.xyz_manipulator.Z.parameter.pos) && (dT_Main.camera_conveyor.X.actual_position == dT_Main.camera_conveyor.X.parameter.pos)){
					dT_Main.service.actual_state = 14;
				}
			}
			break;
		
		case 14: // MOVE CAMERA CONVEYOR POS (7) -> OBJECT_{i} ATTACHED XYZ and DETACHED CAMERA CONVEYOR
			{
				dT_Main.xyz_manipulator.Z.parameter.pos = INIT_CC_OFFSET_Z;
			
				if(dT_Main.xyz_manipulator.Z.actual_position == dT_Main.xyz_manipulator.Z.parameter.pos){
					dT_Main.service.actual_state = 15;
				}
			}
			break;
		
		case 15: // MOVE CAMERA CONVEYOR POS (8) -> OBJECT_{i} ATTACHED XYZ and DETACHED CAMERA CONVEYOR (Wait 1s)
			{
				dT_Main.service.object.write.attach = 1;
				wait_var     = set_time(1, wait_time); 
			
				if(wait_var == 1){
					dT_Main.service.actual_state = 16;
					dT_Main.service.object.write.attach = 0;
					wait_var     = set_time(0, wait_time);
				}
			}
			break;
		
		case 16: // MOVE CAMERA CONVEYOR POS (9) -> OBJECT_{i} ATTACHED XYZ and DETACHED CAMERA CONVEYOR
			{
				dT_Main.xyz_manipulator.Z.parameter.pos = HOME_POS;
			
				if(dT_Main.xyz_manipulator.Z.actual_position == dT_Main.xyz_manipulator.Z.parameter.pos){
					dT_Main.service.actual_state = 17;
				}
			}
			break;
		
		case 17: // WAIT STATE -> GET THE OBJECT TYPE
			{
				if(dT_Main.service.object.read.object_type == OBJ_TYPE_ERR){
					dT_Main.service.actual_state = 20;
				}else if(dT_Main.service.object.read.object_type == OBJ_TYPE_BR){
					dT_Main.service.actual_state = 30;
				}else if(dT_Main.service.object.read.object_type == OBJ_TYPE_SMC){
					dT_Main.service.actual_state = 40;
				}
			}
			break;
		
		case 20: // TRASH STATE (1) -> OBJECT_{i} ATTACHED XYZ
			{
				dT_Main.xyz_manipulator.X.parameter.pos = 3500.0;
				dT_Main.xyz_manipulator.Y.parameter.pos = 1750.0;

				if((dT_Main.xyz_manipulator.X.actual_position == dT_Main.xyz_manipulator.X.parameter.pos) && (dT_Main.xyz_manipulator.Y.actual_position == dT_Main.xyz_manipulator.Y.parameter.pos)){
					dT_Main.service.actual_state = 21;
				}
			}
			break;
		
		case 21: // TRASH STATE (2) -> OBJECT_{i} ATTACHED XYZ
			{
				dT_Main.xyz_manipulator.Z.parameter.pos = 1000.0;
			
				if(dT_Main.xyz_manipulator.Z.actual_position == dT_Main.xyz_manipulator.Z.parameter.pos){
					dT_Main.service.actual_state = 22;
				}
			}
			break;
		
		case 22: // TRASH STATE (3) -> OBJECT_{i} DETACHED XYZ (Wait 1s)
			{
				dT_Main.service.object.write.detach = 1;
				wait_var     = set_time(1, wait_time); 
			
				if(wait_var == 1){
					dT_Main.service.actual_state = 23;
					dT_Main.service.object.write.detach = 0;
					wait_var     = set_time(0, wait_time);
				}
			}
			break;
		
		case 23: // TRASH STATE (4) -> OBJECT_{i} is in the Trash
			{
				dT_Main.xyz_manipulator.Z.parameter.pos = HOME_POS;
			
				if(dT_Main.xyz_manipulator.Z.actual_position == dT_Main.xyz_manipulator.Z.parameter.pos){
					dT_Main.service.actual_state = 50;
				}
			}
			break;
		
		case 30: // BR WAREHOUSE STATE (1) -> OBJECT_{i} ATTACHED XYZ
			{
				dT_Main.xyz_manipulator.X.parameter.pos = INIT_BRW_OFFSET_X + offset_br_pad_x[aux_counter_brP_sm_act];
				dT_Main.xyz_manipulator.Y.parameter.pos = INIT_BRW_OFFSET_Y + offset_br_pad_y[aux_counter_brP_sm_act];
			
				if((dT_Main.xyz_manipulator.X.actual_position == dT_Main.xyz_manipulator.X.parameter.pos) && (dT_Main.xyz_manipulator.Y.actual_position == dT_Main.xyz_manipulator.Y.parameter.pos)){
					dT_Main.service.actual_state = 31;
				}
			}
			break;
		
		case 31: // BR WAREHOUSE STATE (2) -> OBJECT_{i} ATTACHED XYZ
			{
				dT_Main.xyz_manipulator.Z.parameter.pos = INIT_BRW_OFFSET_Z;

				if(dT_Main.xyz_manipulator.Z.actual_position == dT_Main.xyz_manipulator.Z.parameter.pos){
					dT_Main.service.actual_state = 32;
				}
			}
			break;
		
		case 32: // BR WAREHOUSE STATE (3) -> OBJECT_{i} DETACHED XYZ (Wait 1s)
			{
				dT_Main.service.object.write.detach = 1;
				wait_var     = set_time(1, wait_time); 
			
				if(wait_var == 1){
					dT_Main.service.actual_state = 33;
					dT_Main.service.object.write.detach = 0;
					wait_var     = set_time(0, wait_time);
				}
			}
			break;
		
		case 33: // BR WAREHOUSE STATE (4) -> OBJECT_{i} is in the BR WAREHOUSE
			{
				dT_Main.xyz_manipulator.Z.parameter.pos = HOME_POS;
	
				if(dT_Main.xyz_manipulator.Z.actual_position == dT_Main.xyz_manipulator.Z.parameter.pos){
					if(aux_counter_brP_sm_act == aux_counter_brP_sm_bef){
						aux_counter_brP_sm_act = aux_counter_brP_sm_bef + 1;
					}
					
					dT_Main.service.actual_state = 50;
				}
			}
			break;
		
		case 40: // SMC WAREHOUSE STATE (1) -> OBJECT_{i} ATTACHED XYZ
			{
				dT_Main.xyz_manipulator.X.parameter.pos = INIT_SMCW_OFFSET_X + offset_smc_pad_x[aux_counter_smcP_sm_act];
				dT_Main.xyz_manipulator.Y.parameter.pos = INIT_SMCW_OFFSET_Y + offset_smc_pad_y[aux_counter_smcP_sm_act];
			
				if((dT_Main.xyz_manipulator.X.actual_position == dT_Main.xyz_manipulator.X.parameter.pos) && (dT_Main.xyz_manipulator.Y.actual_position == dT_Main.xyz_manipulator.Y.parameter.pos)){
					dT_Main.service.actual_state = 41;
				}
			}
			break;
		
		case 41: // SMC WAREHOUSE STATE (1) -> OBJECT_{i} ATTACHED XYZ
			{
				dT_Main.xyz_manipulator.Z.parameter.pos = INIT_SMCW_OFFSET_Z;
			
				if(dT_Main.xyz_manipulator.Z.actual_position == dT_Main.xyz_manipulator.Z.parameter.pos){
					dT_Main.service.actual_state = 42;
				}
			}
			break;
		
		case 42: // SMC WAREHOUSE STATE (3) -> OBJECT_{i} DETACHED XYZ (Wait 1s)
			{
				dT_Main.service.object.write.detach = 1;
				wait_var     = set_time(1, wait_time); 
			
				if(wait_var == 1){
					dT_Main.service.actual_state = 43;
					dT_Main.service.object.write.detach = 0;
					wait_var     = set_time(0, wait_time);
				}
			}
			break;
		
		case 43: // SMC WAREHOUSE STATE (4) -> OBJECT_{i} is in the SMC WAREHOUSE
			{
				dT_Main.xyz_manipulator.Z.parameter.pos = HOME_POS;
			
				if(dT_Main.xyz_manipulator.Z.actual_position == dT_Main.xyz_manipulator.Z.parameter.pos){
					
					if(aux_counter_smcP_sm_act == aux_counter_smcP_sm_bef){
						aux_counter_smcP_sm_act = aux_counter_smcP_sm_bef + 1;
					}
					
					dT_Main.service.actual_state = 50;
				}
			}
			break;
		
		case 50: // MOVE INITIALIZATION POS (1) -> COUNTER +1 
			{
				if(aux_counter_main_sm_act == aux_counter_main_sm_bef){
					aux_counter_main_sm_act = aux_counter_main_sm_bef + 1;
				}
			
				if(aux_counter_main_sm_act != 9){
					dT_Main.service.actual_state = 51;
				}else{
					dT_Main.service.actual_state = 60;
				}
			}
			break;
		
		case 51: // MOVE INITIALIZATION POS (2) -> (Wait 0.5s)
			{
				dT_Main.service.object.write.set_object_id = aux_counter_main_sm_act;
				wait_var     = set_time(1, wait_time/2); 
			
				if(wait_var == 1){
					dT_Main.service.actual_state = 4;
					wait_var     = set_time(0, wait_time);
				}
			}
			break;
		
		case 60: // MOVE INITIALIZATION POS (3) -> Reset Variables
			{
				aux_counter_main_sm_act = aux_counter_main_sm_bef = 0;
				aux_counter_brP_sm_act  = aux_counter_brP_sm_bef  = 0;
				aux_counter_smcP_sm_act = aux_counter_smcP_sm_bef = 0;
			
				dT_Main.service.object.write.set_object_id = 0;
			
				dT_Main.xyz_manipulator.X.parameter.pos = INIT_PAD_OFFSET_X + offset_init_pad_x[0];
				dT_Main.xyz_manipulator.Y.parameter.pos = INIT_PAD_OFFSET_Y + offset_init_pad_y[0];
			
				if((dT_Main.xyz_manipulator.X.actual_position == dT_Main.xyz_manipulator.X.parameter.pos) && (dT_Main.xyz_manipulator.Y.actual_position == dT_Main.xyz_manipulator.Y.parameter.pos)){
					dT_Main.service.actual_state = 61;
				}
			}
			break;
		
		case 61: // WAIT STATE -> Wait for the user to reset the startup command
			{
				if(dT_Main.service.start == 1){
					dT_Main.service.actual_state = 4;
				}
			}
			break;
		
	}
	
	// **************** MappView -> Display the scanned object ********************** //
	if(dT_Main.service.object.read.object_type == OBJ_TYPE_ERR){
		dT_Main.service.mapp_view.cam_obj_id = 3;
	}else if(dT_Main.service.object.read.object_type == OBJ_TYPE_BR){
		dT_Main.service.mapp_view.cam_obj_id = 1;
	}else if(dT_Main.service.object.read.object_type == OBJ_TYPE_SMC){
		dT_Main.service.mapp_view.cam_obj_id = 2;
	}else{
		dT_Main.service.mapp_view.cam_obj_id = 0;
	}
	
	
	// **************** MappView -> Set the position of the object in the warehouse ********************** //
	if(aux_counter_brP_sm_act == 1){
		dT_Main.service.mapp_view.br_pad_obj_id[0] = 1;
		dT_Main.service.mapp_view.br_pad_obj_id[1] = 0;
		dT_Main.service.mapp_view.br_pad_obj_id[2] = 0;
		dT_Main.service.mapp_view.br_pad_obj_id[3] = 0;
	}else if(aux_counter_brP_sm_act == 2){
		dT_Main.service.mapp_view.br_pad_obj_id[0] = 1;
		dT_Main.service.mapp_view.br_pad_obj_id[1] = 1;
		dT_Main.service.mapp_view.br_pad_obj_id[2] = 0;
		dT_Main.service.mapp_view.br_pad_obj_id[3] = 0;
	}else if(aux_counter_brP_sm_act == 3){
		dT_Main.service.mapp_view.br_pad_obj_id[0] = 1;
		dT_Main.service.mapp_view.br_pad_obj_id[1] = 1;
		dT_Main.service.mapp_view.br_pad_obj_id[2] = 1;
		dT_Main.service.mapp_view.br_pad_obj_id[3] = 0;
	}else if(aux_counter_brP_sm_act == 4){
		dT_Main.service.mapp_view.br_pad_obj_id[0] = 1;
		dT_Main.service.mapp_view.br_pad_obj_id[1] = 1;
		dT_Main.service.mapp_view.br_pad_obj_id[2] = 1;
		dT_Main.service.mapp_view.br_pad_obj_id[3] = 1;
	}
	if(aux_counter_smcP_sm_act == 1){
		dT_Main.service.mapp_view.smc_pad_obj_id[0] = 1;
		dT_Main.service.mapp_view.smc_pad_obj_id[1] = 0;
		dT_Main.service.mapp_view.smc_pad_obj_id[2] = 0;
		dT_Main.service.mapp_view.smc_pad_obj_id[3] = 0;
	}else if(aux_counter_smcP_sm_act == 2){
		dT_Main.service.mapp_view.smc_pad_obj_id[0] = 1;
		dT_Main.service.mapp_view.smc_pad_obj_id[1] = 1;
		dT_Main.service.mapp_view.smc_pad_obj_id[2] = 0;
		dT_Main.service.mapp_view.smc_pad_obj_id[3] = 0;
	}else if(aux_counter_smcP_sm_act == 3){
		dT_Main.service.mapp_view.smc_pad_obj_id[0] = 1;
		dT_Main.service.mapp_view.smc_pad_obj_id[1] = 1;
		dT_Main.service.mapp_view.smc_pad_obj_id[2] = 1;
		dT_Main.service.mapp_view.smc_pad_obj_id[3] = 0;
	}else if(aux_counter_smcP_sm_act == 4){
		dT_Main.service.mapp_view.smc_pad_obj_id[0] = 1;
		dT_Main.service.mapp_view.smc_pad_obj_id[1] = 1;
		dT_Main.service.mapp_view.smc_pad_obj_id[2] = 1;
		dT_Main.service.mapp_view.smc_pad_obj_id[3] = 1;
	}
	
	// **************** MappView -> Reset ********************** //
	if(dT_Main.service.object.write.reset == 1){
		dT_Main.service.mapp_view.br_pad_obj_id[0] = 0;
		dT_Main.service.mapp_view.br_pad_obj_id[1] = 0;
		dT_Main.service.mapp_view.br_pad_obj_id[2] = 0;
		dT_Main.service.mapp_view.br_pad_obj_id[3] = 0;
		dT_Main.service.mapp_view.smc_pad_obj_id[0] = 0;
		dT_Main.service.mapp_view.smc_pad_obj_id[1] = 0;
		dT_Main.service.mapp_view.smc_pad_obj_id[2] = 0;
		dT_Main.service.mapp_view.smc_pad_obj_id[3] = 0;
	}
}

// **************** SET TIME **********************//
BOOL set_time(BOOL enable, TIME t){	
	ton_1.IN = enable;
	ton_1.PT = t;
	
	TON(&ton_1);
	
	return ton_1.Q;
} // end function


