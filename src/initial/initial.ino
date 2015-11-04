/*
 * PINOUT IS AS FOLLOWS:
 * A0: Photoresistor
 * A1: Moisture Sensor 1
 * A2: Moisture Sensor 2
 * 13: DHT Sensor
 * 12: LCD
 * 11: LCD
 * 10: Grow Light
 * 9: Pump
 * 5: LCD
 * 4: LCD
 * 3: LCD
 * 2: LCD
 * 
 */
#include <LiquidCrystal.h>
#include <dht.h>

#define DHTPIN 13
#define DHTTYPE DHT11

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  
  Serial.begin (9600);
  pinMode (A0, INPUT);
  pinMode (A1, INPUT);
  pinMode (A2, INPUT);
  pinMode (10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lights();
  updateLCD();
 delay(300000); //5 minutes
}


int light(){
  return analogRead(A0);
}

int moistureOne(){
  return analogRead(A1);
}

int moistureTwo(){
  return analogRead(A2);
}

float temp(){
  return dht.readTemperature(true);
}

float humid(){
  return dht.readHumidity();
  
}
void lights(){
  if (light()>=1){ //change that light value
    digitalWrite(10, HIGH);
    Serial.print("Lights on");
  }else{
    digitalWrite(10, LOW);
    Serial.print("Lights off");
  }
}
void updateLCD(){
  lcd.print("Temp: ");
  lcd.print(round(temp()));
  lcd.print(" *F");
  lcd.setCursor(0,1);
  lcd.print ("Humid: ");
  lcd.print(round(humid()));
  lcd.print(" %");
  }

