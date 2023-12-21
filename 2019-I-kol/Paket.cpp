#include "Paket.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

Paket::Paket()
{
	vrstaPaketa = nullptr;
	brPretplMin = 0;
	cenaMinuta = 0;
	kolPodataka = 0;
	cenaPoJedGB = 0;
}

Paket::Paket(char* vrsta, double brMin, double kolPod)
{
	vrstaPaketa = new char[strlen(vrsta) + 1];
	strcpy(vrstaPaketa, vrsta);

	// ovde resavam one uslove od-do
	if (brMin < 100) brPretplMin = 100;
	else if (brMin > 2000) brPretplMin = 200;
	else brPretplMin = brMin;

	if (kolPod < 1) kolPodataka = 1;
	else if (kolPod > 10) kolPodataka = 10;
	else kolPodataka = kolPod;

	// ovo preduzece odredjuje tkd ne unosim kroz konstruktor
	cenaMinuta = 1;
	cenaPoJedGB = 100;
}

Paket::~Paket()
{
	if (vrstaPaketa != nullptr)
		delete[] vrstaPaketa;
}

void Paket::zameniBrojPretplMin(double novi)
{
	if (novi < 100) brPretplMin = 100;
	else if (novi > 2000) brPretplMin = 200;
	else brPretplMin = novi;
}

void Paket::prikazi(ostream& izlaz)
{
	izlaz << vrstaPaketa << ":\n";
	izlaz << setw(30) << left << "Broj pretplatnih minuta: " << brPretplMin << endl;
	izlaz << setw(30) << left << "Kolicina podataka (GB): " << kolPodataka << endl;

	// izlaz << "------------------------------------------------\n\n";
}
