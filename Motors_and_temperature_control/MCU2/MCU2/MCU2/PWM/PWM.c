/*
 * PWM.c
 *
 * Created: 8/31/2023 5:44:00 PM
 *  Author: Mustafa gaber
 */ 
#include <avr/io.h>
#define Angle_
void PWM_init(void)
{   
	/*Timer clock is 1MHz!!!!!!!!!!!! */
	/* USING TIMER1 */
	DDRB|=(1<<DDB1);
	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/8 */
	TCCR1A = (1<<WGM11)|(1<<COM1A1);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS11);
	ICR1=2499;  //fPWM=50Hz (Period = 20ms Standard)
	OCR1B=250; /*for 5 seconds in abnormal state*/
}
void ServoPosition(unsigned int duty)
{
	OCR1A=duty;
}
