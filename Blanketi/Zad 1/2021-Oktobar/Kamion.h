#pragma once
#include "Vozilo.h"
#include <fstream>
using namespace std;

class Kamion : public Vozilo
{
private:
	double nosivost;
public:
	Kamion();
	Kamion(const char* _naziv, const char* _reg, double _maxBr, double _potrosnja, double _nosivost);
	~Kamion();

	virtual void ispisi(ostream& izlaz);
	virtual void citaj(istream& ulaz);

	// isto poredjenje i za kamion
	bool operator>(const Kamion& a);
	bool operator<(const Kamion& a);
};

