#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(32, 16, 2);
const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

//Button 1
void loop() {
  if (digitalRead(buttonPin1) == HIGH) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Hello, World :)");
    delay(1000);
    lcd.clear();
  }
  
//Button 2  
  if (digitalRead(buttonPin2) == HIGH) {
    lcd.clear();
    Serial.println("I will survive this last year");
    delay(500);
  }
  
//BUtton 3
  if (digitalRead(buttonPin3) == HIGH) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Hello, World :)");
    Serial.println("I will survive this last year");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("I will survive ");
    lcd.setCursor(0,1);
    lcd.print("this year ;]");
    Serial.println("Hello, World");
    delay(2000);
    lcd.clear();
  }
}

