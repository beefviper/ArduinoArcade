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
	if (currentGame == 3) { menu.draw(screen); }
	if (currentGame == 0) { snake.draw(screen); }
	if (currentGame == 1) { missile.draw(screen); }
	if (currentGame == 2) { breakout.draw(screen); }
}

void Game::logic(Joystick &joystick, Speaker &speaker) {
	if (currentGame == 3) { menu.logic(joystick, speaker); }
	if (currentGame == 0) { snake.logic(joystick, speaker); }
	if (currentGame == 1) { missile.logic(joystick, speaker); }
	if (currentGame == 2) { breakout.logic(joystick, speaker); }
}