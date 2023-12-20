#include "Entitet.h"
#include "Polje.h"
#include<iostream>
using namespace std;

Entitet::Entitet()
{
	tip = 'n'; //n-nista
	energija = 0;
	r = k = 0;
	t = nullptr;
}

Entitet::Entitet(char ttip, int eenergija, Polje* tt, int rr, int kk)
{
	tip = ttip;
	energija = eenergija;
	t = tt;
	r = rr;
	k = kk;
}

Entitet::~Entitet()
{
}

void Entitet::smanji(int damage)
{
	energija -= damage;
	if (energija <= 0)
		t->brisi(r, k);
}

void Entitet::povecaj(int health)
{
	energija += health;
}

