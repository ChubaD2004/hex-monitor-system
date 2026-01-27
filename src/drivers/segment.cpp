#include "segment.h"
#include <avr/io.h>

// Lookup table for 7-segment display (Common Cathode)
// Index: 0-15 -> Value: Segments mapping (gfedcba)
// 0=0x3F, 1=0x06, 2=0x5B, 3=0x4F, 
// 4=0x66, 5=0x6D, 6=0x7D, 7=0x07,
// 8=0x7F, 9=0x6F, A=0x77, B=0x7C, 
// C=0x39, D=0x5E, E=0x79, F=0x71
static const uint8_t SEGMENT_MAP[16] = {
    0x3F, 0x06, 0x5B, 0x4F, 
    0x66, 0x6D, 0x7D, 0x07, 
    0x7F, 0x6F, 0x77, 0x7C, 
    0x39, 0x5E, 0x79, 0x71
};

void seg_init(){
    // Set all pins of PORT D to OUTPUT
    // Write 0xFF (11111111) to DDRD
    DDRD = 0xFF; 
}

void seg_display_hex(uint8_t number){
    // Safety mask: ensure number is between 0-15
    uint8_t safe_index = number & 0x0F;

    // Write the segment code to the port
    PORTD = SEGMENT_MAP[safe_index];
}

