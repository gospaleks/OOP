#include "VozniPark.h"
#include "Automobil.h"
#include "Kamion.h"
#include <string.h>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

int main() {

	ifstream ulaz("automobili.txt");
	if (!ulaz.good()) { return 0; }


	// ucitaj vozni park automobili
	VozniPark* vozniParkAutomobili = new VozniPark();
	vozniParkAutomobili->citaj(ulaz);
	ulaz.close();
	vozniParkAutomobili->dodajVozilo(new Automobil("BMW", "PI-000-AA", 320, 11.12, 2));
	ofstream izlaz1("automobili_izlaz.txt");
	vozniParkAutomobili->ispisi(izlaz1);
	izlaz1.close();

	ifstream ulaz2("kamioni.txt");
	if (!ulaz2.good()) { return 0; }

	// ucitaj vozni park kamioni
	VozniPark* vozniParkKamioni = new VozniPark();
	vozniParkKamioni->citaj(ulaz2);
	ulaz2.close();
	vozniParkKamioni->dodajVozilo(new Kamion("Volvo", "PI-000-AA", 175, 17.2, 25));
	ofstream izlaz2("kamioni_izlaz.txt");
	vozniParkKamioni->ispisi(izlaz2);
	izlaz2.close();


	// cisto nesto da ima na ekran
	vozniParkAutomobili->ispisi(cout);
	vozniParkKamioni->ispisi(cout);



	delete vozniParkAutomobili;
	delete vozniParkKamioni;

	return 0;
}