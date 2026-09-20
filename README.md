# Headless TV-B-Gone

ESP32 IR transmitter firmware with separate North America/Asia and Europe sketches.

## Web flasher

This project includes a browser-based ESP32 flasher in the `web/` folder. It points to the latest compiled firmware binaries in the `latest` GitHub release, so the flash page automatically follows the newest firmware updates.

Open the deployed site in Chrome or Edge, connect an ESP32 with a USB data cable, choose NA/Asia or Europe, and click Install.

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
- Resistor or transistor driver for LED current
- USB data cable

Only use the transmitter with equipment you own or are authorized to control.

## Firmware build workflow

The GitHub Actions workflow in `.github/workflows/build-firmware.yml` compiles the latest NA and EU sketches and publishes merged `.bin` files to a rolling `latest` release for the web flasher.
