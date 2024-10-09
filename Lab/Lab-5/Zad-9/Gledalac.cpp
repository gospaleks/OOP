#include "Gledalac.h"
#include<string.h>
#include<iomanip>
#include<iostream>
#include<fstream>

Gledalac::Gledalac()
{
	strcpy(ime, "__________");
	strcpy(prezime, "__________");
	starost = 0;
	ocena = 0;
	prisutan = 0;
}

Gledalac::Gledalac(char* iime, char * pprezime, int sstarost, float oocena, bool pprisutan)
{
	strcpy(ime, iime);
	strcpy(prezime, pprezime);
	starost = sstarost;
	ocena = oocena;
	prisutan = pprisutan;
}

Gledalac::~Gledalac()
{
}

istream& operator>>(istream& ulaz, Gledalac& g)
{
	ulaz >> g.prisutan;
	if (g.prisutan)
	{
		ulaz >> g.ime >> g.prezime >> g.ocena >> g.starost;
	}
	else
	{
		// ovde kripimo nekako da preskocimo red
		char ime[100];
		ulaz.get(ime, 100);
	} 
	
	return ulaz;
}

ostream& operator<<(ostream& izlaz, Gledalac& g)
{
	return izlaz << setw(10) << g.ime << " " << setw(10) << g.prezime
		<< " (" << g.starost << ", " << g.ocena << ")";
	
	return izlaz;
}
