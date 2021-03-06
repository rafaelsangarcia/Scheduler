/*
 * SchM.h
 *
 *  Created on: 15/11/2017
 *      Author: uid87753
 */

#ifndef BSW_SERVICES_SCHM_SCHM_H_
#define BSW_SERVICES_SCHM_SCHM_H_

#include "Std_Types.h"
#include "SchM_Cfg.h"
#include "SchM_Types.h"

typedef struct {
  uint8_t FlagOverLoad: 1;
  uint8_t FlagTaskState: 1;
}Flags;

extern void SchM_Init( const SchM_ConfigType *SchMConfig );
extern void SchM_Start( void );
extern void SchM_Stop( void );

#endif /* BSW_SERVICES_SCHM_SCHM_H_ */
