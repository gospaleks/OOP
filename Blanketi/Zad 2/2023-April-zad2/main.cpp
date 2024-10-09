#include <iostream>
#include "KvadratnaMatrica.h"
#include "Complex.h"
#include <fstream>
using namespace std;

void main()
{
	//try
	//{
	//	KvadratnaMatrica <int>* m1 = new KvadratnaMatrica<int>(3);
	//	cin >> *m1;
	//	KvadratnaMatrica <int>* m2 = new KvadratnaMatrica<int>(3);
	//	cin >> *m2;
	//	KvadratnaMatrica <int>* m3 = new KvadratnaMatrica<int>(3);
	//	/*(*m3) = (*m1) + (*m2);
	//	m3->snimi("suma.txt");*/
	//	(*m3) = (*m1) * (*m2);
	//	m3->snimi("proizvod.txt");
	//}
	//catch (const char* poruka)
	//{
	//	cout << poruka;
	//}
	try
	{
		KvadratnaMatrica <Complex>* m1 = new KvadratnaMatrica<Complex>(3);
		cin >> *m1;
		cout << *m1;
		KvadratnaMatrica <Complex>* m2 = new KvadratnaMatrica<Complex>(3);
		cin >> *m2;
		KvadratnaMatrica <Complex>* m3 = new KvadratnaMatrica<Complex>(3);
		(*m3) = (*m1) + (*m2);
		m3->snimi("suma.txt");
		(*m3) = (*m1) * (*m2);
		m3->snimi("proizvod.txt");
	}
	catch (const char* poruka)
	{
		cout << poruka;
	}
}