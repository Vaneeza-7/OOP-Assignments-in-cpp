#pragma once

struct Car {

	int petrolLevel;
	Car();
	Car(int);
	void setPetrolLevel(int);
	int getPetrolLevel();
	bool MoveCar(int);
	void Refill();
	bool isEmpty();

};