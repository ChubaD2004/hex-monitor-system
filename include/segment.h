#ifndef SEGMENT_H
#define SEGMENT_H

#include <stdint.h>

void seg_init(void);  //setting an entire port (e.g. Port D) to OUTPUT

/**
 * Gets the corresponding numbers from 0 to 15 
 * and turns on the required segments on the display
 */
void seg_display_hex(uint8_t number);

#endif // SEGMENT_H