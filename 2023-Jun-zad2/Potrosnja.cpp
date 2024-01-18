#include "Potrosnja.h"
#include <iostream>
#include <fstream>
using namespace std;

Potrosnja::Potrosnja()
{
	niza = visa = 0;
}

Potrosnja::Potrosnja(int _niza, int _visa)
	: niza(_niza), visa(_visa) {
}

Potrosnja::~Potrosnja()
{
}

bool Potrosnja::operator==(const Potrosnja& p)
{
	return (this->niza == p.niza && this->visa == p.visa);
}

Potrosnja Potrosnja::operator-(const Potrosnja& p)
{
	return Potrosnja(this->niza - p.niza, this->visa - p.visa);
}

int Potrosnja::operator+(int x)
{
	return (niza + visa + x);
}

bool Potrosnja::operator>(const Potrosnja& p)
{
	return ((this->niza + this->visa) > (p.niza + p.visa));
}

bool Potrosnja::operator<(const Potrosnja& p)
{
	return ((this->niza + this->visa) < (p.niza + p.visa));
}

ostream& operator<<(ostream& izlaz, const Potrosnja& p)
{
	return izlaz << p.niza << " " << p.visa;
}

istream& operator>>(istream& ulaz, Potrosnja& p)
{
	return ulaz >> p.niza >> p.visa;
}
