/*
 * EEPROM.c
 *
 * Created: 9/2/2023 5:41:10 PM
 *  Author: Mustafa gaber
 */ 
#include "avr/io.h"
void EEPROM_Write(unsigned short Address,unsigned char data)
{
	while(EECR&(1<<EEPE)); // waiting if there is a previous writing operation
	while(SPMCSR&=SELFPRGEN);
	EEAR = Address;
	EEDR=data;
	EECR|=(1<<EEMPE);
	EECR|=(1<<EEPE);
}
unsigned char EEPROM_Read(unsigned short Address)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEPE))
	;
	/* Set up address register */
	EEAR = Address;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from Data Register */
	return EEDR;
}