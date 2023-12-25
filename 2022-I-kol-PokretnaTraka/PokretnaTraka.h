#pragma once
#include "Proizvod.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class PokretnaTraka
{
private:
	Proizvod** traka;
	int top;
	int kapacitet;
public:
	PokretnaTraka();
	PokretnaTraka(int _kapacitet);
	~PokretnaTraka();

	void dodajProizvod(Proizvod* p);
	void povecajKapacitet(int brPozicija);
	void izbaci();
	void zameniDefektni(int poz, Proizvod* p);
	int trenutniBrojDefektnih();
	int trenutniBrojPraznihMesta();
	void prikazi(ostream& izlaz);
};

