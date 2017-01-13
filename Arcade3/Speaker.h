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
		Speaker(byte sP, SpeakerParams::Type sT);
		Speaker(SpeakerParams &spp);
		~Speaker();

		void init(byte sP, SpeakerParams::Type sT);

		void beep(int timeout);

	private:
		byte sPin;
		SpeakerParams::Type sType;
};
