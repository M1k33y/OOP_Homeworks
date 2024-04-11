#include "BMW.h"
#include <iostream>
#include <cstring>
#include "Weather.h"

using namespace std;

BMW::BMW()
{
	fuelCapacity = 50;
	fuelConsumption = 6;
	AvgSpeed[SUNNY] = 160;
	AvgSpeed[RAIN] = 140;
	AvgSpeed[SNOW] = 100;
	strcpy(name, "BMW");
}
float BMW::computeRaceTime(unsigned int circuitLength, Weather condition, bool& x)
{
	float rezistance = fuelCapacity / fuelConsumption;
	if (rezistance * AvgSpeed[condition] > circuitLength)
		x = 1;

	return circuitLength / AvgSpeed[condition];

}
char* BMW::getName()
{
	return name;
}
void BMW::printSpecs()
{
	cout << fuelCapacity << " " << fuelConsumption << " " << AvgSpeed[SUNNY] << endl;
}