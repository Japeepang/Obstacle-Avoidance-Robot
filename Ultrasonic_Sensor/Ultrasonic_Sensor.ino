#include <Servo.h>
const int trig = 12; 
const int echo = 11; 

Servo servo; 
int sound = 250; 
long duration;
int distance; 

void setup(){
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  servo.attach(9); 
  Serial.begin(9600);
}

void loop(){
  digitalWrite(trig, LOW);
  delay(10);

  digitalWrite(trig, HIGH);
  delay(50);
  digitalWrite(trig, LOW);

duration = pulseIn(echo, HIGH);
distance = duration * 0.034/2;

Serial.print("Distance: ");
Serial.println(distance);

  if(distance > 20){
    servo.write(170);
    delay(1500);
  }
  else{
    servo.write(0);
  }
}
