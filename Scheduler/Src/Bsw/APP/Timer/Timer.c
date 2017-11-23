/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Timer.c $
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
/*  DATABASE           |        VERSION      | DESCRIPTION                    */
/*----------------------------------------------------------------------------*/
/*   Rafael Sanchez   |         1           |  Create the timer functions*/
/*----------------------------------------------------------------------------*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $

  ============================================================================*/
/* Includes */
#include "Timer.h"
/*============================================================================*/
/* Constants and types  */
/*============================================================================*/
/* Variables */
 T_ULONG u32_lpit0_ch0_flag_counter = 0;
 T_ULONG u32_lpit0_ch1_flag_counter = 0;
/*============================================================================*/
/* Private functions prototypes */
//void appUpDown_void_timer0();
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

void appTimer_void_set_timer1(){
  u32_lpit0_ch1_flag_counter++;
}
void appTimer_void_clear_timer1(){
  u32_lpit0_ch1_flag_counter = 0;
}
void appTimer_void_set_timer0(){
  u32_lpit0_ch0_flag_counter++;
}
void appTimer_void_clear_timer0(){
  u32_lpit0_ch0_flag_counter = 0;
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
