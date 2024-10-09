#include "Sokovi.h"

void Sokovi::zauzmiMem(const char* nazivVoca, float zapremina, int procenatVoca)
{
	this->nazivVoca = new char[strlen(nazivVoca) + 1];
	strcpy(this->nazivVoca, nazivVoca);
	this->zapremina = zapremina;
	this->procenatVoca = procenatVoca;
}

void Sokovi::oslobodiMem()
{
	if (nazivVoca)
		delete[] nazivVoca;
}

Sokovi::Sokovi()
{
	nazivVoca = nullptr;
	zapremina = 0;
	procenatVoca = 0;
}

Sokovi::Sokovi(const char* nazivVoca, float zapremina, int procenatVoca)
{
	zauzmiMem(nazivVoca, zapremina, procenatVoca);
}

Sokovi::Sokovi(const Sokovi& s)
{
	zauzmiMem(s.nazivVoca, s.zapremina, s.procenatVoca);
}

Sokovi::~Sokovi()
{
	oslobodiMem();
}

Sokovi& Sokovi::operator=(const Sokovi& s)
{
	if (this != &s) {
		oslobodiMem();
		zauzmiMem(s.nazivVoca, s.zapremina, s.procenatVoca);
	}

	return *this;
}

bool Sokovi::operator<(const Sokovi& s)
{
	return this->zapremina < s.zapremina;
}

bool Sokovi::operator!=(const Sokovi& s)
{
	return !(*this == s);
}

bool Sokovi::operator==(const Sokovi& s)
{
	return this->zapremina == s.zapremina && strcmp(this->nazivVoca, s.nazivVoca) == 0 && this->procenatVoca == s.procenatVoca;
}

float Sokovi::operator+(float desni)
{
	return this->zapremina + desni;
}

float Sokovi::operator*(int desni)
{
	return this->zapremina * desni;
}

ostream& operator<<(ostream& izlaz, Sokovi& s)
{
	izlaz << s.nazivVoca << " " << s.zapremina << " " << s.procenatVoca;
	return izlaz;
}

istream& operator>>(istream& ulaz, Sokovi& s)
{
	char nazivVoca[100];
	float zapremina;
	int procenatVoca;

	ulaz >> nazivVoca >> zapremina >> procenatVoca;
	s.zauzmiMem(nazivVoca, zapremina, procenatVoca);

	return ulaz;
}
