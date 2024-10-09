#pragma once
#include "Kolekcija.h"
#include<iostream>
#include<fstream>

Kolekcija::Kolekcija()
{
	maxBroj = 0;
	trenutniBroj = 0;
	niz = nullptr;
}

Kolekcija::Kolekcija(int maxBroj)
{
	this->maxBroj = maxBroj;
	this->trenutniBroj = 0;
	niz = new Picture[this->maxBroj];
}

Kolekcija::~Kolekcija()
{
	if(niz!= 0)
		delete[] niz;
	maxBroj = 0;
	trenutniBroj = 0;
}

void Kolekcija::dodajSliku(Picture& p)
{
	this->niz[trenutniBroj++] = p;
}

//prefiksno
Kolekcija& Kolekcija::operator++()
{
	for (int i = 0; i < this->trenutniBroj; i++)
		niz[i]++;
	return *this;
}

//postfiksno
const Kolekcija Kolekcija::operator++(int)
{
	Kolekcija temp(*this);
	for (int i = 0; i < this->trenutniBroj; i++)
		this->niz[i]++;
	return temp;
}

ostream& operator<<(ostream& izlaz, Kolekcija& k)
{
	for (int i = 0; i < k.trenutniBroj; i++)
	{
		izlaz << k.niz[i];
		izlaz << endl;
	}
	return izlaz;
}
