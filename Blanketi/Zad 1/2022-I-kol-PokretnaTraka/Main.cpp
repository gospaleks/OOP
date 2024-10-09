#include "PokretnaTraka.h"
#include "Proizvod.h"
#include "Kondenzator.h"
#include "Otpornik.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {

	// ovo da bi resetovao fajl posle svako pokretanje programa
	// jer kad se izbaci samo se append-uje
	ofstream izlaz("pakovanje.txt");
	izlaz.close();


	PokretnaTraka* traka = new PokretnaTraka(10);

	traka->dodajProizvod(new Kondenzator("111111", 0));
	traka->dodajProizvod(new Otpornik("44444", 0, 2, 20));
	traka->dodajProizvod(new Kondenzator("333333", 5200));
	traka->dodajProizvod(new Otpornik("222222", 10000, 2, 20));
	traka->dodajProizvod(new Kondenzator("555555", 7000));
	traka->dodajProizvod(new Otpornik("666666", 12000, 2, 31));

	// zameni defektan
	Proizvod* o = new Otpornik("123456", 9999, 1, 10);
	traka->zameniDefektni(1, o);
	
	// povecaj kapacitet i dodaj 2 kondenzatora
	traka->povecajKapacitet(2);
	traka->dodajProizvod(new Kondenzator("777777", 500));
	traka->dodajProizvod(new Kondenzator("888888", 400));

	// ovo se ne trazi al da se vidi sta je gde otp
	traka->prikazi(cout);

	// izbaci sve
	for (int i = 0; i < 8; ++i)
		traka->izbaci();

	delete traka;

	return 0;
}