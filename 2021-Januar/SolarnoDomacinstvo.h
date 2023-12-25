#pragma once
#include "Domacinstvo.h"
#include <iostream>
using namespace std;
class SolarnoDomacinstvo : public Domacinstvo
{
	double dobijenaEnergija;
	double koefPodsticaja;
	double odrzavanje;
public:
	SolarnoDomacinstvo();
	SolarnoDomacinstvo(int brd, double po, double potr,
					double de, double kp, double odr);
	virtual ~SolarnoDomacinstvo();
	virtual double cenaPotrosnje(double cena);
	virtual void ispisi(ostream& izlaz);
};

// brojDom; int
// povrsinaObjekti;
// potrosnja;
// dobijenaEnergija
// koeficient podsticaja
// odrzavanje