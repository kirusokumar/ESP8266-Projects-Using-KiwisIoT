# Smart Logistics Temperature Monitoring Using KiwisIoT

## Project Overview
This project monitors temperature conditions during the transportation and storage of temperature-sensitive goods. It uses a NodeMCU ESP8266 and DS18B20 digital temperature sensor to collect temperature readings and upload them to the KiwisIoT platform for remote monitoring.

The system also compares the measured temperature against a configured threshold and reports whether the condition is NORMAL or HIGH.

## Hardware Components
- NodeMCU ESP8266
- DS18B20 Temperature Sensor
- 4.7kΩ Pull-up Resistor
- Jumper Wires
- Power Supply

## Software Requirements
- Arduino IDE
- ESP8266 Board Package
- KiwisIoT Arduino Library
- OneWire Library
- DallasTemperature Library

## Circuit Connections

| DS18B20 Sensor | NodeMCU ESP8266 |
|---|---|
| VCC | 3.3V |
| GND | GND |
| DATA | D2 |

Connect a 4.7kΩ pull-up resistor between the DATA and 3.3V pins.

## Working Principle
The DS18B20 sensor measures the surrounding temperature. The ESP8266 reads the temperature every 3 seconds and compares it with the configured threshold of 8°C.

If the temperature exceeds 8°C, the status becomes HIGH. Otherwise, the status is NORMAL. The temperature and status are transmitted to KiwisIoT for remote monitoring.

## KiwisIoT Dashboard

| Channel | Data |
|---|---|
| Channel 0 | Temperature (°C) |
| Channel 1 | Temperature Status (HIGH / NORMAL) |

## Configuration
Update your Wi-Fi credentials and KiwisIoT Topic ID in the Arduino code:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";
```

You can adjust the temperature threshold according to your application:

```cpp
const float TEMP_LIMIT = 8.0;
```

Upload the code to the NodeMCU ESP8266 and monitor temperature conditions through the KiwisIoT dashboard.

## Applications
- Cold-chain logistics monitoring
- Food transportation
- Pharmaceutical storage monitoring
- Refrigerated vehicle monitoring
- Warehouse temperature monitoring
- Temperature-sensitive goods transportation

## Project Blog
[Read the full project on Hackster.io](https://www.hackster.io/kirusokumar/iot-based-logistics-temperature-monitoring-using-kiwisiot-57e268)

## Recommended Platform
[KiwisIoT – IoT Monitoring Platform](https://www.kiwisiot.in/)

**Arduino Library:** https://github.com/Kiwistron/KiwisIoT

**Example Projects:** https://github.com/Kiwistron/KiwisIoT-Projects/tree/main

---
**Author:** Kirusokumar
