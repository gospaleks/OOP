#pragma once
#include "Poklon.h"
#include <string.h>

class Igracka : public Poklon
{
private:
	char* tipMaterijala;

public:
	Igracka();
	Igracka(double cena, double brojMasnica, const char* tipMaterijala);
	Igracka(const Igracka& i);
	~Igracka();

	void print(ostream& izlaz) const ;

	int vratiBrojMasnica() const;
};

