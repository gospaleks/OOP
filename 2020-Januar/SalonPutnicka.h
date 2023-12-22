#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class SalonPutnicka
{
protected:
	char tip[50];
	char* naziv;
	int brojZaposlenihPutnicka;
	double xKoo;
	double yKoo;
	int brojProdatihPutnickih;
public:
	SalonPutnicka();
	SalonPutnicka(char* nnaziv, int bbrojZaposlenihPutnicka,
		double xxKoo, double yyKoo,
		int bbrojProdatihPutnickih);
	double getX() { return xKoo; }
	double getY() { return yKoo; }
	virtual int vratiBrojZaposlenih() { return brojZaposlenihPutnicka; }
	char* getTip() { return tip; }
	virtual int vratiBrProdatih() { return brojProdatihPutnickih; }
	virtual void uvecaj(int broj) { brojProdatihPutnickih+= broj; }
	virtual ~SalonPutnicka();
	virtual double efikasnost();
	virtual void ispisi(ostream& izlaz);
};
