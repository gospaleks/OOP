#include "Tekst.h"
#include "Paragraf1.h"
#include "Paragraf2.h"
#include <fstream>
#include <iostream>
using namespace std;

Tekst::Tekst()
{
	niz = nullptr;
	brTrenutnih = 0;
	maxBr = 0;
}

Tekst::Tekst(int mmaxBr)
{
	this->brTrenutnih = 0;
	zauzmiMem(mmaxBr);
}

Tekst::~Tekst()
{
	oslobodiMem();
}

void Tekst::oslobodiMem()
{
	if (niz != nullptr) {
		for (int i = 0; i < maxBr; ++i)
			if (niz[i] != nullptr)
				delete niz[i];
		delete[] niz;
	}
}

void Tekst::zauzmiMem(int n)
{
	this->maxBr = n;
	niz = new Paragraf * [maxBr];
	for (int i = 0; i < maxBr; ++i)
		niz[i] = nullptr;
}

void Tekst::dodajParagraf(Paragraf& par)
{
	if (brTrenutnih == maxBr) {
		prosiri();
	}
	niz[brTrenutnih++] = &par;
	
}

void Tekst::prosiri()
{
	Paragraf** pomNiz;
	int novaDim = maxBr + (maxBr / 2);
	pomNiz = new Paragraf * [novaDim];
	for (int i = 0; i < novaDim; ++i)
		if (niz[i] != nullptr && i < maxBr)
			pomNiz[i] = niz[i];
		else
			pomNiz[i] = nullptr;

	delete[] niz;
	maxBr = novaDim;
	niz = pomNiz;
}

void Tekst::upisi(char* putanjaFajla)
{
	ofstream izlaz(putanjaFajla);
	izlaz << "Trenutni broj paragrafa: " << brTrenutnih;
	izlaz << "\nMax broj paragrafa: " << maxBr << endl;
	izlaz << "---------------------------" << endl;
	for (int i = 0; i < brTrenutnih; ++i) {
		niz[i]->prikazi(izlaz);
		izlaz << endl;
	}
	izlaz.close();
}

void Tekst::citaj(char* putanjaFajla)
{
	ifstream ulaz(putanjaFajla);
	if (ulaz.good()) {
		int x, y;
		ulaz >> x >> y;
		zauzmiMem(x);
		for (int i = 0; i < y; ++i) {
			int tip;
			ulaz >> tip;
			char c;
			ulaz.get(c);		// preskoci blanko posle tipa

			char poms[100];
			int j = 0;
			ulaz.get(c);
			while (c != '\n') {
				poms[j++] = c;
				ulaz.get(c);
			}
			poms[j] = '\0';
			char* zaParagraf = new char[strlen(poms) + 1];
			strcpy(zaParagraf, poms);
			// ovde kopiram cisto da ne zauzima vise nego sto treba


			if (tip == 1) {
				Paragraf* p = new Paragraf1(zaParagraf);
				dodajParagraf(*p);
			}
			else if (tip == 2) {
				Paragraf* p = new Paragraf2(zaParagraf);
				dodajParagraf(*p);
			}
		}

		ulaz.close();
	}
	else {
		cout << "Fajl na zadatoj putanji ne postoji\n";
	}
}
