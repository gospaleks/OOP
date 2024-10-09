#include "Preduzece.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

Preduzece::Preduzece()
{
	niz = nullptr;
	maxEl = top = 0;
}

Preduzece::Preduzece(int mmaxEl)
{
	maxEl = mmaxEl;
	top = 0;
	niz = new Paket * [maxEl];
	for (int i = 0; i < maxEl; ++i)
		niz[i] = nullptr;
}

Preduzece::~Preduzece()
{
	if (niz != nullptr)
	{
		for (int i = 0; i < maxEl; ++i)
			if (niz[i] != nullptr)
				delete niz[i];

		delete[] niz;
	}
}

void Preduzece::dodajPaket(Paket* p)
{
	niz[top++] = p;
}

void Preduzece::ukloniSa(int k)
{
	if (niz[k] != nullptr && k < top && k >= 0) {
		delete niz[k];
		for (int i = k; i < top-1; ++i)
			niz[i] = niz[i + 1];
		top--;
	}
}

// u ove dve odma handlujem i opsege
void Preduzece::zameniBrojPretplMin(int el, double nova)
{
	if (nova < 100) nova = 100;
	if (nova > 2000) nova = 2000;
	if (el >= 0 && el < top && niz[el] != nullptr)
		niz[el]->zameniBrojPretplMin(nova);
}

void Preduzece::zameniProcentualniParametar(int el, double nova)
{
	if (nova < 50) nova = 50;
	if (nova > 100) nova = 100;
	if (el >= 0 && el < top && niz[el] != nullptr)
		niz[el]->zameniProcentualniParametar(nova);
}

void Preduzece::zameniBrojDece(int el, double nova)
{
	if (el >= 0 && el < top && niz[el] != nullptr)
		niz[el]->zameniBrojDece(nova);
}

void Preduzece::stampajIzvestaj(ostream& izlaz)
{
	izlaz << "IZVESTAJ:\n\n";
	for (int i = 0; i < top; ++i)
		niz[i]->prikazi(izlaz);

	izlaz << "\n";
	izlaz << setw(30) << left << "Ukupna zarada od svih korisnika: " << zaradaOdSvihKorisnika();
	izlaz << " din\n";
	izlaz << "################################################\n\n";
}

double Preduzece::ukupanBrojMinuta()
{
	double rez = 0;
	for (int i = 0; i < top; ++i)
		if (niz[i] != nullptr)
			rez += niz[i]->vratiBrojPretplMin();

	return rez;
}

double Preduzece::zaradaOdSvihKorisnika()
{
	double rez = 0;
	for (int i = 0; i < top; ++i)
	{
		if (niz[i] != nullptr)
			rez += niz[i]->zaUplatu();
	}
	return rez;
}




