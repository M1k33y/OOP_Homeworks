#pragma once
#include "Car.h"

class BMW : public Car
{
public:
	BMW();
	float computeRaceTime(unsigned int circuitLength, Weather condition, bool& x);
	char* getName();
	void printSpecs();
};