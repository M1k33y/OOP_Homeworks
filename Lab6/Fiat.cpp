#include "Fiat.h"
#include <iostream>
#include <cstring>
#include "Weather.h"

using namespace std;

Fiat::Fiat()
{
	fuelCapacity = 35;
	fuelConsumption = 6;
	AvgSpeed[SUNNY] = 100;
	AvgSpeed[RAIN] = 90;
	AvgSpeed[SNOW] = 80;
	strcpy(name, "Fiat");
}
float Fiat::computeRaceTime(unsigned int circuitLength, Weather condition, bool& x)
{
	float rezistance = fuelCapacity / fuelConsumption;
	if (rezistance * AvgSpeed[condition] > circuitLength)
		x = 1;

	return circuitLength / AvgSpeed[condition];

}
char* Fiat::getName()
{
	return name;
}
void Fiat::printSpecs()
{
	cout << fuelCapacity << " " << fuelConsumption << " " << AvgSpeed[SUNNY] << endl;
}