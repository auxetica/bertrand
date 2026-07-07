#include "MorseEncoder.h"

MorseEncoder morseL(13);      // Initialize with the desired pin for Light

void setup() {
  Serial.begin(9600);
  Serial.println("Terminal ready");
  morseL.beginLight(15);      // [LIGHT] Initialize WPM (word per minute) rate
}

void loop() {
  String message = "";
  if (Serial.available()>0){
    String userInput = Serial.readStringUntil('\n');

    userInput.trim();
    message = userInput;
  }
  // String message = "sos";
  morseL.print(message);   // [LIGHT] Broadcast encoded light
  delay(2000);
  // morseL.print(123);       // [LIGHT] its inherits from Print class, so you can encode various types of data
  // delay(2000);
}