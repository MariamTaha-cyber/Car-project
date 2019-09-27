/*
 * service.h
 *
 *  Created on: Sep 26, 2019
 *      Author: Randa
 */

#ifndef SERVICE_H_
#define SERVICE_H_

#include "Timers.h"
#include "motor.h"
#include "seven_segment.h"


void service_init(void);
void delay_sec(void(*appFuncPtr)(void),uint8 period);
void appCall(void);

#endif /* SERVICE_H_ */
