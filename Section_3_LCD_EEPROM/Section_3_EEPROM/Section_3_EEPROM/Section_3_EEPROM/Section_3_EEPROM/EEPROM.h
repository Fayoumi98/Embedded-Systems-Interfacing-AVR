/*
 * EEPROM.h
 *  Author: Fayoumi
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
#include "headers/headers.h"

/*****************************************************************************
* Function Name: EEPROM_read
* Purpose      : read from location (address) and return value in this location
* Parameters   : address: address of EEPROM location range from 0 to 1023
* Return value : uint8_t: 1 byte which refer to value in location (address) in EEPROM
*****************************************************************************/
uint8_t EEPROM_read(uint16_t address);


/*****************************************************************************
* Function Name: EEPROM_write
* Purpose      : write (data) on location (address)
* Parameters   : address: address of EEPROM location
*                data: data to be write
* Return value : void
*****************************************************************************/
void EEPROM_write(uint16_t address , uint8_t data);


#endif /* EEPROM_H_ */