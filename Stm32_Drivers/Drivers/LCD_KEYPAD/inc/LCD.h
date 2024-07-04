/*
 * LCD.h
 *
 *  Created on: Jan 31, 2024
 *      Author: Mustafa gaber
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_
#include "GPIO_header.h"
#include "stm32f103xx.h"
//==================================================
//====================Macros========================
//==================================================

#define CursorIncrement 1
#define CursorDecrement 0
#define NoBlinkCursor 0
#define BlinkCursor 1
#define CursorOn 1
#define CursorOff 0
#define DisplayOn 1
#define DisplayOff 0
#define CursorShift 0
#define DisplayShift 1
#define ShiftRight 1
#define ShiftLeft 0
//=============================================================================
//===========================APIs Supported for LCD============================
//=============================================================================
void HAL_LCD_Init(GPIO_typedef* GPIOx, uint8_t noPins,uint8_t En);
void HAL_LCD_Clear();
void HAL_LCD_WriteChar(uint8_t character);
void HAL_LCD_Cursor(uint8_t OnOff,uint8_t Blink);
void HAL_LCD_WriteString(char* str);
void HAL_LCD_CursorOrDispShift(uint8_t CursorOrDisplayShift, uint8_t ShiftDirection );
void HAL_LCD_CursorPosition(uint8_t CursorPos); // from 0 to 80
#endif /* INC_LCD_H_ */
