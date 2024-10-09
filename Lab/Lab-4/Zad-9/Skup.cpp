#include "Skup.h"
#include <iostream>

Skup::Skup()
{
	for (int i = 0; i < NMAX; i++)
		niz[i] = nullptr;
}

Skup::~Skup()
{
	for (int i = 0; i < NMAX; i++)
		delete niz[i];
	delete[] niz;
}

void Skup::sort(char p)
{
	if (p != 'b' && p != 'm')
		return;
	for (int i = 0; i < NMAX; i++)
		for (int j = i + 1; j < NMAX; j++)
		{
			if (p == 'b')
			{
				if (niz[i]->getB() > niz[j]->getB())
					swap(niz[i], niz[j]);
			}
			else
				if (niz[i]->getM() > niz[j]->getM())
					swap(niz[i], niz[j]);
		}
}

void Skup::setI(Protivnik* p, int i)
{
	niz[i] = p;
}

void Skup::ispisi(ostream& izlaz)
{
	for (int i = 0; i < NMAX; i++)
		niz[i]->output(izlaz);
}
