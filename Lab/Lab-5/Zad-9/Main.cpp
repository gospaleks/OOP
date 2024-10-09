#include <iostream>
#include <fstream>
#include "Bioskop.h"
#include "Gledalac.h"
using namespace std;

int main() {
	
	// treba sve u dinamicku zonu al jbg

	ifstream ulaz("unos.txt");
	if (ulaz.good()) {

		Gledalac g1, g2, g3, g4;

		ulaz >> g1 >> g2 >> g3 >> g4;
		ulaz.close();

		Bioskop<Gledalac, 3, 3> b;
		b(0, 0) = g1;
		b(1, 1) = g2;
		b(2, 1) = g3;
		b(2, 2) = g4;

		b.ispis();

		float prosek = b.prosekGodina();
		float ocena = b.prosekOcene();
		cout << endl  << "Prosek godina: " << prosek << endl;
		cout << "Prosek ocena:  " << ocena << endl;
	}

	return 0;
}