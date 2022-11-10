#include <Servo.h>

const int sw = A0;
const int trigPin = A1;
const int echoPin = A2;
const int servoPin = A3;
const int led1 = 12;
const int led2 = 11;
int val, i;
double SetDelay, Input, Ouput, ServoOutput;
Servo servo;

void setup() {

  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(sw, INPUT);
  digitalWrite(led1, 0);
  digitalWrite(led2, 1);

  servo.attach(servoPin);
  ServoOutput = 30;
  servo.write(ServoOutput);
  Input = readPosition();

}

void loop() {

  Input = readPosition();
  if (Input >= 140) {
    for (i = 30; i <= 150; i++) {
      servo.write(i);
      delay(5);
    }

    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);

    delay(3000);

    for(i = 150; i >= 30; i--) {
      servo.write(i);
      delay(1);      
    }
  }
  else {
    delay(200);
  }

  digitalWrite(led1, 0);
  digitalWrite(led2, 1);
}

float readPosition() {
  delay(40);
  long duration, var;
  int distance;
  val = digitalRead(sw);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration/(29*2);
  Serial.print("sw:");
  Serial.print(val);
  Serial.print(";  ");
  Serial.print("Distance:");
  Serial.print(distance);
  Serial.print("公分");
  if (distance < 50 || val == 0) {
    var = 180;
  }
  else {
    var = 90;
  }
  return var;
}
