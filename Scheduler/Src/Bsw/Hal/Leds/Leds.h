/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
* $Source: Leds.h $
* $Revision: version 1 $
* $Author: Rafael Sanchez $
* $Date: 23/Nov/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    In this Win_Mov.h file, there are the prototypes function Timer, validation_10ms,
    validation_500ms, Manual_up and Manual_down.
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
/*  Author         	   |        Version     | Descritpion											*/
/*----------------------------------------------------------------------------*/
/*    Rafael Sanchez   |          1         |  Create the Prototypes led behavior functions*/
/*----------------------------------------------------------------------------*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/

/* Includes */
#ifndef BSW_HAL_LEDS_LEDS_H_
#define BSW_HAL_LEDS_LEDS_H_

//#include "Std_Types.h"
#include "Dio.h"
#include "Port.h"
/*============================================================================*/
/* Constants and types */
/*============================================================================*/
/* Exported Variables */
/*============================================================================*/
/*============================================================================*/
/* Exported functions prototypes */
/*============================================================================*/
void halLeds_void_TurnOnBlueLed(T_UBYTE);
void halLeds_void_TurnOnGreenLed(T_UBYTE);
void halLeds_void_TurnOnRedLed(T_UBYTE);
void halLeds_void_TurnOnLedBar1(T_UBYTE);
void halLeds_void_TurnOnLedBar2(T_UBYTE);
void halLeds_void_TurnOnLedBar3(T_UBYTE);
void halLeds_void_TurnOnLedBar4(T_UBYTE);
void halLeds_void_TurnOnLedBar5(T_UBYTE);
void halLeds_void_TurnOnLedBar6(T_UBYTE);
void halLeds_void_TurnOnLedBar7(T_UBYTE);
void halLeds_void_TurnOnLedBar8(T_UBYTE);
void halLeds_void_TurnOnLedBar9(T_UBYTE);
void halLeds_void_TurnOnLedBar10(T_UBYTE);
/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
