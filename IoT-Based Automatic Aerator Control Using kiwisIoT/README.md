# IoT-Based Automatic Aerator Control Using KiwisIoT

## Project Overview
This project automates aerator control in aquaculture systems using a NodeMCU ESP8266, dissolved oxygen (DO) sensor, and relay module. It monitors dissolved oxygen sensor readings and automatically switches the aerator ON or OFF based on configured thresholds. Sensor readings and aerator status are sent to the KiwisIoT platform for remote monitoring.

## Hardware Components
- NodeMCU ESP8266
- Dissolved Oxygen (DO) Sensor
- Relay Module
- Water Aerator
- Jumper Wires
- Power Supply

## Software Requirements
- Arduino IDE
- ESP8266 Board Package
- KiwisIoT Arduino Library

## Circuit Connections

| Component | ESP8266 Pin |
|---|---|
| DO Sensor Analog Output | A0 |
| Relay Module Input | D5 |
| Sensor VCC | Suitable power supply |
| Sensor GND | GND |

Connect the aerator to the relay's appropriately rated output terminals.

## Working Principle
The ESP8266 reads the dissolved oxygen sensor's analog value every 3 seconds. When the reading reaches or falls below the low threshold (400), the relay switches the aerator ON. When the reading reaches or exceeds the high threshold (500), the aerator switches OFF.

The two thresholds create a control range that helps prevent rapid relay switching. The sensor reading and aerator status are displayed in the Serial Monitor and transmitted to KiwisIoT.

## Automatic Control Thresholds

| Condition | Aerator Status |
|---|---|
| ADC ≤ 400 | ON |
| ADC ≥ 500 | OFF |
| ADC between 400 and 500 | Previous state maintained |

## KiwisIoT Dashboard

| Channel | Data |
|---|---|
| Channel 0 | DO Sensor ADC Reading |
| Channel 1 | Aerator Status (ON / OFF) |

## Configuration
Update your Wi-Fi credentials and KiwisIoT Topic ID:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";
```

Adjust the thresholds based on your calibrated DO sensor:

```cpp
const int DO_LOW_THRESHOLD = 400;
const int DO_HIGH_THRESHOLD = 500;
```

Upload the code to the NodeMCU ESP8266 and monitor the aerator status through the KiwisIoT dashboard.

**Note:** The current code sends raw ADC readings, not dissolved oxygen measurements in mg/L. Calibrate the sensor and determine suitable thresholds before using automatic control. Check relay compatibility and use a properly rated, isolated switching arrangement for the aerator, especially if it operates on mains voltage.

## Applications
- Smart aquaculture systems
- Fish pond oxygen management
- Automatic aerator control
- Remote aquaculture monitoring
- IoT-based water management

## Project Blog
[Read the full project on Hackster.io](https://www.hackster.io/kirusokumar/iot-based-automatic-aerator-control-using-kiwisiot-330d66)

## Recommended Platform
[KiwisIoT – IoT Monitoring Platform](https://www.kiwisiot.in/)

**Arduino Library:** https://github.com/Kiwistron/KiwisIoT

**Example Projects:** https://github.com/Kiwistron/KiwisIoT-Projects/tree/main

---
**Author:** Kirusokumar