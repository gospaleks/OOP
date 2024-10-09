#pragma once
#include "Paket.h"
#include <iostream>
#include <fstream>
using namespace std;
class UpareniPaket : public Paket
{
protected:
	double odnosParametraPaketa;
public:
	UpareniPaket() : Paket() { 
		odnosParametraPaketa = 0;
	}
	UpareniPaket(double brMin, double kolPod, double odnos);
	UpareniPaket(char *v, double brMin, double kolPod, double odnos);
	virtual ~UpareniPaket();

	void umanjenje(double procUm);

	virtual double zaUplatu();
	virtual double vratiBrojPretplMin();
	virtual void zameniProcentualniParametar(double novi);
	virtual void zameniBrojDece(double novi) { }
	virtual void prikazi(ostream& izlaz);

};

