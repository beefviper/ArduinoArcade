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

int ScreenParams::data1Pin   =  8;
int ScreenParams::data2Pin   =  9;
int ScreenParams::data3Pin   = 10;
int ScreenParams::data4Pin   = 12;
int ScreenParams::data5Pin   =  4;
int ScreenParams::data6Pin   =  5;
int ScreenParams::data7Pin   =  6;
int ScreenParams::data8Pin   =  7;
int ScreenParams::enablePin  = 18;
int ScreenParams::commandPin = 17;
int ScreenParams::resetPin   = 15;

int JoystickParams::xPin  = 16;
int JoystickParams::yPin  = 19;
int JoystickParams::bPin  =  2;

#define SpkrType SpeakerParams::Type 
int     SpeakerParams::sPin   = 11;
SpkrType SpeakerParams::sType  = SpeakerParams::Passive;

int RanNumGenParams::fPin = 14;

ScreenParams    HardwareParams::Screen    = ScreenParams();
JoystickParams  HardwareParams::Joystick  = JoystickParams();
SpeakerParams   HardwareParams::Speaker   = SpeakerParams();
RanNumGenParams HardwareParams::RanNumGen = RanNumGenParams();

HardwareParams hardwareparams;

bool Variables::gameOver = true;
bool Variables::firstGame = true;
int Variables::score = 0;
int Variables::frameLimit = Variables::frameSkip;

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
