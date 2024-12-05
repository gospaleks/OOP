#include "Lekcija.h"

Lekcija::Lekcija()
	:IspitniMaterijal() 
{
	stranice = 0;
}

Lekcija::Lekcija(int oznaka, double tezina, double stranice)
	:IspitniMaterijal(oznaka, tezina)
{
	this->stranice = stranice;
}

Lekcija::Lekcija(const Lekcija& l)
	:IspitniMaterijal(l)
{
	stranice = l.stranice;
}

Lekcija::~Lekcija()
{
}

float Lekcija::vratiVreme(int vreme)
{
	return (float)tezina * (float)stranice * vreme;
}

void Lekcija::stampaj(ostream& izlaz)
{
	izlaz << "LEKCIJA" << endl
		<< "oznaka: " << oznaka << endl
		<< "tezina: " << tezina << endl
		<< "status: " << status << endl
		<< "stranice: " << stranice << endl;
}
