/*
 * seven_segment.h
 *
 *  Created on: 27 Sep 2019
 *      Author: Mariam Taha
 */

#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#include "Timers.h"
#include <util/delay.h>

extern uint8 seconds_count_increment;

#define segment_Data_PORT_output PORTC
#define segment_Data_PORT_direction DDRC

#define Data_PIN1 PC0
#define Data_PIN2 PC1
#define Data_PIN3 PC2
#define Data_PIN4 PC3

#define segment_Enable_PORT_output PORTA
#define segment_Enable_PORT_direction DDRA

#define segment1_enable PA0
#define segment2_enable PA1

void seven_segment_init(void);
void seven_segment_increment(void);
void seven_segment_decrement(void);


#endif /* SEVEN_SEGMENT_H_ */
