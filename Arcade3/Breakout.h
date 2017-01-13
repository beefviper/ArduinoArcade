/*
Name:		Breakout.h
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

class Paddle : public Variables {
	public:
		Paddle();
		~Paddle() {  }
		
		D2Point position;
		D2Point size;

		void draw(U8G2_ST7920_128X64_1_6800 &screen);
};

class Block : public Variables {
	public:
		Block();
		~Block() {  }

		static const byte totalBlocks = 35;
		static const byte columns = 7;
		static const byte rows = 5;

		bool enabled[totalBlocks];
		D2Point position[totalBlocks];
		D2Point size;
		
		void reset();
		void draw(U8G2_ST7920_128X64_1_6800 &screen);
};


class Ball : public Variables {
	public:
		Ball();
		~Ball() {  }

		D2Point position;
		D2Point velocity;
		byte radius;

		void reset();
		void move();
		void collide(Paddle &paddle, Block &block, Speaker &speaker);
		void draw(U8G2_ST7920_128X64_1_6800 &screen);
};

class bAttract : public Variables {
public:
	void draw(U8G2_ST7920_128X64_1_6800 &screen);
};

class Breakout : public Variables {
	public:
		Breakout();
		~Breakout();

		Paddle paddle;
		Block block;
		Ball ball;
		bAttract battract;

		void draw(U8G2_ST7920_128X64_1_6800 &screen);
		void logic(Joystick &joystick, Speaker &speaker);
};

