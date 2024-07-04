/*
 * LCD.c
 *
 *  Created on: Jan 31, 2024
 *      Author: Mustafa gaber
 */
#include "LCD.h"
#include "time.h"
static uint8_t EnablePin=0;
static GPIO_typedef* GPIO;

void Send()
{ int i=0;
	while(i<500)
		i++;
	GPIO->BSRR=(1<<EnablePin);
	GPIO->BSRR=(1<<EnablePin<<16);
	GPIO->BSRR=(0xFF)<<16;
}

void HAL_LCD_Init(GPIO_typedef* GPIOx, uint8_t noPins,uint8_t En)
{
	EnablePin=En;
	GPIO=GPIOx;
	for(int i =0; i<noPins;i++)
	MCAL_GPIO_PinConfig(GPIOx,i, GPIO_PIN_OUTPUT_10M,GPIO_PIN_OUTPUT_G_PP);
	HAL_LCD_Cursor(CursorOn,BlinkCursor);
	HAL_LCD_Clear();
}
void HAL_LCD_DispOnOff(uint8_t OnOFF)
{
	GPIO->ODR=(0x008|(OnOFF<<2));
	Send();
}
void HAL_LCD_Cursor(uint8_t OnOFF,uint8_t Blink)
{
	GPIO->ODR=(0x00C|(OnOFF<<1)|Blink);
	Send();

}
void HAL_LCD_Clear()
{
	GPIO->ODR=1;
	Send();
}
void HAL_LCD_WriteChar(uint8_t character)
{
	GPIO->ODR=(0x200|character);
	Send();
}
void HAL_LCD_WriteString(char* str)
{
	int i = 0 ;
	while(str[i]!='\0')
	HAL_LCD_WriteChar(str[i++]);

}
void HAL_LCD_CursorOrDispShift(uint8_t CursorOrDisplayShift, uint8_t ShiftDirection )
{
	GPIO->ODR=(0x010|CursorOrDisplayShift<<3|ShiftDirection<<2);
		Send();
}
void HAL_LCD_CursorPosition(uint8_t CursorPos) // from 0 to 80
{
	GPIO->ODR=(0x080|CursorPos);
	Send();

}
