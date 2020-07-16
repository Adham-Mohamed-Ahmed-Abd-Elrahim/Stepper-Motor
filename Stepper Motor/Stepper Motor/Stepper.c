/*
 * Stepper.c
 *
 * Created: 12/07/2020 02:35:02
 *  Author: ADHM
 */ 
#include "Stepper.h"
//static uint8_t mode;
/*#define MODE 
#if defined (NORMAL)
mode=1;
#elif defined (HALF)
 mode =2;
#endif*/
 static inline void MY_DELAY_MS(uint64_t val)
{while(val--)
	{_delay_ms(1);	
	}
	
}
void STEPPER_INI()
{DDRC=0b00001111;	
}

void CLK_WISE(float RES,uint8_t mode)
{//uint16_t delay=DELAY(RES);
//float rps=RPM/60;
float DELAY =(STEP_ANGLE/RES)*(1000);
	
if(RES>MAX_SPEED) {DELAY=(STEP_ANGLE/MAX_SPEED)*1000;} 
	switch(mode)
	{//NORMAL MODE [full step MODE ]
		case NORMAL:
		PORTC=0b00001000;
	MY_DELAY_MS((int)DELAY);
PORTC=0b00000100;
	MY_DELAY_MS((int)DELAY);
PORTC=0b00000010;
	MY_DELAY_MS((int)DELAY);
PORTC=0b00000001;
	MY_DELAY_MS((int)DELAY); break;
	//Half STEP MODE 
	case HALF:
	DELAY=(float)(DELAY/2);
	PORTC=0b00001001;
	MY_DELAY_MS((int)DELAY);
	PORTC=0b00001000;
	MY_DELAY_MS((int)DELAY);
	PORTC=0b00001100;
	MY_DELAY_MS((int)DELAY);
	PORTC=0b00000100;
	MY_DELAY_MS((int)DELAY);
	PORTC=0b00000110;
	MY_DELAY_MS((int)DELAY);
	PORTC=0b00000010;
	MY_DELAY_MS((int)DELAY); 
	PORTC=0b00000011;
	MY_DELAY_MS((int)DELAY);
	PORTC=0b00000001;
	MY_DELAY_MS((int)DELAY); break;
	
	//NORMAL MODE 
	default:PORTC=0b00001000;
	MY_DELAY_MS((int)DELAY);
	PORTC=0b00000100;
	MY_DELAY_MS((int)DELAY);
	PORTC=0b00000010;
	MY_DELAY_MS((int)DELAY);
	PORTC=0b00000001;
	MY_DELAY_MS((int)DELAY); break;
	}
	
	
}
void COUNTER_CLK_WISE(float RES,uint8_t mode)
{//uint16_t delay=DELAY(RES);
	
	//float rps=RPM/60;
	float DELAY =(STEP_ANGLE/RES)*(1000);
	
	if(RES>MAX_SPEED) {DELAY=(STEP_ANGLE/MAX_SPEED)*1000;}
		switch(mode)
	{//FULL STEP MODE 
		case NORMAL :
		PORTC=0b00000001;
	MY_DELAY_MS((int)DELAY);
	PORTC=0b00000010;
	MY_DELAY_MS((int)DELAY);
	PORTC=0b00000100;
	MY_DELAY_MS((int)DELAY);
	PORTC=0b00001000;
	MY_DELAY_MS((int)DELAY);break;
	//half STEP MODE 
	
	    case HALF:
	
		PORTC=0b00000001;
		MY_DELAY_MS((int)DELAY);
		PORTC=0b00000011;
		MY_DELAY_MS((int)DELAY);
		PORTC=0b00000010;
		MY_DELAY_MS((int)DELAY);
		PORTC=0b00000110;
		MY_DELAY_MS((int)DELAY);
		PORTC=0b00000100;
		MY_DELAY_MS((int)DELAY);
		PORTC=0b00001100;
		MY_DELAY_MS((int)DELAY);
		PORTC=0b00001000;
		MY_DELAY_MS((int)DELAY);
		PORTC=0b00001001;
		MY_DELAY_MS((int)DELAY);break;
		//NORMAL MODE [FULL STEP MODE ]
		default:	
		PORTC=0b00000001;
		MY_DELAY_MS((int)DELAY);
		PORTC=0b00000010;
		MY_DELAY_MS((int)DELAY);
		PORTC=0b00000100;
		MY_DELAY_MS((int)DELAY);
		PORTC=0b00001000;
		MY_DELAY_MS((int)DELAY);break;
	

}
	}