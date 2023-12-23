#pragma once
#include "Poklon.h"
#include <fstream>
#include <iostream>
using namespace std;

class KutijaCokolade : public Poklon
{
private:
	int ukupanBrojCokolada;
	double masaJedneCokolade;
public:
	KutijaCokolade();
	KutijaCokolade(double _masaUkrasneAmbalaze, int _ukupanBrojCokolada, double _masaJedneCokolade);
	~KutijaCokolade();

	virtual void prikazi(ostream& izlaz);
	virtual double getMasa();
};

