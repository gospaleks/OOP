#include "Skup.h"
#include "Procesor.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {

	// mng traze u main mrzi me sve to da pisem...

	try {
		Skup<Procesor> s1;
		s1.Ucitaj("ulaz.txt");
		cout << s1 << endl;

		Skup<Procesor> s2(s1);
		s1.IzbaciDuplikate();
		Skup<Procesor> s3 = s1 + s2;

		cout << s3 << endl;
		s3.Sortiraj();
		cout << s3;

		Skup<Procesor> s5(5);
		s5.Dodaj(*(new Procesor("p1", 3.6, 4, 2)));
		Skup<Procesor> s4 = s3 * s5;
		cout << s4 << endl;

	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	return 0;
}