#pragma once
#include <fstream>
using namespace std;

class Vozilo
{
protected:
	char* naziv;
	char* reg;
	double maxBrzina;
	double potrosnja;
	void zauzmiMem(const char* _naziv, const char* _reg);
public:
	Vozilo();
	Vozilo(const char* _naziv, const char* _reg, double _maxBr, double _potrosnja);
	virtual ~Vozilo();

	virtual void ispisi(ostream& izlaz);
	virtual void citaj(istream& ulaz) = 0;
};



