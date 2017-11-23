/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: UpDown.h $
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
/*  DATABASE           |        PROJECT     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/* Rafael Sanchez       |         1         | Prototype creations to up & down the window*/
/* Rafael Sanchez       |         2         | Reorder and split prototype functions*/

/*----------------------------------------------------------------------------*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $

  ============================================================================*/
#ifndef BSW_APP_UPDOWN_UPDOWN_H_
#define BSW_APP_UPDOWN_UPDOWN_H_

/* Includes */
//#include "Std_Types.h"
#include "Buttons.h"
#include "Timer.h"
#include "Validation.h"
#include "Leds.h"
//#include "Port.h"
//#include "Dio.h"


/*============================================================================*/
/* Constants and types */
/*============================================================================*/
//typedef unsigned int T_ULONG;
//typedef signed int T_SLONG;
/* Exported Variables */
/*============================================================================*/
/* Exported functions prototypes */
void appUpDown_void_ManualUp();
//void appUpDown_void_ManualDown();
T_ULONG appUpDown_u32_PushUpButton();
T_ULONG appUpDown_u32_PushDownButton();
//T_U32 appUpDown_u32_PushAntipinch();
/*T_ULONG appUpDown_u32_validation10ms();
T_ULONG appUpDown_u32_validation500ms();*/
void app_void_behaviorUp();
void app_void_oneTouchUp();
T_ULONG appUpDown_u32_Push10ms();
//void appUpDown_void_clearGPIO();
//void appUpDown_void_default_Leds(T_ULONG led);

/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
