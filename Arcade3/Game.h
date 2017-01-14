/*
Name:		Game.h
Created:	1/7/2017 7:49:54 PM
Author:		beefviper
*/

#pragma once

#include "Params.h"

#include "Joystick.h"
#include "Speaker.h"

#include "Menu.h"
#include "Snake.h"
#include "Missile.h"
#include "Breakout.h"

class Game : public Variables {
	public:
		Game();
		~Game();

		Menu menu;
		Snake snake;
		Missile missile;
		Breakout breakout;

		void draw(U8G2_ST7920_128X64_1_6800 &screen);
		void logic(Joystick &joystick, Speaker &speaker);
};
