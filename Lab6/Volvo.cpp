#include "Volvo.h"
#include <iostream>
#include <cstring>
#include "Weather.h"

using namespace std;

Volvo::Volvo()
{
	fuelCapacity = 55;
	fuelConsumption = 8;
	AvgSpeed[SUNNY] = 140;
	AvgSpeed[RAIN] = 115;
	AvgSpeed[SNOW] = 70;
	strcpy(name, "Volvo");
}
float Volvo::computeRaceTime(unsigned int circuitLength, Weather condition, bool& x)
{
	float rezistance = fuelCapacity / fuelConsumption;
	if (rezistance * AvgSpeed[condition] > circuitLength)
		x = 1;

	return circuitLength / AvgSpeed[condition];

}
char* Volvo::getName()
{
	return name;
}
void Volvo::printSpecs()
{
	cout << fuelCapacity << " " << fuelConsumption << " " << AvgSpeed[SUNNY] << endl;
}