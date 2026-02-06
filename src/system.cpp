#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>
#include "dip_switch.h"
#include "system.h"
#include "segment.h"
#include "uart.h"

// Global variable shared between ISR and main loop
// 'volatile' tells the compiler that this value can change unexpectedly
volatile uint8_t current_val = 0;

// Initialize all hardware subsystems
void system_init() {
    // 1. Basic hardware setup
    uart_init();                            // Initialize UART for debug output
    _delay_ms(100);                         // Wait for UART line to stabilize

    // Send a few newlines to clear the garbage from terminal
    uart_print("\n\n--- System Starting ---\n");

    dip_init();                             // Initialize DIP-switch pins as Inputs with Pull-up
    seg_init();                             // Initialization of adjustment of the 7-segment display

    // 2. Initial read BEFORE timer starts
    // This ensures the display shows the correct value immediately
    current_val = dip_read();
    seg_display_hex(current_val);

    // 3. Timer1 setup
    TCCR1A = 0;                             // Clear PWM settings
    TCCR1B = 0;                             // Clear Prescaler and Mode settings
    TCNT1  = 0;                             // Initialize counter value to 0

    OCR1A = 624;                            // Calculated number of Trigger Threshold

    TIMSK1 |= (1 << OCIE1A);                // Allowing the system to "interrupt" the main cycle
    TCCR1B = (1 << WGM12) | (1 << CS12);    // Prescaler - 1:256. Operation in CTC mode

    sei();                                  // Enable global interrupts
}

// Main system logic (executed repeatedly)
void system_loop(){
    if (current_val > 0) {                  // Check the shared value updated by the timer interrupt
        uart_print("Active!\n");            // Send status message to terminal

        _delay_ms(500);                     // Prevent UART flooding (poll every 500ms)
    }
    

}

// Timer1 Compare Match A Interrupt Service Routine
// This function runs automatically every 10ms
ISR(TIMER1_COMPA_vect) {
    static uint8_t active_digit = 0;            // Persistent variable to keep track of which digit to light up
    
    current_val = dip_read();                   // Read input (shared with main loop)
    
    if (active_digit == 0)
    {
        uint8_t tens = current_val / 10;        // Calculate TENS (e.g., 15 / 10 = 1)
        seg_display_digit(tens, 0);             // Display on the LEFT digit (index 0)
        active_digit = 1;                       // Switch to the right digit for next time
    } else if (active_digit == 1) {
        uint8_t units = current_val % 10;       // Calculate UNITS (e.g., 15 % 10 = 5)
        seg_display_digit(current_val, 1);      // Display on the RIGHT digit (index 1)
        active_digit = 0;                       // Switch to the left digit for next time
    }
    

    
}