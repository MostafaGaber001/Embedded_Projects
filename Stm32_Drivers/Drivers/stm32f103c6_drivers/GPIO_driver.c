/*
 * GPIO_driver.c
 *
 *  Created on: Jan 30, 2024
 *      Author: Mustafa gaber
 */
#include"GPIO_header.h"
/**================================================================
* @Fn-MCAL_GPIO_PinConfig
* @brief - configuring the GPIO pins
* @param [in] - GPIO port , pin number , desired mode and configurations
* @param [out] - void
* @retval -
* Note-
*/
void MCAL_GPIO_PinConfig(GPIO_typedef* GPIOx,uint8_t PinNumber,uint8_t PinMode, uint8_t PinConfig)
{
uint32_t* CRLH ;
uint8_t Higher8=0;
if(PinNumber < GPIO_Pin_8)
	{
		CRLH=&GPIOx->CRL;
	}
	else
	{
	    CRLH=&GPIOx->CRH;
	    PinNumber=PinNumber-(uint8_t)8;
	    Higher8=1;
	}

	*CRLH&=(~((0xF)<<(PinNumber*4)));

if(PinMode==GPIO_PIN_INPUT && PinConfig==GPIO_PIN_INPUT_PU)
		 {
			 *CRLH|=((GPIO_PIN_INPUT_PD<<2)|(PinMode))<<(PinNumber*4);
			 GPIOx->ODR|=(1<<(PinNumber+8*(Higher8)));
		 }
	 else
	 {
		 *CRLH|=((PinConfig<<2)|(PinMode))<<PinNumber*4;
	 }
}
void MCAL_GPIO_DeInit(GPIO_typedef* GPIOx)
{

	RCC->APB2ENR&=~(0x4);
}
void MCAL_GPIO_RESET(GPIO_typedef* GPIOx)
{
		GPIOx->CRL=0x44444444;
		GPIOx->CRH=0x44444444;
		GPIOx->ODR=0;
}
void MCAL_GPIO_WritePin(GPIO_typedef* GPIOx,uint8_t PinNumber, uint8_t value)
{
	if(value==0)
	    GPIOx->ODR&=~(1<<PinNumber);
		else GPIOx->ODR|=(1<<PinNumber);
}
void MCAL_GPIO_WritePort(GPIO_typedef* GPIOx, uint16_t value)
{
GPIOx->ODR=value;
}
uint32_t MCAL_GPIO_ReadPin(GPIO_typedef* GPIOx,uint8_t PinNumber)
{
	return ((GPIOx->IDR)>>PinNumber&1);
}
uint16_t MCAL_GPIO_ReadPort(GPIO_typedef* GPIOx)
{
	return GPIOx->IDR;
}
void MCAL_GPIO_TOGGPin(GPIO_typedef* GPIOx,uint8_t PinNumber)
{
		    GPIOx->ODR^=(1<<PinNumber);

}
