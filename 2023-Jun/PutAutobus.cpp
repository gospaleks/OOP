#include "PutAutobus.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

PutAutobus::PutAutobus()
	: Put() {
	ukupnaKm = 0;
	cenaGorivaPoLitru = 0;
	potrosnja = 0;
	brojNociUAutobusu = 0;
}

PutAutobus::PutAutobus(char* _imeGrada, int _maxBrPutnika, int _brojNocenja, double _cenaPoNocenju, double _ukupnaKm, double _cenaGoriva, double _potrosnja, int _brojNociUAutobusu)
	: Put(_imeGrada, _maxBrPutnika, _brojNocenja, _cenaPoNocenju) {

	ukupnaKm = _ukupnaKm;
	cenaGorivaPoLitru = _cenaGoriva;
	potrosnja = _potrosnja;
	brojNociUAutobusu = _brojNociUAutobusu;
}

double PutAutobus::getCenaZaAgenciju()
{
	double utrosakGoriva = ((ukupnaKm * potrosnja) / 100) * cenaGorivaPoLitru;
	
	return (utrosakGoriva*1.25) + (maxBrPutnika*getCenaSmestaja());
}

double PutAutobus::getCenaPoPutniku()
{
	return ((this->getCenaZaAgenciju() / maxBrPutnika) * 1.35);
}

void PutAutobus::prikaziPut(ostream& izlaz)
{
	izlaz << left << setw(25) << "PUT AUTOBUSOM:" << endl;
	izlaz << "-----------------------------------\n";

	Put::prikaziPut(izlaz);

	izlaz << left << setw(25) << "UKUPNO KM: ";
	izlaz << left << ukupnaKm << endl;

	izlaz << left << setw(25) << "CENA GORIVA: ";
	izlaz << left << cenaGorivaPoLitru << endl;

	izlaz << left << setw(25) << "POTROSNJA: ";
	izlaz << left << potrosnja << endl;

	izlaz << left << setw(25) << "BROJ NOCI U AUTOBUSU: ";
	izlaz << left << brojNociUAutobusu << endl;

	izlaz << left << setw(25) << "CENA ZA AGENCIJU: ";
	izlaz << left << getCenaZaAgenciju() << endl;

	izlaz << left << setw(25) << "CENA PO PUTNIKU: ";
	izlaz << left << getCenaPoPutniku() << endl << endl;
}
