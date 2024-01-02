#include <iostream>
#include "Kolekcija.h"
#include "IzlozbeniPosetioci.h"

int main() {

	try 
	{
		Kolekcija<int> k(10);
		k.dodaj(11);
		k.dodaj(2);
		k.dodaj(34);
		k.dodaj(23);
		k.dodaj(11);
		k.dodaj(44);

		int dan1, dan2;
		k.dvaDanaMinZarada(&dan1, &dan2);
		std::cout << dan1 << ", " << dan2 << std::endl;

		std::cout << k.brojPosetilacaIzmedju(2, 4) << std::endl;
		k.obrisiPrvihX(2);

		k.sacuvaj("interaktivni.txt");

		Kolekcija<int> novaK(10);
		novaK.ucitaj("interaktivni.txt");
//		novaK.ispisiNaEkran();
		
		std::cout << std::endl;
	}
	catch (const char* s) {
		std::cout << s << std::endl;
	}

	try {
		Kolekcija<IzlozbeniPosetioci> kol(10);
		
		kol.dodaj(IzlozbeniPosetioci(1, 2, 3));
		kol.dodaj(IzlozbeniPosetioci(4, 2, 10));
		kol.dodaj(IzlozbeniPosetioci(1, 2, 0));
		kol.dodaj(IzlozbeniPosetioci(3, 1, 0));
		kol.dodaj(IzlozbeniPosetioci(4, 4, 4));
		kol.dodaj(IzlozbeniPosetioci(0, 0, 0));
		kol.dodaj(IzlozbeniPosetioci(1, 12, 0));

		int dan1, dan2;
		kol.dvaDanaMinZarada(&dan1, &dan2);
		std::cout << dan1 << ", " << dan2 << std::endl;

		std::cout << kol.brojPosetilacaIzmedju(2, 4);
		kol.obrisiPrvihX(2);

		kol.sacuvaj("izlozbeni.txt");

		Kolekcija<IzlozbeniPosetioci> novaIzl(10);
		novaIzl.ucitaj("izlozbeni.txt");
//		novaIzl.ispisiNaEkran();
	}
	catch (const char* s) {
		std::cout << s << std::endl;
	}

	return 0;
}