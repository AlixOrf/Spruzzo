#include <IRremote.hpp>
 
#define PIN_IRREMOTE_RECV 9
 
IRrecv irrecv(PIN_IRREMOTE_RECV);
IRData results;
 
void setup() {
  Serial.begin(9600); // Start Serial communication
  irrecv.begin(PIN_IRREMOTE_RECV, ENABLE_LED_FEEDBACK); // Initialize IR receiver
  Serial.println("Ready to receive IR signals...");
}
 
void loop() {
  if (irrecv.decode()) {
    results = irrecv.decodedIRData;
    if (results.command != 0xFFFFFFFF) { // Ignore repeats
      Serial.print("Key Code: 0x");
      Serial.println(results.command, HEX);
    }
    irrecv.resume(); // Prepare to receive the next signal
  }
  delay(100);
}