#pragma once
#include <fstream>
using namespace std;
class Protivnik
{
protected:
	char* ime;
	double B, M;
public:
	Protivnik();
	Protivnik(char* ime, double bb, double mm);
	virtual ~Protivnik();
	virtual void output(ostream& izlaz) = 0;
	double getB() { return B; }
	double getM() { return M; }
};

