#pragma once
#include "Cvet.h"

class Ruza : public Cvet
{
private:
	int R;
	int G;
	int B;
public:
	static double cenaSavrseneRuze;

	Ruza(int r = 0, int g = 0, int b = 0);
	~Ruza() { }

	virtual double getCena();
	virtual void ispisi(ostream& izlaz);
};

