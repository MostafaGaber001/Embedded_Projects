/*
 * ADC.h
 *
 * Created: 8/31/2023 1:38:47 PM
 *  Author: Mustafa gaber
 */ 


#ifndef ADC_H_
#define ADC_H_
/****************Vreference = 10 voltage************** for sensor*/
void ADC_init(void);
unsigned short Read_ADC(void);
#endif /* ADC_H_ */