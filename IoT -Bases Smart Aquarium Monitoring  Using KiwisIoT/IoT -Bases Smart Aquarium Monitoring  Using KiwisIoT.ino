#include <ESP8266WiFi.h>
#include <KiwisIoT.h>
#include <OneWire.h>
#include <DallasTemperature.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";

#define TEMP_PIN D4
#define PH_PIN A0
#define WATER_LEVEL_PIN D5

OneWire oneWire(TEMP_PIN);
DallasTemperature sensors(&oneWire);

KiwisIoT kiwisiot(ssid, pass, topic);

unsigned long previousMillis = 0;

void setup() {
  Serial.begin(115200);

  sensors.begin();
  pinMode(WATER_LEVEL_PIN, INPUT_PULLUP);

  Serial.println("Smart Aquarium Monitoring Started");

  kiwisiot.begin();
}

void loop() {
  kiwisiot.run();

  if (millis() - previousMillis >= 3000) {
    previousMillis = millis();

    sensors.requestTemperatures();
    float temperature = sensors.getTempCByIndex(0);

    int phRaw = analogRead(PH_PIN);

    int waterLevel = digitalRead(WATER_LEVEL_PIN);

    String levelStatus =
      (waterLevel == LOW) ? "LOW" : "NORMAL";

    Serial.println("\n--- AQUARIUM MONITOR ---");

    if (temperature != DEVICE_DISCONNECTED_C) {
      Serial.print("Water Temperature: ");
      Serial.println(temperature);

      kiwisiot.send("0", String(temperature, 2));
    } else {
      Serial.println("Temperature Sensor Error");
    }

    Serial.print("pH ADC Reading: ");
    Serial.println(phRaw);

    Serial.print("Water Level: ");
    Serial.println(levelStatus);

    kiwisiot.send("1", String(phRaw));
    kiwisiot.send("2", levelStatus);
  }
}