#include "Skup.h"
void main()
{
	Skup* niz1 = new Skup(10);
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
	delete niz1, niz2;
}