#include "Pcela.h"
#include <math.h>

Pcela::Pcela(Polje* pp, int rr, int kk)
	: Entitet('p', pow(pi, (rr + 1 + kk + 1)), pp, rr, kk)
{
}

void Pcela::dobro()
{
	float health = (r + 1) * (pi + k + 1);
	for (int i = 0; i < t->getN(); i++)
		for (int j = 0; j < t->getM(); j++)
			if (t->vratiIJ(i, j) != nullptr)
				if (t->vratiIJ(i, j)->getTip() == 'o')
					t->vratiIJ(i, j)->povecaj((int)health);
}

void Pcela::lose()
{
	float damage = pow(pi, (r + 1 + k + 1) / (k + 1));
	for (int i = 0; i < t->getN(); i++)
		for (int j = 0; j < t->getM(); j++)
			if (t->vratiIJ(i, j) != nullptr)
				if (t->vratiIJ(i, j)->getTip() == 'o')
					t->vratiIJ(i, j)->smanji((int)damage);
}
