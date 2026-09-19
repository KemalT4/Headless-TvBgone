# Headless-TvBgone

ESP32 IR transmitter project organized as separate Arduino IDE sketches. Each folder is a self-contained firmware target with its own `.ino` file and IR-code header.

## Choose a firmware

Open **one folder at a time** in Arduino IDE and upload that sketch:

```text
Arduino/
├── EU-Tv-B-Gone/
│   ├── EU-Tv-B-Gone.ino
│   └── ir_codes_eu.hpp
├── NA-Tv-B-Gone/
│   ├── NA-Tv-B-Gone.ino
│   └── ir_codes_na.hpp
└── LG-Tv-B-Gone/
    ├── LG-Tv-B-Gone.ino
    └── ir_codes_lg.hpp
```

| Folder | Firmware | Code database |
|---|---|---|
| `EU-Tv-B-Gone` | European-region transmitter | `ir_codes_eu.hpp` |
| `NA-Tv-B-Gone` | North America/Asia transmitter | `ir_codes_na.hpp` |
| `LG-Tv-B-Gone` | Small LG-only test transmitter | `ir_codes_lg.hpp` |

This keeps each Arduino sketch small and prevents unrelated regional code databases from being compiled into the firmware.

## Setup

1. Install Arduino IDE and the ESP32 board package.
2. Install the `IRremoteESP8266` library.
3. Open one of the folders above. Do not open the repository root as a sketch.
4. Select your ESP32 board and the correct serial port.
5. Connect the IR LED to GPIO 4, with an appropriate resistor and driver circuit.
6. Upload the selected `.ino` file.

The selected firmware starts transmitting its own database automatically. Use the Serial Monitor at **115200 baud** to see progress.

## Adding more regions

To add another regional target, copy an existing region folder:

```text
AU-Tv-B-Gone/
├── AU-Tv-B-Gone.ino
└── ir_codes_au.hpp
```

Then change the include in the sketch to `ir_codes_au.hpp` and place only that region's `IrCode` entries in the header. The sketch and header in each folder intentionally use the same small interface:

```cpp
extern const IrCode* const kPowerCodes[];
extern const uint8_t kPowerCodeCount;
```

## Attribution and licensing

The original project is MIT licensed. Imported IR databases may have their own licenses; keep attribution and the applicable license file beside the database that uses it. Do not assume that adding an external code database changes its license to MIT.
