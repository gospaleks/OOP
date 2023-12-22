#pragma once
#include "Ucesnik.h"
#include <iostream>
using namespace std;
class Takmicenje
{
	Ucesnik** niz;
	int maxEl;
	int top;
public:
	Takmicenje();
	Takmicenje(int mmaxEl);
	~Takmicenje();
	void dodaj(Ucesnik* u);
	void obrisi(int redniBr);
	double srednjaVrednostPoena();
	Ucesnik* najveciBrPoena();
	void upisi(ostream& izlaz);
	void sortiraj();
};

