#pragma once
class Vektor
{
private:
	int n;
	int* niz;
public:
	Vektor();
	Vektor(int dim);
	Vektor(const Vektor& v); // copy constructor
	~Vektor();
	inline void postaviKti(int k, int x) { niz[k] = x; }
	inline const int vratiKti(int k) { return niz[k]; }
	void sortiraj();
	int skalarniProizvod(const Vektor& v);
	int najbliziSrednjoj();
};

