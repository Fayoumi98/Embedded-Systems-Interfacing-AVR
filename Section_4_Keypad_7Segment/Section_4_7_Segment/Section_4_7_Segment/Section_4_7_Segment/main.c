/*
 * Section_4_7_Segment.c
 * Author : Fayoumi
 */ 

#include <avr/io.h>
#include "headers/headers.h"
#include "headers/seven_segment.h"

int main(void)
{
	// initialize 7 segment
	seven_segment_init();
	
	uint8_t i = 0;
    while (1) 
    {
		
		for(uint8_t c = 0 ; c < 5 ; c++)
		{
			seven_segment_write(i);
		}
		i++;
    }
}

