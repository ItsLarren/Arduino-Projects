void setup() {
  for (int i=2; i<=7; i++) pinMode(i, OUTPUT);
  for (int i=8; i<=13; i++) pinMode(i, INPUT);
}

const int d = 100;

void patternOne() {
  for (byte c=0; c<3; c++) {
    for (int i = 7; i >= 2; i--) {
      for (int j = 2; j <= i; j++) {
        digitalWrite(j, HIGH); delay(d); digitalWrite(j, LOW);
      }
      digitalWrite(i, HIGH); delay(d);
    }
    for (int i = 2; i <= 7; i ++) digitalWrite(i, LOW);
  }
}

void patternTwoFiveSix(int p) {
  int count = (p == 2) ? 3*2 : 3;
  for (byte c=0; c<count; c++) {
    for (byte i=0; i<=5; i++) {
      digitalWrite(i+2, p == 5 ? !digitalRead(i+2) : HIGH);
      digitalWrite(7-i, p == 5 ? !digitalRead(7-i) : HIGH);
      delay((p == 5 && i == 5) ? d*3 : d);
      if (p != 5) {
        digitalWrite(i+2, LOW);
        digitalWrite(7-i, LOW);
        delay((p == 6 && i == 5) ? d*3 : 0);
      }
    }
  }
}

void patternThree() {
  for (byte c = 0; c < 3; c++) {
    for (byte i = 2; i <= 7; i++ ) {
      digitalWrite(i, HIGH); delay(d);
    }
    for (byte i = 2; i <= 7; i++ ) {
      digitalWrite(i, LOW); delay(d);
    }
  }
}

void patternFour() {
  for (byte c=0; c<3*2; c++) {
    for (byte i=2; i<=7; i++) {
      digitalWrite(i, HIGH); delay(d); digitalWrite(i, LOW);
    }
  }
}

void loop() {
  if (digitalRead(8) == HIGH) patternOne();
  if (digitalRead(9) == HIGH) patternTwoFiveSix(2);
  if (digitalRead(10) == HIGH) patternThree();
  if (digitalRead(11) == HIGH) patternFour();
  if (digitalRead(12) == HIGH) patternTwoFiveSix(5);
  if (digitalRead(13) == HIGH) patternTwoFiveSix(6);
  else for (int i=2; i<=7; i++) digitalWrite(i, LOW);
}