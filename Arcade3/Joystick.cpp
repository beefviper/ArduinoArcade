/*
Name:		Joystick.cpp
Created:	1/7/2017 7:49:54 PM
Author:		beefviper
*/

#include "Joystick.h"

Joystick::Joystick() {

}

Joystick::Joystick(byte xP, byte yP, byte bP) {
	init(xP, yP, bP);
}

Joystick::Joystick(JoystickParams &jsp) {
	init(jsp.xPin, jsp.yPin, jsp.bPin);
}

Joystick::~Joystick() {

}

void Joystick::init(byte xP, byte yP, byte bP) {
	xPin = xP;
	yPin = yP;
	bPin = bP;

	pinMode(xPin, INPUT);
	pinMode(yPin, INPUT);
	pinMode(bPin, INPUT_PULLUP);
}

int Joystick::getx() {
	return x;
}

int Joystick::gety() {
	return y;
}

int Joystick::getb() {
	return b;
}

void Joystick::setx() {
	x = analogRead(xPin);
}

void Joystick::sety() {
	y = analogRead(yPin);
}

void Joystick::setb() {
	b = !(digitalRead(bPin));
}

bool Joystick::button() {
	if (b) {
		return true;
	}
	else {
		return false;
	}
}

bool Joystick::up() {
	if (y < 255) {
		return true;
	}
	else {
		return false;
	}
}

bool Joystick::down() {
	if (y > 767) {
		return true;
	}
	else {
		return false;
	}
}

bool Joystick::left() {
	if (x < 255) {
		return true;
	}
	else {
		return false;
	}
}

bool Joystick::right() {
	if (x > 767) {
		return true;
	}
	else {
		return false;
	}
}

Direction Joystick::direction() {
	if (left()) {
		return Left;
	}
	else if (right()) {
		return Right;
	}
	else if (up()) {
		return Up;
	}
	else if (down()) {
		return Down;
	}
	else {
		return None;
	}
}

void Joystick::update() {
	setx();
	sety();
	setb();
}

void Joystick::print() {
	Serial.print("X: ");
	Serial.print(x);
	Serial.print(", ");
	Serial.print("Y: ");
	Serial.print(y);
	Serial.print(", ");
	Serial.print("B: ");
	Serial.println(b);
}
