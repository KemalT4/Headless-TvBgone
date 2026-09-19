# Headless-TvBgone

ESP32 IR transmitter project for sending TV power-off codes.

This project works with most ESP32 boards , as long as the board has a valid GPIO connected to the IR LED.

## Features
- Sends IR power-off codes (Tested in EU tvs only)
- Most ESP32 and IR compatible
- Easy to modify for different GPIO pins

## Wiring
- Use GPIO 4 by default
- Connect the IR LED to the Esp32

## Setup
1. Install Arduino Ide
2. Download the zip of this repo
3.  Select your ESP32 board
3. Upload it 

## Default pin
```cpp
constexpr uint16_t kIrLedPin = 4;
