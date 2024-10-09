#pragma once
#include<fstream>
using namespace std;

class Complex
{
private:
	double re, im;
public:
	Complex();
	Complex(double re, double im);
	~Complex();
	friend istream& operator>>(istream& ulaz, Complex& c);
	friend ostream& operator<<(ostream& izlaz, Complex& c);
	Complex& operator+(Complex& c2);
	Complex& operator-(Complex& c2);
	bool operator==(Complex& c2);
	bool operator<(Complex& c2);
	bool operator>(Complex& c2);
	Complex& operator=(const Complex& c2);
	inline double getRe() { return re; }
	inline double getIm() { return im; }
	void kopiraj(double re, double im);
};
