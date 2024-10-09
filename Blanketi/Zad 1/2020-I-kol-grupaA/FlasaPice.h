#pragma once
#include "Poklon.h"
#include <fstream>
#include <iostream>
using namespace std;

class FlasaPice : public Poklon
{
private:
	double masaPrazneFlase;
	double gustinaPica;
	double zapremina;	// 1l = 1000g
public:
	FlasaPice();
	FlasaPice(double _masaUkrasneAmbalaze, double _masaPrazneFlase, double _gustinaPica, double _zapremina);
	~FlasaPice();

	virtual void prikazi(ostream& izlaz);
	virtual double getMasa();
};

