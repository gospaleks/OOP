#include "Student.h"

void Student::zauzmi(const char* iindeks, const char* iime, const char* pprezime, float pprosek)
{
	indeks = new char[strlen(iindeks) + 1];
	ime = new char[strlen(iime) + 1];
	prezime = new char[strlen(pprezime) + 1];
	strcpy(indeks, iindeks);
	strcpy(ime, iime);
	strcpy(prezime, pprezime);
	prosek = pprosek;
}

Student::Student()
{
	indeks = nullptr;
	ime = nullptr;
	prezime = nullptr;
	prosek = 0;
}

Student::Student(const char* iindeks, const char* iime, const char* pprezime, float pprosek)
{
	zauzmi(iindeks, iime, pprezime, pprosek);
}

// TREBALO BI DA SE NAPRAVI POM F-JA void OslobodiMem(); JER IMA DUPLIRANJE KODA
Student::~Student()
{
	if (indeks != nullptr)
		delete [] indeks;
	if (ime != nullptr)
		delete [] ime;
	if (prezime != nullptr)
		delete [] prezime;
}

Student::Student(const Student& s)
{
	if (indeks != nullptr)
		delete [] indeks;
	if (ime != nullptr)
		delete [] ime;
	if (prezime != nullptr)
		delete [] prezime;
	zauzmi(s.indeks, s.ime, s.prezime, s.prosek);
}

bool Student::operator<(Student& s)
{
	return (prosek < s.prosek);
}

bool Student::operator>(Student& s)
{
	return (prosek > s.prosek);
}

Student& Student::operator=(Student& s)
{
	if (this != &s) {
		if (indeks != nullptr)
			delete [] indeks;
		if (ime != nullptr)
			delete [] ime;
		if (prezime != nullptr)
			delete [] prezime;
		zauzmi(s.indeks, s.ime, s.prezime, s.prosek);
	}
	return *this;
}

bool Student::operator==(Student& s)
{
	return (prosek == s.prosek);
}

ostream& operator<<(ostream& izlaz, Student& s)
{
	cout << s.indeks << " " << s.ime << " "
		<< s.prezime << " " << s.prosek;
	return izlaz;
}

istream& operator>>(istream& ulaz, Student& s)
{
	char ind[40];
	char _ime[40];
	char _prez[40];
	float pr;
	ulaz >> ind >> _ime >> _prez >> pr;
	s.zauzmi(ind, _ime, _prez, pr);
	return ulaz;
}
