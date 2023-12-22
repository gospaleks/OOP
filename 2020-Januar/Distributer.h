#pragma once
#include "SalonPutnicka.h"
#include "SalonPutnickaDostavna.h"
#include <iostream>
using namespace std;

class Distributer
{
	SalonPutnicka** niz;
	int top;
	int maxEl;
public:
	Distributer();
	Distributer(int mmaxEl);
	~Distributer();
	void dodaj(SalonPutnicka* s);
	void izbaci(int rredniBroj);
	void uvecaj(int redniBroj, const char* tip, int za);
	int veciBrZaposlenih(int granica);
	SalonPutnicka* najblizi(double x, double y);
	int brProdatihVozila();
	void prikazi(ostream& izlaz);
	double prosecnaEfikasnost();
};

