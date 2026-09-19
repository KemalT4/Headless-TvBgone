# Headless-TvBgone

ESP32 IR transmitter TV-B-Gone project for sending power-off codes to consumer electronics.

This project is designed for ESP32 boards supported by the Arduino-ESP32 core. Every ESP32 board supported by the Arduino-ESP32 core is compatible as long as it has a valid GPIO connected to an IR LED driver circuit.

## Features
- Sends a large set of EU power-off IR codes
- Includes direct LG power-pulse commands for quicker response
- Runs on ESP32 Arduino boards
- Easy to modify for different GPIO pins and timing

## Hardware wiring
- Use a GPIO pin such as GPIO 4 as the IR output pin by default
- Connect the IR LED through a transistor or MOSFET driver stage
- Add a current-limiting resistor and proper flyback protection as needed
- Keep wiring short and use a proper IR LED driver for reliable output

## Required setup
1. Install the Arduino-ESP32 core in Arduino IDE
2. Select your ESP32 board from Tools > Board
3. Open this project in Arduino IDE
4. Build and upload to the ESP32
5. Connect the IR output circuit to the configured GPIO

## Default pin
The sketch uses GPIO 4 by default:

```cpp
constexpr uint16_t kIrLedPin = 4;
```

## Notes
- Not every GPIO is ideal for IR output on all ESP32 modules, so verify your board pin map
- The code is built around the Arduino-ESP32 `IRsend` class
- A dedicated transistor driver is recommended for stronger IR output

## License
This project is provided under the MIT license.
