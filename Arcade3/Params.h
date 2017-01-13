/*
Name:		Params.h
Created:	1/7/2017 7:49:54 PM
Author:		beefviper
*/

#pragma once

#include <Arduino.h>

enum Direction { Up, Down, Left, Right, None };

class D2Point {
public:
	byte x;
	byte y;
};

class ScreenParams {
	public:
		static byte data1Pin;
		static byte data2Pin;
		static byte data3Pin;
		static byte data4Pin;
		static byte data5Pin;
		static byte data6Pin;
		static byte data7Pin;
		static byte data8Pin;
		static byte enablePin;
		static byte commandPin;
		static byte resetPin;
};

class JoystickParams {
	public:
		static byte xPin;
		static byte yPin;
		static byte bPin;
};

class SpeakerParams {
	public:
		enum Type { Active, Passive };
		static byte sPin;
		static Type sType;
};

class RanNumGenParams {
	public:
		static byte fPin;
};

class HardwareParams {
	public:
		static bool screenEnable;
		static bool joystickEnable;
		static bool speakerEnable;
		static bool rngEnable;

		static ScreenParams Screen;
		static JoystickParams Joystick;
		static SpeakerParams Speaker;
		static RanNumGenParams RanNumGen;
};

class SoftwareParams {
	public:

};

class Variables {
public:
	// Hardware constants
	static const byte screenScale = 4;
	static const byte screenWidth = 128;
	static const byte screenHeight = 64;
	static const byte screenXMiddle = screenWidth / 2;
	static const byte screenYMiddle = screenHeight / 2;
	static const byte screenColumns = screenWidth / screenScale;
	static const byte screenRows = screenHeight / screenScale;

	// Game variables
	static const int frameSkip = 1;

	static byte frameLimit;
	static byte score;
	static bool buttonState;
	static bool gameOver;
	static bool firstGame;
};
