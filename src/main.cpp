#include <Arduino.h>
#include "system.h"
void setup() {
  // Initialize the system core
  system_init(); 

}

void loop() {
  // Hand over control to our system loop
  system_loop();     

}