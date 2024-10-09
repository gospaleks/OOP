#pragma once
#include<iostream>
#include<fstream>
using namespace std;

class Picture
{
private:
	int n, m;
	int** mat;
public:
	Picture();
	~Picture();
	Picture(int visina, int sirina);
	inline void vratiDim(int* nn, int* mm) {
		*nn = this->n;
		*mm = this->m;
	}
	void Brihtness(int s);
	void ucitaj();
	void ispisi();
	void resize(int newN, int newM);

	Picture(const Picture& p);

	void oslobodiMem();
	void zauzmiMem(int n, int m);
	void kopiraj(const Picture& p);

	void preklopi(Picture& p1, Picture& p2);
	int brojBoja();
	Picture& operator=(Picture& p);
	friend istream& operator>>(istream& ulaz, Picture& p);
	friend ostream& operator<<(ostream& izlaz, Picture& p);

	Picture& operator++();
	const Picture operator++(int);
};