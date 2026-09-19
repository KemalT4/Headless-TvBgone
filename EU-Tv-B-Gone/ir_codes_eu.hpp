#pragma once

#include <Arduino.h>

struct IrCode {
  uint16_t timerValue;
  uint8_t numPairs;
  uint8_t bitsPerIndex;
  uint8_t timeValues;
  uint16_t codeBytes;
  const uint16_t* times;
  const uint8_t* codes;
};

constexpr uint16_t kEu000Times[] = {
  43, 47, 43, 91, 43, 8324, 88, 47,
  133, 133, 264, 90, 264, 91,
};
constexpr uint8_t kEu000Codes[] = {
  0xA4, 0x08, 0x00, 0x00, 0x00, 0x00, 0x64, 0x2C,
  0x40, 0x80, 0x00, 0x00, 0x00, 0x06, 0x41,
};

constexpr IrCode kEu000Code = {
  35, 40, 3, 7, sizeof(kEu000Codes), kEu000Times, kEu000Codes
};

// Add further EU entries here without changing EU-Tv-B-Gone.ino.
constexpr const IrCode* kPowerCodes[] = {&kEu000Code};
constexpr uint8_t kPowerCodeCount = sizeof(kPowerCodes) / sizeof(kPowerCodes[0]);
