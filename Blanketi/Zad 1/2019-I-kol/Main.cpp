#include "Paket.h"
#include "PojedinacniPaket.h"
#include "UpareniPaket.h"
#include "PorodicniPaket.h"
#include "Preduzece.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
	
	// TREBA SE DODA ZAMENA CELOG PAKETA AL NEAM SNAGU VISE
	// U SUSTINI PROSLEDIS MU NOV PAKET I IME TRENUTNOG
	// OVAJ OBRISES A NA TO MESTO STAVIS NOVI I TJT

	Preduzece* p = new Preduzece(10);

	Paket* p1 = new PojedinacniPaket(300, 5);
	Paket* p2 = new UpareniPaket(300, 5, 70);
	Paket* p3 = new PorodicniPaket(300, 5, 65, 2);

	p->dodajPaket(p1);
	p->dodajPaket(p2);
	p->dodajPaket(p3);

	p->stampajIzvestaj(cout);

	// zameni broj pretplatnih minuta i stampaj nov izvestaj
	//p->zameniBrojPretplMin(1, 1500);
	//p->stampajIzvestaj(cout);
	
	//cout << "Ukupan broj minuta svih koristnika: " << p->ukupanBrojMinuta() << endl;

	// zameni procentualni parametar i stampaj nov izvestaj
	//p->zameniProcentualniParametar(1, 88);
	//p->stampajIzvestaj(cout);




	
	delete p;
	return 0;
}