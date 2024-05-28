/*
 * Section_8_I2C.c
 * Author : Fayoumi
 */ 

#include <avr/io.h>
#include "headers/headers.h"
#include "headers/I2C.h"

int main(void)
{
	I2C_master_init();
	uint8_t i = 0;
	
    while (1) 
    {
		I2C_master_start();
		I2C_master_addr(15,0);
		I2C_master_write(i++);
		I2C_master_stop();
		
		_delay_ms(50);
    }
}

