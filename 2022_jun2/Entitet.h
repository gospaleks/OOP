#pragma once
#include <iostream>
#define pi 3.14159265359
using namespace std;

class Polje;

class Entitet
{
protected:
	char tip;
	int energija;
	Polje* t;
	int r, k;
public:
	Entitet();
	Entitet(char ttip, int eenergija, Polje* tt, int rr, int kk);
	~Entitet();
	virtual void dobro() = 0;
	virtual void lose() = 0;
	void smanji(int damage);
	void povecaj(int health);
	char getTip() { return tip; }
	int getEnergija() { return energija; }
};

