#pragma once
#include "Paketic.h"

class PaketicHrana : public Paketic
{
private:
	int brojCokolada;
	double ukupnaTezina;
	double cenaPoJed;
public:
	PaketicHrana();
	PaketicHrana(char* _adresa, char* _boja, int _brojCokolada, double _ukupnaTezina, double _cenaPoJed);
	virtual ~PaketicHrana() { }

	virtual double vratiCenu();
	virtual double vratiTezinu();
	virtual void prikaziPaketic(ostream& izlaz);
};

