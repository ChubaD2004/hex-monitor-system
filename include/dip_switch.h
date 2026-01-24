#ifndef DIP_SWITCH_H
#define DIP_SWITCH_H

#include <stdint.h>

/**
* @brief Initialize ports for DIP switch
* On individual pins as INPUT and enable internal PULL-UP resistor.
*/
void dip_init(void);

/**
* @brief Read current value
*
* @return uint8_t Number from 0 to 15 (0x00 - 0x0F).
* The function itself takes care of the logic inversion (pressed = 1)
* and masking of unnecessary bits.
*/
uint8_t dip_read(void);

#endif // DIP_SWITCH_H