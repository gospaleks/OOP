#pragma once
#include "Vozilo.h"
#include <fstream>
using namespace std;

class VozniPark
{
private:
	Vozilo** niz;
	int top;
	int maxEl;
	char* tip;

	// ovo u private da ne bi moglo iz main da se pozove
	// nego samo funkcije clanice mogu da ih pozivaju
	void zauzmiMemoriju(int _maxEl, const char* _tip);
	void prosiriMem();
public:
	VozniPark();
	VozniPark(int _maxEl, const char* _tip);
	~VozniPark();

	void dodajVozilo(Vozilo* v);

	void ispisi(ostream& izlaz);
	void citaj(istream& ulaz);
};

