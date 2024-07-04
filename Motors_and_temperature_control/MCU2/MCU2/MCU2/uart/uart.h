/*
 * uart.h
 *
 * Created: 8/31/2023 5:39:38 PM
 *  Author: Mustafa gaber
 */ 


#ifndef UART_H_
#define UART_H_
void uart_init(void);
void uart_send(unsigned char);
void uart_send_string(unsigned char*);
unsigned char uart_recieve(void);
#endif /* UART_H_ */