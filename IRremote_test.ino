#include <IRremote.hpp>
#define IR_RECEIVE_PIN 6

void setup() {
  Serial.begin(9600);

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  
  Serial.println("IR Receiver Ready");
}

void loop() {
  if (IrReceiver.decode()) {

    Serial.print("Address: ");
    Serial.print(IrReceiver.decodedIRData.address, HEX);

    Serial.print("       Command: ");
    Serial.println(IrReceiver.decodedIRData.command, HEX);

    IrReceiver.resume();
  }
}
