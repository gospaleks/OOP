#include "Pice.h"

Pice::Pice()
{
	zapremina = 0;
	brAmbalaza = 0;
}

Pice::Pice(float zapremina, int brAmbalaza)
{
	this->zapremina = zapremina;
	this->brAmbalaza = brAmbalaza;
}

Pice::~Pice()
{
}

void Pice::Prikazi(ostream& izlaz)
{
	izlaz << "Cena: " << cena() << endl;
	izlaz << "Zapremina: " << zapremina << "\nBr. ambalaza: " << brAmbalaza << endl;
}

ostream& operator<<(ostream& izlaz, Pice& p)
{
	p.Prikazi(izlaz);
	return izlaz;
}
