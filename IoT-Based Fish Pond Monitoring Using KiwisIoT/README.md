# IoT-Based Fish Pond Monitoring

## Project Overview
This project monitors fish pond water conditions using an ESP32 and three sensors: DS18B20 temperature sensor, pH sensor, and turbidity sensor. The collected readings are sent to the KiwisIoT platform for remote monitoring through an IoT dashboard.

## Hardware Components
- ESP32 Development Board
- DS18B20 Temperature Sensor
- pH Sensor Module
- Turbidity Sensor
- Jumper Wires
- Power Supply

## Software Requirements
- Arduino IDE
- ESP32 Board Package
- KiwisIoT Arduino Library
- OneWire Library
- DallasTemperature Library

## Circuit Connections

| Sensor | ESP32 Pin |
|---|---|
| DS18B20 Data | GPIO 4 |
| pH Sensor Analog Output | GPIO 34 |
| Turbidity Sensor Analog Output | GPIO 35 |

Connect the DS18B20 data line with an appropriate pull-up resistor.

## Working Principle
The ESP32 collects water temperature, pH sensor ADC readings, and turbidity sensor ADC readings every 3 seconds. The collected values are displayed in the Serial Monitor and transmitted to the KiwisIoT platform.

## KiwisIoT Dashboard

| Channel | Data |
|---|---|
| Channel 0 | Water Temperature (°C) |
| Channel 1 | pH Sensor ADC |
| Channel 2 | Turbidity Sensor ADC |

**Note:** The pH and turbidity values are raw ADC readings. Calibration and suitable conversion formulas are required to obtain actual pH and turbidity measurements.

## Configuration
Update the Wi-Fi credentials and KiwisIoT topic ID in the Arduino code:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";
```

Upload the code to the ESP32 and monitor the sensor readings through the KiwisIoT dashboard.

## Applications
- Fish pond water quality monitoring
- Aquaculture management
- Smart fish farming
- Remote water condition monitoring

## Project Blog
[Read the full project on Hackster.io](https://www.hackster.io/kirusokumar/iot-based-fish-pond-monitoring-39e731)

## Recommended Platform
[KiwisIoT – IoT Monitoring Platform](https://www.kiwisiot.in/)

**Arduino Library:** https://github.com/Kiwistron/KiwisIoT

**Example Projects:** https://github.com/Kiwistron/KiwisIoT-Projects/tree/main

---
**Author:** Kirusokumar