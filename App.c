/*
 * App.c
 *
 *  Created on: Sep 26, 2019
 *      Author: Randa
 */


#include "service.h"
#include "motor.h"

void motor_switch(void)
{
	//toggle motor pins
	MOTOR_toggle();
}

int main(void)
{
	uint8 delay = 10;
	MOTOR_init();
	//7 seg
	while(1)
	{
		delay_sec(motor_switch, delay);
	}
}
