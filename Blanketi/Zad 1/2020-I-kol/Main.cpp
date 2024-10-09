#include "Cvet.h"
#include "Ruza.h"
#include "Lala.h"
#include "Buket.h"

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	Buket* b = new Buket(15);
	
	b->ucitaj("ulaz.txt");
	b->sortirajPoCeni();
	b->ispisi(cout);


	Buket *b1 = new Buket(10);
	Buket *b2 = new Buket(10);
	b->podeliBuket(b1, b2);

	ofstream buket1("buket1.txt");
	b1->ispisi(buket1);
	buket1.close();

	ofstream buket2("buket2.txt");
	b2->ispisi(buket2);
	buket2.close();

	// isisuje sve NULL jer je podeljeno u drugi buketi
	// b->ispisi(cout);

	delete b;
	delete b1;
	delete b2;

	return 0;
}