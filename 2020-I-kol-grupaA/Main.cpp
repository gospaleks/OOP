#include "Paket.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {

	Paket* p = new Paket(12);
	p->ucitaj("ulaz.txt");
	cout << setw(25) << left <<
		"UKUPNA MASA PAKETA: " << p->ukupnaMasa() << endl << endl;
	p->prikazi(cout);

	// DELJENJE PAKETA NA DVA I PRIKAZ U FAJL
	Paket* p1 = new Paket(6);
	Paket* p2 = new Paket(6);
	p->podeliPaket(p1, p2);

	ofstream paket1("paket1.txt");
	p1->prikazi(paket1);
	paket1.close();

	ofstream paket2("paket2.txt");
	p2->prikazi(paket2);
	paket2.close();

	// sve NULL jer je podeljen paket
	p->prikazi(cout);


	delete p;
	return 0;
}