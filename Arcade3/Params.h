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
	int x;
	int y;
};

class ScreenParams {
	public:
		static int data1Pin;
		static int data2Pin;
		static int data3Pin;
		static int data4Pin;
		static int data5Pin;
		static int data6Pin;
		static int data7Pin;
		static int data8Pin;
		static int enablePin;
		static int commandPin;
		static int resetPin;
};

class JoystickParams {
	public:
		static int xPin;
		static int yPin;
		static int bPin;
};

class SpeakerParams {
	public:
		enum Type { Active, Passive };
		static int sPin;
		static Type sType;
};

class RanNumGenParams {
	public:
		static int fPin;
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
	static const int screenScale = 4;
	static const int screenWidth = 128;
	static const int screenHeight = 64;
	static const int screenXMiddle = screenWidth / 2;
	static const int screenYMiddle = screenHeight / 2;
	static const int screenColumns = screenWidth / screenScale;
	static const int screenRows = screenHeight / screenScale;

	// Game variables
	static const int frameSkip = 1;

	static int frameLimit;
	static int score;
	static bool buttonState;
	static bool gameOver;
	static bool firstGame;
};
