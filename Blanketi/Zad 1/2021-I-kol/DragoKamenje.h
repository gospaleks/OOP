#pragma once
#include "Predmet.h"
#include <fstream>
#include <iostream>
using namespace std;
class DragoKamenje : public Predmet
{
private:
	double cistoca;
	char* boja;
	int brojStranica;
public:
	DragoKamenje();
	DragoKamenje(double m, double c, char* b, int br);
	~DragoKamenje();
	virtual void prikazi(ostream& izlaz);
};

