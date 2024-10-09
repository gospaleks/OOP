#include <iostream>
#include <fstream>
#include "Matrica.h"
#include "Complex.h"
using namespace std;

int main() {
	
	ifstream ulaz("ulazInt.txt");
	if (ulaz.good()) {

		cout << "INT\n\n";

		int n, m;

		// MAT_1
		ulaz >> n >> m;
		Matrica<int>* matInt1 = new Matrica<int>(n, m);
		ulaz >> *matInt1;


		// MAT_2
		ulaz >> n >> m;
		Matrica<int>* matInt2 = new Matrica<int>(n, m);
		ulaz >> *matInt2;

		matInt2->SetElement(1, 1, 100);

		// MAT_1 * MAT_2
		Matrica<int> rezMatInt = ((*matInt1) * (*matInt2));
		cout << "MAT_INT_1 * MAT_INT_2:\n\n" << rezMatInt;


		cout << "\n\nOperator = (matInt2 dodeljujemo na objekat proba)\n\n";

		Matrica<int> proba;
		proba = *matInt2;
		cout << proba;

		cout << "\n\nElement MAT_INT_1 na poziciji (1, 1) = " << matInt1->GetElement(1, 1) << endl;

		delete matInt1;

		// delete matInt2; 
		/* nema potrebe za delete ovde 
		   jer je proba sad taj objekat 
		   se brise sam jer je u statickoj zoni */
	}

	cout << "\n\n----------------------------------------------\nCOMPLEX\n\n";

	ifstream ulazC("ulazComplex.txt");
	if (ulazC.good()) {
		int n, m;

		// MAT_1
		ulazC >> n >> m;
		Matrica<Complex>* matComplex1 = new Matrica<Complex>(n, m);
		ulazC >> *matComplex1;


		// MAT_2
		ulazC >> n >> m;
		Matrica<Complex>* matComplex2 = new Matrica<Complex>(n, m);
		ulazC >> *matComplex2;

		Complex c(1, 10);
		matComplex1->SetElement(0, 1, c);

		cout << "MAT_COMPLEX_1\n\n" << *matComplex1 << "\n\n";
		cout << "MAT_COMPLEX_2\n\n" << *matComplex2 << "\n\n";
	
		Matrica<Complex> rezMatComplex = ((*matComplex1) * (*matComplex2));
		cout << "MAT_COMPLEX_1 * MAT_COMPLEX_2:\n\n" << rezMatComplex << "\n\n";

		delete matComplex1;
		delete matComplex2;
	}


	return 0;
}