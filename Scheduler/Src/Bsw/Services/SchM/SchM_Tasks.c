/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 ** $Source: SchM_Tasks.c $
 * $Revision: version 9 $
 * $Author: Rodrigo Mortera $
 * $Date: 23/Nov/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    short description in one sentence end with dot.
    detailed
    multiline
    description of the file
 */
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2014                                  */
/* AUTOMOTIVE GROUP, Interior Division, Body and Security                     */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
/*============================================================================*/
/*                    REUSE HISTORY - taken over from                         */
/*============================================================================*/
/*  Author           |        Version     |           DESCRIPTION             */
/*----------------------------------------------------------------------------*/
/*  Rafael Sanchez   |      1             |  Use the template and add the code*/
/*  Rafael Sanchez   |      2             | Fill each task turning on/off leds*/
/*  Rafael Sanchez   |      3             | add SchM_1ms_Task*/
/*  Rafael Sanchez   |      4             | add start to build STATEMACHINE*/
/*  Rafael Sanchez   |      5             | reorder the state & add one touch up function*/
/*  Rodrigo Mortera  |      6             | Add one touch down function*/
/*  Rodrigo Mortera  |      7             | Add manual up & down functions*/
/*  Rafael Sanchez   |      8             | Add antipinch functions*/
/*  Rodrigo Mortera  |      9             | Add 5 seconds waiting */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
#include "SchM_Tasks.h"
/*#include "UpDown.h"
#include "Buttons.h"*/

/*============================================================================*/

/* Constants and types  */
/*============================================================================*/

/* Variables */
T_SLONG s32_switch_flag = -1;
T_ULONG u32_Antipinch_Flag = 0;
/*============================================================================*/

/* Private functions prototypes */
/*============================================================================*/

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/

/** Check if action is allowed by overload protection.
 To avoid overheating of the door locking motors and hardware failure
 the software shall limit the number of activations in a short period.
 This function checks if the limitation algorithm allows or not
 a certain activation of the motors.
 \returns TRUE if the activation is allowed, FALSE if not
 */

/* Exported functions */
void SchM_1ms_Task ( void ){
	static unsigned char state = 0;
	switch(state){
	case 0: /*idle State*/
		if ( appButtons_u32_PushUpButton() == 1 ) {
			appTimer_void_set_timer1();
			if (appButtons_u32_Push10ms() == 1) {
				state = 1;
			}
		}

		if (u32_Antipinch_Flag == 1){
			state = 8;
			u32_Antipinch_Flag=0;
			appTimer_void_clear_timer1();
		}

		if (appButtons_u32_PushDownButton() == 1 ){
			appTimer_void_set_timer1();
			if (appButtons_u32_Push10ms() == 1) {
				state = 3;
			}
		}

		if (appButtons_u32_PushUpButton() == 0 && appButtons_u32_PushDownButton() == 0) {
			appTimer_void_clear_timer1();
		}
		break;

	case 1: /*Behavior UP*/
		if( appButtons_u32_PushUpButton() == 0 ){ //up_off
			if(halValidation_u32_Validation500ms() == 0){
				//state = 2;
				state = 7;
			}
		}
		else {
			//state= 0;
			appTimer_void_set_timer1();
			if(halValidation_u32_Validation500ms() == 1){
				state = 5;
			}

		}

		break;

	case 2: /*One Touch Up*/
		halLeds_void_TurnOnBlueLed(1);
		halLeds_void_TurnOnGreenLed(0);
		appTimer_void_set_timer0();
		if (u32_lpit0_ch0_flag_counter == 400){
			if (s32_switch_flag<9) {
				s32_switch_flag++;
			}
			switch (s32_switch_flag) {
			case 0:
				halLeds_void_TurnOnLedBar1(1);
				break;

			case 1:
				halLeds_void_TurnOnLedBar2(1);
				break;

			case 2:
				halLeds_void_TurnOnLedBar3(1);
				break;

			case 3:
				halLeds_void_TurnOnLedBar4(1);
				break;

			case 4:
				halLeds_void_TurnOnLedBar5(1);
				break;

			case 5:
				halLeds_void_TurnOnLedBar6(1);
				break;

			case 6:
				halLeds_void_TurnOnLedBar7(1);
				break;

			case 7:
				halLeds_void_TurnOnLedBar8(1);
				break;

			case 8:
				halLeds_void_TurnOnLedBar9(1);
				break;

			case 9:
				//halWinMov_void_ToggleBlueLed(0); /* Toggle output on port D0 (blue LED) */
				halLeds_void_TurnOnBlueLed(0);
				halLeds_void_TurnOnLedBar10(1);
				state = 0;
				break;
			}
			appTimer_void_clear_timer0();
			if(s32_switch_flag < 9){
				state = 7;
			}
		}

		break;

	case 3: /*Behavior Down*/
		if( appButtons_u32_PushDownButton() == 0 ){ //up_off
			if(halValidation_u32_Validation500ms() == 0){
				state = 4;
			}
		}
		else {
			//state= 0;
			appTimer_void_set_timer1();
			if(halValidation_u32_Validation500ms() == 1){
				state = 6;
			}

		}
		break;

	case 4: /*One Touch Down */
		if (s32_switch_flag < 0) {
			state = 0;
		}
		else{
			halLeds_void_TurnOnBlueLed(0);
			halLeds_void_TurnOnGreenLed(1);
			appTimer_void_set_timer0();

			if (u32_lpit0_ch0_flag_counter == 400){

				switch (s32_switch_flag) {
				case 0:
					halLeds_void_TurnOnLedBar1(0);
					halLeds_void_TurnOnGreenLed(0);
					s32_switch_flag= -1;
					state = 0;
					break;

				case 1:
					halLeds_void_TurnOnLedBar2(0);
					break;

				case 2:
					halLeds_void_TurnOnLedBar3(0);
					break;

				case 3:
					halLeds_void_TurnOnLedBar4(0);
					break;

				case 4:
					halLeds_void_TurnOnLedBar5(0);
					break;

				case 5:
					halLeds_void_TurnOnLedBar6(0);
					break;

				case 6:
					halLeds_void_TurnOnLedBar7(0);
					break;

				case 7:
					halLeds_void_TurnOnLedBar8(0);
					break;

				case 8:
					halLeds_void_TurnOnLedBar9(0);
					break;

				case 9:
					//halWinMov_void_ToggleBlueLed(0); /* Toggle output on port D0 (blue LED) */
					halLeds_void_TurnOnLedBar10(0);

					break;
					default:
				break;
				}
				if (s32_switch_flag>0) {
					s32_switch_flag--;
				}
				appTimer_void_clear_timer0();
			}
		}
		break;

	case 5: /*Manual Up*/
		halLeds_void_TurnOnBlueLed(1);
		halLeds_void_TurnOnGreenLed(0);
		appTimer_void_set_timer0();
		if (u32_lpit0_ch0_flag_counter == 400){
			if (s32_switch_flag<9) {
				s32_switch_flag++;
			}
			switch (s32_switch_flag) {
			case 0:
				halLeds_void_TurnOnLedBar1(1);
				break;

			case 1:
				halLeds_void_TurnOnLedBar2(1);
				break;

			case 2:
				halLeds_void_TurnOnLedBar3(1);
				break;

			case 3:
				halLeds_void_TurnOnLedBar4(1);
				break;

			case 4:
				halLeds_void_TurnOnLedBar5(1);
				break;

			case 5:
				halLeds_void_TurnOnLedBar6(1);
				break;

			case 6:
				halLeds_void_TurnOnLedBar7(1);
				break;

			case 7:
				halLeds_void_TurnOnLedBar8(1);
				break;

			case 8:
				halLeds_void_TurnOnLedBar9(1);
				break;

			case 9:
				//halWinMov_void_ToggleBlueLed(0); /* Toggle output on port D0 (blue LED) */
				halLeds_void_TurnOnBlueLed(0);
				halLeds_void_TurnOnLedBar10(1);
				state = 0;
				break;
			}
			appTimer_void_clear_timer0();
			state = 0;
		}

		break;

	case 6: /*Manual Down*/
		if (s32_switch_flag < 0) {
			state = 0;
		}
		else {
			halLeds_void_TurnOnBlueLed(0);
			halLeds_void_TurnOnGreenLed(1);
			appTimer_void_set_timer0();
			if (u32_lpit0_ch0_flag_counter == 400){

				switch (s32_switch_flag) {
				case 0:
					halLeds_void_TurnOnLedBar1(0);
					s32_switch_flag= -1;
					state = 0;
					break;

				case 1:
					halLeds_void_TurnOnLedBar2(0);
					break;

				case 2:
					halLeds_void_TurnOnLedBar3(0);
					break;

				case 3:
					halLeds_void_TurnOnLedBar4(0);
					break;

				case 4:
					halLeds_void_TurnOnLedBar5(0);
					break;

				case 5:
					halLeds_void_TurnOnLedBar6(0);
					break;

				case 6:
					halLeds_void_TurnOnLedBar7(0);
					break;

				case 7:
					halLeds_void_TurnOnLedBar8(0);
					break;

				case 8:
					halLeds_void_TurnOnLedBar9(0);
					break;

				case 9:
					//halWinMov_void_ToggleBlueLed(0); /* Toggle output on port D0 (blue LED) */
					halLeds_void_TurnOnLedBar10(0);

					break;
				}
				if (s32_switch_flag>0) {
					s32_switch_flag--;
				}
				appTimer_void_clear_timer0();
				state = 0;

				halLeds_void_TurnOnGreenLed(0);
			}
		}
		break;

	case 7: /*Antipinch Validation State */
		if(appButtons_u32_AntipinchButton() == 1){
			u32_Antipinch_Flag = 1;
			state = 4;
		}
		else{
			state = 2;
		}
		break;

	case 8:
		if (u32_lpit0_ch1_flag_counter<=5000){
			state = 8;
			appTimer_void_set_timer1();
		}
		else{
			state = 0;
			appTimer_void_clear_timer1();
		}
		break;
	}


}
/*============================================================================*/

/* Notice: the file ends with a blank new line to avoid compiler warnings */
