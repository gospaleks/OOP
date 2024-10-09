#include "Lala.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

double Lala::cenaLalePoGramu;

Lala::Lala(double _masa)
	: Cvet("Lala"), masa(_masa) {
}

double Lala::getCena()
{
	return (cenaLalePoGramu * masa);
}

void Lala::ispisi(ostream& izlaz)
{
	izlaz << "Lala -> (" << setw(3) << masa << "), " << setw(16) << "CENA: " << getCena() << "\n";
}
