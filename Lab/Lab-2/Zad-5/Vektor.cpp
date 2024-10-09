#include "Vektor.h"
#include <iostream>
#include <math.h>
using namespace std;

Vektor::Vektor() {
	n = 0;
	niz = nullptr;
}

Vektor::Vektor(int dim) {
	zauzmiMemoriju(dim);
}

Vektor::Vektor(const Vektor& v)
{
	zauzmiMemoriju(v.n);
	kopiraj(v);
}

Vektor::~Vektor() {
	oslobodiMemoriju();
}

void Vektor::sortiraj() {
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			if (poredi(niz[i], niz[j]))
				swap(niz[i], niz[j]);
}

double Vektor::skalarniProizvod(const Vektor& v1) {
	if (this->n == v1.n) {
		double skalarni = 0;
		for (int i = 0; i < v1.n; ++i)
			skalarni += this->niz[i].getX() * v1.niz[i].getX();
		return skalarni;
	}
	return 0;
}

int Vektor::najbliziSrednjoj() {
	double avg = 0;
	for (int i = 0; i < n; ++i)
		avg += niz[i].getX();
	avg /= n;

	int minindex = 0;
	double mini = abs(niz[0].getX() - avg);
	for (int i = 1; i < n; ++i) {
		if (abs(niz[i].getX() - avg) < mini) {
			mini = abs(niz[i].getX() - avg);
			minindex = i;
		}
	}
	return minindex;
}


// LAB 2
Vektor& Vektor::saberi(Vektor& v2)
{
	Vektor *rez = new Vektor(this->n);
	if (this->n == v2.n) {
		for (int i = 0; i < rez->n; ++i)
			rez->niz[i] = this->niz[i] + v2.niz[i];
	}
	return *rez;
}

void Vektor::izbaciDuplSort()
{
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (niz[i] == niz[j]) {
				for (int k = j; k < n - 1; ++k)
					niz[k] = niz[k + 1];
				--n;
				--j;
			}
		}
	}

	Tacka* pom = new Tacka[n];
	for (int i = 0; i < n; ++i)
		pom[i] = niz[i];

	oslobodiMemoriju();
	niz = pom;
	this->sortiraj();
}

void Vektor::rotDesno()
{
	Tacka pom(niz[n - 1]);
	for (int i = n-1; i > 0; --i)
		niz[i] = niz[i-1];
	niz[0] = pom;
}

void Vektor::rotLevo()
{
	Tacka pom(niz[0]);
	for (int i = 0; i < n-1; ++i)
		niz[i] = niz[i + 1];
	niz[n-1] = pom;
}

// OPERATORSKE FUNKCIJE
Vektor& Vektor::operator=(const Vektor& v)
{
	if (this != &v) {
		oslobodiMemoriju();
		zauzmiMemoriju(v.n);
		kopiraj(v);
	}
	return *this;
}

Vektor& Vektor::operator*(Vektor& v)
{
	Vektor* rez = new Vektor(v.n);
	if (this->n == v.n) {
		for (int i = 0; i < v.n; ++i)
			rez->niz[i] = this->niz[i] * v.niz[i];
	}
	return *rez;
}

Vektor& Vektor::operator++()
{
	for (int i = 0; i < n; ++i)
		niz[i]++;
	return *this;
}

const Vektor Vektor::operator++(int)
{
	Vektor v(*this);
	for (int i = 0; i < n; ++i)
		niz[i]++;
	return v;
}

istream& operator>>(istream& ulaz, Vektor& v)
{
	for (int i = 0; i < v.n; ++i)
		ulaz >> v.niz[i];
	return ulaz;
}

ostream& operator<<(ostream& izlaz, Vektor& v)
{
	// izlaz << "Sadrzaj vektora:\n";
	for (int i = 0; i < v.n; ++i)
		izlaz << v.niz[i] << endl;
	izlaz << endl;
	return izlaz;
}

Vektor& operator*(double x, Vektor& v)
{
	for (int i = 0; i < v.n; ++i)
		v.niz[i] = x * v.niz[i];
	return v;
}

Vektor& operator+(double x, Vektor& v)
{
	for (int i = 0; i < v.n; ++i)
		v.niz[i] = x + v.niz[i];
	return v;
}

// POMOCNE - REDUKUJEMO DUPLIRANJE KODA!
void Vektor::oslobodiMemoriju()
{
	if (niz != nullptr)
		delete[] niz;
}

void Vektor::zauzmiMemoriju(int dim)
{
	this->n = dim;
	this->niz = new Tacka[dim];
}

void Vektor::kopiraj(const Vektor& v)
{
	this->n = v.n;
	for (int i = 0; i < this->n; ++i)
		this->niz[i] = v.niz[i];
}
