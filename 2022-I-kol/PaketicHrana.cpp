#include "PaketicHrana.h"

PaketicHrana::PaketicHrana()
	: Paketic() {
	brojCokolada = 0;
	ukupnaTezina = 0;
	cenaPoJed = 0;
}

PaketicHrana::PaketicHrana(char* _adresa, char* _boja, int _brojCokolada, double _ukupnaTezina, double _cenaPoJed)
	: Paketic(_adresa, _boja) {
	brojCokolada = _brojCokolada;
	ukupnaTezina = _ukupnaTezina;
	cenaPoJed = _cenaPoJed;
}

double PaketicHrana::vratiCenu()
{
	return (ukupnaTezina * cenaPoJed);
}

double PaketicHrana::vratiTezinu()
{
	return ukupnaTezina;
}

void PaketicHrana::prikaziPaketic(ostream& izlaz)
{
	Paketic::prikaziPaketic(izlaz);
	izlaz << brojCokolada << ", " << ukupnaTezina << ", " << cenaPoJed << endl;
}
