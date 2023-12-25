#include "VozniPark.h"
#include "Automobil.h"
#include "Kamion.h"
#include <string.h>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

VozniPark::VozniPark()
{
	niz = nullptr;
	top = maxEl = 0;
	tip = nullptr;
}

VozniPark::VozniPark(int _maxEl, const char* _tip)
{
	zauzmiMemoriju(_maxEl, _tip);
}

VozniPark::~VozniPark()
{
	if (tip != nullptr)
		delete[] tip;
	if (niz != nullptr) {
		for (int i = 0; i < maxEl; ++i)
			if (niz[i] != nullptr)
				delete niz[i];
		delete[] niz;
	}
}

void VozniPark::zauzmiMemoriju(int _maxEl, const char* _tip)
{
	tip = new char[strlen(_tip) + 1];
	strcpy(tip, _tip);
	maxEl = _maxEl;
	top = 0;
	niz = new Vozilo * [maxEl];
	for (int i = 0; i < maxEl; ++i)
		niz[i] = nullptr;
}

void VozniPark::dodajVozilo(Vozilo* v)
{
	if (top == maxEl) {
		prosiriMem();
		niz[top++] = v;
	}
	else {
		niz[top++] = v;
	}
}

void VozniPark::prosiriMem()
{
	int newMax = maxEl + (maxEl / 2);
	Vozilo** tmp = new Vozilo * [newMax];
	for (int i = 0; i < newMax; ++i)
		tmp[i] = nullptr;

	// ovamo neki mrtvi warning da ce prekoracim buffer nzm koji mu je
	// vrv misli da je top > newMax i onda da ce probije
	// sve u svemu radi i ovo se tako radi provereno
	for (int i = 0; i < top; ++i)
		tmp[i] = niz[i];
	
	delete[] niz;
	maxEl = newMax;
	niz = tmp;
}

void VozniPark::ispisi(ostream& izlaz)
{
	izlaz << left << setw(25) << "TIP VOZNOG PARKA: " << tip << endl;
	izlaz << left << setw(25) << "KAPACITET: " << maxEl << endl;
	izlaz << left << setw(25) << "TR BR VOZILA: " << top << "\n\n\n";

	for (int i = 0; i < top; ++i)
		if (niz[i] != nullptr)
			niz[i]->ispisi(izlaz);

	izlaz << "#########################################-KRAJ\n\n";
}

void VozniPark::citaj(istream& ulaz)
{
	char _tip[100];
	int _maxEl;
	ulaz >> _tip;
	ulaz >> _maxEl;
	zauzmiMemoriju(_maxEl, _tip);

	int n;
	ulaz >> n;
	for (int i = 0; i < n; ++i)
	{
		if (!strcmp(tip, "Automobili")) {
			Vozilo * v = new Automobil();
			v->citaj(ulaz);
			dodajVozilo(v);
		}
		else if (!strcmp(tip, "Kamioni")) {
			Vozilo * v = new Kamion();
			dodajVozilo(v);
			v->citaj(ulaz);
		}
	}
}


