/*
 * PWM.h
 *
 * Created: 8/31/2023 5:43:38 PM
 *  Author: Mustafa gaber
 */ 


#ifndef PWM_H_
#define PWM_H_
#define Angle_p90 249.9  /*these value was calculated by mapping 0-2499 with 1ms-2ms pulse width */
#define Angle_0  187.425
#define Angle_n90 124.95 
void PWM_init(void);
void ServoPosition(unsigned int duty); 
#endif /* PWM_H_ */