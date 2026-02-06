#ifndef SEGMENT_H
#define SEGMENT_H

#include <stdint.h>

//setting an entire port (e.g. Port D) to OUTPUT
void seg_init(void);  

/**
 * Gets the corresponding numbers from 0 to 15 
 * and turns on the required segments on the display
 */
void seg_display_hex(uint8_t number);

// displays a number on a SPECIFIC digit (0 or 1)
void seg_display_digit(uint8_t number, uint8_t digit_idx);

#endif // SEGMENT_H