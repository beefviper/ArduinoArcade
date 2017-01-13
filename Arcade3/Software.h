/*
Name:		Software.h
Created:	1/7/2017 7:49:54 PM
Author:		beefviper
*/

#pragma once

#include "Game.h"

class Software {
	public:
		Software();
		~Software();

		Game game;

		void draw(U8G2_ST7920_128X64_1_6800 &screen);
		void logic(Joystick &joystick, Speaker &speaker);
};
