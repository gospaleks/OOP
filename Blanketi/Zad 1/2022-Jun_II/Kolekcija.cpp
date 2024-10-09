#include "Kolekcija.h"
#include <iostream>
#include <fstream>
using namespace std;

Kolekcija::Kolekcija()
{
	nmax = brtr = 0;
	niz = nullptr;
}

Kolekcija::Kolekcija(int n)
{
	nmax = n;
	brtr = 0;
	zauzmimem(nmax);
}

void Kolekcija::dodaj(Figura* f)
{
	if (brtr < nmax)
		niz[brtr++] = f;
	else
	{
		int novaVel = nmax + (nmax / 2);
		Figura** temp = new Figura * [novaVel];
		for (int i = 0; i < novaVel; i++)
			temp[i] = nullptr;

		for (int i = 0; i < brtr; i++)
			temp[i] = niz[i];

		delete[] niz;

		nmax = novaVel;
		niz = temp;

		niz[brtr++] = f;
	}
}

void Kolekcija::zauzmimem(int n)
{
	niz = new Figura * [n];
	for (int i = 0; i < n; i++)
		niz[i] = nullptr;
}

void Kolekcija::vratipovrsinu()
{
	for (int i = 0; i < brtr; i++)
		cout << niz[i]->vratiP() << endl;
}

void Kolekcija::vratiobim()
{
	for (int i = 0; i < brtr; i++)
		cout << niz[i]->vratiO() << endl;
}

void Kolekcija::sortirajpoO()
{
	int min;
	for (int i = 0; i < brtr - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < brtr; j++)
			if (niz[j]->vratiO() < niz[i]->vratiO())
				min = j;
		if (min != i)
			swap(niz[min], niz[i]);
	}
}

void Kolekcija::ispisi(ostream& izlaz)
{
	for (int i = 0; i < nmax; i++)
	{
		if (niz[i] != nullptr)
		{
			niz[i]->ispisi(izlaz);
			izlaz << endl;
		}
		else
			izlaz << "prazno mesto" << endl;
	}
}

