# Headless-TvBgone

ESP32 IR transmitter project for sending TV power-off codes.

This project works with ESP32 boards supported by the Arduino-ESP32 core, as long as the board has a valid GPIO connected to an IR LED driver.

## Features
- Sends IR power-off codes
- ESP32 compatible
- Easy to modify for different GPIO pins

## Wiring
- Use GPIO 4 by default
- Connect the IR LED to the Esp32

## Setup
1. Install Arduino Ide
2. Select your ESP32 board
3. Upload the sketch
4. Connect the IR output circuit

## Default pin
```cpp
constexpr uint16_t kIrLedPin = 4;
