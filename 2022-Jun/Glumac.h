#pragma once
#include "Ucesnik.h"
class Glumac : public Ucesnik
{
	int brRekvizita;
	int brPoenaZirijaIdeja;
	int brPoemaZirijaIzvodjenje;
public:
	Glumac();
	Glumac(int rb, char* ime, char* pr, int pp, int br,
		int bpzi, int bpziz);
	virtual ~Glumac();
	virtual int ukupnoPoena();
	virtual void ispisi(ostream& izlaz);
	virtual bool prolazi();
	virtual double brPomocnogOsoblja();
};




// redniBroj;
// ime;
// prezime;
// poeniPublike;
// broj Rekvizita
// broj Poena zirija za ideju
// broj Poena zirija za izvodjenje
