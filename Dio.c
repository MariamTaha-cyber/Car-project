
#include "Dio.h"


status DIO_init(void)
{
	uint8 loop_index;
	status retval=OK;

	if(num_of_pins<=Max_num_of_pins)
	{
		for(loop_index=0;loop_index<num_of_pins;loop_index++)
		{
			Peripherals[loop_index].is_configured=INITIALIZED;
			switch(Peripherals[loop_index].PORT)
			{
			case PORT_A:

				if(Peripherals[loop_index].direction==OUTPUT)
				{
					DDRA |=(1u<<Peripherals[loop_index].PIN);
					if(Peripherals[loop_index].intial_value==HIGH)
					{
						PORTA |=(1u<<Peripherals[loop_index].PIN);
					}
					else if(Peripherals[loop_index].intial_value==LOW)
					{
						PORTA &=~(1u<<Peripherals[loop_index].PIN);
					}
					else
					{
						Peripherals[loop_index].is_configured=UNINITIALIZED;
						retval=NOK;
					}

				}
				else if (Peripherals[loop_index].direction==INPUT)
				{
					DDRA &=~(1u<<Peripherals[loop_index].PIN);
					if(Peripherals[loop_index].resistor==PULLUP)
					{
						PORTA |=(1u<<Peripherals[loop_index].PIN);
					}
					else if(Peripherals[loop_index].resistor==EXTERNAL)
					{
						PORTA &=~(1u<<Peripherals[loop_index].PIN);
					}
					else
					{
						Peripherals[loop_index].is_configured=UNINITIALIZED;
						retval=NOK;
					}

				}
				else
				{
					Peripherals[loop_index].is_configured=UNINITIALIZED;
					retval=NOK;
				}

				break;
			case PORT_B:
				if(Peripherals[loop_index].direction==OUTPUT)
				{
					DDRB |=(1u<<Peripherals[loop_index].PIN);
					if(Peripherals[loop_index].intial_value==HIGH)
					{
						PORTB |=(1u<<Peripherals[loop_index].PIN);
					}
					else if(Peripherals[loop_index].intial_value==LOW)
					{
						PORTB &=~(1u<<Peripherals[loop_index].PIN);
					}
					else
					{
						Peripherals[loop_index].is_configured=UNINITIALIZED;
						retval=NOK;
					}

				}
				else if (Peripherals[loop_index].direction==INPUT)
				{
					DDRB &=~(1u<<Peripherals[loop_index].PIN);
					if(Peripherals[loop_index].resistor==PULLUP)
					{
						PORTB |=(1u<<Peripherals[loop_index].PIN);
					}
					else if(Peripherals[loop_index].resistor==EXTERNAL)
					{
						PORTB &=~(1u<<Peripherals[loop_index].PIN);
					}
					else
					{
						Peripherals[loop_index].is_configured=UNINITIALIZED;
						retval=NOK;
					}

				}
				else
				{
					Peripherals[loop_index].is_configured=UNINITIALIZED;
					retval=NOK;
				}
				break;
			case PORT_C:
				if(Peripherals[loop_index].direction==OUTPUT)
				{
					DDRC |=(1u<<Peripherals[loop_index].PIN);
					if(Peripherals[loop_index].intial_value==HIGH)
					{
						PORTC |=(1u<<Peripherals[loop_index].PIN);
					}
					else if(Peripherals[loop_index].intial_value==LOW)
					{
						PORTC &=~(1u<<Peripherals[loop_index].PIN);
					}
					else
					{
						Peripherals[loop_index].is_configured=UNINITIALIZED;
						retval=NOK;
					}

				}
				else if (Peripherals[loop_index].direction==INPUT)
				{
					DDRC &=~(1u<<Peripherals[loop_index].PIN);
					if(Peripherals[loop_index].resistor==PULLUP)
					{
						PORTC |=(1u<<Peripherals[loop_index].PIN);
					}
					else if(Peripherals[loop_index].resistor==EXTERNAL)
					{
						PORTC &=~(1u<<Peripherals[loop_index].PIN);
					}
					else
					{
						Peripherals[loop_index].is_configured=UNINITIALIZED;
						retval=NOK;
					}

				}
				else
				{
					Peripherals[loop_index].is_configured=UNINITIALIZED;
					retval=NOK;
				}
				break;
			case PORT_D:
				if(Peripherals[loop_index].direction==OUTPUT)
				{
					DDRD |=(1u<<Peripherals[loop_index].PIN);
					if(Peripherals[loop_index].intial_value==HIGH)
					{
						PORTD |=(1u<<Peripherals[loop_index].PIN);
					}
					else if(Peripherals[loop_index].intial_value==LOW)
					{
						PORTD &=~(1u<<Peripherals[loop_index].PIN);
					}
					else
					{
						Peripherals[loop_index].is_configured=UNINITIALIZED;
						retval=NOK;
					}

				}
				else if (Peripherals[loop_index].direction==INPUT)
				{
					DDRD &=~(1u<<Peripherals[loop_index].PIN);
					if(Peripherals[loop_index].resistor==PULLUP)
					{
						PORTD |=(1u<<Peripherals[loop_index].PIN);
					}
					else if(Peripherals[loop_index].resistor==EXTERNAL)
					{
						PORTD &=~(1u<<Peripherals[loop_index].PIN);
					}
					else
					{
						Peripherals[loop_index].is_configured=UNINITIALIZED;
						retval=NOK;
					}

				}
				else
				{
					Peripherals[loop_index].is_configured=UNINITIALIZED;
					retval=NOK;
				}
				break;
			default:
				Peripherals[loop_index].is_configured=UNINITIALIZED;
				retval=NOK;
			}
		}
	}
	else
	{
		for(loop_index=0;loop_index<num_of_pins;loop_index++)
		{
			Peripherals[loop_index].is_configured=UNINITIALIZED;
		}

		retval=NOK;
	}

	return retval;
}



status DIO_read(uint8 port,uint8 pin,uint8 peripheral_index,uint8* value)
{
	status retvalue=OK;

	if ((Peripherals[peripheral_index].PORT==port)&&(Peripherals[peripheral_index].PIN==pin))
	{
		if((Peripherals[peripheral_index].is_configured==INITIALIZED)&&(Peripherals[peripheral_index].direction==INPUT))
		{

			switch (port)
			{
			case PORT_A:*value=1u&(PINA>>pin);
			break;
			case PORT_B:*value=1u&(PINB>>pin);
			break;
			case PORT_C:*value=1u&(PINC>>pin);
			break;
			case PORT_D:*value=1u&(PIND>>pin);
			break;
			default : retvalue=NOK;
			}
		}
		else
		{
			retvalue=NOK;
		}
	}
	else
	{
		retvalue=NOK;
	}

	return retvalue;
}

status DIO_write(uint8 port,uint8 pin,uint8 peripheral_index,uint8 value)
{
	status retvalue=OK;
	if ((Peripherals[peripheral_index].PORT==port)&&(Peripherals[peripheral_index].PIN==pin))
	{
		if((Peripherals[peripheral_index].is_configured==INITIALIZED)&&(Peripherals[peripheral_index].direction==OUTPUT))
		{
			switch (port)
			{
			case PORT_A: if(value==HIGH)
			{
				PORTA|=(1u<<pin);
			}
			else if (value==LOW)
			{
				PORTA&=~(1u<<pin);
			}
			else
			{
				retvalue=NOK;
			}
			break;
			case PORT_B:if(value==HIGH)
			{
				PORTB|=(1u<<pin);
			}
			else if (value==LOW)
			{
				PORTB&=~(1u<<pin);
			}
			else
			{
				retvalue=NOK;
			}
			break;
			case PORT_C:if(value==HIGH)
			{
				PORTC|=(1u<<pin);
			}
			else if (value==LOW)
			{
				PORTC&=~(1u<<pin);
			}
			else
			{
				retvalue=NOK;
			}
			break;
			case PORT_D:if(value==HIGH)
			{
				PORTD|=(1u<<pin);
			}
			else if (value==LOW)
			{
				PORTD&=~(1u<<pin);
			}
			else
			{
				retvalue=NOK;
			}
			break;
			default : retvalue=NOK;
			}
		}
		else
		{
			retvalue=NOK;
		}

	}
	else
	{
		retvalue=NOK;
	}

	return retvalue;
}

