/*
 * Port.h
 *
 *  Created on: 15/11/2017
 *      Author: uid87753
 */

#ifndef BSW_MCAL_PORT_PORT_H_
#define BSW_MCAL_PORT_PORT_H_

#include "Std_Types.h"

//Port Led Define
#define BlueLed 0
#define RedLed 15
#define GreenLed 16

//Push Button Define
#define UpButton 12
#define DownButton 13
#define Antipinch 13

//Led Bar Define
#define LedBar_1 7
#define LedBar_2 17
#define LedBar_3 14
#define LedBar_4 15
#define LedBar_5 16
#define LedBar_6 14
#define LedBar_7 3
#define LedBar_8 16
#define LedBar_9 15
#define LedBar_10 14

void PORT_init (void);

#endif /* BSW_MCAL_PORT_PORT_H_ */
