#include "Poklon.h"

Poklon::Poklon()
{
	cena = 0;
	brojMasnica = 0;
}

Poklon::Poklon(double cena, double brojMasnica)
	: cena(cena), brojMasnica(brojMasnica)
{
}

Poklon::Poklon(const Poklon& p)
{
	cena = p.cena;
	brojMasnica = p.brojMasnica;
}

Poklon::~Poklon()
{
}

void Poklon::print(ostream& izlaz) const
{
	izlaz << "Cena: " << cena << "\nBroj masnica: " << brojMasnica << endl;
}

ostream& operator<<(ostream& izlaz, const Poklon& p)
{
	p.print(izlaz);
	return izlaz;
}
