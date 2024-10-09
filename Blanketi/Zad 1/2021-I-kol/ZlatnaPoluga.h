#pragma once
#include "Predmet.h"
#include <fstream>
#include <iostream>
using namespace std;
class ZlatnaPoluga : public Predmet
{
private:
	double stepenCistoce;
public:
	ZlatnaPoluga();
	ZlatnaPoluga(double m, double sc);
	virtual void prikazi(ostream& izlaz);
};

