#include "Mantikor.h"
#include <iostream>
using namespace std;

Mantikor::Mantikor(double ii, double kk, double oo, double uu)
	:Protivnik((char*)"mantikor", 0.5 * (uu + oo) * kk, ii* (kk + oo + uu) / 3) {
	I = ii;
	K = kk;
	O = oo;
	U = uu;
}

Mantikor::~Mantikor()
{
}

void Mantikor::output(ostream& izlaz)
{
	izlaz << "ime: " << ime << ", " << I << ", " << K << ", " << O << ", " << U << ", B = " << B << ", M = " << M << endl;
}
