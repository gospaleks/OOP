#pragma once
#include "Cvet.h"
#include <iostream>
#include <fstream>
using namespace std;

class Buket
{
private:
	Cvet** niz;
	int top;
	int maxEl;
public:
	Buket();
	Buket(int _maxEl);
	~Buket();

	void dodaj(Cvet* c);
	void ucitaj(const char* imeFajla);
	void ispisi(ostream& izlaz);
	void sortirajPoCeni();
	void podeliBuket(Buket* b1, Buket* b2);
};

