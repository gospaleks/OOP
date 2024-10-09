#include "Preduzece.h"
#include "Domacinstvo.h"
#include "SolarnoDomacinstvo.h"
#include <iostream>
using namespace std;

void main()
{
	Preduzece* p = new Preduzece(10);

	Domacinstvo* d1 = new Domacinstvo(1, 36.2, 156.1);
	Domacinstvo* d2 = new Domacinstvo(2, 76.2, 341.7);
	Domacinstvo* d3 = new SolarnoDomacinstvo(3, 43.8, 265.3, 55.1, 1.55, 2000);
	Domacinstvo* d4 = new SolarnoDomacinstvo(4, 87.9, 501.55, 89.3, 1.33, 5000);
	
	p->dodaj(d1);
	p->dodaj(d2);
	p->dodaj(d3);
	p->dodaj(d4);
//	d3->ispisi(cout);

	// p->izbaci(2);

	/*Domacinstvo* d5 = new Domacinstvo(5, 44, 200);
	p->dodaj(d5);*/

	p->prikazi(cout);

	/*cout << "Prosecna potrosnja po jedinici povrsine: "
		<< p->prosecnaPotrosnja() << endl;*/

	/*Domacinstvo* d6 = p->najmanjaSvota(10);
	Domacinstvo* d7 = p->najvecaSvota(10);

	cout << "Domacinstvo koje je potrosilo najmanju svotu: " << endl;
	d6->ispisi(cout);
	cout << "Domacinstvo koje je potrosilo najvecu svotu: " << endl;
	d7->ispisi(cout);*/
}