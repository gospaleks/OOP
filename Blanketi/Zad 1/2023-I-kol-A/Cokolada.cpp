#include "Cokolada.h"

Cokolada::Cokolada() : Poklon()
{
	procenatKakaa = 0;
}

Cokolada::Cokolada(int cena, int brojMasnica, double procenatKakaa)
	: Poklon(cena, brojMasnica), procenatKakaa(procenatKakaa)
{
}

Cokolada::Cokolada(const Cokolada& c) : Poklon(c)
{
	procenatKakaa = c.procenatKakaa;
}

Cokolada::~Cokolada()
{
}

void Cokolada::print(ostream& izlaz) const
{
	Poklon::print(izlaz);
	izlaz << "Procenat kakaa: " << procenatKakaa << endl;
	izlaz << endl;
}

int Cokolada::vratiBrojMasnica() const
{
	return 2 * brojMasnica;
}
