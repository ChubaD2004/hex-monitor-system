#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdint.h>

void system_init(void); //Driver initialization

void system_loop(void); //The logic of "read -> processed -> output"

#endif // SYSTEM_H