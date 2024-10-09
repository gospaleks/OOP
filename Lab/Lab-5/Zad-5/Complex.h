#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Complex
{
private:
	double re;
	double im;
public:
	Complex();
	Complex(double rre, double iim);
	~Complex();

	Complex operator*(const Complex& desni);
	Complex operator+(const Complex& desni);
	Complex& operator=(const Complex& desni);

	friend ostream& operator<<(ostream& izlaz, Complex& c);
	friend istream& operator>>(istream& ulaz, Complex& c);
};

