#include "Complex.h"

Complex::Complex()
{
	Re = 0;
	Im = 0;
}

Complex::Complex(float r, float i)
{
	Re = r;
	Im = i;
}

Complex::~Complex()
{
	
}

Complex::Complex(const Complex& c)
{
	Re = c.Re;
	Im = c.Im;
}

Complex& Complex::operator+(Complex& c)
{
	Complex* c1 = new Complex();
	c1->Re = this->Re + c.Re;
	c1->Im = this->Im + c.Im;
	return *c1;
}

Complex& Complex::operator=(Complex& c)
{
	if (this != &c)
	{
		this->Re = c.Re;
		this->Im = c.Im;
	}
	return *this;
}

Complex& Complex::operator*(Complex& c)
{
	Complex *c1 = new Complex();
	c1->Re = (this->Re * c.Re) - (this->Im * c.Im);
	c1->Im = (this->Re * c.Im) + (this->Im * c.Re);
	return *c1;
}



ostream& operator<<(ostream& izlaz, Complex& c)
{
	izlaz << c.Re << " + " << c.Im << "j  ";
	return izlaz;
}

istream& operator>>(istream& ulaz, Complex& c)
{
	ulaz >> c.Re >> c.Im;
	return ulaz;
}
