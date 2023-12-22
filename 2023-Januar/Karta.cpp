#include "Karta.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

Karta::Karta()
{
	vrsta = nullptr;
	id = 0;
	redniBrojDana = 0;
	brojDanaVazenja = 0;
	osnovnaCenaKarte = 0;
	popust = 0;
}

Karta::Karta(const char* _vrsta, int _id, int _redniBrojDana, int _brojDanaVazenja, double _osnCena, double _popust)
{
	vrsta = new char[strlen(_vrsta) + 1];
	strcpy(vrsta, _vrsta);

	id = _id;
	redniBrojDana = _redniBrojDana;
	brojDanaVazenja = _brojDanaVazenja;
	osnovnaCenaKarte = _osnCena;
	popust = _popust;

}

void Karta::prikazi(ostream& izlaz)
{
	izlaz << vrsta << ":(" << id << "):\n";
	izlaz << left << setw(25) << "REDNI BROJ DANA: " << redniBrojDana << endl;
	izlaz << left << setw(25) << "BROJ DANA VAZENJA: " << brojDanaVazenja << endl;
	izlaz << left << setw(25) << "OSNOVNA CENA KARTE: " << osnovnaCenaKarte << endl;
	izlaz << left << setw(25) << "POPUST: " << popust << endl;
}
