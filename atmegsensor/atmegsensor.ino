const int trigPin = 9;
const int echoPin = 10;
const int level4 = 8;
const int level3 = 11;
const int level2 = 12;
const int level1 = 13;
const int buzzerPin = 6; ///[eto yung buzzer mo jean]

long duration;
int distance;
int safetyDistance;
int consecutiveDetects = 0; ///[dito mag start mag count buzzer mo]
const int consecutiveThreshold = 3; ///[dito siya mag b-buzz]

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

  if (distance <= 25) {
    consecutiveDetects++; 
  } else {
    consecutiveDetects = 0;
  }

  if (consecutiveDetects >= consecutiveThreshold) {
    digitalWrite(buzzerPin, HIGH); ///[on niya buzzer kapag pangatlo na]
  } else {
    digitalWrite(buzzerPin, LOW); ///[off niya kapag nag reset siya]
  }

  ///[ hindi ko na to dinelete baka kase magalit ka, kaya dinagdagan ko nalang for formality ]
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.print("Consecutive Detects: ");
  Serial.println(consecutiveDetects);
}
