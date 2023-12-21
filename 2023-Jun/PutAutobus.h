#pragma once
#include "Put.h"
#include <fstream>
#include <iostream>
using namespace std;

class PutAutobus : public Put
{
private:
	double ukupnaKm;
	double cenaGorivaPoLitru;	// u din
	double potrosnja;
	int brojNociUAutobusu;
public:
	PutAutobus();
	PutAutobus(char* _imeGrada, int _maxBrPutnika, int _brojNocenja, double _cenaPoNocenju, double _ukupnaKm, double _cenaGoriva, double _potrosnja, int _brojNociUAutobusu);
	~PutAutobus() { }

	virtual double getCenaZaAgenciju();
	virtual double getCenaPoPutniku();

	virtual void prikaziPut(ostream& izlaz);
};

