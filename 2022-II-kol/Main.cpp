#include <iostream>
#include "Kolekcija.h"
#include "ProsireniPodatak.h"
using namespace std;

void main()
{
	int maxPodataka = 8, brojPodataka = 5;
	float temperature[] = { 23, 37, 28, 31, 34 };
	float vlaznosti[] = { 21, 28, 25, 26, 23 };
	float brzine[] = { 8, 15, 10, 12, 5 };
	// 3 boda
	// postavljanje i prihvatanje izuzetaka
	try {
		// 1 bod
		Kolekcija<float> kolProst(maxPodataka);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++)
			kolProst.DodajPodatak(temperature[i]);
		// 1 bod
		cout << kolProst << endl; //kolProst.Ispisi(cout);
		// 1 bod
		kolProst.Obrisi(4);
		cout << kolProst << endl; //kolProst.Ispisi(cout);
		// 1 bod
		float prosecnaTemperatura = kolProst.OdrediProsek();
		cout << prosecnaTemperatura << endl;
		// 1 bod
		float najveciPodatak = kolProst.NajveciPodatak();
		cout << najveciPodatak << endl;
		// 1 bod
		kolProst.Sacuvaj("ProstiPodaci.txt");
		// 2 boda
		Kolekcija<float> kolProstNova(maxPodataka);
		kolProstNova.Ucitaj("ProstiPodaci.txt");
		cout << kolProstNova << endl; //kolProstNova.Ispisi(cout);
	}
	catch (const char* poruka) {
		cout << poruka << endl;
	}

	try {
		// 1 bod
		Kolekcija<ProsireniPodatak> kolProsirena(maxPodataka);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++) {
			ProsireniPodatak podatak(temperature[i], vlaznosti[i], brzine[i]);
			kolProsirena.DodajPodatak(podatak);
		}
		// 1 bod
		cout << kolProsirena << endl; //kolProsirena.Ispisi(cout);
		// 0 bodova
		kolProsirena.Obrisi(4);
		cout << kolProsirena << endl; //kolProsirena.Ispisi(cout);
		// 2 boda
		float prosecnaSubjektivnaTemperatura = kolProsirena.OdrediProsek();
		cout << prosecnaSubjektivnaTemperatura << endl;
		// 2 boda
		ProsireniPodatak najveciPodatak = kolProsirena.NajveciPodatak();
		cout << najveciPodatak << endl;
		// 0 bod
		kolProsirena.Sacuvaj("ProsireniPodaci.txt");
		// 1 bod
		Kolekcija<ProsireniPodatak> kolProsirenaNova(maxPodataka);
		kolProsirenaNova.Ucitaj("ProsireniPodaci.txt");
		cout << kolProsirenaNova << endl; //kolProsirenaNova.Ispisi(cout);
	}
	catch (const char* poruka) {
		cout << poruka << endl;
	}
}