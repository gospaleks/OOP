#include "PokretnaTraka.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
using namespace std;

PokretnaTraka::PokretnaTraka()
{
	traka = nullptr;
	top = kapacitet = 0;
}

PokretnaTraka::PokretnaTraka(int _kapacitet)
{
	kapacitet = _kapacitet;
	top = 0;
	traka = new Proizvod * [kapacitet];
	for (int i = 0; i < kapacitet; ++i)
		traka[i] = nullptr;
}

PokretnaTraka::~PokretnaTraka()
{
	if (traka != nullptr)
	{
		for (int i = 0; i < kapacitet; ++i)
			if (traka[i] != nullptr)
				delete traka[i];
		delete[] traka;
	}
}

void PokretnaTraka::dodajProizvod(Proizvod* p)
{
	if (top < kapacitet) {
		traka[top++] = p;
	}
}

void PokretnaTraka::povecajKapacitet(int brPozicija)
{
	int newKap = kapacitet + brPozicija;
	Proizvod** tmp = new Proizvod * [newKap];
	for (int i = 0; i < newKap; ++i)
		tmp[i] = nullptr;

	for (int i = 0; i < top; ++i)
		tmp[i] = traka[i];

	delete[] traka;

	kapacitet = newKap;
	traka = tmp;
}

// izbaci prvi koji nije null 
// i upisi ga u fajl
void PokretnaTraka::izbaci()
{
	if (top == 0) return;

	int i = 0;
	while (traka[i] == nullptr)
		++i;
	
	
	ofstream izlaz;
	izlaz.open("pakovanje.txt", ios_base::app);
	traka[i]->prikazi(izlaz);
	izlaz.close();


	delete traka[i];
	for (; i < top - 1; ++i)
		traka[i] = traka[i + 1];
	top--;
	traka[top] = nullptr;
}

void PokretnaTraka::zameniDefektni(int poz, Proizvod* p)
{
	if (poz < 0 || poz > kapacitet) return;

	if (traka[poz]->jeDefektan())
	{
		// u prvoj trecini trake i istog tipa
		if (poz <= (kapacitet / 3) && !strcmp(traka[poz]->getTip(), p->getTip())) {
			delete traka[poz];
			traka[poz] = p;
		}
	}
}

int PokretnaTraka::trenutniBrojDefektnih()
{
	int rez = 0;
	for (int i = 0; i < top; ++i)
		if (traka[i] != nullptr && traka[i]->jeDefektan())
			++rez;
	return rez;
}

int PokretnaTraka::trenutniBrojPraznihMesta()
{
	int rez = 0;
	for (int i = 0; i < top; ++i)
		if (traka[i] == nullptr)
			++rez;
	return rez;
}

void PokretnaTraka::prikazi(ostream& izlaz)
{
	izlaz << "SADRZAJ TRAKE:\n\n";
	for (int i = 0; i < kapacitet; ++i)
		if (traka[i] != nullptr)
			traka[i]->prikazi(izlaz);
		else
			izlaz << "NULL\n\n";
	izlaz << "###########################################-KRAJ";
}
