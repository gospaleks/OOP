#pragma once
#include "Paketic.h"
class PaketicIgracke : public Paketic
{
private:
	int brojAutica;
	double tezinaJednog;
	double cenaJednog;
public:
	PaketicIgracke();
	PaketicIgracke(char* _adresa, char* _boja, int brAut, double t, double c);
	virtual ~PaketicIgracke() { }

	virtual double vratiCenu();
	virtual double vratiTezinu();
	virtual void prikaziPaketic(ostream& izlaz);
};

