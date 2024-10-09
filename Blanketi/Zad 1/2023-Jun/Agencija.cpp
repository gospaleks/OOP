#include "Agencija.h"

Agencija::Agencija(int _maxEl)
{
	maxEl = _maxEl;
	top = 0;
	niz = new Putovanje * [maxEl];
	for (int i = 0; i < maxEl; ++i)
		niz[i] = nullptr;
}

Agencija::~Agencija()
{
	if (niz != nullptr) {
		for (int i = 0; i < maxEl; ++i)
			if (niz[i] != nullptr)
				delete niz[i];
		delete[] niz;
	}
}

void Agencija::dodajPutovanje(Putovanje* p)
{
	if (top < maxEl)
		niz[top++] = p;
}

void Agencija::prikaziSvaPutovanja(ostream& izlaz)
{
	for (int i = 0; i < top; ++i)
		if (niz[i] != nullptr)
			niz[i]->prikaziDetaljePutovanja(izlaz);
}

