/*
 * timer1.h
 *  Author: Fayoumi
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#include "headers.h"


/*****************************************************************************
* Function Name: timer1_ICU_capture
* Purpose      : initialize ICU1 and measure period of signal in usec
* Parameters   : void
* Return value : return period of freq in usec
*****************************************************************************/
uint16_t timer1_ICU_capture(void);


#endif /* TIMER1_H_ */