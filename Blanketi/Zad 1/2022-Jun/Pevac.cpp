#include "Pevac.h"

Pevac::Pevac()
{
	pesma = nullptr;
	brInstrumenata = 0;
	brPratecihVokala = 0;
	poeniMuzickogZirija = 0;
}

Pevac::Pevac(int rb, char* ime, char* prezime, int pp, char* ppesma, int bi, int bmw, int pmz)
	: Ucesnik(rb, ime, prezime, pp)
{
	pesma = new char[strlen(ppesma) + 1];
	strcpy(pesma, ppesma);
	brInstrumenata = bi;
	brPratecihVokala = bmw;
	if (pmz > 100)
		poeniMuzickogZirija = 100;
	else if (pmz < 0)
		poeniMuzickogZirija = 0;
	else
		poeniMuzickogZirija = pmz;
}

Pevac::~Pevac()
{
	if (pesma != nullptr)
		delete[] pesma;
}

int Pevac::ukupnoPoena()
{
	int rez = poeniPublike + poeniMuzickogZirija;
	return rez;
}

void Pevac::ispisi(ostream& izlaz)
{
	izlaz << "PEVAC: " << endl
		<< "Redni Broj: " << redniBroj << endl
		<< "Ime: " << ime << endl
		<< "Prezime: " << prezime << endl
		<< "Poeni Publike: " << poeniPublike << endl
		<< "Pesma: " << pesma << endl
		<< "Broj Instrumenata: " << brInstrumenata << endl
		<< "Broj Pratecih Vokala: " << brPratecihVokala << endl
		<< "Poeni Muzickog Zirija: " << poeniMuzickogZirija << endl
		<< endl << endl;
}

bool Pevac::prolazi()
{
	if (poeniMuzickogZirija >= 50 && ukupnoPoena() > 100)
		return true;
	else
		return false;
}

double Pevac::brPomocnogOsoblja()
{
	double rez = (double)brInstrumenata + (double)brPratecihVokala;
	return rez;
}

// redniBroj;
// ime;
// prezime;
// poeniPublike;
// pesma
// broj instrumenata
// broj pratecih vokala
// poeni muzickog zirija
