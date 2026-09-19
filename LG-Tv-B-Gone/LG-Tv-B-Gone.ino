#include <Arduino.h>
#include <IRsend.h>
#include "ir_codes_lg.hpp"

constexpr uint16_t kIrLedPin = 4;
IRsend irsend(kIrLedPin);

void setup() {
  Serial.begin(115200);
  delay(500);
  irsend.begin();
  Serial.println(F("LG transmitter ready"));
}

void loop() {
  for (uint8_t i = 0; i < kLgCodeCount; ++i) {
    irsend.sendNEC(kLgPowerCodes[i], 32);
    Serial.print(F("Sent LG code "));
    Serial.println(i + 1);
    delay(100);
    yield();
  }
  delay(2000);
}
