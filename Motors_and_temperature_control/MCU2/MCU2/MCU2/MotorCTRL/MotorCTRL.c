/*
* MotorCTRL.c
*
* Created: 8/31/2023 5:48:53 PM
*  Author: Mustafa gaber
*/
#include <avr/io.h>
void MotorCTRL_init(void)
{ 
	 /*===============USING TIMER2=================*/ 
	//Logic output pins for motor
	DDRD|=(1<<DDD3)|(1<<DDD4);
	PORTD|=(1<<DDD3);  /*Motor IS running*/
	//PWM output
	DDRB|=(1<<DDB3);  /* PORTD Pin 3 */
	/* Set Fast PWM - OC2A on compare match */
	TCCR2A = (1<<WGM20)|(1<<WGM21)|(1<<COM2A1);
	TCCR2B = (1<<CS21);
}
