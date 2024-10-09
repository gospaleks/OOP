#include <iostream>
#include <fstream>
#include "Vektor.h"
using namespace std;

int main() {

	/*ifstream ulaz("input.txt");
	if (!ulaz.good()) return 0;
	
	int n;
	ulaz >> n;
	Vektor *v1 = new Vektor(n);
	ulaz >> (*v1);

	ulaz >> n;
	Vektor* v2 = new Vektor(n);
	ulaz >> (*v2);

	ulaz.close();

	cout << "VEKTOR v1:\n" << *v1 << endl;
	cout << "VEKTOR v2:\n" <<  *v2 << endl;

	Vektor *v3 = new Vektor(v1->saberi(*v2));
	cout << "v1+v2\n" << *v3;

	Vektor* v4 = new Vektor((*v1) * (*v2));
	cout << "v1*v2\n" << *v4;

	*v3 = (5 + *v1);
	cout << "5+v1\n" << *v3;

	*v4 = (5 * (*v2));
	cout << "5*v2\n" << *v4;

	delete v1;
	delete v2;
	delete v3;
	delete v4;*/


	//Tacka t1(1, 2, 3);
	//Tacka t2 = t1++;

	//cout << t1 << endl;
	//cout << t2;

	ifstream ulaz("input.txt");
	if (ulaz.good()) {

		int n;
		ulaz >> n;
		Vektor* v1 = new Vektor(n);
		ulaz >> (*v1);
		++(*v1);
		cout << *v1;

		ulaz.close();

		delete v1;
	}

	return 0;
}