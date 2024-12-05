#include <stdio.h>
#include "IspitniMaterijal.h"
#include "Lekcija.h"
#include "Zadatak.h"
#include "IspitPriprema.h"

using namespace std;

int main() 
{
	float vJedinicno = 10;

	// 2 poena
	IspitniMaterijal* p1 = new Lekcija(1001, 2.0, 1.5);

	//p1->Prikazi();
	cout << *p1 << endl;

	// 2 poena
	IspitniMaterijal* p2 = new Zadatak(1002, 2.4, 20);

	//p2->Prikazi();
	cout << *p2 << endl;
	float tezine[] = { 1.5, 2.7, 0.8, 3.2, 1.8 };
	float duzina[] = { 1.2, 3.1, 2.5, 3.4, 4.1 };
	int kod[] = { 100, 20, 40, 50, 30 };
	IspitPriprema* pIspit = new IspitPriprema(20);

	// 2 poena
	for (int i = 0; i < 5; i++)
	{
		Lekcija* lekcija = new Lekcija(2 * i + 1, tezine[i], duzina[i]);
		pIspit->Dodaj(lekcija);
		Zadatak* zadatak = new Zadatak(2 * i + 2, tezine[i], kod[i]);
		pIspit->Dodaj(zadatak);
	}

	// 2 poena
	//pe.print();
	cout << *pIspit << endl;

	// 2 poena
	pIspit->Obrisi(3);

	//pe->print();
	cout << *pIspit << endl;

	// 2 poena
	pIspit->Savladaj(2);

	//pe->print();
	cout << *pIspit << endl;

	// 2 poena
	int sav = pIspit->UkupnoSavladanih();
	cout << sav << endl;

	// 3 poena
	float vreme = pIspit->UkupnoVreme(vJedinicno);
	cout << vreme << endl;

	// 2 poena
	IspitniMaterijal* matMin = nullptr, * matMax = nullptr;
	pIspit->VratiNaj(vJedinicno, &matMin, &matMax);
	cout << *matMin << endl << *matMax << endl;
	//matMin->Prikazi();
	//matMax->Prikazi();
	// 1 poena
	delete pIspit;
}