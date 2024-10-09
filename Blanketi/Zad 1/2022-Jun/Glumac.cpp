#include "Glumac.h"

Glumac::Glumac()
{
	brRekvizita = 0;
	brPoenaZirijaIdeja = 0;
	brPoemaZirijaIzvodjenje = 0;
}

Glumac::Glumac(int rb, char* ime, char* pr, int pp, int br, int bpzi, int bpziz)
	: Ucesnik(rb, ime, pr, pp)
{
	brRekvizita = br;
	if (bpzi > 50)
		brPoenaZirijaIdeja = 50;
	else if (bpzi < 0)
		brPoenaZirijaIdeja = 0;
	else
		brPoenaZirijaIdeja = bpzi;
	if (bpziz > 50)
		brPoemaZirijaIzvodjenje = 50;
	else if (bpziz < 0)
		brPoemaZirijaIzvodjenje = 0;
	else 
		brPoemaZirijaIzvodjenje = bpziz;
}

Glumac::~Glumac()
{
}

int Glumac::ukupnoPoena()
{
	int rez = poeniPublike + brPoenaZirijaIdeja + brPoemaZirijaIzvodjenje;
	return rez;
}

void Glumac::ispisi(ostream& izlaz)
{
	izlaz << "GLUMAC: " << endl
		<< "Redni Broj: " << redniBroj << endl
		<< "Ime: " << ime << endl
		<< "Prezime: " << prezime << endl
		<< "Poeni Publike: " << poeniPublike << endl
		<< "Broj Rekvizita: " << brRekvizita << endl
		<< "Broj poena zirija za ideju: " << brPoenaZirijaIdeja << endl
		<< "Broj poena zirija za izvodjenje: " << brPoemaZirijaIzvodjenje << endl
		<< endl << endl;
}

bool Glumac::prolazi()
{
	if (brPoenaZirijaIdeja >= 25 && brPoemaZirijaIzvodjenje >= 25 && ukupnoPoena() > 100)
		return true;
	else
		return false;
}

double Glumac::brPomocnogOsoblja()
{
	double rez = (double)brRekvizita / 2;
	return rez;
}
// redniBroj;
// ime;
// prezime;
// poeniPublike;
// broj Rekvizita
// broj Poena zirija za ideju
// broj Poena zirija za izvodjenje