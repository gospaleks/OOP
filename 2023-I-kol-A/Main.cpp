#include "Paketic.h"
#include "Cokolada.h"
#include "Igracka.h"

using namespace std;

void main()
{
	// 2 poena
	Poklon * p1 = new Cokolada(109.00, 3, 25);
	//p1.print();
	cout << *p1 << endl;
	// 2 poena
	Poklon * p2 = new Igracka(399.99, 1, "plisana");
	//p2.print();
	cout << *p2 << endl;
	
	Paketic p(4);
	Paketic * pp = new Paketic(4);
	// 2 poena
	for (int i = 0; i < p.BrojPoklona() / 2; i++)
	{
		p.Add(new Cokolada(100 + i * 5, i * 3, 20 + i * 13));
		p.Add(new Igracka(1000 + i * 20.37, (i + 1) * i, "plisana"));
	}
	for (int i = 0; i < pp->BrojPoklona() / 2; i++)
	{
		pp->Add(new Cokolada(100 + i * 5, i * 3, 20 + i * 13));
		pp->Add(new Igracka(1000 + i * 20.37, (i + 1) * i, "plisana"));
	}
	// 2 poena
	//p.print();
	cout << p << endl;

	// 2 poena
	Paketic ppp = p + *pp;
	//ppp.print();
	cout << ppp << endl;

	// 2 poena
	delete pp;

	// 2 poena
	p.Save("paketici.txt");

	 // 2 poena
	Poklon * pmaxMasnica = p.Max();
	cout << *pmaxMasnica << endl;

	// 2 poena
	Paketic cPaketic = p;
	// cPaketic.print();
	cout << cPaketic << endl;

	// 2 poena
	p.RemoveMinimum(&p1);
	cout << p << endl;
	cout << *p1;
}