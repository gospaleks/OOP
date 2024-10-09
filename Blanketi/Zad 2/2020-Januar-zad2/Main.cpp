#include "Polica.h"
#include "Knjiga.h"
#include "CD.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	Polica<Knjiga> pK(10);
	try {
		pK.Ucitaj("policaKnjige.txt");
		pK.Izbaci(2);
		pK.Izbaci(7);

	}
	catch (exception& e) {
		cout << e.what() << endl;
		cout << pK << endl;
	}

	cout << endl;

	Polica<CD> pC(10);
	try {
		pC.Ucitaj("policaCD.txt");
		pC.Izbaci(5);
		pC.Izbaci(-2);

	}
	catch (exception& e) {
		cout << e.what() << endl;
		cout << pC << endl;
	}

	return 0;
}