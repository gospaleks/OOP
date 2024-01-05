#include "Proizvod.h"
#include <fstream>
#include <iostream>
#include <string.h>

Proizvod::Proizvod()
{
	naziv = nullptr;
	brojMeseciDoIsteka = 0;
	cena = 0.0f;
	koef = 0.0f;
}

Proizvod::Proizvod(const char* _naziv, int _brojMeseci, float _cena, float _koef)
{
	naziv = new char[strlen(_naziv) + 1];
	strcpy(naziv, _naziv);

	if (_brojMeseci <= 3)
		throw "Broj meseci do isteka mora biti veci od 3.";
	else 
		brojMeseciDoIsteka = _brojMeseci;
	
	if (_cena > 10000)
		throw "Cena ne sme biti veca od 10000 dinara";
	else 
		cena = _cena;

	koef = _koef;
}

Proizvod::~Proizvod()
{
	if (naziv != nullptr)
		delete[] naziv;
	naziv = nullptr;
}

float Proizvod::operator+(float x)
{
	// vrednost se racuna kao prozivod cene i koef
	return (cena * koef + x);
}

std::ostream& operator<<(std::ostream& izlaz, Proizvod& p)
{
	return izlaz << p.naziv << " "
		<< p.brojMeseciDoIsteka << " "
		<< p.cena << " "
		<< p.koef;
}

std::istream& operator>>(std::istream& ulaz, Proizvod& p)
{
	char tmpNaziv[100];
	ulaz >> tmpNaziv;
	p.naziv = new char[strlen(tmpNaziv) + 1];
	strcpy(p.naziv, tmpNaziv);
	ulaz >> p.brojMeseciDoIsteka >> p.cena >> p.koef;
	return ulaz;
}
