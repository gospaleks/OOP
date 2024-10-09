#pragma once
#include "Ucesnik.h"
class Pevac : public Ucesnik
{
	char* pesma;
	int brInstrumenata;
	int brPratecihVokala;
	int poeniMuzickogZirija;
public:
	Pevac();
	Pevac(int rb, char* ime, char* prezime, int pp,
		char* ppesma, int bi, int bmw, int pmz);
	virtual ~Pevac();
	virtual int ukupnoPoena();
	virtual void ispisi(ostream& izlaz);
	virtual bool prolazi();
	virtual double brPomocnogOsoblja();
};


