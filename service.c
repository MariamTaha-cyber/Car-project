/*
 * service.c
 *
 *  Created on: Sep 26, 2019
 *      Author: Randa
 */

#include "service.h"

static volatile void (*g_callBackPtr)(void) = NULL;

void service_init(void)
{
	MOTOR_init();
	seven_segment_init();

}


void delay_sec(void(*appFuncPtr)(void), uint8 period)
{
	//Set callback function
	g_callBackPtr = appFuncPtr;
	TIMER_delay_sec(appCall, period);
	seven_segment_increment();
}

void appCall(void)
{
	(*g_callBackPtr)();
}
