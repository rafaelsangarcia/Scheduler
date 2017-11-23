/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
* $Source: Validation.h $
* $Revision: version 3 $
* $Author: Rafael Sanchez $
* $Date: 23/Nov/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file

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
/*    Rafael Sanchez   |          1         |  Create the validate functions*/
/*    Rafael Sanchez   |          2         |  Split and add Validation functions*/
/*    Rafael Sanchez   |          3         |  Add validation prototype function*/
/*----------------------------------------------------------------------------*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/

/*typedef unsigned int u32_t;//hola=Lpit0_ch1, contador, Lpit0_ch0
typedef int s32_t;//counter*/
/* Includes */


#ifndef BSW_HAL_VALIDATION_VALIDATION_H_
#define BSW_HAL_VALIDATION_VALIDATION_H_

#include "Port.h"
#include "General.h"
//#include "Std_Types.h"
// #include "Dio.h"
 #include "Timer.h"

/*============================================================================*/
/* Constants and types */
//-------------------typedef unsigned int T_U32;
/*============================================================================*/
/* Exported Variables */

/*============================================================================*/

/*============================================================================*/
/* Exported functions prototypes */
/*============================================================================*/
T_ULONG halValidation_u32_ValidateUpButton();
T_ULONG halValidation_u32_ValidateDownButton();
T_ULONG halValidation_u32_ValidateAntipinchButton();
T_ULONG halValidation_u32_Validation10ms();
T_ULONG halValidation_u32_Validation500ms();

/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
