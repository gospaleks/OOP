#pragma once
#include <fstream>
#include <iostream>
using namespace std;

class Poklon
{
protected:
	char* tip;
	double masaUkrasneAmbalaze;
public:
	Poklon();
	Poklon(const char* _tip, double _masaUkrasneAmbalaze);
	virtual ~Poklon();

	virtual void prikazi(ostream& izlaz);
	virtual double getMasa() = 0;
};

