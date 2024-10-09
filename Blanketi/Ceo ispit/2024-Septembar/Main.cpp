#include "Voda.h"
#include "Sok.h"
#include "Skladiste.h"

// 2. zad
#include "Fabrika.h"
#include "Sokovi.h"

void zadatak1()
{
	char ukus1[7] = "jagoda";
	int procenat1 = 50;
	float odnosCene = 0.75;
	// 2 poena
	Pice* p1 = new Voda(1);
	//p1->Prikazi();
	cout << *p1 << endl;
	// 2 poena
	Pice* p2 = new Sok(0.75, ukus1, procenat1, odnosCene);
	//p2->Prikazi();
	cout << *p2 << endl;
	float voda[] = { 1, 0.2, 2, 5, 1, 1, 2, 5 };
	float sok[] = { 1, 0.2, 1.5, 0.5, 1, 0.5, 1, 1.5 };
	Skladiste* s = new Skladiste(10);
	// 2 poena
	for (int i = 0; i < 4; i++)
	{
		s->Dodaj(new Voda(voda[i]));
		s->Dodaj(new Sok(sok[i], ukus1, procenat1, odnosCene));
	}
	// 2 poena
	//s->print();

	//cout << *s << endl;
	// 2 poena
	for (int i = 4; i < 8; i++)
	{
		s->Dodaj(new Voda(voda[i]));
		s->Dodaj(new Sok(sok[i], ukus1, procenat1, odnosCene));
	}
	//s->print();
	cout << *s << endl;
	// 2 poena
	Sok sok1(0.5, ukus1, procenat1, odnosCene);
	s->Izdvoji(sok1, 2);
	//s->print();
	cout << *s << endl;
	// 1 poena
	Voda voda1(1);
	s->Izdvoji(voda1, 2);
	//s->print();
	cout << *s << endl;
	// 2 poena
	Voda voda2(2);
	s->Presipaj(voda2, voda1);
	//s->print();
	cout << *s << endl;
	// 2 poena
	int nabavka = 7;
	if (s->DovoljnaKolicina(nabavka))
		cout << "Ima dovoljno vode i sokova za " << nabavka << "l" << endl;
	else
		cout << "Nema dovoljno vode i sokova" << endl;
	// 2 poena
	Pice* piceMin = nullptr, * piceMax = nullptr;
	s->VratiNaj(&piceMin, &piceMax);
	piceMin->Prikazi(cout);
	piceMax->Prikazi(cout);
	// 1 poena
	delete s;
}

void zadatak2()
{
	int maxPodataka = 8, brojPodataka = 7;
	// 3 boda
	//// postavljanje i prihvatanje izuzetaka
	//{
	//	float voda[] = { 1, 0.2, 0.5, 1, 0.5, 0.2, 0.2 };
	//	Fabrika<float> fv(maxPodataka);
	//	// 1 bod
	//	for (int i = 0; i < brojPodataka; i++) {
	//		try {
	//			fv.Dodaj(voda[i]);
	//		}
	//		catch (const char* poruka) {
	//			cout << poruka << endl;
	//		}
	//	}
	//	cout << fv << endl; // fv.Ispisi(cout);
	//	// 1 bod
	//	try {
	//		fv.Izbaci(voda[1]);
	//	}
	//	catch (const char* poruka) {
	//		cout << poruka << endl;
	//	}
	//	cout << fv << endl; //fv.Ispisi(cout);

	//	// 1 bod
	//	float ukupno = fv.Ukupno();
	//	cout << ukupno << endl; 
	//	// 1 bod
	//	int vrednost = 1; float ukupnaVrednost = 0;
	//	int broj = fv.UkupniBrojVrednost(vrednost, &ukupnaVrednost);
	//	cout << broj << " " << ukupnaVrednost << endl; // 2 2
	//	// 1 bod
	//	int najmanjeAmbalaza = fv.NajmanjeAmbalaza(2.8);
	//	cout << najmanjeAmbalaza << endl; // 4
	//	// 1 bod
	//	try {
	//		fv.Sacuvaj("NovaFabrikaVode.txt");
	//	}
	//	catch (const char* poruka) {
	//		cout << poruka << endl;
	//	}
	//	// 1 boda
	//	Fabrika<float> novaUcitana(maxPodataka);
	//	novaUcitana.Ucitaj("NovaFabrikaVode.txt");
	//	cout << novaUcitana << endl; // novaUcitana.Ispisi(cout);
	//}

	{
		char ukus[][7] = { "jagoda", "jabuka", "jagoda", "jagoda", "jagoda", "jabuka",

		"jagoda" };

		float zap[] = { 1, 0.2, 0.5, 1, 0.5, 0.2, 0.2 };
		int procenat[] = { 50, 70, 50, 50, 50, 70, 50 };
		Fabrika<Sokovi> fs(maxPodataka);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++) {
			try {
				fs.Dodaj(Sokovi(ukus[i], zap[i], procenat[i]));
			}
			catch (const char* poruka) {
				cout << poruka << endl;
			}
		}
		// 1 bod
		cout << fs << endl; //fs.Ispisi(cout);
		// 1 bod
		try {
			fs.Izbaci(Sokovi(ukus[1], zap[1], procenat[1]));
		}
		catch (const char* poruka) {
			cout << poruka << endl;
		}
		cout << fs << endl; //fs.Ispisi(cout);
		// 2 boda
		float ukupno = fs.Ukupno();
		cout << ukupno << endl;
		// 2 boda
		Sokovi vr(ukus[0], zap[0], procenat[0]);
		float ukupnaVrednost = 0;
		int broj = fs.UkupniBrojVrednost(vr, &ukupnaVrednost);
		cout << broj << " " << ukupnaVrednost << endl; // 2 2
		// 2 boda
		int najmanjeAmbalaza = fs.NajmanjeAmbalaza(2.5);
		cout << najmanjeAmbalaza << endl; // 3
		// 0 bodova
		try {
			fs.Sacuvaj("NovaFabrikaSokova.txt");
		}
		catch (const char* poruka) {
			cout << poruka << endl;
		}
		// 1 bod
		Fabrika<Sokovi> novaUcS(maxPodataka);
		try {
			novaUcS.Ucitaj("NovaFabrikaSokova.txt");
		}
		catch (const char* poruka) {
			cout << poruka << endl;
		}
		cout << novaUcS << endl; // novaUcS.Ispisi(cout);
	}
}
void main()
{
	//zadatak1();
	zadatak2();
}