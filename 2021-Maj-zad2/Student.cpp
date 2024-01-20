#include "Student.h"
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

void Student::Kreiraj(int _brInd, const char* _ime, const char* _prezime, float _pOcena)
{
	if (_ime != nullptr) {
		ime = new char[strlen(_ime) + 1];
		strcpy(ime, _ime);
	}
	else
		ime = nullptr;

	if (_prezime != nullptr) {
		prezime = new char[strlen(_prezime) + 1];
		strcpy(prezime, _prezime);
	}
	else
		prezime = nullptr;

	brInd = _brInd;
	pOcena = _pOcena;
}

void Student::OslobodiMem()
{
	if (ime != nullptr)
		delete[] ime;

	if (prezime != nullptr)
		delete[] prezime;
}

Student::Student()
{
	ime = prezime = nullptr;
	brInd = 0;
	pOcena = 0.0f;
}

Student::Student(int _brInd, const char* _ime, const char* _prezime, float _pOcena)
{
	Kreiraj(_brInd, _ime, _prezime, _pOcena);
}

Student::~Student()
{
	OslobodiMem();
}

Student::Student(const Student& s)
{
	Kreiraj(s.brInd, s.ime, s.prezime, s.pOcena);
}

Student& Student::operator=(const Student& s)
{
	if (this != &s) {
		OslobodiMem();
		Kreiraj(s.brInd, s.ime, s.prezime, s.pOcena);
	}
	
	return *this;
}

bool Student::operator!=(Student& s)
{
	return (brInd != s.brInd);
}

bool Student::operator<(Student& s)
{
	return (brInd < s.brInd);
}

bool Student::operator>(Student& s)
{
	return (brInd > s.brInd);
}

ostream& operator<<(ostream& izlaz, const Student& s)
{
	return izlaz << s.brInd << " " << s.ime << " " << s.prezime << " " << s.pOcena;
}

istream& operator>>(istream& ulaz, Student& s)
{
	int b;
	char i[100];
	char p[100];
	float o;
	ulaz >> b >> i >> p >> o;
	s.Kreiraj(b, i, p, o);
	return ulaz;
}
