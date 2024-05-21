/*
 * seven_segment.h
 * Author : Fayoumi
 */ 


#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#include "headers.h"

// PD0,1,2,3 = A,B,C,D
#define INIT_SEVEN_SEGMENT() DDRC|= 0b111111;


#define SEG_A(x)    if (x == 0) CLRBIT(PORTC,0); else SETBIT(PORTC,0);
#define SEG_B(x)    if (x == 0) CLRBIT(PORTC,1); else SETBIT(PORTC,1);
#define SEG_C(x)    if (x == 0) CLRBIT(PORTC,2); else SETBIT(PORTC,2);
#define SEG_D(x)    if (x == 0) CLRBIT(PORTC,3); else SETBIT(PORTC,3);
#define SEG_E1(x)   if (x == 0) CLRBIT(PORTC,4); else SETBIT(PORTC,4);
#define SEG_E2(x)   if (x == 0) CLRBIT(PORTC,5); else SETBIT(PORTC,5);


/*****************************************************************************
* Function Name: seven_segment_init
* Purpose      : initialize anode 7 Segment with BCD decoder 7447
* Parameters   : void
* Return value : void
*****************************************************************************/
void seven_segment_init(void);


/*****************************************************************************
* Function Name: seven_segment_write
* Purpose      : initialize 7 Segment pins
* Parameters   : uint8_t number to be displayed
* Return value : void
*****************************************************************************/
void seven_segment_write(uint8_t counter);

#endif /* SEVEN_SEGMENT_H_ */