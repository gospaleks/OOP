#include "PorodicniNovcanik.h"
#include "NovcanicaDinar.h"
#include "NovcanicaStrana.h"

#include "Novcanik.h"
#include "NovcanicaValuta.h"

void zadatak1() {
	char oz[4] = "EUR";
	double kurs = 117.20;
	// 2 poena
	Novcanica* p1 = new NovcanicaDinar(100);
	//p1->Prikazi();
	cout << *p1 << endl;
	// 2 poena
	Novcanica* p2 = new NovcanicaStrana(50, oz, kurs);
	//p2->Prikazi();
	cout << *p2 << endl;
	int dinari[] = { 100, 20, 200, 500, 100, 100, 200, 500 };
	int evri[] = { 100, 20, 10, 50, 100, 50, 100, 10 };
	PorodicniNovcanik* pNov = new PorodicniNovcanik(10);
	// 2 poena
	for (int i = 0; i < 4; i++)
	{
		pNov->Dodaj(new NovcanicaDinar(dinari[i]));
		pNov->Dodaj(new NovcanicaStrana(evri[i], oz, kurs));
	}
	// 2 poena
	//pe.print();
	cout << *pNov << endl;
	// 2 poena
	for (int i = 4; i < 8; i++)
	{
		pNov->Dodaj(new NovcanicaDinar(dinari[i]));
		pNov->Dodaj(new NovcanicaStrana(evri[i], oz, kurs));
	}
	//pe->print();
	cout << *pNov << endl;
	// 2 poena
	NovcanicaStrana evro(50, oz, kurs);
	pNov->Izdvoji(evro, 2);
	//pe->print();
	cout << *pNov << endl;
	// 1 poena
	NovcanicaDinar dinar100(100);
	pNov->Izdvoji(dinar100, 2);
	//pe->print();
	cout << *pNov << endl;
	// 2 poena
	NovcanicaDinar dinar200(200);
	pNov->Rasitni(dinar200, dinar100);
	//pe->print();
	cout << *pNov << endl;
	// 2 poena
	int placanje = 5000;
	if (pNov->MozePlatiti(placanje))
		cout << "Moze platiti " << placanje << endl; // T
	else
		cout << "Ne moze platiti " << placanje << endl;

	// 2 poena
	Novcanica* novcanicaMin = nullptr, * novcanicaMax = nullptr;
	pNov->VratiNaj(&novcanicaMin, &novcanicaMax);
	cout << *novcanicaMin << endl;
	cout << *novcanicaMax << endl;
	//novcanicaMin->Prikazi(); // 20 1
	//novcanicaMax->Prikazi(); // 100 2 EUR
	// 1 poena
	delete pNov;
}

void zadatak2()
{
	int maxPodataka = 8, brojPodataka = 7;
	// 3 boda
	// postavljanje i prihvatanje izuzetaka
	try {
		int dinari[] = { 100, 20, 50, 100, 50, 20, 20 };
		Novcanik<int> nov(maxPodataka);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++)
			nov.Dodaj(dinari[i]);
		cout << nov << endl; //nov.Ispisi(cout);
		// 1 bod
		nov.Izbaci(dinari[1]);
		cout << nov << endl; //nov.Ispisi(cout);
		// 1 bod
		float ukupno = nov.Ukupno();
		cout << ukupno << endl; // 340
		// 1 bod
		int vrednost = 100; float ukupnaVrednost = 0;
		int broj = nov.UkupniBrojVrednost(vrednost, ukupnaVrednost);
		cout << broj << " " << ukupnaVrednost << endl; // 2 200
		// 1 bod
		int najmanjeNovcanica = nov.NajmanjeNovcanica(280);
		cout << najmanjeNovcanica << endl; // 4
		// 1 bod
		nov.Sacuvaj("NovDin.txt");
		// 1 boda
		Novcanik<int> novUcitan(maxPodataka);
		novUcitan.Ucitaj("NovDin.txt");
		cout << novUcitan << endl; //novUcitan.Ispisi(cout);
	}
	catch (const char* poruka) {
		cout << poruka << endl;
	}
	
	try {
		char oz[][4] = { "RSD", "EUR", "RSD", "RSD", "RSD", "EUR", "RSD" };
		int vred[] = { 100, 20, 50, 100, 50, 20, 20 };
		float kurs[] = { 1, 117.2f, 1, 1, 1, 117.2f, 1 };
		Novcanik<NovcanicaValuta> novVal(maxPodataka);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++) {
			novVal.Dodaj(NovcanicaValuta(oz[i], vred[i], kurs[i]));
		}
		// 1 bod
		cout << novVal << endl; //novVal.Ispisi(cout);
		// 1 bodova
		novVal.Izbaci(NovcanicaValuta(oz[1], vred[1], kurs[1]));
		cout << novVal << endl; //novVal.Ispisi(cout);
		// 2 bod
		float ukupno = novVal.Ukupno();
		cout << ukupno << endl; // 2664
		// 2 bod
		NovcanicaValuta vr(oz[0], vred[0], kurs[0]);
		float ukupnaVrednost = 0;
		int broj = novVal.UkupniBrojVrednost(vr, ukupnaVrednost);
		cout << broj << " " << ukupnaVrednost << endl; // 2 200
		// 2 bod
		int najmanjeNovcanica = novVal.NajmanjeNovcanica(2500);
		cout << najmanjeNovcanica << endl; // 3
		// 0 bod
		novVal.Sacuvaj("NovVal.txt");
		// 1 bod
		Novcanik<NovcanicaValuta> novValUc(maxPodataka);
		novValUc.Ucitaj("NovVal.txt");
		cout << novValUc << endl; //novValUc.Ispisi(cout);
	}
	catch (const char* poruka) {
		cout << poruka << endl;
	}
}

void main()
{
	zadatak1();
	zadatak2();
}