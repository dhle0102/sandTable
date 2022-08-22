#ifndef SERIAL_H
#define SERIAL_H

#include <SoftwareSerial.h>

#define TxSerial 10 
#define RxSerial 9
#define BAUD_RATE 115200

void serial_init(void);
void print(const char *string, float value);
void serial_register_init(void);
#endif