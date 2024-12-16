#define RED1_PIN 5
#define GREEN1_PIN 6
#define ORANGE_PIN 7
#define RED2_PIN 8
#define GREEN2_PIN 9
#define TOGGLE_PIN 10
#define RED_GREEN_TIME 4000
#define GREEN_RED_TIME 5000
#define ORANGE_TIME 1000
#define CYCLE_COUNT 2 

bool switchPressed = false;
int repeatCount = 0;

void setup() {
  pinMode(RED1_PIN, OUTPUT);
  pinMode(GREEN1_PIN, OUTPUT);
  pinMode(ORANGE_PIN, OUTPUT);
  pinMode(RED2_PIN, OUTPUT);
  pinMode(GREEN2_PIN, OUTPUT);
  pinMode(TOGGLE_PIN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(TOGGLE_PIN) == LOW && !switchPressed) {
    switchPressed = true;
    repeatCount = 0;
    while (repeatCount < CYCLE_COUNT) {
      int cycle = 0;
      while (cycle < 1) { 
        digitalWrite(RED1_PIN, HIGH);
        digitalWrite(GREEN2_PIN, HIGH);
        delay(RED_GREEN_TIME);
        digitalWrite(RED1_PIN, LOW);
        digitalWrite(GREEN2_PIN, LOW);

        digitalWrite(RED2_PIN, HIGH);
        digitalWrite(GREEN1_PIN, HIGH);
        delay(GREEN_RED_TIME);
        digitalWrite(RED2_PIN, LOW);
        digitalWrite(GREEN1_PIN, LOW);

        digitalWrite(ORANGE_PIN, HIGH);
        delay(ORANGE_TIME);
        digitalWrite(ORANGE_PIN, LOW);

        cycle++;
      }
      repeatCount++;
    }
  } else if (digitalRead(TOGGLE_PIN) == HIGH && switchPressed) {
    switchPressed = false;
  }
}

