#include "Voda.h"

Voda::Voda() : Pice()
{
}

Voda::Voda(float zapremina) : Pice(zapremina, 1)
{
}

Voda::~Voda()
{
}

void Voda::Prikazi(ostream& izlaz)
{
	izlaz << "Voda:\n";
	Pice::Prikazi(izlaz);
}

bool Voda::operator==(Pice& p)
{
	return this->getZapremina() == p.getZapremina();
}

float Voda::cena()
{
	return zapremina * brAmbalaza;
}

