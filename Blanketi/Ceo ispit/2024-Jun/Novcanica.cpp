#include "Novcanica.h"

Novcanica::Novcanica(int vrednost, int brojNovcanica)
	: vrednost(vrednost), brojNovcanica(brojNovcanica)
{
}

Novcanica::~Novcanica()
{
}

void Novcanica::povecajBrojNovcanica(int za)
{
	brojNovcanica += za;
}

void Novcanica::smanjiBrojNovcanica(int za)
{
	brojNovcanica -= za;
}

std::ostream& operator<<(std::ostream& izlaz, const Novcanica& n)
{
	n.Prikazi(izlaz);
	return izlaz;
}
