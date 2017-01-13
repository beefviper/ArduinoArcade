/*
Name:		Missle.h
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

class Base : public Variables{
	public:
		Base() { crossHair.x = screenXMiddle; crossHair.y = screenYMiddle; };
		~Base() {  };

		D2Point crossHair;

		void draw(U8G2_ST7920_128X64_1_6800 &screen);
};

class Enemy : public Variables {
	public:
		Enemy();
		~Enemy() {  };

		D2Point origin;
		D2Point end;
		D2Point slope;
		int speedLimit;
		int speed;

		void reset();
		void move();

		void draw(U8G2_ST7920_128X64_1_6800 &screen);
};

class Bullet : public Variables {
	public:
		Bullet();
		~Bullet() {  }

		D2Point position;
		int size;
		bool exploding;
		bool growing;
		int speedLimit;
		int speed;

		void reset();
		void explode();

		void draw(U8G2_ST7920_128X64_1_6800 &screen);
};

class mAttract : public Variables {
public:
	void draw(U8G2_ST7920_128X64_1_6800 &screen);
};

class Missile : public Variables {
	public:
		Missile() {  };
		~Missile() {  };

		Base base;
		Enemy enemy;
		Bullet bullet;
		mAttract attract;

		void draw(U8G2_ST7920_128X64_1_6800 &screen);
		void logic(Joystick &joystick, Speaker &speaker);
};
