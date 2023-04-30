#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define echoPin 8
#define trigPin 9

float time;
float distance_cm;
float distance_in;
 
void setup(){
Serial.begin(9600);

pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

lcd.begin(16, 2);
}
 
void loop(){
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);

time = pulseIn(echoPin, HIGH);

distance_cm = (time/2) / 29.1;
distance_in = (time/2) / 73.914;

lcd.setCursor(0, 0);
lcd.print("    Distance   ");

lcd.setCursor(0, 1);
lcd.print(distance_cm,1);
lcd.print("cm  ");

lcd.setCursor(9, 1);
lcd.print(distance_in);
lcd.print("in  ");

Serial.print("cm= ");
Serial.print(distance_cm);
Serial.print(" inch= ");
Serial.println(distance_in);

delay(200);
}