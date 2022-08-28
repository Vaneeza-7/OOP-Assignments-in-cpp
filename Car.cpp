
#include<iostream>
#include"Car.h"

using namespace std;


	void Car::setPetrolLevel(int petrolLevelVal)
	{
		if (petrolLevelVal >= 0 && petrolLevelVal <= 45)
			petrolLevel = petrolLevelVal;
	}

	int Car::getPetrolLevel()
	{
		return petrolLevel;
	}

	Car::Car()
	{
		petrolLevel = 0;
	}

	Car::Car(int petrolLevelVal)
	{
		petrolLevel = petrolLevelVal;
	}
	
	bool Car::MoveCar(int distanceKM)
	{
			if (distanceKM > petrolLevel)
				return false;
			

			if (distanceKM < petrolLevel)
				petrolLevel = petrolLevel - distanceKM;
			return true;

	}

	void Car::Refill()
	{
		while (petrolLevel != 45)
		{
			petrolLevel++;
		}
	}

	bool Car::isEmpty()
	{
		if (petrolLevel == 0)
			return true;
		else
			return false;
	}