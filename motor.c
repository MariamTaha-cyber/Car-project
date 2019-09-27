/*
 * motor.c
 *
 *  Created on: Sep 26, 2019
 *      Author: Randa
 */
#include "motor.h"


uint8 clockwise = HIGH;
uint8 anti_clockwise = LOW;

void MOTOR_init(void)
{
	DIO_init();
}
void MOTOR_toggle(void)
{
	DIO_write(PORT_A, PIN0, MotorOut1, clockwise);
	DIO_write(PORT_A, PIN1, MotorOut2, anti_clockwise);
	clockwise ^= 1u;
	anti_clockwise ^= 1u;
}

