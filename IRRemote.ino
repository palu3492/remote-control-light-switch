#include "IRremote.h"

int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 11

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

void setup() {
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn(); // Start the receiver

}


void loop() {
  //if received an IR signal
  if (irrecv.decode(&results)) {
    translateIR();
    // receive the next value
    irrecv.resume();
  }
}
void translateIR() {
  //check if power button is being pressed
  if(results.value == 16753245){
    Serial.println("Power");
  }
} 
