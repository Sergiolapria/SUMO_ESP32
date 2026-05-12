#include <Arduino.h>
#include <Wire.h>
#include "ESP32Servo.h"
#include "Adafruit_VL6180X.h"
/*
This firmware control 2 servos continuous rotation and read a distance sensor (HC-SR04) or a VL680 laser
The students must code the logic to control the robot for a sumo fight with a other similar robot. For this
 purpose, the students code must be coded in void loop() function.
*/
#define pinMotorD 12
#define pinMotorI 13
#define pinTrig 25
#define pinEcho 26  
#define suelo 4

Adafruit_VL6180X vl = Adafruit_VL6180X();//constructor of the sensor
Servo motorD;
Servo motorI;
long duration, distance;
uint8_t range=0;
void MotorD(int sentidoD){
  if (sentidoD == 1){
    motorD.write(180);
  }
  else if (sentidoD == -1){
    motorD.write(0);
  }
  else{
    motorD.write(90);
  }
}
void MotorI(int sentidoI){
  if (sentidoI == 1){
    motorI.write(180);
  }
  else if (sentidoI == -1){
    motorI.write(0);
  }
  else{
    motorI.write(90);
  }
}
void Medir_Distancia(){
  
  //digitalWrite(pinTrig, LOW);
  //delayMicroseconds(2);
 // digitalWrite(pinTrig, HIGH);
 // delayMicroseconds(10);
 //// digitalWrite(pinTrig, LOW);
 // duration = pulseIn(pinEcho, HIGH);
  //distance = (duration/2) / 29.1;
 // Serial.print("Distance: ");
 // Serial.print(distance);
  //Serial.println(" cm");
  //Si esta habilitado sensor VL6180X, se comenta el bloque de medición de distancia con HC-SR04 y se descomenta el bloque de medición con el sensor
  float lux = vl.readLux(VL6180X_ALS_GAIN_1);
  range = vl.readRange();
  Serial.print("Range: ");  
  Serial.println(range);
}
void setup() {
  Serial.begin(9600);
  pinMode(suelo, INPUT);
  motorD.attach(pinMotorD);
  motorI.attach(pinMotorI);
  //Wire.begin();
  //pinMode(pinTrig, OUTPUT);
  //pinMode(pinEcho, INPUT);
  //si tiene habilitado VL6180X, se comenta el bloque de medición de distancia con HC-SR04 y se descomenta el bloque de inicialización del sensor
  if (!vl.begin()) {
    Serial.println("Failed to initialize VL6180X sensor!");
    while (1);
  }
}
void loop(){
  Medir_Distancia();

  
} 
