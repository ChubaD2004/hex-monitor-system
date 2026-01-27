#include "uart.h"
#include "dip_switch.h"
#include <util/delay.h>
#include "system.h"

// Initialize all hardware subsystems
void system_init() {
    uart_init();                        // Initialize UART for debug output
    dip_init();                         // Initialize DIP-switch pins as Inputs with Pull-up

    uart_print("System Booted...\n");   // Boot log (optional, confirms system reset)
}

// Main system logic (executed repeatedly)
void system_loop(){
    // 1. Read the current state of switches (0-15)
    uint8_t dip_value = dip_read();
    
    // 2. Check if any button is pressed
    if (dip_value > 0) {
        // Send debug message
        uart_print("Key Pressed!\n");
    }
    
    // 3. Simple delay to prevent UART flooding (10Hz polling rate)
    _delay_ms(100);
}