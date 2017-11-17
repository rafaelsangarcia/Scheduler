/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 ** $Source: SchM_Tasks.c $
 * $Revision: version 2 $
 * $Author: Rafael Sanchez $
 * $Date: 17/Nov/2017 $
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
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
#include "SchM_Tasks.h"
#include "Dio.h"

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

/** Check if action is allowed by overload protection.
 To avoid overheating of the door locking motors and hardware failure
 the software shall limit the number of activations in a short period.
 This function checks if the limitation algorithm allows or not
 a certain activation of the motors.
 \returns TRUE if the activation is allowed, FALSE if not
*/

/* Exported functions */
void SchM_3p125ms_Task ( void ){
	Dio_PortTooglePin(PORTCH_C, LedBar_1);
		static int counter;
		for(counter=0; counter <= Cycles; counter++){}
}
void SchM_6p25ms_Task ( void ){
	Dio_PortTooglePin(PORTCH_B, LedBar_2);
	static int counter;
	for(counter=0; counter <= Cycles; counter++){}
	/* Task Body */
}
void SchM_12p5ms_Task ( void ){
	/* Task Body */
	Dio_PortTooglePin(PORTCH_B, LedBar_3);
	static int counter;
	for(counter=0; counter <= Cycles; counter++){}
}
void SchM_25ms_Task ( void ){
	Dio_PortTooglePin(PORTCH_B, LedBar_4);
	static int counter;
	for(counter=0; counter <= Cycles; counter++){}
	/* Task Body */
}
void SchM_50ms_Task ( void ){
	Dio_PortTooglePin(PORTCH_B, LedBar_5);
	static int counter;
	for(counter=0; counter <= Cycles; counter++){}
	/* Task Body */
}
void SchM_100ms_Task ( void ){
	Dio_PortTooglePin(PORTCH_C, LedBar_6);
	static int counter;
	for(counter=0;counter <= Cycles; counter++){}
}
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */
