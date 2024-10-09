#pragma once
#include "Paragraf.h"
class Tekst
{
private:
	Paragraf** niz;
	int brTrenutnih;
	int maxBr;
public:
	Tekst();
	Tekst(int mmaxBr);
	~Tekst();

	void oslobodiMem();
	void zauzmiMem(int n);
	void dodajParagraf(Paragraf& par);
	void prosiri();
	void upisi(char * putanjaFajla);
	void citaj(char * putanjaFajla);
};

