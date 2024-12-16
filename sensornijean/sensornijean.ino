const int trigPin = 9;
const int echoPin = 10;
const int level4 = 8;
const int level3 = 11;
const int level2 = 12;
const int level1 = 13;
const int buzzerPin = 7; ///[jean eto yung buzzer mo]

long duration;
int distance;
int safetyDistance;
int consecutiveDetects = 0; ///[dito siya mag start mag count ng detections]
const int consecutiveThreshold = 3; /// [eto yung kelan niya need mag buzz na]

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(level4, OUTPUT);
  pinMode(level3, OUTPUT);
  pinMode(level2, OUTPUT);
  pinMode(level1, OUTPUT);
  pinMode(buzzerPin, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  safetyDistance = distance;
  if (distance <= 25) {
    digitalWrite(level4, HIGH);
  } else {
    digitalWrite(level4, LOW);
  }
  if (distance <= 50) {
    digitalWrite(level3, HIGH);
  } else {
    digitalWrite(level3, LOW);
  }
  if (distance <= 75) {
    digitalWrite(level2, HIGH);
  } else {
    digitalWrite(level2, LOW);
  }
  if (distance <= 100) {
    digitalWrite(level1, HIGH);
  } else {
    digitalWrite(level1, LOW);
  }

  if (distance <= 25) {
    consecutiveDetects++; 
  } else {
    consecutiveDetects = 0; 
  }

  if (consecutiveDetects >= consecutiveThreshold) {
    digitalWrite(buzzerPin, HIGH); ///[eto yung nag o=on sa buzzer ha jean rose jean]
  } else {
    digitalWrite(buzzerPin, LOW); ///[eto naman off ha jean ha jean]
  }

  // [hindi ko na inalis baka magalit kapa eh, dinagdagan ko nalang for monitoring]
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.print("Consecutive Detects: ");
  Serial.println(consecutiveDetects);
}
