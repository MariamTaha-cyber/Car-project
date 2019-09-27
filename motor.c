/*
 * motor.c
 *
 *  Created on: Sep 26, 2019
 *      Author: Randa
 */
#include "motor.h"


uint8 OUTPUT1 = HIGH;
uint8 OUTPUT2 = LOW;

void MOTOR_init(void)
{
	DIO_init();
	DIO_write(PORT_A, PIN0, MotorOut1, HIGH);
	DIO_write(PORT_A, PIN1, MotorOut2, LOW);
}
void MOTOR_toggle(void)
{
	OUTPUT1 ^= 1u;
	OUTPUT2 ^= 1u;

	DIO_write(PORT_A, PIN0, MotorOut1, OUTPUT1);
	DIO_write(PORT_A, PIN1, MotorOut2, OUTPUT2);

}

