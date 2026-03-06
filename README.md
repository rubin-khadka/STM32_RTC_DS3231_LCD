# STM32 RTC DS3231 LCD Project

![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)
[![STM32](https://img.shields.io/badge/STM32-F103C8T6-blue)](https://www.st.com/en/microcontrollers-microprocessors/stm32f103c8.html)
[![CubeIDE](https://img.shields.io/badge/IDE-STM32CubeIDE-darkblue)](http://st.com/en/development-tools/stm32cubeide.html)

## Project Overview

This project demonstrates interfacing a **DS3231 Precision RTC Module** with an **STM32F103C8T6 microcontroller** (Blue Pill) to create a real-time clock and temperature monitoring system. The current time, date, and temperature are displayed on a **16x2 LCD with I2C backpack** in real-time.

## Video Demonstration

https://github.com/user-attachments/assets/5b047b2e-48a7-4b0d-94cc-8901fa1f2d6f

## Project Schematic

![schematic_diagram](https://github.com/user-attachments/assets/1e304c64-b8e8-41d6-bd60-c040e58c345d)

## Hardware Components

| Component | Quantity | Description |
|-----------|----------|-------------|
| **STM32F103C8T6** | 1 | "Blue Pill" development board with 72MHz Cortex-M3 |
| **DS3231 RTC Module** | 1 | Precision RTC with built-in temperature sensor (±3°C accuracy) |
| **LCD 16x2 with I2C** | 1 | Character display module with PCF8574 I2C backpack |

## Pin Configuration

| Peripheral | Pin | Connection | Notes |
|------------|-----|------------|-------|
| **DS3231 RTC** | PB8 | SCL | I2C1 clock (shared with LCD) |
| | PB9 | SDA | I2C1 data (shared with LCD) |
| | 5V | VCC | Power |
| | GND | GND | Common ground |
| **LCD 16x2 I2C** | PB8 | SCL | I2C1 clock (shared with DS3231) |
| | PB9 | SDA | I2C1 data (shared with DS3231) |
| | 5V | VCC | Power |
| | GND | GND | Common ground |

| Device | I2C Address (7-bit) | 8-bit Write | 8-bit Read |
|--------|---------------------|-------------|------------|
| **DS3231 RTC** | 0x68 | 0xD0 | 0xD1 |
| **LCD Module** | 0x27 | 0x4E | 0x4F |

🔗 [View Custom Written I2C Driver Source Code](https://github.com/rubin-khadka/STM32_RTC_DS3231_LCD/blob/main/Src/i2c1.c) <br>
🔗 [View LCD Driver Source Code](https://github.com/rubin-khadka/STM32_RTC_DS3231_LCD/blob/main/Src/lcd.c) <br>

## DS3231 RTC Driver

The DS3231 is a **precision Real-Time Clock (RTC)** with an integrated temperature-compensated crystal oscillator and **I2C interface** (shared with LCD at address 0x68).

The driver provides two ways to access RTC data:
1. **Time/Date Data**: Current time (hours, minutes, seconds) and date (day, month, year)
2. **Temperature Data**: Built-in temperature sensor reading (±3°C accuracy)

**Implementation:**
- **Burst read** of all 7 time registers in a single I2C transaction
- **BCD conversion** handles register format automatically
- **Data Flow:** I2C Read (0x00-0x06) → 7 bytes → Convert BCD → Update time structure
- **Oscillator monitoring** detects power failures via status register

### Output Values

| Measurement | Range | Resolution | Format |
|-------------|-------|------------|--------|
| **Time** | 00:00:00 - 23:59:59 | 1 second | HH:MM:SS |
| **Date** | 01/01/00 - 31/12/99 | 1 day | DD/MM/YY |
| **Temperature** | -40°C to +85°C | 0.25°C | XX.X°C |

🔗 [View DS3231 Driver Source Code](https://github.com/rubin-khadka/STM32_RTC_DS3231_LCD/blob/main/Src/ds3231.c)

> **Note**: LCD display shows **formatted time/date strings** and temperature in physical units. Raw BCD values are automatically converted using internal helper functions. The RTC maintains accurate time even when main power is off using a CR2032 backup battery.

## Getting Started

### Prerequisites

| Component | Details |
|-----------|---------|
| **MCU** | STM32F103C8T6 "Blue Pill" board |
| **RTC** | DS3231 Real Time Clock + Temperature Sensor |
| **Display** | 16x2 LCD with I2C backpack (PCF8574) |
| **Programmer** | ST-Link V2 (or USB to UART for serial bootloader) |
| **IDE** | STM32CubeIDE v1.13.0 or higher |

### Installation

1. Clone the repository
```bash
git clone https://github.com/rubin-khadka/STM32_RTC_DS3231_LCD.git
```
2. Open in STM32CubeIDE
    - `File` → `Import...`
    - `General` → `Existing Projects into Workspace` → `Next`
    - Select the project directory
    - Click `Finish`    

3. Verify Project Settings
    - `Project` → `Properties` → `C/C++ Build` → `Settings`
    - `MCU GCC Compiler` → `Preprocessor`
    - Ensure `STM32F103xB` is defined
    - `MCU GCC Compiler` → `Include paths` Add the following paths
        - "~\STM32Cube_FW_F1_V1.8.0\Drivers\CMSIS\Core\Include"
        - "~\STM32Cube_FW_F1_V1.8.0\Drivers\CMSIS\Device\ST\STM32F1xx\Include"

4. Build & Flash
    - Build: `Ctrl+B`
    - Debug: `F11`
    - Run: `F8` (Resume)

### Expected output
```
21:19:00  T:24.5C
06/03/2026
```

## Resources
- [STM32F103 Datasheet](https://www.st.com/resource/en/datasheet/stm32f103c8.pdf)
- [STM32F103 Reference Manual](https://www.st.com/resource/en/reference_manual/rm0008-stm32f101xx-stm32f102xx-stm32f103xx-stm32f105xx-and-stm32f107xx-advanced-armbased-32bit-mcus-stmicroelectronics.pdf)
- [PCF8574 I2C Backpack Datasheet](https://www.ti.com/lit/ds/symlink/pcf8574.pdf)
- [RTC DS3231 Datasheet](https://www.analog.com/media/en/technical-documentation/data-sheets/ds3231.pdf)

## Project Status
- **Status**: Complete
- **Version**: v1.0
- **Last Updated**: March 2026

## Contact
**Rubin Khadka Chhetri**  
📧 rubinkhadka84@gmail.com <br>
🐙 GitHub: https://github.com/rubin-khadka