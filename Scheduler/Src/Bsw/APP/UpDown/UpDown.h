/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: UpDown.h $
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
/*  DATABASE           |        PROJECT     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/* Rafael Sanchez       |         1         | Prototype creations to up & down the window*/
/* Rafael Sanchez       |         2         | Reorder and split prototype functions*/
/* Rafael Sanchez       |         3         | Add prototype behaviors with its action*/
/* and match with the main state machine                                        */

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
T_UBYTE app_void_behaviorUp();
T_UBYTE app_void_behaviorDown();
T_UBYTE app_void_oneTouchUp();
T_UBYTE app_void_oneTouchDown();
T_UBYTE appUpDown_void_ManualUp();
T_UBYTE appUpDown_void_ManualDown();
T_UBYTE appUpDown_void_antipinch();
T_UBYTE appDown_void_5sec();
T_UBYTE appUpDown_Init();
//T_ULONG appUpDown_u32_Push10ms();
//void appUpDown_void_clearGPIO();
//void appUpDown_void_default_Leds(T_ULONG led);

/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
