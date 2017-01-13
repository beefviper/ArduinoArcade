/*
Name:		RandomNumberGenerator.h
Created:	1/7/2017 7:49:54 PM
Author:		beefviper
*/

#pragma once

class RanNumGen {
	public:
		RanNumGen() {  }
		RanNumGen(int fP) { init(fP); }
		RanNumGen(RanNumGenParams &rngp) { init(rngp.fPin); }
		~RanNumGen() {  }

		void init(int fP) { fPin = fP;  setSeed(); }
		void setSeed() { randomSeed(analogRead(fPin)); }

	private:
		int fPin;
};
