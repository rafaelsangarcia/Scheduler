/*
 * SchM_Cfg.h
 *
 *  Created on: 15/11/2017
 *      Author: uid87753
 */

#ifndef BSW_SERVICES_SCHM_SCHM_CFG_H_
#define BSW_SERVICES_SCHM_SCHM_CFG_H_

#include "Std_Types.h"


typedef uint8_t SchM_TaskOffsetType;

typedef enum{
	SCHM_MASK_3P125MS = 0x03,
	SCHM_MASK_6P25MS = 0x07,
	/*  ... */
}SchM_TaskMaskType;

typedef struct{
	SchM_TaskMaskType TaskMask;
	SchM_TaskOffsetType TaskOffset;
	/* .. */
	tCallbackFunction TaskCallback;
}SchM_TaskConfigType;


typedef struct {
	uint8_t NumOfTasks;
	const SchM_TaskConfigType *TaskConfig;
}SchM_ConfigType;

const SchM_ConfigType SchedulerConfig;

#endif /* BSW_SERVICES_SCHM_SCHM_CFG_H_ */
