/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Validation.c $
 * $Revision: version  2$
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
/* AUTOMOTIVE GROUP, T_U32erior Division, Body and Security                     */
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
/*    Rafael Sanchez   |         1          |   Create validate function      */
/*    Rafael Sanchez   |         2          |   plite and add validate fucntions      */
/*----------------------------------------------------------------------------*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
 *
  ============================================================================*/

/* Includes */

#include "Validation.h"
//#include "General.h"
//#include "Port.h"

/*============================================================================*/
/* Constants and types  */
/*============================================================================*/
/* Variables */
/*T_ULONG u32_lpit0_ch0_flag_counter = 0;
T_ULONG u32_lpit0_ch1_flag_counter = 0;*/
/*============================================================================*/
/* Private functions prototypes */
/*============================================================================*/
/* Inline functions */
/*============================================================================*/
/* Private functions */
/*============================================================================*/
/* Exported functions */

T_ULONG halValidation_u32_ValidateUpButton(){
	if(PTC->PDIR & (1<<UpButton)){
			return 1;
		}
		else{
			return 0;
		}
}
T_ULONG halValidation_u32_ValidateDownButton(){
	if(PTC->PDIR & (1<<DownButton)){
			return 1;
		}
		else{
			return 0;
		}
}
T_ULONG halValidation_u32_Validation10ms() {
	if (u32_lpit0_ch1_flag_counter >= 10) {
		return 1;
	}
	else {
		return 0;
	}
}
T_ULONG halValidation_u32_Validation500ms() {
	if (u32_lpit0_ch1_flag_counter >= 500) {
		return 1;
	}
	else {
		return 0;
	}
}

/*T_U32 halValidation_u32_ValidateAntipinch(){
	if(PTE->PDIR & (1<<Antipinch)){
				return 1;
			}
			else{
				return 0;
			}
}*/
/*============================================================================*/
 /* Notice: the file ends with a blank new line to avoid compiler warnings */