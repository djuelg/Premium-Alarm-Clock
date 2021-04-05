#include <Arduino.h>
#include <assert.h>
#include "IRService.h"

void setup() {
  // put your setup code here, to run once:
  IR_init();
}

void loop() {
  // put your main code here, to run repeatedly:
  IR_read();
}
