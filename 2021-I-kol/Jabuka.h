#pragma once
#include "Predmet.h"
#include <fstream>
#include <iostream>
using namespace std;
class Jabuka : public Predmet
{
private:
	double ks;
	double kk;
	char* boja;
public:
	Jabuka();
	Jabuka(double m, double kks, double kkk, char* b);
	~Jabuka();
	virtual void prikazi(ostream& izlaz);
};

