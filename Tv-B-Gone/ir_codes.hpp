#pragma once

#include <Arduino.h>

#define NA 0
#define EU 1 // set by a LOW on REGIONSWITCH pin

// Lets us calculate the size of the NA/EU databases
#define NUM_ELEM(x) (sizeof (x) / sizeof (*(x)))

// set define to 0 to turn off debug output
#define DEBUG 0
#define DEBUGP(x) if (DEBUG == 1) { x ; }

// Shortcut to insert single, non-optimized-out nop
#define NOP __asm__ __volatile__ ("nop")

// Not used any more on esp8266, so don't bother
// Tweak this if neccessary to change timing
// -for 8MHz Arduinos, a good starting value is 11
// -for 16MHz Arduinos, a good starting value is 25
#define DELAY_CNT 25

// Makes the codes more readable. the OCRA is actually
// programmed in terms of 'periods' not 'freqs' - that
// is, the inverse!
#define freq_to_timerval(x) (x / 1000)

struct IrCode {
  uint8_t timer_val;
  uint8_t numpairs;
  uint8_t bitcompression;
  uint16_t const *times;
  uint8_t const *codes;
};

const uint16_t code_na000Times[] = {
  60, 60,
  60, 2700,
  120, 60,
  240, 60,
};
const uint8_t code_na000Codes[] = {
  0xE2,
  0x20,
  0x80,
  0x78,
  0x88,
  0x20,
  0x10,
};
const struct IrCode code_na000Code = {
  freq_to_timerval(38400),
  26,
  2,
  code_na000Times,
  code_na000Codes
};

const uint16_t code_na001Times[] = {
  50, 100,
  50, 200,
  50, 800,
  400, 400,
};
const uint8_t code_na001Codes[] = {
  0xD5,
  0x41,
  0x11,
  0x00,
  0x14,
  0x44,
  0x6D,
  0x54,
  0x11,
  0x10,
  0x01,
  0x44,
  0x45,
};
const struct IrCode code_na001Code = {
  freq_to_timerval(57143),
  52,
  2,
  code_na001Times,
  code_na001Codes
};

const uint16_t code_na002Times[] = {
  42, 46,
  42, 133,
  42, 7519,
  347, 176,
  347, 177,
};
const uint8_t code_na002Codes[] = {
  0x60, 0x80, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x20,
  0x00, 0x00, 0x04, 0x12, 0x48, 0x04, 0x12, 0x48, 0x2A, 0x02,
  0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x80, 0x00,
  0x00, 0x10, 0x49, 0x20, 0x10, 0x49, 0x20, 0x80,
};
const struct IrCode code_na002Code = {
  freq_to_timerval(37037), 100, 3, code_na002Times, code_na002Codes
};

const uint16_t code_eu000Times[] = {
  43, 47, 43, 91, 43, 8324, 88, 47, 133, 133, 264, 90, 264, 91,
};
const uint8_t code_eu000Codes[] = {
  0xA4, 0x08, 0x00, 0x00, 0x00, 0x00, 0x64, 0x2C, 0x40, 0x80,
  0x00, 0x00, 0x00, 0x06, 0x41,
};
const struct IrCode code_eu000Code = {
  freq_to_timerval(35714), 40, 3, code_eu000Times, code_eu000Codes
};

const IrCode* const NApowerCodes[] = {
  &code_na000Code, &code_na001Code, &code_na002Code,
};
const IrCode* const EUpowerCodes[] = {
  &code_eu000Code,
};

uint8_t num_NAcodes = NUM_ELEM(NApowerCodes);
uint8_t num_EUcodes = NUM_ELEM(EUpowerCodes);
