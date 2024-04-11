#include "Seat.h"
#include <iostream>
#include <cstring>
#include "Weather.h"

using namespace std;

Seat::Seat()
{
	fuelCapacity = 60;
	fuelConsumption = 8;
	AvgSpeed[SUNNY] = 140;
	AvgSpeed[RAIN] = 120;
	AvgSpeed[SNOW] = 70;
	strcpy(name, "Seat");
}
float Seat::computeRaceTime(unsigned int circuitLength, Weather condition, bool& x)
{
	float rezistance = fuelCapacity / fuelConsumption;
	if (rezistance * AvgSpeed[condition] > circuitLength)
		x = 1;

	return circuitLength / AvgSpeed[condition];

}
char* Seat::getName()
{
	return name;
}
void Seat::printSpecs()
{
	cout << fuelCapacity << " " << fuelConsumption << " " << AvgSpeed[SUNNY] << endl;
}