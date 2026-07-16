#include <Servo.h>
const int photoResistorPin = A1;
const int servoPin = 7;
Servo servo;
int pos;


void setup() {
  // put your setup code here, to run once:
  servo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int photoResistorValue = analogRead(photoResistorPin);
  Serial.println(analogRead(photoResistorPin));
  if (photoResistorValue < 10) {
    // pos = 60;
    delay(25);
    servo.write(15);
    delay(30);
    servo.write(40);
  }
}
