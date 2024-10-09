#include <iostream>
#include <fstream>
#include "Ranac.h"
#include "DragoKamenje.h"
#include "Jabuka.h"
#include "ZlatnaPoluga.h"

using namespace std;

int main()
{
	Ranac* r = new Ranac(5);
	char c;

	for (int i = 0; i < 3; ++i)
	{
		cout << "z - zlatna poluga, d - drago kamenje, j - jabuka\n";
		opet:cin >> c;
		switch (c) {
		case 'z':
		{
			double masa, sc;
			cout << "Masa: "; cin >> masa;
			cout << "Stepen cistoce: "; cin >> sc;
			r->dodajPredmet(new ZlatnaPoluga(masa, sc));
			cout << "----------------------------------" << endl;
			break;
		}
		case 'd':
		{
			double masa, c;
			char boja[100];
			int brStr;
			cout << "Masa: "; cin >> masa;
			cout << "Koef cistoce: "; cin >> c;
			cout << "Boja: "; cin >> boja;
			cout << "Br str: "; cin >> brStr;
			r->dodajPredmet(new DragoKamenje(masa, c, boja, brStr));
			cout << "----------------------------------" << endl;
			break;
		}
		case 'j':
		{
			double masa, ks, kk;
			char boja[100];
			cout << "Masa: "; cin >> masa;
			cout << "Koef slatkoce: "; cin >> ks;
			cout << "Koef kiselosti: "; cin >> kk;
			cout << "Boja: "; cin >> boja;
			r->dodajPredmet(new Jabuka(masa, ks, kk, boja));
			cout << "----------------------------------" << endl;
			break;
		}
		default:
			goto opet;
		}
	}
	cout << endl << endl;

	r->prikazi(cout);
	cout << endl << endl << "Najvredniji po jedinici mase:\n";
	(r->najvrednijiPoJediniciMase())->prikazi(cout);
	cout << endl << endl << "Srednja vrednost: " << r->srednjaVrednost() << endl;

	
	delete r;
	return 0;
}