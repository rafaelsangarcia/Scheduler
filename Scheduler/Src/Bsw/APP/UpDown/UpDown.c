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
/*============================================================================*/

T_UBYTE appUpDown_u8_BehaviorUp(){
  if( appButtons_u8_PushUpButton() == 0 ){
    if(halValidation_u8_Validation500ms() == 0){
      manage = 7;
    }
  }
  else {
    appTimer_void_set_timer1();
    if(halValidation_u8_Validation500ms() == 1){
      manage = 5;
    }
  }
  return manage;
}

T_UBYTE appUpDown_u8_OneTouchUp(){
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

T_UBYTE appUpDown_u8_OneTouchDown(){
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

T_UBYTE appUpDown_u8_BehaviorDown(){
  if( appButtons_u8_PushDownButton() == 0 ){ //up_off
    if(halValidation_u8_Validation500ms() == 0){
      manage = 4;
    }
  }
  else {
    //state= 0;
    appTimer_void_set_timer1();
    if(halValidation_u8_Validation500ms() == 1){
      manage = 6;
    }

  }
  return manage;
}

T_UBYTE appUpDown_u8_ManualUp(){
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

T_UBYTE appUpDown_u8_ManualDown(){
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

T_UBYTE appUpDown_u8_Antipinch(){
  if(appButtons_u8_AntipinchButton() == 1){
    u32_Antipinch_Flag = 1;
    manage = 4;
  }
  else{
    manage = 2;
  }
  return manage;
}

T_UBYTE appUpDown_u8_5sec(){
  if (u32_lpit0_ch1_flag_counter<=5000){
    manage = 8;
    appTimer_void_set_timer1();
    halLeds_void_TurnOnGreenLed(1);
    halLeds_void_TurnOnRedLed(1);
    halLeds_void_TurnOnBlueLed(1);

  }
  else{
    manage = 0;
    appTimer_void_clear_timer1();
  }
  return manage;
}

T_UBYTE appUpDown_u8_Init(){
  if ( appButtons_u8_PushUpButton() == 1 ) {
    appTimer_void_set_timer1();
    if (appButtons_u8_Push10ms() == 1) {
      manage = 1;
    }
  }

  if (u32_Antipinch_Flag == 1){
    manage = 8;
    u32_Antipinch_Flag=0;
    appTimer_void_clear_timer1();
  }

  if (appButtons_u8_PushDownButton() == 1 ){
    appTimer_void_set_timer1();
    if (appButtons_u8_Push10ms() == 1) {
      manage = 3;
    }
  }

  if (appButtons_u8_PushUpButton() == 0 && appButtons_u8_PushDownButton() == 0) {
    appTimer_void_clear_timer1();
    halLeds_void_TurnOnGreenLed(0);
    halLeds_void_TurnOnRedLed(0);
    halLeds_void_TurnOnBlueLed(0);
  }
  return manage;
}
 /* Notice: the file ends with a blank new line to avoid compiler warnings */
