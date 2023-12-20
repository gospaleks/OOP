#include "Saonice.h"
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;

Saonice::Saonice()
{
	niz = nullptr;
	top = maxBr = 0;
}

Saonice::Saonice(int _maxBr)
{
	maxBr = _maxBr;
	top = 0;
	niz = new Paketic * [maxBr];
	for (int i = 0; i < maxBr; ++i)
		niz[i] = nullptr;
}

Saonice::~Saonice()
{
	if (niz != nullptr)
	{
		for (int i = 0; i < maxBr; ++i)
			if (niz[i] != nullptr)
				delete niz[i];
		delete[] niz;
	}
}

void Saonice::dodajPaketic(Paketic* p)
{
	if (top < maxBr) {
		niz[top++] = p;
	}
}

void Saonice::izbaciPaketic(const char* _adresa)
{
	for (int i = 0; i < top; ++i)
	{
		if (!strcmp(niz[i]->vratiAdresu(), _adresa)) {
			delete niz[i];
			niz[i] = nullptr;
			for (int j = i; j < top - 1; ++j)
				niz[j] = niz[j + 1];
			--i;
			--top;
			niz[top] = nullptr;
		}
	}
}

void Saonice::prikaziSaonice(ostream& izlaz)
{
	izlaz << "SADRZAJ SAONICA:\n";
	for (int i = 0; i < top; ++i) {
		if (niz[i] != nullptr)
			niz[i]->prikaziPaketic(izlaz);
	}
}

double Saonice::srednjaCena()
{
	double rez = 0;
	for (int i = 0; i < top; ++i)
		if (niz[i] != nullptr)
			rez += niz[i]->vratiCenu();
	return (rez/top);
}

Paketic* Saonice::vratiNajteziPaketic()
{
	Paketic* p = niz[0];
	for (int i = 1; i < top; ++i)
		if (niz[i]->vratiTezinu() > p->vratiTezinu())
			p = niz[i];
	return p;
}


