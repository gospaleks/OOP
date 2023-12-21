#pragma once
#include "Put.h"
#include <fstream>
#include <iostream>
using namespace std;

class PutAvion : public Put
{
private:
	char* imeKompanije;
	int duzTrajanjaLeta; // u minuti
	double cenaMestaPoPutniku;
public:
	PutAvion();
	PutAvion(char* _imeGrada, int _maxBrPutnika, int _brojNocenja, double _cenaPoNocenju, char* _imeKompanije, int _duzTrLeta, double _cenaMestaPoPutniku);
	~PutAvion();

	virtual double getCenaZaAgenciju();
	virtual double getCenaPoPutniku();
	
	virtual void prikaziPut(ostream& izlaz);
};

