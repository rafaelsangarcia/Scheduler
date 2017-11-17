/*
 * SchM_Tasks.c
 *
 *  Created on: 15/11/2017
 *      Author: uid87753
 */

#include "SchM_Tasks.h"
#include "Dio.h"

//description

void SchM_3p125ms_Task ( void )
{
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


void SchM_6p25ms_Task ( void )
{
	/* Task Body */
}

void SchM_12p5ms_Task ( void )
{
	/* Task Body */
}

void SchM_25ms_Task ( void )
{
	/* Task Body */
}

void SchM_50ms_Task ( void )
{
	/* Task Body */
}
void SchM_100ms_Task ( void )
{
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
