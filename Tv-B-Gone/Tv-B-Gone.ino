/*
  Headless-TvBgone
  ESP32 IR transmitter based on TV-B-Gone-style IR patterns.
  Adapted from public TV-B-Gone and IR transmission examples.
*/

#include <IRsend.h>
#include "ir_codes.hpp"

constexpr uint16_t kIrLedPin = 4;
IRsend irsend(kIrLedPin);

uint16_t rawData[300];
uint8_t bitsleft_r = 0;
uint8_t bits_r = 0;
uint8_t code_ptr = 0;
const IrCode* powerCode = nullptr;

uint8_t read_bits(uint8_t count) {
  uint8_t value = 0;
  for (uint8_t i = 0; i < count; ++i) {
    if (bitsleft_r == 0) {
      bits_r = powerCode->codes[code_ptr++];
      bitsleft_r = 8;
    }
    --bitsleft_r;
    value |= (((bits_r >> bitsleft_r) & 1) << (count - 1 - i));
  }
  return value;
}

void sendAllEUCodes() {
  for (uint8_t i = 0; i < num_EUcodes; ++i) {
    powerCode = EUpowerCodes[i];
    if (powerCode == nullptr) continue;

    code_ptr = 0;
    bitsleft_r = 0;

    for (uint8_t pair = 0; pair < powerCode->numpairs; ++pair) {
      const uint16_t index = static_cast<uint16_t>(read_bits(powerCode->bitcompression)) * 2;
      rawData[pair * 2] = powerCode->times[index] * 10;
      rawData[pair * 2 + 1] = powerCode->times[index + 1] * 10;
    }

    irsend.sendRaw(rawData, powerCode->numpairs * 2, powerCode->timer_val);

    Serial.print(F("Sent EU code "));
    Serial.print(i + 1);
    Serial.print('/');
    Serial.println(num_EUcodes);
    delay(5);
    yield();
  }
}

void sendLGDirect() {
  irsend.sendNEC(0x20DF10EF, 32);
  Serial.println(F("Sent LG power code 1"));
  delay(100);

  irsend.sendNEC(0x20DF23DC, 32);
  Serial.println(F("Sent LG power code 2"));
  delay(100);
}

void setup() {
  Serial.begin(115200);
  delay(500);
  irsend.begin();

  Serial.print(F("Headless-TvBgone ready: "));
  Serial.print(num_EUcodes);
  Serial.println(F(" EU codes plus direct LG codes."));
}

void loop() {
  sendLGDirect();
  sendAllEUCodes();
  Serial.println(F("Full EU cycle complete; restarting."));
  delay(2000);
}
