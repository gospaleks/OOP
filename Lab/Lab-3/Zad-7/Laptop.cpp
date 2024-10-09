#include "Laptop.h"
#include <iostream>
using namespace std;

Laptop::Laptop()
{
	opis = nullptr;
	stanje = 0;
}

Laptop::Laptop(char* nnaziv, double ccena,char* oopis, bool sstanje)
	:Artikal(nnaziv, ccena) {
	opis = new char[strlen(oopis) + 1];
	strcpy(opis, oopis);
	stanje = sstanje;
}

Laptop::~Laptop()
{
	if (opis != nullptr)
		delete [] opis;
}

void Laptop::showDescription()
{
	Artikal::showDescription();
	cout << opis << endl;
}

void Laptop::turnOn()
{
	if (stanje == 0) {
		stanje = 1;
		cout << "Laptop ukljucen.\n";
	}
	else {
		cout << "Laptop vec ukljucen.\n";
	}
}

void Laptop::turnOff()
{
	if (stanje == 1) {
		stanje = 0;
		cout << "Laptop iskljucen.\n";
	}
	else {
		cout << "Laptop vec iskljucen.\n";
	}
}


