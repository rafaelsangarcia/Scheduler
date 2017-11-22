/*
 * Port.c
 *
 *  Created on: 15/11/2017
 *      Author: uid87753
 */

#include "General.h"          /* include peripheral declarations */
#include "Port.h"

void PORT_init (void) {
  PCC-> PCCn[PCC_PORTD_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
	PCC-> PCCn[PCC_PORTC_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
	PCC-> PCCn[PCC_PORTB_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
	PCC-> PCCn[PCC_PORTE_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */

	PTD->PDDR |= 1<<BlueLed; /* Port D0: Data Direction= output */
	PTD->PDDR |= 1<<RedLed; /* Port D15: Data Direction= output */
	PTD->PDDR |= 1<<GreenLed; /* Port D16: Data Direction= output */
	PTC->PDDR |= 1<<LedBar_1;/*Port C7: Data Direction= output*/
	PTB->PDDR |= 1<<LedBar_2;
	PTB->PDDR |= 1<<LedBar_3;
	PTB->PDDR |= 1<<LedBar_4;
	PTB->PDDR |= 1<<LedBar_5;
	PTC->PDDR |= 1<<LedBar_6;
	PTC->PDDR |= 1<<LedBar_7;
	PTE->PDDR |= 1<<LedBar_8;
	PTE->PDDR |= 1<<LedBar_9;
	PTE->PDDR |= 1<<LedBar_10;
	PTC->PDDR &= ~(1<<UpButton);/*PORT C12: Data Direction= input*/
	PTC->PDDR &= ~(1<<DownButton);/*PORT C13: Data Direction= input*/
	PTE->PDDR &= ~(1<<Antipinch);

	PORTD->PCR[BlueLed]  = 0x00000100; /* Port D0: MUX = ALT1, GPIO (to blue LED on EVB) */
	PORTD->PCR[RedLed] = 0x00000100; /* Port D0: MUX = ALT1, GPIO (to red LED on EVB) */
	PORTD->PCR[GreenLed] = 0x00000100; /* Port D0: MUX = ALT1, GPIO (to green LED on EVB) */
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
	PORTC->PCR[UpButton] = 0x00000110;
	PORTC->PCR[DownButton] = 0x00000110;
	PORTE->PCR[Antipinch] = 0x00000110;

/*turn off leds*/
  PTD->PSOR |= 1<<BlueLed; /*turn off the led*/
  PTD->PSOR |= 1<<RedLed; /*turn off the led*/
  PTD->PSOR |= 1<<GreenLed; /*turn off the led*/
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
