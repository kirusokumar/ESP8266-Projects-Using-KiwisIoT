#include <WiFi.h>
#include <KiwisIoT.h>
#include <OneWire.h>
#include <DallasTemperature.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";

#define TEMP_PIN 4
#define PH_PIN 34
#define TURBIDITY_PIN 35

OneWire oneWire(TEMP_PIN);
DallasTemperature tempSensor(&oneWire);

KiwisIoT kiwisiot(ssid, pass, topic);

void setup() {
  Serial.begin(115200);

  tempSensor.begin();
  kiwisiot.begin();

  Serial.println("Fish Pond Monitoring Started");
}

void loop() {
  kiwisiot.run();

  static unsigned long previousTime = 0;

  if (millis() - previousTime >= 3000) {
    previousTime = millis();

    tempSensor.requestTemperatures();

    float temperature =
      tempSensor.getTempCByIndex(0);

    int phRaw = analogRead(PH_PIN);
    int turbidityRaw = analogRead(TURBIDITY_PIN);

    Serial.println("---- FISH POND DATA ----");

    Serial.print("Temperature: ");
    Serial.println(temperature);

    Serial.print("pH ADC: ");
    Serial.println(phRaw);

    Serial.print("Turbidity ADC: ");
    Serial.println(turbidityRaw);

    kiwisiot.send("0", String(temperature, 2));
    kiwisiot.send("1", String(phRaw));
    kiwisiot.send("2", String(turbidityRaw));
  }
}