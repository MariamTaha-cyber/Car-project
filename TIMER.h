/*
 * TIMER.h
 *
 *  Created on: Sep 21, 2019
 *      Author: Randa
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "Timer_config.h"
#include "Dio.h"
#include "avr/interrupt.h"

#define MAX_NUM_OF_TIMERS 3
#define NUMBER_OF_OVERFLOWS 4

volatile uint8 TIMER0_Flag_tick;
volatile uint8 TIMER1_Flag_tick;


TIMER_cnfg_t timers[num_of_timers];

uint8 TIMER_init(void);
uint8 TIMER_PWM(uint8 duty_cycle);

#endif /* TIMER_H_ */
