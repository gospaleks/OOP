#pragma once
#include <iostream>
using namespace std;

class Pice
{
protected:
	float zapremina;
	int brAmbalaza;

public:
	Pice();
	Pice(float zapremina, int brAmbalaza);
	virtual ~Pice();

	// Getteri
	float getZapremina() { return zapremina; }
	int getBrAmbalaza() { return brAmbalaza; }
	virtual int getProcenat() = 0;
	virtual float getOdnosCene() = 0;
	virtual char* getUkusSoka() = 0;


	friend ostream& operator<<(ostream& izlaz, Pice& p);
	virtual void Prikazi(ostream& izlaz);

	virtual char Tip() = 0;
	virtual bool operator==(Pice& p) = 0;

	void promeniBrAmbalazaZa(int za) { brAmbalaza += za; }

	virtual float cena() = 0;
};

