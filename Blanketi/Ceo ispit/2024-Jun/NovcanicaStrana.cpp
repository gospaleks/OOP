#include "NovcanicaStrana.h"

NovcanicaStrana::NovcanicaStrana(int vrednost, const char* kodValute, double kurs)
	: Novcanica(vrednost, 1), kurs(kurs)
{
	strcpy(this->kodValute, kodValute);
}

NovcanicaStrana::~NovcanicaStrana()
{
	// Ne treba nista jer je kodValute staticki niz karaktera 
	// zato sto unapred znamo broj karaktera za valutu
}

bool NovcanicaStrana::operator==(const Novcanica& n) const
{
	return vrednost == n.getVrednost() && strcmp(kodValute, n.getKodValute()) == 0 && kurs == n.getKurs();
}

void NovcanicaStrana::Prikazi(std::ostream& izlaz) const
{
	izlaz << kodValute << ": " << vrednost << "(" << brojNovcanica << ") -> " << ukupnaVrednost() << " RSD" << endl;
}
