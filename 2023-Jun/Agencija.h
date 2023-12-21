#pragma once
#include "Putovanje.h"
#include <fstream>
#include <iostream>
using namespace std;

class Agencija
{
private:
	Putovanje** niz;
	int maxEl;
	int top;
public:
	Agencija(int _maxEl = 10);
	~Agencija();

	void dodajPutovanje(Putovanje* p);
	void prikaziSvaPutovanja(ostream& izlaz);
	Putovanje* get(int i) {
		if (niz[i] != nullptr)
			return niz[i];
		else
			return nullptr;
	}
};

