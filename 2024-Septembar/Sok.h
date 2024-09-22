#pragma once
#include "Pice.h"
#include <string.h>
using namespace std;

class Sok : public Pice
{
private:
	char* ukusSoka;
	int procenat;
	float odnosCene;

public:
	Sok();
	Sok(float zapremina, char* ukusSoka, int procenat, float odnosCene);
	~Sok();

	int getProcenat() { return procenat; }
	float getOdnosCene() { return odnosCene; }
	char* getUkusSoka() { return ukusSoka; }

	void Prikazi(ostream& izlaz);
	char Tip() { return 'S'; }
	bool operator==(Pice& p);
	float cena();
};

