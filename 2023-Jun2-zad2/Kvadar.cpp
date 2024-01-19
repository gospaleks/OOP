#include "Kvadar.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

float Kvadar::getMasa()
{
	return (duzina * visina * sirina * gustina);
}

Kvadar::Kvadar()
{
	duzina = visina = sirina = gustina = 0;
}

Kvadar::Kvadar(float d, float v, float s, float g)
	:duzina(d), visina(v), sirina(s), gustina(g) {
}

bool Kvadar::operator>(Kvadar& k)
{
	return (this->getMasa() > k.getMasa());
}

float Kvadar::operator+(float r)
{
	return (getMasa() + r);
}

ostream& operator<<(ostream& izlaz, Kvadar& k)
{
	return izlaz << k.duzina << " " << k.visina << " " << k.sirina << " " << k.gustina;
}

istream& operator>>(istream& ulaz, Kvadar& k)
{
	return ulaz >> k.duzina >> k.visina >> k.sirina >> k.gustina;
}