#include "BeliZecevi.h"
#include <iostream>
using namespace std;

BeliZecevi::BeliZecevi(double cc, double ww)
	:Protivnik((char*)"beliZec", ww, cc) {
	W = ww;
	C = cc;
}

BeliZecevi::~BeliZecevi()
{
}

void BeliZecevi::output(ostream& izlaz)
{
	izlaz << "ime: " << ime << ", " << C << ", " << W << ", B = " << B << ", M = " << M << endl;
}
