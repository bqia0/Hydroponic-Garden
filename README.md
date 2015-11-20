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

Assume flat side of pnp facing user. Left pin is one, middle 2, right 3.
Pnp transistors flow from emitter (1) to collector (3) with the base at 2. Voltage at base would turn off a pnp transistor, while no voltage would re-enable it. 
Example of transistor use in picture below:


PINOUT IS AS FOLLOWS:
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
