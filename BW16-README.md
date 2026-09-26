# BW16 support

The repository now includes sketches for the Realtek RTL8720DN BW16 board:

- `BW16-NA-Tv-B-Gone/BW16-NA-Tv-B-Gone.ino`
- `BW16-EU-Tv-B-Gone/BW16-EU-Tv-B-Gone.ino`

## Hardware

- BW16 (RTL8720DN)
- IR LED on **GPIO 12** through an appropriate current-limiting/transistor driver
- Common ground between the BW16 and the driver circuit

GPIO 12 is a default and can be changed in `BW16-NA-Tv-B-Gone/bw16_transmitter.hpp`.

## Arduino IDE

1. Add the AmebaD package URL to Additional Boards Manager URLs:
   `https://github.com/ambiot/ambd_arduino/raw/master/Arduino_package/package_realtek.com_amebad_index.json`
2. Install **AmebaD Boards** and select **BW16**.
3. Install **Arduino-IRremote** (the portable `IRremote.hpp` library). The existing ESP32 sketches continue to use `IRremoteESP8266`; BW16 uses Arduino-IRremote because `IRremoteESP8266` does not support RTL8720DN.
4. Open either BW16 sketch and upload it.

The BW16 sketches use the same compressed regional timing tables as the ESP32 sketches and transmit them with Arduino-IRremote's portable raw sender. The browser installer is intentionally not used for BW16: `esp-web-tools` supports Espressif ESP chips, not Realtek AmebaD devices.
