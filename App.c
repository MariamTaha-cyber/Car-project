/*
 * App.c
 *
 *  Created on: Sep 26, 2019
 *      Author: Randa
 */


#include "service.h"

void motor_switch(void)
{
	//toggle motor pins
	MOTOR_toggle();
}

int main(void)
{
	uint8 delay = 10;

	service_init();

	while(1)
	{
		delay_sec(motor_switch, delay);

	}
}

