/*
Name:		Arcade3.ino
Created:	1/7/2017 7:49:54 PM
Author:		beefviper
*/

#include <Arduino.h>

#include "Params.h"
#include "Arcade.h"

bool HardwareParams::screenEnable   = true;
bool HardwareParams::joystickEnable = true;
bool HardwareParams::speakerEnable  = true;
bool HardwareParams::rngEnable      = true;

byte ScreenParams::data1Pin   =  8;
byte ScreenParams::data2Pin   =  9;
byte ScreenParams::data3Pin   = 10;
byte ScreenParams::data4Pin   = 12;
byte ScreenParams::data5Pin   =  4;
byte ScreenParams::data6Pin   =  5;
byte ScreenParams::data7Pin   =  6;
byte ScreenParams::data8Pin   =  7;
byte ScreenParams::enablePin  = 18;
byte ScreenParams::commandPin = 17;
byte ScreenParams::resetPin   = 15;

byte JoystickParams::xPin  = 16;
byte JoystickParams::yPin  = 19;
byte JoystickParams::bPin  =  2;

#define SpkrType SpeakerParams::Type 
byte     SpeakerParams::sPin   = 11;
SpkrType SpeakerParams::sType  = SpeakerParams::Passive;

byte RanNumGenParams::fPin = 14;

ScreenParams    HardwareParams::Screen    = ScreenParams();
JoystickParams  HardwareParams::Joystick  = JoystickParams();
SpeakerParams   HardwareParams::Speaker   = SpeakerParams();
RanNumGenParams HardwareParams::RanNumGen = RanNumGenParams();

HardwareParams hardwareparams;

bool Variables::gameOver = true;
bool Variables::firstGame = true;
byte Variables::score = 0;
byte Variables::frameLimit = Variables::frameSkip;

Arcade arcade(hardwareparams);

// the setup function runs once when you press reset or power the board
void setup() {
	arcade.init();
}

// the loop function runs over and over again until power down or reset
void loop() {
	arcade.draw();
	arcade.input();
	arcade.logic();
	//arcade.hardware.joystick.print(); // debug
}
