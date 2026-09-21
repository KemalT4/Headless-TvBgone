# Headless TV-B-Gone

ESP32 IR transmitter firmware with separate North America/Asia and Europe sketches.

## Web flasher

Flash from Chrome or Edge at https://keml4.github.io/Headless-TvBgone/.

Pick NA/Asia or Europe. Firmware `.bin` files are hosted same-origin on GitHub Pages (see `web/`). Manual files are also in the rolling `latest` release.

## Flash with Arduino IDE

1. Install the ESP32 board package.
2. Install the **IRremoteESP8266** library by `crankyoldgit`.
3. Open one sketch at a time:
   - `NA-Tv-B-Gone/NA-Tv-B-Gone.ino`
   - `EU-Tv-B-Gone/EU-Tv-B-Gone.ino`
4. Select **ESP32 Dev Module** and your serial port.
5. Click Upload.

## Hardware

- ESP32 Dev Module
- IR LED on GPIO 4

