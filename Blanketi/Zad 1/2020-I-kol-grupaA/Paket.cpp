#include "Paket.h"
#include "KutijaCokolade.h"
#include "FlasaPice.h"
#include <iostream>
#include <fstream>
using namespace std;

Paket::Paket()
{
	niz = nullptr;
	top = maxEl = 0;
}

Paket::Paket(int _maxEl)
{
	maxEl = _maxEl;
	top = 0;
	niz = new Poklon * [maxEl];
	for (int i = 0; i < maxEl; ++i)
		niz[i] = nullptr;
}

Paket::~Paket()
{
	if (niz != nullptr)
	{
		for (int i = 0; i < maxEl; ++i)
			if (niz[i] != nullptr)
				delete niz[i];
		delete[] niz;
	}
}

void Paket::dodajPoklon(Poklon* p)
{
	if (top < maxEl) {
		niz[top++] = p;
	}
}

void Paket::ucitaj(const char* imeFajla)
{
	ifstream ulaz(imeFajla);
	if (ulaz.good()) {
		
		int n; ulaz >> n;
		for (int i = 0; i < n; ++i) {
			double p1, p3;
			int p2;
			ulaz >> p1 >> p2 >> p3;
			this->dodajPoklon(new KutijaCokolade(p1, p2, p3));
		}
		
		ulaz >> n;
		for (int i = 0; i < n; ++i) {
			double p1, p2, p3, p4;
			ulaz >> p1 >> p2 >> p3 >> p4;
			this->dodajPoklon(new FlasaPice(p1, p2, p3, p4));
		}

		ulaz.close();
	}
}

void Paket::prikazi(ostream& izlaz)
{
	izlaz << "SADRZAJ PAKETA:\n\n";
	for (int i = 0; i < top; ++i) {
		if (niz[i] != nullptr)
			niz[i]->prikazi(izlaz);
		else
			izlaz << "NULL\n";
	}
	izlaz << "############################################-KRAJ\n\n";
}

double Paket::ukupnaMasa()
{
	double rez = 0;
	for (int i = 0; i < top; ++i)
		if (niz[i] != nullptr)
			rez += niz[i]->getMasa();
	return rez;
}

void Paket::podeliPaket(Paket* p1, Paket* p2)
{
	for (int i = 0; i < 4; ++i) {
		if (niz[i] != nullptr) {
			p1->dodajPoklon(niz[i]);
			niz[i] = nullptr;
		}
		if (niz[i + 4] != nullptr)
		{
			p2->dodajPoklon(niz[i + 4]);
			niz[i + 4] = nullptr;
		}
	}

	for (int i = 8; i < 10; ++i) {
		if (niz[i] != nullptr) {
			p1->dodajPoklon(niz[i]);
			niz[i] = nullptr;
		}
		if (niz[i + 2] != nullptr)
		{
			p2->dodajPoklon(niz[i + 2]);
			niz[i + 2] = nullptr;
		}
	}
}


