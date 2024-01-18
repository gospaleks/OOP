#include <iostream>
#include "Kolekcija.h"
#include "Banana.h"
using namespace std;

void main()
{
	/*try
	{
		Kolekcija<float> k1(10);
		float a1 = 100.5;
		float a2 = 140.8;
		float a3 = 90;
		float a4 = 110;
		float a5 = 76.6;
		k1.dodaj(a1);
		k1.dodaj(a2);
		k1.dodaj(a3);
		k1.dodaj(a4);
		k1.dodaj(a5);
		float prosek = k1.prosek();
		cout << prosek << endl;
		k1.obrisi(15);
		cout << k1;
	}
	catch (const char* poruka)
	{
		cout << poruka;
	}*/
	try
	{
		Kolekcija <Banana> k2(10);
		Banana b1(100.5, "zrela");
		Banana b2(140.8, "zrela");
		Banana b3(90, "zrela");
		Banana b4(110, "zrela");
		Banana b5(76.6, "zrela");
		k2.dodaj(b1);
		k2.dodaj(b2);
		k2.dodaj(b3);
		k2.dodaj(b4);
		k2.dodaj(b5);
		float pprosek = k2.prosek();
		cout << pprosek << endl;
		k2.obrisi(15);
		cout << k2;
	}
	catch (const char* poruka)
	{
		cout << poruka;
	}
}