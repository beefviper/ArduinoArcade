/*
Name:		Joystick.h
Created:	1/7/2017 7:49:54 PM
Author:		beefviper
*/

#pragma once

#include <Arduino.h>
#include "Params.h"

class Joystick {
	public:
		Joystick();
		Joystick(byte xP, byte yP, byte bP);
		Joystick(JoystickParams &jsp);
		~Joystick();

		void init(byte xP, byte yP, byte bp);

		int getx();
		int gety();
		int getb();

		bool button();
		bool up();
		bool down();
		bool left();
		bool right();
		Direction direction();

		void update();
		void print();

	private:
		byte xPin;
		byte yPin;
		byte bPin;

		int x;
		int y;
		int b;

		void setx();
		void sety();
		void setb();
};
