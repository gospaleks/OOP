#include "GeometrijskaSlika.h"
#include <iostream>
#include <math.h>
using namespace std;

GeometrijskaSlika::GeometrijskaSlika()
{
	R = G = B = 0;
	x = y = 0;
}

GeometrijskaSlika::GeometrijskaSlika(int r, int g, int b, double xx, double yy)
{
	if (r < 0) R = 0;
	else if (r > 255) R = 255;
	else R = r;

	if (g < 0) G = 0;
	else if (g > 255) G = 255;
	else G = g;

	if (b < 0) B = 0;
	else if (B > 255) B = 255;
	else B = b;

	x = xx;
	y = yy;
}

double GeometrijskaSlika::rastojanjeFigure()
{
	return sqrt(x*x + y*y);
}

void GeometrijskaSlika::transliraj(int dx, int dy)
{
	x += dx;
	y += dy;
}

void GeometrijskaSlika::show()
{
	cout << "(" << R << ", " << G << ", " << B << ")" << " (" << x << ", " << y << ") ";
}

bool GeometrijskaSlika::jeVeca(GeometrijskaSlika* g)
{
	if (this->povrsina() > g->povrsina())
		return true;
	return false;
}




