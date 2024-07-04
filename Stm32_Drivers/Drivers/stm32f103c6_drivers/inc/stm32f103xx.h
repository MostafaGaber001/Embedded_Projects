/*
 * stm32f103xx.h
 *
 *  Created on: Jan 30, 2024
 *      Author: Mustafa gaber
 */

#ifndef INC_STM32F103XX_H_
#define INC_STM32F103XX_H_
//-----------------------------
//Includes
//-----------------------------
#include <stdint.h>
//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASH_MEMORY_BASE 		   0x08000000UL
#define SYSTEM_MEMORY_BASE 		   0x1FFFF000UL
#define SRAM_MEMORY_BASE 		   0x20000000UL
#define PERIPHERALS_BASE 		   0x40000000UL
#define Cortex_M3_PERIPHERALS_BASE 0x40000000UL
//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------
#define RCC_BASE 0x40021000UL

//-----------------------------
//Base addresses for ABP2 Peripherals
//-----------------------------
//GPIO A,B fully included in LQFP48
#define GPIOA_BASE 0x40010800UL
#define GPIOB_BASE 0x40010C00UL
//GPIO C,D PARTIALLY INCULDDED IN LQFP48
#define GPIOC_BASE 0x40011000UL
#define GPIOD_BASE 0x40011400UL
//GPIO E NOT INCULDED
#define GPIOE_BASE 0x40011800UL
//EXTI
#define EXTI_BASE 0x40010400UL
//AIFO
#define AFIO_BASE 0x40010000UL
//-----------------------------
//Base addresses for APB1 Peripherals
//-----------------------------


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKRL;
}GPIO_typedef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:RCC
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
volatile uint32_t CR;
volatile uint32_t CFGR;
volatile uint32_t CIR;
volatile uint32_t APB2RSTR;
volatile uint32_t APB1RSTR;
volatile uint32_t AHBENR;
volatile uint32_t APB2ENR;
volatile uint32_t APB1ENR;
volatile uint32_t BDCR;
volatile uint32_t CSR;
}RCC_typedef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:EXTI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_typedef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:AFIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t RESERVED;
	volatile uint32_t MAPR2;

}AFIO_typedef;
//=====================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:GPIO
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA  ((GPIO_typedef *)GPIOA_BASE)
#define GPIOB  ((GPIO_typedef *)GPIOB_BASE)
#define GPIOC  ((GPIO_typedef *)GPIOC_BASE)
#define GPIOD  ((GPIO_typedef *)GPIOD_BASE)

#define RCC	   ((RCC_typedef *)RCC_BASE)
#define EXTI   ((EXTI_typedef *)EXTI_BASE)
#define AFIO   ((AFIO_typedef *)AFIO_BASE)
//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define RCC_GPIOA_CLK_EN() (RCC->APB2ENR|=0x4)
#define RCC_GPIOB_CLK_EN() (RCC->APB2ENR|=0x8)
#define RCC_GPIOC_CLK_EN() (RCC->APB2ENR|=0x1)
#define RCC_GPIOD_CLK_EN() (RCC->APB2ENR|=0x20)
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#endif /* INC_STM32F103XX_H_ */
