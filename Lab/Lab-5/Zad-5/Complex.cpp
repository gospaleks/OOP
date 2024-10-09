#include "Complex.h"
#include <iostream>
#include <fstream>
using namespace std;

Complex::Complex()
{
	re = im = 0;
}

Complex::Complex(double rre, double iim)
	:re(rre), im(iim) {
}

Complex::~Complex()
{
}

Complex Complex::operator*(const Complex& desni)
{
	return Complex(this->re * desni.re - this->im * desni.im,
				   this->re * desni.im + desni.re * this->im);
}

Complex Complex::operator+(const Complex& desni)
{
	return Complex(this->re + desni.re, this->im + desni.im);
}

Complex& Complex::operator=(const Complex& desni)
{
	if (this != &desni) {
		this->re = desni.re;
		this->im = desni.im;
	}

	return *this;
}

ostream& operator<<(ostream& izlaz, Complex& c)
{
	return izlaz << c.re << showpos << c.im << 'j' << "\t";
}

istream& operator>>(istream& ulaz, Complex& c)
{
	return ulaz >> c.re >> c.im;
}
