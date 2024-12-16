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
  // Read the state of the sensor/digital input
  sensorState = digitalRead(sensorPin);

  // Check if the sensor pin is HIGH and if enough time has passed since the last detection
  if (sensorState == HIGH && !motionDetected && (millis() - lastDetectionTime >= detectionCooldown)) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Sensor activated!");
    motionDetected = true;
    lastDetectionTime = millis();  // Update the last detection time
  } else if (motionDetected && millis() - lastDetectionTime >= detectionCooldown) {
    digitalWrite(ledPin, LOW);
    motionDetected = false;
  }

  // You can remove the delay or adjust it as needed.
  delay(150);
}
