#include "Kolekcija.h"
#include <iostream>
#include <fstream>
using namespace std;

void main()
{
	ifstream ulaz("ulaz.txt");
	if (ulaz.good()) {

		int n;
		ulaz >> n;
		Image* i1 = new Image(n);
		ulaz >> (*i1);
		
		cout << *i1;
		i1->rotiraj();
		cout << endl;
		cout << *i1;

		//ulaz >> n;
		//Image* i2 = new Image(n);
		//ulaz >> (*i2);

		ulaz.close();

		//Image* i3 = new Image();
		//*i3 = i1->preklopi(*i2);

		//Kolekcija* k = new Kolekcija(5);
		//k->dodajSliku(*i1);
		//k->dodajSliku(*i2);
		//k->dodajSliku(*i3);
		//k->ispisi();
	}

}