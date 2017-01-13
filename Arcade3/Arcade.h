/*
Name:		Arcade.h
Created:	1/7/2017 7:49:54 PM
Author:		beefviper
*/

#pragma once

#include "Params.h"
#include "Hardware.h"
#include "Software.h"

class Arcade {
	public:
		Arcade();
		Arcade(HardwareParams &hwp);
		~Arcade();

		Hardware hardware;
		Software software;

		int init();
		int draw();
		int input();
		int logic();
};

