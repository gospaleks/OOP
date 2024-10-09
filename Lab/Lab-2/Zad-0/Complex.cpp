#pragma once
#include<math.h>
#include "Complex.h"
#include <iomanip>

Complex::Complex()
{
	im = re = 0;
}

Complex::Complex(double re, double im)
{
	kopiraj(re, im);
}

Complex::~Complex()
{
	im = re = 0;
}

Complex& Complex::operator+(Complex& c2)
{
	Complex *rez = new Complex(this->re+c2.re, this->im+c2.im);
	return *rez;
}

Complex& Complex::operator-(Complex& c2)
{
	Complex* rez = new Complex(this->re - c2.re, this->im - c2.im);
	return *rez;
}

bool Complex::operator==(Complex& c2)
{
	if (this->re == c2.re && this->im == c2.im)
		return true;
	return false;
}

bool Complex::operator<(Complex& c2)
{
	double mod1, mod2;
	mod1 = sqrt(pow(this->re, 2) + pow(this->im, 2));
	mod2 = sqrt(pow(c2.re, 2) + pow(c2.im, 2));
	if (mod1 < mod2)
		return true;
	return false;
}

bool Complex::operator>(Complex& c2)
{
	double mod1, mod2;
	mod1 = sqrt(pow(this->re, 2) + pow(this->im, 2));
	mod2 = sqrt(pow(c2.re, 2) + pow(c2.im, 2));
	if (mod1 > mod2)
		return true;
	return false;
}

 Complex& Complex::operator=(const Complex& c2)
 {
 	if (this != &c2) 
 	{
		kopiraj(c2.re, c2.im);
 	}
 	return *this;
 }

void Complex::kopiraj(double re, double im)
{
	this->re = re;
	this->im = im;
}

istream& operator>>(istream& ulaz, Complex& c)
{
	ulaz >> c.re >> c.im;
	return ulaz;
}

ostream& operator<<(ostream& izlaz, Complex& c)
{
	izlaz << showpos << c.re << " " << c.im << "i";
	return izlaz;
}
