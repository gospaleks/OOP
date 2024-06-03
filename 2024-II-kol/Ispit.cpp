#include "Ispit.h"

void Ispit::zauzmiMem(const char* naziv, int ocena, int espb)
{
	this->naziv = new char[strlen(naziv) + 1];
	strcpy(this->naziv, naziv);
	this->ocena = ocena;
	this->espb = espb;
}

Ispit::Ispit()
{
	naziv = nullptr;
	ocena = espb = 0;
}

Ispit::Ispit(const char* naziv, int ocena, int espb)
{
	zauzmiMem(naziv, ocena, espb);
}

Ispit::~Ispit()
{
	if (naziv)
		delete[] naziv;
}

Ispit::Ispit(const Ispit& i)
{
	zauzmiMem(i.naziv, i.ocena, i.espb);
}

float Ispit::operator+(float leviOp)
{
	return this->ocena + leviOp;
}

Ispit& Ispit::operator=(const Ispit& i)
{
	if (this != &i) {
		if (naziv)
			delete [] naziv;
		naziv = new char[strlen(i.naziv) + 1];
		strcpy(naziv, i.naziv);
		this->ocena = i.ocena;
		this->espb = i.espb;
	}
	return *this;
}

bool Ispit::operator>(Ispit& s)
{
	return this->espb > s.espb;
}

ostream& operator<<(ostream& izlaz, Ispit& i)
{
	izlaz << i.naziv << " " << i.ocena << " " << i.espb;
	return izlaz;
}

istream& operator>>(istream& ulaz, Ispit& i)
{
	char n[100];
	int oc, es;
	ulaz >> n >> oc >> es;
	i.zauzmiMem(n, oc, es);
	return ulaz;
}
