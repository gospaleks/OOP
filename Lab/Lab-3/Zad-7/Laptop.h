#pragma once
#include "Artikal.h"
class Laptop : public Artikal
{
private:
	char* opis;
	bool stanje;
public:
	Laptop();
	Laptop(char* nnaziv, double ccena, char* oopis, bool sstanje = 0);
	virtual ~Laptop();
	virtual void showDescription();
	void turnOn();
	void turnOff();
};

