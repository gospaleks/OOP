#include "ZlatnaPoluga.h"
#include <fstream>
#include <iostream>
using namespace std;
ZlatnaPoluga::ZlatnaPoluga()
	:Predmet() {
	stepenCistoce = 0;
}

ZlatnaPoluga::ZlatnaPoluga(double m, double sc)
	:Predmet(m, (((sc > 24) ? 24 : sc)/24)*m) {
	if (sc > 24)
		stepenCistoce = 24;
	else
		stepenCistoce = sc;
}

void ZlatnaPoluga::prikazi(ostream& izlaz)
{
	izlaz << "ZLATNA POLUGA - ";
	izlaz << "Stepen cistoce: " << stepenCistoce << ", Masa: " << vratiMasu() << ", Vrednost: " << vratiVrednost() << endl;
}

