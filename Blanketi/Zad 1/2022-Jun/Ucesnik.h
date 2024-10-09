#pragma once
#include <iostream>
using namespace std;
class Ucesnik
{
protected:
	int redniBroj;
	char* ime;
	char* prezime;
	int poeniPublike;
public:
	Ucesnik();
	Ucesnik(int rredniBroj, char* iime, char* pprezime, int ppoeniPublike);
	virtual ~Ucesnik();
	int GetredniBroj() { return redniBroj; }
	virtual int ukupnoPoena() = 0;
	virtual double brPomocnogOsoblja() = 0;
	virtual void ispisi(ostream& izlaz) = 0;
	virtual bool prolazi() = 0;
};

