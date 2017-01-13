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
		Joystick(int xP, int yP, int bP);
		Joystick(JoystickParams &jsp);
		~Joystick();

		void init(int xP, int yP, int bp);

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
		int xPin;
		int yPin;
		int bPin;

		int x;
		int y;
		int b;

		void setx();
		void sety();
		void setb();
};
