#pragma once
#include "Protivnik.h"
#include <fstream>
using namespace std;
class Azdaja : public Protivnik
{
private:
	double S, K, T, U;
public:
	Azdaja() :Protivnik((char*)"azdaja", 0, 0) { S = K = U = T = 0; }
	Azdaja(double ss, double kk, double tt, double uu);
	virtual ~Azdaja();
	virtual void output(ostream& izlaz);
};

