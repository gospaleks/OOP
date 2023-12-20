#pragma once
#include <fstream>
#include <iostream>
using namespace std;

class Paketic
{
private:
	char* adresa;
	char* boja;
public:
	Paketic();
	Paketic(char* _adresa, char* _boja);
	virtual ~Paketic();

	inline char* vratiAdresu() { return adresa; }
	virtual double vratiCenu() = 0;
	virtual double vratiTezinu() = 0;
	virtual void prikaziPaketic(ostream& izlaz);
};

