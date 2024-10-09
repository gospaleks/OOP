#include "Displej.h"
#include "DekadniMatricniDisplej.h"
#include <fstream>
#include<iostream>
using namespace std;

void main()
{
	ifstream ulaz("ulaz.txt");
	if(ulaz.good())
	{
		Displej dd(8);
		DekadniMatricniDisplej d;
		d.ucitajCifru(ulaz);

		for (int i = 0; i < 50001; i++)
		{
			dd.inc();
			d.inc();
			if (i % 2018 == 0)
			{
				dd.show();
				d.show();
			}
		}
		dd.reset();
		for (int i = 0; i < 50001; i++)
		{
			dd.inc();
			d.inc();
			if (i % 2018 == 0)
			{
				dd.show();
				d.show();
			}
		}
	}
}