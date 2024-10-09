#include "Roda.h"

Roda::Roda()
{
	masa = visina = rasponKrila = najveciBrojZaba = 0;
}

Roda::Roda(float mmasa, float vis, float rasKr, float nbz)
{
	if (mmasa <= 0 || vis <= 0 || rasKr <= 0 || nbz <= 0)
		throw "Roda nije validna";
	else
	{
		masa = mmasa;
		visina = vis;
		rasponKrila = rasKr;
		najveciBrojZaba = nbz;
	}
}

Roda::~Roda()
{

}

bool Roda::operator>(Roda& r)
{
	if (masa == r.masa)
	{
		if (najveciBrojZaba == r.najveciBrojZaba)
		{
			if (visina == r.visina)
			{
				return (rasponKrila > r.rasponKrila);
			}
			else
				return (visina > r.visina);
		}
		else
			return (najveciBrojZaba > r.najveciBrojZaba);
	}
	else
		return (masa > r.masa);
}

bool Roda::operator==(Roda& r)
{
	return (masa == r.masa && visina == r.visina && rasponKrila == r.rasponKrila && najveciBrojZaba == r.najveciBrojZaba);
}

Roda& Roda::operator=(Roda& r)
{
	if (this != &r)
	{
		masa = r.masa;
		visina = r.visina;
		rasponKrila = r.rasponKrila;
		najveciBrojZaba = r.najveciBrojZaba;
	}
	return *this;
}

float Roda::operator+(float br)
{
	return (this->masa + br);
}

istream& operator>>(istream& ulaz, Roda& r)
{
	ulaz >> r.masa >> r.visina >> r.rasponKrila >> r.najveciBrojZaba;
	return ulaz;
}

ostream& operator<<(ostream& izlaz, Roda& r)
{
	izlaz << "Masa: " << r.masa
		<< " Visina: " << r.visina
		<< " Raspon Krila: " << r.rasponKrila
		<< " Najveci broj zaba: " << r.najveciBrojZaba;
	return izlaz;
}
