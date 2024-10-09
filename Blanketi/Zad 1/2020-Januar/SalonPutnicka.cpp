#include "SalonPutnicka.h"

SalonPutnicka::SalonPutnicka()
{
	strcpy(tip, "Putnicka");
	naziv = nullptr;
	brojZaposlenihPutnicka = 0;
	xKoo = 0;
	yKoo = 0;
	brojProdatihPutnickih = 0;
}

SalonPutnicka::SalonPutnicka(char* nnaziv, int bbrojZaposlenihPutnicka, double xxKoo, double yyKoo, int bbrojProdatihPutnickih)
{
	strcpy(tip, "Putnicka");
	naziv = new char[strlen(nnaziv) + 1];
	strcpy(naziv, nnaziv);
	brojZaposlenihPutnicka = bbrojZaposlenihPutnicka;
	xKoo = xxKoo;
	yKoo = yyKoo;
	brojProdatihPutnickih = bbrojProdatihPutnickih;
}

SalonPutnicka::~SalonPutnicka()
{
	if (naziv != nullptr)
		delete[] naziv;
}

double SalonPutnicka::efikasnost()
{
	double rez1 = brojProdatihPutnickih / brojZaposlenihPutnicka;
	return rez1;
}

void SalonPutnicka::ispisi(ostream& izlaz)
{
	izlaz << "SALON ZA PUTNICKA VOZILA: "
		<< "Naziv: " << naziv << endl
		<< "Broj Zaposlenih: " << brojZaposlenihPutnicka << endl
		<< "Koordinate: " << "(" << xKoo << ", " << yKoo << ")" << endl
		<< "Broj Prodathih Vozila: " << brojProdatihPutnickih << endl << endl << endl;
}
