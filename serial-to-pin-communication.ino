/*
Usage:
- <01-123> sends 123 to pin #1
- <09-999> sends 999 to pin #9
- <06-003> sends 3 to pin #6
- <08-048> sends 48 to pin #8
- <11-421> sends 48 to pin #8

Warnings:
- Doesn't support numbers over integer limit, 32767
- Doesn't support negative values but you can set your own "zero". For example you can treat numbers below 100 as negative.
*/

#define maxSignalDigit 3 // Like 001 or 180 or 99. You can change this up to 5, because of int limit.
#define maxPinDigit 2    // Like 02 or 09 or 13 You can change this up to 5, because of int limit.

int controlledPin, signalValue, currentDigitCount, currentPinCount;
boolean waitingForPin;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing");
  
  
  Serial.println("Ready");
}

void loop() {
  if (Serial.available()) {
    char ch = Serial.read();
    
    //Send next read character to our reader
    serialCommunication(ch);
  }
}

void sendSignal(int pin, int signal) {
  Serial.print("Pin Number: ");
  Serial.print(pin);
  Serial.print(", Signal: ");
  Serial.println(signal);
  
  //DO WORK HERE
}

void serialCommunication(char ch) {
  if(ch == '<') {
    //Start listening for the command
    waitingForPin = true;
    
    currentDigitCount = 0;
    currentPinCount = 0;
    
    controlledPin = 0;
    signalValue = 0;
  } else if(ch == '>') {
    //End listening for the command
    sendSignal(controlledPin, signalValue);
  } else if(ch == '-') {
    //Stop listening for pin number
    waitingForPin = false;
  } else if(isDigit(ch)){
    if(waitingForPin == true) {
      //Set first coming digits before '-' as pin number.
      controlledPin += (pow(10, maxPinDigit - currentPinCount - 1) * (ch - '0')) + 0.5;
      currentPinCount++;
    } else {
      /* For command <01-456> it goes like this
      4 * 10 ^ (3 - 0 - 1) = 4 * 10 ^ 2 = 400
      5 * 10 ^ (3 - 1 - 1) = 5 * 10 ^ 1 = 50
      6 * 10 ^ (3 - 2 - 1) = 5 * 10 ^ 0 = 6
      400 + 50 + 6 = 456
      */
      signalValue += (pow(10, maxSignalDigit - currentDigitCount - 1) * (ch - '0')) + 0.5;
      currentDigitCount++;
    }
  }
}
