/*
Name:		Snake.cpp
Created:	1/7/2017 7:49:54 PM
Author:		beefviper
*/

#include "Snake.h"

Body::Body() {
	reset();
}

Body::~Body() {

}

void Body::reset() {
	velocityX = 0;
	velocityY = -1;

	length = 0;

	position[0].x = screenColumns / 2 * screenScale;
	position[0].y = screenRows / 2 * screenScale;
}

void Body::grow() {
	if (length < (maxLength - 2)) {
		length++;
	}
}

void Body::move() {
	for (byte i = length; i >= 0; i--) {
		position[i + 1].x = position[i].x;
		position[i + 1].y = position[i].y;
	}

	position[0].x = position[0].x + (velocityX * screenScale);
	position[0].y = position[0].y + (velocityY * screenScale);
}

bool Body::collide() {
	if (position[0].x < 0 || position[0].x > 127 || position[0].y < 0 || position[0].y > 63) {
		return true;
	}

	for (byte i = 1; i <= length; i++) {
		if ((position[0].x == position[i].x) && (position[0].y == position[i].y)) {
			return true;
		}
	}

	return false;
}

bool Body::eat(Food &f) {
	if ((position[0].x == f.position.x) && (position[0].y == f.position.y)) {
		return true;
	}
	else {
		return false;
	}
}

void Body::draw(U8G2_ST7920_128X64_1_6800 &screen) {
	if (!gameOver) {
		for (byte i = length; i >= 0; i--) {
			screen.drawBox(position[i].x, position[i].y, screenScale, screenScale);
		}
	}
}

void Body::direction(Direction d) {
	if ((d == Up) && (velocityY == 0)) {
		up();
	}
	else if ((d == Down) && (velocityY == 0)) {
		down();
	}
	else if ((d == Left) && (velocityX == 0)) {
		left();
	}
	else if ((d == Right) && (velocityX == 0)) {
		right();
	}
}

Food::Food() {

}

Food::~Food() {

}

void Food::place() {
	position.x = random(screenColumns) * screenScale;
	position.y = random(screenRows)    * screenScale;
}

void Food::draw(U8G2_ST7920_128X64_1_6800 &screen) {
	if (!gameOver) {
		screen.drawBox(position.x, position.y, screenScale, screenScale);
	}
}

void sAttract::draw(U8G2_ST7920_128X64_1_6800 &screen) {
	if (gameOver) {
		if (!firstGame) {
			screen.drawStr(40, 14, "Game Over");
			screen.drawStr(40, 54, "Score:");
			screen.setCursor(75, 54);
			screen.print(score);
		}
		screen.drawStr(50, 24, "Snake");
		screen.drawStr(34, 34, "Press Button");
	}
}

void Snake::draw(U8G2_ST7920_128X64_1_6800 &screen) {
	body.draw(screen);
	food.draw(screen);
	attract.draw(screen);
}

void Snake::logic(Joystick &joystick, Speaker &speaker) {
	if (!gameOver) {
		frameLimit--;
		if (frameLimit < 1) {
			frameLimit = frameSkip;

			body.direction(joystick.direction());
			body.move();

			if (body.collide()) {
				gameOver = true;
				speaker.beep(100);
			}

			if (body.eat(food)) {
				body.grow();
				food.place();
				score++;
				speaker.beep(50);
			}
		}
	}
	else {
		if (joystick.button()) {
			gameOver = false;
			firstGame = false;
			body.reset();
			score = 0;
			speaker.beep(100);
			food.place();
		}
	}
}