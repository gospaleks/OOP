#pragma once
#include "Poklon.h"
#include <iostream>
#include <fstream>
using namespace std;

class Paket
{
private:
	Poklon** niz;
	int top;
	int maxEl;
public:
	Paket();
	Paket(int _maxEl);
	~Paket();
	
	void dodajPoklon(Poklon* p);
	void ucitaj(const char* imeFajla);
	void prikazi(ostream& izlaz);
	double ukupnaMasa();
	void podeliPaket(Paket* p1, Paket* p2);
};

