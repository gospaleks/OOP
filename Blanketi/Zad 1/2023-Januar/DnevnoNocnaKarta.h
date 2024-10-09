#pragma once
#include "Karta.h"
class DnevnoNocnaKarta : public Karta
{
private:
	double osnovnaCenaNocneKarte;
	int brojNociVazenja;
public:
	DnevnoNocnaKarta();
	DnevnoNocnaKarta(int _id, int _redniBrojDana, int _brojDanaVazenja, double _osnCena, double _popust, double _osnCenaNocne, int _brNocenja);
	~DnevnoNocnaKarta();

	virtual double getCena();
	virtual void produzi(int _za);
	virtual void prikazi(ostream& izlaz);
};

