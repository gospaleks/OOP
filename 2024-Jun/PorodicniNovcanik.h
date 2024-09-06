#pragma once
#include "Novcanica.h"
#include "NovcanicaDinar.h"
#include "NovcanicaStrana.h"

class PorodicniNovcanik
{
private:
	Novcanica** novcanice;
	int brTr;
	int kapacitet;

	double UkupnaVrednostNovcanika() const;

public:
	PorodicniNovcanik(int kapacitet);
	~PorodicniNovcanik();

	void Dodaj(Novcanica* n);
	void Izdvoji(Novcanica& n, int br);
	void Rasitni(Novcanica& veca, Novcanica& manja);
	bool MozePlatiti(int iznos) const;
	void VratiNaj(Novcanica** min, Novcanica** max) const;

	friend std::ostream& operator<<(std::ostream& izlaz, const PorodicniNovcanik& pn);
};

