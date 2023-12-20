#pragma once
#include "Paketic.h"
#include <fstream>
#include <iostream>
using namespace std;

class Saonice
{
private:
	Paketic** niz;
	int top;
	int maxBr;
public:
	Saonice();
	Saonice(int _maxBr);
	~Saonice();

	void dodajPaketic(Paketic* p);
	void izbaciPaketic(const char* _adresa);
	void prikaziSaonice(ostream& izlaz);
	double srednjaCena();
	Paketic* vratiNajteziPaketic();
};

