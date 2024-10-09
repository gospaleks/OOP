#include "Zamak.h"
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

Zamak::Zamak()
{
	kapacitet = 0;
	lista = nullptr;
	naziv_zamka = nullptr;
}

Zamak::Zamak(int kapacitet, char *naziv_zamka)
{
	this->kapacitet = kapacitet;
	lista = new Posetilac * [this->kapacitet];
	for (int i = 0; i < this->kapacitet; i++)
		lista[i] = nullptr;
	this->naziv_zamka = new char[strlen(naziv_zamka) + 1];
	strcpy(this->naziv_zamka, naziv_zamka);
}

Zamak::~Zamak()
{
	for (int i = 0; i < kapacitet; i++)
		if (lista[i] != nullptr)
			delete lista[i];
	delete[] lista;
}

void Zamak::dodaj(Posetilac* p)
{
	if (p->getbtermina() <= kapacitet && lista[p->getbtermina() - 1] == nullptr)
		lista[p->getbtermina() - 1] = p;	//ako se zauzimaju 2 termina onda se 2 puta pozove funkcija		
	else
		delete p;
}

void Zamak::prikazitermine(ostream& izlaz)
{
	for (int i = 0; i < kapacitet; i++)
	{
		if (lista[i] == nullptr)
			izlaz << "termin " << i + 1 << " je PRAZAN" << endl <<endl;
		else
		{
			izlaz << "termin " << i + 1 << " je za:" << endl;
			lista[i]->prikazi(izlaz);
			izlaz << endl;
		}
	}
}

void Zamak::otkazi(int termin)
{
	if (lista[termin - 1] != nullptr)
		delete lista[termin - 1];
	lista[termin - 1] = nullptr;
}

int Zamak::prihod()
{
	int prihod = 0;
	for (int i = 0; i < kapacitet; i++)
		if (lista[i] != nullptr)
			prihod += lista[i]->getcena();
	return prihod;
}

Posetilac* Zamak::orden()
{
	int imax = 0;
	for (int i = 0; i < kapacitet; i++)
		if (lista[i] != nullptr && lista[i]->getzainteresovanost() > lista[imax]->getzainteresovanost())
			imax = i;
	return lista[imax];
}
