/*
Name:		Menu.cpp
Created:	1/7/2017 7:49:54 PM
Author:		beefviper
*/

#include "Menu.h"

void Cursor::draw(U8G2_ST7920_128X64_1_6800 &screen) {
	selectGame = selectGame % 3;
	screen.drawStr(18, ((selectGame + 1) * 10) + 10 + 4, "*");
}

void menuAttract::draw(U8G2_ST7920_128X64_1_6800 &screen) {
		screen.drawStr(20, 14, "Pick Game:");
		screen.drawStr(25, 24, "Snake");
		screen.drawStr(25, 34, "Missile");
		screen.drawStr(25, 44, "Breakout");
}

Menu::Menu() {

}

Menu::~Menu() {

}

void Menu::logic(Joystick &joystick, Speaker &speaker) {
	if (joystick.up()) { selectGame--; if (selectGame == -1) { selectGame = 2; } }
	if (joystick.down()) { selectGame++; }
	selectGame = selectGame % 3;
	if (joystick.button()) { currentGame = selectGame; }
}

void Menu::draw(U8G2_ST7920_128X64_1_6800 &screen) {
	cursor.draw(screen);
	attract.draw(screen);
}
