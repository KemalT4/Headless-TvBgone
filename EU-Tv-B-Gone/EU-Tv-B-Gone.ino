#include <Arduino.h>
#include <IRsend.h>
#include "ir_codes_eu.hpp"

namespace {
constexpr uint16_t kIrLedPin = 4;
constexpr uint32_t kSerialBaud = 115200;
constexpr uint16_t kInterCodeDelayMs = 5;
constexpr uint16_t kLgInterCodeDelayMs = 100;

IRsend irsend(kIrLedPin);
uint16_t rawData[300];

bool expandCode(const IrCode& code) {
  uint16_t codeByte = 0;
  uint8_t bitsLeft = 0;
  uint16_t codePtr = 0;

  for (uint8_t pair = 0; pair < code.numPairs; ++pair) {
    uint16_t index = 0;
    for (uint8_t bit = 0; bit < code.bitsPerIndex; ++bit) {
      if (bitsLeft == 0) {
        if (codePtr >= code.codeBytes) return false;
        codeByte = code.codes[codePtr++];
        bitsLeft = 8;
      }
      --bitsLeft;
      index = static_cast<uint16_t>((index << 1) | ((codeByte >> bitsLeft) & 1));
    }

    const uint16_t timingIndex = index * 2;
    if (timingIndex + 1 >= code.timeValues) return false;
    rawData[pair * 2] = code.times[timingIndex] * 10;
    rawData[pair * 2 + 1] = code.times[timingIndex + 1] * 10;
  }
  return true;
}

void sendLgPowerCodes() {
  for (uint8_t i = 0; i < kLgCodeCount; ++i) {
    irsend.sendNEC(kLgPowerCodes[i], 32);
    Serial.print(F("Sent LG power code "));
    Serial.print(i + 1);
    Serial.print('/');
    Serial.println(kLgCodeCount);
    delay(kLgInterCodeDelayMs);
    yield();
  }
}

void sendCode(uint8_t index) {
  const IrCode& code = *kPowerCodes[index];
  if (!expandCode(code)) {
    Serial.println(F("Invalid EU code data; transmission skipped."));
    return;
  }

  irsend.sendRaw(rawData, code.numPairs * 2, code.timerValue);
  Serial.print(F("Sent EU code "));
  Serial.print(index + 1);
  Serial.print('/');
  Serial.println(kPowerCodeCount);
}
}

void setup() {
  Serial.begin(kSerialBaud);
  delay(500);
  irsend.begin();
  Serial.print(F("EU transmitter ready: "));
  Serial.print(kPowerCodeCount);
  Serial.print(F(" EU codes plus "));
  Serial.print(kLgCodeCount);
  Serial.println(F(" LG codes"));
}

void loop() {
  sendLgPowerCodes();

  for (uint8_t index = 0; index < kPowerCodeCount; ++index) {
    sendCode(index);
    delay(kInterCodeDelayMs);
    yield();
  }
  Serial.println(F("EU cycle complete"));
  delay(2000);
}
