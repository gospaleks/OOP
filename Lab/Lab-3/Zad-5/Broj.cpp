#include "Broj.h"
#include <iostream>
#include <string.h>
using namespace std;

void Broj::PostaviVrednost(double vvrednost)
{
	vrednost = vvrednost;
}

Broj::Broj(char* vvrsta, double vvrednost)
{
	vrsta = new char[strlen(vvrsta)+1];
	strcpy(vrsta, vvrsta);
	vrednost = vvrednost;
}

Broj::Broj(char* vvrsta)
{
	vrsta = new char[strlen(vvrsta) + 1];
	strcpy(vrsta, vvrsta);
	vrednost = 0;
}

Broj::~Broj()
{
	if (vrsta != nullptr)
		delete [] vrsta;
}

void Broj::Print()
{
	cout << vrsta << " " << vrednost << endl;
}

double Broj::VratiVrednost()
{
	return vrednost;
}
