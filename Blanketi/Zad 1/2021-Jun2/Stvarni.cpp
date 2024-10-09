#include "Stvarni.h"
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

Stvarni::Stvarni()
	:Posetilac(){
	radni_status = nullptr;
	cena = b_odgovora = popust = zainteresovanost = 0;
}

Stvarni::Stvarni(int bt, char* ime, char* prezime, char* radni_status, int br_odgovora, int popust)
	:Posetilac(bt, ime, prezime){
	this->radni_status = new char[strlen(radni_status) + 1];
	strcpy(this->radni_status, radni_status);
	this->popust = popust;
	b_odgovora = br_odgovora;
	cena = Posetilac::osnovna_cena - popust;
	zainteresovanost = b_odgovora;
}

void Stvarni::prikazi(ostream& izlaz)
{
	izlaz << "Stvarni posetilac:" << endl
		<< b_termina << " - broj termina" << endl
		<< ime << " " << prezime << " - ime prezime" << endl
		<< radni_status << " - radni status" << endl
		<< b_odgovora << " - broj odgovora" << endl
		<< popust << " - popust" << endl
		<< zainteresovanost << " - zainteresovanost"
		<< cena << " - cena" << endl;
}
