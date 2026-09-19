#pragma once

#include <Arduino.h>

// Common LG TV NEC power commands included by every regional sketch.
constexpr uint32_t kLgPowerCodes[] = {
  0x20DF10EF,
  0x20DF23DC,
};
constexpr uint8_t kLgCodeCount = sizeof(kLgPowerCodes) / sizeof(kLgPowerCodes[0]);
