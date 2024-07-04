/*
 * EEPROM.h
 *
 * Created: 9/2/2023 5:40:52 PM
 *  Author: Mustafa gaber
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
void EEPROM_Write(unsigned short Address, unsigned char data);
unsigned char EEPROM_Read(unsigned short Address);
#endif /* EEPROM_H_ */