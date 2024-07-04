/*
 * Keypad.c
 *
 *  Created on: Feb 9, 2024
 *      Author: Mustafa gaber
 */
#include "Keypad.h"
#include "LCD.h"
void HAL_Keypad_Init()
{
	uint16_t i;
	i=InputIndex;
	for(i; i<InputIndex+4;i++)
		MCAL_GPIO_PinConfig(GPIO_Keypad, i,GPIO_PIN_INPUT,GPIO_PIN_INPUT_PD);

	i=OutputIndex;
	for(i; i<OutputIndex+4;i++)
		MCAL_GPIO_PinConfig(GPIO_Keypad, i, GPIO_PIN_OUTPUT_50M, GPIO_PIN_OUTPUT_G_PP);
}
void HAL_Keypad_Get_Char()
{
	uint8_t i ,j;
	for (i=0;i<4;i++)
	{
		GPIO_Keypad->ODR&=~(0xF<<OutputIndex);
		MCAL_GPIO_WritePin(GPIO_Keypad, OutputIndex+i, 1);
		for(j=0;j<4;j++)
		{
			if(MCAL_GPIO_ReadPin(GPIO_Keypad, InputIndex<<j))
			{
				switch(i)
				{
				case(0):if(j==0) HAL_LCD_WriteChar('9 ');
						else if(j==1) HAL_LCD_WriteChar('4');
						else if(j==2) HAL_LCD_WriteChar('1');
						else if(j==3) HAL_LCD_WriteChar('0');


					break;
				}

			while(MCAL_GPIO_ReadPin(GPIO_Keypad, InputIndex<<j));
			}

		}

	}
}

