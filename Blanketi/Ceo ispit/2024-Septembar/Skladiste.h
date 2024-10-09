#pragma once
#include "Pice.h"

class Skladiste
{
private:
	Pice** niz;
	int trBr;
	int maxBr;

public:
	Skladiste(int maxBr);
	~Skladiste();

	void Dodaj(Pice* p);
	friend ostream& operator<<(ostream& izlaz, Skladiste& s);
	void Izdvoji(Pice& p, int brAmbalaza);
	void Presipaj(Pice& vece, Pice& manje);
	void Izbaci(int i);
	bool DovoljnaKolicina(int nabavka);
	void VratiNaj(Pice** piceMin, Pice** piceMax);
};

