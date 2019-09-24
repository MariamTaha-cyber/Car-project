
#ifndef REGISTER_LIB_H_
#define REGISTER_LIB_H_

#include "std_types.h"


#define DDRA   (*(volatile uint8* const)0x003A)
#define PORTA  (*(volatile uint8* const)0x003B)
#define PINA   (*(volatile uint8* const)0x0039)


#define DDRB   (*(volatile uint8* const)0x0037)
#define PORTB  (*(volatile uint8* const)0x0038)
#define PINB   (*(volatile uint8* const)0x0036)

#define DDRC   (*(volatile uint8* const)0x0034)
#define PORTC  (*(volatile uint8* const)0x0035)
#define PINC   (*(volatile uint8* const)0x0033)

#define DDRD   (*(volatile uint8* const)0x0031)
#define PORTD  (*(volatile uint8* const)0x0032)
#define PIND   (*(volatile uint8* const)0x0030)


#endif
