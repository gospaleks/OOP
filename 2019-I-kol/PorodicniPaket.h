#pragma once
#include "UpareniPaket.h"
#include <iostream>
#include <fstream>
using namespace std;
class PorodicniPaket : public UpareniPaket
{
private:
	int brojDece;
public:
	PorodicniPaket();
	PorodicniPaket(double brMin, double kolPod, double odnos, int brDece);
	virtual ~PorodicniPaket();

	virtual double zaUplatu();
	virtual double vratiBrojPretplMin();
	virtual void zameniProcentualniParametar(double novi);
	virtual void zameniBrojDece(double novi);
	virtual void prikazi(ostream& izlaz);

};

