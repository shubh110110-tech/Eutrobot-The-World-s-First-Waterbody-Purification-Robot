#include "HUSKYLENS.h"
#include <Wire.h>
#include <QMC5883LCompass.h>
#include <TinyGPS++.h>
#include <Servo.h>

HUSKYLENS huskylens;

const int L_IN1 = 22, L_IN2 = 23, L_ENA = 9;
const int R_IN3 = 24, R_IN4 = 25, R_ENB = 10;


Servo algaeServo;
const int SERVO_PIN = 11;


QMC5883LCompass compass;

// GPS
TinyGPSPlus gps;
#define GPS_RX 18 
#define GPS_TX 19 

void setup() {
  Serial.begin(9600); 
  Serial1.begin(9600); 
 
  Wire.begin(); 
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

  
  algaeServo.attach(SERVO_PIN);
  algaeServo.write(0); 

  
  compass.init();
}

void loop() {
  
  if (!huskylens.request()) {
    Serial.println("Failed to request data from HuskyLens");
  } 
  else if (huskylens.available()) {
    HUSKYLENSResult result = huskylens.read();
    if (result.ID == 1) { 
      Serial.println("Color ID 1 detected - Moving Forward + Servo 
NEW SKETCH
54555657585960616263646566676869
void loop() {
  
  if (!huskylens.request()) {
    Serial.println("Failed to request data from HuskyLens");
  } 
  else if (huskylens.available()) {
    HUSKYLENSResult result = huskylens.read();
    if (result.ID == 1) { 
      Serial.println("Color ID 1 detected - Moving Forward + Servo Active");
      moveForward();

Active");
      moveForward();
      algaeServo.write(90); 
    else { 
      Serial.println("Other ID detected - Stopping");
      stopMotors();
      algaeServo.write(0); 
    }
  } 
  else {
    Serial.println("No object detected - Stopping");
    stopMotors();
    algaeServo.write(0); 
  }


  while (Serial1.available() > 0) {
    gps.encode(Serial1.read());
  }
  if (gps.location.isUpdated()) {
    Serial.print("GPS Lat: "); Serial.print(gps.location.lat(), 6);
    Serial.print(", Lng: "); Serial.println(gps.location.lng(), 6);
  }


  compass.read();
  int heading = compass.getAzimuth();
  Serial.print("Compass Heading: ");
  Serial.print(heading);
  Serial.println(" degrees");

  delay(500);
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

