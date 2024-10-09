#pragma once
#include "Protivnik.h"
#include <fstream>
#define NMAX 2331
using namespace std;

class Skup
{
private:
	Protivnik* niz[NMAX];
public:
	Skup();
	~Skup();
	void sort(char p);
	void setI(Protivnik* p, int i);
	void ispisi(ostream& izlaz);
};

