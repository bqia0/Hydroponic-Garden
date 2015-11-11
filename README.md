# Hydroponic-Garden
Temperature and Humidity Sensor:
Import DHT library.
Sensor is DHT 11. 
Connect the left (data) pin to a digital pin. The middle and right pins are positive and negative, respectively.
Use the readTemperature(). Use parameter true if you want Fahrenheit. 

Photo resistor:
Connect the left (data) pin to an analog pin. The middle and right pins are positive and negative, respectively.
Use the analogRead() method. 

Add pull up/down resistors

PINOUT IS AS FOLLOWS:
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