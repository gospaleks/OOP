#include "DragoKamenje.h"
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;
DragoKamenje::DragoKamenje()
	: Predmet() {
	cistoca = 0.0;
	boja = nullptr;
	brojStranica = 0;
}

DragoKamenje::DragoKamenje(double m, double c, char* b, int br)
	: Predmet(m, m+c) {
	cistoca = c;
	boja = new char[strlen(b) + 1];
	strcpy(boja, b);
	brojStranica = br;
}

DragoKamenje::~DragoKamenje()
{
	if (boja != nullptr)
		delete[] boja;
}

void DragoKamenje::prikazi(ostream& izlaz)
{
	izlaz << "DRAG KAMEN - ";
	izlaz << "Koef cistoce: " << cistoca << ", Boja: " << boja << ", Broj stranica: " << brojStranica << ", Masa: " << vratiMasu() << ", Vrednost: " << vratiVrednost() << endl;
}



