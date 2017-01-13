/*
Name:		Software.cpp
Created:	1/7/2017 7:49:54 PM
Author:		beefviper
*/

#include "Software.h"

Software::Software() {

}


Software::~Software() {

}

void Software::draw(U8G2_ST7920_128X64_1_6800 &screen) {
	game.draw(screen);
}

void Software::logic(Joystick &joystick, Speaker &speaker) {
	game.logic(joystick, speaker);
}
