#pragma once
#include "Car.h"

class RangeRover : public Car
{
public:
	RangeRover();
	float computeRaceTime(unsigned int circuitLength, Weather condition,bool& x);
	char* getName();
	void printSpecs();
};