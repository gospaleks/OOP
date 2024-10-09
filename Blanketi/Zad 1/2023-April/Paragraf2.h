#pragma once
#include "Paragraf.h"
class Paragraf2 : public Paragraf
{
public:
	Paragraf2() :Paragraf() { }
	Paragraf2(char* pp) :Paragraf(pp) { }
	virtual ~Paragraf2() { }
	virtual void prikazi(ostream& izlaz);
};

