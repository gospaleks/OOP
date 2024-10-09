#pragma once
#include "Predmet.h"
#include <fstream>
#include <iostream>
using namespace std;

class Ranac
{
private:
	int N;
	Predmet** niz;
	int trBr;
public:
	Ranac();
	Ranac(int Nmax);
	~Ranac();
	
	void dodajPredmet(Predmet* p);
	void prikazi(ostream& izlaz);
	double srednjaVrednost();
	Predmet* najvrednijiPoJediniciMase();
};

