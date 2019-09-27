
#ifndef DIO_H_
#define DIO_H_

#include "Dio_confg.h"
#include "register_lib.h"

#define Max_num_of_pins 32

uint8 DIO_init(void);
uint8 DIO_read(uint8 port,uint8 pin,uint8 peripheral_index,uint8* value);
uint8 DIO_write(uint8 port,uint8 pin,uint8 peripheral_index,uint8 value);

#endif
