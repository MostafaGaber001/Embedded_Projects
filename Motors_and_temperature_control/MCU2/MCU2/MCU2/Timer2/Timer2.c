
/*
 * Timer2.h
 *
 * Created: 9/2/2023 1:46:24 AM
 *  Author: Mustafa gaber
 */ 
#include <avr/io.h>
void Timer2Begin(void)
{
	//1MHz clock
	//Normal mode timer
	TCCR2B|=(1<<CS22)|(1<<CS20)|(CS21); /*1024 PRESCALER*/
		// no need for compare value we will interrupt when overflow happens
}
void Timer2Stop(void)
{
	TCCR2B=0; //Cut the clock source
}
