#include "RangeRover.h"
#include <iostream>
#include <cstring>
#include "Weather.h"

using namespace std;

RangeRover::RangeRover()
{
	fuelCapacity = 40;
	fuelConsumption = 7;
	AvgSpeed[SUNNY] = 120;
	AvgSpeed[RAIN] = 100;
	AvgSpeed[SNOW] = 80;

	strcpy(name, "RangeRover");
}
float RangeRover::computeRaceTime(unsigned int circuitLength, Weather condition,bool &x)
{
	float rezistance = fuelCapacity / fuelConsumption;
	if (rezistance * AvgSpeed[condition] > circuitLength)
		x = true;

	return (circuitLength / AvgSpeed[condition]);

}
char* RangeRover::getName()
{
	return name;
}
void RangeRover::printSpecs()
{
	cout << fuelCapacity << " " << fuelConsumption << " " << AvgSpeed[SUNNY] << endl;
}