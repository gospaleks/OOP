#include "Jabuka.h"
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;
Jabuka::Jabuka()
	: Predmet() {
	ks = kk = 0;
	boja = nullptr;
}

Jabuka::Jabuka(double m, double kks, double kkk, char* b)
	: Predmet(m, ( (kks<0.5||kkk<0.5) ? 0 : (kks*kkk*m*1000)  ) ) {
	
	ks = kks;
	kk = kkk;
	boja = new char[strlen(b) + 1];
	strcpy(boja, b);
}

Jabuka::~Jabuka()
{
	if (boja != nullptr)
		delete[] boja;
}

void Jabuka::prikazi(ostream& izlaz)
{
	izlaz << "JABUKA - ";
	izlaz << "Koef slatkoce: " << ks << ", Koef kiselosti: " << kk << ", Boja: " << boja << ", Masa: " << vratiMasu() << ", Vrednost: " << vratiVrednost() << endl;
}
