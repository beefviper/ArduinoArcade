/*
Name:		Missle.cpp
Created:	1/7/2017 7:49:54 PM
Author:		beefviper
*/

#include "Missile.h"

void Base::draw(U8G2_ST7920_128X64_1_6800 &screen) {
	if (!gameOver) {
		screen.drawBox(screenXMiddle - 2, screenHeight - 6, 4, 6);
		screen.drawLine(crossHair.x - 2, crossHair.y, crossHair.x + 2, crossHair.y);
		screen.drawLine(crossHair.x, crossHair.y - 2, crossHair.x, crossHair.y + 2);
	}
}

Enemy::Enemy() {
	reset();
}

void Enemy::reset() {
	origin.x = random(screenWidth);
	origin.y = 0;
	slope.x = 1;
	slope.y = random(1, 4);
	end.x = origin.x + slope.x;
	end.y = origin.y + slope.y;
	speedLimit = 3;
	speed = speedLimit;
}

void Enemy::move() {
	speed--;
	if ( speed < 0 ) {
		speed = speedLimit;
		if (end.y < 63) {
			end.x += slope.x;
			end.y += slope.y;
		}
		else {
			gameOver = true;
		}

		if (end.x < 0 || end.x > 127) {
			reset();
		}
	}
}

void Enemy::draw(U8G2_ST7920_128X64_1_6800 &screen) {
	if (!gameOver) {
		screen.drawLine(origin.x, origin.y, end.x, end.y);
	}
}

Bullet::Bullet() {
	reset();
}

void Bullet::reset() {
	size = 1;
	exploding = false;
	speedLimit = 3;
	speed = speedLimit;
	growing = true;
}

void Bullet::explode() {
	speed--;
	if (speed < 0) {
		speed = speedLimit;

		if (exploding) {
			if (size > 5) { growing = false; }
			if (growing) {
				size += 2;
			}
			else {
				size -= 2;
			}
			if (size < 1) {
				exploding = false;
				reset();
			}
		}
	}
}

void Bullet::draw(U8G2_ST7920_128X64_1_6800 &screen) {
	if (!gameOver) {
		if (exploding) {
			screen.drawCircle(position.x, position.y, size);
		}
	}
}

void mAttract::draw(U8G2_ST7920_128X64_1_6800 &screen) {
	if (gameOver) {
		if (!firstGame) {
			screen.drawStr(40, 14, "Game Over");
			screen.drawStr(40, 54, "Score:");
			screen.setCursor(75, 54);
			screen.print(score);
		}
		screen.drawStr(46, 24, "Missile");
		screen.drawStr(34, 34, "Press Button");
	}
}

void Missile::draw(U8G2_ST7920_128X64_1_6800 &screen) {
	base.draw(screen);
	enemy.draw(screen);
	bullet.draw(screen);
	attract.draw(screen);
}

void Missile::logic(Joystick &joystick, Speaker &speaker) {
	if (!gameOver) {
		frameLimit--;
		if (frameLimit < 1) {
			frameLimit = frameSkip;

			//base.crossHair.x = map(joystick.getx(), 0, 1023, 0, 127);
			//base.crossHair.y = map(joystick.gety(), 0, 1023, 0, 63);

			int stepping = 2;

			if (joystick.up() && joystick.left()) {
				base.crossHair.y -= stepping;
				base.crossHair.x -= stepping;
			} else if (joystick.up() && joystick.right() ) {
				base.crossHair.y -= stepping;
				base.crossHair.x += stepping;
			} else if (joystick.down() && joystick.left()) {
				base.crossHair.y += stepping;
				base.crossHair.x -= stepping;
			} else if (joystick.down() && joystick.right()) {
				base.crossHair.y += stepping;
				base.crossHair.x += stepping;
			} else if (joystick.up()) {
				base.crossHair.y -= stepping;
			} else if (joystick.down()) {
				base.crossHair.y += stepping;
			} else if (joystick.left()) {
				base.crossHair.x -= stepping;
			} else if (joystick.right()) {
				base.crossHair.x += stepping;
			}

			if (joystick.button()) {
				if (!bullet.exploding) {
					bullet.position.x = base.crossHair.x;
					bullet.position.y = base.crossHair.y;
					bullet.exploding = true;
				}
			}

			enemy.move();
			bullet.explode();

			if ( (enemy.end.x > bullet.position.x - bullet.size) && (enemy.end.x < bullet.position.x + bullet.size) &&
				 (enemy.end.y > bullet.position.y - bullet.size) && (enemy.end.y < bullet.position.y + bullet.size)) {
				enemy.reset();
				bullet.reset();
				score++;
				speaker.beep(50);
			}


		}
	}
	else {
		if (joystick.button()) {
			gameOver = false;
			firstGame = false;
			enemy.reset();
			score = 0;
			speaker.beep(100);
			if (!firstGame) {
				selectGame = 3;
				currentGame = 3;
			}
		}
	}

}
