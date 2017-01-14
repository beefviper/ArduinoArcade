/*
Name:		Breakout.cpp
Created:	1/7/2017 7:49:54 PM
Author:		beefviper
*/

#include "Breakout.h"

Paddle::Paddle() {
	position.x = screenXMiddle;
	position.y = 56;
	size.x = 20;
	size.y = 5;
}

void Paddle::draw(U8G2_ST7920_128X64_1_6800 &screen) {
	if (!gameOver) {
		screen.drawBox(position.x-size.x/2, position.y, size.x, size.y);
	}
}

Block::Block() {
	reset();
}

void Block::reset() {
	size.x = 14;
	size.y = 7;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			position[j + i*columns].x = j * size.x + size.x;
			position[j + i*columns].y = i * size.y;
			enabled[j + i*columns] = true;
		}
	}
}

void Block::draw(U8G2_ST7920_128X64_1_6800 &screen) {
	if (!gameOver) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (enabled[j+i*columns]) {
					screen.drawBox(position[j + i*columns].x + 1, position[j + i*columns].y + 1, size.x - 1, size.y - 1);
				}
			}
		}
	}
}

Ball::Ball() {
	reset();
}

void Ball::reset() {
	radius = 2;
	velocity.x = 2;
	velocity.y = -2;
	position.x = screenXMiddle;
	position.y = 52;
}

void Ball::move() {
	position.x += velocity.x;
	position.y += velocity.y;
}

void Ball::collide(Paddle &paddle, Block &block, Speaker &speaker) {
	if (position.x > 127 - radius && velocity.x == 2) {
		velocity.x = -2;
	}

	if (position.x < 0 + radius && velocity.x == -2) {
		velocity.x = 2;
	}
	
	if (position.y >  paddle.position.y - radius - 1 &&
		position.y <  paddle.position.y &&
		position.x > (paddle.position.x - (paddle.size.x / 2)) &&
		position.x < (paddle.position.x + (paddle.size.x / 2)) &&
		velocity.y ==  2) {

		velocity.y = -2;
	}
	
	if (position.y < 0 + radius && velocity.y == -2) {
		velocity.y = 2;
	}

	if (position.y > 63 && velocity.y == 2) {
		gameOver = true;
		reset();
	}

	for (int i = 0; i < block.rows; i++) {
		for (int j = 0; j < block.columns; j++) {
			//block.position[j + i*block.columns].x;
			//block.position[j + i*block.columns].y;
			if (block.enabled[j + i*block.columns]) {
				if ((position.y < block.position[j + i*block.columns].y + block.size.y + radius) &&
					(position.y > block.position[j + i*block.columns].y + block.size.y - 3) &&
					(position.x > block.position[j + i*block.columns].x) &&
					(position.x < block.position[j + i*block.columns].x + block.size.x) &&
					(velocity.y == -2)) {
					block.enabled[j + i*block.columns] = false;
					score++;
					speaker.beep(50);
					velocity.y = 2;
				}
				else if ((position.y > block.position[j + i*block.columns].y - radius) &&
					(position.y < block.position[j + i*block.columns].y + block.size.y + 3) &&
					(position.x > block.position[j + i*block.columns].x) &&
					(position.x < block.position[j + i*block.columns].x + block.size.x) &&
					(velocity.y == 2)) {
					block.enabled[j + i*block.columns] = false;
					score++;
					speaker.beep(50);
					velocity.y = -2;
				}
				else if ((position.x < block.position[j + i*block.columns].x + block.size.x + radius) &&
					(position.x > block.position[j + i*block.columns].x + block.size.x - 3) &&
					(position.y > block.position[j + i*block.columns].y) &&
					(position.y < block.position[j + i*block.columns].y + block.size.y) &&
					(velocity.x == -2)) {
					block.enabled[j + i*block.columns] = false;
					score++;
					speaker.beep(50);
					velocity.x = 2;
				}
				else if ((position.x > block.position[j + i*block.columns].x - radius) &&
					(position.x < block.position[j + i*block.columns].x + block.size.x + 3) &&
					(position.y > block.position[j + i*block.columns].y) &&
					(position.y < block.position[j + i*block.columns].y + block.size.y) &&
					(velocity.x == 2)) {
					block.enabled[j + i*block.columns] = false;
					score++;
					speaker.beep(50);
					velocity.x = -2;
				}
			}
		}
	}

}

void Ball::draw(U8G2_ST7920_128X64_1_6800 &screen) {
	if (!gameOver) {
		screen.drawDisc(position.x, position.y, radius);
	}
}

void bAttract::draw(U8G2_ST7920_128X64_1_6800 &screen) {
	if (gameOver) {
		if (!firstGame) {
			screen.drawStr(40, 14, "Game Over");
			screen.drawStr(40, 54, "Score:");
			screen.setCursor(75, 54);
			screen.print(score);
		}
		screen.drawStr(40, 24, "Breakout");
		screen.drawStr(34, 34, "Press Button");
	}
}

Breakout::Breakout() {

}

Breakout::~Breakout() {

}

void Breakout::draw(U8G2_ST7920_128X64_1_6800 &screen) {
	paddle.draw(screen);
	block.draw(screen);
	ball.draw(screen);
	battract.draw(screen);
}

void Breakout::logic(Joystick &joystick, Speaker &speaker) {
	if (!gameOver) {
		frameLimit--;
		if (frameLimit < 1) {
			frameLimit = frameSkip;

			paddle.position.x = map(joystick.getx(), 63, 959, 0+paddle.size.x/2, 127-paddle.size.x/2);

			ball.move();
			ball.collide(paddle, block, speaker);
		}
	}
	else {
		if (joystick.button()) {
			gameOver = false;
			firstGame = false;
			score = 0;
			block.reset();
			ball.reset();
			speaker.beep(100);
			if (!firstGame) {
				selectGame = 3;
				currentGame = 3;
			}
		}
	}
}
