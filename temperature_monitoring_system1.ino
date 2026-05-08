#include <Adafruit_LiquidCrystal.h>


Adafruit_LiquidCrystal lcd(0); 

void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(1); 
  lcd.print("Temp Monitor");
}

void loop() {
  int sensorVal = analogRead(A0);
  float voltage = (sensorVal / 1024.0) * 5.0;
  float tempC = (voltage - 0.5) * 100;

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(tempC);
  lcd.print(" C  "); 
  
  delay(1000);
}