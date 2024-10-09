#pragma once
#include <iostream>
using namespace std;

template <class Pod, int stepen>
class Polinom
{
private:
	Pod* niz;
public:
	Polinom() {
		niz = new Pod[stepen+1];
	}
	
	~Polinom() {
		if (niz != nullptr)
			delete [] niz;
	}

	void Ucitaj() {
		for (int i = 0; i <= stepen; ++i)
		{
			cout << stepen - i << ": ";
			cin >> niz[i];
		}
	}

	Pod& IzracunajPolinom(Pod x) {
		
		Pod rez = *(new Pod(0));

		for (int i = stepen; i > 0; --i) {

			// ovde nadje x^5 npr
			Pod xNa = x;
			for (int j = 0; j < i-1; ++j)
				xNa = xNa * x;

			// ovaj deo je koef * x^5 npr
			xNa = xNa * niz[stepen - i];
			
			rez = rez + xNa;
		}

		rez = rez + niz[0];
		Pod* frez = new Pod(rez);

		return *frez;
	}

	void PrikaziPolinom() {
		cout << "P(x) = ";
		for (int i = 0; i <= stepen; ++i) {
			cout << niz[i] << "x^" << noshowpos <<stepen - i;
			if (i != stepen)
				cout << " + ";
		}
	}

};

