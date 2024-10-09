#pragma once
#include "Paragraf.h"
class Paragraf1 : public Paragraf
{
public:
	Paragraf1() :Paragraf() { }
	Paragraf1(char* pp) :Paragraf(pp) { }
	virtual ~Paragraf1() { }
	virtual void prikazi(ostream& izlaz);
};

