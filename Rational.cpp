/******************************************************************************

				                VANEEZA AHMAD
				                  21I-0390
								 SECTION: A
								   BS(CS)

*******************************************************************************/

#include<iostream>
#include"Rational.h"

using namespace std;

Rational::Rational(int n, int d)
{
	int gcd = GCD(n, d);
	numerator = n / gcd;
	denominator = d / gcd;
}

Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}

Rational::Rational(const Rational& copy)
{
	numerator = copy.numerator;
	denominator = copy.denominator;
}

int Rational::getnumerator()const
{
	return numerator;
}

int Rational::getdenominator()const
{
	return denominator;
}

void Rational::setnumerator(int n)
{
	numerator = n;
}

void Rational::setdenominator(int d)
{
	denominator = d;
}

Rational Rational::operator=(const  Rational& x)
{
	numerator = x.numerator;
	denominator = x.denominator;
	Rational object(numerator, denominator);
	return object;
}

int Rational::GCD(int x, int y)const
{
	if (y == 0)
		return x;
	else
		return GCD(y, x % y);
}

Rational Rational::operator+(const Rational& x) const
{
	Rational objNew(0, 1);
	int numer = (numerator * (x.denominator)) + ((x.numerator) * denominator);
	int denom = denominator * (x.denominator);
	int gcd = GCD(numer, denom);
	numer = numer / gcd;
	denom = denom / gcd;
	objNew.setnumerator(numer);
	objNew.setdenominator(denom);

	return objNew;
}

Rational Rational::operator-(const Rational& x) const
{
	Rational objNew(0, 1);
	int numer = (numerator * (x.denominator)) - ((x.numerator) * denominator);
	int denom = denominator * (x.denominator);
	int gcd = GCD(numer, denom);
	numer = numer / gcd;
	denom = denom / gcd;
	objNew.setnumerator(numer);
	objNew.setdenominator(denom);

	return objNew;
}

Rational Rational::operator*(const Rational& x) const
{
	Rational objNew(0, 1);
	int numer = numerator * (x.numerator);
	int denom = denominator * (x.denominator);
	int gcd = GCD(numer, denom);
	numer = numer / gcd;
	denom = denom / gcd;
	objNew.setnumerator(numer);
	objNew.setdenominator(denom);

	return objNew;
}

Rational Rational::operator/(const Rational& x) const
{
	Rational objNew(0, 1);
	int numer = numerator * (x.denominator);
	int denom = denominator * (x.numerator);
	int gcd = GCD(numer, denom);
	numer = numer / gcd;
	denom = denom / gcd;
	objNew.setnumerator(numer);
	objNew.setdenominator(denom);
	
	return objNew;
}


bool Rational::operator == (const Rational& other) const
{
	int gcd = GCD(numerator, denominator);
	int numer = numerator / gcd;
	int denom = denominator / gcd;
	gcd = GCD(other.numerator, other.denominator);
	int nu = other.numerator / gcd;
	int de = other.denominator / gcd;

	if (numer == nu && denom == de)
		return true;

	else return false;
}

bool Rational::operator < (const Rational& other) const
{
	int n = numerator * (other.denominator);
	int d = other.numerator * denominator;

	if (n < d)
		return true;
	else return false;
}

bool Rational::operator > (const Rational& other) const
{
	int n = numerator * (other.denominator);
	int d = other.numerator * denominator;

	if (n > d)
		return true;
	else return false;
}

bool Rational::operator <= (const Rational& other) const
{
	int n = numerator * (other.denominator);
	int d = other.numerator * denominator;

	if (n <= d)
		return true;
	else return false;
}

bool Rational::operator >= (const Rational& other) const
{
	int n = numerator * (other.denominator);
	int d = other.numerator * denominator;

	if (n >= d)
		return true;
	else return false;
}

Rational::operator string() const
{
	string n, d, str;
	if (numerator < 0 && denominator < 0)
	{
		int numer = numerator * -1;
		int denom = denominator * -1;
		n = to_string(numer);
		d = to_string(denom);
		str = n + "/" + d;

		return str;
	}

	else 
    n = to_string(numerator);
	d = to_string(denominator);
	 if (d == "1")
		 str = n;
	 else if (n == "0")
		 str = "0";
	 else
	     str = n + "/" + d;
     return str;
}

Rational::~Rational()
{
	numerator = 0;
	denominator = 1;
}

ostream& operator<<(ostream& output, const Rational& obj)
{
	output << obj.numerator<<"/"<<obj.denominator;
	return output;
}

istream& operator>>(istream& input, Rational&obj)
{
	input >> obj.numerator;
	input >> obj.denominator;
	return input;
}

Rational Rational::operator+=(const Rational& x) 
{
	numerator = (numerator * (x.denominator)) + ((x.numerator) * denominator);
	denominator = denominator * (x.denominator);
	int gcd = GCD(numerator, denominator);
	numerator = numerator / gcd;
	denominator = denominator / gcd;
	Rational objNew(numerator, denominator);
	return objNew;
}

Rational Rational::operator-=(const Rational& x) 
{
	numerator = (numerator * (x.denominator)) - ((x.numerator) * denominator);
	denominator = denominator * (x.denominator);
	int gcd = GCD(numerator, denominator);
	numerator = numerator / gcd;
	denominator = denominator / gcd;
	Rational objNew(numerator, denominator);
	return objNew;
}

Rational Rational::operator*=(const Rational& x) 
{
	numerator = numerator * (x.numerator);
	denominator = denominator * (x.denominator);
	int gcd = GCD(numerator, denominator);
	numerator = numerator / gcd;
	denominator = denominator / gcd;
	Rational objNew(numerator, denominator);
	return objNew;
}

Rational Rational::operator/=(const Rational& x) 
{
	numerator = numerator * (x.denominator);
	denominator = denominator * (x.numerator);
	int gcd = GCD(numerator, denominator);
	numerator = numerator / gcd;
	denominator = denominator / gcd;
	Rational objNew(numerator, denominator);
	return objNew;
}
