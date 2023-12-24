#pragma once
#include "Posetilac.h"
#include <iostream>
#include <fstream>
using namespace std;

class Zamak
{
private:
	char* naziv_zamka;
	Posetilac** lista;
	int kapacitet;
public:
	Zamak();
	Zamak(int kapacitet, char* naziv_zamka);
	~Zamak();
	void dodaj(Posetilac* p);
	void prikazitermine(ostream& izlaz);
	void otkazi(int termin);
	int prihod();
	Posetilac* orden();
};

