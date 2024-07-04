/*
 * uart.c
 *
 * Created: 8/31/2023 1:43:46 PM
 *  Author: Mustafa gaber
 */ 
#include <avr/io.h>
void uart_init(void)
{   /*Set baud rate */
	UBRR0H = (unsigned char)(103>>8);
	UBRR0L = (unsigned char)103;
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 8data, 2stop bit */
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}
void uart_send( unsigned short data )
{
	
	/* Wait for empty transmit buffer */
	if ( ( UCSR0A & (1<<UDRE0)) )
	UDR0 = data;
	/* Put data into buffer, sends the data */

}
void uart_send_string(unsigned char* data)
{
	unsigned char i=0;
	while(data[i]!='\0')
	{
		while ( !( UCSR0A & (1<<UDRE0)) )
		// Put data into buffer, sends the data
		UDR0 = data[i];
		i++;
	}
}
unsigned char uart_recieve()
{
	if((UCSR0A & (1<<RXC0)))
	return UDR0;
}