/*
 * Timer_config.c
 *
 *  Created on: Sep 25, 2019
 *      Author: Randa
 */

#include "Timer_config.h"
/*
TIMER_cnfg_t timers[num_of_timers]=
{
		{OVERFLOW,Timer0,ON,Prescaler_256,IN_CLK,NA,NA,NA,NA,NA,NA,NA,0x00,NA,NA,NA,INITIALISED}
};
*/


TIMER_cnfg_t timers[num_of_timers]=
{
		{PWM,Timer0,NA,Prescaler_256,IN_CLK,NA,NA,NA,NA,NA,FAST_PWM,NON_INVERTING,0x00,0x00,NA,NA,INITIALISED}
};

