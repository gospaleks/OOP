#include "NovcanicaDinar.h"

NovcanicaDinar::NovcanicaDinar(int vrednost)
	: Novcanica(vrednost, 1)
{
}

NovcanicaDinar::~NovcanicaDinar()
{
}

bool NovcanicaDinar::operator==(const Novcanica& n) const
{
	return vrednost == n.getVrednost();
}

void NovcanicaDinar::Prikazi(std::ostream& izlaz) const
{
	izlaz << "DIN: " << vrednost << "(" << brojNovcanica << ") -> " << ukupnaVrednost() << " RSD" << endl;
}
