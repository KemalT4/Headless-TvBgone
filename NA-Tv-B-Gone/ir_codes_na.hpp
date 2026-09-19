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

constexpr uint16_t kNa000Times[] = {60, 60, 60, 2700, 120, 60, 240, 60};
constexpr uint8_t kNa000Codes[] = {0xE2, 0x20, 0x80, 0x78, 0x88, 0x20, 0x10};
constexpr IrCode kNa000Code = {38, 26, 2, 4, sizeof(kNa000Codes), kNa000Times, kNa000Codes};

constexpr uint16_t kNa001Times[] = {50, 100, 50, 200, 50, 800, 400, 400};
constexpr uint8_t kNa001Codes[] = {0xD5, 0x41, 0x11, 0x00, 0x14, 0x44, 0x6D, 0x54, 0x11, 0x10, 0x01, 0x44, 0x45};
constexpr IrCode kNa001Code = {57, 52, 2, 4, sizeof(kNa001Codes), kNa001Times, kNa001Codes};

// Add further North American/Asian entries here without changing the sketch.
constexpr const IrCode* kPowerCodes[] = {&kNa000Code, &kNa001Code};
constexpr uint8_t kPowerCodeCount = sizeof(kPowerCodes) / sizeof(kPowerCodes[0]);
