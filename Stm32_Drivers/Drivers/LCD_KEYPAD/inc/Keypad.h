/*
 * Keypad.h
 *
 *  Created on: Feb 9, 2024
 *      Author: Mustafa gaber
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_
#include "stm32f103xx.h"
#include "GPIO_header.h"
/*
 * ===================================================================================
 * ==============================================APIs=================================
 * ===================================================================================
 * */
void HAL_Keypad_Init();
void HAL_Keypad_Get_Char();
/*
 * ==================================================================================
 * =====================================Macros=======================================
 * ==================================================================================
 * */
#define InputIndex  0
#define OutputIndex 4
#define GPIO_Keypad GPIOB


#endif /* INC_KEYPAD_H_ */
