#pragma once
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;

class Novcanica
{
protected:
	int vrednost;
	int brojNovcanica;

public:
	Novcanica(int vrednost, int brojNovcanica);
	virtual ~Novcanica();
	
	void povecajBrojNovcanica(int za = 1);
	void smanjiBrojNovcanica(int za);

	// Geteri
	virtual const int getVrednost() const { return vrednost; }
	virtual const char* getKodValute() const { return "DIN"; }
	virtual double getKurs() const { return 0.0; }
	int getBrojNovcanica() const { return brojNovcanica; }

	// Operatori
	friend std::ostream& operator<<(std::ostream& izlaz, const Novcanica& n);
	virtual bool operator==(const Novcanica& n) const = 0;

	virtual void Prikazi(std::ostream& izlaz) const = 0;
	virtual	inline double ukupnaVrednost() const = 0;
};

