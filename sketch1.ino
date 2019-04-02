#include <Servo.h>
#include "IRremote.h"

// IR Remote
int receiver = 11;
IRrecv irrecv(receiver);
decode_results results;

// Servo Motor
Servo myservo;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  
  myservo.attach(8);
  myservo.write(10);
}

bool lightOn = false;
bool moveSwitch = false;
bool turnOn = true;
long end = 0;
void loop() {
  if (irrecv.decode(&results)) {
    translateIR();
    irrecv.resume();
  }
  if(moveSwitch){
    if(turnOn){
      myservo.write(20);
      lightOn = true;
    }else{
      myservo.write(200);
      lightOn = false;
    }
    if(millis() > end){
      moveSwitch = false;
    }
  } else {
    myservo.write(90);
  }
}

void translateIR() {
  Serial.println(results.value);
  if(results.value == 16724175){
    end = millis() + 1000;
    moveSwitch = true;
    
    turnOn = true;
  } else if (results.value == 16718055){
    end = millis() + 1000;
    moveSwitch = true;
    
    turnOn = false;
  }
} 
