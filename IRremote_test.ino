#include <IRremote.hpp>
#define IR_RECEIVE_PIN 6

void setup() {
  Serial.begin(9600);

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  
  Serial.println("IR Receiver Ready");
}

void loop() {
  if (IrReceiver.decode()) {
     byte command = IrReceiver.decodedIRData.command ;
     Serial.print("comand: ");
     Serial.println(command); 
// 0 = 22, 1 = 12, 2 = 24, 3 = 94, 4 = 8, 5 = 28, 6 = 90, 7 = 66, 8 = 82, 9 = 74
 // these are what i've tested with a remote; may vary between remotes   

    IrReceiver.resume();
  }
}

