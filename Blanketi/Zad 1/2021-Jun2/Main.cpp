#include <iostream>
#include <fstream>
#include "Zamak.h"
#include "Posetilac.h"
#include "Stvarni.h"
#include "Virtuelni.h"
using namespace std;

int main()
{
	int kapacitet;
	cin >> kapacitet;
	Zamak z(kapacitet, (char*)"bogda");
	
	Stvarni* s1 = new Stvarni(1, (char*)"Jovan", (char*)"Bogdanovic", (char*)"student", 50, 50);
	Stvarni* s2 = new Stvarni(3, (char*)"Pera", (char*)"Petrovic", (char*)"radi", 30, 100);
	Stvarni* s3 = new Stvarni(5, (char*)"Marko", (char*)"Markovic", (char*)"ne radi", 10, 30);

	Virtuelni* v1 = new Virtuelni(2, (char*)"Mirko", (char*)"Mirkovic", (char*)"mirko123", 3, 1);
	Virtuelni* v2 = new Virtuelni(3, (char*)"Aca", (char*)"Ackovic", (char*)"acko_mafija", 4, 5);
	Virtuelni* v3 = new Virtuelni(6, (char*)"Vojin", (char*)"Jevtovic", (char*)"doo_jevta", 1, 2);

	z.dodaj(s1);
	z.dodaj(s2);
	z.dodaj(s3);

	z.dodaj(v1);
	z.dodaj(v2);
	z.dodaj(v3);

	ofstream izlaz("izlaz.txt");
	z.prikazitermine(izlaz);

	v1->prikazi(cout);

	Posetilac* p = z.orden();
	p->prikazi(cout);

	int cena = z.prihod();
	cout << cena;
}