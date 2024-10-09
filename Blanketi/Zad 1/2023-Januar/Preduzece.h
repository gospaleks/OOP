#pragma once
#include "Karta.h"
#include <iostream>
#include <fstream>
using namespace std;

class Preduzece
{
private:
	Karta** niz;
	int top;
	int maxEl;
public:
	Preduzece();
	Preduzece(int _maxEl);
	~Preduzece();

	void dodajKartu(Karta * k);
	void obrisiKartu(int _id);
	void produziTrajanje(int _id, int _brDanaZaProduzenje);
	void prikazi(ostream& izlaz);
	int brojVazecihKarata(int _redniBroj, const char * _vrsta);
	double ukupnaZarada();

	void minMax(Karta** min, Karta** max);
};

