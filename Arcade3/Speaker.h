/*
Name:		Speaker.h
Created:	1/7/2017 7:49:54 PM
Author:		beefviper
*/

#pragma once

#include <Arduino.h>

#include "Params.h"

class Speaker {
	public:
		Speaker();
		Speaker(int sP, SpeakerParams::Type sT);
		Speaker(SpeakerParams &spp);
		~Speaker();

		void init(int sP, SpeakerParams::Type sT);

		void beep(int timeout);

	private:
		int sPin;
		SpeakerParams::Type sType;
};
