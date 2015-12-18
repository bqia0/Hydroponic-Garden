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
 * 7: Moisture Sensor 2 Power
 * 6: Moisture Sensor 1 Power
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
  pinMode (13, INPUT);
  pinMode (10, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode (6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  updateLCD();
  pump();
  lights();
 delay(300000); //5 minutes
}


int light(){
  return analogRead(A0);
}

int moistureOne(){
  digitalWrite(6, HIGH);
  delay(1000); //This might be needed
  int i = analogRead(A1);
  Serial.print("Moisture 1: " +i);
  digitalWrite(6, LOW);
  return i;
  
}

int moistureTwo(){
  digitalWrite(7, HIGH);
  delay(1000); //This might be needed
  int i = analogRead(A2);
  Serial.print("Moisture 2: " +i);
  digitalWrite(7, LOW);
  return i;
}

float temp(){
  return dht.readTemperature(true);
}

float humid(){
 return dht.readHumidity();
  
}
void lights(){
  if (light()>=650){ 
    digitalWrite(10, HIGH);
    Serial.print("Lights on");
  }else{
    digitalWrite(10, LOW);
    Serial.print("Lights off");
  }
}
void pump(){
  if(moistureOne()<=540||moistureTwo()<=540){
    digitalWrite(9, HIGH);
    delay(300000);//Wait 5 minutes
    digitalWrite(9, LOW);
    pump();//RUN AGAIN? MAYBE THIS IS A BAD IDEA
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

