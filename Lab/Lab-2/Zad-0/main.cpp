
#include <iostream>
#include "Skup.h"
#include "Complex.h"
using namespace std;

void main()
{
	/*Skup* niz1 = new Skup(10);
	niz1->input();
	int kolikoBrojeva, broj, duzina;
	cout << "uneti koliko brojeva ispitujete da li pripadaju skupu:" << endl;
	cin >> kolikoBrojeva;
	for (int i = 0; i < kolikoBrojeva; i++)
	{
		cin >> broj;
		if (niz1->ispitaj(broj))
			cout << "pripada" << endl;
		else
			cout << "ne pripada" << endl;
	}
	cout << "koliko ce biti dugacak drugi niz?" << endl;
	cin >> duzina;
	Skup* niz2 = new Skup(duzina);
	niz2->input();
	niz2->izbaciDupl();
	niz2->nerastuci();
	niz2->output();
	delete niz1, niz2;*/

	ifstream ulaz("ulaz.txt");
	if (ulaz.good()) {
		
		int n;
		ulaz >> n;
		Skup *s1 = new Skup(n);
		ulaz >> *s1;
		
		ulaz >> n;
		Skup* s2 = new Skup(n);
		ulaz >> *s2;

		cout << *s1 << endl;
		cout << *s2 << endl;

		Skup *s3 = new Skup();

		*s3 = s1->unija(*s2);

		cout << *s3;
		delete s1;
		delete s2;
		delete s3;
		ulaz.close();
	}
}