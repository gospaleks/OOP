#include "CD.h"
#include <iostream>
#include <fstream>
using namespace std;

CD::CD()
{
	velicina = zauzetProstor = slobodanProstor = 0;
}

CD::CD(float v, float zP, float sP)
{
	if (v <= 0 || zP < 0 || sP < 0)
		throw exception("Svi parametri CD-a moraju biti veci od 0.");

	velicina = v;
	zauzetProstor = zP;
	slobodanProstor = sP;
}

bool CD::operator==(CD& c)
{
	return (velicina == c.velicina && zauzetProstor == c.zauzetProstor && slobodanProstor == c.slobodanProstor);
}

bool CD::operator>(CD& c)
{
	if (velicina > c.velicina)
		return true;
	else
		return (slobodanProstor > c.slobodanProstor);
}

ostream& operator<<(ostream& izlaz, const CD& c)
{
	return izlaz << c.velicina << " " << c.zauzetProstor << " " << c.slobodanProstor;
}

istream& operator>>(istream& ulaz, CD& c)
{
	return ulaz >> c.velicina >> c.zauzetProstor >> c.slobodanProstor;
}
