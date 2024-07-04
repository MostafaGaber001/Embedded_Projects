/*
 * WDT_Timer1.c
 *
 * Created: 9/2/2023 12:03:08 AM
 *  Author: Mustafa gaber
 */ 
#include <avr/io.h>
#include <avr/wdt.h>
#define SREG   *((volatile unsigned char*)(0x5F))
void Timer1Begin(void)
{
	//1MHz clock
	//Normal mode timer
	TCCR1B|=(1<<CS12)|(1<<CS10); /*1024 PRESCALER*/
	OCR1A=6836; //Matching happens after 7 Seconds
}
void Timer1Stop(void)
{
	TCCR1B=0; //Cut the clock source
}
void WDT_Begin(void)
{    SREG&=~(1<<7);
	 wdt_reset();
	 wdt_enable(WDTO_15MS);
}

