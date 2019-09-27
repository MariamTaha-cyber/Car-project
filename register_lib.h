/*
 * register_lib.h
 *
 *  Created on: Sep 20, 2019
 *      Author: Randa
 */

#ifndef REGISTER_LIB_H_
#define REGISTER_LIB_H_
#include "std_types.h"

//GPIO Registers

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

//GPIO port A pins

#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5
#define PA6 6
#define PA7 7

//GPIO port B pins

#define PB0 0
#define PB1 1
#define PB2 2
#define PB3 3
#define PB4 4
#define PB5 5
#define PB6 6
#define PB7 7

//GPIO port C pins

#define PC0 0
#define PC1 1
#define PC2 2
#define PC3 3
#define PC4 4
#define PC5 5
#define PC6 6
#define PC7 7

//GPIO port D pins

#define PD0 0
#define PD1 1
#define PD2 2
#define PD3 3
#define PD4 4
#define PD5 5
#define PD6 6
#define PD7 7

//Timer0 Registers

#define TCCR0  (*(volatile uint8* const)0x0053)
#define TCNT0  (*(volatile uint8* const)0x0052)
#define OCR0   (*(volatile uint8* const)0x005C)
#define TIMSK  (*(volatile uint8* const)0x0059)
#define TIFR   (*(volatile uint8* const)0x0058)

//Timer0 control register Pins (TCCR0)

#define CS00 0
#define CS01 1
#define CS02 2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0 7

//Timer1 Registers

//Timer2 Registers
#define TCCR2 (*(volatile uint8 * const)0x0045)
#define TCNT2 (*(volatile uint8 * const)0x0044)
#define OCR2 (*(volatile uint8 * const)0x0043)
#define ASSR (*(volatile uint8 * const)0x0042)

//Global interrupt pin

#define SREG  (*(volatile uint8* const)0x005F)
#define I_bit 7

//Timers interrupt mask register Pins (TIMSK)

#define TOIE0 0
#define OCIE0 1
#define TOIE1 2
#define OCIE1B 3
#define OCIE1A 4
#define TICIE1 5
#define TOIE2 6
#define OCIE2 7

//Timers interrupt flag register Pins (TIFR)

#define TOV0 0
#define OCF0 1
#define TOV1 2
#define OCF1B 3
#define OCF1A 4
#define ICF1 5
#define TOV2 6
#define OCF2 7


#define TCCR1A (*(volatile uint8 * const)0x004F)
#define TCCR1B (*(volatile uint8 * const)0x004E)
#define TCNT1H (*(volatile uint8 * const)0x004D)
#define TCNT1L (*(volatile uint8 * const)0x004C)
#define OCR1AH (*(volatile uint8 * const)0x004B)
#define OCR1AL (*(volatile uint8 * const)0x004A)
#define OCR1BH (*(volatile uint8 * const)0x0049)
#define OCR1BL (*(volatile uint8 * const)0x0048)
#define ICR1H (*(volatile uint8 * const)0x0047)
#define ICR1L (*(volatile uint8 * const)0x0046)



#endif /* REGISTER_LIB_H_ */
