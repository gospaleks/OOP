#include "Virtuelni.h"
#include <iostream>
#include <string.h>
using namespace std;

Virtuelni::Virtuelni()
	:Posetilac(){
	korisnicno_ime = nullptr;
	cena = b_sati = 0;
}

Virtuelni::Virtuelni(int bt, char* ime, char* prezime, char* k_ime, int br_sati, int br_komentara)
	:Posetilac(bt, ime, prezime){
	korisnicno_ime = new char[strlen(k_ime) + 1];
	strcpy(korisnicno_ime, k_ime);
	b_sati = br_sati;
	b_komentara = br_komentara;
	cena = br_sati * Posetilac::cena_po_satu;
	zainteresovanost = b_sati * b_komentara;
}

void Virtuelni::prikazi(ostream& izlaz)
{
	izlaz << "Virtuelni posetilac:" << endl
		<< b_termina << " - broj termina" << endl
		<< ime << " " << prezime << " - ime prezime" << endl
		<< b_sati << " - broj sati" << endl
		<< b_komentara << " - broj komentara" << endl
		<< zainteresovanost << " - zainteresovanost" << endl
		<< cena << " - cena" << endl;
}
