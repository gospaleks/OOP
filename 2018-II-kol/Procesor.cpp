#include "Procesor.h"
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

void Procesor::Kreiraj(const char* _naziv, float _brzina, int _brojJezgara, float _kolKesa)
{
	if (_naziv != nullptr) {
		naziv = new char[strlen(_naziv) + 1];
		strcpy(naziv, _naziv);
	}
	else
		naziv = nullptr;

	brzina = _brzina;
	brojJezgara = _brojJezgara;
	kolKesa = _kolKesa;
}

void Procesor::OslobodiMem()
{
	if (naziv != nullptr)
		delete[] naziv;
}

Procesor::Procesor()
{
	naziv = nullptr;
	brzina = kolKesa = 0.0f;
	brojJezgara = 0;
}

Procesor::Procesor(const char* _naziv, float _brzina, int _brojJezgara, float _kolKesa)
{
	Kreiraj(_naziv, _brzina, _brojJezgara, _kolKesa);
}

Procesor::~Procesor()
{
	OslobodiMem();
}

Procesor::Procesor(const Procesor& p)
{
	// OslobodiMem();
	Kreiraj(p.naziv, p.brzina, p.brojJezgara, p.kolKesa);
}

Procesor& Procesor::operator=(const Procesor& p)
{
	if (this != &p) {
		OslobodiMem();
		Kreiraj(p.naziv, p.brzina, p.brojJezgara, p.kolKesa);
	}
	return *this;
}

float Procesor::GetVrednost()
{
	return (brzina * brojJezgara);
}

bool Procesor::operator==(Procesor& p)
{
	return (GetVrednost() == p.GetVrednost());
}

bool Procesor::operator>(Procesor& p)
{
	return (GetVrednost() > p.GetVrednost());
}
