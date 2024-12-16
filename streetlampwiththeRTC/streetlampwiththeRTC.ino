#include <Wire.h>
#include <Ds1302.h>

// Connection pins for DS1302
#define DS1302_SCLK_PIN 12
#define DS1302_IO_PIN 11
#define DS1302_CE_PIN 10

Ds1302 rtc(DS1302_CE_PIN, DS1302_IO_PIN, DS1302_SCLK_PIN);

int sensorPin = 2;
int ledPin = 13;
int sensorState = LOW;
unsigned long lastDetectionTime = 0;
unsigned long detectionCooldown = 5000;  // Set the cooldown time in milliseconds (e.g., 5000 = 5 seconds)
bool motionDetected = false;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // Get current time from RTC
  Ds1302::DateTime dt;
  rtc.getDateTime(&dt);

  int hour = dt.hour;
  int minute = dt.minute;
  int second = dt.second;

  //Debug statements
  //Serial.print("Hour: ");
  //Serial.println(hour);
  //Serial.print("Motion Sensor State: ");
  //Serial.println(sensorState);
  //Serial.print("Is it Nighttime?: ");
  //Serial.println((hour >= 18 || hour < 6) ? "Yes" : "No");

  // Check if it's nighttime (e.g., between 6 PM and 6 AM)
  if ((hour >= 18 || hour < 6) && !motionDetected) {
    // Read the state of the sensor/digital input
    sensorState = digitalRead(sensorPin);

    // Check if the sensor pin is HIGH and if enough time has passed since the last detection
    if (sensorState == HIGH && (millis() - lastDetectionTime >= detectionCooldown)) {
      digitalWrite(ledPin, HIGH);
      Serial.println("Sensor activated!");
      motionDetected = true;
      lastDetectionTime = millis(); // Update the last detection time
    } else if (motionDetected && millis() - lastDetectionTime >= detectionCooldown) {
      digitalWrite(ledPin, LOW);
      motionDetected = false;
    }
  } else {
    // Turn off the LED during daytime
    digitalWrite(ledPin, LOW);
    motionDetected = false;
  }

  // You can remove the delay or adjust it as needed.
  delay(150);
}
