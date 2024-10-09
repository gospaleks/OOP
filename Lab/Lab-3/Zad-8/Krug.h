#pragma once
#include "GeometrijskaSlika.h"
class Krug : public GeometrijskaSlika
{
private:
	double r;
public:
	Krug();
	Krug(int r, int g, int b, double xx, double yy, double rr);
	virtual double povrsina();
	virtual void show();
};

