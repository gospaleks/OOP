#pragma once
#include "Broj.h"
class RacionalanBroj : public Broj 
{
private:
	int a;
	int b;
public:
	RacionalanBroj();
	RacionalanBroj(int aa, int bb);
	RacionalanBroj(double d);
	~RacionalanBroj();

	virtual void PostaviVrednost(double d);
	virtual void Print();
};

