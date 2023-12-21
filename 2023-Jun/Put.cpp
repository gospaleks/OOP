#include "Put.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

Put::Put()
{
	imeGrada = nullptr;
	maxBrPutnika = 0;
	brojNocenja = 0;
	cenaPoNocenju = 0;
}

Put::Put(char* _imeGrada, int _maxBrPutnika, int _brojNocenja, double _cenaPoNocenju)
{
	imeGrada = new char[strlen(_imeGrada) + 1];
	strcpy(imeGrada, _imeGrada);

	maxBrPutnika = _maxBrPutnika;
	brojNocenja = _brojNocenja;
	cenaPoNocenju = _cenaPoNocenju;
}

Put::~Put()
{
	if (imeGrada != nullptr)
		delete[] imeGrada;
}

void Put::prikaziPut(ostream& izlaz)
{
	izlaz << left << setw(25) << "IME GRADA: ";
	izlaz << left << imeGrada << endl;

	izlaz << left << setw(25) << "MAX BR PUTNIKA: ";
	izlaz << left << maxBrPutnika << endl;

	izlaz << left << setw(25) << "BR NOCENJA: ";
	izlaz << left << brojNocenja << endl;

	izlaz << left << setw(25) << "CENA PO NOCENJU: ";
	izlaz << left << cenaPoNocenju << endl;
}


