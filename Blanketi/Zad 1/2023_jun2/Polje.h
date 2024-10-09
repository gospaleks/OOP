#pragma once
#include "Entitet.h"
#include "Osa.h"
#include "Pcela.h"
#include <fstream>
#include <iostream>
#define pi 3.14159265359
using namespace std;

class Entitet;

class Polje
{
private:
	Entitet*** mat;
	int n, m;
public:
	Polje();
	Polje(int nn, int mm);
	~Polje();
	bool daLiPripada(int i, int j);
	void ucitaj(istream& ulaz);
	void zauzmiMem(int nn, int mm);
	void postavi(int ii, int jj, Entitet* e);
	void prikazi();
	inline int getN() { return n; }
	inline int getM() { return m; }
	void brisi(int i, int j);
	Entitet* vratiIJ(int i, int j) { return mat[i][j]; }
	void sviDobro();
	void sviLose();
};

