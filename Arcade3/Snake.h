/*
Name:		Snake.h
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

class Food;
class Snake;

class Body : public Variables {
	public:
		Body();
		~Body();

		int velocityX;
		int velocityY;
		int length;

		static const int maxLength = 100;

		D2Point position[maxLength];

		void reset();
		void grow();
		void move();
		bool collide();
		bool eat(Food &f);
		void draw(U8G2_ST7920_128X64_1_6800 &screen);

		void left() { velocityX = -1; velocityY = 0; };
		void right() { velocityX = 1; velocityY = 0; };
		void up() { velocityX = 0; velocityY = -1; };
		void down() { velocityX = 0; velocityY = 1; };
		void direction(Direction d);

	private:

};

class Food : public Variables {
	public:
		Food();
		~Food();

		D2Point position;

		void place();
		void draw(U8G2_ST7920_128X64_1_6800 &screen);

	private:

};

class sAttract : public Variables {
	public:
		void draw(U8G2_ST7920_128X64_1_6800 &screen);
};

class Snake : public Variables {
	public:
		Snake() {  };
		~Snake() {  };

		Body body;
		Food food;
		sAttract attract;

		void draw(U8G2_ST7920_128X64_1_6800 &screen);
		void logic(Joystick &joystick, Speaker &speaker);
};
