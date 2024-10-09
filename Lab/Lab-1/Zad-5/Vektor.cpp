#include "Vektor.h"
#include <iostream>
#include <math.h>
using namespace std;

// default konstruktor koji postavlja dimenziju vektora na 0
Vektor::Vektor() {
	n = 0;
	niz = nullptr;
}

// konstruktor za postavljanje velicine niza
Vektor::Vektor(int dim) {
	n = dim;
	niz = new int[n];
}

Vektor::Vektor(const Vektor& v)
{
	this->n = v.n;
	this->niz = new int[this->n];
	for (int i = 0; i < this->n; ++i)
		this->niz[i] = v.niz[i];
}

// destruktor
Vektor::~Vektor() {
	if (niz != nullptr)
		delete[] niz;
	n = 0;
}

// funkciju koja uredjuje elemente niza u neopadajuci redosled
void Vektor::sortiraj() {
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			if (niz[i] > niz[j])
				swap(niz[i], niz[j]);
}

// funkciju koja racuna skalarni proizvod dva vektora 
int Vektor::skalarniProizvod(const Vektor& v1) {
	if (this->n == v1.n) {
		int skalarni = 0;
		for (int i = 0; i < v1.n; ++i)
			skalarni += this->niz[i] * v1.niz[i];
		return skalarni;
	}
	return 0; // po dogovoru kad nisu ispunjeni uslovi
}

// funkciju koja vraca indeks elementa koji ima vrednost
// najblizu srednjoj vrednosti svih elemenata u vektoru
int Vektor::najbliziSrednjoj() {
	double avg = 0;
	for (int i = 0; i < n; ++i)
		avg += niz[i];
	avg /= n;

	int minindex = 0;
	double mini = abs(niz[0]-avg);
	for (int i = 1; i < n; ++i) {
		if (abs(niz[i] - avg) < mini) {
			mini = abs(niz[i] - avg);
			minindex = i;
		}
	}
	return minindex;
}

