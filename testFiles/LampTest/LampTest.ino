#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#include <DHT.h>
#define DHTPIN 13
#define DHTTYPE DHT11
#include "DHT.h"
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  lcd.begin (16,2);
  Serial.begin(9600);
  Serial.println("Begin");
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(A0, INPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
   
  updateLCD();
  lights();
  pump();
  delay(5000);
  Serial.println("Loop");
}

void lights() {
  if (light() >= 650) { //change that light value
    digitalWrite(10, HIGH);
    Serial.println("Lights on");
  } else {
    digitalWrite(10, LOW);
    Serial.println("Lights off");
  }
}
int moistureOne(){
  //digitalWrite(6, HIGH);
  //delay(3000); //This might be needed
  int i = analogRead(A1);
  Serial.println(i);
  digitalWrite(6, LOW);
  return i;
  
}
void pump(){
  if(moistureOne()<=540){
    digitalWrite(9, HIGH);
    Serial.println("PUMP ON");
    delay(3000);//Wait 5 minutes
    digitalWrite(9, LOW);
    Serial.println("PUMP OFF");
    pump();//RUN AGAIN? MAYBE THIS IS A BAD IDEA
  }
}
int light() {
  //Serial.println(analogRead(A0));
  return analogRead(A0);

}
float temp(){
  //Serial.println(dht.readTemperature(true));
  return dht.readTemperature(true);
}

float humid(){
 //Serial.println(dht.readHumidity());
 return dht.readHumidity();
  
}
void updateLCD(){
  lcd.clear();
  lcd.print("Temp: ");
  lcd.print(round(temp()));
  lcd.print(" *F");
  lcd.setCursor(0,1);
  lcd.print ("Humid: ");
  lcd.print(round(humid()));
  lcd.print(" %");
  }
