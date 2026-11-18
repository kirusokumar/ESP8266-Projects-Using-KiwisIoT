tegrationC/C++

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// WiFi Credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT Topic ID
const char* topic = "YOUR_TOPIC_ID";

// Temperature Sensor Pin
#define TEMP_PIN D2

// Temperature threshold
const float TEMP_LIMIT = 8.0;

// Sensor Configuration
OneWire oneWire(TEMP_PIN);
DallasTemperature sensors(&oneWire);

// KiwisIoT
KiwisIoT kiwisiot(ssid, pass, topic);

unsigned long previousMillis = 0;
const unsigned long interval = 3000;

void setup() {
  Serial.begin(115200);

  sensors.begin();
  kiwisiot.begin();

  Serial.println("Smart Logistics Monitoring Started");
}

void loop() {
  kiwisiot.run();

  if (millis() - previousMillis >= interval) {
    previousMillis = millis();

    sensors.requestTemperatures();

    float temperature =
      sensors.getTempCByIndex(0);

    Serial.println("\n--- LOGISTICS MONITOR ---");

    if (temperature != DEVICE_DISCONNECTED_C) {

      String status =
        (temperature > TEMP_LIMIT) ? "HIGH" : "NORMAL";

      Serial.print("Temperature: ");
      Serial.print(temperature);
      Serial.println(" °C");

      Serial.print("Temperature Status: ");
      Serial.println(status);

      kiwisiot.send("0", String(temperature, 2));
      kiwisiot.send("1", status);

    } else {
      Serial.println("Temperature Sensor Error");
    }
  }
}

