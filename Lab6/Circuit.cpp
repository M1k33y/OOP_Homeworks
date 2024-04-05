#include "Circuit.h"
#include <iostream>
using namespace std;

Circuit::Circuit() 
{
	nrCars = 0;
	length = 0;
	condition = SUNNY;
	for (int i = 0; i < 100; ++i) 
	{
		cars[i] = NULL;
		finishTime[i]=0;
		finish[i]=0;
	}
	
}
void Circuit::SetLength(unsigned int length)
{
	this->length = length;
}
void Circuit::SetWeather(Weather weather)
{
	this->condition = weather;
}
void Circuit::AddCar(Car* car)
{
	cars[nrCars++] = car;
}
void Circuit::Race()
{
	
	for (int i = 0; i < nrCars; i++)
	{
		bool x = false;
		finishTime[i] = cars[i]->computeRaceTime(length, condition, x);
		finish[i] = x;

	}
}
void Circuit::ShowFinalRanks()
{
	cout << "Clasamentul: ";
	for (int i = 0; i < nrCars; i++)
		if (finish[i])
			cout << cars[i]->getName() << " cu timpul de " << finishTime[i] << " secunde" << endl;
}
void Circuit::ShowWhoDidNotFinish()
{
	cout << "Masinile care nu au terminat cursa sunt: ";
	for (int i = 0; i < nrCars; i++)
		if (!finish[i])
			cout << cars[i]->getName()<<endl;
}