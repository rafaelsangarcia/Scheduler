/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 ** $Source: SchM_Tasks.c $
 * $Revision: version 10 $
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
/*  Rafael Sanchez   |      5             | reorder the state & add one touch up function*/
/*  Rodrigo Mortera  |      6             | Add one touch down function*/
/*  Rodrigo Mortera  |      7             | Add manual up & down functions*/
/*  Rafael Sanchez   |      8             | Add antipinch functions*/
/*  Rodrigo Mortera  |      9             | Add 5 seconds waiting */
/*  Rafael Sanchez   |      10            | Reorden the STMachin with comunnication in UpDown*/
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
/*int counter_1;*/ /*to active overload*/
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
<<<<<<< HEAD
	Dio_PortTooglePin(PORTCH_D, RedLed);
=======
	/*for( counter_1=0; counter_1 <= Cycles; counter_1++){}*/ /*to active overload*/
>>>>>>> Dev
	static unsigned char state = 0;
	switch(state){
	case 0: /*idle State*/
		state = appUpDown_u8_Init();
		break;

	case 1: /*Behavior UP*/
		state = appUpDown_u8_BehaviorUp();
		break;

	case 2: /*One Touch Up*/
		state = appUpDown_u8_OneTouchUp();
		break;

	case 3: /*Behavior Down*/
		state = appUpDown_u8_BehaviorDown();
		break;

	case 4: /*One Touch Down */
		state = appUpDown_u8_OneTouchDown();
		break;

	case 5: /*Manual Up*/
		state = appUpDown_u8_ManualUp();
		break;

	case 6: /*Manual Down*/
		state = appUpDown_u8_ManualDown();
		break;

	case 7: /*Antipinch Validation State */
		state = appUpDown_u8_Antipinch();
		break;

	case 8:
		state = appUpDown_u8_5sec();
		break;

	default:
		halLeds_void_TurnOnRedLed(1);
		break;
	}
}
/*============================================================================*/

/* Notice: the file ends with a blank new line to avoid compiler warnings */
