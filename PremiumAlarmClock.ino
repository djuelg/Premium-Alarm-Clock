#include <Arduino.h>
#include <assert.h>
#include "IRService.h"
#include "RTCService.h"

const uint32_t kBaudRate = 115200; // should not be lower

void setup() {
  #if defined(ESP8266)
    Serial.begin(kBaudRate, SERIAL_8N1, SERIAL_TX_ONLY);
  #else  // ESP8266
    Serial.begin(kBaudRate, SERIAL_8N1);
  #endif  // ESP8266
    while (!Serial) delay(50); // wait for serial port to connect

  IR_init();
  RTC_init();
}

void loop() {
  // put your main code here, to run repeatedly:
  RTC_read_time();
  RTC_read_temp();
  IR_read();
  delay(2000);
}
