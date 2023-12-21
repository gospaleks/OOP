#pragma once
#include "Paket.h"
#include <iostream>
#include <fstream>
using namespace std;

class PojedinacniPaket : public Paket
{
public:
	PojedinacniPaket() : Paket() { }
	PojedinacniPaket(double brMin, double kolPod);
	virtual ~PojedinacniPaket();

	virtual double zaUplatu();
	virtual double vratiBrojPretplMin();
	virtual void zameniProcentualniParametar(double novi) { }
	virtual void zameniBrojDece(double novi) { }
	virtual void prikazi(ostream& izlaz);
};

