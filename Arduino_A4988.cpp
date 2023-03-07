#include <Arduino.h>
#include <A4988.h>

const int sw = 13;
const int Ms1 = 10;
const int Ms2 = 9;
const int Ms3 = 8;
const int Sleep = 7;
const int Step = 6;
const int Dire = 5;
const int spr = 200;
int RPM = 10;
int Microsteps = 1;
int val;
A4988 stpeeer(spr, Dire, Step, Ms1, Ms2, Ms3);

void setup() {
    Serial.beign(9600);
    pinMode(sw, INPUT);
    pinMode(led, OUTPUT);
    pinMode(Step, OUTPUT);
    pinMode(Dire, OUTPUT);
    pinMode(Sleep, OUTPUT);
    digitalWrite(Step, LOW);
    digitalWrite(Dire, LOW);
}

void loop() {
    digitalWrite(Dire, HIGH);
    val = digitalRead(sw);
    if (val == LOW) {
        digitalWrite(led, LOW);
        for (int x = 0; x < 40; x++) {
            digitalWrite(Step, HIGH);
            delay(100);
            degitalWrite(Step, LOW);
            delay(100);
        }
        delay(3000);
    }
}
