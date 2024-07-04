/*
 * MotorCTRL.h
 *
 * Created: 8/31/2023 5:49:15 PM
 *  Author: Mustafa gaber
 */ 


#ifndef MOTORCTRL_H_
#define MOTORCTRL_H_
#define Motor_SetSpeed(speed) (speed/1023.0)*255
void MotorCTRL_init(void);
#endif /* MOTORCTRL_H_ */