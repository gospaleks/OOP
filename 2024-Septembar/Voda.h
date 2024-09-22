#pragma once
#include "Pice.h"
class Voda : public Pice
{
public:
	Voda();
	Voda(float zapremina);
	~Voda();

	int getProcenat() { return 0; }
	float getOdnosCene() { return 1; }
	char* getUkusSoka() { return nullptr; }

	void Prikazi(ostream& izlaz);
	char Tip() { return 'V'; }
	bool operator==(Pice& p);
	float cena();
};

