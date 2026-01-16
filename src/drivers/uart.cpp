#include "uart.h"
#include <avr/io.h>

void uart_init() {
    unsigned int ubrr_value = 103;
    UBRR0H = (ubrr_value >> 8);
    UBRR0L = ubrr_value;

    UCSR0B |= (1 << TXEN0) | (1 << RXEN0);

    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_send_byte(uint8_t data) {
    while (!(UCSR0A & (1 << UDRE0)));
    
    UDR0 = data;
}

void uart_print(const char* str) {
    while (*str) {
        uart_send_byte(*str);
        str++;
    }
}