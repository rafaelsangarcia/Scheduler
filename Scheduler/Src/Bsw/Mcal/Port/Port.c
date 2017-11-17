/*
 * Port.c
 *
 *  Created on: 15/11/2017
 *      Author: uid87753
 */

#include "General.h"          /* include peripheral declarations */
#include "Port.h"

void PORT_init (void) {
  PCC-> PCCn[PCC_PORTB_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
  PCC-> PCCn[PCC_PORTC_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
  PCC-> PCCn[PCC_PORTD_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
  PCC-> PCCn[PCC_PORTE_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */

  PTD->PDDR |= 1<<BlueLed;            /* Port D0:  Data Direction= output */
  PORTD->PCR[BlueLed] =  0x00000100;  /* Port D0:  MUX = ALT1, GPIO (to blue LED on EVB) */

  PTD->PDDR |= 1<<RedLed;            /* Port D0:  Data Direction= output */
  PORTD->PCR[RedLed] =  0x00000100;  /* Port D0:  MUX = ALT1, GPIO (to blue LED on EVB) */

  /*LedBars*/
  PTC->PDDR |= 1<<LedBar_1;
	PTB->PDDR |= 1<<LedBar_2;
	PTB->PDDR |= 1<<LedBar_3;
	PTB->PDDR |= 1<<LedBar_4;
	PTB->PDDR |= 1<<LedBar_5;
	PTC->PDDR |= 1<<LedBar_6;
	PTC->PDDR |= 1<<LedBar_7;
	PTE->PDDR |= 1<<LedBar_8;
	PTE->PDDR |= 1<<LedBar_9;
	PTE->PDDR |= 1<<LedBar_10;

  PORTC->PCR[LedBar_1] = 0x00000100;
  PORTB->PCR[LedBar_2] = 0x00000100;
  PORTB->PCR[LedBar_3] = 0x00000100;
  PORTB->PCR[LedBar_4] = 0x00000100;
  PORTB->PCR[LedBar_5] = 0x00000100;
  PORTC->PCR[LedBar_6] = 0x00000100;
  PORTC->PCR[LedBar_7] = 0x00000100;
  PORTE->PCR[LedBar_8] = 0x00000100;
  PORTE->PCR[LedBar_9] = 0x00000100;
  PORTE->PCR[LedBar_10] = 0x00000100;

  PTC->PCOR |= 1<<LedBar_1;
  PTB->PCOR |= 1<<LedBar_2;
  PTB->PCOR |= 1<<LedBar_3;
  PTB->PCOR |= 1<<LedBar_4;
  PTB->PCOR |= 1<<LedBar_5;
  PTC->PCOR |= 1<<LedBar_6;
  PTC->PCOR |= 1<<LedBar_7;
  PTE->PCOR |= 1<<LedBar_8;
  PTE->PCOR |= 1<<LedBar_9;
  PTE->PCOR |= 1<<LedBar_10;



}
