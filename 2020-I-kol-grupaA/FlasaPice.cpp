#include "FlasaPice.h"
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

FlasaPice::FlasaPice()
	: Poklon() {
	masaPrazneFlase = 0;
	gustinaPica = 0;
	zapremina = 0;
}

FlasaPice::FlasaPice(double _masaUkrasneAmbalaze, double _masaPrazneFlase, double _gustinaPica, double _zapremina)
	: Poklon("FlasaPice", _masaUkrasneAmbalaze) {
	masaPrazneFlase = _masaPrazneFlase;
	gustinaPica = _gustinaPica;
	zapremina = _zapremina;
}

FlasaPice::~FlasaPice()
{
}

void FlasaPice::prikazi(ostream& izlaz)
{
	Poklon::prikazi(izlaz);
	izlaz << left << setw(25) << "MASA PRAZNE FLASE: " << masaPrazneFlase << endl;
	izlaz << left << setw(25) << "GUSTINA PICA: " << gustinaPica << endl;
	izlaz << left << setw(25) << "ZAPREMINA: " << zapremina << endl << endl;
}

double FlasaPice::getMasa()
{
	return (masaUkrasneAmbalaze + masaPrazneFlase + zapremina * 1000);
}


