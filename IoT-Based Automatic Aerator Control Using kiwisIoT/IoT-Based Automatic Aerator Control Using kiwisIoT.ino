#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

// WiFi Credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT Topic ID
const char* topic = "YOUR_TOPIC_ID";

// Sensor and Relay Pins
#define DO_SENSOR_PIN A0
#define RELAY_PIN D5

// Relay Configuration
// Change if your relay is active HIGH
#define RELAY_ON LOW
#define RELAY_OFF HIGH

// Calibrated ADC Thresholds
// Replace these with thresholds obtained
// from your calibrated DO sensor.

const int DO_LOW_THRESHOLD = 400;
const int DO_HIGH_THRESHOLD = 500;

// KiwisIoT
KiwisIoT kiwisiot(ssid, pass, topic);

unsigned long previousMillis = 0;

bool aeratorStatus = false;

void setup() {

  Serial.begin(115200);

  pinMode(DO_SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, RELAY_OFF);

  kiwisiot.begin();

  Serial.println("Automatic Aerator Control Started");
}

void loop() {

  kiwisiot.run();

  if (millis() - previousMillis >= 3000) {

    previousMillis = millis();

    // Read dissolved oxygen sensor
    int doRaw = analogRead(DO_SENSOR_PIN);

    // Automatic Aerator Control
    if (doRaw <= DO_LOW_THRESHOLD) {

      aeratorStatus = true;

    }

    else if (doRaw >= DO_HIGH_THRESHOLD) {

      aeratorStatus = false;

    }

    // Control Relay
    digitalWrite(
      RELAY_PIN,
      aeratorStatus ? RELAY_ON : RELAY_OFF
    );

    String aeratorState =
      aeratorStatus ? "ON" : "OFF";

    Serial.println("\n--- AQUACULTURE MONITOR ---");

    Serial.print("DO Sensor ADC: ");
    Serial.println(doRaw);

    Serial.print("Aerator Status: ");
    Serial.println(aeratorState);

    // Send data to KiwisIoT
    kiwisiot.send("0", String(doRaw));

    kiwisiot.send("1", aeratorState);

  }
}