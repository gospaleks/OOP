#include "Poklon.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

Poklon::Poklon()
{
	tip = nullptr;
	masaUkrasneAmbalaze = 0;
}

Poklon::Poklon(const char* _tip, double _masaUkrasneAmbalaze)
{
	masaUkrasneAmbalaze = _masaUkrasneAmbalaze;
	tip = new char[strlen(_tip) + 1];
	strcpy(tip, _tip);
}

Poklon::~Poklon()
{
	if (tip != nullptr)
		delete[] tip;
}

void Poklon::prikazi(ostream& izlaz)
{
	izlaz << left << setw(25) << tip << endl;
	izlaz << left << setw(25) << "MASA AMBALAZE: " << masaUkrasneAmbalaze << endl;
}

