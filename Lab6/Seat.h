#pragma once
#include "Car.h"

class Seat : public Car
{
public:
	Seat();
	float computeRaceTime(unsigned int circuitLength, Weather condition, bool& x);
	char* getName();
	void printSpecs();
};