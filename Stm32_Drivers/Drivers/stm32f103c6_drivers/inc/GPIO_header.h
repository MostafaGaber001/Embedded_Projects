/*
 * GPIO_header.h
 *
 *  Created on: Jan 30, 2024
 *      Author: Mustafa gaber
 */

#ifndef INC_GPIO_HEADER_H_
#define INC_GPIO_HEADER_H_
//includes
#include "stm32f103xx.h"

//configure structure
/*typedef struct
{
	uint8_t GPIO_PinNumber; // Choose pin number based on @ref pins numbers
	uint8_t Mode;  //specify operation mode based on @ref pin modes
	uint8_t Config; // specify configuration based on @ref config
}GPIO_Pin;*/
//-*-*-*-*-*-*-*-*-*-*-*-
//GPIO Macros
//-*-*-*-*-*-*-*-*-*-*-*

//@ref pins numbers
#define GPIO_Pin_0 (uint8_t) 0
#define GPIO_Pin_1 (uint8_t) 1
#define GPIO_Pin_2 (uint8_t) 2
#define GPIO_Pin_3 (uint8_t) 3
#define GPIO_Pin_4 (uint8_t) 4
#define GPIO_Pin_5 (uint8_t) 5
#define GPIO_Pin_6 (uint8_t) 6
#define GPIO_Pin_7 (uint8_t) 7
#define GPIO_Pin_8 (uint8_t) 8
#define GPIO_Pin_9 (uint8_t) 9
#define GPIO_Pin_10 (uint8_t) 10
#define GPIO_Pin_11 (uint8_t) 11
#define GPIO_Pin_12 (uint8_t) 12
#define GPIO_Pin_13 (uint8_t) 13
#define GPIO_Pin_14 (uint8_t) 14
#define GPIO_Pin_15 (uint8_t)15
//@ref pin modes
#define GPIO_PIN_INPUT 0x00
#define GPIO_PIN_OUTPUT_10M 0x01
#define GPIO_PIN_OUTPUT_2M 0x02
#define GPIO_PIN_OUTPUT_50M 0x03

//@ref pins config
#define GPIO_PIN_INPUT_A 0x00	    //ANALOG INPUT MODE
#define GPIO_PIN_INPUT_F 0x01     // FLOATING INPUT MODE
#define GPIO_PIN_INPUT_PU 0x03     // PULL UP INPUT MODE
#define GPIO_PIN_INPUT_PD 0x02     // PULL DOWN INPUT MODE
#define GPIO_PIN_OUTPUT_G_PP 0x00  // GENERAL OUTPUT PUSH PULL MODE
#define GPIO_PIN_OUTPUT_G_OD 0x01  // GENERAL OUTPUT OPEN DRAIN MODE
#define GPIO_PIN_OUTPUT_AF_PP 0x02	//ALTERNATIVE FUNCTION PUSH PULL OUTPUT MODE
#define GPIO_PIN_OUTPUT_AF_OD 0x03	// ALTERNATIVE FUNCTION OPEN DRAIN OUTPUT MODE

/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/
void MCAL_GPIO_PinConfig(GPIO_typedef* GPIOx,uint8_t PinNumber,uint8_t PinMode, uint8_t PinConfig);
void MCAL_GPIO_DeInit(GPIO_typedef* GPIOx);
void MCAL_GPIO_RESET(GPIO_typedef* GPIOx);

void MCAL_GPIO_WritePin(GPIO_typedef* GPIOx,uint8_t PinNumber, uint8_t value);
void MCAL_GPIO_WritePort(GPIO_typedef* GPIOx, uint16_t value);
void MCAL_GPIO_TOGGPin(GPIO_typedef* GPIOx,uint8_t PinNumber);

uint32_t MCAL_GPIO_ReadPin(GPIO_typedef* GPIOx,uint8_t PinNumber);
uint16_t MCAL_GPIO_ReadPort(GPIO_typedef* GPIOx);

void MCAL_GPIO_LockPin(GPIO_typedef* GPIOx,uint8_t PinNumber);
void MCAL_GPIO_ResetPin(GPIO_typedef* GPIOx,uint8_t PinNumber);
void Send();
#endif /* INC_GPIO_HEADER_H_ */
