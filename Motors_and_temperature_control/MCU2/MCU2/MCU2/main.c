/*
* MCU2.c
*
* Created: 8/31/2023 5:23:12 PM
* Author : Mustafa gaber
*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "uart.h"
#include "ADC.h"
#include "PWM.h"
#include "MotorCTRL.h"
#include "Timer2.h"
#define SREG   *((volatile unsigned char*)(0x5F))
#define Normal_State_lvl1 'g'
#define Normal_State_lvl2 'y'
#define Normal_State_lvl3 'r'
#define Emergency   'e'
#define Abnormal 'a'
unsigned char Time=0;
unsigned int x =0;
unsigned char state;
int main(void)
{	uart_init();
	ADC_init();
	PWM_init();
	INT0_InterruptEnable();
	MotorCTRL_init();
	DDRB|=(0b111)<<DDB4; /*Output led pins pin 4 5 6 */
	DDRD|=(1<<DDD5); /* Buzzer pin */

	unsigned int speed;
	ServoPosition(Angle_0);
	while (1)
	{
		state=uart_recieve();
		speed=Read_ADC();
		OCR2A=Motor_SetSpeed(speed);
		switch(state)
		{
			case Normal_State_lvl1: PORTB|=(1<<DDB4);
			PORTB &=~((1<<DDB5)|(1<<DDB6)); // enable the indicating led and disable the others
			PORTD &=~(1<<DDD5);              //
			break;
			case Normal_State_lvl2: PORTB|=(1<<DDB5);
			PORTB &=~((1<<DDB4)|(1<<DDB6));
			PORTD &=~(1<<DDD5);
			break;
			case Normal_State_lvl3: PORTB|=(1<<DDB6);
			PORTB &=~((1<<DDB5)|(1<<DDB4));
			PORTD &=~(1<<DDD5);
			break;
			case Emergency : PORTB|=(1<<DDB6);
			PORTB &=~((1<<DDB5)|(1<<DDB4));
			PORTD |=(1<<DDD5);
			break;
			case Abnormal : Abnormal_State();
			break;
		}
	}
}
void Abnormal_State()
{	uart_send('k'); //sending acknowledge to MCU1 that i entered the abnormal state
	EIMSK&=~(1<<INT0);
	/*After MCU1 resting it sends unintentionally an IRQ for MCU2 so to avoid
	that i disabled INT0 for a while and will be enabled after ending abnormal case*/
	Timer1OVFen();
}

void INT0_InterruptEnable(void)
{/*INT0*/
	PORTD|=(1<<DDD2); /*Pin2 PORTD input */
	SREG |=(1<<7); /*setting bit 7 int AVR status register --Enable interrupts-- */
	EICRA|=(1<<ISC00)|(1<<ISC01); /*Detecting Rise Edge on INT0 pin*/
	EIMSK|=(1<<INT0);
	/*INT0 PIN IS READY*/
}
ISR(INT0_vect)
{		uart_send('k');
	    PORTD=PORTD^(1<<DDD3); /*SHTTING THE MACHINE*/
	    EIFR|=(1<<INTF0); /* CLEAR INTERRUPT FLAG*/
}

void Timer1OVFen(void)
{
	SREG|=(1<<7);//Enable global interrupt;
	TIMSK1|=(1<<TOIE1); //Timer/Counter1, OverFlow Interrupt Enable
};

ISR(TIMER1_OVF_vect)
{	if(Time>250)/* 19*255*(1024/1000000)=OUR 5seconds delay */
	{
		TIMSK1&=~(1<<TOIE1);
		PORTD|=(1<<DDD3);
		ServoPosition(Angle_0);
		EIMSK|=(1<<INT0);
		Time=0;
	}
	else
	{
	Time++;
	PORTD&=~(1<<DDD3); // Shutting the machine
	ServoPosition(Angle_p90);
	
	}
}
