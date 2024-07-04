/*
 * WDT_Timer1.h
 *
 * Created: 9/2/2023 12:03:24 AM
 *  Author: Mustafa gaber
 */ 


#ifndef WDT_TIMER1_H_
#define WDT_TIMER1_H_
#include <avr/wdt.h>
void Timer1Begin(void);
void Timer1Stop(void);
void WDT_Begin(void);
void WDT_Stop(void);


#endif /* WDT_TIMER1_H_ */