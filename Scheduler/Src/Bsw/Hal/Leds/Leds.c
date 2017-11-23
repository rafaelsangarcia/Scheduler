/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Leds.c $
 * $Revision: version 1 $
 * $Author: Rafael Sanchez $
 * $Date: 23/Nov/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    In this Win_Mov.c file, there are the function Timer, validation_10ms,
		validation_500ms, Manual_up and Manual_down.
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2014                                  */
/* AUTOMOTIVE GROUP, T_ULONGerior Division, Body and Security                     */
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
/*  Author         	   |        Version     | Descritpion					  */
/*----------------------------------------------------------------------------*/
/*    Rafael Sanchez   |         1          |   Create the Led behavior functions  */
/*----------------------------------------------------------------------------*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
 *
  ============================================================================*/

/* Includes */

#include "Leds.h"
/*============================================================================*/
/* Constants and types  */
/*============================================================================*/
/* Variables */
/*============================================================================*/
/* Private functions prototypes */
/*============================================================================*/
/* Inline functions */
/*============================================================================*/
/* Private functions */
/*============================================================================*/
/* Exported functions */
// leds 0 prende , barled 1 prende
void halLeds_void_TurnOnBlueLed(T_ULONG u32_status){
  switch (u32_status) {
    case 0:
      Dio_PortSetPin(PORTCH_D, BlueLed);
    break;

    case 1:
      Dio_PortClearPin(PORTCH_D, BlueLed);
    break;
  }
}
void halLeds_void_TurnOnGreenLed(T_ULONG u32_status){
  switch (u32_status) {
    case 0:
      Dio_PortSetPin(PORTCH_D, GreenLed);
    break;

    case 1:
      Dio_PortClearPin(PORTCH_D, GreenLed);
    break;
  }
}
void halLeds_void_TurnOnRedLed(T_ULONG u32_status){
  switch (u32_status) {
    case 0:
      Dio_PortSetPin(PORTCH_D, RedLed);
    break;

    case 1:
      Dio_PortClearPin(PORTCH_D, RedLed);
    break;
  }
}
void halLeds_void_TurnOnLedBar1(T_ULONG u32_status){
  switch (u32_status) {
    case 0:
      Dio_PortClearPin(PORTCH_C, LedBar_1);
    break;

    case 1:
      Dio_PortSetPin(PORTCH_C, LedBar_1);
    break;
  }
}
void halLeds_void_TurnOnLedBar2(T_ULONG u32_status){
  switch (u32_status) {
    case 0:
      Dio_PortClearPin(PORTCH_B, LedBar_2);
    break;

    case 1:
      Dio_PortSetPin(PORTCH_B, LedBar_2);
    break;
  }
}
void halLeds_void_TurnOnLedBar3(T_ULONG u32_status){
  switch (u32_status) {
    case 0:
      Dio_PortClearPin(PORTCH_B, LedBar_3);
    break;

    case 1:
      Dio_PortSetPin(PORTCH_B, LedBar_3);
    break;
  }
}
void halLeds_void_TurnOnLedBar4(T_ULONG u32_status){
  switch (u32_status) {
    case 0:
      Dio_PortClearPin(PORTCH_B, LedBar_4);
    break;

    case 1:
      Dio_PortSetPin(PORTCH_B, LedBar_4);
    break;
  }
}
void halLeds_void_TurnOnLedBar5(T_ULONG u32_status){
  switch (u32_status) {
    case 0:
      Dio_PortClearPin(PORTCH_B, LedBar_5);
    break;

    case 1:
      Dio_PortSetPin(PORTCH_B, LedBar_5);
    break;
  }
}
void halLeds_void_TurnOnLedBar6(T_ULONG u32_status){
  switch (u32_status) {
    case 0:
      Dio_PortClearPin(PORTCH_C, LedBar_6);
    break;

    case 1:
      Dio_PortSetPin(PORTCH_C, LedBar_6);
    break;
  }
}
void halLeds_void_TurnOnLedBar7(T_ULONG u32_status){
  switch (u32_status) {
    case 0:
      Dio_PortClearPin(PORTCH_C, LedBar_7);
    break;

    case 1:
      Dio_PortSetPin(PORTCH_C, LedBar_7);
    break;
  }
}
void halLeds_void_TurnOnLedBar8(T_ULONG u32_status){
  switch (u32_status) {
    case 0:
      Dio_PortClearPin(PORTCH_E, LedBar_8);
    break;

    case 1:
      Dio_PortSetPin(PORTCH_E, LedBar_8);
    break;
  }
}
void halLeds_void_TurnOnLedBar9(T_ULONG u32_status){
  switch (u32_status) {
    case 0:
      Dio_PortClearPin(PORTCH_E, LedBar_9);
    break;

    case 1:
      Dio_PortSetPin(PORTCH_E, LedBar_9);
    break;
  }
}
void halLeds_void_TurnOnLedBar10(T_ULONG u32_status){
  switch (u32_status) {
    case 0:
      Dio_PortClearPin(PORTCH_E, LedBar_10);
    break;

    case 1:
      Dio_PortSetPin(PORTCH_E, LedBar_10);
    break;
  }
}

/*============================================================================*/
 /* Notice: the file ends with a blank new line to avoid compiler warnings */
