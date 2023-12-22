#include "Takmicenje.h"
#include "Ucesnik.h"
#include "Glumac.h"
#include "Pevac.h"
#include "iostream"
#include "fstream"
using namespace std;

void main()
{
	Takmicenje* t = new Takmicenje(10);

	Ucesnik* u1 = new Glumac(1, (char*)"Veljko", (char*)"Najdanovic", 51, 34, 26, 27);
	Ucesnik* u2 = new Glumac(2, (char*)"Aleksandar", (char*)"Sasa", 61, 44, 44, 32);
	Ucesnik* u3 = new Pevac(3, (char*)"Marjana", (char*)"Torbica", 99, (char*)"Kocke Leda", 55, 23, 55);
	Ucesnik* u4 = new Pevac(4, (char*)"Aca", (char*)"Lukas", 99, (char*)"Nesto protiv bolova", 1, 0, 100);

	t->dodaj(u1);
	t->dodaj(u2);
	t->dodaj(u3);
	t->dodaj(u4);

	ofstream izlaz("takmicenje.txt");
	t->upisi(izlaz);
	izlaz << "------------------------------------------------" << endl;
	/*t->obrisi(3);
	t->upisi(izlaz);*/
	t->sortiraj();
	t->upisi(izlaz);

	cout << endl << t->srednjaVrednostPoena() << endl;
	Ucesnik* u5 = t->najveciBrPoena();
	u5->ispisi(cout);
	delete t;

}