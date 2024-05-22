/*
 * timer0.h
 *  Author: Fayoumi
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "headers.h"
#include "LCD.h"



/*****************************************************************************
* Function Name: timer0_NM_init
* Purpose      : Initialize normal mode for timer0 - No prescaler - Enable interrupt
*                Frequency 16Mhz
* Parameters   : void
* Return value : void
*****************************************************************************/
void timer0_NM_init(void);



/*****************************************************************************
* Function Name: timer0_CTC_init
* Purpose      : Initialize CTC mode for timer0 - prescaler 1024 - Enable interrupt
*                Frequency 16Mhz
* Parameters   : uint8_t value (0 to 255)
* Return value : void
*****************************************************************************/
void timer0_CTC_init(uint8_t value);



/*****************************************************************************
* Function Name: timer0_FG_init
* Purpose      : Initialize frequency Generator mode for timer0 - No prescaler
                 Frequency 16Mhz
* Parameters   : value: frequency value range from 0 (0) to 255 (31.25 Khz) 
*              : frequency Generated  = 16000000 / ((value+1) * 2)
* Return value : void
*****************************************************************************/
void timer0_FG_init(uint8_t value);



#endif /* TIMER0_H_ */