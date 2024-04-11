#pragma once
#include "Car.h"

class Fiat : public Car
{
public:
	Fiat();
	float computeRaceTime(unsigned int circuitLength, Weather condition, bool& x);
	char* getName();
	void printSpecs();
};