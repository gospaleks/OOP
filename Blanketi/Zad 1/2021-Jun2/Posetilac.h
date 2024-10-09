#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Posetilac
{
protected:
	int b_termina, cena, zainteresovanost;
	char* ime;
	char* prezime;
	int cena_po_satu = 100;
	int osnovna_cena = 200;
public:
	Posetilac();
	Posetilac(int bt, char* ime, char* prezime);
	virtual void prikazi(ostream& izlaz) = 0;
	int getcena() { return cena; }
	int getzainteresovanost() { return zainteresovanost; }
	int getbtermina() { return b_termina; }
};