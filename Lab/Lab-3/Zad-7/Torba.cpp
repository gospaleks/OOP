#include "Torba.h"
#include "Laptop.h"
#include <iostream>
using namespace std;
Torba::Torba()
{
	sadrzaj = nullptr;
}

Torba::Torba(char* nnaziv, double ccena)
	:Artikal(nnaziv, ccena) {
	sadrzaj = nullptr;
}

Torba::Torba(char* nnaziv, double ccena, Artikal* ssadrzaj)
	:Artikal(nnaziv, ccena), sadrzaj(ssadrzaj) {
}

Torba::~Torba()
{
	if (sadrzaj != nullptr)
		delete sadrzaj;
}

void Torba::showDescription()
{
	cout << "-------------------------------\n";
	cout << "Torba za Laptop racunar.\n";
	Artikal::showDescription();
	if (sadrzaj != nullptr)
		sadrzaj->showDescription();
	cout << "-------------------------------\n";
}

void Torba::put(Artikal& a)
{
	if (sadrzaj == nullptr) {
		sadrzaj = &a;
		cout << "Artikal smesten.\n";
	}
	else {
		cout << "Torba puna. Artikal nije smesten.\n";
	}
}

void Torba::remove()
{
	if (sadrzaj != nullptr) {
		delete sadrzaj;
		sadrzaj = nullptr;
		cout << "Ispraznjena torba.\n";
	}
}


