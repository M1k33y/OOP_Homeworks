#pragma once
#include "Car.h"
#include "Weather.h"
class Circuit
{
private:
	unsigned int length;
	Weather condition;

	Car* cars[100];
	float finishTime[100];
	bool finish[100];
	int nrCars=0;

public:
	Circuit();

	void SetLength(unsigned int length);
	void SetWeather(Weather condition);

	void AddCar(Car* car);
	void Race();

	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};