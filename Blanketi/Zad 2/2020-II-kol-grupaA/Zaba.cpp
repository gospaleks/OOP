#include "Zaba.h"

Zaba::Zaba()
{
	gustinaPega = 0;
	masa = 0;
	omiljenaVelMuve = 0;
}

Zaba::Zaba(float ggustinaPega, float mmasa, float oomiljenaVelMuve)
{
	if (ggustinaPega <= 0 || mmasa <= 0 || oomiljenaVelMuve <= 0)
		throw "Zaba nije validna";
	else
	{
		gustinaPega = ggustinaPega;
		masa = mmasa;
		omiljenaVelMuve = oomiljenaVelMuve;
	}
}

Zaba::~Zaba()
{

}

bool Zaba::operator>(Zaba& z)
{
	if (masa == z.masa)
	{
		if (omiljenaVelMuve == z.omiljenaVelMuve)
		{
			if (gustinaPega > z.gustinaPega)
				return 1;
			else
				return 0;
		}
		else
			return (omiljenaVelMuve > z.omiljenaVelMuve);
	}
	else
		return (masa > z.masa);
}

bool Zaba::operator==(Zaba& z)
{
	return (gustinaPega == z.gustinaPega && masa == z.masa && omiljenaVelMuve == z.omiljenaVelMuve);
}

Zaba& Zaba::operator=(Zaba& z)
{
	if (this != &z)
	{
		gustinaPega = z.gustinaPega;
		masa = z.masa;
		omiljenaVelMuve = z.omiljenaVelMuve;
		return *this;
	}
}

float Zaba::operator+(float br)
{
	return (this->masa + br);
}

istream& operator>>(istream& ulaz, Zaba& z)
{
	ulaz >> z.gustinaPega >> z.masa >> z.omiljenaVelMuve;
	return ulaz;
}

ostream& operator<<(ostream& izlaz, Zaba& z)
{
	izlaz << "Gustina pega: " << z.gustinaPega
		<< " Masa: " << z.masa
		<< " Omiljena velicina muve: " << z.omiljenaVelMuve;
	return izlaz;
}
