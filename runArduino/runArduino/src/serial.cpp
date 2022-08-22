#include <Arduino.h>
#include <stdio.h>
#include "serial.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <HardwareSerial.h>


void serial_init(void)
{
    Serial.begin(BAUD_RATE);
    Serial.println("Sandtable V1");
}


void print(const char *string, float value)
{
    Serial.print(string);
    Serial.println(value);
}

void serial_register_init(void)
{
    // Set baud rate
    uint16_t UBRR0_value = ((F_CPU / (4L * BAUD_RATE)) - 1) / 2;
    UCSR0A |= (1 << U2X0); // baud doubler on for high baud rates, i.e. 115200
    UBRR0H = UBRR0_value >> 8;
    UBRR0L = UBRR0_value;

    // enable rx and tx
    UCSR0B |= 1 << RXEN0;
    UCSR0B |= 1 << TXEN0;

    // enable interrupt on complete reception of a byte
    UCSR0B |= 1 << RXCIE0;

    // defaults to 8-bit, no parity, 1 stop bit
}
