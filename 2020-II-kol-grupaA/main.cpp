#include <iostream>
#include <fstream>
#include "Niz.h"
#include "Zaba.h"
#include "Roda.h"
using namespace std;

void main()
{
	try
	{
		Niz<Roda>* A = new Niz<Roda>(10);
		ifstream ulaz1("Rode.txt");
		if (ulaz1.good())
		{
			float rez;
			A->ucitaj(ulaz1);
			rez = A->ukupnaMasa();
			cout << rez << endl;
			//A->izbaci(2);
			A->ispisi(cout);
			/*A->izbaci(7);
			A->ispisi(cout);*/
			ulaz1.close();
		}
	}
	catch (const char* poruka)
	{
		cout << poruka;
	}
	cout << "Zabe:" << endl;
	try
	{
		Niz<Zaba>* B = new Niz<Zaba>(10);
		ifstream ulaz2("Zabe.txt");
		if (ulaz2.good())
		{
			float rez1;
			B->ucitaj(ulaz2);
			rez1 = B->ukupnaMasa();
			cout << rez1 << endl;
			/*B->izbaci(-2);
			B->ispisi(cout);*/
			//B->izbaci(5);
			B->ispisi(cout);
			ulaz2.close();
		}
	}
	catch(const char* poruka)
	{
		cout << poruka;
	}
}