/*
 * WDT.c
 *  Author: Fayoumi
 */ 


#include "headers/WDT.h"


void WDT_on(void)
{
	/*
	Watchdog timer enables with typical timeout period 1 second.
	WDP2, WDP1, WDP0: Watchdog Timer prescaler 	WDP2 = 1	 WDP1 = 1	 WDP0 = 0
	*/
	WDTCR = (1<<WDE)|(1<<WDP2)|(1<<WDP1);
}

void WDT_off(void)
{
	/*
	This function use for disable the watchdog timer.
	
	*/
	WDTCR = 1<<WDTOE | 1<< WDE;
	WDTCR = 0;

}

	