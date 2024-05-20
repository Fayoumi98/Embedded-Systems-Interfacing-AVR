/*
 * EEPROM.c
 *  Author: Fayoumi
 */ 


#include "headers/headers.h"
#include "EEPROM.h"

uint8_t EEPROM_read(uint16_t address)
{
	// Wait until EEWE becomes zero (Pooling Process) => Synchronous Function
	while(READBIT(EECR,EEWE) == 1) {}

	// Write new EEPROM address to EEAR
	EEAR = address;
	
	// set EEPROM Read enable bit
	SETBIT(EECR,EERE);
	
	// return EEPROM data register
	return EEDR;
}


void EEPROM_write(uint16_t address , uint8_t data)
{
	// Wait until EEWE becomes zero (Pooling Process) => Synchronous Function
	while(READBIT(EECR,EEWE) == 1) {}
		
	// Write new EEPROM address to EEAR
	EEAR = address;
	// Write new EEPROM data to EEDR
	EEDR = data;
	// Write a logical one to the EEMWE bit while writing a zero to EEWE in EECR.
	SETBIT(EECR,EEMWE);
	// Within four clock cycles after setting EEMWE, write a logical one to EEWE.
	SETBIT(EECR,EEWE);
	
}

