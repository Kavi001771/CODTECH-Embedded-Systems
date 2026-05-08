#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);
int lightPin = 13;
char command;

void setup() {
  Serial.begin(9600);
  pinMode(lightPin, OUTPUT);
  
  lcd.begin(16, 2);
  lcd.setBacklight(1);
  lcd.print("Smart Home Sys");
  lcd.setCursor(0, 1);
  lcd.print("Waiting...");
  delay(2000);
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read(); 
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Command Recv:");
    lcd.setCursor(0, 1);
    
    if (command == '1') {
      digitalWrite(lightPin, HIGH);
      lcd.print("LIGHT: ON");
      Serial.println("Action: Light Turned ON");
    } 
    else if (command == '0') {
      digitalWrite(lightPin, LOW);
      lcd.print("LIGHT: OFF");
      Serial.println("Action: Light Turned OFF");
    }
    else {
      lcd.print("Invalid Key!");
    }
  }
}