/*
 * SchM_Tasks.c
 *
 *  Created on: 15/11/2017
 *      Author: uid87753
 */

#include "SchM_Tasks.h"
#include "Dio.h"


void SchM_3p125ms_Task ( void )
{
	/* Task Body */
	Dio_PortSetPin(PORTCH_D, 0);
	/* ....   */
	Dio_PortClearPin(PORTCH_D, 0);
}


void SchM_6p25ms_Task ( void )
{
	/* Task Body */
}
