
#ifndef DIO_CONFG_H_
#define DIO_CONFG_H_

#include "std_types.h"

typedef enum {MotorOut1,MotorOut2,num_of_pins}PINS_t;

typedef struct
{
	uint8 PORT;
	uint8 PIN;
	uint8 direction;
	uint8 resistor;
	uint8 intial_value;
	uint8 is_configured;
}DIO_confg_t;

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define HIGH 1
#define LOW 0

#define NOK 0
#define OK 1

#define PULLUP 1
#define EXTERNAL 0

#define OUTPUT 1
#define INPUT 0

#define INITIALIZED 1
#define UNINITIALIZED 0

#define NA 0xff

extern DIO_confg_t Peripherals[num_of_pins];

#endif
