#include "Dio.h"

int main(void)
{
	status ret= DIO_init();
	uint8 button_value;

	if(ret==NOK)
	{
		DIO_write(PORT_A,PIN0,ERROR,HIGH);
	}

	while(1)
	{
		DIO_read(PORT_A,PIN2,BUTTON,&button_value);

		if(button_value==LOW)
		{
			DIO_write(PORT_A,PIN1,LED,HIGH);
		}
		else
		{
			DIO_write(PORT_A,PIN1,LED,LOW);
		}

	}
	return 0;
}
