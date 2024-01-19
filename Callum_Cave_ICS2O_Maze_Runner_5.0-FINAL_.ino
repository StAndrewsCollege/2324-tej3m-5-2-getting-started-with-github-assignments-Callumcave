/*
 * This program makes robot detect wall and move through maze
 * 
 * Programmer: Callum Cave
 * Last Updated: 1/26/2023
 */


//setting up servo
#include <Servo.h>
Servo myservo;


//Giving variable names to the pin
#define SpeedLeft 5
#define SpeedRight 6
#define DirectionLeft 7
#define DirectionRight 8 
#define PowerAll 3

int Echo = 12;
int Trig = 13;

long duration;
long distance;

int distDetect(){
  //senses distance and returns is 
 digitalWrite(Trig, LOW);
 delayMicroseconds(2);
 digitalWrite(Trig, HIGH);
 delayMicroseconds(20);
 digitalWrite(Trig, LOW);
 duration = pulseIn(Echo, HIGH);
 distance = duration / 58;
 Serial.print("Distance; ");
 Serial.println(distance);
 return distance;

}

void forward (int speed) {
  //moves robot forward 
  digitalWrite(DirectionRight, HIGH); 
  analogWrite(SpeedRight, speed-7);
  digitalWrite(DirectionLeft, HIGH);
  analogWrite(SpeedLeft, speed);
  digitalWrite(PowerAll, HIGH);
  Serial.print ("Forward"); 
}

void one80(){
  digitalWrite(DirectionRight,HIGH);
  analogWrite(SpeedRight, 100);
  digitalWrite(DirectionLeft,LOW);
  analogWrite(SpeedLeft, 100);
  digitalWrite(PowerAll, HIGH);
  delay(505);
  Serial.print("right90");
  
}

 void backward (int speed) {
  //moves robot backward 
  digitalWrite(DirectionRight, LOW); 
  analogWrite(SpeedRight, speed);
  digitalWrite(DirectionLeft, LOW);
  analogWrite(SpeedLeft, speed);
  digitalWrite(PowerAll, HIGH);
  Serial.print ("Backward");
 }
void left (int speed) {
  //moves robot left
  digitalWrite(DirectionRight, LOW); 
  analogWrite(SpeedRight, speed);
  digitalWrite(DirectionLeft, HIGH);
  analogWrite(SpeedLeft, speed);
  digitalWrite(PowerAll, HIGH);
  Serial.print ("left");
}
void left90 () {
  //moves robot left
  digitalWrite(DirectionRight, LOW); 
  analogWrite(SpeedRight, 100);
  digitalWrite(DirectionLeft, HIGH);
  analogWrite(SpeedLeft, 100);
  digitalWrite(PowerAll, HIGH);
  delay(505);
  Serial.print ("left90");
}
void right (int speed) {
  //moves robot right
  digitalWrite(DirectionRight, HIGH); 
  analogWrite(SpeedRight, speed);
  digitalWrite(DirectionLeft, LOW);
  analogWrite(SpeedLeft, speed);
  digitalWrite(PowerAll, HIGH);
  Serial.print ("right");
}

void SpeedUpForward () {
  //Robot speeds up from a stop to full speed going forward
 for (int i=0; i<=255; i++){
  forward (i);
  delay (10);
 }
 Serial.println ("Speed Up Forward");
}

void SlowDownForward (){
  //Robot slow down from full speed to a stop going forward
 for (int i=255; i>=0; i--){
  forward (i);
  delay (10);
 }
 Serial.println ("Slow Down Backward");
}

void SpeedUpBack (){
  //Robot speeds up fron a stop to full speed going backward
  for (int i=0; i<=255; i++){
    backward (i);
    delay (10);
  }
  Serial.println("Speed Up Back");
}

void SlowDownBack (){
  //Robot slow down from full speed going backward
  for (int i=255; i>=0; i--){
    backward (i);
    delay (10);
  }
  Serial.println ("Slow Down Backward");
}


void Stop (){
  //Makes robot stop
  digitalWrite (PowerAll, LOW);
  Serial.println ("Stop");
}
void setup() {
  // defining the digital pins to Outputs and Input
  pinMode (SpeedLeft, OUTPUT);
  pinMode (SpeedRight, OUTPUT);
  pinMode (DirectionLeft, OUTPUT);
  pinMode (DirectionRight, OUTPUT);
  pinMode (PowerAll, OUTPUT);
  pinMode (Echo, INPUT); 
  pinMode (Trig, OUTPUT); 
  // set up serial monitor 
  Serial.begin (9600);

//attaching servo to pin and looking forward
myservo.attach(10);
myservo.write(90);//move servos to center position

}

void loop() {
 //Robots moves through the maze and turns when detects a wall
 
    myservo.write(90);
    if(distDetect()<10){
    Stop();
    myservo.write(180);
    delay(1000);
    if(distDetect()<26){
    right(100);
    delay(600);
    Stop();
    forward(100);
    }
    else{
      left(100);
      delay(500);
      forward(100);
    }
    }
    else{
    forward(65);
    }
    

    }

  
