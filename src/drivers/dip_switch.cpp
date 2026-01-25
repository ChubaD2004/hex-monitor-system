#include "dip_switch.h"
#include <avr/io.h>

void dip_init() {

    // Clear DDR bits for PC0-PC3 (Input)
    DDRC &= ~((1 << PC0) | (1 << PC1) | (1 << PC2) | (1 << PC3));
    
    // Set PORT bits for PC0-PC3 (Pull-up)
    PORTC |= (1 << PC0) | (1 << PC1) | (1 << PC2) | (1 << PC3);
}

uint8_t dip_read() {
    return ~PINC & 0x0F; // Return the DIP switch value (0-15)
}