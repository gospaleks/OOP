#include "Artikal.h"
#include <string.h>
#include <iostream>
using namespace std;
Artikal::Artikal()
{
	naziv = nullptr;
	cena = 0.0;
}

Artikal::Artikal(char* nnaziv, double ccena)
{ 
	naziv = new char[strlen(nnaziv) + 1];
	strcpy(naziv, nnaziv);
	cena = ccena;
}

Artikal::~Artikal()
{
	if (naziv != nullptr)
		delete [] naziv;
}

void Artikal::showDescription()
{
	cout << naziv << ": " << cena << endl;
}
