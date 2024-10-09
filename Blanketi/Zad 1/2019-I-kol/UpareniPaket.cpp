#include "UpareniPaket.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

UpareniPaket::UpareniPaket(double brMin, double kolPod, double odnos)
	: Paket((char*)"Upareni_paket", brMin, kolPod) {
	
	odnosParametraPaketa = odnos;
	umanjenje(15);
}

UpareniPaket::UpareniPaket(char* v, double brMin, double kolPod, double odnos)
	: Paket(v, brMin, kolPod) {

	odnosParametraPaketa = odnos;
	umanjenje(15);
}

UpareniPaket::~UpareniPaket()
{
}

void UpareniPaket::umanjenje(double procUm)
{
	this->cenaMinuta = this->cenaMinuta * ((100 - procUm) / 100);
	this->cenaPoJedGB = this->cenaPoJedGB * ((100 - procUm) / 100);
}

double UpareniPaket::vratiBrojPretplMin()
{
	// vrati za oba clana, za jednog ide umanjeno
	return brPretplMin + (odnosParametraPaketa / 100) * brPretplMin;
}

void UpareniPaket::zameniProcentualniParametar(double novi)
{
	odnosParametraPaketa = novi;
}

void UpareniPaket::prikazi(ostream& izlaz)
{
	Paket::prikazi(izlaz);
	izlaz << setw(30) << left << "Odnos parametra paketa: " << odnosParametraPaketa << "%\n";
	izlaz << setw(30) << left << "Za uplatu: " << zaUplatu() << " din" << endl;
	izlaz << "------------------------------------------------\n\n";
}

double UpareniPaket::zaUplatu()
{
	// za prvog
	double rez = (brPretplMin * cenaMinuta) + (kolPodataka * cenaPoJedGB);

	// za drugog
	rez += ((odnosParametraPaketa/100)*brPretplMin * cenaMinuta) + ((odnosParametraPaketa / 100)*kolPodataka * cenaPoJedGB);

	return rez;
}
