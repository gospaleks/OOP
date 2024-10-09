#pragma once
#include "Cvet.h"
#include <iostream>
#include <fstream>
using namespace std;
class Lala : public Cvet
{
private:
	double masa;
public:
	static double cenaLalePoGramu;

	Lala(double _masa = 0);
	~Lala() { }

	virtual double getCena();
	virtual void ispisi(ostream& izlaz);
};

