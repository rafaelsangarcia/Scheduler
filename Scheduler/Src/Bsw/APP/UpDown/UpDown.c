/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: UpDown.c $
 * $Revision: version 3 $
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
/*   Rafael Sanchez   |         2           |  Reorden and split functions    */
/*   Rafael Sanchez   |         3           |  Add functions behaviors with its action*/
/*   and match with the main state machine                                    */
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
T_SLONG s32_switch_flag = -1;
T_ULONG u32_Antipinch_Flag = 0;

T_UBYTE manage = 0;
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

T_UBYTE app_void_behaviorUp(){
  if( appButtons_u32_PushUpButton() == 0 ){ //up_off
    if(halValidation_u32_Validation500ms() == 0){
      manage = 7;
    }
  }
  else {
    appTimer_void_set_timer1();
    if(halValidation_u32_Validation500ms() == 1){
      manage = 5;
    }
  }
  return manage;
}

T_UBYTE app_void_oneTouchUp(){
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
      break;
    }
    appTimer_void_clear_timer0();
    if(s32_switch_flag < 9){
      manage = 7;
    }
    else {
      manage = 0;
    }
  }
  return manage;
}

T_UBYTE app_void_oneTouchDown(){
  if (s32_switch_flag < 0) {
    manage = 0;
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
        manage = 0;
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
  return manage;
}

T_UBYTE app_void_behaviorDown(){
  if( appButtons_u32_PushDownButton() == 0 ){ //up_off
    if(halValidation_u32_Validation500ms() == 0){
      manage = 4;
    }
  }
  else {
    //state= 0;
    appTimer_void_set_timer1();
    if(halValidation_u32_Validation500ms() == 1){
      manage = 6;
    }

  }
  return manage;
}

T_UBYTE appUpDown_void_ManualUp(){
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
      halLeds_void_TurnOnBlueLed(0);
      halLeds_void_TurnOnLedBar10(1);
      manage = 0;
      break;
    }
    appTimer_void_clear_timer0();
    manage = 0;
  }
  return manage;
}

T_UBYTE appUpDown_void_ManualDown(){
  if (s32_switch_flag < 0) {
    manage = 0;
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
        manage = 0;
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
        halLeds_void_TurnOnLedBar10(0);

        break;
      }
      if (s32_switch_flag>0) {
        s32_switch_flag--;
      }
      appTimer_void_clear_timer0();
      halLeds_void_TurnOnGreenLed(0);
      manage = 0;
    }
  }
  return manage;
}

T_UBYTE appUpDown_void_antipinch(){
  if(appButtons_u32_AntipinchButton() == 1){
    u32_Antipinch_Flag = 1;
    manage = 4;
  }
  else{
    manage = 2;
  }
  return manage;
}

T_UBYTE appDown_void_5sec(){
  if (u32_lpit0_ch1_flag_counter<=5000){
    manage = 8;
    appTimer_void_set_timer1();
  }
  else{
    manage = 0;
    appTimer_void_clear_timer1();
  }
  return manage;
}

T_UBYTE appUpDown_Init(){
  if ( appButtons_u32_PushUpButton() == 1 ) {
    appTimer_void_set_timer1();
    if (appButtons_u32_Push10ms() == 1) {
      manage = 1;
    }
  }

  if (u32_Antipinch_Flag == 1){
    manage = 8;
    u32_Antipinch_Flag=0;
    appTimer_void_clear_timer1();
  }

  if (appButtons_u32_PushDownButton() == 1 ){
    appTimer_void_set_timer1();
    if (appButtons_u32_Push10ms() == 1) {
      manage = 3;
    }
  }

  if (appButtons_u32_PushUpButton() == 0 && appButtons_u32_PushDownButton() == 0) {
    appTimer_void_clear_timer1();
  }
  return manage;
}

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
