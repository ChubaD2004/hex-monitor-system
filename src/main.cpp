#include <Arduino.h>
#include "../include/uart.h"

void setup() {
  uart_init();
  uart_print("System Booted...\n");
}

void loop() {
  
}

