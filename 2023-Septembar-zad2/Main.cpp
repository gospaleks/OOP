#include <iostream>
#include <fstream>

#include "Prodavnica.h"
#include "Proizvod.h"

int main() {
	
	try 
	{
		Prodavnica<float> *p1 = new Prodavnica<float>("HranaZaPse", 1);
		
		std::cout << "Dodajte 4 proizvoda u prodavnicu hrane za pse:\n";
		for (int i = 0; i < 4; ++i) {
			float x; std::cin >> x;
			p1->Dodaj(x);
		}

		p1->Prodaj(2);

		p1->UpisiUFajl("hrana_za_pse.txt");
		std::cout << "p1 uspesno upisan u fajl\nSrednja vrednost prodavnice p1: " << p1->SrednjaVrednost() << std::endl;
	
		delete p1;

		Prodavnica<float> p2;
		p2.CitajIzFajla("hrana_za_pse.txt");
//		p2.StampajNaEkran();
	}
	catch (const char* s) {
		std::cout << s << std::endl;
	}

	try {
		Prodavnica<Proizvod> *s1 = new Prodavnica<Proizvod>("Supermarket", 3);
		Proizvod* pro1 = new Proizvod("ZutiCvet", 5, 955.99f, 1.23f);
		Proizvod* pro2 = new Proizvod("Brasno", 4, 499.99f, 0.99f);
		Proizvod* pro3 = new Proizvod("VodaVoda", 6, 58.99f, 1.55f);

		s1->Dodaj(*pro1);
		s1->Dodaj(*pro2);
		s1->Dodaj(*pro3);

		s1->Prodaj(1);

		s1->UpisiUFajl("supermarket.txt");
		std::cout << "s1 uspesno upisan u fajl." << std::endl;

		delete s1;

		Prodavnica<Proizvod> s2;
		s2.CitajIzFajla("supermarket.txt");
//		s2.StampajNaEkran();
	}
	catch (const char* s) {
		std::cout << s << std::endl;
	}

	return 0;
}