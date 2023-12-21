#include "PorodicniPaket.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

PorodicniPaket::PorodicniPaket()
	: UpareniPaket() {
	brojDece = 0;
}

PorodicniPaket::PorodicniPaket(double brMin, double kolPod, double odnos, int brDece)
	: UpareniPaket((char*)"Porodicni_paket", brMin, kolPod, odnos) {
	brojDece = brDece;
	
	// 20% umanjenje + za svako dete do petog jos po 5%
	umanjenje(20);
	for (int i = 1; i < min(brojDece, 5); ++i)
		umanjenje(5);
}

PorodicniPaket::~PorodicniPaket()
{
}

double PorodicniPaket::vratiBrojPretplMin()
{
	// za oba clana plus za svako dete
	double rez = brPretplMin + (odnosParametraPaketa / 100) * brPretplMin;
	for (int i = 0; i < brojDece; ++i)
		rez += 0.5 * brPretplMin;
	return rez;
}

void PorodicniPaket::zameniProcentualniParametar(double novi)
{
	odnosParametraPaketa = novi;
}

void PorodicniPaket::zameniBrojDece(double novi)
{
	// OVDE MORA DA SE SREDE UMANJENJA!!!!
	// JER ZA SVAKO DETE IDE JOS PO 5%
	// AKO NEKO DETE NAPUNI 18god I NPR SE SMANJI BROJ DECE TREBA DA SE SREDI UMANJENJE CENE
	brojDece = novi;
}

void PorodicniPaket::prikazi(ostream& izlaz)
{
	Paket::prikazi(izlaz);
	izlaz << setw(30) << left << "Odnos parametra paketa: " << odnosParametraPaketa << "%\n";
	izlaz << setw(30) << left << "Broj dece: " << brojDece << endl;
	izlaz << setw(30) << left << "Za uplatu: " << zaUplatu() << " din" << endl;
	izlaz << "------------------------------------------------\n\n";
}

double PorodicniPaket::zaUplatu()
{
	// za prvog
	double rez = (brPretplMin * cenaMinuta) + (kolPodataka * cenaPoJedGB);

	// za drugog
	rez += ((odnosParametraPaketa / 100) * brPretplMin * cenaMinuta) + ((odnosParametraPaketa / 100) * kolPodataka * cenaPoJedGB);
	
	// deca imaju 50% od prvog
	for (int i = 0; i < brojDece; ++i)
		rez += (0.5*brPretplMin * cenaMinuta) + (0.5*kolPodataka * cenaPoJedGB);
	
	return rez;
}




