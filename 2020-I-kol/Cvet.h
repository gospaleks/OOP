#pragma once
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

class Cvet
{
private:
	char* vrsta;
public:
	Cvet() { vrsta = nullptr; }
	Cvet(const char* _vrsta) {
		vrsta = new char[strlen(_vrsta) + 1];
		strcpy(vrsta, _vrsta);
	}
	virtual ~Cvet() { 
		if (vrsta != nullptr)
			delete[] vrsta;
	}

	char* getVrsta() { return vrsta; }

	virtual double getCena() = 0;
	virtual void ispisi(ostream& izlaz) = 0;
};

