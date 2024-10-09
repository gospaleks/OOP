#pragma once
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;

class Karta
{
protected:
	char* vrsta;
	int id;
	int redniBrojDana;
	int brojDanaVazenja;
	double osnovnaCenaKarte;
	double popust;
public:
	Karta();
	Karta(const char* _vrsta, int _id, int _redniBrojDana, int _brojDanaVazenja, double _osnCena, double _popust);

	~Karta() {
		if (vrsta != nullptr)
			delete vrsta;
	}
	
	int getId() { return id; }
	int getBrojDanaVazenja() { return brojDanaVazenja; }
	int getRedniBrojDana() { return redniBrojDana; }
	char* getVrsta() { return vrsta; }

	virtual double getCena() = 0;
	virtual void produzi(int _za) = 0;
	
	virtual void prikazi(ostream& izlaz);
};

