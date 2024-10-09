#include "Polinom.h"
#include "Complex.h"
#include <iostream>
using namespace std;

int main() {

	Polinom<int, 5> *polinomInt = new Polinom<int, 5>();
	cout << "Uneti koeficijente INT polinoma:\n";
	polinomInt->Ucitaj();

	polinomInt->PrikaziPolinom();

	cout << "\n\nZa x = 2:\n";
	cout << polinomInt->IzracunajPolinom(2) << "\n\n\n";

	delete polinomInt;


	Polinom<Complex, 5>* polinomComplex = new Polinom<Complex, 5>();
	cout << "Uneti koeficijente COMPLEX polinoma:\n";
	polinomComplex->Ucitaj();

	polinomComplex->PrikaziPolinom();

	cout << "\n\nZa x = 2:\n";
	cout << polinomComplex->IzracunajPolinom(*(new Complex(2))) << "\n\n\n";

	delete polinomComplex;

	return 0;
}