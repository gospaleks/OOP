#include "KutijaCokolade.h"
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

KutijaCokolade::KutijaCokolade()
	: Poklon() {
	ukupanBrojCokolada = 0;
	masaJedneCokolade = 0;
}

KutijaCokolade::KutijaCokolade(double _masaUkrasneAmbalaze, int _ukupanBrojCokolada, double _masaJedneCokolade)
	: Poklon("KutijaCokolade", _masaUkrasneAmbalaze) {
	ukupanBrojCokolada = _ukupanBrojCokolada;
	masaJedneCokolade = _masaJedneCokolade;
}

KutijaCokolade::~KutijaCokolade()
{
}

void KutijaCokolade::prikazi(ostream& izlaz)
{
	Poklon::prikazi(izlaz);
	izlaz << left << setw(25) << "UKUPAN BROJ COKOLADA: " << ukupanBrojCokolada << endl;
	izlaz << left << setw(25) << "MASA JEDNE COKOLADE: " << masaJedneCokolade << endl << endl;
}

double KutijaCokolade::getMasa()
{
	return (masaUkrasneAmbalaze + masaJedneCokolade * (double)ukupanBrojCokolada);
}


