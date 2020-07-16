/*
 * Stepper.h
 *
 * Created: 12/07/2020 02:34:43
 *  Author: ADHM
 */ 


#ifndef STEPPER_H_
#define STEPPER_H_
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

//************************************
#define RPM (360)
#define STEP_ANGLE (12)

//#define DELAY(DEG) (int)((DEG)/(RPM*6))
#define RPS (float)(RPM/60)
#define MAX_SPEED  (float)(RPS*STEP_ANGLE)
#define DELAY(SPEED) (float)((float)(STEP_ANGLE/SPEED)*(1000))
//#define STEPS_PER_REV 360/STEP_ANGLE
//#define STEPS_PER_SEC RPS*STEPS_PER_REV
//#define DELAY(DEG) (int)((DEG)*((1/(RPS))/(STEPS_PER_REV))/(STEP_ANGLE))
//******************************************
#define NORMAL (1)
#define HALF  (2) 

//Functions 
//intialize Pins for stepper motor as OUTPUT
void STEPPER_INI();
//Res = angle per step 
void CLK_WISE(float RES,uint8_t mode);
void COUNTER_CLK_WISE(float RES,uint8_t mode);
//to perform delay with a variable 
static inline void MY_DELAY_MS(uint64_t val);





#endif /* STEPPER_H_ */