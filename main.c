/*
 * main.c
 *
 *  Created on: Sep 20, 2019
 *      Author: Randa
 */

#include "Dio.h"
#include "TIMER.h"

/*DIO and Timer Driver tests*/

//uint8 toggle_value = 0;
/*
int main()
{

	DIO_init();
	//uint8 button_value;
	TIMER_init();
	//TIMER_PWM(100);
	while(1)
	{
		//Test Timer0
		if(TIMER0_Flag_tick == NUMBER_OF_OVERFLOWS)
		{
			DIO_write(PORT_A, PIN0, ERROR, toggle_value);
			toggle_value ^= 1;
			TIMER0_Flag_tick = 0;
		}

		//Test timer1
		if(TIMER1_Flag_tick == 1)
		{
			DIO_write(PORT_A, PIN0, ERROR, toggle_value);
			toggle_value ^= 1;
			TIMER1_Flag_tick = 0;
		}


		//Test DIO
		DIO_read(PORT_A, PIN2, BUTTON, &button_value);
		if(button_value == LOW)
		{
			DIO_write(PORT_A, PIN1, LED, HIGH);
		}
		else
		{
			DIO_write(PORT_A, PIN1, LED, LOW);
		}

	}
return 0;
}
*/
