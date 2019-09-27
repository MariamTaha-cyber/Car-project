/*
 * seven_segment.c
 *
 *  Created on: 27 Sep 2019
 *      Author: Mariam Taha
 */

#include "seven_segment.h"

uint8 seconds_count_increment=0;
sint8 seconds_count_decrement=9;

void seven_segment_init(void)
{
	//Configure first four pins in data port as output pins
	segment_Data_PORT_direction |=((1u<<Data_PIN1)|(1u<<Data_PIN2)|(1u<<Data_PIN3)|(1u<<Data_PIN4));

	//Initial values for all the Seven-segment pins
	segment_Data_PORT_output &=~((1u<<PC0)|(1u<<PC1)|(1u<<PC2)|(1u<<PC3));


	TIMER_init();
}

void seven_segment_increment(void)
{
	if(TIMER1_Flag_tick==1)
	{
		seconds_count_increment++;

		if(seconds_count_increment == 10)
		{
			seconds_count_increment = 0;
		}
		TIMER1_Flag_tick=0;
	}
	else
	{
		segment_Data_PORT_output =(segment_Data_PORT_output & 0xF0) | (seconds_count_increment);
		_delay_ms(2);
	}
}


void seven_segment_decrement(void)
{
	if(TIMER1_Flag_tick==1)
	{
		seconds_count_decrement--;

		if(seconds_count_decrement == -1)
		{
			seconds_count_decrement = 9;
		}
		TIMER1_Flag_tick=0;
	}
	else
	{
		PORTC =(PORTC & 0xF0) | (seconds_count_decrement);
		_delay_ms(2);
	}
}
