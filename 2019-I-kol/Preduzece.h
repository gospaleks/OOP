#pragma once
#include "Paket.h"
#include <iostream>
#include <fstream>
using namespace std;

class Preduzece
{
private:
	Paket** niz;
	int maxEl;
	int top;
public:
	Preduzece();
	Preduzece(int mmaxEl);
	~Preduzece();

	void dodajPaket(Paket* p);
	void ukloniSa(int k);

	// zamene
	void zameniBrojPretplMin(int el, double nova);
	void zameniProcentualniParametar(int el, double nova);
	void zameniBrojDece(int el, double nova);

	// statistika
	double ukupanBrojMinuta();
	double zaradaOdSvihKorisnika();
	void stampajIzvestaj(ostream& izlaz);
};

