# Headless TV-B-Gone

Open one folder at a time in Arduino IDE:

- EU-Tv-B-Gone/
- NA-Tv-B-Gone/
Each folder is a separate sketch with its own IR code header.

Usage:
1. Open a .ino folder (the one with arduino ide photo)
2. Select your ESP32 board and serial port.
3. Install the IRremoteESP8266 library!!!
4. Upload.

Arduino libraries:
- IRremoteESP8266 by crankyoldgit

Board:
- ESP32

IR LED pin:
- GPIO 4

 Whenever the esp32 is working it will scroll through all the tv closing codes.
