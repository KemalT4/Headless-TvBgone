# Headless TV-B-Gone

Open one folder at a time in Arduino IDE:

- EU-Tv-B-Gone/
- NA-Tv-B-Gone/
- LG-Tv-B-Gone/

Each folder is a separate sketch with its own IR code header.

Usage:
1. Open just one folder in Arduino IDE.
2. Select your ESP32 board and serial port.
3. Upload that sketch.
4. Keep the IR LED on GPIO 4 with a proper resistor and driver.
5. Watch the Serial Monitor at 115200.

Notes:
- EU and NA include the LG code set as part of their transmission loops.
- LG also remains available as a small standalone sketch.
- Add more regions by copying an existing folder.
