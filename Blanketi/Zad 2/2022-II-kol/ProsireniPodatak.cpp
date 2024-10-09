#include "ProsireniPodatak.h"

float ProsireniPodatak::getOsecaj()
{
	return (T + 0.33 * E - 0.7 * V - 4.0);
}

ProsireniPodatak::ProsireniPodatak()
{
	T = E = V = 0;
}

ProsireniPodatak::ProsireniPodatak(float _T, float _E, float _V)
	:T(_T), E(_E), V(_V) {
}

ProsireniPodatak::~ProsireniPodatak()
{
}

bool ProsireniPodatak::operator>(ProsireniPodatak& p)
{
	return (this->getOsecaj() > p.getOsecaj());
}


float ProsireniPodatak::operator+(float x)
{
	return (getOsecaj() + x);
}

ostream& operator<<(ostream& izlaz, ProsireniPodatak& p)
{
	return izlaz << p.T << " " << p.E << " " << p.V << " ";
}

istream& operator>>(istream& ulaz, ProsireniPodatak& p)
{
	return ulaz >> p.T >> p.E >> p.V;
}