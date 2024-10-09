#include "SportskiCentar.h"
#include "KosarkaskiKlub.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	try {
		SportskiCentar<int> spc1(4);
		int x1 = 5;
		spc1.dodaj(x1);
		int x2 = 6;
		spc1.dodaj(x2);
		int x3 = 1;
		spc1.dodaj(x3);
		int x4 = 3;
		spc1.dodaj(x4);
		cout << spc1;
		spc1.izvestajprosek("prosek.txt");
		spc1.izvestajnajvrednija("max.txt");
		spc1.izvestajnajmanjevredna("min.txt");
	}
	catch (const char* poruka) {
		cout << poruka << endl;
	}

	try {
		SportskiCentar<KosarkaskiKlub> spc2;
		
		ifstream ulaz("podacizakk.txt");
		if (ulaz.good()) {

			ulaz >> spc2;
			
			ulaz.close();
		}
		cout << spc2;
		spc2.izvestajprosek("prosek.txt");
		spc2.izvestajnajvrednija("max.txt");
		spc2.izvestajnajmanjevredna("min.txt");
	}
	catch (const char* poruka) {
		cout << poruka;
	}
}