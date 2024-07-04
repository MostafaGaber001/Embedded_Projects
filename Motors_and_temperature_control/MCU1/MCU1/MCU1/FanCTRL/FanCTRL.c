/*
 * FanCTRL.c
 *
 * Created: 8/31/2023 6:10:04 PM
 *  Author: Mustafa gaber
 */ 
#include <avr/io.h>
void FanCTRL_init(void)
{ //output pins for motor
	DDRD|=(1<<DDD3)|(1<<DDD4);
	PORTD|=(1<<DDD3);  /*Motor IS running*/
	//PWM output
	DDRB|=(1<<DDB3);
	/* Set Fast PWM - OC2A on compare match */
	TCCR2A = (1<<WGM20)|(1<<WGM21)|(1<<COM2A1);
	TCCR2B = (1<<CS21);
}