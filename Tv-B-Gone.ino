#include <IRsend.h>
#include "ir_codes.hpp"   // downloaded from the repo, same folder as this .ino

const uint16_t kIrLedPin = 4;
IRsend irsend(kIrLedPin);

uint16_t rawData[300];
uint8_t bitsleft_r = 0;
uint8_t bits_r = 0;
uint8_t code_ptr;
volatile const IrCode* powerCode;

uint8_t read_bits(uint8_t count) {
  uint8_t tmp = 0;
  for (uint8_t i = 0; i < count; i++) {
    if (bitsleft_r == 0) {
      bits_r = powerCode->codes[code_ptr++];
      bitsleft_r = 8;
    }
    bitsleft_r--;
    tmp |= (((bits_r >> bitsleft_r) & 1) << (count - 1 - i));
  }
  return tmp;
}

void sendAllEUCodes() {
  for (int i = 0; i < num_EUcodes; i++) {
    powerCode = EUpowerCodes[i];

    const uint8_t freq = powerCode->timer_val;
    const uint8_t numpairs = powerCode->numpairs;
    const uint8_t bitcompression = powerCode->bitcompression;
    code_ptr = 0;
    bitsleft_r = 0;

    for (uint8_t k = 0; k < numpairs; k++) {
      uint16_t ti = (read_bits(bitcompression)) * 2;
      rawData[k * 2]     = powerCode->times[ti] * 10;
      rawData[(k * 2) + 1] = powerCode->times[ti + 1] * 10;
    }

    irsend.sendRaw(rawData, numpairs * 2, freq);

    Serial.print("Sent EU code ");
    Serial.print(i + 1);
    Serial.print("/");
    Serial.println(num_EUcodes);

    delay(5);
  }
}

// Dedicated LG power codes (NEC protocol) - fired first, before the full EU sweep,
// so LG sets get hit immediately rather than waiting on their position in the big list
void sendLGDirect() {
  irsend.sendNEC(0x20DF10EF, 32);
  Serial.println("Sent LG direct 1");
  delay(100);
  irsend.sendNEC(0x20DF23DC, 32);
  Serial.println("Sent LG direct 2");
  delay(100);
}

void setup() {
  irsend.begin();
  Serial.begin(115200);
  delay(1000);
  Serial.print("EU TV-B-Gone loaded — ");
  Serial.print(num_EUcodes);
  Serial.println(" codes, plus dedicated LG.");
}

void loop() {
  sendLGDirect();
  sendAllEUCodes();
  Serial.println("--- Full EU cycle complete, restarting ---");
  delay(2000);
}