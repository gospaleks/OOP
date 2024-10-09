#pragma once
#include <iostream>
using namespace std;

class Complex
{
	float Re;
	float Im;
public:
	Complex();
	Complex(float r, float i);
	~Complex();
	Complex(const Complex& c);

	Complex& operator+(Complex& c);
	Complex& operator=(Complex& c);
	Complex& operator*(Complex& c);

	friend ostream& operator<<(ostream& izlaz, Complex& c);
	friend istream& operator>>(istream& ulaz, Complex& c);

	
};

