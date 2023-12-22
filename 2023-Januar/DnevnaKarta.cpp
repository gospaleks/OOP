#include "DnevnaKarta.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

DnevnaKarta::DnevnaKarta()
	: Karta() {
}

DnevnaKarta::DnevnaKarta(int _id, int _redniBrojDana, int _brojDanaVazenja, double _osnCena, double _popust)
	: Karta("Dnevna-Karta", _id, _redniBrojDana, _brojDanaVazenja, _osnCena, _popust) {
}

DnevnaKarta::~DnevnaKarta()
{
}

double DnevnaKarta::getCena()
{
	double zbirniPopust = (popust + brojDanaVazenja) * 0.02;
	return (osnovnaCenaKarte + zbirniPopust);
}

void DnevnaKarta::produzi(int _za)
{
	brojDanaVazenja += _za;
}

void DnevnaKarta::prikazi(ostream& izlaz)
{
	Karta::prikazi(izlaz);
	izlaz << "#####################################-KRAJ\n\n";
}


