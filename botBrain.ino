//define variables these based on construction
//try to do servo and IR reciever as PWM pins

static int ir = 0;     // replace 0 with arduino pin connected to Y pin on IRreciever

//servos
static int rservo = 0;   // yellow wire on right servo
static int lservo = 0;   // yellow wire on left servo

//motors
static int rw1 = 0;      //right wheel posotive
static int rw2 = 0;      //right wheel neg
static int lw1 = 0;      //left wheel posotive
static int lw2 = 0;      // left wheel neg
//these must be tested. to test press button 1 on IR remote which will call forward 
// if one of the wheels are turning backwards swap the positions of black and red 
// wires on the l293d configuration for that motor


// if open and close dont work find leftCLaw.write and rightClaw.write in the setup
// open and close method and change the angles inside the ()

#include<Servo.h>
#include <IRremote.hpp>
Servo rightClaw;
Servo leftClaw;
#define IR_RECEIVE_PIN ir  
byte command;    



void setup() {
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);   
  pinMode(lservo,OUTPUT);                       //6right 5 left
  pinMode(rservo,OUTPUT);
  rightClaw.attach(rservo);
  leftClaw.attach(lservo);
  leftClaw.write(90);               // starts 90 ends 0
  rightClaw.write(90);              // starts 90 ends 180
 
  pinMode(rw1,OUTPUT);
  pinMode(rw2,OUTPUT);
  pinMode(lw1,OUTPUT);
  pinMode(lw2,OUTPUT);

  Serial.begin(9600);

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  Serial.println("IR Receiver Ready");
}
void forward(){
    digitalWrite(rw1,1);
    digitalWrite(rw2,0);
    digitalWrite(lw1,0);
    digitalWrite(lw2,1);
    delay(500);
    digitalWrite(rw1,0);
    digitalWrite(rw2,0);
    digitalWrite(lw1,0);
    digitalWrite(lw2,0);
}

void left(){
  digitalWrite(rw1,1);
    digitalWrite(rw2,0);
    digitalWrite(lw1,1);
    digitalWrite(lw2,0);
      delay(500);
    digitalWrite(rw1,0);
    digitalWrite(rw2,0);
    digitalWrite(lw1,0);
    digitalWrite(lw2,0);

}

void right(){
  digitalWrite(rw1,0);
    digitalWrite(rw2,1);
    digitalWrite(lw1,0);
    digitalWrite(lw2,1);
      delay(500);
    digitalWrite(rw1,0);
    digitalWrite(rw2,0);
    digitalWrite(lw1,0);
    digitalWrite(lw2,0);
}
 void open(){
  leftClaw.write(90);               
  rightClaw.write(90);
 }
 void close(){
   leftClaw.write(0);               
  rightClaw.write(180);
 }


void loop() {
  if (IrReceiver.decode()) {
     command = IrReceiver.decodedIRData.address ;
     if(command == ){
       
     }
    if(command == ){
       
     }
    if(command == ){
       
     }

    

    IrReceiver.resume();
  }
}
