
#include <Servo.h>
Servo myservo;
const int trigPin = 2;
const int echoPin = 4;
 
void setup() {
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  long duration, cm;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(4);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  cm = microsecondsToCentimeters(duration);

  if (cm > 7 && cm < 14) {
    myservo.write(140);
    delay(4000);
  }
  else if (cm < 8) {
    myservo.write(40);
    delay(100);
  }
  else {
    myservo.write(40);
    delay(100);
  }
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
}
 
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
