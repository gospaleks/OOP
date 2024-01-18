#include "Kolekcija.h"
#include "Potrosnja.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {

	try {
		Kolekcija<int> k(12);

		cout << "Unesite podatka za 15 meseci:\n";
		for (int i = 0; i < 15; ++i)
		{
			cout << "Unesite podatke: ";
			int x, y;
			cin >> x >> y;
			k.Dodaj(x, y);

			k.PrikaziSpisak(cout);
			cout << endl;
			cout << "Razlika u potrosnji:\t" << k.RazlikaPotrosnje(x) << endl;
			cout << "Prosecna potrosnja:\t" << k.ProsecnaPotrosnja() << endl;
			cout << "----------------------------------\n";
		}
		int minP, maxP;
		k.MinMaxPotrosnja(&minP, &maxP);
		cout << "Min i Max potrosnja:\t";
		cout << minP << ", " << maxP << endl;
		cout << "Broj podatak vecih u odnosu na aktuelnu:\t" << k.BrojVecihOdAktuelne() << endl;

		k.Sacuvaj("kolekcijaInt.txt");
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	try {
		Kolekcija<Potrosnja> kPot(12);

		cout << "Unesite podatka za 15 meseci:\n";
		for (int i = 0; i < 4; ++i)			// treba 15 ovde al me mrzi da ubacujem tlk podaci
		{
			cout << "Unesite podatke: ";
			int rbr;
			cin >> rbr;
			Potrosnja p;
			cin >> p;
			kPot.Dodaj(rbr, p);
			kPot.PrikaziSpisak(cout);
			cout << endl;
			cout << "Razlika u potrosnji u odnosu na mesec 1:\t" << kPot.RazlikaPotrosnje(rbr) << endl;
			cout << "Prosecna potrosnja:\t" << kPot.ProsecnaPotrosnja() << endl;
			cout << "---------------------------------------\n";
		}
	
		Potrosnja minP, maxP;
		kPot.MinMaxPotrosnja(&minP, &maxP);
		cout << "Min i Max potrosnja:\t";
		cout << minP << ", " << maxP << endl;
		cout << "Broj podatak vecih u odnosu na aktuelnu:\t" << kPot.BrojVecihOdAktuelne() << endl;

		kPot.Sacuvaj("kolekcijaPotrosnja.txt");
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}


	return 0;
}