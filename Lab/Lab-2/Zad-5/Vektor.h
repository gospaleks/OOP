#pragma once
#include "Tacka.h"
class Vektor
{
private:
	int n;
	Tacka* niz;
	void oslobodiMemoriju();
	void zauzmiMemoriju(int dim);
	void kopiraj(const Vektor& v);
public:
	Vektor();
	Vektor(int dim);
	Vektor(const Vektor& v);
	~Vektor();
	
	inline void postaviKti(int k, Tacka& t) { niz[k] = t; }
	inline const Tacka& vratiKti(int k) { return niz[k]; }
	void sortiraj();
	double skalarniProizvod(const Vektor& v);				// po x koordinati ???
	int najbliziSrednjoj();									// po x koordinati ???

	// za LAB2
	Vektor& saberi(Vektor& v2);
	void izbaciDuplSort();
	void rotDesno();
	void rotLevo();
	Vektor& operator=(const Vektor& v);
	friend istream& operator>>(istream& ulaz, Vektor& v);
	friend ostream& operator<<(ostream& izlaz, Vektor& v);
	friend Vektor& operator*(double x, Vektor& v);			// mnozenje svih el konstantom
	Vektor& operator*(Vektor& v);							// mnozenje dva niza
	friend Vektor& operator+(double x, Vektor& v);			// sabiranje sa konstantom


	int getN() { return n; } // za proveru nekvo


	// operator ++
	Vektor& operator++();
	const Vektor operator++(int);
};

