/*
Name:		Arcade.cpp
Created:	1/7/2017 7:49:54 PM
Author:		beefviper
*/

#include "Arcade.h"

Arcade::Arcade() {

}

Arcade::Arcade(HardwareParams &hwp) :
	hardware(hwp) {

}

Arcade::~Arcade() {

}

int Arcade::init() {
	hardware.screen.begin();
	hardware.rng.setSeed();
}

int Arcade::draw() {
	hardware.screen.firstPage();
	do {
		// all graphics commands have to appear within the loop body.
		// set font 
		hardware.screen.setFont(u8g2_font_6x12_tf);
		// draw graphics
		software.draw(hardware.screen);

	} while (hardware.screen.nextPage());
}

int Arcade::input() {
	hardware.joystick.update();
}

int Arcade::logic() {
	software.logic(hardware.joystick, hardware.speaker);
}
