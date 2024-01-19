#include "Kolekcija.h"
#include "Kvadar.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {

	// KOLEKCIJA CELIH 1
	Kolekcija<int> k;
	k.unos("celiBrojevi.txt");
	k.prikaz();
	k.sort();
	k.prikaz();
	cout << k.prosek() << endl;
	
	cout << endl << endl;

	// KOLEKCIJA KVADRA
	Kolekcija<Kvadar> k2;
	k2.unos("kvadarUlaz.txt");
	k2.prikaz();
	k2.sort();
	k2.prikaz();
	cout << k2.prosek() << endl << endl;

	// KOLEKCIJA CELIH 2
	Kolekcija<int> k3;
	k3.unos("celiBrojevi.txt");

	// SPAJANJE KOLEKCIJA
	//Kolekcija<int> rez(k);
	Kolekcija<int> rez(k + k3);
	rez.prikaz();

	return 0;
}