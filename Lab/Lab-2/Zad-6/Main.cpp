#include <fstream>
#include <iostream>
#include "Minesweeper.h"
using namespace std;

int main() {
	
	ifstream ulaz("ulaz.txt");
	if (ulaz.good()) {

		int n, m;
		ulaz >> n >> m;
		
		Minesweeper* m1 = new Minesweeper(n, m);
		ulaz >> *m1;
		ulaz.close();
		
		cout << "MINESWEEPER:\n" << *m1;
		m1->rotGore();
		cout << "Gore:\n" << *m1;

		m1->rotDesno();
		cout << "Desno:\n" << *m1;

		m1->rotDole();
		cout << "Dole:\n" << *m1;

		m1->rotLevo();
		cout << "Levo:\n" << *m1;
		

		// m1->zameniNtoPolje(5);
		// cout << *m1;

		// cout << m1->vratiBrmina(2, 2);


		delete m1;
	}


	return 0;
}