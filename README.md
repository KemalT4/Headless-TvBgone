# Headless TV-B-Gone

Open one folder at a time in Arduino IDE:

- EU-Tv-B-Gone/
- NA-Tv-B-Gone/
- LG-Tv-B-Gone/

Each folder is a separate sketch with its own IR code header.

Usage:
1. Open a .ino folder (the one with arduino ide photo)
2. Select your ESP32 board and serial port.
3. Upload.
4. Connect the IR led to Pin 4.
5. Whenever the esp32 is working it will scroll through all the tv closing codes.

Notes:
- EU and NA include the LG code set as part of their transmission loops.
 ## Make sure you have arduino IDE downloaded
