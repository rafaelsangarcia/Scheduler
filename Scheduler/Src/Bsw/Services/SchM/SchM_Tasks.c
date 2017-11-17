/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 ** $Source: SchM_Tasks.c $
 * $Revision: version 1 $
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
// uint8 algreqg_olp_CheckOLPAllow(uint8 ReqestedAction_u8,       /**< the requested action to be performed (e.g. unlock) */
//                                 uint16 RequestedComponent_u16  /**< the mask of the doors which motors to be activated (e.g. front doors) */
//                                 )
// {
// 	return 0;
// }


/* Exported functions */
void SchM_3p125ms_Task ( void ){
		//MAL********
	static int counter = 0;
	counter++;
	if(counter == 1000){
	/* Task Body */
		Dio_PortSetPin(PORTCH_D, 15);
	}
	/* ....   */
	if (counter == 2000){

		Dio_PortClearPin(PORTCH_D, 15);
		counter=0;
	}
}
void SchM_6p25ms_Task ( void ){
	/* Task Body */
}
void SchM_12p5ms_Task ( void ){
	/* Task Body */
}
void SchM_25ms_Task ( void ){
	/* Task Body */
}
void SchM_50ms_Task ( void ){
	/* Task Body */
}
void SchM_100ms_Task ( void ){
	static int counter = 0;
	counter++;
	if(counter == 10){
	/* Task Body */
		Dio_PortSetPin(PORTCH_D, 0);
	}
	/* ....   */
	if (counter == 20){

		Dio_PortClearPin(PORTCH_D, 0);
		counter=0;
	}
	/* Task Body */
}
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */
