#pragma once
#include <fstream>
using namespace std;
class Poklon
{
protected:
	double cena;
	int brojMasnica;

public:
	Poklon();
	Poklon(double cena, double brojMasnica);
	Poklon(const Poklon& p);
	virtual ~Poklon();

	virtual void print(ostream& izlaz) const ;
	friend ostream& operator<<(ostream& izlaz, const Poklon& p);

	virtual int vratiBrojMasnica() const = 0;
};

