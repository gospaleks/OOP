#include <iostream>
#include "Minesweeper.h"
using namespace std;

int main() {

	//int n, m;
	//cout << "Unesite dimenzije polja: ";
	//cin >> n >> m;
	//Minesweeper polje(n, m);
	//polje.ucitajRaspored();

	//int pozr, pozk;
	//cout << "Unesite poziciju jednog polja: ";
	//cin >> pozr >> pozk;
	//int brMina = polje.vratiBrmina(pozr, pozk);
	//if (brMina == -1)
	//	polje.prikazi();
	//else
	//	cout << brMina;

	Minesweeper* polje2 = new Minesweeper(3, 4);
	polje2->ucitajRaspored();
	// polje2->izbaci();
	cout << polje2->vratiBrmina(1, 0) << endl;
	polje2->prikazi();

	delete polje2;
	return 0;
}