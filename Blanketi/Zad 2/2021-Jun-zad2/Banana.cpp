#include "Banana.h"

Banana::Banana()
{
	tezina = 0;
	trulazrela = nullptr;
}

Banana::Banana(float ttezina, const char* ttrulazrela)
{
	char s1[10] = "trula";
	char s2[10] = "zrela";
	if (!strcmp(ttrulazrela, s1))
	{
		zauzmi(-1, ttrulazrela);
	}
	else if (!strcmp(ttrulazrela, s2))
	{
		zauzmi(ttezina, ttrulazrela);
	}
	else
	{
		throw "Banana nije validna :(";
	}

}

Banana::~Banana()
{

}


void Banana::zauzmi(float ttezina, const char* tt)
{
	tezina = ttezina;
	trulazrela = new char[strlen(tt) + 1];
	strcpy(trulazrela, tt);
}

Banana::Banana(const Banana& b)
{
	if (trulazrela != nullptr)
		delete trulazrela;
	zauzmi(b.tezina, b.trulazrela);
}

Banana& Banana::operator=(Banana& b)
{
	if (this != &b)
	{
		delete[] trulazrela;
		zauzmi(b.tezina, b.trulazrela);
	}
	return *this;
}

float Banana::operator+(float broj)
{
	return (this->tezina + broj);
}

float Banana::operator-(float broj)
{
	return (this->tezina - broj);
}

ostream& operator<<(ostream& izlaz, Banana& b)
{
	izlaz << "Tezina: " << b.tezina << " Trula ili zrela: " << b.trulazrela;
	return izlaz;
}
