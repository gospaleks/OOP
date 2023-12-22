#include "DnevnoNocnaKarta.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

DnevnoNocnaKarta::DnevnoNocnaKarta()
	: Karta() {
	osnovnaCenaNocneKarte = 0;
	brojNociVazenja = 0;
}

DnevnoNocnaKarta::DnevnoNocnaKarta(int _id, int _redniBrojDana, int _brojDanaVazenja, double _osnCena, double _popust, double _osnCenaNocne, int _brNocenja)
	: Karta("Dnevno-Nocna-Karta", _id, _redniBrojDana, _brojDanaVazenja, _osnCena, _popust) {
	
	// i ovde kaze prijaviti gresku
	// ja bi bacio throw "";
	// al to nema za kolokvijum
	// ovako ga samo setujem na vazeci podatak
	if (_brNocenja > _brojDanaVazenja) _brNocenja = _brojDanaVazenja;
	if (_brNocenja + 1 != _brojDanaVazenja) _brNocenja = _brojDanaVazenja;

	osnovnaCenaNocneKarte = _osnCenaNocne;
	brojNociVazenja = _brNocenja;
}

DnevnoNocnaKarta::~DnevnoNocnaKarta()
{
}

double DnevnoNocnaKarta::getCena()
{
	double zbirniNocniPopust = (popust + brojNociVazenja) * 0.02;
	return (osnovnaCenaNocneKarte + zbirniNocniPopust);
}

void DnevnoNocnaKarta::produzi(int _za)
{
	brojDanaVazenja += _za;
	brojNociVazenja += _za;
}

void DnevnoNocnaKarta::prikazi(ostream& izlaz)
{
	Karta::prikazi(izlaz);
	izlaz << left << setw(25) << "OSNOVNA CENA NOCNE: " << osnovnaCenaNocneKarte << endl;
	izlaz << left << setw(25) << "BROJ NOCI VAZENJA: " << brojNociVazenja << endl;
	izlaz << "#####################################-KRAJ\n\n";
}
