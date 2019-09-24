
#ifndef DIO_H_
#define DIO_H_

#include "Dio_confg.h"
#include "register_lib.h"

typedef enum {NOK,OK}status;

#define Max_num_of_pins 32

status DIO_init(void);
status DIO_read(uint8 port,uint8 pin,uint8 peripheral_index,uint8* value);
status DIO_write(uint8 port,uint8 pin,uint8 peripheral_index,uint8 value);

#endif
