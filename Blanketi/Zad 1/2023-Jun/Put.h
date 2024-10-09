#pragma once
#include <fstream>
#include <iostream>
using namespace std;

class Put
{
protected:
	char* imeGrada;
	int maxBrPutnika;
	int brojNocenja;
	double cenaPoNocenju;
public:
	Put();
	Put(char* _imeGrada, int _maxBrPutnika, int _brojNocenja, double _cenaPoNocenju);
	virtual ~Put();

	double getCenaSmestaja() { return brojNocenja * cenaPoNocenju; }
	int getMaxBrPutnika() { return maxBrPutnika; }
	char* getImeGrada() { return imeGrada; }
	int getBrojNocenja() { return brojNocenja; }


	virtual double getCenaZaAgenciju() = 0;
	virtual double getCenaPoPutniku() = 0;

	virtual void prikaziPut(ostream& izlaz);
};

