#include "Buket.h"
#include "Ruza.h"
#include "Lala.h"
#include <iostream>
#include <fstream>
using namespace std;

Buket::Buket()
{
	niz = nullptr;
	top = maxEl = 0;
}

Buket::Buket(int _maxEl)
{
	maxEl = _maxEl;
	top = 0;
	niz = new Cvet * [maxEl];
	for (int i = 0; i < maxEl; ++i)
		niz[i] = nullptr;
}

Buket::~Buket()
{
	if (niz != nullptr) {
		for (int i = 0; i < maxEl; ++i)
			if (niz[i] != nullptr)
				delete niz[i];
		delete[] niz;
	}
}

void Buket::dodaj(Cvet* c)
{
	if (top < maxEl) {
		niz[top++] = c;
	}
}

void Buket::ucitaj(const char* imeFajla)
{
	ifstream ulaz(imeFajla);
	if (ulaz.good()) {

		// PRVO PROCITAJ STATICKE ATRIBUTE
		ulaz >> Ruza::cenaSavrseneRuze;
		ulaz >> Lala::cenaLalePoGramu;

		// BROJ RUZA PA RUZE
		int brRuza; ulaz >> brRuza;
		for (int i = 0; i < brRuza; ++i) {
			int r, g, b;
			ulaz >> r >> g >> b;
			this->dodaj(new Ruza(r, g, b));
		}

		// BROJ LALA PA LALE
		int brLala; ulaz >> brLala;
		for (int i = 0; i < brLala; ++i) {
			int m;
			ulaz >> m;
			this->dodaj(new Lala(m));
		}

		ulaz.close();
	}
}

void Buket::ispisi(ostream& izlaz)
{
	izlaz << "BUKET:\n";
	for (int i = 0; i < top; ++i)
	{
		if (niz[i] != nullptr)
			niz[i]->ispisi(izlaz);
		else
			izlaz << "NULL\n";
	}
	izlaz << "#################################################-KRAJ\n\n";
}

void Buket::sortirajPoCeni()
{
	for (int i = 0; i < top-1; ++i)
	{
		for (int j = i + 1; j < top; ++j) {
			if (niz[i]->getCena() < niz[j]->getCena())
				swap(niz[i], niz[j]);
		}
	}
}

void Buket::podeliBuket(Buket* b1, Buket* b2)
{

	// BUKET 1
	int brojac = 0;
	for (int i = 0; i < top && brojac < 3; ++i) {

		if (niz[i] != nullptr && !strcmp(niz[i]->getVrsta(), "Ruza")) {
			++brojac;
			b1->dodaj(niz[i]);
			niz[i] = nullptr;
		}

	}

	brojac = 0;
	for (int i = top - 1; i >= 0 && brojac < 4; --i) {
		
		if (niz[i] != nullptr && !strcmp(niz[i]->getVrsta(), "Lala")) {
			++brojac;
			b1->dodaj(niz[i]);
			niz[i] = nullptr;
		}

	}

	// BUKET 2
	bool prvaLala = false;
	for (int i = 0; i < top && !prvaLala; ++i)
		if (niz[i] != nullptr && !strcmp(niz[i]->getVrsta(), "Lala"))
		{
			delete niz[i];
			niz[i] = nullptr;
			prvaLala = true;
		}

	brojac = 0;
	for (int i = 0; i < top; ++i) {
		if (niz[i] != nullptr) {
			b2->dodaj(niz[i]);
			niz[i] = nullptr;
		}
	}

	
}


