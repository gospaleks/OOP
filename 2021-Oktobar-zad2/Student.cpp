#include "Student.h"
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
using namespace std;

Student::Student()
{
	ime = nullptr;
	prezime = nullptr;
	imeRoditelja = nullptr;
	prosek = 0;
}

Student::Student(const char* iime, const char* pprezime, const char* iimeRoditelja, float pprosek)
{
	zauzmichar(iime, pprezime, iimeRoditelja);
	prosek = pprosek;
}

Student::Student(Student& s)
{
	oslobodimem();
	zauzmichar(s.ime, s.prezime, s.imeRoditelja);
	prosek = s.prosek;
}

Student::~Student()
{
	oslobodimem();
}

Student& Student::operator=(const Student& s)
{
	if (this != &s) {
		oslobodimem();
		zauzmichar(s.ime, s.prezime, s.imeRoditelja);
		prosek = s.prosek;
	}
	return *this;
}

bool Student::operator==(Student& s)
{
	if (!(strcmp(ime, s.ime)))
		if (!(strcmp(prezime, s.prezime)))
			if (!(strcmp(imeRoditelja, s.imeRoditelja)))
				return true;
	return false;
}

void Student::zauzmichar(const char* iime, const char* pprezime, const char* iimeRoditelja)
{
	if(iime!=nullptr){
		ime = new char[strlen(iime) + 1];
		strcpy(ime, iime);
	}
	if(pprezime!=nullptr){
		prezime = new char[strlen(pprezime) + 1];
		strcpy(prezime, pprezime);
	}
	if(iimeRoditelja!=nullptr){
		imeRoditelja = new char[strlen(iimeRoditelja) + 1];
		strcpy(imeRoditelja, iimeRoditelja);
	}
}

void Student::oslobodimem()
{
	if (ime != nullptr)
		delete[] ime;
	if (prezime != nullptr)
		delete[] prezime;
	if (imeRoditelja != nullptr)
		delete[] imeRoditelja;
}

ostream& operator<<(ostream& izlaz, Student& s)
{
	izlaz << left << setw(20) << "ime:" << s.ime << endl
		<< left << setw(20) << "prezime:" << s.prezime << endl
		<< left << setw(20) << "imeRoditelja:" << s.imeRoditelja << endl
		<< left << setw(20) << "prosek:" << s.prosek << endl;
	return izlaz;
}
