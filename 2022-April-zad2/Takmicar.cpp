#include "Takmicar.h"

Takmicar::Takmicar()
{
	id = startniBroj = rezultat = 0;
}

Takmicar::Takmicar(int iid, int sstartniBroj, int rrezultat)
{
	id = iid;
	startniBroj = sstartniBroj;
	rezultat = rrezultat;
}

bool Takmicar::operator==(int x)
{
	return (this->id == x);
}

ostream& operator<<(ostream& izlaz, Takmicar& t)
{
	izlaz << "id - " << t.id << " satrdniBroj - " << t.startniBroj << " rezultat - " << t.rezultat << endl;
	return izlaz;
}
