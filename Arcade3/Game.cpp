/*
Name:		Game.cpp
Created:	1/7/2017 7:49:54 PM
Author:		beefviper
*/

#include "Game.h"

Game::Game() {

}


Game::~Game() {

}

void Game::draw(U8G2_ST7920_128X64_1_6800 &screen) {
	snake.draw(screen);
	//missile.draw(screen);
	//breakout.draw(screen);
}

void Game::logic(Joystick &joystick, Speaker &speaker) {
	snake.logic(joystick, speaker);
	//missile.logic(joystick, speaker);
	//breakout.logic(joystick, speaker);
}