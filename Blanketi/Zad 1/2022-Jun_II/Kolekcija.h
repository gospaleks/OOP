#pragma once
#include "Figura.h"
#include <fstream>
using namespace std;

class Kolekcija
{
private:
	Figura** niz;
	int nmax, brtr;
public:
	Kolekcija();
	Kolekcija(int n);
	void dodaj(Figura* f);
	void zauzmimem(int n);
	void vratipovrsinu();
	void vratiobim();
	void sortirajpoO();
	void ispisi(ostream& izlaz);
};

