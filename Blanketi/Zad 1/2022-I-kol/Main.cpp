#include "Saonice.h"
#include "Paketic.h"
#include "PaketicHrana.h"
#include "PaketicIgracke.h"

#include <iostream>
#include <fstream>

using namespace std;

int main() {

	Saonice* s = new Saonice(10);
	
	s->dodajPaketic(new PaketicHrana((char*)"Takovksa 46", (char*)"Plav", 10, 1.24, 123.99));
	s->dodajPaketic(new PaketicIgracke((char*)"Sremska 4", (char*)"Crven", 5, 100, 220.46));
	s->dodajPaketic(new PaketicHrana((char*)"Stevana Sremca 50", (char*)"Ljubicast", 4, 120, 12.46));
	s->dodajPaketic(new PaketicIgracke((char*)"Bulevar Zorana Djindjica 17", (char*)"Zut", 19, 32, 512.46));
	s->dodajPaketic(new PaketicHrana((char*)"Dusanova 136A", (char*)"Crn", 1, 99, 250.96));
	s->dodajPaketic(new PaketicIgracke((char*)"Aleksandra Medvedeva 14", (char*)"Plav", 13, 30, 11.46));

	ofstream izlaz("pokloni.txt");
	if (izlaz.good()) {
		s->prikaziSaonice(izlaz);
		izlaz.close();
	}

	double srednjaCena = s->srednjaCena();
	Paketic* najteziPaketic = s->vratiNajteziPaketic();

	cout << "Srednja cena svih paketica: " << srednjaCena;
	cout << "\nNajtezi paketic:\n";
	najteziPaketic->prikaziPaketic(cout);

	// ucitati 3 adrese i izbaciti ako postoje
	cout << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "Unesite adresu: ";
		char adresa[100];
		cin.getline(adresa, 100);
		s->izbaciPaketic(adresa);
	}

	cout << "\nSaonice nakon izbacivanja:\n";
	s->prikaziSaonice(cout);

	delete s;
	return 0;
}