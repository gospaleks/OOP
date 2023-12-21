#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Paket
{
protected:
	char* vrstaPaketa;
	double brPretplMin; // 100 do 2000
	double cenaMinuta;
	double kolPodataka;	// 1GB do 10GB
	double cenaPoJedGB;
public:
	Paket();
	Paket(char* vrsta, double brMin, double kolPod);
	virtual ~Paket();

	virtual double zaUplatu() = 0;
	virtual void zameniBrojPretplMin(double novi);
	virtual void zameniProcentualniParametar(double novi) = 0;
	virtual void zameniBrojDece(double novi) = 0;
	virtual void prikazi(ostream& izlaz);

	inline char* vratiVrstuPaketa() { return vrstaPaketa; }
	virtual double vratiBrojPretplMin() = 0;
};

