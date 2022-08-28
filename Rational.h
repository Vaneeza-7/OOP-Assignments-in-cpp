#ifndef RATIONAL_H_
#define RATIONAL_H_
#include <iostream>
#include <string>
using namespace std;

class Rational {
	int numerator;
	int denominator;

public:
	Rational(int,int);
	Rational();
	Rational(const Rational &copy);// copy constructor to initialize the Rational form existing Rational //object
	//getters and setters
	int getnumerator()const;
	int getdenominator()const;
	void setnumerator(int);
	void setdenominator(int);
    // Binary Operators
	// Assignment Operator
	Rational operator = (const Rational &x);
	//GCD function
	int GCD(int, int)const;
	// Arithmetic Operators
	Rational operator+(const Rational &x) const;
	Rational operator-(const Rational &x) const;
	Rational operator*(const Rational &x) const;
	Rational operator/(const Rational &x) const;
	// Compound Arithmetic Operators
	Rational operator += (const Rational &x);
	Rational operator -= (const Rational &x);
	Rational operator *= (const Rational &x);
	Rational operator /= (const Rational &x);
	 //Logical Operators
	bool operator == (const Rational & other) const;
	bool operator < (const Rational & other) const;
	bool operator > (const Rational & other) const;
	bool operator <= (const Rational & other) const;
	bool operator >= (const Rational & other) const;

	// Unary Operator
	// Conversion Operator
	operator string() const; // returns 2/3 as “2/3”. If the denominator is 1 then only the numerator is returned, i.e. for 2/1 the operator shall return “2”
	~Rational(); // destructor

	friend ostream& operator<<(ostream& output, const Rational&);
	friend istream& operator>>(istream& input, Rational&);
};

// Operator Overloading as Non-Member Functions
// Stream Insertion and Extraction Operators
//ostream& operator<<(ostream& output, const Rational &); 	// outputs the Rational
//istream& operator>>(istream& input, Rational&); 	// inputs the Rational


#endif /* RATIONAL_H_ */



