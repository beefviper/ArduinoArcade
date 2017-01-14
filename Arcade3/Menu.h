/*
Name:		Menu.h
Created:	1/7/2017 7:49:54 PM
Author:		beefviper
*/

#pragma once

#include <Arduino.h>

#include <U8x8lib.h>
#include <U8g2lib.h>

#include "Params.h"

#include "Joystick.h"
#include "Speaker.h"

class Cursor : public Variables	{
	public:
		void draw(U8G2_ST7920_128X64_1_6800 &screen);
};

class menuAttract : public Variables {
	public:
		void draw(U8G2_ST7920_128X64_1_6800 &screen);
};

class Menu : public Variables {
	public:
		Menu();
		~Menu();

		Cursor cursor;
		menuAttract attract;

		void logic(Joystick &joystick, Speaker &speaker);
		void draw(U8G2_ST7920_128X64_1_6800 &screen);
};
