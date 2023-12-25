#pragma once
#include <iostream>
using namespace std;

class Domacinstvo
{
protected:
	int brojDom;
	double povrsinaObjekti;
	double potrosnja;
public:
	Domacinstvo();
	Domacinstvo(int bbrojDom, double po, double ppotrosnja);
	virtual ~Domacinstvo();
	int GetbrojDom() { return brojDom; }
	virtual double cenaPotrosnje(double cena) { return potrosnja * cena; }
	double GetpovrsinaObjekti() { return povrsinaObjekti; }
	double Getpotrosnja() { return potrosnja; }
	virtual void ispisi(ostream& izlaz);
};

// brojDom;
// povrsinaObjekti;
// potrosnja;