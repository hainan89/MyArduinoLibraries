/*
||
|| @author Alexander Brevig
|| @version 1.0
||
*/

#ifndef SHIFTREGISTER595_H
#define SHIFTREGISTER595_H

#include "arduino.h"

class ShiftRegister595 {
	public:
		ShiftRegister595( byte userLatchPin, byte userClockPin, byte userDataPin );	
		void write(uint8_t dataCount, byte* out);
			
	private:
		//void shiftOut(byte out);
		byte latchPin;
		byte clockPin;
		byte dataPin;
};

#endif

/*
|| Changelog:
||
|| 1.0 2009-04-13 - Alexander Brevig : Initial Release
*/