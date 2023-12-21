#include "KolekcijaKupovina.h"
#include"RobaRate.h"
#include<iostream>
using namespace std;

KolekcijaKupovina::KolekcijaKupovina()
{
	nmax = brtr = 0;
	niz = nullptr;
}

KolekcijaKupovina::KolekcijaKupovina(int n)
{
	brtr = 0;
	zauzmimem(n);
}

void KolekcijaKupovina::ubacikupovinu(RobaKes* r)
{
	if (brtr < nmax)
		niz[brtr++] = r;
	else
		cout << "greska, nema dovoljno prostora!" << endl;
}

void KolekcijaKupovina::vratiproizvod(int kkod)
{
	int i = -1;
	while (i < brtr && niz[++i]->getsifra() != kkod);
	if (i == brtr - 1)
		cout << "greska, nepostojeca kupovina (neispravan kod)" << endl;
	else 
	{
		delete niz[i];
		for (int j = i; j < brtr; j++)
			niz[j] = niz[j + 1];
		niz[--brtr] = nullptr;
	}
}

void KolekcijaKupovina::ispissvihprodaja()
{
	for (int i = 0; i < brtr; i++)
	{
		cout << "kupovina " << i << ":" << endl;
		niz[i]->prikazi();
	}

}

void KolekcijaKupovina::vratiminmax(RobaKes* r1, RobaKes* r2)
{
	r1 = niz[0];
	r2 = niz[0];
	for (int i = 1; i < brtr; i++)
	{
		if (niz[i]->getcena() < r1->getcena())
			r1 = niz[i];
		if (niz[i]->getcena() > r2->getcena())
			r2 = niz[i];
	}
}

int KolekcijaKupovina::vratibrojkupovina(int dan1, int dan2, int sifra)
{
	int br = 0;
	for (int i = 0; i < brtr; i++)
		if (niz[i]->getkod() == sifra && niz[i]->getdan() >= dan1 && niz[i]->getdan() <= dan2)
			br++;
	return br;
}

float KolekcijaKupovina::ukupnacenaprodata(int dan1, int dan2)
{
	float ukupnacena = 0;
	for (int i = 0; i < brtr; i++)
		if (niz[i]->getdan() >= dan1 && niz[i]->getdan() <= dan2)
			ukupnacena += niz[i]->getcenasapopustom();
	return ukupnacena;
}

float KolekcijaKupovina::dugovanje(int dan1)
{
	float dug = 0;
	for (int i = 0; i < brtr; i++)
		if (niz[i]->getdan() >= dan1 && niz[i]->getrate() && niz[i]->getcenasapopustom() != niz[i]->getplacenodosad())
			dug += (niz[i]->getcenasapopustom() - niz[i]->getplacenodosad());
	return dug;
}

void KolekcijaKupovina::ucitaj(istream& ulaz)
{
	int n, r, kod, sifra, dan, cena, popust, uplaceno, brata, razmak, bplacenih;
	ulaz >> nmax;
	zauzmimem(nmax);
	ulaz >> n;
	for (int i = 0; i < n; i++)
	{
		ulaz >> r;
		if (!r)
		{
			ulaz >> kod >> sifra >> dan >> cena >> popust;
			ubacikupovinu(new RobaKes(kod, sifra, dan, cena, popust));
		}
		else
		{
			ulaz >> kod >> sifra >> dan >> cena >> popust >> uplaceno >> brata >> razmak >> bplacenih;
			ubacikupovinu(new RobaRate(kod, sifra, dan, cena, popust, uplaceno, brata, razmak, bplacenih));
		}
	}
}

void KolekcijaKupovina::zauzmimem(int nnmax)
{
	nmax = nnmax;
	niz = new RobaKes * [nmax];
	for (int i = 0; i < nmax; i++)
		niz[i] = nullptr;
}
