#include <iostream>
#include "Vektor.h"
using namespace std;

int main() {
	int dim;
	cout << "Unesite dimenzije vektora v1: ";
	cin >> dim;
	Vektor *v1 = new Vektor(dim);
	for (int i = 0; i < dim; ++i) {
		int x;
		cin >> x;
		v1->postaviKti(i, x);
	}

	v1->sortiraj();

	cout << "Sortirani vektor: ";
	for (int i = 0; i < dim; ++i)
		cout << v1->vratiKti(i) << " ";
	cout << endl << endl;

	// ------------------------------------------------
	//int dim2;
	//cout << "Unesite dimenzije vektora v2: ";
	//cin >> dim2;
	Vektor* v2 = new Vektor(*v1);
	//for (int i = 0; i < dim2; ++i) {
	//	int x;
	//	cin >> x;
	//	v2->postaviKti(i, x);
	//}

	cout << "\nSkalarni proizvod v1 i v2: " << v1->skalarniProizvod(*v2) << endl;
	cout << "Indeks elementa najblizeg srednjoj vrednosti za v1: " << v1->najbliziSrednjoj() << endl;

	delete v1;
	delete v2;
	return 0;
}