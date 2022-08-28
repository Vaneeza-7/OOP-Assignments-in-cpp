#include<iostream>
#include"Sandwich.h"

Sandwich::Sandwich()
{
	name = NULL;
	filling = NULL;
	size = NULL;
	is_ready=false;
	price=0.0;
}

Sandwich::Sandwich(char* fillingVal, double priceVal)
{

	name = NULL;
	size = NULL;
	is_ready = false;
	filling = fillingVal;
	price = priceVal;
}

Sandwich::Sandwich(char* fillingVal, double priceVal, char* nameVal, char* sizeVal, bool
	ready_status)
{
	filling = fillingVal;
	price = priceVal;
	name = nameVal;
	size = sizeVal;
	is_ready = ready_status;
}

Sandwich::Sandwich(const Sandwich& sandwich)
{
	price = sandwich.price;
	is_ready = sandwich.is_ready;
	name = sandwich.name;
	filling = sandwich.filling;
	size = sandwich.size;


}

void Sandwich::setFilling(char* fillingVal)
{
	filling = fillingVal;
}

void Sandwich::setPrice(double priceVal)
{
	price = priceVal;
}

void Sandwich::setName(char* nameVal)
{
	name = nameVal;
}

void Sandwich::setSize(char* sizeVal)
{
	if (sizeVal[0] == 's' && sizeVal[1] == 'm' && sizeVal[2] == 'a' && sizeVal[3] == 'l' && sizeVal[4] == 'l' && sizeVal[5] == '\0')
		size = sizeVal;
	else if (sizeVal[0] == 'm' && sizeVal[1] == 'e' && sizeVal[2] == 'd' && sizeVal[3] == 'i' && sizeVal[4] == 'u' && sizeVal[5] == 'm' && sizeVal[6]=='\0')
		size = sizeVal;
	else if (sizeVal[0] == 'l' && sizeVal[1] == 'a' && sizeVal[2] == 'r' && sizeVal[3] == 'g' && sizeVal[4] == 'e' && sizeVal[5] == '\0')
		size = sizeVal;
	else
		size = NULL;
}

char* Sandwich::getFilling()
{
	return filling;
}

double Sandwich::getPrice()
{
	return price;
}
char* Sandwich::getName()
{
	return name;
}
char* Sandwich::getSize()
{
	return size;
}
void Sandwich::makeSandwich()
{
	if (filling != NULL)
		is_ready = true;
	else
		is_ready = false;
}
bool Sandwich::check_status()
{
	if (is_ready == true)
		return true;
	else
		return false;
}