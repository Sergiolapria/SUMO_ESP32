#include <Arduino.h>
#include <Wire.h>
#include "ESP32Servo.h"
/*
This firmware control 2 servos continuous rotation and read a distance sensor (HC-SR04) or a VL680 laser
The students must code the logic to control the robot for a sumo fight with a other similar robot. For this
 purpose, the students code must be coded in void loop() function.
*/
#define pinMotorD 32
#define pinMotorI 33
#define pinTrig 25
#define pinEcho 26  
Servo motorD;
Servo motorI;
long duration, distance;
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
  
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);
  duration = pulseIn(pinEcho, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
void setup() {
  Serial.begin(115200);
  Wire.begin();
  motorD.attach(pinMotorD);
  motorI.attach(pinMotorI);
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
}
void loop(){
  Medir_Distancia();
  if (distance < 20){
    MotorD(1);//Go on
    MotorI(1);
  }
  else{
    MotorD(0);//Gira
    MotorI(0);
  }
} 
