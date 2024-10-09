#pragma once
#include "Novcanica.h"
#include <string.h>

class NovcanicaStrana : public Novcanica
{
private:
	char kodValute[4];
	double kurs;

public:
	NovcanicaStrana(int vrednost, const char* kodValute, double kurs);
	~NovcanicaStrana();

	// Geteri
	const char* getKodValute() const { return kodValute; }
	double getKurs() const { return kurs; }

	// Operatori
	bool operator==(const Novcanica& n) const;

	void Prikazi(std::ostream& izlaz) const;
	inline double ukupnaVrednost() const { return vrednost * brojNovcanica * kurs; }
};

