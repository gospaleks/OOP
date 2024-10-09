#pragma once
#include "Displej.h"
#include<fstream>
using namespace std;

class DekadniMatricniDisplej : public Displej
{
private:
	int n, m;
	bool niz[7];
	bool** mat;
public:
	DekadniMatricniDisplej();
	DekadniMatricniDisplej(int ccifra);
	~DekadniMatricniDisplej();
	void ucitajCifru(istream& ulaz);
	void detektuj();
	void zauzmiMem(int nn, int mm);
	virtual void set(int ccifra);
	virtual void show();
	virtual void inc();
	void ispisiNaDisplej();
	void ispisiNa(ostream& izlaz);
};