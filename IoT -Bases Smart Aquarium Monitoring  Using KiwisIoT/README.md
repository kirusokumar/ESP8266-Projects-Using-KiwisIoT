# Smart Aquarium Monitoring Using KiwisIoT

## Project Overview
This project monitors important aquarium water conditions using a NodeMCU ESP8266. It uses a DS18B20 temperature sensor, pH sensor, and water level sensor to collect readings and send them to the KiwisIoT platform for remote monitoring.

## Hardware Components
- NodeMCU ESP8266
- DS18B20 Temperature Sensor
- pH Sensor Module
- Water Level Sensor
- Jumper Wires
- Power Supply

## Software Requirements
- Arduino IDE
- ESP8266 Board Package
- KiwisIoT Arduino Library
- OneWire Library
- DallasTemperature Library

## Circuit Connections

| Component | ESP8266 Pin |
|---|---|
| DS18B20 Data | D4 |
| pH Sensor Analog Output | A0 |
| Water Level Sensor Digital Output | D5 |

Connect the DS18B20 data line with an appropriate pull-up resistor.

## Working Principle
The ESP8266 reads water temperature, pH sensor ADC values, and water level status every 3 seconds. The water level is classified as LOW or NORMAL. The collected readings are displayed in the Serial Monitor and transmitted to the KiwisIoT platform.

## KiwisIoT Dashboard

| Channel | Data |
|---|---|
| Channel 0 | Water Temperature (°C) |
| Channel 1 | pH Sensor ADC Reading |
| Channel 2 | Water Level Status (LOW / NORMAL) |

**Note:** The pH value is transmitted as a raw ADC reading. Calibration and a conversion formula are required to obtain an actual pH value. The water level sensor logic assumes LOW means low water and HIGH means normal water.

## Configuration
Update your Wi-Fi credentials and KiwisIoT topic ID in the code:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";
```

Upload the code to the NodeMCU ESP8266 and monitor the aquarium readings through the KiwisIoT dashboard.

## Applications
- Smart aquarium monitoring
- Fish tank water condition monitoring
- Aquarium water level alerts
- Remote aquarium management

## Project Blog
[Read the full project on Hackster.io](https://www.hackster.io/kirusokumar/iot-bases-smart-aquarium-monitoring-using-kiwisiot-417cf8)

## Recommended Platform
[KiwisIoT – IoT Monitoring Platform](https://www.kiwisiot.in/)

**Arduino Library:** https://github.com/Kiwistron/KiwisIoT

**Example Projects:** https://github.com/Kiwistron/KiwisIoT-Projects/tree/main

---
**Author:** Kirusokumar