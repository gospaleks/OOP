#pragma once
#include "Broj.h"
class KompleksanBroj : public Broj
{
private:
	int a;
	int b;
public:
	KompleksanBroj();
	KompleksanBroj(int aa, int bb);
	~KompleksanBroj();

	virtual void PostaviVrednost(double d);
	virtual void Print();
};

