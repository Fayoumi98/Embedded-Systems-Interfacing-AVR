/*
 * seven_segment.c
 * Author : Fayoumi
 */ 


#include "headers//seven_segment.h"


void seven_segment_init(void)
{
	INIT_SEVEN_SEGMENT();
	
	SEG_E1(1);
	SEG_E2(1);
}


void seven_segment_write(uint8_t data)
{
	uint8_t first_digit;
	first_digit = data % 10;
	SEG_E1(1);
	SEG_E2(0);
	SEG_A(READBIT(first_digit,0));
	SEG_B(READBIT(first_digit,1));
	SEG_C(READBIT(first_digit,2));
	SEG_D(READBIT(first_digit,3));
	
	_delay_ms(100);
	
	uint8_t second_digit = (data / 10) % 10 ;
	SEG_E1(0);
	SEG_E2(1);
	SEG_A(READBIT(second_digit,0));
	SEG_B(READBIT(second_digit,1));
	SEG_C(READBIT(second_digit,2));
	SEG_D(READBIT(second_digit,3));
	
	_delay_ms(100);
}