#include "HUSKYLENS.h"
#include <Wire.h>

HUSKYLENS huskylens;

const int L_IN1 = 2, L_IN2 = 3, L_ENA = 5;
const int R_IN3 = 4, R_IN4 = 7, R_ENB = 6;

void setup() {
  Serial.begin(9600);
  Wire.begin(); // Uses SDA/SCL pins

  if (!huskylens.begin(Wire)) {
    Serial.println("HuskyLens not connected!");
    while (1);
  }

  Serial.println("HuskyLens connected.");

  pinMode(L_IN1, OUTPUT);
  pinMode(L_IN2, OUTPUT);
  pinMode(L_ENA, OUTPUT);
  pinMode(R_IN3, OUTPUT);
  pinMode(R_IN4, OUTPUT);
  pinMode(R_ENB, OUTPUT);
}

void loop() {
  if (!huskylens.request()) {
    Serial.println("Failed to request data from HuskyLens");
    return;
  }

  if (huskylens.available()) {
    HUSKYLENSResult result = huskylens.read();
    if (result.ID == 1) {
      Serial.println("Color ID 1 detected - Moving Forward");
      moveForward();
    } else { 
      Serial.println("Other ID detected - Stopping");
      stopMotors();
    }
  } else {
    Serial.println("No object detected - Stopping");
    stopMotors();
  }

  delay(100);
}

void moveForward() {
  digitalWrite(L_IN1, HIGH);
  digitalWrite(L_IN2, LOW);
  analogWrite(L_ENA, 200);

  digitalWrite(R_IN3, HIGH);
  digitalWrite(R_IN4, LOW);
  analogWrite(R_ENB, 200);
}

void stopMotors() {
  analogWrite(L_ENA, 0);
  analogWrite(R_ENB, 0);
}
