#include "Igracka.h"

Igracka::Igracka() : Poklon()
{
	tipMaterijala = nullptr;
}

Igracka::Igracka(double cena, double brojMasnica, const char* tipMaterijala)
	: Poklon(cena, brojMasnica)
{
	this->tipMaterijala = new char[strlen(tipMaterijala) + 1];
	strcpy(this->tipMaterijala, tipMaterijala);
}

Igracka::Igracka(const Igracka& i) : Poklon(i)
{
	this->tipMaterijala = new char[strlen(i.tipMaterijala) + 1];
	strcpy(this->tipMaterijala, i.tipMaterijala);
}

Igracka::~Igracka()
{
	if (tipMaterijala != nullptr)
		delete[] tipMaterijala;
}

void Igracka::print(ostream& izlaz) const
{
	Poklon::print(izlaz);
	izlaz << "Tip materijala: " << tipMaterijala << endl;
	izlaz << endl;
}

int Igracka::vratiBrojMasnica() const
{
	return 2 + brojMasnica;
}
