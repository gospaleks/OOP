#pragma once
#include "Put.h"
#include <fstream>
#include <iostream>
using namespace std;

class Putovanje
{
private:
	Put** listaPuteva;
	int brojPlaniranihPutnika;
	int top;
	char datumPolaska[15]; // "dd-mm-yyyy"
	int maxPuteva;
public:
	Putovanje();
	Putovanje(int _max, const char _datumPolaska[]);
	~Putovanje();

	double cenaZaAgenciju();
	double cenaZaPutnika();

	void dodajPut(Put* p);
	void prikaziDetaljePutovanja(ostream& izlaz);
	void ucitajPutovanje(const char * imeFajla);
	double getPlaniranaZarada();
	int getUkupanBrojNocenja();
	void obrisiPut(const char* _nazivGrada);
	void prosiriMemoriju();
};

