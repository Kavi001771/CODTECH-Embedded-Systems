#include <Adafruit_LiquidCrystal.h>


Adafruit_LiquidCrystal lcd(0);  

const int relayPin = 13; 
String voiceCommand = ""; 

void setup() {
  
  Serial.begin(9600);
  
  
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); 

  
  lcd.begin(16, 2);
  lcd.setBacklight(1);
  
  
  lcd.setCursor(0, 0);
  lcd.print("Voice Control");
  lcd.setCursor(0, 1);
  lcd.print("System Ready...");
  delay(2000);
  lcd.clear();
}

void loop() {
  
  while (Serial.available() > 0) {
    delay(10); 
    char c = Serial.read(); 
    if (c == '\n' || c == '\r') break; 
    voiceCommand += c; 
  }

  if (voiceCommand.length() > 0) {
    voiceCommand.toLowerCase(); 
    voiceCommand.trim();       

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Voice: " + voiceCommand);

    
    if (voiceCommand == "on" || voiceCommand == "light on") {
      digitalWrite(relayPin, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("Relay: ON ");
      Serial.println("Action: Relay Turned ON");
    } 
    else if (voiceCommand == "off" || voiceCommand == "light off") {
      digitalWrite(relayPin, LOW);
      lcd.setCursor(0, 1);
      lcd.print("Relay: OFF");
      Serial.println("Action: Relay Turned OFF");
    } 
    else {
      lcd.setCursor(0, 1);
      lcd.print("Unknown Command");
    }

    voiceCommand = "";
  }
}