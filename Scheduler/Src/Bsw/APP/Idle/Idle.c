/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: filename.c $
 * $Revision: version $
 * $Author: author $
 * $Date: date $
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
/*                     |                    |                                 */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
#include "Idle.h"

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

void appInit_void_IdleState(){
  if ( appButtons_u32_PushUpButton() == 1 ) {
    appTimer_void_set_timer1();
    if (appButtons_u32_Push10ms() == 1) {
      state = 1;
    }
  }

  if (u32_Antipinch_Flag == 1){
    state = 8;
    u32_Antipinch_Flag=0;
    appTimer_void_clear_timer1();
  }

  if (appButtons_u32_PushDownButton() == 1 ){
    appTimer_void_set_timer1();
    if (appButtons_u32_Push10ms() == 1) {
      state = 3;
    }
  }

  if (appButtons_u32_PushUpButton() == 0 && appButtons_u32_PushDownButton() == 0) {
    appTimer_void_clear_timer1();
  }
}


 /* Notice: the file ends with a blank new line to avoid compiler warnings */
