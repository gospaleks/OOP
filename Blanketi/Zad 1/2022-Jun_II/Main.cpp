#include <iostream>
#include <fstream>
#include "Kolekcija.h"
#include "Figura.h"
#include "Kvadrat.h"
#include "Pravougaonik.h"
using namespace std;

int main()
{
	ifstream ulaz("ulaz.txt");
	if (ulaz.good())
	{
		int nmax, n;
		float x, y, visina, sirina;
		char tip;
		ulaz >> nmax;
		ulaz >> n;
		Kolekcija k(nmax);
		for (int i = 0; i < n; i++)
		{
			ulaz >> tip;
			if (tip == 'p')
			{
				ulaz >> x >> y >> visina >> sirina;
				k.dodaj(new Pravougaonik(visina, sirina, x, y));
			}
			else if (tip == 'k')
			{
				ulaz >> x >> y >> visina;
				k.dodaj(new Kvadrat(visina, x, y));
			}
		}

		ofstream izlaz("izlaz.txt");
		k.ispisi(izlaz);

		Kvadrat* k1 = new Kvadrat();
		k1->upisi(ulaz);
		k.dodaj(k1);

		Pravougaonik* p1 = new Pravougaonik();
		p1->upisi(ulaz);
		k.dodaj(p1);

		k.ispisi(izlaz);

		Kvadrat* k2 = new Kvadrat();
		k2->upisi(ulaz);
		k.dodaj(k2);

		Kvadrat* k3 = new Kvadrat();
		k3->upisi(ulaz);
		k.dodaj(k3);

		k.ispisi(izlaz);

		izlaz.close();
	}
}