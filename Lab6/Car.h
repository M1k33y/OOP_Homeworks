#pragma once
#include "Weather.h"
class Car
{
protected:
	//de facut cu float/double pt majoritatea valorilor
	int fuelCapacity;
	int fuelConsumption;
	int AvgSpeed[3]; //AvgSpeedSunny,AvgSpeedRain sau faci un mini vector cu 3 valori
	char name[50];
	
public:
	virtual float computeRaceTime(unsigned int circuitLength, Weather condition,bool& x) = 0;
	virtual char* getName()=0;

};