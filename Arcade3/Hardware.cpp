/*
Name:		Hardware.cpp
Created:	1/7/2017 7:49:54 PM
Author:		beefviper
*/

#include "Hardware.h"

Hardware::Hardware() :
	screen(U8G2_R2, 8, 9, 10, 11, 4, 5, 6, 7, 18, U8X8_PIN_NONE, 17, 15),
	joystick(xAxisPin, yAxisPin, buttonPin),
	speaker(speakerPin, speakerType),
	rng(floatingPin) {

}

Hardware::Hardware(HardwareParams &hwp) :
	screen(U8G2_R2, hwp.Screen.data1Pin, hwp.Screen.data2Pin, hwp.Screen.data3Pin, hwp.Screen.data4Pin, 
		hwp.Screen.data5Pin, hwp.Screen.data6Pin, hwp.Screen.data7Pin, hwp.Screen.data8Pin, 
		hwp.Screen.enablePin, U8X8_PIN_NONE, hwp.Screen.commandPin, hwp.Screen.resetPin) {

		if (hwp.joystickEnable) {
			joystick.init(hwp.Joystick.xPin, hwp.Joystick.yPin, hwp.Joystick.bPin);
		}

		if (hwp.speakerEnable) {
			speaker.init(hwp.Speaker.sPin, hwp.Speaker.sType);
		}
	
		if (hwp.rngEnable) {
			rng.init(hwp.RanNumGen.fPin);
		}
}

Hardware::~Hardware()
{

}

void Hardware::draw() {

}
