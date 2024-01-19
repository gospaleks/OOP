#include "Knjiga.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void Knjiga::Kreiraj(const char* _naslov, const char* _autor, int _brojStrana, int _tiraz)
{
	if (_brojStrana <= 0)
		throw exception("Broj strana mora biti pozitivan.");
	else
		brojStrana = _brojStrana;

	if (_tiraz < 200)
		throw exception("Tiraz mora biti najmanje 200 primeraka.");
	else
		tiraz = _tiraz;

	if (_naslov != nullptr) {
		naslov = new char[strlen(_naslov) + 1];
		strcpy(naslov, _naslov);
	}
	else
		naslov = nullptr;

	if (_autor != nullptr) {
		autor = new char[strlen(_autor) + 1];
		strcpy(autor, _autor);
	}
	else
		autor = nullptr;

}

void Knjiga::OslobodiMem()
{
	if (naslov != nullptr)
		delete[] naslov;
	if (autor != nullptr)
		delete[] autor;
}

Knjiga::Knjiga()
{
	naslov = nullptr;
	autor = nullptr;
	brojStrana = tiraz = 0;
}

Knjiga::Knjiga(const char* _naslov, const char* _autor, int _brojStrana, int _tiraz)
{
	Kreiraj(_naslov, _autor, _brojStrana, _tiraz);
}

Knjiga::~Knjiga()
{
	OslobodiMem();
}

Knjiga::Knjiga(const Knjiga& k)
{
	OslobodiMem();
	Kreiraj(k.naslov, k.autor, k.brojStrana, k.tiraz);
}

Knjiga& Knjiga::operator=(const Knjiga& k)
{
	if (this != &k) {
		OslobodiMem();
		Kreiraj(k.naslov, k.autor, k.brojStrana, k.tiraz);
	}
	return *this;
}

bool Knjiga::operator==(Knjiga& k)
{
	return ((!strcmp(naslov, k.naslov)) &&
			(!strcmp(autor, k.autor)) &&
			brojStrana == k.brojStrana &&
			tiraz == k.tiraz);
}

bool Knjiga::operator>(Knjiga& k)
{
	if (strcmp(naslov, k.naslov) > 0)
		return true;
	else if (strcmp(autor, k.autor) > 0)
		return true;
	else if (brojStrana > k.brojStrana)
		return true;
	else
		return (tiraz > k.tiraz);
}

ostream& operator<<(ostream& izlaz, const Knjiga& k)
{
	return izlaz << k.naslov << " " << k.autor << " " << k.brojStrana << " " << k.tiraz;
}

istream& operator>>(istream& ulaz, Knjiga& k)
{
	char _naslov[100];
	char _autor[100];
	int _brojStrana;
	int _tiraz;
	ulaz >> _naslov >> _autor >> _brojStrana >> _tiraz;
	k.Kreiraj(_naslov, _autor, _brojStrana, _tiraz);
	return ulaz;
}
