#pragma once
#include <iostream>
#include <fstream>
#include"Kolekcija.h"
#include"Picture.h"
using namespace std;

void main() {
	ifstream ulaz("ulaz.txt");
	if (ulaz.good()) {

		int n, m;

		Kolekcija* k = new Kolekcija(4);

		ulaz >> n >> m;
		Picture* p1 = new Picture(n, m);
		ulaz >> *p1;
		(*p1)++;

		ulaz >> n >> m;
		Picture* p2 = new Picture(n, m);
		ulaz >> *p2;
		Picture* p3 = new Picture(n, m);

		p3->preklopi(*p1, *p2);

		k->dodajSliku(*p1);
		k->dodajSliku(*p2);
		k->dodajSliku(*p3);


		ulaz >> n >> m;
		Picture* p4 = new Picture(n, m);
		ulaz >> *p4;
		k->dodajSliku(*p4);

		ulaz >> n >> m;
		Picture* p5 = new Picture(n, m);
		ulaz >> *p5;
		k->dodajSliku(*p5);

		cout << *k;

		delete p1, p2, p3, p4, p5;
		ulaz.close();
	}
	return;
}