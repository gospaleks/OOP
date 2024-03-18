#pragma once
#include "Poklon.h"

class Cokolada : public Poklon
{
private:
	double procenatKakaa;

public:
	Cokolada();
	Cokolada(int cena, int brojMasnica, double procenatKakaa);
	Cokolada(const Cokolada& c);
	~Cokolada();

	void print(ostream& izlaz) const ;

	int vratiBrojMasnica() const;
};

