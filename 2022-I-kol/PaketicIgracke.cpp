#include "PaketicIgracke.h"

PaketicIgracke::PaketicIgracke()
	: Paketic() {
	brojAutica = 0;
	tezinaJednog = 0;
	cenaJednog = 0;
}

PaketicIgracke::PaketicIgracke(char* _adresa, char* _boja, int brAut, double t, double c)
	: Paketic(_adresa, _boja) {
	brojAutica = brAut;
	tezinaJednog = t;
	cenaJednog = c;
}

double PaketicIgracke::vratiCenu()
{
	return (brojAutica*cenaJednog);
}

double PaketicIgracke::vratiTezinu()
{
	return ((double)brojAutica*tezinaJednog);
}

void PaketicIgracke::prikaziPaketic(ostream& izlaz)
{
	Paketic::prikaziPaketic(izlaz);
	izlaz << brojAutica << ", " << tezinaJednog << ", " << cenaJednog << endl;
}
