#include "Krug.h"
#include <iostream>
#include <iomanip>
using namespace std;
const double PI = 3.14159;

Krug::Krug()
	:GeometrijskaSlika() {
	r = 0;
}

Krug::Krug(int r, int g, int b, double xx, double yy, double rr)
	:GeometrijskaSlika(r, g, b, xx, yy), r(rr) {
}

double Krug::povrsina()
{
	return (r*r*PI);
}

void Krug::show()
{
	cout << "Krug: ";
	GeometrijskaSlika::show();
	cout << "r = (" << r << ") P = " << povrsina() << endl;
}


