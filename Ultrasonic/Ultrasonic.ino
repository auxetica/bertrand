const int trigPin = 10;
const int echoPin = 9;
const int ledPin1 = 2;
const int ledPin2 = 3;
const int ledPin3 = 4;
const int ledPin4 = 5;
const int buzzerPin = 6;

long duration;
long distance;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  measureDistance();
}

float measureDistance() {
  //fire pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0343 / 2.0;
  Serial.println(distance);

  //reset LEDs
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);

  //activate LEDs
  if (distance <= 5 ) {
    digitalWrite(ledPin1, HIGH);
  }
  else if (distance <= 10) {
    digitalWrite(ledPin2, HIGH);
  }
  else if (distance <= 15) {
    digitalWrite(ledPin3, HIGH);
  }
  else if (distance <= 20) {
    digitalWrite(ledPin4, HIGH);
  }
  delay(100);
}
