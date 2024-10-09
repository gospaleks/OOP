#include "Kvadrat.h"
#include <iostream>
#include <iomanip>
using namespace std;

Kvadrat::Kvadrat()
	:GeometrijskaSlika() {
	a = 0;
}

Kvadrat::Kvadrat(int r, int g, int b, double xx, double yy, double aa)
	:GeometrijskaSlika(r, g, b, xx, yy), a(aa) {
}

double Kvadrat::povrsina()
{
	return (a*a);
}

void Kvadrat::show()
{
	cout << "Kvadrat: ";
	GeometrijskaSlika::show();
	cout << "a = (" << a << ") P = " << povrsina() << endl;
}


