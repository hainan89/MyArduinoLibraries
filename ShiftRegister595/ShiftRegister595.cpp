#include "ShiftRegister595.h"

//<<constructor>>
ShiftRegister595::ShiftRegister595( byte userLatchPin, byte userClockPin, byte userDataPin)
{
  latchPin	= userLatchPin;
  clockPin	= userClockPin;
  dataPin	= userDataPin;
  
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void ShiftRegister595::write(uint8_t dataCount, byte* out)
{
  digitalWrite(latchPin, LOW);
  for(int i = (dataCount - 1); i >= 0 ; i --)
  {
		shiftOut(dataPin, clockPin, MSBFIRST, out[i]);
  }
  digitalWrite(latchPin, HIGH);
}

//based on this code http://arduino.cc/en/Tutorial/ShftOut11
/*
void ShiftRegister595::shiftOut(byte out){
  bool pinState = false;
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, LOW);
  for (byte i=7; i>=0; i--)  {
    digitalWrite(clockPin, LOW);
    if ( out & (1<<i) ) {
      pinState= true;
    }
    else {	
      pinState= false;
    }
    digitalWrite(dataPin, pinState);
    digitalWrite(clockPin, HIGH);
    digitalWrite(dataPin, LOW);
  }
  digitalWrite(clockPin, LOW);
}*/
