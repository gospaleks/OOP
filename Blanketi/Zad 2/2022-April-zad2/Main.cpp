#include <iostream>
#include "Takmicar.h"
#include "Lista.h"
using namespace std;

int main() {
	//int

	Lista<int> lista1(5);
	lista1.dodaj(14);
	lista1.dodaj(54);
	lista1.dodaj(24);
	lista1.dodaj(16);
	lista1.dodaj(16);
	lista1.dodaj(16);

	cout << lista1 << endl;

	lista1.obrisi(54);

	cout << lista1 << endl;

	Lista<int> lista2(7);
	lista2.dodaj(1);
	lista2.dodaj(2);
	lista2.dodaj(3);
	lista2.dodaj(4);
	lista2.dodaj(5);

	cout << lista2 << endl;

	Lista<int> lista3(15);

	lista3 = lista1 + lista2;

	cout << lista3;

	//Takmicar

	Lista<Takmicar> lista4(5);
	Takmicar element1(1,2,3);
	lista4.dodaj(element1);
	Takmicar element2(1,2,3);
	lista4.dodaj(element2);
	Takmicar element3(2, 3, 5);
	lista4.dodaj(element3);
	Takmicar element4(6, 14, 6);
	lista4.dodaj(element4);

	cout << lista4;

	lista4.obrisi(1);

	cout << lista4;

	Lista<Takmicar> lista5(5);
	Takmicar element5(4, 5, 6);
	lista5.dodaj(element5);
	Takmicar element6(88, 5, 6);
	lista5.dodaj(element6);

	Lista<Takmicar> lista6(17);

	lista6 = lista4 + lista5;

	cout << lista6;
}