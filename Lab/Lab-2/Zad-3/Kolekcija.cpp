#include "Kolekcija.h"
#include <iostream>
using namespace std;
Kolekcija::Kolekcija()
{
	trenutnoSlika = 0;
	maksBroj = 0;
	niz = nullptr;
}

Kolekcija::~Kolekcija()
{
	if (niz != 0)
		delete[] niz;
	trenutnoSlika = 0;
	maksBroj = 0;
}

Kolekcija::Kolekcija(int maksBroj)
{
	niz = new Image[maksBroj];
}

void Kolekcija::dodajSliku(Image& img)
{
	niz[trenutnoSlika++] = img;
}

void Kolekcija::ispisi()
{
	for (int i = 0; i < trenutnoSlika; i++)
		cout << niz[i] << endl;

}
