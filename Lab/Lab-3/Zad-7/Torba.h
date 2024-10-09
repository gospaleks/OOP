#pragma once
#include "Artikal.h"
class Torba : public Artikal
{
private:
	Artikal* sadrzaj;
public:
	Torba();
	Torba(char* nnaziv, double ccena);
	Torba(char* nnaziv, double ccena, Artikal* ssadrzaj);
	virtual ~Torba();
	virtual void showDescription();

	void put(Artikal& a);
	void remove();
};

