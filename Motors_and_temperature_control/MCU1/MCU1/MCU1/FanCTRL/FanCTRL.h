/*
 * FanCTRL.h
 *
 * Created: 8/31/2023 6:10:33 PM
 *  Author: Mustafa gaber
 */ 


#ifndef FANCTRL_H_
#define FANCTRL_H_
#define MAX_Speed 255
#define Fan_OFF 0x00
#define Speed(temperature) (temperature-20)*255/20.0
void FanCTRL_init(void);
#endif /* FANCTRL_H_ */