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
				SCHM_TASKID_3P125MS,
				SCHM_MASK_3P125MS,
				SCHM_OFFSET_3P125MS,
				/* ... */
				SchM_3p125ms_Task
		},
		{
				SCHM_TASKID_6P25MS,
				SCHM_MASK_6P25MS,
				SCHM_OFFSET_6P25MS,
				/* ... */
				SchM_6p25ms_Task
		},
		{
				SCHM_TASKID_12P5MS,
				SCHM_MASK_12P5MS,
				SCHM_OFFSET_12P5MS,
				/* ... */
				SchM_12p5ms_Task
		},
		{
				SCHM_TASKID_25MS,
				SCHM_MASK_25MS,
				SCHM_OFFSET_25MS,
				/* ... */
				SchM_25ms_Task
		},
		{
				SCHM_TASKID_50MS,
				SCHM_MASK_50MS,
				SCHM_OFFSET_50MS,
				/* ... */
				SchM_50ms_Task
		},
		{
				SCHM_TASKID_100MS,
				SCHM_MASK_100MS,
				SCHM_OFFSET_100MS,
				/* ... */
				SchM_100ms_Task
		}

};

const SchM_ConfigType SchedulerConfig =
{
		sizeof(TaskDescriptor)/sizeof(SchM_TaskConfigType),
		&TaskDescriptor[0]
};
