#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

const int tempPin = A0; 
const int ldrPin = A1;  

void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(1);
  lcd.print("Smart Weather");
  lcd.setCursor(0, 1);
  lcd.print("Station Active");
  delay(2000);
}

void loop() {
  
  int tempVal = analogRead(tempPin);
  float voltage = (tempVal / 1024.0) * 5.0;
  float tempC = (voltage - 0.5) * 100;

  
  int ldrVal = analogRead(ldrPin);
  int lightPercent = map(ldrVal, 0, 1023, 0, 100); 

  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Light: ");
  lcd.print(lightPercent);
  lcd.print(" %");

  delay(2000);
}