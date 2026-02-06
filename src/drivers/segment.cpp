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

void seg_init() {
    // Configure PORT D (Pins D2-D7) as Output
    // We use |= 0xFC (11111100) to set bits 2-7 to HIGH (Output)
    // while leaving bits 0-1 (UART) unchanged.
    DDRD |= 0xFC; 
    
    // Configure PORT B (Pins D8-D9) as Output
    // We use |= 0x03 (00000011) to set bits 0-1 to HIGH (Output).
    DDRB |= 0x07; 

}

void seg_display_digit(uint8_t number, uint8_t index) {
    uint8_t safe_index = number & 0x0F;                     // 1. Safety mask: ensure number is within 0-15 range
    uint8_t segments  = SEGMENT_MAP[safe_index];            // 2. Get the raw segment code (Bits: DP, G, F, E, D, C, B, A)


    PORTD = (PORTD & 0x03) | (segments << 2);               // PORT D OPERATION (Segments A to F) 


    PORTB |= 0x06;                                          // 0x06 = 00000110 (PB1, PB2 set to 1)

    // We take bit 6 from 'segments' and put it into bit 0 of PORTB
    if (segments & (1 << 6)) {
        PORTB |= (1 << PB0);                                // Turn G on
    } else {
        PORTB &= ~(1 << PB0);                               // Turn G off
    }

    // Turn ON the selected digit (Set pin to LOW)
    if (index == 0)
    {
        PORTB &= ~(1 << PB1);                               // Turn ON Digit 0 (Left)
    } else if (index == 1)
    {
        PORTB &= ~(1 << PB2);                               // Turn ON Digit 1 (Right)
    }
    
    
}

void seg_display_hex(uint8_t number){
    uint8_t safe_index = number & 0x0F;                     // 1. Safety mask: ensure number is within 0-15 range

    uint8_t segments  = SEGMENT_MAP[safe_index];            // 2. Get the raw segment code (Bits: DP, G, F, E, D, C, B, A)


    PORTD = (PORTD & 0x03) | (segments << 2);               // PORT D OPERATION (Segments A to F) 

    PORTB = (PORTB & 0x06) | (segments >> 6);               // PORT B OPERATION (Segments G and DP) 
}

