/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 ** $Source: SchM_Tasks.c $
 * $Revision: version 5 $
 * $Author: Rafael Sanchez $
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
/*  Rafael Sanchez   |      5             | reorder the state*/
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
		case 0:
			if ( appButtons_u32_PushUpButton() == 1 ) {
				appTimer_void_set_timer1();
				if (appButtons_u32_Push10ms() == 1) {
					state = 1;
				}
			}
			if (appButtons_u32_PushUpButton() == 0 && appButtons_u32_PushDownButton() == 0) {
				appTimer_void_clear_timer1();
			}
		break;

		case 1:
			if( appButtons_u32_PushUpButton() == 0 ){ //up_off
				if(halValidation_u32_Validation500ms() == 0){
					state = 2;
				}
			 }
		break;

		case 2: //behavior up
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
			}

		break;
	}
}



		/*case 0:
			if ( appUpDown_u32_PushUpButton() == 1 ) {
				appUpDown_void_set_timer1();
				if (appUpDown_u32_validation10ms() == 1 ){
					state = 1;
				}
			}
			if (appUpDown_u32_PushUpButton() == 1){
				appUpDown_void_clear_timer1();
			}
		break;

		case 1:
			if( appUpDown_u32_PushUpButton() == 0 ){ //up_off
				if(appUpDown_u32_validation500ms() == 0){
					//onetouch
				}
			}
			else{
				if(appUpDown_u32_validation500ms() == 1){
					appUpDown_void_ManualUp();
				}
			}
		break;*/

		/*Idlle state*/


			//Dio_PortTooglePin(PORTCH_D, RedLed);
			//appUpDown_void_clear_timer1();



	/*if ( halValidation_u32_ValidateUpButton() == 1 ) {
		appUpDown_void_set_timer1();
		if (appUpDown_u32_validation10ms() == 1 ){
			Dio_PortTooglePin(PORTCH_D, RedLed);
			appUpDown_void_clear_timer1();
		}
	}*/
/*============================================================================*/

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
