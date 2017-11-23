/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: UpDown.c $
 * $Revision: version 2 $
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
/*  DATABASE           |        VERSION      | DESCRIPTION                    */
/*----------------------------------------------------------------------------*/
/*   Rafael Sanchez   |         1           |  Validate and turn on the red led*/
/*   Rafael Sanchez   |         2           |  Reorden and split functions*/
/*----------------------------------------------------------------------------*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $

  ============================================================================*/
/* Includes */
#include "UpDown.h"
/*============================================================================*/
/* Constants and types  */
/*============================================================================*/
/* Variables */
//T_SLONG s32_switch_flag = -1;
/*T_ULONG u32_lpit0_ch0_flag_counter = 0;
T_ULONG u32_lpit0_ch1_flag_counter = 0;*/
/*============================================================================*/
/* Private functions prototypes */
//void appUpDown_void_timer0();
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
/*============================================================================*/

/*void app_void_behaviorUp(){
  if( appButtons_u32_PushUpButton() == 0 ){ //up_off
    if(halValidation_u32_Validation500ms() == 0){
      app_void_oneTouchUp();
    }
   }
  else{
    if(halValidation_u32_Validation500ms() == 1){
    	appUpDown_void_ManualUp();
    }
  }
}*/

/*void app_void_oneTouchUp(){
	for ( int states = 0 ; states <= 9; states++){
		//appUpDown_void_ManualUp();
    if (u32_lpit0_ch0_flag_counter == 400){
      switch(states){
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
  				//halWinMov_void_ToggleBlueLed(0);
  				halLeds_void_TurnOnBlueLed(0);
  				halLeds_void_TurnOnLedBar10(1);
  			break;
      }
    }
	}
}
*/
/*void appUpDown_void_ManualUp() {
  halLeds_void_TurnOnBlueLed(1);
  halLeds_void_TurnOnGreenLed(0);
	if (s32_switch_flag<9) {
		s32_switch_flag++;
		}
	else{
	}
	appTimer_void_set_timer0();
	if (u32_lpit0_ch0_flag_counter == 400){
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
				//halWinMov_void_ToggleBlueLed(0);
				halLeds_void_TurnOnBlueLed(0);
				halLeds_void_TurnOnLedBar10(1);
			break;
		}
		appTimer_void_clear_timer0();
	}
}*/
//
// void appUpDown_void_ManualDown() {
// 	halWinMov_void_ToggleBlueLed(0);//Blue led off
// 	halWinMov_void_ToggleGreenLed(1); /*Green Led On*/
// 	appUpDown_void_timer0();
// 	switch (s32_switch_flag) {
// 		case 9:
// 			halWinMov_void_ToggleLedBar10(0); /* Toggle output on port D0 (blue LED) */
// 			break;
//
// 		case 8:
// 			halWinMov_void_ToggleLedBar9(0);/* Toggle output on port D0 (blue LED) */
// 			break;
//
// 		case 7:
// 			halWinMov_void_ToggleLedBar8(0); /* Toggle output on port D0 (blue LED) */
// 			break;
//
// 		case 6:
// 			halWinMov_void_ToggleLedBar7(0); /* Toggle output on port D0 (blue LED) */
// 			break;
//
// 		case 5:
// 			halWinMov_void_ToggleLedBar6(0); /* Toggle output on port D0 (blue LED) */
// 			break;
//
// 		case 4:
// 			halWinMov_void_ToggleLedBar5(0); /* Toggle output on port D0 (blue LED) */
// 			break;
//
// 		case 3:
// 			halWinMov_void_ToggleLedBar4(0); /* Toggle output on port D0 (blue LED) */
// 			break;
//
// 		case 2:
// 			halWinMov_void_ToggleLedBar3(0); /* Toggle output on port D0 (blue LED) */
// 			break;
//
// 		case 1:
// 			halWinMov_void_ToggleLedBar2(0); /* Toggle output on port D0 (blue LED) */
// 			break;
//
// 		case 0:
// 			halWinMov_void_ToggleLedBar1(0); /* Toggle output on port D16 (green LED) */
// 			s32_switch_flag=-1;
// 			break;
//
// 		default:
// 			break;
// 	}
// 	if (s32_switch_flag>0){
// 		s32_switch_flag--;
// 	}
// }

/*void appUpDown_void_clearGPIO() {
	halWinMov_void_ToggleBlueLed(0);
	halWinMov_void_ToggleRedLed(0);
	halWinMov_void_ToggleGreenLed(0);
	halWinMov_void_ToggleLedBar1(0);
	halWinMov_void_ToggleLedBar2(0);
	halWinMov_void_ToggleLedBar3(0);
	halWinMov_void_ToggleLedBar4(0);
	halWinMov_void_ToggleLedBar5(0);
	halWinMov_void_ToggleLedBar6(0);
	halWinMov_void_ToggleLedBar7(0);
	halWinMov_void_ToggleLedBar8(0);
	halWinMov_void_ToggleLedBar9(0);
	halWinMov_void_ToggleLedBar10(0);
}*/

// T_U32 appUpDown_u32_PushAntipinch(){
// 	if(halWinMov_u32_ValidateAntipinch()){
// 			return 1;
// 		}
// 		else{
// 			return 0;
// 		}
// }
//
// void appUpDown_void_default_Leds(T_U32 u32_led) {
// 	switch(u32_led){
// 		case 0:
// 			halWinMov_void_ToggleBlueLed(0);
// 			halWinMov_void_ToggleGreenLed(0);
// 			halWinMov_void_ToggleRedLed(0);
// 			break;
//
// 		case 1:
// 			halWinMov_void_ToggleBlueLed(0);
// 			break;
//
// 		case 2:
// 			halWinMov_void_ToggleGreenLed(0);
// 			break;
//
// 		case 3:
// 			halWinMov_void_ToggleRedLed(1);
// 			break;
//
// 		default:
// 			halWinMov_void_ToggleBlueLed(1);
// 			halWinMov_void_ToggleGreenLed(1);
// 			halWinMov_void_ToggleRedLed(1);
// 			break;
// 	}
// }
 /* Notice: the file ends with a blank new line to avoid compiler warnings */
