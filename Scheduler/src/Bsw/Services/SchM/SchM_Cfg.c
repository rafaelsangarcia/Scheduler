/*
 * SchM_Cfg.c
 *
 *  Created on: 15/11/2017
 *      Author: uid87753
 */

#include "SchM.h"
#include "SchM_Tasks.h"

const SchM_TaskConfigType TaskDescriptor[]=
{
		{
				SCHM_MASK_3P125MS,
				0x03,
				/* ... */
				SchM_3p125ms_Task
		},
		{
				SCHM_MASK_6P25MS,
				0x07,
				/* ... */
				SchM_6p25ms_Task
		}

};

const SchM_ConfigType SchedulerConfig =
{
		sizeof(TaskDescriptor)/sizeof(SchM_TaskConfigType),
		&TaskDescriptor[0]
};
