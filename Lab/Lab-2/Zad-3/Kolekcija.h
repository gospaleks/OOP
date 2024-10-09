#pragma once
#include "Image.h"

class Kolekcija
{
private:
	int trenutnoSlika;
	int maksBroj;
	Image* niz;
public:
	Kolekcija();
	~Kolekcija();
	Kolekcija(int maksBroj);
	void dodajSliku(Image& img);
	void ispisi();
};

