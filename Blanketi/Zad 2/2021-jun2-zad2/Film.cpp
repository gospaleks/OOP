#include "Film.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void Film::Kreiraj(int _id, const char* _naziv, int _godina, float _ocena)
{
	id = _id;
	godina = _godina;
	ocena = _ocena;
	if (_naziv != nullptr)
	{
		naziv = new char[strlen(_naziv) + 1];
		strcpy(naziv, _naziv);
	}
	else {
		naziv = nullptr;
	}
}

Film::Film()
{
	id = 0;
	naziv = nullptr;
	godina = 0;
	ocena = 0;
}

Film::Film(int _id, const char* _naziv, int _godina, float _ocena)
{
	Kreiraj(_id, _naziv, _godina, _ocena);
}

Film::~Film()
{
	if (naziv != nullptr)
		delete[] naziv;
}

Film::Film(const Film& f)
{
	if (naziv != nullptr)
		delete[] naziv;
	Kreiraj(f.id, f.naziv, f.godina, f.ocena);
}

Film& Film::operator=(const Film& f)
{
	if (this != &f) {
		if (naziv != nullptr)
			delete[] naziv;
		Kreiraj(f.id, f.naziv, f.godina, f.ocena);
	}

	return *this;
}

bool Film::operator<(float x)
{
	return (ocena < x);
}

Film& Film::operator=(float _ocena)
{
	ocena = _ocena;
	return *this;
}

bool Film::operator==(float x)
{
	return (ocena == x);
}

bool Film::operator<(const Film& f)
{
	return (ocena < f.ocena);
}

bool Film::operator>(const Film& f)
{
	return (ocena > f.ocena);
}

ostream& operator<<(ostream& izlaz, const Film& f)
{
	return izlaz << f.id << " " << f.naziv << " " << f.godina << " " << f.ocena;
}

istream& operator>>(istream& ulaz, Film& f)
{
	int _id, _godina;
	float _ocena;
	char n[100];
	ulaz >> _id;
	ulaz >> n;
	ulaz >> _godina >> _ocena;

	f.Kreiraj(_id, n, _godina, _ocena);

	return ulaz;
}
