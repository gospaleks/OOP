#pragma once
#include <fstream>
#include <iostream>
using namespace std;
class Predmet
{
private:
	double masa;
	double vrednost;
public:
	Predmet();
	Predmet(double m, double v);
	virtual ~Predmet() { }

	double vratiVrednost();
	double vratiMasu();
	virtual void prikazi(ostream& izlaz) = 0;
};

