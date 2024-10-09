#pragma once
#include "Proizvod.h"
class Otpornik : public Proizvod
{
private:
	float r;	// otpornost
	float minTemp;
	float maxTemp;
public:
	Otpornik();
	Otpornik(const char* _barkod, float _r, float _minTemp, float _maxTemp);
	~Otpornik() { }

	virtual bool jeDefektan();
	virtual void prikazi(ostream& izlaz);
};

