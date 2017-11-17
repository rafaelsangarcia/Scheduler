/*
 * SchM.c
 *
 *  Created on: 15/11/2017
 *      Author: uid87753
 */

#include "General.h"
#include "SchM.h"
#include "Lpit.h"
/* #include "Dio.h" line must be removed as it is just an example to access on Port D pin 0 !!!
 * Note: Dio module provides access to all Dio (Digital Input Output channels configured as GPIO). The user must ensure that
 *       the PORT pins are properly configured from Port module as GPIO input or output channel from the intended PORT
 *       Currently the Port module configures the Port E channel 0 only as an output
 *
 *       Please: Remove this comment !
 *
 *  */
#include "Dio.h"

#define NUM_OF_TASKS (0x6)

const SchM_ConfigType *GlbSchMConfig;

SchM_TaskControlBlockType SchM_TaskControlBlock[NUM_OF_TASKS];
SchM_SchedulerStatusType SchM_SchedulerStatus;

Flags FlagsScheduler = {
	0,0
};

uint32_t OsTickCounter = 0; /* Remove this line */

void SchM_OsTick( void )
{
	SchM_SchedulerStatus.OsTickCounter++;

	/* Remove the following lines */
	/*OsTickCounter++;

	if (OsTickCounter > 640)
	{
		Dio_PortTooglePin(PORTCH_D, 0);
		OsTickCounter = 0;
	}*/

	//uint8_t FlagRunning=0;
	//uint8_t FlagOF=0;

	uint8_t LocTaskIdx;

	SchM_SchedulerStatus.OsTickCounter++;

	//Set Ready the Task if mask match the Counter
	for(LocTaskIdx = 0; LocTaskIdx < GlbSchMConfig->NumOfTasks; LocTaskIdx++){
		if((SchM_SchedulerStatus.OsTickCounter & GlbSchMConfig->TaskConfig[LocTaskIdx].TaskMask) == GlbSchMConfig->TaskConfig[LocTaskIdx].TaskOffset){
			if(FlagsScheduler.FlagTaskState == 1) {
				FlagsScheduler.FlagOverLoad = 1;
			}

					SchM_TaskControlBlock[LocTaskIdx].SchM_TaskState=SCHM_TASK_STATE_READY;
					FlagsScheduler.FlagTaskState = 1;
			}
	}
}

void SchM_Background( void )
{
	uint8_t LocTaskIdx;
	while(1) //for|
	{
		for(LocTaskIdx = 0; LocTaskIdx < GlbSchMConfig->NumOfTasks; LocTaskIdx++)
		{
			if ( SCHM_TASK_STATE_READY == SchM_TaskControlBlock[LocTaskIdx].SchM_TaskState )
			{
				SchM_TaskControlBlock[LocTaskIdx].SchM_TaskState = SCHM_TASK_STATE_RUNNING;
				SchM_SchedulerStatus.SchM_SchedulerState = SCHM_RUNNING;
				GlbSchMConfig->TaskConfig[LocTaskIdx].TaskCallback();
				SchM_TaskControlBlock[LocTaskIdx].SchM_TaskState = SCHM_TASK_STATE_SUSPENDED;
				SchM_SchedulerStatus.SchM_SchedulerState = SCHM_IDLE;
				FlagsScheduler.FlagTaskState = 0;
				SchM_SchedulerStatus.SchM_SchedulerState = SCHM_IDLE;
			}
		}
	}
}

void SchM_Init( const SchM_ConfigType *SchMConfig )
{
	GlbSchMConfig = SchMConfig;
	uint8_t LocTaskIdx;
	SchM_SchedulerStatus.SchM_SchedulerState = SCHM_UNINIT;

	for(LocTaskIdx = 0; LocTaskIdx < GlbSchMConfig->NumOfTasks; LocTaskIdx++)
	{
		SchM_TaskControlBlock[LocTaskIdx].SchM_TaskState = SCHM_TASK_STATE_SUSPENDED;
	}

	LPIT0_init(SchM_OsTick);            /* Initialize PIT0 for 781.25 micro-seconds timeout & Callback Install */

	SchM_SchedulerStatus.SchM_SchedulerState = SCHM_INIT;
}

void SchM_Start( void )
{
	LPIT0_Start();
	SchM_Background();
}

void SchM_Stop( void )
{
	LPIT0_Stop();
}
