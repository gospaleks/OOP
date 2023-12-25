#pragma once
#include "Vozilo.h"
#include <fstream>
using namespace std;

class Automobil : public Vozilo
{
private:
	int maxBrPutnika;
public:
	Automobil();
	Automobil(const char* _naziv, const char* _reg, double _maxBr, double _potrosnja, double _maxBrPutnika);
	~Automobil();

	virtual void ispisi(ostream& izlaz);
	virtual void citaj(istream& ulaz);

	// ovo je za ono poredjenje automobila
	// mada nigde se ne koristi
	// za neko sortiranje moze da posluzi
	bool operator>(const Automobil& a);
	bool operator<(const Automobil& a);
};

