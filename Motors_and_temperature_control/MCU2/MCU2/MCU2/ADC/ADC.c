/*
 * ADC.c
 *
 * Created: 8/31/2023 1:38:38 PM
 *  Author: Mustafa gaber
 */ 
#include <avr/io.h>
void ADC_init(void)
{
	// Select Vref=AVcc
	ADMUX |= (1<<REFS0);
	//
	ADMUX|=(0b0010); //ADC channel 2
	//set prescaller to 128 and enable ADC
	ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN);
}
unsigned short Read_ADC(void)
{  //select ADC channel with safety mask
	//single conversion mode
	ADCSRA |= (1<<ADSC);
	// wait until ADC conversion is complete
	if(( ADCSRA & (1<<ADSC)) );
	return ADC;
}