#include "Azdaja.h"
#include <iostream>
using namespace std;

Azdaja::Azdaja(double ss, double kk, double tt, double uu)
	:Protivnik((char*)"azdaja", tt * (1 + kk) * uu, ss * kk) {
	S = ss;
	K = kk;
	T = tt;
	U = uu;
}

Azdaja::~Azdaja()
{
}

void Azdaja::output(ostream& izlaz)
{
	izlaz << "ime: " << ime << ", " << S << ", " << K << ", " << T << ", " << U << ", B = " << B << ", M = " << M << endl;
}
