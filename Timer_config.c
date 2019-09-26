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
		{OVERFLOW,Timer0,ON,Prescaler_256,IN_CLK,NA,NA,NA,NA,NA,NA,NA,0x00,NA,NA,NA,INITIALISED},
		{OVERFLOW,Timer1,ON,Prescaler_256,IN_CLK,NA,NA,NA,NA,NA,NA,NA,0xF9E6,NA,NA,INITIALISED}
};

