#include "PojedinacniPaket.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

PojedinacniPaket::PojedinacniPaket(double brMin, double kolPod)
	: Paket((char*)"Pojedinacni_paket", brMin, kolPod) {
}

PojedinacniPaket::~PojedinacniPaket()
{
}

void PojedinacniPaket::prikazi(ostream& izlaz)
{
	Paket::prikazi(izlaz);
	izlaz << setw(30) << left << "Za uplatu: " << zaUplatu() << " din" << endl;
	izlaz << "------------------------------------------------\n\n";
}

double PojedinacniPaket::zaUplatu()
{
	return (brPretplMin * cenaMinuta) + (kolPodataka * cenaPoJedGB);
}

double PojedinacniPaket::vratiBrojPretplMin()
{
	return brPretplMin;
}
