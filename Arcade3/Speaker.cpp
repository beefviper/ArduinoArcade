/*
Name:		Speaker.cpp
Created:	1/7/2017 7:49:54 PM
Author:		beefviper
*/

#include "Speaker.h"

Speaker::Speaker() {

}

Speaker::Speaker(int sP, SpeakerParams::Type sT) {
	init(sP, sT);
}

Speaker::Speaker(SpeakerParams &ssp) {
	init(ssp.sPin, ssp.sType);
}

Speaker::~Speaker() {

}

void Speaker::init(int sP, SpeakerParams::Type sT) {
	sPin = sP;
	pinMode(sP, OUTPUT);
	sType = sT;
}

void Speaker::beep(int timeout) {
	if ( sType == SpeakerParams::Active ) {
		digitalWrite(sPin, HIGH);
		delay(timeout);
		digitalWrite(sPin, LOW);
	}
	else if ( sType == SpeakerParams::Passive ) {
		tone(sPin, 440, timeout);
	}
}
