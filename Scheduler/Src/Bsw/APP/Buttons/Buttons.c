/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Buttons.c $
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
/*   Rafael Sanchez   |         1           | Create the buttons functions*/
/*   Rafael Sanchez   |         2           | Add antipinch validation callback*/
/*----------------------------------------------------------------------------*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $

  ============================================================================*/
/* Includes */
#include "Buttons.h"
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
/*============================================================================*/
T_ULONG appButtons_u32_PushUpButton(){
	if(halValidation_u32_ValidateUpButton()){
		return 1;
	}
	else{
		return 0;
	}
}
T_ULONG appButtons_u32_PushDownButton(){
	if(halValidation_u32_ValidateDownButton()){
		return 1;
	}
	else{
		return 0;
	}
}
T_ULONG appButtons_u32_AntipinchButton(){
	if(halValidation_u32_ValidateAntipinchButton()){
		return 1;
	}
	else{
		return 0;
	}
}
T_ULONG appButtons_u32_Push10ms(){
	if(halValidation_u32_Validation10ms()){
		return 1;
	}
	else{
		return 0;
	}
}
 /* Notice: the file ends with a blank new line to avoid compiler warnings */
