#pragma once
#include "Car.h"

class Volvo : public Car
{
public:
	Volvo();
	float computeRaceTime(unsigned int circuitLength, Weather condition, bool& x);
	char* getName();
	void printSpecs();
};