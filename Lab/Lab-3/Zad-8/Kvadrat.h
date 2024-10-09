#pragma once
#include "GeometrijskaSlika.h"
class Kvadrat : public GeometrijskaSlika
{
private:
	double a;
public:
	Kvadrat();
	Kvadrat(int r, int g, int b, double xx, double yy, double aa);
	virtual double povrsina();
	virtual void show();
};

