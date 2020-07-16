/*
 * Stepper Motor.c
 *
 * Created: 12/07/2020 02:34:13
 * Author : ADHM
 */ 

#include <avr/io.h>
#include "Stepper.h"
#define MODE HALF


int main(void)
{STEPPER_INI();
	
    /* Replace with your application code */
    while (1) 
    {
	/*CLK_WISE(12,NORMAL);
	_delay_ms(500);
	CLK_WISE(12,HALF);
	_delay_ms(500);
	COUNTER_CLK_WISE(12,NORMAL);
		_delay_ms(500);*/
			COUNTER_CLK_WISE(12,HALF);
			_delay_ms(500);
	//COUNTER_CLK_WISE(60);
		//_delay_ms(500);


    }
}

