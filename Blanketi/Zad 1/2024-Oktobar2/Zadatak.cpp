#include "Zadatak.h"

Zadatak::Zadatak()
	:IspitniMaterijal()
{
	linije = 0;
}

Zadatak::Zadatak(int oznaka, double tezina, int linije)
	:IspitniMaterijal(oznaka, tezina)
{
	this->linije = linije;
}

Zadatak::Zadatak(const Zadatak& z)
	:IspitniMaterijal(z)
{
	linije = z.linije;
}

Zadatak::~Zadatak()
{
}

float Zadatak::vratiVreme(int vreme)
{
	return (float)tezina * linije * 0.05f * vreme;
}

void Zadatak::stampaj(ostream& izlaz)
{
	izlaz << "ZADATAK" << endl
		<< "oznaka: " << oznaka << endl
		<< "tezina: " << tezina << endl
		<< "status: " << status << endl
		<< "linije: " << linije << endl;
}
