/*
* MCU1.c
*
* Created: 8/31/2023 1:38:03 PM
* Author : Mustafa gaber
*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "ADC.h"
#include "uart.h"
#include "MachineSates.h"
#include "FanCTRL.h"
#include "WDT_Timer1.h"
#include "EEPROM.h"
#define SREG   *((volatile unsigned char*)(0x5F))
int main(void)
{   wdt_disable();
	unsigned char Button_next_action=0; //
	unsigned char previous_state=Normal_State_lvl1;
	uart_init();
	ADC_init();
	FanCTRL_init();
	Timer1Match_INTen();
	PORTD|=(1<<DDD5);  /*Push button pin input*/
	 // output ping for external interrupt for MCU2
	PORTD|=(1<<DDD7);
	DDRB|=(1<<DDD7); 
	unsigned char current_temp=0;
	while (1)
	{
		current_temp=Read_ADC()-1;
		if(((PIND&(1<<PIND5))>>PIND5)&&(Button_next_action==1))
		{
			PORTB|=(1<<DDB7);
			PORTB&=~(1<<DDB7);
			   Button_next_action^=(1);
			while (((PIND&(1<<PIND5))>>PIND5));

		}
		if(current_temp<40)
		{ 
			if(current_temp>20)
			{ OCR2A=Speed(current_temp);
				uart_send(Normal_State_lvl2);
				if(previous_state!=Normal_State_lvl2)
			   {	EEPROM_Write(0x0,Normal_State_lvl2);
					previous_state=Normal_State_lvl2;
			   }
			}
			else
			{  uart_send(Normal_State_lvl1);
				OCR2A=Fan_OFF;
			if(previous_state!=Normal_State_lvl1)
				{
					EEPROM_Write(0x0,Normal_State_lvl1);
					previous_state=Normal_State_lvl1;
				}
			}
		}
		
		else
		{	OCR2A=MAX_Speed;
			if(current_temp<50)
			{   uart_send(Normal_State_lvl3);
			if(previous_state!=Normal_State_lvl3)
				{	
					EEPROM_Write(0x0,Normal_State_lvl3);
					previous_state=Normal_State_lvl3;
				}
				if(((PIND&(1<<PIND5))>>PIND5))
				{	
					PORTB|=(1<<DDB7);
					PORTB&=~(1<<DDB7);
				    Button_next_action^=(1);
					while (((PIND&(1<<PIND5))>>PIND5));

				}
			}
			else
			{	if(previous_state!=Abnormal)
				{
					EEPROM_Write(0x0,Emergency);
					previous_state=Abnormal;
				}
				emergency_state();
			}
		}
	}
}
void Timer1Match_INTen(void)
{
	SREG|=(1<<7);//Enable global interrupt;
	TIMSK1|=(1<<OCIE1A); //Timer/Counter1, Output Compare A Match Interrupt Enable
};
void emergency_state(void)
{
	Timer1Begin();
	while((Read_ADC()-1)>50)
	{  uart_send('e');
	}
	Timer1Stop();

}
ISR(TIMER1_COMPA_vect)
{	
	while(UDR0!='a'&& !(UCSR0A&(1<<TXC0)))
	uart_send(Abnormal);
	while(uart_recieve()!='k')
	{
		uart_send(Abnormal);
	}EEPROM_Write(0x0,Abnormal);
	SREG|=(1<<7);
	WDT_Begin();
}
