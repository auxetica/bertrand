
int xPin = A0;
int yPin = A1;
int Q1 = 3;
int Q2 = 5;
int Q3 = 6;
int Q4 = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Q1, OUTPUT);
  pinMode(Q2, OUTPUT);
  pinMode(Q3, OUTPUT);
  pinMode(Q4, OUTPUT);
}

void loop() {
  int x = map(analogRead(xPin), 0, 1023, 0, 255);
  int y = map(analogRead(yPin), 0, 1023, 0, 255);
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(", ");
  Serial.println(getQuadrantPower(x, y));
  if (x > 131) {
    if (y < 131) {
      //Q1
      analogWrite(Q1, getQuadrantPower(x, y));
      analogWrite(Q2, 0);
      analogWrite(Q3, 0);
      analogWrite(Q4, 0);
    }
    else {
      //Q4
      analogWrite(Q4, getQuadrantPower(x, y));
      analogWrite(Q2, 0);
      analogWrite(Q3, 0);
      analogWrite(Q1, 0);
    }
  }
  else {
    if (y < 131) {
      //Q2
      analogWrite(Q2, getQuadrantPower(x, y));
      analogWrite(Q1, 0);
      analogWrite(Q3, 0);
      analogWrite(Q4, 0);
    }
    else {
      //Q3
      analogWrite(Q3, getQuadrantPower(x, y));
      analogWrite(Q2, 0);
      analogWrite(Q1, 0);
      analogWrite(Q4, 0);
    }
  }
}

int getQuadrantPower(int x, int y) {
  x = abs(x-128);
  y = abs(y-128);
  int distance = sqrt(x*x + y*y);
  return map(distance, 0, 182, 0, 255);
}
