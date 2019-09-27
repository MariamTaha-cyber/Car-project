/*
 * Timers.c
 *
 *  Created on: Sep 21, 2019
 *      Author: Mariam Taha
 */

#include "Timers.h"

volatile uint8 TIMER0_Flag_tick = 0;
volatile uint8 TIMER1_Flag_tick = 0;
volatile uint8 TIMER2_Flag_tick = 0;
volatile static uint8 PWM_count1 = 0;
volatile static uint8 PWM_count2 = 0;
static uint8 toggle_value = 1;

volatile uint8 seven_segment_Flag_tick=0;

volatile uint8 seven_segment_Flag_tick=0;

static volatile void (*g_Timer_callBackPtr)(void) = NULL;
uint8 g_delay=0;

//Clk set function
static uint8 TIMER_start(uint8 timer)
{
	uint8 retval = OK;
	switch (timer)
	{
	case Timer0:
		if(timers[Timer0].clk_Oscillator == IN_CLK)
		{
			switch (timers[Timer0].prescalar)
			{
			case No_Prescaler:
				TCCR0 |= (1u << FOC0 )| (1u << CS00);
				break;
			case Prescaler_8:
				TCCR0 |= (1u << FOC0) |( 1u << CS01);
				break;
			case Prescaler_64:
				TCCR0 |= (1u << FOC0) | (1u << CS01) |( 1u << CS00);
				break;
			case Prescaler_256:
				TCCR0 |= (1u << FOC0) |( 1u << CS02);
				break;
			case Prescaler_1024:
				TCCR0 |= (1u << FOC0 )|( 1u << CS02 )|( 1u << CS00);
				break;
			default:
				timers[timer].is_configured = UNINITIALISED;
				retval=NOK;
			}
		}
		else if(timers[Timer0].clk_Oscillator == EX_CLK)
		{
			if(timers[Timer0].EX_clk_edge==Falling_edge)
			{
				TCCR0 = (1u << FOC0) |(1u << CS02) | (1u << CS01);
			}
			else if(timers[Timer0].EX_clk_edge==Rising_edge)
			{
				TCCR0 = (1u << FOC0) | (1u << CS02) | (1u << CS01)|( 1u << CS00);
			}
			else
			{
				timers[Timer0].is_configured = UNINITIALISED;
				retval=NOK;
			}
		}
		else
		{
			timers[Timer0].is_configured = UNINITIALISED;
			retval=NOK;
		}
		break;
	case Timer1:
		if(timers[Timer1].clk_Oscillator == IN_CLK)
		{
			switch (timers[Timer1].prescalar)
			{
			case No_Prescaler:
				TCCR1B |= (1u << CS00);
				break;
			case Prescaler_8:
				TCCR1B |= ( 1u << CS01);
				break;
			case Prescaler_64:
				TCCR1B |= (1u << CS01) | ( 1u << CS00);
				break;
			case Prescaler_256:
				TCCR1B |= ( 1u << CS02);
				break;
			case Prescaler_1024:
				TCCR1B |= ( 1u << CS02 ) | ( 1u << CS00);
				break;
			default:
				timers[Timer1].is_configured = UNINITIALISED;
				retval=NOK;
			}
		}
		else if(timers[Timer1].clk_Oscillator == EX_CLK)
		{
			if(timers[Timer1].EX_clk_edge==Falling_edge)
			{
				TCCR1B = (1u << CS02) | (1u << CS01);
			}
			else if(timers[Timer1].EX_clk_edge==Rising_edge)
			{
				TCCR1B = (1u << CS02) | (1u << CS01)|( 1u << CS00);
			}
			else
			{
				timers[Timer1].is_configured = UNINITIALISED;
				retval=NOK;
			}
		}
		else
		{
			timers[Timer1].is_configured = UNINITIALISED;
			retval=NOK;
		}
		break;
	}

	return retval;
}

//Timer modes initialization function
uint8 TIMER_init(void)
{
	uint8 retval = OK;
	uint8 loop_index;
	if(num_of_timers <= MAX_NUM_OF_TIMERS)
	{
		for(loop_index = 0; loop_index < num_of_timers; loop_index++)
		{
			switch (timers[loop_index].timer)
			{
			case Timer0:
				TCNT0 = (uint8)timers[loop_index].Timer_reg;
				switch (timers[loop_index].mode)
				{
				case OVERFLOW:
					if(timers[loop_index].interrupt_flag == ON)
					{
						SREG  |= (1 << I_bit);
						TIMSK |= (1u << TOIE0);
					}
					else if(timers[loop_index].interrupt_flag == NA)
					{
						TIMSK &= ~(1u << TOIE0);
					}
					break;
				case OUTCOMP:
					TCCR0 = (1u << FOC0 | 1u << WGM01);
					OCR0 = (uint8)timers[loop_index].Compare_reg;
					if(timers[loop_index].CTC_flag == Normal_Compare_match)
					{
						if(timers[loop_index].interrupt_flag == ON)
						{
							SREG  |= (1 << I_bit);
							TIMSK |= (1u << OCIE0);
						}
						else if(timers[loop_index].interrupt_flag == NA)
						{
							TIMSK &= ~(1u << OCIE0);
						}
						else
						{
							timers[loop_index].is_configured = UNINITIALISED;
							retval = NOK;
						}
					}
					// if(timers[loop_index].CTC_flag == Normal_Compare_match) end
					else if(timers[loop_index].CTC_flag == Wave_generation)
					{
						//set OC0 as output pin
						DDRB  = DDRB | (1 << WG_Timer0_PIN);
						TIMSK &= ~(1u << OCIE0);
						switch (timers[loop_index].WG_PIN)
						{
						case WG_TOGGLE_Pin:
							TCCR0 = (1u << COM00);	
							break;
						case WG_CLEAR_Pin:
							TCCR0 = (1u << COM01);
							break;
						case WG_SET_Pin:
							TCCR0 = (1u << COM00 | 1u << COM01);	
							break;
						default:
							timers[loop_index].is_configured = UNINITIALISED;
						}
					}
					break;
				default:
					timers[loop_index].is_configured = UNINITIALISED;
					retval = NOK;
				}
				TIMER_start(Timer0);
				break;
				case Timer1:
				{
					TCNT1 = timers[Timer1].Timer_reg;
					switch (timers[Timer1].mode)
					{
					case OVERFLOW:
					{
						TCCR1A = (1u << FOC1A) | (1u << FOC1B);
						if(timers[Timer1].interrupt_flag == ON)
						{
							SREG  |= (1u << I_bit);
							TIMSK |= (1u << TOIE1);
						}
						else if(timers[Timer1].interrupt_flag == NA)
						{
							TIMSK &= ~(1u << TOIE1);
						}
						else
						{
							timers[Timer1].is_configured = UNINITIALISED;
							retval = NOK;
						}
					}
					break;
					case OUTCOMP:
					{
						TCCR1A = (1u << FOC1A) | (1u << FOC1B);
						if(timers[loop_index].CTC_flag == Normal_Compare_match)
						{
							if(timers[loop_index].Timer1_channel == CHANNEL_A)
							{
								TCCR1B = (1 << WGM12);
								OCR1A = timers[loop_index].Compare_reg;
								if(timers[loop_index].interrupt_flag == ON)
								{
									SREG  |= (1u << I_bit);
									TIMSK |= (1u << OCIE1A);
								}
								else if(timers[loop_index].interrupt_flag == NA)
								{
									TIMSK &= ~(1u << OCIE1A);
								}
							}
							else if(timers[loop_index].Timer1_channel == CHANNEL_B)
							{
								OCR1B = timers[loop_index].Compare_reg;
								if(timers[loop_index].interrupt_flag == ON)
								{
									SREG  |= (1u << I_bit);
									TIMSK |= (1u << OCIE1B);
								}
								else if(timers[loop_index].interrupt_flag == NA)
								{
									TIMSK &= ~(1u << OCIE1B);
								}
							}
						}
						else
						{
							retval = NOK;
							timers[loop_index].is_configured = UNINITIALISED;
						}
					}
					break;
					default:
					{
						retval =  NOK;
						timers[loop_index].is_configured = UNINITIALISED;
					}
					}
					TIMER_start(Timer1);
				}
				break;
			}
		}
	}
	else
	{
		for(loop_index = 0; loop_index < num_of_timers; loop_index++)
		{
			timers[loop_index].is_configured = UNINITIALISED;
		}
		retval = NOK;
	}
	return retval;
}

//Timer PWM mode initialization function
uint8 TIMER_PWM(uint8 duty_cycle)
{
	uint8 retval = OK;
	uint8 loop_index;
	uint8 OCR0_value = 0;
	//uint16 OCR1_value;
	//uint8 OCR2_value;
	if(num_of_timers <= MAX_NUM_OF_TIMERS)
	{
		for(loop_index = 0; loop_index < num_of_timers; loop_index++)
		{
			if(timers[loop_index].mode == PWM)
			{
				switch(timers[loop_index].timer)
				{
				case Timer0:
					TCCR0 &= ~(1 << FOC0);		//FOC0 = 0 -> PWM mode
					DDRB  = DDRB | (1 << WG_Timer0_PIN); 	//set OC0 as output pin
					OCR0_value = ((duty_cycle * OVERFLOW_OF_TIMER0) / 100);
					OCR0 = OCR0_value;
					switch(timers[loop_index].PWM_mode_option)
					{
					case FAST_PWM:
						TCCR0 |= (1u << WGM01 | 1u << WGM00);
						if(timers[loop_index].inverting_mode == INVERTING)
						{
							TCCR0 |= (1u << COM01 | 1u << COM00);
						}
						else if(timers[loop_index].inverting_mode == NON_INVERTING)
						{
							TCCR0 |= (1u << COM01);
						}
						break; //FAST PWM break
					case Phase_correct_PWM:
						TCCR0 |= (1u << WGM00);
						if(timers[loop_index].inverting_mode == INVERTING)
						{
							TCCR0 |= (1u << COM01 | 1u << COM00);
						}
						else if(timers[loop_index].inverting_mode == NON_INVERTING)
						{
							TCCR0 |= (1u << COM01);
						}
						break; //Phase correct break
					default:
						timers[loop_index].is_configured = UNINITIALISED;
						retval = NOK;
					}
					//clock start
					retval=TIMER_start(Timer0);
					break;
				}
			}
			else
			{
				timers[loop_index].is_configured = UNINITIALISED;
				retval = NOK;
			}
		}
	}
	else
	{
		for(loop_index = 0; loop_index < num_of_timers; loop_index++)
		{
			timers[loop_index].is_configured = UNINITIALISED;
		}
		retval = NOK;
	}
	return retval;
}

void PWM(uint8 timer, uint8 duty_cycle)
{

	DIO_write(PORT_B, PIN3, test, toggle_value);

	TCCR0 = (1u << FOC0 | 1u << WGM01);
	TCNT0 = 0;
	OCR0 = (uint8) 250;
	SREG  |= (1 << I_bit);
	TIMSK |= (1u << OCIE0);
	TIMER_start(timer);

	if(duty_cycle == 25)
	{
		PWM_count1 = 1;
		PWM_count2 = 4;
	}
	else if(duty_cycle == 50)
	{
		PWM_count1 = 2;
		PWM_count2 = 4;
	}
	else if(duty_cycle == 75)
	{
		PWM_count1 = 3;
		PWM_count2 = 4;
	}

}
//set call back function
void TIMER_delay_sec(void(*ServiceFuncPtr)(void),uint8 delay)
{
	g_Timer_callBackPtr=ServiceFuncPtr;
	g_delay=delay;
}

ISR(TIMER0_OVF_vect)
{
	TIMER0_Flag_tick++;
}

ISR(TIMER0_COMP_vect)
{
	TIMER0_Flag_tick++;
	if(TIMER0_Flag_tick == PWM_count1)
	{
		DIO_write(PORT_B, PIN3, test, toggle_value);
	}
	else if(TIMER0_Flag_tick == PWM_count2)
	{
		toggle_value ^= 1;
		DIO_write(PORT_B, PIN3, test, toggle_value);
		TIMER0_Flag_tick = 0;
	}
}

ISR(TIMER1_OVF_vect)
{
	TIMER1_Flag_tick++;
	TCNT1 = timers[Timer1].Timer_reg;
}

ISR (TIMER1_COMPA_vect)
{
	TIMER1_Flag_tick++;
	seven_segment_Flag_tick++;

	if(TIMER1_Flag_tick==g_delay)
	{
		TIMER1_Flag_tick=0;
		(*g_Timer_callBackPtr)();
	}
}

ISR(TIMER2_OVF_vect)
{
	TIMER2_Flag_tick++;
}

ISR(TIMER2_COMP_vect)
{
	TIMER2_Flag_tick++;
}
