// Pin definitions
#define RED1_PIN 3
#define RED2_PIN 4
#define GREEN1_PIN 5
#define GREEN2_PIN 6
#define ORANGE_PIN 7
#define TACT_SWITCH_PIN 2

// Time intervals (in milliseconds)
#define RED_GREEN_TIME 4000
#define GREEN_RED_TIME 5000
#define ORANGE_TIME 1000
#define CYCLE_COUNT 3

bool switchPressed = false;
int cycleCount = 0;

void setup() {
  // Initialize pins as outputs
  pinMode(RED1_PIN, OUTPUT);
  pinMode(RED2_PIN, OUTPUT);
  pinMode(GREEN1_PIN, OUTPUT);
  pinMode(GREEN2_PIN, OUTPUT);
  pinMode(ORANGE_PIN, OUTPUT);
  
  // Initialize tact switch pin as input with internal pull-up resistor
  pinMode(TACT_SWITCH_PIN, INPUT_PULLUP);
}

void loop() {
  // Check if tact switch is pressed and released
  if (digitalRead(TACT_SWITCH_PIN) == LOW && !switchPressed) {
    switchPressed = true;
    
    // Execute traffic light sequence
    while (cycleCount < CYCLE_COUNT) {
      // Red1 (stop vehicle) and Green2 (go pedestrian) for 4 seconds
      digitalWrite(RED1_PIN, HIGH);
      digitalWrite(GREEN2_PIN, HIGH);
      delay(RED_GREEN_TIME);
      digitalWrite(RED1_PIN, LOW);
      digitalWrite(GREEN2_PIN, LOW);

      // Red2 (stop pedestrian) and Green1 (go vehicle) for 5 seconds
      digitalWrite(RED2_PIN, HIGH);
      digitalWrite(GREEN1_PIN, HIGH);
      delay(GREEN_RED_TIME);
      digitalWrite(RED2_PIN, LOW);
      digitalWrite(GREEN1_PIN, LOW);

      // Orange for 1 second
      digitalWrite(ORANGE_PIN, HIGH);
      delay(ORANGE_TIME);
      digitalWrite(ORANGE_PIN, LOW);

      cycleCount++;
    }
    // Reset cycle count after completion
    cycleCount = 0;
  } else if (digitalRead(TACT_SWITCH_PIN) == HIGH && switchPressed) {
    switchPressed = false;
  }
}
