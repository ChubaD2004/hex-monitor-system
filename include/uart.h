#ifndef UART_H
#define UART_H

#include <stdint.h> 

void uart_init();

void uart_send_byte(uint8_t data);

void uart_print(const char* str);

#endif