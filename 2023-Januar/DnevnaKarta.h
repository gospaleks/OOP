#pragma once
#include "Karta.h"

class DnevnaKarta : public Karta
{
public:
	DnevnaKarta();
	DnevnaKarta(int _id, int _redniBrojDana, int _brojDanaVazenja, double _osnCena, double _popust);
	~DnevnaKarta();

	virtual double getCena();
	virtual void produzi(int _za);
	virtual void prikazi(ostream& izlaz);
};

