#include "Posetilac.h"
#include <iostream>
#include <string.h>
using namespace std;

Posetilac::Posetilac()
{
	b_termina = cena = zainteresovanost = 0;
	ime = nullptr;
	prezime = nullptr;
}

Posetilac::Posetilac(int bt, char* ime, char* prezime)
{
	b_termina = bt;
	this->ime = new char[strlen(ime) + 1];
	strcpy(this->ime, ime);
	this->prezime = new char[strlen(prezime) + 1];
	strcpy(this->prezime, prezime);
	zainteresovanost = cena = 0;
}
