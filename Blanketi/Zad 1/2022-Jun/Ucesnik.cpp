#include "Ucesnik.h"

Ucesnik::Ucesnik()
{
	redniBroj = 0;
	ime = nullptr;
	prezime = nullptr;
	poeniPublike = 0;
}

Ucesnik::Ucesnik(int rredniBroj, char* iime, char* pprezime, int ppoeniPublike)
{
	redniBroj = rredniBroj;
	ime = new char[strlen(iime) + 1];
	strcpy(ime, iime);
	prezime = new char[strlen(pprezime) + 1];
	strcpy(prezime, pprezime);
	if (ppoeniPublike > 100)
		poeniPublike = 100;
	else if (ppoeniPublike < 0)
		poeniPublike = 0;
	else
		poeniPublike = ppoeniPublike;
}

Ucesnik::~Ucesnik()
{
	if (prezime != nullptr)
		delete[] prezime;
	if (ime != nullptr)
		delete[] ime;
}
