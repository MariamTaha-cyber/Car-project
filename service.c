/*
 * service.c
 *
 *  Created on: Sep 26, 2019
 *      Author: Randa
 */

#include "service.h"

static volatile void (*g_callBackPtr)(void) = NULL;


void delay_sec(void(*appFuncPtr)(void), uint8 period)
{
	//Set callback function
	g_callBackPtr = appFuncPtr;
	timers[Timer1].prescalar;
	TIMER_delay_sec(appCall, period);
}

void appCall(void)
{
	(*g_callBackPtr)();
}
