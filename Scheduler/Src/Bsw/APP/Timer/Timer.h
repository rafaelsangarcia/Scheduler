/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Timer.h $
 * $Revision: version 1 $
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
/* Rafael Sanchez       |         1         | Prototype timer functions*/
/*----------------------------------------------------------------------------*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $

  ============================================================================*/
#ifndef BSW_APP_TIMER_TIMER_H_
#define BSW_APP_TIMER_TIMER_H_


/* Includes */
#include "Std_Types.h"
//#include "Validation.h"
//#include "Port.h"

/*============================================================================*/
/* Constants and types */
/*============================================================================*/
//typedef unsigned int T_ULONG;
//typedef signed int T_SLONG;
/* Exported Variables */
T_ULONG u32_lpit0_ch0_flag_counter;
T_ULONG u32_lpit0_ch1_flag_counter;
/*============================================================================*/
/* Exported functions prototypes */
void appTimer_void_set_timer1();
void appTimer_void_clear_timer1();
void appTimer_void_set_timer0();
void appTimer_void_clear_timer0();

/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
