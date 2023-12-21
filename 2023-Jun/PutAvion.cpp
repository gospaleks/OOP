#include "PutAvion.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

PutAvion::PutAvion()
	: Put() {
	imeKompanije = nullptr;
	duzTrajanjaLeta = 0;
	cenaMestaPoPutniku = 0;
}

PutAvion::PutAvion(char* _imeGrada, int _maxBrPutnika, int _brojNocenja, double _cenaPoNocenju, char* _imeKompanije, int _duzTrLeta, double _cenaMestaPoPutniku)
	: Put(_imeGrada, _maxBrPutnika, _brojNocenja, _cenaPoNocenju) {

	imeKompanije = new char[strlen(_imeKompanije) + 1];
	strcpy(imeKompanije, _imeKompanije);

	duzTrajanjaLeta = _duzTrLeta;
	cenaMestaPoPutniku = _cenaMestaPoPutniku;
}

PutAvion::~PutAvion()
{
	if (imeKompanije != nullptr)
		delete imeKompanije;
}

double PutAvion::getCenaZaAgenciju()
{
	return (maxBrPutnika * (cenaMestaPoPutniku + getCenaSmestaja()));
}

double PutAvion::getCenaPoPutniku()
{
	return (cenaMestaPoPutniku*1.30) + (getCenaSmestaja()*1.25);
}

void PutAvion::prikaziPut(ostream& izlaz)
{
	izlaz << left << setw(25) << "PUT AVIONOM:" << endl;
	izlaz << "-----------------------------------\n";
	
	Put::prikaziPut(izlaz);

	izlaz << left << setw(25) << "IME KOMPANIJE: ";
	izlaz << left << imeKompanije << endl;

	izlaz << left << setw(25) << "DUZ TRAJANJA LETA: ";
	izlaz << left << duzTrajanjaLeta << endl;

	izlaz << left << setw(25) << "CENA MESTA PO PUTNIKU: ";
	izlaz << left << cenaMestaPoPutniku << endl;

	izlaz << left << setw(25) << "CENA ZA AGENCIJU: ";
	izlaz << left << getCenaZaAgenciju() << endl;

	izlaz << left << setw(25) << "CENA PO PUTNIKU: ";
	izlaz << left << getCenaPoPutniku() << endl << endl;
}




